// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
// Room: some place in 西牛贺洲
// inside2.c

#include <ansi.h>
inherit ROOM;

void create ()
{
 set ("short", "厨房");
  set ("long", @LONG

虽说道士们清茶淡饭吃的并不好，但他们却经常周济附近一些贫
苦的村民．边上的架子上堆着蔬菜，一口大水缸立在墙角．一个
胖胖的道士正在烧火，炉上热气腾腾，不知煮的什么．你可以要
些(yao)吃的。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"houyuan",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "bowl" : "锅里是热气腾腾的包子，你要饿了也可以拿些去吃．
",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/wanfeng" : 1,
  "/d/ourhome/obj/hulu" :1,
   __DIR__"obj/shuitong" : 1,
]));
  set("clean_up", 1);

  setup();
}
void init()
{
        add_action("do_none","get");
        add_action("do_none","put");
}
int do_none()
{
        object zm=present("zhang men");
        if(zm)
        {
        message_vision("$N对$n摇了摇头。\n",zm,this_player());
        return 1;
        }
        return 1;
}
int valid_leave()
{
        if((present("bao", this_player())))
            return notify_fail("吃完包子再走吗！\n");
   if((present("hulu", this_player())))
       return notify_fail("你不能把葫芦带走！\n");
    if((present("shuitong",this_player()))&&this_player()->query("lingtai_quest/quest_type")!="挑水")
       return notify_fail(HIY"没你事,你现在不能拿走水桶!\n"NOR);
    return ::valid_leave();
}

