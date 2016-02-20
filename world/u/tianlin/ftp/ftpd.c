#define FTPD_VERSION "5.8"
inherit F_DBASE;

mapping socket_info;
int our_socket;
mapping temp_map;
int number_of_users;

/*
 * edit ftpdconf.h & ftpdsupp.h to configure ftpd for your mudlib
 */
#include <net/ftpd.h>
#include <net/ftpdconf.h>
#include <net/ftpdsupp.h>

void setup_ftp( int port );
void finish_lookup( string host, string number );
void resolve_callback( string address, string resolved, int key );
string get_path( int fd, string str );
int strncmp(string str, string sub, int i);

void lose_connection( int fd )
{
	socket_close( fd );
	map_delete( socket_info, fd );
}

void lose_user( int fd )
{
	socket_close( fd );
	map_delete( socket_info, fd );
	number_of_users--;
}

int strncmp(string str, string sub, int i)
{
	int j;

	j = strlen(str);
	return (i > j ? strcmp(str, sub) : strcmp(str[0..i-1], sub));
}

int check_valid_read( string fname, int fd )
{
	int res;

	seteuid( socket_info[ fd ][ USER_NAME ] );
	res = (int) master() -> valid_read(fname, this_object(), "read_file");
	seteuid( getuid() );

	/*
	 * This rather complicated looking section of code handles the
	 * various read levels available.  See ftpdconf.h for READ_LEVEL
	 * definitions of these flags.
	 */
#ifdef READ_LEVEL
#if READ_LEVEL == VALID_READ
	return res;
#elif READ_LEVEL == RESTRICTED_READ
	if (strncmp(fname, HOME_DIR( UNAME ), strlen(HOME_DIR( UNAME ))) == 0
#ifdef PUB_DIR
		  || strncmp(fname, PUB_DIR, strlen(PUB_DIR)) == 0
#endif
#ifdef FTP_DIR
		  || strncmp(fname, FTP_DIR, strlen(FTP_DIR)) == 0
#endif
#ifdef TMP_DIR
		  || strncmp(fname, TMP_DIR, strlen(TMP_DIR)) == 0
#endif
		  )
		return res;
	else
		return 0;
#elif READ_LEVEL == WRITE_LIMIT_READ
	return check_valid_write( fname, fd );
#else
	// default
	return res;
#endif
#else
	// default
	return res;
#endif
}

int check_valid_write( string fname, int fd )
{
	int res;

#ifdef MESSAGE_FILES
	// Prevent removing .message file from ftp connection.
	if( fname[<8..<0] == "/.message") return 0;
#endif

	seteuid( socket_info[ fd ][ USER_NAME ] );
	res = (int) master() -> valid_write(fname, this_object(), "write_file");
	seteuid( getuid() );

	/*
	 * This rather complicated looking section of code handles the
	 * various write levels available.  See ftpdconf.h for WRITE_LEVEL
	 * definitions of these flags.
	 */
#ifdef WRITE_LEVEL
#if WRITE_LEVEL == VALID_WRITE
	return res;
#elif WRITE_LEVEL == RESTRICTED_WRITE
	if (strncmp(fname, HOME_DIR( UNAME ), strlen(HOME_DIR( UNAME ))) == 0
#ifdef PUB_DIR
		  || strncmp(fname, PUB_DIR, strlen(PUB_DIR)) == 0
#endif
#ifdef FTP_DIR
		  || strncmp(fname, FTP_DIR, strlen(FTP_DIR)) == 0
#endif
#ifdef TMP_DIR
		  || strncmp(fname, TMP_DIR, strlen(TMP_DIR)) == 0
#endif
		  )
		return res;
	else
		return 0;
#elif WRITE_LEVEL == READ_ONLY
	return 0;
#else
	// default
	return res;
#endif
#else
	// default
	return res;
#endif
}

mapping query_sinfo() { return socket_info; }

/* query_connections returns an array of users connected to ftpd */
mapping *query_connections()
{
	mixed *vals;
	mapping *list;
	int count, i;

	return values(socket_info);
	vals = values( socket_info );
	list = allocate( sizeof( vals ) );
	count = sizeof( vals );

	while ( count-- )
		if (!undefinedp( (vals[count])[USER_NAME] ))
			list[i++] = ([
						   USER_NAME :
							 capitalize(( string )((vals[count])[USER_NAME])),
						   USER_SITE :
							 (string)((vals[count])[USER_SITE])
						]);

	return i ? list[0..i-1] : ({ });
}

