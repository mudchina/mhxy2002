// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "á÷ÁÔ³¡");
  set ("long", @LONG

        ÕâÀïÄã¿ÉÒÔÊäÈë [1;32m  shou_lie[m ¾ÍÑ§Ï°´òÁÔ£º£©¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "north": __DIR__"syroad5",
]));

        setup();
}

void init()
{
                add_action("do_work","shou_lie");
}

int do_work()
{
        object ob = this_player();

        if( !present("zhandou ji",ob) ) return 0;


        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/life",-10);
        ob->add("hen/dirty",7);
        ob->add("hen/happy",-7);
        ob->add("hen/satisfy",-7);
        
        cat(HUNTER);

        if( time() - ob->query("hen/last_shoulie") < 180 )
        {
        write("¿´À´Ð¡¼¦ºÜÌÖÑáÖØ¸´×öÍ¬Ò»¼þÊÂÇé¡£\n");
        ob->add("hen/affection",-1);
        return 1;
        }

        ob->add("hen/money",200+random(20));
        ob->add("hen/love",-3);
        ob->add("hen/impurity",3);
        ob->set("hen/last_shoulie",time());
        
        return 1;
}
