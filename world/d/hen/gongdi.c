// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "¹¤µØ");
  set ("long", @LONG

        ÕâÀïÄã¿ÉÒÔÊäÈë [1;32m zuo_kuli [m È¥µ½¹¤µØÉÏÕÒÐ©»î¸É¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "south": __DIR__"syroad5",
]));
        setup();
}

void init()
{
                add_action("do_work","zuo_kuli");
}

int do_work()
{
        object ob = this_player();

        if( !present("zhandou ji",ob) ) return 0;


        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/life",-15);
        ob->add("hen/happy",-10);
        ob->add("hen/satisfy",-10);
        ob->add("hen/dirty",12);

        cat(MILL);

        if( time() - ob->query("hen/last_gongdi") < 180 )
        {
        write("¿´À´Ð¡¼¦ºÜÌÖÑáÖØ¸´×öÍ¬Ò»¼þÊÂÇé¡£\n");
        ob->add("hen/affection",-1);
        return 1;
        }

        ob->add("hen/money",400+random(20));
        ob->set("hen/last_famu",time());
        ob->add("hen/max_life",3);
        return 1;
}