void create()
{
	set("channel_id", "µµ°¸´«Êä¾«Áé");
	if ( !socket_info ) {
		socket_info = ([  ]);
		temp_map = ([ ]);
		number_of_users = 0;
		seteuid( ROOT_UID );
		call_out( "setup_ftp", 2, FTPD_PORT );
		call_out( "check_connections", 3 * 60 );
	}
}

protected void setup_ftp( int port )
{
	our_socket = socket_create( STREAM, "in_read_callback",
								"in_close_callback" );
	if ( our_socket < 0 ) {
		TP( "Failed to create socket.\n" );
		return;
	}
	if ( socket_bind( our_socket, port ) <  0 ) {
		TP( "Failed to bind socket.\n" );
		socket_close( our_socket );
		return;
	}
	if ( socket_listen( our_socket, "in_listen_callback" ) <  0 ) {
		TP( "Failed to listen to socket.\n" );
		return;
	}
} /* setup_ftp() */

void in_write_callback( int fd )
{
	string address;
	int res;

	if ( undefinedp( socket_info[fd][CONNECTED] ) ) {
		if ( number_of_users > FTPD_MAX_USERS ) {
			res = socket_write( fd,
				  "530 Too many ftp connections active.  Try again later.\n");
			/*
			 * In these cases there isn't much more that can be done
			 */
			if (res != EECALLBACK)
				lose_user( fd );

			/*
			 * The following blocks the code in_read_callback &
			 * in_write_callback on this connection; we let the driver
			 * complete the send and let the daemon timeout the connection
			 */
			if (res == EECALLBACK) {
				socket_info[fd][CONNECTED] = 0;
			}
			return;
		}

		res = socket_write( fd,
			  sprintf( "220- %s FTP server (Version %s (MudOS/LPC)) ready.\n"
#ifdef ANONYMOUS_FTP
					   "220  Please login as yourself or 'anonymous'.\n",
#else
					   "220  Please login as yourself.\n",
#endif
					   THE_MUD_NAME, FTPD_VERSION ) );

		/*
		 * In these cases, assume user will receive above message
		 */
		if (res == EESUCCESS || res == EECALLBACK) {
			socket_info[fd][CONNECTED] = 1;
			if ((address = socket_address(fd)) &&
				  sscanf( address, "%s %*s", address )) {
				socket_info[fd][USER_SITE] = address;
				socket_info[fd][IDLE_SETTING] = FTPD_TIMEOUT;
				temp_map += ([ resolve( address, "resolve_callback" ) : fd ]);
			} else {
				socket_write( fd,
						"451 Error in server: socket_address() failed.\n"
						"221 Closing connection due to server error.\n");
				lose_user( fd );
			}
		} else if (res == EEWOULDBLOCK) {
			call_out( "in_write_callback", 2, fd );
		} else {
			lose_user( fd );
		}
	}
}

/*
 * called for each new ftp login connection
 */
void in_listen_callback( int fd )
{
	int new_fd;

	if ( ( new_fd =
		socket_accept( fd, "in_read_callback", "in_write_callback" ) ) < 0 )
		return;

	number_of_users++;
	socket_info[new_fd] = ([  ]);
	socket_info[new_fd][LAST_DATA] = time();
	in_write_callback( new_fd );
}

