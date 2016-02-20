// /d/guzhanchang/pomiao.c
inherit ROOM;
int do_out();
void create()
{
        set("short", "破庙");
         set ("long", @LONG
 "这里是一个破庙，
到处贴满了符，看起来相当诡异。
*/.    .   .    *      .
  .\*    .    []           *  __
  */ .   ./\~~~~~~~~~~~~'\. |◆  
   \*   ,/,..,\,...........,\.◆  
   ||  ..▎#  ▎田  田 ▎ | ▎◆
   ||  &&▎   ▎       ▎'|'▎ o   
   || ##■■■■■■■■■■〓   
LONG);
                     
set("exits", ([
                "down" : __DIR__"road0",
                
        ]));
  set("objects", ([
             __DIR__"npc/guiwang" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
 add_action("do_out","out");
}
int do_out()
{
 object room;
 object who = this_player();
  message_vision("$N决定要离开了，不觉心中一轻，飞一般的跑了出去！\n",who);
  who->recieve_damage(who->query("kee")/5);
  who->recieve_wound(who->query("max_kee")/5);
  who->start_busy(5);
  who->move("/d/guzhanchang/mi8");
  return 1;
}

int valid_leave(object me, string dir)
{       
        object a;
        if( wizardp(me)) return 1;

        if (dir == "down") {
                if(objectp(a=present("guiwang", environment(me))) && living(a) )
                return notify_fail("鬼王大叫：“哪里跑？不打死我你进不了九重天！！！”！\n");
        return ::valid_leave(me, dir);
        }

        return 1;
}

