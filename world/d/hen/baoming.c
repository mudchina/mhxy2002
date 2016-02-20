// by happ@YSZZ
inherit ROOM;
#include <ansi.h>
#define RESULT1 "/log/hen_game1"
#define RESULT2 "/log/hen_game2"
#define RESULT3 "/log/hen_game3"
#define RESULT4 "/log/hen_game4"

void create ()
{
  set ("short", "±ÈÈü±¨Ãû´¦");
  set ("long", @LONG

        ±ÈÈü·ÖÎªËÄÏî£º
        
        [1;31m¼ÒÎñ±ÈÈü [m£¬ÇëÊäÈë [1;32mjoin 1[m
        [1;31mÎè»á±ÈÈü [m£¬ÇëÊäÈë [1;32mjoin 2[m
        [1;31mÎÄ»¯±ÈÈü [m£¬ÇëÊäÈë [1;32mjoin 3[m
        [1;31mÃÀÊõ±ÈÈü [m£¬ÇëÊäÈë [1;32mjoin 4[m

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "out" : __DIR__"gate",
        "west":__DIR__"game3",
        "up":__DIR__"game4",
        "east":__DIR__"game2",
        "south":__DIR__"game1",
]));
        set("undo",1);
        set("no_clean_up",1);
        setup();
}
void init()
{
        if( query("undo") )
        {
        delete("undo");
        remove_call_out("wait");
        call_out("wait",1);
        }
        add_action("do_join","join");
}

int do_join(string arg)
{

        int t = time() - query("last_game");
        object ob = this_player();

        if( ! arg ||( arg !="1" && arg !="2" && arg !="3" && arg !="4") )
                return notify_fail("ÄãÒª²Î¼ÓÊ²Ã´±ÈÈü£¿\n");

        if( ! present("zhandou ji",ob)) return notify_fail("ÄãÓĞĞ¡¼¦Âğ£¿\n");

        if( ob->query_temp("hen_game") )
                return notify_fail("ÄãÒÑ¾­²Î¼Ó¹ı±ÈÈüÁË.\n");

        switch(arg)
        {
                case "1":
                ob->set_temp("hen/game_1",1);
                tell_room(this_object(),ob->name()+"±¨Ãû²Î¼Ó¼ÒÎñ´óÈü£¡\n");
                break;

                case "2":
                ob->set_temp("hen/game_2",1);
                tell_room(this_object(),ob->name()+"±¨Ãû²Î¼ÓÎèµ¸´óÈü£¡\n");
                break;

                case "3":
                ob->set_temp("hen/game_3",1);
                tell_room(this_object(),ob->name()+"±¨Ãû²Î¼ÓÎÄ»¯´óÈü£¡\n");
                break;

                case "4":
                ob->set_temp("hen/game_4",1);
                tell_room(this_object(),ob->name()+"±¨Ãû²Î¼ÓÃÀÊõ´óÈü£¡\n");
                break;
        }
        ob->set_temp("hen_game",1);

        set("last_game",time());
        return 1;
}

void wait()
{
        object ob = this_player();
        message("chat",HBRED+HIW"¡¾Ğ¡¼¦¾«Áé¡¿£º±ÈÈü¼´½«¿ªÊ¼£¬·ÖÎªÎèµ¸¡¢ÎÄ»¯¡¢ÃÀÊõ¡¢¼ÒÎñËÄÏî±ÈÈü£¡»¶Ó­±¨Ãû£¡\n"NOR,users());
        message("chat",HBRED+HIW"¡¾Ğ¡¼¦¾«Áé¡¿£º±ÈÈüÒ»·ÖÖÓºó¿ªÊ¼,ÇëÑ¡ÊÖÈë³¡.\n"NOR,users());
        set_temp("can_in",1);
        remove_call_out("check_time");
        call_out("check_time",60);
        remove_call_out("wait");
        call_out("wait",5*60*60);
}

void check_time()
{
        object room1=load_object(__DIR__"game1");
        object room2=load_object(__DIR__"game2");
        object room3=load_object(__DIR__"game3");
        object room4=load_object(__DIR__"game4");


        write_file(RESULT1,"",1);
        write_file(RESULT2,"",1);
        write_file(RESULT3,"",1);    
        write_file(RESULT4,"",1);  
        room1->begin(); room2->begin(); room3->begin(); room4->begin();

        message("chat",HBRED+HIW"¡¾Ğ¡¼¦¾«Áé¡¿£º±ÈÈü¿ªÊ¼£¬Ñ¡ÊÖÍ£Ö¹Èë³¡£¡\n"NOR,users());
        delete_temp("can_in");
        call_out("can_in",60);
}
 
void can_in()
{
        set_temp("can_in",1);
}

int valid_leave(object me, string dir)
{                                                 
        if( ! query_temp("can_in")&& dir != "out")
                return notify_fail("ÏÖÔÚ²»ÄÜ²Î¼Ó±ÈÈü!\n");

return ::valid_leave(me, dir);    
}
