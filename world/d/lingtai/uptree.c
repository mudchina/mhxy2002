// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// Room: some place in Î÷Å£ºØÖŞ
// uptree.c

inherit ROOM;

void create()
{
  set ("short", "[0;35m´óËÉÊ÷¶¥[m");
  set ("long", @LONG

Õ¾ÔÚ´óËÉÊ÷µÄ¶¥¶Ë£¬É½·çÕóÕó£¬¿ÕÆøÇåĞÂ£®ÏòÉ½¶¥ÑöÍû£¬Òş
Ô¼¿´µ½Ò»Æ¬·¿ÎİÔÚÒ»¹Éµ­µ­µÄ×ÏÆøÁıÕÖÖ®ÏÂ£®
LONG);
set("exits", ([ /* sizeof() == 4 */
"down": __DIR__"uphill2"
]));
set("objects", ([
     __DIR__"obj/guo": 1]));
        set("no_clean_up", 0);
   set("outdoors", 1);
        setup();
        replace_program(ROOM);
}


