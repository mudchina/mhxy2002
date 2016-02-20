// Room: /4world/houshan1
inherit ROOM;

void create ()
{
  set ("short", "[0;32mºóÉ½Ğ¡Â·[m");
  set ("long", @LONG

ÕâÊÇÍ¨ÍùºóÉ½µÄÒ»ÌõĞ¡Â·¡£Ö»ÄÜĞ¡ĞÄÒíÒíµØÔÚÊ÷´ÔÖĞ×êĞĞ£¬
Ò»¸ö²»×¢Òâ¾Í»áÅöµÃÍ·ÆÆÑªÁ÷¡£¼¸Ö»ºï×ÓÎ§×ÅÄãÌøÀ´ÌøÈ¥£¬
Ò»±ßÖ¨Ö¨ÂÒ½Ğ£¬Ò»±ß³åÄãÈÓÒ°¹û¡£
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/monkey1" : 2,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"entrance",
  "northup" : __DIR__"houshan2",
]));

  setup();
}
