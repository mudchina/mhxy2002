inherit ROOM;
void create()
{
set("short","[31m¹ÅÄ¹½ûµØ[m");
set("long",@LONG

    ÕâÀïÊÇĞùÔ¯Ä¹µÄ½ûµØ£¬ÎŞÊıÖ»Ğ¡ºüÀêÒòÎªÒªÀë¿ªÕâ¸öµØ·½¶ø
ÔÚ´ËÊÜµ½³Í·££¬ÏãÏãÔÚÕâ¸öµØ·½Ò²Ã»ÓĞ¶àÉÙÊÂÇé×ö£¬Ö»ÊÇÏ²»¶¿´
×ÅĞ©½ø½ø³ö³öµÄÈËÃÇ¡£

LONG);
set("exits", ([
         "west" : __DIR__"nei2",
]));
set("objects", ([
    __DIR__"npc/xian": 1,
]) );
setup();

}

