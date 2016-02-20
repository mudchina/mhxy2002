//By tianlin@mhxy for 2002.2.26

#include <ansi.h>
inherit ROOM;
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create()
{
	set("short", "麒麟阁");
	set("long",

"\n太宗李世民在即位前受封秦王，手下谋臣勇将为建立李氏王朝立下了\n"+
"汗马功劳。高祖为这些功臣们特起了一座彩楼，名曰"+HIY"「麒麟阁」"NOR+"。此\n"
"楼飞檐挂角，雕梁画栋，吸引了无数百姓前来观看。\n\n"
	);
	set("no_fight", 1);
	set("item_desc", ([ /* sizeof() == 1 */
  "up" : HIC"楼上人声喧哗，想是传杯送盏，酒兴正至半酣。\n"NOR,
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
           __DIR__"npc/qinbing" : 2,
            "/d/jjf/npc/chengyaojin": 1,
]));
	set("light_up", 1);
	set("exits", ([ /* sizeof() == 2 */
       "up" : __DIR__"qilin2",
       "east" : "/d/city/xuanwu-n0",
]));

	setup();
	replace_program(ROOM);
}
void init()
{
    object where=this_object();
    remove_call_out("check_time");
    check_time(where);
    add_action("do_hear","hear");
}
void check_time(object where)
{
   mixed *local = localtime((time()-900000000)*60);
   int t = local[2] * 60 + local[1];

   int phase=((int)(t/120));
   if(phase==5&&(!query("jiangbing"))) jiang_jing(where);
   if(phase==6&&query("jiangbing")) finish_jing(where);
   call_out("check_time",60,where);
}
void jiang_jing(object where)
{
message("channel:chat",CYN+"◇"RED"大唐将军府"CYN"◇"NOR+WHT"程咬金[Cheng yaojin]："CYN"大唐将军府众将演武场点兵。"HIR"(Hear)\n"+NOR,users());
tell_object(where,"你听到程咬金的声音：这样  .  这样   .如此  . 如此。\n");
tell_object(where,"你听到程咬金的声音：枪乃，我们兵家常识，你可要用心听着。\n");
tell_object(where,"........................................\n");
   set("jiangbing",1);
}
void finish_jing(object where)
{
   tell_object(where,"程咬金说道：大家休息一会吧。\n");
   set("jiangbing",0);
}
int do_hear()
{
 object yao;
   object me=this_player();

   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
   if(!query("jiangbing"))
      return notify_fail("还没有开始呢。\n");

 if((string)me->query("family/family_name")!="将军府")
      return notify_fail("你是哪里的？\n");
   if(me->query("faith")>1000)
      return notify_fail("程咬金对你说道：你可以去找些其它的事情做了。\n");
   tell_object(me,"你觉着程咬金讲的对极了。\n");
   me->start_busy(4);
   me->add("faith",1);
   me->add("combat_exp",60);
   me->add("potential",50);
   me->improve_skill("baguazhou",1000);  
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}
