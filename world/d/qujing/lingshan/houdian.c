// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "后殿");
  set ("long", @LONG

后殿里仙气冉冉，东西面是金凤银鹤花屏，南边是一排香木玉
窗(windows)，窗外有一天院，临窗可见院中翠竹竿竿倒，金
莲朵朵摇,北面是一彩绒殿门。
LONG);
set("item_desc", ([ /* sizeof() == 1 */
  "windows" : "窗外金光耀眼，一时让人睁不开眼睛，却间窗外一老者矗立其间。\n",
]));

  set("exits", ([
        "north"   : __DIR__"daxiong",
      ]));
  set("objects", ([
        __DIR__"npc/xiantong" : 2,
     ]));

  setup();
}
void init()
{
 add_action("do_out", "out");
 }


int do_out(string arg)
{
 object me=this_player();
 
  if( (!arg) || !((arg == "windows") || (arg == "窗户")))
    return notify_fail("你想去那里？\n");
  if (me->is_busy()) return notify_fail("你现在正忙着呢。");
  if( me->query("kee") < (int)(me->query("max_kee")*2/3)){
    me->receive_damage("kee",(int)me->query("max_kee")*10/100);
me->move("/d/qujing/lingshan/siqian");
me->unconcious();
return 1;
}
	  if ((int)me->query_skill("force", 1)<180 )
	  {
	  message_vision("$N看了看四周的小童，心虚的低下了头．\n", me);
   }
      else
        {
	  message_vision("$N看了看四周的小童，趁他们不注意，一溜烟窜了出去!。\n", me);
	  tell_object(me,"刚落下，却发现几个神将已出现在眼前!\n");
	  
   me->move(__DIR__"windows.c");
        }
    me->receive_damage("kee", (int)me->query("max_kee")*10/100);
  return 1;
}



