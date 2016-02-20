
inherit ROOM;

void create()
{
        set("short", "谷地");
        set("long", @LONG

只见四下流泉白石，奇松异草，将这四山环绕的谷地，点缀得有如神仙世
界一般。林木流水之间，点缀著许多栋飞檐凤阁，及一些假山亭台，一条
石板缀成的道路，宛延通向前方。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"hateroom",
  "east" : __DIR__"garden3",
   ]));
        set("outdoors", "mojiao");
	setup();
        replace_program(ROOM);
}

