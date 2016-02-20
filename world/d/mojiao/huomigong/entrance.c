
// create by qlwy 28/06/2001
// room: maojiao/entrance.c

inherit ROOM;

void create ()
{
        set ("short", "ÃÔ¹¬¶´¿Ú");
        set ("long", @LONG

Ïò±±¾ÍÊÇ´«ËµÖĞµÄ»ğÃÔ¹¬ÁË£¬ÄãÕ¾ÔÚ¶´¿Ú¶¼¾õµÄÈÈ
ÆøÏ®ÈË¡££

LONG);
        set("exits", 
        ([ //sizeof() == 2
//                "south" : __DIR__"xxx", ÓÃÓÚÁ¬½Ó
                  "north" : __DIR__"hmg0",
        ]));
        setup();
}


