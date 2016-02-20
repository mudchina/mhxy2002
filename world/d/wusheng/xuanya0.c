// changan wusheng
// xuanya0.c

inherit ROOM;

void create()
{
  set ("short", "石阶");
  set ("long", @LONG

峭壁就在面前，像镜子一样。
LONG);
set("exits", ([ /* sizeof() == 4 */
  "south": __DIR__"shijie8",
//      "up": __DIR__"xuanya1",
]));
set("objects", ([
        "/d/wusheng/npc/laozhe": 1]));
        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
       object laozhe;
       object me=this_player();
 
       if( (!arg) || !((arg == "xuanya") || (arg == "悬崖")))
	       return notify_fail("爬什么？\n");
       if (me->is_busy()) return notify_fail("你现在正忙着呢。");
       if( me->query("kee") < (int)(me->query("max_kee")/3)){
	       me->receive_damage("kee",(int)me->query("max_kee")*20/100);
               return notify_fail("你身子发虚，一头栽了下来，哎呀！\n");
}
       if (!((string)me->query("family/family_name")=="武圣门" )&&
       objectp(laozhe = present("laozhe", environment(me))) && living(laozhe))
{
	       message_vision("老者拦道：此间并非戏耍之处，请勿骚扰我仙家清修\n", me);
}
       else
{
       if ((int)me->query_skill("dodge", 1)<100 && (int)me->query_skill("mizongbu", 1) < 100)
{
	       message_vision("$N小心翼翼的往上爬了一点，觉得头晕眼花，就赶紧爬了下来．\n", me);
	       me->improve_skill("dodge", 100-me->query("str"));
	       tell_object(me, "你领悟出一些基本轻功方面的窍门。\n");
}
      else
{
	       message_vision("$N纵身往悬崖上一跳，接着爬入高耸入云的悬崖不见了。\n", me);
               me->move(__DIR__"xuanya1.c");
}
}
	       me->receive_damage("kee", (int)me->query("max_kee")*10/100);
	       return 1;
}


