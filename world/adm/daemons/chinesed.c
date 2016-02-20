// chinese_d.c

#include <localtime.h>
#include <ansi.h>
#ifndef DATA_DIR
#define DATA_DIR 	"/data/"
#endif

#define DICTIONARY DATA_DIR + "chinese"

inherit F_SAVE;

static string *c_digit = ({ "Áã","Ê®","°Ù","Ç§","Íò","ÒÚ","Õ×" });
static string *c_num = ({"Áã","Ò»","¶ş","Èı","ËÄ","Îå","Áù","Æß","°Ë","¾Å","Ê®"});
static string *sym_tien = ({ "¼×","ÒÒ","±û","¶¡","Îì","¼º","¸ı","ĞÁ","ÈÉ","¹ï" });
static string *sym_dee = ({ "×Ó","³ó","Òú","Ã®","³½","ËÈ","Îç","Î´","Éê","ÓÏ","Ğç","º¥" });


mapping dict = ([]);

//void add_translate( string key, string chinz );
//void remove_translate( string key );
void create();
string query_save_file();
void remove();
string chinese_year ( int i );
string chinese_number ( int num );
string chinese( string str );
void remove_translate( string key );
void add_translate( string key, string chinz );
void remove_translate( string key );
void dump_translate();
varargs string chinese_date( int date, int real_time );
string chinese_period( int t );
string ansi_color( string str );
int ansi_count( string str );
string ansi_display( string str, int length );
int check_chinese(string name);
int check_return(string name);
int check_space(string name);
int check_control(string name);
int check_length(string str);
string chinese_month(int date);
string chinese_monthday(int date);

void create()
{
	seteuid(getuid());
	restore();
}

void remove() { save(); }

string chinese_month(int date)
{
        mixed *local;
        local = localtime(date);
        return sprintf("%s",chinese_number(local[LT_MON] + 1));
}
string chinese_monthday(int date)
{
        mixed *local;
        local = localtime(date);
        return sprintf("%sÔÂ%sÈÕ",chinese_number(local[LT_MON] + 1),
                chinese_number(local[LT_MDAY]+1));
}

string chinese_year ( int i )
{
	if( i == 0 ) return ""; 

	if( i < 0 ) return "¸º" + chinese_year ( -i );	

	if( i > 0 )
		return chinese_year( i / 10 ) + c_num[i % 10];
}

string chinese_number(int i)
{
	if( i<0 ) return "¸º" + chinese_number(-i);
	if( i<11 ) return c_num[i];
	if( i<20 ) return c_num[10] + c_num[i-10];
	if( i<100 ) {
		if( i%10 ) return c_num[i/10] + c_digit[1] + c_num[i%10];
		else return c_num[i/10] + c_digit[1];
	}
	if( i<1000 ) {
		if( i%100==0 )
			return c_num[i/100] + c_digit[2];
		else if( i%100 < 10 )
			return c_num[i/100] + c_digit[2] + c_num[0] + chinese_number(i%100);
		else if( i%100 < 20 )
			return c_num[i/100] + c_digit[2] + c_num[1] + chinese_number(i%100);
		else return c_num[i/100] + c_digit[2] + chinese_number(i%100);
	}
	if( i<10000 ) {
		if( i%1000==0 )
			return c_num[i/1000] + c_digit[3];
		else if( i%1000 < 100 )
			return c_num[i/1000] + c_digit[3] + c_digit[0] + chinese_number(i%1000);
		else
			return c_num[i/1000] + c_digit[3] + chinese_number(i%1000);
	}
	if( i<100000000 ) {
		if( i%10000==0 )
			return chinese_number(i/10000) + c_digit[4];
		else if( i%10000 < 1000 )
			return chinese_number(i/10000) + c_digit[4] + c_digit[0] + chinese_number(i%10000);
		else
			return chinese_number(i/10000) + c_digit[4] + chinese_number(i%10000);
	}
	if( i<1000000000000 ) {
		if( i%100000000==0 )
			return chinese_number(i/100000000) + c_digit[5];
		else if( i%100000000 < 10000000 )
			return chinese_number(i/100000000) + c_digit[5] + c_digit[0] + chinese_number(i%100000000);
		else
			return chinese_number(i/100000000) + c_digit[5] + chinese_number(i%100000000);
	}
		if( i%1000000000000==0 )
			return chinese_number(i/1000000000000) + c_digit[6];
		else if( i%1000000000000 < 100000000000 )
			return chinese_number(i/1000000000000) + c_digit[6] + c_digit[0] + chinese_number(i%1000000000000);
		else
			return chinese_number(i/1000000000000) + c_digit[6] + chinese_number(i%1000000000000);
}

