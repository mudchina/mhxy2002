// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// Room: some place in Î÷Å£ºØÖŞ
// forrest.c

inherit ROOM;

void create()
{
  set ("short", "[0;32mËÉÊ÷ÁÖ[m");
  set ("long", @LONG

ËÉÁÖÖ®ÖĞ·Ç³£µÄ°µ£¬¹âÏßÈ«±»ÈçÉ¡Èç¸ÇµÄÊ÷Ö¦µ²×¡£®ÖÜÎ§¿´
²»µ½Ò»¸öÈËÓ°£¬ÄãÖ»ÄÜÊÖÃş×ÅÊ÷¸ÉÒ»²½²½×ß£®³ıÁË½ÅÏÂµÄ¿İ
Ö¦·¢³ö±»²È¶ÏÊ±µÄ²Ò½Ğ£¬Ö»ÓĞÒ»Ğ©ÎŞÁÄµÄĞ¡³æÎŞÁÄµÄ½Ğ×Å£®
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup" : __DIR__"lantao1",
"south" : __DIR__"forrest2",
"east" : __DIR__"uphill2",
"west" : __DIR__"cave1",

]));
set("objects", ([ /* sizeof() == 2 */
"/d/lingtai/obj/shuzhi": 2]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


