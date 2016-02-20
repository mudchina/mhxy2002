// LLY@FYSY
inherit ROOM;
void create()

{
        set("short", "湖畔小河边");

        set("long", @LONG
浓雾迷没的河面上，忽然传来一点闪动明灭的微弱火花。不是灯光，是
炉火。一叶孤舟，一只小小的红泥炉火，闪动的火光，照著盘膝坐在船头上
的一个老人。
LONG
        );

        set("exits", ([ 
  "enter" : __DIR__"boat",]));

                       set("coor/x",-1065);

	               set("coor/y",75);

	               set("coor/z",10);


	setup();

}


