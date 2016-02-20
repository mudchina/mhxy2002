inherit ROOM;
void create()
{
set("short","[35mÄÚÊÒ[m");
set("long",@LONG

  »è°µµÄµÆ¹â£¬ÄÑÎÅµÄÆøÎ¶£¬Èç¹ûÈË×¡ÔÚÕâÖÖµØ·½£¬²»
»î»î±ïËÀ²Å¹ÖÄØ£¡Èç¹û²»ÊÇÈËÀàÄÇ¾ÍÁîµ±±ğÂÛÁË£¬×îÈÃ
ÈËÊÜ²»ÁËµÄ¾ÍÊÇ£ºÕâÀïÀÏÊÇÄÜ¿´µ½Ò»Ğ©¸ÕËÀÈ¥µÄ¶«Î÷£¬
ËûÃÇºÃÏó»¹ÔÚÕõÔú×Å£¬ÈÃÄã¾õµÃ²Ò²»ÈÌ¶Ã¡£

LONG);
set("exits", ([
         "east" : __DIR__"nei2",
       "west" : __DIR__"road4",
       "north": __DIR__"chufang",
       "south":__DIR__"lian",
]));
set("objects", ([
  __DIR__"npc/meifu" : 1,
]) );
setup();

}

