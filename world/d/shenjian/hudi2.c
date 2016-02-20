// LLY@FYSY
inherit ROOM;

void create()
{
        set("short", "绿水湖湖底");

        set("long", @LONG
绿水湖的湖水清澈冰凉，从这里可以看到湖畔的岸边景色，绿水湖中独有的鱼儿在你的面前游来游去。
LONG
        );
              set("exits", ([ 
  "north" : __DIR__"hudi","up" : __DIR__"sjhupan",
]));
       	set("objects",([
			__DIR__"obj/fish" : 2,
       	]) );
        set("coor/x",-1055);

	set("coor/y",15);

	set("coor/z",-10);
        set("no_magic",1);

	setup();

}


