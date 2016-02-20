// LLY@FYSY
inherit ROOM;
void create()

{
        set("short", "湖畔小河边");

        set("long", @LONG浓雾、流水。河岸旁荻花瑟瑟。河水在黑暗中默默流动，河上的雾浓如烟。
LONG
        );

        set("exits", ([ 
  "north" : __DIR__"river1",]));

                       set("coor/x",-1065);

	               set("coor/y",65);

	               set("coor/z",10);


set("no_magic",1);	
setup();

}


