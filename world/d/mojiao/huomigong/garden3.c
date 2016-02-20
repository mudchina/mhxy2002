
inherit ROOM;

void create()
{
        set("short", "大殿");
        set("long", @LONG

这是一间金碧辉煌的大殿，两行蟠龙巨柱，有如巨人般排列在大殿中
央。殿中堂上有一个拱桌，上面供俸着一把长剑。一个英俊的年青人
正在那里谈笑风生。
LONG
        );
        set("exits", ([ 
       "west" : __DIR__"valley",
                      ]));
        set("objects", ([
       "/d/mojiao/npc/master2": 1,
                        ]) );
        set("valid_startroom", 1);
 	  setup();
        replace_program(ROOM);
}