string query_save_file() { return DICTIONARY; }

// This is called by to_chinese() simul_efun
string chinese(string str)
{
	if( !undefinedp( dict[str] ) ) return dict[str];
	else return str;
}

void remove_translate( string key )
{
	map_delete( dict, key );
	save();
}

void add_translate( string key, string chinz )
{
	dict[key] = chinz;
	save();
}

void dump_translate()
{
	string *k, str;
	int i;

	str = "";
	k = keys(dict);
	for(i=0; i<sizeof(k); i++)
		str += sprintf("%-30s %s\n", k[i], dict[k[i]]);
	write_file("/CHINESE_DUMP", str);
}

string chinese_date(int date)
{
	mixed *local;

	local = localtime(date);

	return sprintf("%s%sÄê%sÔÂ%sÈÕ%sÊ±%s¿Ì",
		sym_tien[local[LT_YEAR]%10], sym_dee[local[LT_YEAR]%12],
		chinese_number(local[LT_MON]+1),
		chinese_number(local[LT_MDAY] + (local[LT_HOUR]>23? 1 : 0)),
		sym_dee[((local[LT_HOUR]+1)%24)/2],
		chinese_number((local[LT_MIN]+1)%2 * 2 + local[LT_MIN]/30 + 1) );
}
string chinese_period(int t)
{
	int y, n, d, h, m, s;
	string time;

	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t % 30;		t /= 30;
	n = t % 12;		t /= 12;
	y = t;

	time = "";

	if(y) time = chinese_number(y) + "ÄêÓÖ";
	if(n) time += chinese_number(n) + "¸öÔÂ"	+ (strlen(time)?"":"ÓÖ");
	if(d) time += chinese_number(d) + "Ìì"		+ (strlen(time)?"":"ÓÖ");
	if(h) time += chinese_number(h) + "Ğ¡Ê±"	+ (strlen(time)?"":"ÓÖ");
	if(m) time += chinese_number(m) + "·Ö"		+ (strlen(time)?"":"ÓÖ");
	time += chinese_number(s) + "Ãë";

	return time;
}

string ansi_color( string str )
{
	str = replace_string(str, "$BLK$", BLK);
	str = replace_string(str, "$RED$", RED);
	str = replace_string(str, "$GRN$", GRN);
	str = replace_string(str, "$YEL$", YEL);
	str = replace_string(str, "$BLU$", BLU);
	str = replace_string(str, "$MAG$", MAG);
	str = replace_string(str, "$CYN$", CYN);
	str = replace_string(str, "$WHT$", WHT);
	str = replace_string(str, "$HIR$", HIR);
	str = replace_string(str, "$HIG$", HIG);
	str = replace_string(str, "$HIY$", HIY);
	str = replace_string(str, "$HIB$", HIB);
	str = replace_string(str, "$HIM$", HIM);
	str = replace_string(str, "$HIC$", HIC);
	str = replace_string(str, "$HIW$", HIW);
	str = replace_string(str, "$NOR$", NOR);

	return str;
}

int ansi_count( string str )
{
	string *sections, ansi;
	int i, count = 0;
	sections = explode( str, "" );
	i = sizeof( sections );
	while( i-- ) {
		if( sscanf( sections[i], "[%sm%*s", ansi ) )
			count += strlen( ansi ) + 3;
	}

	return count;
}

string ansi_display( string str, int length )
{
	string space = "                                                                                                   ";
	int i;

	if( strsrch( str, "" ) == -1 )
		return str;

	if( !length )
		return str;
	if( ( i = length - strlen( str ) + ansi_count( str ) - 1 ) > 0 )
		return str + space[0..i];
	else
		return str;
}

int check_length(string str)
{
	if(!str) return 0;
	else return strlen(str);
}
int check_control(string name)
{
	int i;
	if(!name) return 0;
	i = strlen(name);
	while(i--) {
                if(name[i]==' ' || name[i] == '\n') continue;
                if( name[i]<' ' )  return 1;
	}
	return 0;
}
int check_space(string name)
{
        int i;
        if(!name) return 0;
        i = strlen(name);
        while(i--) {
	if(name[i]== ' ') return 1;
	}
	return 0;
}
int check_return(string name)
{
        int i;
        if(!name) return 0;
        i = strlen(name);
        while(i--) {
        if(name[i]== '\n') return 1;
        }
        return 0;
}

int check_chinese(string name)
{
        int i;
        if(!name) return 0;
        i = strlen(name);
        while(i--) {
                if( i%2==0 && !is_chinese(name[i..<0]) ) return 0;
	}
	return 1;
}
