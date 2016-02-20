// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "Ä§·¨½ÌÊÒ");
  set ("long", @LONG

        ÕâÀïÄã¿ÉÒÔÊäÈë [1;32mxue_magic [m À´Ñ§Ï°Ä§·¨¿Î³Ì¡£

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "south": __DIR__"xxroad4",
]));

        setup();
}

void init()
{
                add_action("do_xuexi","xue_magic");
}

int do_xuexi()
{
        object ob = this_player();
        int fee;        
        int age=ob->query("hen/age");
        string lv;
        
        if( ob->query("hen/max_fali") < 500 )
        {
        fee=(age+1)*10+50;
        lv="[31m¡²³õ¼¶¡³[m";
        }

        if( ob->query("hen/max_fali") >= 500 )
        {
        fee=(age+1)*20+100;
        lv="[32m¡²ÖÐ¼¶¡³[m";
        }

        if( ob->query("hen/max_fali") >= 5000 )
        {
        fee=(age+1)*30+200;
        lv="[33m¡²¸ß¼¶¡³[m";        
        }

        if( !present("zhandou ji",ob) ) return 0;

        if( ob->query("hen/money") < fee ) 
                return notify_fail("ÄãµÄÇ®²»¹»Ñ§Ï°Ä§·¨¿Î³Ì¡£\n");

        ob->command_function("cls");
        ob->command_function("shape");

        ob->add("hen/money",-fee);
        ob->add("hen/life",-6);
        ob->add("hen/happy",-4);
        ob->add("hen/satisfy",-4);
        ob->add("hen/dirty",5);

	
	switch(random(2))
	{
		case 0:
                cat(MAGIC1);
		write("Éßµ¨+ó¬òæÎ²+ÊóÑÀ+ó¸òÜ=??\n");
		break;

		case 1:
		cat(MAGIC2);
		write("ÎÒ±ä ÎÒ±ä ÎÒ±ä±ä±ä..\n");
		break;
	}


        write("Äã»¨ÁË "+fee+" ÔªÑ§Ï°Ä§·¨"+lv+"¿Î³Ì¡£\n");
        ob->query("hen/max_fali")<50000?ob->add("hen/max_fali",2):
        ob->set("hen/max_fali",50000);
        return 1;
}
