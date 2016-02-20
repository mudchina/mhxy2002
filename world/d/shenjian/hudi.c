inherit ROOM;
void create()
{
        set("short", "绿水湖湖底");
        set("long", @LONG
绿水湖的湖水清澈冰凉，各式各样的鱼儿在你的面前游来游去。
LONG);
set("exits", ([ 
  "west" : __DIR__"hudi1", 
  "south" : __DIR__"hudi2",
]));

set("objects",([
__DIR__"obj/fish" : 1,
]) );
setup();
}