string ls( string path, int column, int fd ) {
   string *files;
   int i, j, s;
   mixed *xfiles;
   mixed *stats;
   string tmp, tmp2, creator, domain;

   /* if path is a directory get contents */
   if ( directory_exists( path ) ) {
     if ( path[ strlen( path ) - 1 ] == '/' )
        path += "*";
     else
        path += "/*";
   }

   /* begin narrow columnar "nlst" */
   if (column) {
     files = get_dir( path );

     /* can only happen if permissions are messed up at account level */
     if (!files)
        return "";

     files -= ({ ".", ".." });

     if (!(i = sizeof( files )))
        return "";

     /* no wild cards...must have been the exact pathname to a file */
     if (strsrch(path, '*') == -1 && strsrch(path, '?') == -1) {
        return files[0] + "\n";
     }

     /* remove globber at end of path, leave a trailing slash */
     j = strsrch(path, '/', -1);
     path = path[0..j];

     while ( i-- ) {
        /* scan next level down for files */
        tmp = sprintf("%s%s/", path, files[i]);
        if ( directory_exists( tmp ) ) {
          files[i] += "/";
        }
     }
     return implode( files, "\n" ) + "\n";
   }

   /* begin long "list" */
   xfiles = get_dir( path, -1 );
   if (!xfiles || !(s = sizeof( xfiles )))
     return "";

   files = allocate(s);

   // the Unix-like file permissions are mainly for effect...hopefully it
   // isn't too much, since anything more would likely be too cpu intensive
   // and cause it to max eval...
   creator = (string)MASTER_OB->creator_file(path);
   if (!creator)  creator = ROOT_UID;

   domain = (string)MASTER_OB->domain_file(path);
   if (!domain)  domain = ROOT_UID;

   i = strsrch(path, '/', -1);
   if (i >= 0)
     path = path[0..i];

   for (i = 0; i < s; i++) {
     /* process timestamp */
     tmp2 = ctime((xfiles[i])[2]); /* get last modified timestamp */
     if ((xfiles[i])[2] + SECS_IN_YEAR < time()) {
        /* MMM DD  YYYY */
        tmp = sprintf("%s  %s", tmp2[4..9], tmp2[20..23]);
     } else {
        /* MMM DD hh:mm */
        tmp = tmp2[4..15];
     }

     j = (xfiles[i])[1];   /* get filesize */
     if (j == -2) {
        /* directory */
//        files[i] = sprintf("drwxrwsr-x  %12s  %12s    < DIR >  %12s  %s/",
        files[i] = sprintf("drwxrwsr-x   1 %-8s %-8s            0 %12s %s",
            creator, domain, tmp, (xfiles[i])[0]);
     } else {
        /* file */
        stats = stat(path + (xfiles[i])[0]);
//        files[i] = sprintf("-rw%crw-r--  %12s  %12s  %8d  %12s  %s",
        files[i] = sprintf("-rw%crw-r--   1 %-8s %-8s %12d %12s %s",
            stats[2] ? 'x' : '-', /* 'x' if loaded, else ' ' */
            creator, domain, j, tmp, (xfiles[i])[0]);
     }
   }

   return sprintf( "%s\n", implode( files, "\n" ) );
}


void data_write_callback( int fd )
{
	int pos, length, ret_val;
	buffer tmp;

	if ( socket_info[fd][TYPE] == DOWNLOAD ) return;

	pos = socket_info[fd][POS];
	length = ( (pos+BLOCK_SIZE) >= socket_info[fd][LEN] ) ?
			 ( socket_info[fd][LEN] - pos ) : BLOCK_SIZE;

	socket_info[ socket_info[fd][PARENT_FD] ][LAST_DATA] = time();

	if ( socket_info[fd][TYPE] == STRING ) {
		while ( ((ret_val = socket_write( fd, socket_info[fd][DATA][pos..(pos+BLOCK_SIZE-1)] )) >= 0)
		||	(ret_val==EECALLBACK) ) {
			pos += BLOCK_SIZE;
			if ( pos > socket_info[ fd ][ LEN ] ) {
				socket_write( socket_info[ fd ][ PARENT_FD ], "226 Transfer complete.\n" );
				socket_close( fd );
				map_delete( socket_info[ socket_info[ fd ][ PARENT_FD ] ], DATA_FD );
				return;
			}
			if( ret_val==EECALLBACK ) break;
		}
	} else {
		if (catch( tmp = read_buffer( socket_info[ fd ][ DATA ], pos, length ) )) {
			socket_write( socket_info[ fd ][ PARENT_FD ], "551 Error on input file.\n" );
			socket_close( fd );
			map_delete( socket_info[ socket_info[ fd ][ PARENT_FD ] ], DATA_FD );
			return;
		}

		while ( ((ret_val = socket_write( fd, tmp )) >= 0)
				|| (ret_val==EECALLBACK) ) {
			pos += length;
			if ( pos >= socket_info[ fd ][ LEN ] ) {
				socket_write( socket_info[ fd ][ PARENT_FD ], "226 Transfer complete.\n" );
				socket_close( fd );
				map_delete( socket_info[ socket_info[ fd ][ PARENT_FD ] ], DATA_FD );
				return;
			}
			if( ret_val==EECALLBACK ) break;
			length = ( (pos+BLOCK_SIZE) >= socket_info[ fd ][ LEN ] ) ?
				  ( socket_info[ fd ][ LEN ] - pos ) : BLOCK_SIZE;
			tmp = read_buffer( socket_info[ fd ][ DATA ], pos, length );
		}
	}

	// Advance the position we're sending next time.
	socket_info[ fd ][ POS ] = pos;

	switch(ret_val) {
		case EEWOULDBLOCK:	// data transfer busy (MudOS -> OS)
			call_out("data_write_callback", 2, fd);
		case EECALLBACK:	// data transfer busy (LPC -> MudOS)
			return;
		default:		
#ifdef DEBUG_REPORT
			CHANNEL_D->do_channel(this_object(), "sys",
				"data_write_callback: error " + ret_val + ", wait until next callback.");
#endif
			while ( remove_call_out( "data_write_callback" ) != -1 );
	}
}


