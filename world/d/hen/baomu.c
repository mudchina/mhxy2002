// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "±£Ä·ÊÂÎïËù");
  set ("long", @LONG

        ÕâÀïÄã¿ÉÒÔÊäÈë [1;32 dai_haizi (´øº¢×Ó) [m À´×öÐ©±£Ä·¹¤×÷À­¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "north": __DIR__"syroad1",
]));

        setup();
}

void init()
{
                add_action("do_work","dai_haizi");
}

int do_work()
{
        object ob = this_player();

        if( !present("zhandou ji",ob) ) return 0;


        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/life",-2);
        ob->add("hen/happy",-4);
        ob->add("hen/satisfy",-4);
        ob->add("hen/dirty",5);

        cat(MATRON);

        if( time() - ob->query("hen/last_baomu") < 180 )
        {
        write("¿´À´Ð¡¼¦ºÜÌÖÑáÖØ¸´×öÍ¬Ò»¼þÊÂÇé¡£\n");
        ob->add("hen/affection",-1);
        return 1;
        }

        ob->add("hen/money",100+random(20));
        ob->add("hen/evaluation/homework",1);
        ob->add("hen/love",1);
        ob->set("hen/last_baomu",time());

        return 1;
}
