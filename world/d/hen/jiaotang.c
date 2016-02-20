// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "½ÌÌÃ");
  set ("long", @LONG

        ÕâÀïÄã¿ÉÒÔÊäÈë [1;32m  dagong [m ¾Í¿ÉÒÔÔÚ½ÌÌÃÏ×°®ÐÄà¶~~¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "north": __DIR__"syroad3",
]));

        setup();
}

void init()
{
                add_action("do_work","dagong");
}

int do_work()
{
        object ob = this_player();

        if( !present("zhandou ji",ob) ) return 0;


        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/life",-5);
        ob->add("hen/dirty",7);

        cat(CHAPEL);

        if( time() - ob->query("hen/last_jiaotang") < 180 )
        {
        write("¿´À´Ð¡¼¦ºÜÌÖÑáÖØ¸´×öÍ¬Ò»¼þÊÂÇé¡£\n");
        ob->add("hen/affection",-1);
        return 1;
        }

        ob->add("hen/money",100+random(20));
        ob->set("hen/last_jiaotang",time());
        ob->add("hen/love",1);
        ob->add("hen/ethics",1);
        return 1;
}
