// LLY@FYSY
inherit ROOM;
void create()

{
        set("short", "绿水湖湖底");

        set("long", @LONG
绿水湖的湖水清澈冰凉，绿水湖中独有的鱼儿在你的面前游来游去。
LONG
        );
               set("exits", ([ 
  "north" : __DIR__"hudi3", "east" : __DIR__"hudi",

]));

	set("objects",([
			__DIR__"obj/fish" : 1,
       	]) );
  
                       set("coor/x",-1065);

	               set("coor/y",25);

	               set("coor/z",-10);

set("no_magic",1);	
setup();

}


