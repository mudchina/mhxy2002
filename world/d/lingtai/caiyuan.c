// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: some place in 西牛贺洲
// houyuan.c

inherit ROOM;

void create()
{
  set("short", "菜园");
  set ("long", @LONG

方寸山生活清苦。为了改善生活，云阳真人下令在后园开辟了一大片
菜地，种植各种各样的蔬菜和水果。
LONG);
set("exits", ([ /* sizeof() == 4 */
"southwest": __DIR__"houyuan",
]));
        set("no_clean_up", 0);
   set("outdoors", 1);
        setup();
}

