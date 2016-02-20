inherit ROOM;
void create()
{
set("short","[35mÍ¨µÀ[m");
set("long",@LONG

  ÕâÊ±Äã¸Ğ¾õÑÛÇ°µÄÊÀ½ç±ä´óÁËºÃ¶à£¬¼¸Ö»Ğ¡ºüÀêÔÚÄãµÄ½Å
ÏÂ´©À´´©È¥£¬ÄãµÄĞÄÆ½Ï¢ÁË£¬ÕâÀïºÃÏóºÜ°²Ïê£¬Ö»ÊÇÄãÎÅµ½
Ò»¹ÉºÜÄÑÎÅµÄÎ¶µÀ£¬²»¹ıµØ·½È´´òÉ¨µÄºÜ¸É¾»¡£

LONG);
set("exits", ([
         "west" : __DIR__"sleeproom",
       "south" : __DIR__"road2",
       "north" : __DIR__"road4",
]));
set("objects", ([
  __DIR__"npc/fox" : 3,
]) );
setup();

}

