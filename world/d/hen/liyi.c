// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "ÀñÒÇ½ÌÊÒ");
  set ("long", @LONG

        ÕâÀïÄã¿ÉÒÔÊäÈë [1;32mxue_liyi [m À´Ñ§Ï°ÀñÒÇ¿Î³Ì¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "north": __DIR__"xxroad4",
]));

        setup();
}

void init()
{
                add_action("do_xuexi","xue_liyi");
}

int do_xuexi()
{
        object ob = this_player();
        int fee;        
        int age=ob->query("hen/age");
        string lv;
        
        if( ob->query("hen/decorum") < 500 )
        {
        fee=(age+1)*10+50;
        lv="[31m¡²³õ¼¶¡³[m";
        }

        if( ob->query("hen/decorum") >= 500 )
        {
        fee=(age+1)*20+100;
        lv="[32m¡²ÖÐ¼¶¡³[m";
        }

        if( ob->query("hen/decorum") >= 5000 )
        {
        fee=(age+1)*30+200;
        lv="[33m¡²¸ß¼¶¡³[m";        
        }

        if( !present("zhandou ji",ob) ) return 0;

        if( ob->query("hen/money") < fee ) 
                return notify_fail("ÄãµÄÇ®²»¹»Ñ§Ï°ÀñÒÇ¿Î³Ì¡£\n");

        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/money",-fee);
        ob->add("hen/life",-6);
        ob->add("hen/happy",-4);
        ob->add("hen/satisfy",-4);
        ob->add("hen/dirty",5);


	write("(Í¼Æ¬ÔÝÈ±)\n\nÒªµ±Ö»ÓÐÀñÃ²µÄ¼¦...\n");

        write("Äã»¨ÁË "+fee+" ÔªÑ§Ï°ÀñÒÇ"+lv+"¿Î³Ì¡£\n");
        ob->query("hen/decorum")<50000?ob->add("hen/decorum",2):
        ob->set("hen/decorum",50000);
        return 1;
}
