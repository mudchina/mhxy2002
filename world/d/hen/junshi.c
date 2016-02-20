// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "¾üÊÂÑ§½ÌÊÒ");
  set ("long", @LONG

        ÕâÀïÄã¿ÉÒÔÊäÈë [1;32mxue_junshi [m À´Ñ§Ï°¾üÊÂÑ§¿Î³Ì¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "north": __DIR__"xxroad2",
]));

        setup();
}

void init()
{
                add_action("do_xuexi","xue_junshi");
}

int do_xuexi()
{
        object ob = this_player();
        int fee;        
        int age=ob->query("hen/age");
        string lv;
        
        if( ob->query("hen/combat_ski") < 500 )
        {
        fee=(age+1)*10+50;
        lv="[31m¡²³õ¼¶¡³[m";
        }

        if( ob->query("hen/combat_ski") >= 500 )
        {
        fee=(age+1)*20+100;
        lv="[32m¡²ÖÐ¼¶¡³[m";
        }

        if( ob->query("hen/combat_ski") >= 5000 )
        {
        fee=(age+1)*30+200;
        lv="[33m¡²¸ß¼¶¡³[m";        
        }

        if( !present("zhandou ji",ob) ) return 0;

        if( ob->query("hen/money") < fee ) 
                return notify_fail("ÄãµÄÇ®²»¹»Ñ§Ï°¾üÊÂÑ§¿Î³Ì¡£\n");

        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/money",-fee);
        ob->add("hen/life",-6);
        ob->add("hen/happy",-4);
        ob->add("hen/satisfy",-4);
        ob->add("hen/dirty",5);


                cat(MILITARY);
                write("Ëï×Ó±ø·¨ÊÇÖÐ¹ú±ø·¨Êé....\n");
        write("Äã»¨ÁË "+fee+" ÔªÑ§Ï°¾üÊÂÑ§"+lv+"¿Î³Ì¡£\n");
        ob->query("hen/combat_ski")<10000?ob->add("hen/combat_ski",1):
        ob->set("hen/combat_ski",10000);
        ob->add("hen/might",1);
        return 1;
}
