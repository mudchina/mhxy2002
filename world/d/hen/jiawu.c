// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "¼ÒÎñÌü");
  set ("long", @LONG

        ÕâÀïÄã¿ÉÒÔÊäÈë [1;32mzuo_jiawu [m À´Ñ§Ï°×ö¼ÒÎñ£¬Ë³±ã×¬µãÇ®¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "south": __DIR__"syroad1",
]));

        setup();
}

void init()
{
                add_action("do_work","zuo_jiawu");
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

        cat(HOMEWORK);

        if( time() - ob->query("hen/last_jiawu") < 180 )
        {
        write("¿´À´Ð¡¼¦ºÜÌÖÑáÖØ¸´×öÍ¬Ò»¼þÊÂÇé¡£\n");
        ob->add("hen/affection",-1);
        return 1;
        }

        ob->add("hen/money",100+random(20));
        ob->add("hen/evaluation/homework",1);
        ob->set("hen/last_jiawu",time());

        return 1;
}
