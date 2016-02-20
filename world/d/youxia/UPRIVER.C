// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "小河流上游");
        set("long", @LONG
这里的河床较宽，水流缓慢。河边的芦苇随风起伏荡漾，发出
沙沙的声音，偶尔还夹杂着野鸭的嘎嘎声。河边有几条依稀的小径
蜿蜒地伸向远方，几块嶙峋的怪石耸立在小径旁。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jungle",
  "south" : __DIR__"playground",
]));
	set("outdoors","wanmei");
        set("coor/x",200);
	set("coor/y",-300);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