protected void data_conn( int fd, string mess, string name, int type )
{
	int new_fd, ret, data_mode;
	string data_mode_name;
	mixed tmp;

	if(	type == STRING
	||	( type == FILE && UTYPE == STRING ) ) {
		data_mode_name = "ASCII";
		data_mode = STREAM;
		tmp = "";
	} else {
		data_mode_name = "BINARY";
		data_mode = STREAM_BINARY;
		tmp = allocate_buffer( 0 );
	}

	if ( socket_info[ fd ][ DATA_FD ] ) {
		socket_write( fd, "425 Can't open data connection.\n" );
		return;
	}
	new_fd = socket_create( data_mode, "data_read_callback",
		  "data_close_callback" );

	if ( new_fd < 0 ) {
		socket_write( fd, "425 Can't create data socket.\n" );
		return;
	}

	if ( ( ret = socket_connect( new_fd, sprintf("%s %d",
		  socket_info[ fd ][ DATA_ADDR ], socket_info[ fd ][ DATA_PORT ]),
		  "data_read_callback", "data_write_callback" ) ) < 0 ) {
//		TP( "Error: " + socket_info[ fd ][ DATA_ADDR ] + " " +
//			socket_info[ fd ][ DATA_PORT ] + "\n" );
//		TP( socket_error( ret ) + "\n" );
		socket_write( fd, "425 Can't build data connection.\n" );
		socket_close( new_fd );		return;
	}

	socket_info[ new_fd ] = ([
		DATA	  : (type == STRING ? replace_string(mess, "\n", "\r\n") : mess),
		POS	   : 0,
		PARENT_FD : fd,
		TYPE	  : type,
		LEN	   : (type == STRING ? strlen(mess) : file_size(mess))
	]);

	socket_info[ fd ][ DATA_FD ] = new_fd;

	socket_write( fd, sprintf("150 Opening %s mode data connection for %s "
		  "(%d bytes).\n", data_mode_name, name, socket_info[ new_fd ][ LEN ]));
}

protected void read_connection( int fd, string path, int append )
{
	int new_fd, ret, data_mode;
	string data_mode_name;
	mixed tmp;

	if ( UTYPE == BINARY ) {
		data_mode_name = "BINARY";
		data_mode = STREAM_BINARY;
		tmp = allocate_buffer( 0 );
	} else {
		data_mode_name = "ASCII";
		data_mode = STREAM;
		tmp = "";
	}

	if ( socket_info[ fd ][ DATA_FD ] ) {
		socket_write( fd, "425 Can't open data connection.\n" );
		return;
	}

	new_fd = socket_create( data_mode, "data_read_callback",
							"data_close_callback" );

	if ( new_fd < 0 ) {
		socket_write( fd, "425 Can't create data socket.\n" );
		return;
	}

	if ( ( ret = socket_connect( new_fd, sprintf("%s %d",
		  socket_info[ fd ][ DATA_ADDR ], socket_info[ fd ][ DATA_PORT ]),
		  "data_read_callback", "data_write_callback" ) ) < 0 ) {
		TP( "Error: " + socket_info[ fd ][ DATA_ADDR ] + " " +
			socket_info[ fd ][ DATA_PORT ] + "\n" );
		TP( socket_error( ret ) + "\n" );
		socket_write( fd, "425 Can't build data connection.\n" );
		socket_close( new_fd );
		return;
	}

	socket_info[ new_fd ] = ([
		PATH	  : path,
		PARENT_FD : fd,
		DATA	  : tmp,
		TYPE	  : DOWNLOAD,
		APPEND	: append
	]);

	socket_info[ fd ][ DATA_FD ] = new_fd;

	socket_write( fd, sprintf("150 Opening %s mode data connection for %s.\n",
		  data_mode_name, path) );
}  /* read_connection() */


