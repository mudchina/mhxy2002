// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// Room: some place in Î÷Å£ºØÖŞ
// forrest.c

inherit ROOM;

void create()
{
  set ("short", "[32mËÉÊ÷ÁÖ[m");
  set ("long", @LONG

ËÉÁÖÖ®ÖĞ·Ç³£µÄ°µ£¬¹âÏßÈ«±»ÈçÉ¡Èç¸ÇµÄÊ÷Ö¦µ²×¡¡£µØÏÂ²¼
Âú¿İÖ¦£¬Ã¿×ßÒ»²½¶¼»á·¢³öºÜ´äµÄÏìÉù£¬²»Ê±¿É¿´µ½¼¸¸ö¿³
²ñµÄµÀÊ¿¡£
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"lantao",
"southdown" : __DIR__"forrest",

]));
set("objects", ([ /* sizeof() == 2 */
"/d/lingtai/obj/shuzhi": 1,
"/d/lingtai/npc/kancai": 1
]));
   set("outdoors", 1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


