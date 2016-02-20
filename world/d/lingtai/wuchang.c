// Room: /d/lingtai/wuchang.c

inherit ROOM;

void create()
{
        set("short", "[0;33mÁ·Îä³¡[m");
        set("long", @LONG
ÕâÀïÊÇ·½´çÉ½ÈıĞÇ¶´µÄÁ·Îä³¡¡£ÓÉÎŞÊı¿é¾Ş´óµÄ»¨¸ÚÑÒÊ¯°åÆÌ¾Í¡£
ÉÏÇ§ÄêµÄ²ÈÌ¤ÒÑÊ¹µÃÕâĞ©Ê¯°åÈçÍ¬¾µ×Ó°ãÆ½Õû¹â»¬¡£Î÷±ß½ÇÉÏ»¹
ÓĞÁ½¸ö´óÉ³¿Ó£¬Ê®À´¸öµÀÊ¿ÕıÔÚÁ·Ï°ÎäÒÕ¡£¶«Î÷Á½Ãæ¸÷ÊÇÒ»¼ä¾²
ÊÒ¡£
LONG );
        set("exits", ([
                "down" : __DIR__"jingtang",
                "east" : __DIR__"xiuwu",
                "west" : __DIR__"yangxin",
        ]));
        set("outdoors", 1);
        setup();
}

