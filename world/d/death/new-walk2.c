//By tianlin@mhxy for 2001.12.30制作

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "奉祭场");
  set ("long", @LONG

奉祭场中有一四方高台，台上刻有日月星辰，山川大河的图腾。台
上的铜鼎里偶有青烟生起，四周但见磷火阵阵，闪冒银光。四周有
一座座的楼阁宫殿，看起来也相当的富丽堂皇，间有几个索命鬼，
勾司人走来走去。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"new-walk3",
  "west" : __DIR__"new-walk4",
  "north" : __DIR__"new-walk5",
  "south": __DIR__"new-zhaopo",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhangmen" : 1,
]));
  set("valid_startroom", 1);

  setup();
}

void init()
{
        add_action("do_enter", "enter");
}
int do_enter()
{
	object me=this_player();
	me=this_player();
       if ( (string)me->query("family/family_name")=="阎罗地府"){
       if(me->query("combat_exp")<2000000)
              return notify_fail(HIY"你没有资格进去见冥王.\n"HIC"就算进去了,冥王也不会见你的\n"NOR);
       if(me->query("daoxing")<2000000)
              return notify_fail(HIY"你没有资格进去见冥王.\n"HIC"就算进去了,冥王也不会见你的\n"NOR);
	message_vision(HIY"$N禁闭双眼，往墙里面冲了过去。\n"NOR, me);
       this_player()->move("/d/death/mishi");
	message_vision(HIM"$N冲过了气墙,心中有说不出的喜悦。\n"NOR, me);
       me->set_temp("mingwang_tianlin");
        return 1;
}}
