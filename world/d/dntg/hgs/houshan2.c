// Room: /4world/houshan2
inherit ROOM;

void create ()
{
  set ("short", "[0;32mºóÉ½´ÔÁÖ[m");
  set ("long", @LONG

Äã¶¥×ÅÂúÍ·ÂúÁ³µÄÒ°¹ûÖ­´©ĞĞÔÚÊ÷´ÔÖĞ£¬°ÑÒ»Èººï×ÓÀÖµÃ
Ö¨Ö¨ÂÒ½Ğ¡£ËüÃÇÏÔÈ»²»Ì«Í¬ÇéÄãµÄ´¦¾³£¬»¹ÔÚ²»Í£µØÄÃ¸÷
ÖÖ¸÷ÑùµÄÒ°¹ûÔÒÄã¡£ÄÏÃæÊÇÒ»ÌõÏÂÉ½µÄĞ¡Â·£¬±±ÃæÍ¸¹ıÊ÷
´Ô¿ÉÒÔ¿´µ½Ò»Ğ¡¿éÆ½µØ¡£
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/monkey2" : 1,
  __DIR__"npc/monkey1" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"houshan3",
//  "west" : "/d/shuilian/tbridge",
  "southdown" : __DIR__"houshan1",
]));

  setup();
}
