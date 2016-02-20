// 心叶树下 by Calvin

inherit ROOM;
int number=1+random(4);
void create ()
{
  set ("short", "心叶树下");
  set ("long", @LONG
     心叶无心心也灵，人情有情情不情。
LONG);

  set("exits", ([ /* sizeof() == 1 */
   "west" : "/d/milin/qy/sc7",
]));

        set("objects", 
        ([ //sizeof() == 1
          "/d/longzhu/npc/xiaolin" : 1,
        ]));

  setup();
}
void init() {
  add_action("do_dig",({"dig","wa","jue"}));
}

int do_dig(string arg) {

  object wan,me=this_player();

  if (!arg && arg!="tree" && arg!="lihua tree")
    return notify_fail("你要挖什么？\n");

  if (me->is_busy()) return notify_fail("休息一会儿再挖吧。\n");

  me->add("kee",-200);
  message_vision("$N在心叶树下挖了半天，累得满头大汗。\n",me);
  if (!random(5))
      if (!number)
         message_vision("$N挖出一个龙珠探测器,可是却坏的不成样子了。\n",me);
      else {
         message_vision("$N挖出一个光亮无比的宝物,看得出那便是龙珠。\n",me);
         wan=new("/d/longzhu/obj/2");
         if (!wan->move(me)) wan->move(this_object());
         number--;
      }
  me->start_busy(5+random(5));
  return 1;
}         
