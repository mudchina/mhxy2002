// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "ÔèÌÃ");
  set ("long", @LONG

        ÕâÊÇ¸øÐ¡¼¦Ï´ÔèµÄµØ·½£¬Èç¹ûÄãµÄÐ¡¼¦ÔàÁË£¬¾Íµ½Õâ[1;33m wash [mÒ»ÏÂ¡£
LONG);

  set("exits", ([ /* sizeof() == 4 */
        "east": __DIR__"road1",
]));

        setup();
}

void init()
{
                add_action("do_wash","wash");
}

int do_wash()
{
        object ob = this_player();
        
        if( !present("zhandou ji",ob) ) return 0;

        ( ob->query("hen/dirty") <= 20 )?ob->set("hen/dirty",0):
        ob->add("hen/dirty",-20);
        ob->add("hen/life",-2);
        ob->command_function("cls");
        ob->command_function("shape");
        cat(BATHE);

        return 1;
}
