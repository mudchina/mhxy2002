inherit ROOM;
void create()
{
set("short","[32m×ßÀÈ[m");
set("long",@LONG

ğ®µÀÀï³±ÊªÒõ°µ£¬Á½±Ú¹Ò×ÅÊÖ±Û´ÖÏ¸µÄÅ£ÓÍÀ¯Öò£¬ÔÚÕóÕóÒõ·ç´µ¶¯ÏÂ
ºöÃ÷ºö°µ¡£×ßÀÈÀïËÄ´¦³äÂúÁËÉ§³ô£¬Äã²»½ûÎæ×¡ÁË±Ç×Ó£¬ÔÚ×ßÀÈµÄÅÔ
±ß£¬Äã»¹¿´µ½Ò»Ì²ÈËÑª£¬¿´À´ÊÇºüÀêÔÚ×÷¹Ö¡£

LONG);
set("exits", ([
         "east" : __DIR__"nei3",
       "west" : __DIR__"nei1",
       "north": __DIR__"yongdao",
       "south":__DIR__"dadian",
]));
set("objects", ([
  __DIR__"npc/guard" : 2,
]) );
setup();

}
