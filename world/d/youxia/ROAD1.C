inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "Ã·ÁÖÖ®ÖÐ");
        set("long", @LONG
½ÅÏÂ¿ÝÖ¦¶ÏËé£¬·¢³öÖ¨Ö¨Éù¡£Ã·»¨Ëæ·çÆ®Îè£¬ÅÌÐýÂäÏÂ¡£
Å¼¶ûÒ»Á½ÉùÜà½Ð£¬»®ÆÆÄþ¾²¡£ÃÜÁÖÉî´¦£¬ËÆÓÐÖØÖØÈËÓ°»Î¶¯¡£
Ô¶·½Ò»á¦°×ÆìËæ·ç·­·É°Ú¶¯¡£
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"road",
  "north" : __DIR__"cleft",
]));
set("objects", ([
__DIR__"npc/liuxiang" :1,
]));
        set("outdoors", "wanmei");
        set("coor/x",120);
        set("coor/y",-400);
        set("coor/z",30);
        setup();
}
void init()
{
        if(interactive(this_player()))
        {
                remove_call_out("dropleaf");
                call_out("dropleaf",random(10)+10,this_player());
        }
}

int dropleaf(object me)
{
        object leaf;
        if(me)
        if(environment(me) == this_object())
        {
                tell_object(me,"[31mÒ»¶äÃ·»¨Ëæ·çÆ®ÏÂ£®£®£®£®[0m\n");
                leaf = new(__DIR__"obj/leaf");
                leaf->move(this_object());      
        }
}

