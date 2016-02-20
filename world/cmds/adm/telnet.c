//Cracked by Roath
/* lpMud socket( telnet )
 * author : evilgod@SZU
* modify by :netplay@CCTX
 * last update : 98-10-20
 */
#include <ansi.h>
#include <net/dns.h>
#include <net/telnet.h>
#include <net/socket.h>
#include <net/socket_errors.h>
#include <socket_err.h>

inherit ITEM;

static int my_socket,socket1,socket2;
static object me;

void create()
{
set_name("上线器", ({ "telnet" }) );
        set("long",
                  "这是火云邪神创造的用来连接其他 mud 的精灵。\n用法是telnet ip prot\n用 / 信息");
set("value", 1000000);
                set_weight(3000);
set("wear","1");
                set_max_encumbrance(0);
                if( clonep() )
                        set_default_object(__FILE__);
                else {
                        set("unit", "个");
                        set("material", "unknow");
                }
        setup();
}

void init()
{       
        object ob;

        if( interactive(ob = this_player()) ) {
                add_action("close_socket","close");
                add_action("write_message","/");
                add_action("do_telnet","telnet");
                me = ob;
        }
}

void tell_me(string arg)
{
        tell_object(environment(this_object()),arg);
}

int do_telnet(string arg)
{
        int err;
        if( query("connected") )        socket_close(my_socket);
        my_socket = socket_create( STREAM, "in_read_callback","in_close_callback" );
        if ( my_socket < 0 ) {
                tell_me( "Failed to create socket.\n" );
                return 1;
        }
        err = socket_connect( my_socket, arg , "read_callback","write_callback" );
        if( err==EESUCCESS ) {
                        tell_me("Connect to " + arg + "\n");
                        set("connected",1);
        }
        else
                        tell_me("Can't connect to " + arg + "\n");
        return 1;
}

int close_socket()
{
        if( query("connected") )  {
                        if( socket_close(my_socket) ) {
                                tell_me("Closed telnet socket.\n");
                                delete("connected");
                        }
                        else
                                tell_me("Close telnet socket fail.\n");
                }
        else
                tell_me("Not connected.\n");
        return 1;
}

void read_callback(int fd, mixed message)
{
         message = BOLD + "上线器>" + NOR + message;
        tell_me( (string) message );
}

void write_callback(int fd)
{
        int res;
        if(query("connect"))return ;
        res = socket_write( fd,"");
        if (res == EESUCCESS || res == EECALLBACK) {
                set("connected",1);
        }
}

int write_message(string arg)
{
        if( !arg ) arg="";
        socket_write(my_socket,arg+"\n");
        return 1;
}




