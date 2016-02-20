inherit ROOM;
void create()
{
set("short","[32m¶´ÖĞ[m");
set("long",@LONG

    ÕâÀïºÃÏóÊÇ¶´µÄÖĞĞÄÁË£¬Äã³ıÁËÄÜÎÅµ½É§³ôÎ¶£¬¿´µ½»è°µ
¾°É«Íâ£¬ÆäËüºÃÏóÊ²Ã´Ò²Ã»ÓĞ£¬Å¼¶ûÓĞ¼¸Ö»ºüÀêÅÜÁË¹ıÀ´£¬Â·
ÔÚÕâ¿ªÊ¼·Ö²æÁË£¬ÄãÓĞµãÃÔ»óÁË¡£

LONG);
set("exits", ([
         "east" : __DIR__"nei1",
       "south" : __DIR__"road3",
       "west" : __DIR__"dan",
       "north" : __DIR__"road5",
]));
set("objects", ([
  __DIR__"npc/fox" : 1,
]) );
setup();

}

