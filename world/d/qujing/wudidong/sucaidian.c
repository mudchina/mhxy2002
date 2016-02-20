// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create ()
{
  set ("short", "[31m¹Ï[32m¹û[33mÊß[35m²Ë[36mµê[m");
  set ("long", @LONG

Õâ¼ÒÊß²ËµêÎ»ÓÚĞ¡´åµÄÂ·¿ÚÖ®ÉÏ,ËäÈ»µêÃæ²»´ó,¿ÉÂòµÄÊß²Ë¹Ï¹û
µÄÆ·ÖÖµ¹ÊÇ²»ÉÙ,¼ÓÉÏÂò²Ë´óÉ©Ì¬¶ÈºÍ°ª,ÉúÒâµ¹Ò²ºì»ğ.

LONG);
  set("exits", ([ /* sizeof() == 2 */
        "north" : __DIR__"entrance",
]));
  set("objects",([
        __DIR__"npc/maicaide":1,
        ]));
  set("outdoors", "1");

  setup();
}
