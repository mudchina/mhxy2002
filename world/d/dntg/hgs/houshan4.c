// Room: /4world/houshan4
//by tianlin 2001.5.1
inherit ROOM;

void create ()
{
  set ("short", "[33mÌÒÊ÷ÁÖ[m");
  set ("long", @LONG

ÌÒÊ÷ÁÖÖĞ¡£»Æ³Î³ÎµÄâ¨ºïÌÒÏÔÈ»ÒÑ¾­ÊìÍ¸£¬ÒÑ¾­ÓĞÒ»Ğ©´ÓÊ÷ÉÏ
µôÁËÏÂÀ´¡£Ò»Õó¹ûÏãÆ®À´£¬Äã¿ÚË®¶¼Á÷ÁË³öÀ´¡£
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/d/obj/drug/mihoutao" : 2,
  "/d/4world/npc/liuer-mihou" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"houshan3",
]));

  setup();
}
