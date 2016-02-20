inherit ROOM;
void create()
{
set("short","[35mÃÜÊÒ[m");
set("long",@LONG

   ÕâÀï¾ÓÈ»¹ØÑº×ÅÉÌ´úµÄ±©¾ıæûÍõ£¬ÌıËµæûÍõÁÙÊ±Ê±²ÅÖªµÀ
×Ô¼º±»ºüÀê¾«ËùÃÔ»ó£¬¶øÄÇÊ±ËûµÄ½­É½ÒÑ¾­Ò×Ö÷ÁË£¬ËûÔõÃ´
µ½ÏÖÔÚ»¹»î×Å£¿Ò²ĞíÊÇºüÀê¾«¸øËûÊ©ÁËÑı·¨¡£

LONG);
set("exits", ([
       "north": __DIR__"mishi",
]));
set("objects", ([
  __DIR__"npc/zhouwang" : 1,
  __DIR__"npc/taijian" :2,
  __DIR__"obj/fengdao" :2,
]) );
setup();

}

