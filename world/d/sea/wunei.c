inherit ROOM;

void create ()
{
  set ("short", "石屋内");
  set ("long", @LONG

石屋内黑咚咚的，还散发着一股说不上来的怪味，让人闻之欲呕。
周围依稀看到几根铁柱(pole)，还残留着几丝血迹。
LONG);
set("item_desc", ([ /* sizeof() == 1 */
  "pole" : "丝丝血迹，仿佛蕴涵着无数幽灵，高耸的顶端却有丝丝辉光渗下。\n",
]));

          set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/beast" : 1,
]));

  set("exits", ([ /* sizeof() == 4 */
//  "east" : __DIR__"yujie2.c",
]));
}
void init()
{
  add_action("do_climb", "climb");
 }


int do_climb(string arg)
{
 object me=this_player();
 
  if( (!arg) || !((arg == "pole") || (arg == "铁柱")))
    return notify_fail("爬什么？\n");
  if (me->is_busy()) return notify_fail("你现在正忙着呢。");
  if( me->query("kee") < (int)(me->query("max_kee")/2)){
    me->receive_damage("kee",(int)me->query("max_kee")*10/100);
    return notify_fail("你身子发虚，一头栽了下来，哎呀！\n");
}

	  if ((int)me->query_skill("dodge", 1)<120 )
	  {
	  message_vision("$N看了看高耸的铁柱，没敢露丑．\n", me);
   }
      else
        {
	  message_vision("$N扫了一眼铁柱，蹭的一声窜了上去，只留下”哗啦“抖动的铁索。\n", me);
          me->move(__DIR__"enter.c");
        }
    me->receive_damage("kee", (int)me->query("max_kee")*10/100);
  return 1;
}