void data_read_callback( int fd, mixed mess )
{
	if ( socket_info[ fd ][ TYPE ] != DOWNLOAD )
		return;

	socket_info[ socket_info[ fd ][ PARENT_FD ]][ LAST_DATA ] = time();

	if ( stringp( mess ) )
		mess = replace_string( mess, "\r", "" );

	socket_info[ fd ][ DATA ] += mess;
}  /* data_read_callback() */
void data_close_callback( int fd )
{
	int pos, size, res;

	if ( socket_info[ fd ][ TYPE ] == DOWNLOAD ) {
		if ( socket_info[ fd ][ APPEND ] != 1 )
			catch( rm( socket_info[ fd ][ PATH ] ) );
		else pos = file_size( socket_info[ fd ][ PATH ] );

		do {
			if (catch( res = write_buffer( UPATH, pos,
									   UDATA[pos..(pos+(BLOCK_SIZE-1))] ) ))
				socket_write( socket_info[ fd ][ PARENT_FD ],
					  "452 Error writing file.\n");
			if (res)
				pos += BLOCK_SIZE;
		} while (res);

		size = stringp( UDATA ) ? strlen( UDATA ) : sizeof( UDATA );

#ifdef FILE_LOCKING
		flock_wrapper( socket_info[ fd ][ PATH ], F_UNLOCK,
			  socket_info[ fd ][ PARENT_FD ]);
#endif

		if ( socket_info[ fd ][ APPEND ] == -1)
			socket_write( socket_info[ fd ][ PARENT_FD ],				  sprintf("226 Transfer complete (unique file name:%s).\n",
				  socket_info[ fd ][ PATH ]) );		else
			socket_write( socket_info[ fd ][ PARENT_FD ],					  "226 Transfer complete.\n" );
	}

	/*
	 * only close data connections here
	 */
	if (!undefinedp( socket_info[fd][PARENT_FD] )) {
		socket_close( fd );
		map_delete( socket_info[ socket_info[ fd ][ PARENT_FD ] ],
			  DATA_FD );
	}
}  /* data_close_callback() */


protected void logout( int fd )
{
	socket_info[ fd ][ LOGGED_IN ] = 0;
	if ( UNAME ) {
#ifdef LOG_TIME
		// message("channel:ftp","¡¾FTP¡¿" + FTP_TIME + "\n",users());
		log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_CONNECT
		message("channel:ftp","¡¾FTP¡¿" + sprintf("%s logged out from %s.\n", UNAME, USITE) + "\n",users());
		log_file( LOG_FILE, sprintf("%s logged out from %s.\n", UNAME, USITE) );
#endif

	}
}  /* logout() */


/*
 * parse user command
 */
