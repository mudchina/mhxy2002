
inherit ROOM;

void create ()
{
  set ("short", "[36mð®µÀ[m");
  set ("long", @LONG
ÕâÀïÊÇ¹ÅÄ¹µÄÒ»Ìõ¾²¾²µÄÍ¨µÀ£¬ÄÏ±ßÍ¨ÏòÒ»¸öÉñÃØµÄËÀÍöÃÔ¹¬£¬
µ«¾ÝËµÓÐÒ»´ó±Ê¹ÅÄ¹±¦²Ø£¬ËùÒÔ³£ÓÐÈËÀ´´ËÌ½±¦¡ª¡ªÄÏ±ßÒõÉ­É­µÄºÃ
ÅÂÈË£¬Õâ¶ùµÄÊØÎÀµ¹Ò²¸ßÐËÓÐÈËÀ´¡ª¡ªËûÃÇ¾Í¿¿ÄÇÐ©ËÍËÀµÄÈË³ä¼¢¹ý
ÈÕ×Ó¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"maze1",
  "south" : __DIR__"nei2",
]));  
  set("objects", ([
  ]));
  setup();
}                                                                                                      
