//shushan by yushu 2000.11
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short",HIR "「" HIY "卧室" HIR "」" NOR);
  set ("long", @LONG

南边的窗上挂着一只鸟笼，里面的鸟儿正唱着歌。背面墙上上挂着
一幅细竹山水画，房中有一竹桌竹椅。这里有一张床(bed).
LONG);

  set("no_fight", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "bed" : "睡觉用的床铺(gosleep,gobed,bed)。 
",
       ]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"hsg",
]));
 set("no_magic", 1);

  setup();
}

void init()
{
        add_action("do_bed", "gosleep");
        add_action("do_bed", "gobed", );
        add_action("do_bed", "bed");
        add_action("do_push", "push");
}

int do_bed()
{       object me;
        me=this_player();
        message_vision(HIY "$N掀开纱帐，准备上床了。\n\n" NOR, me);
        me->move(__DIR__"chuang");
            message_vision(HIY "\n纱帐轻轻一动，$N钻了进来。\n" NOR, me);
                return 1;
}

int do_push(string arg)
{
  object me=this_player();
  int myeffstr=me->query("str")+me->query_skill("unarmed", 1)/10-2;
  int mykar=me->query_kar(), diff=40-mykar, percentage;
  int mymaxkee=me->query("max_kee"), mymaxsen=me->query("max_sen");
  if ((arg != "zhuyi" && arg != "竹椅") || !arg)
    return notify_fail("你要推什么？\n");
  if (me->is_busy()) return notify_fail("你忙着呢！\n");
  if (me->query_temp("no_move")) return notify_fail("你被定住了，什么也干不了。\n");
  if (me->query_skill("xianfeng-spells", 1) > 160
   && me->query("family/family_name") == "蜀山派")
  {
      message_vision("$N运起仙风云体术！一阵清风过后人不见了！\n", me);
      me->move(__DIR__"midao");
      return 1;
  }
  if (me->query_str()<30||myeffstr<20)
    {
      message_vision("$N使劲推竹椅，但竹椅纹丝不动。\n", me);
      return 1;
    }
  message_vision("$N用力推动竹椅，突然一阵狂风吹过,人不见了\n", me);
  me->move(__DIR__"midao");
  return 1;
}