protected void parse_comm( int fd, string str ){
	string *command, tmp, tmp2;	mixed *misc;
	int port, i, s;
	TP( "Parsing " + str + ".\n" );	command = explode( str, " " );
	socket_info[ fd ][ LAST_DATA ] = time();

	switch( lower_case( command[ 0 ] ) )  {
		case "port": // specify data connection port
			command = explode( implode( command[1..1000], " " ), "," );
			if ( sizeof( command ) < 6 )
				socket_write( fd, "550 Failed command.\n" );
			else {
				socket_info[ fd ][ DATA_ADDR ] = implode( command[ 0..3 ], "." );
				sscanf( command[ 4 ], "%d", i );
				port = i << 8;
				i = atoi( command[5] );
				port += i;
				socket_info[ fd ][ DATA_PORT ] = port;
				socket_write( fd, "200 PORT command successful.\n" );
			}
			break;
		case "user": // specify user name
			if ( socket_info[ fd ][ LOGGED_IN ] ) {
				logout( fd );
				UNAME = 0;
			}

			CHECK_CMD(1);

			if ( !check_access( command[ 1 ] ) ) {
				socket_write( fd, sprintf("530 User %s access denied.\n",
					  command[ 1 ]) );
#ifdef LOG_TIME
				// message("channel:ftp","¡¾FTP¡¿" + FTP_TIME + "\n",users());
				log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_NO_CONNECT
				message("channel:ftp","¡¾FTP¡¿" + sprintf("%s denied access from %s.\n",
					  command[ 1 ], USITE) + "\n",users());
				log_file( LOG_FILE, sprintf("%s denied access from %s.\n",
					  command[ 1 ], USITE) );
#endif
			} else {
#ifdef ANONYMOUS_FTP
				if ( command[ 1 ] == "anonymous" )
					socket_write( fd,
	"331 Guest login ok, send your complete E-mail address as password.\n" );
				else
#endif
					socket_write( fd, sprintf(
						  "331 Password required for %s.\n", command[ 1 ]) );
				UNAME = command[ 1 ];
			}
			break;
		case "pass": // specify password
			if ( socket_info[fd][LOGGED_IN] || !socket_info[fd][USER_NAME] ) {
				socket_write( fd, "503 Log in with USER first.\n" );
				break;
			}

			if ( !check_password( socket_info[fd][ USER_NAME ],
				  implode( command[ 1..sizeof( command ) - 1 ], " " ) ) ) {
#ifdef ANONYMOUS_FTP
				if (UNAME == "anonymous")
					socket_write( fd,
"530 Login failed.  Please send your complete E-mail address as password.\n" );
				else
#endif
					socket_write( fd, "530 Login incorrect.\n" );

#ifdef LOG_TIME
				// message("channel:ftp","¡¾FTP¡¿" + FTP_TIME + "\n",users());
				log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_NO_CONNECT
				message("channel:ftp","¡¾FTP¡¿" + sprintf(
					  "%s failed/incorrect login from %s.\n", UNAME, USITE) + "\n",users());
				log_file( LOG_FILE, sprintf(
					  "%s failed/incorrect login from %s.\n", UNAME, USITE) );
#endif
				UNAME = 0;
			} else
#ifdef CHECK_SITE
			if (!check_site( UNAME, fd )) {
				/*
				 * Note: this particular response of 530 is not mentioned
				 * as a possible response to the PASS command in RFC959,
				 * because site checking is TMI specific.
				 */
				socket_write( fd, sprintf("530 User %s: Can't login from %s.\n",
					  UNAME, USITE) );
#ifdef LOG_TIME
				// message("channel:ftp","¡¾FTP¡¿" + FTP_TIME + "\n",users());
				log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_NO_CONNECT
				message("channel:ftp","¡¾FTP¡¿" + sprintf("%s refused login from %s.\n",
					  UNAME, USITE) + "\n",users());
				log_file( LOG_FILE, sprintf("%s refused login from %s.\n",
					  UNAME, USITE) );
#endif
				UNAME = 0;
				lose_user( fd );
			} else
#endif
			{
				socket_info[ fd ][ LOGGED_IN ] = 1;
#ifdef ANONYMOUS_FTP
				if ( UNAME == "anonymous" )
					UCWD = FTP_DIR;
				else
#endif
					UCWD = HOME_DIR( UNAME );
#ifdef LOG_TIME
				// message("channel:ftp","¡¾FTP¡¿" + FTP_TIME + "\n",users());
				log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_CONNECT
#ifdef ANONYMOUS_FTPSSS
				if (UNAME == "anonymous")
                                        message("channel:ftp","¡¾FTP¡¿" + sprintf("%s (%s) connected from %s.\n",
						  UNAME, str[strlen(command[0]) + 1..<1], USITE) + "\n",users());
					log_file( LOG_FILE, sprintf("%s (%s) connected from %s.\n",
						  UNAME, str[strlen(command[0]) + 1..<1], USITE) );
				else
#endif
					message("channel:ftp","¡¾FTP¡¿" + sprintf("%s connected from %s.\n",
						  UNAME, USITE) + "\n",users());
					log_file( LOG_FILE, sprintf("%s connected from %s.\n",
						  UNAME, USITE) );
#endif

				if ( !directory_exists( UCWD ) ) {
					socket_write( fd, "230 No directory! Logging in with home="
#ifdef GUEST_WIZARD_FTP
						  PUB_DIR ".\n" );
					socket_info[ fd ][ CWD ] = PUB_DIR;
#else
						  "/\n" );
					socket_info[ fd ][ CWD ] = "/";
#endif
				} else {
#ifdef LOGIN_MSG
					tmp = read_file( LOGIN_MSG );
					tmp = tmp[0..<2];
					tmp = sprintf("230- %s\n",
						  replace_string( tmp, "\n", "\n230- " ) );
					socket_write( fd, tmp );
#endif
#ifdef ANONYMOUS_FTP
					if (UNAME == "anonymous")
						socket_write( fd,
					  "230 Guest login ok, access restrictions apply.\n" );
					else
#endif ANONYMOUS_FTP
					socket_write( fd, sprintf(
						  "230 User %s logged in successfully.\n", UNAME) );
				}
				socket_info[ fd ][ TYPE ] = STRING;
			}
			break;
		case "allo": // allocate storage (vacuously)
			socket_write( fd, "202 ALLO command ignored.\n" );
			break;
		case "noop": // do nothing
			socket_write( fd, "200 NOOP command successful.\n" );
			break;
		case "retr": // retrieve a file
			CHECK_LOGIN();
			CHECK_CMD(1);
			tmp = get_path( fd, command[ 1 ] );
			if ((i = file_size(tmp)) == -2) {
				socket_write( fd, sprintf("550 %s: Not a plain file.\n",
					  command[1]));
			} else if (i == -1) {
				socket_write( fd, sprintf(
					  "550 %s: No such file or directory(%s).\n", command[1], tmp));
			} else if ( !check_valid_read( tmp, fd ) )  {
				PERMISSION_DENIED550(command[ 1 ]);
			} else {
#ifdef LOG_TIME
				// message("channel:ftp","¡¾FTP¡¿" + FTP_TIME + "\n",users());
				log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_FILE
				message("channel:ftp","¡¾FTP¡¿" + sprintf("%s retr %s (%s).\n",
					  UNAME, tmp, (UTYPE == BINARY ? "BINARY" : "ASCII") ) + "\n",users());
				log_file( LOG_FILE, sprintf("%s retr %s (%s).\n",
					  UNAME, tmp, (UTYPE == BINARY ? "BINARY" : "ASCII") ) );
#endif
				data_conn( fd, tmp, command[ 1 ], FILE );
			}
			break;
		case "stou": // store a file with a unique name
			CHECK_LOGIN();
			CHECK_CMD(1);
			tmp = get_path( fd, command[ 1 ] );
			i = file_size(tmp);
			if (i >= 0 && check_valid_write( tmp, fd )) {
				for (i = MAX_UNIQUE_TRIES; i; i--) {
					if (file_size(sprintf("%s%d", tmp, i)) == -1)
						break;
				}
				if (i) {
					tmp = sprintf("%s%d", tmp, i);
#ifdef FILE_LOCKING
					if (flock_wrapper(tmp, F_LOCK, fd)) {   /* parent fd */
#endif

#ifdef LOG_TIME
						// message("channel:ftp","¡¾FTP¡¿" + FTP_TIME + "\n",users());
						log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_FILE
						message("channel:ftp","¡¾FTP¡¿" + sprintf("%s stou %s (%s).\n", UNAME,
							  tmp, (UTYPE == BINARY ? "BINARY" : "ASCII") ) + "\n",users());
						log_file( LOG_FILE, sprintf("%s stou %s (%s).\n", UNAME,
							  tmp, (UTYPE == BINARY ? "BINARY" : "ASCII") ) );
#endif
						read_connection( fd, tmp, -1 );
#ifdef FILE_LOCKING
					} else {
						PERMISSION_DENIED550(command[ 1 ]);
					}
#endif
				} else {
					socket_write( fd, "452 Unique file name cannot be created.\n");
				}
			} else {
				PERMISSION_DENIED553(command[ 1 ]);
			}
			break;
		case "stor": // store a file
			CHECK_LOGIN();
			CHECK_CMD(1);
			tmp = get_path( fd, command[ 1 ] );
			if ( file_size(tmp) != -2 && check_valid_write( tmp, fd ) ) {
#ifdef FILE_LOCKING
				if (flock_wrapper(tmp, F_LOCK, fd)) {   /* parent fd */
#endif

#ifdef LOG_TIME
					// message("channel:ftp","¡¾FTP¡¿" + FTP_TIME + "\n",users());
					log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_FILE
					message("channel:ftp","¡¾FTP¡¿" + sprintf("%s stor %s (%s).\n", UNAME,
						  tmp, (UTYPE == BINARY ? "BINARY" : "ASCII") )  + "\n",users());
					log_file( LOG_FILE, sprintf("%s stor %s (%s).\n", UNAME,
						  tmp, (UTYPE == BINARY ? "BINARY" : "ASCII") ) );
#endif
					read_connection( fd, tmp, 0 );
#ifdef FILE_LOCKING
				} else {
					PERMISSION_DENIED550(command[ 1 ]);
				}
#endif
			} else {
				PERMISSION_DENIED553(command[ 1 ]);
			}
			break;
		case "appe": // append to a file
			CHECK_LOGIN();
			CHECK_CMD(1);
			tmp = get_path( fd, command[ 1 ] );
			if ( file_size(tmp) >= 0 && check_valid_write( tmp, fd ) ) {
#ifdef FILE_LOCKING
				if (flock_wrapper(tmp, F_LOCK, fd)) {   /* parent fd */
#endif

#ifdef LOG_TIME
					// message("channel:ftp","¡¾FTP¡¿" + FTP_TIME + "\n",users());
					log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_FILE
					message("channel:ftp","¡¾FTP¡¿" + sprintf("%s appe %s (%s).\n", UNAME,
						  tmp, (UTYPE == BINARY ? "BINARY" : "ASCII") ) + "\n",users());
					log_file( LOG_FILE, sprintf("%s appe %s (%s).\n", UNAME,
						  tmp, (UTYPE == BINARY ? "BINARY" : "ASCII") ) );
#endif
					read_connection( fd, tmp, 1 );
#ifdef FILE_LOCKING
				} else {
					PERMISSION_DENIED550(command[ 1 ]);
				}
#endif
			} else {
				PERMISSION_DENIED553(command[ 1 ]);
			}
			break;
		case "dele": // delete a file
			CHECK_LOGIN();
			CHECK_CMD(1);
			tmp = get_path( fd, command[ 1 ] );
			if ((i = file_size(tmp)) == -2) {
				socket_write( fd, sprintf("550 %s: Not a plain file.\n",
					  command[1]));
			} else if (i == -1) {
				socket_write( fd, sprintf(
					  "550 %s: No such file or directory.\n", command[1]));
			} else if ( check_valid_write( tmp, fd ) ) {
#ifdef FILE_LOCKING
				if (flock_wrapper(tmp, F_LOCK, fd)) {   /* parent fd */
#endif

#ifdef LOG_TIME
					// message("channel:ftp","¡¾FTP¡¿" + FTP_TIME + "\n",users());
					log_file( LOG_FILE, FTP_TIME );
#endif

#ifdef LOG_FILE
					message("channel:ftp","¡¾FTP¡¿" + sprintf("%s dele %s.\n", UNAME, tmp) + "\n",users());
					log_file( LOG_FILE, sprintf("%s dele %s.\n", UNAME, tmp) );
#endif
					catch( i = rm(tmp) );
					if (i)
						socket_write( fd, "250 DELE command successful.\n" );
					else
						socket_write( fd, sprintf(
							  "550 Permission denied to %s.\n", command[ 1 ]) );
#ifdef FILE_LOCKING
					flock_wrapper(tmp, F_UNLOCK, fd);   /* parent fd */
				} else {
					PERMISSION_DENIED550(command[ 1 ]);
				}
#endif
			} else {
				PERMISSION_DENIED553(command[ 1 ]);
			}
			break;
		/* Supposed to return modified time in the format: YYYYMMDDHHMMSS */
		case "mdtm": // show last modification time of file
			CHECK_LOGIN();
			CHECK_CMD(1);
			tmp = get_path( fd, command[ 1 ] );
			if ( check_valid_read( tmp, fd ) ) {
				if ((i = file_size(tmp)) == -2)
					socket_write( fd, sprintf("550 %s: Not a plain file.\n",
						  command[1]));
				else if (i == -1)
					socket_write( fd, sprintf(
						  "550 %s: No such file or directory.\n", command[1]));
				else {
					misc = stat(tmp);
					tmp