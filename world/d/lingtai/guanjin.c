// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// Room: some place in Î÷Å£ºØÖŞ
// uphill4.c

inherit ROOM;

void create()
{
  set ("short", "[0;35m¹Û¾°Ì¨[m");
  set ("long", @LONG

ÕâÀïÄËÊÇÒ»´¦¸ßÑÂ£¬Ëä²»ÊÇÔÆĞüÇ§³ß£¬È´Ò²ÊÇ¶¸ÇÍÒì³£¡£ÖÜÎ§¶¤
ÁËĞ©Ä¾×®£¬°ó×ÅÉş×ÓÒÔ·ÀÊ§×ã¡£Ô¶´¦¿ÉÍûµ½¸ß¼ÒÕò£¬Ò»Æ¬Ò»Æ¬µÄ
ÇàÍß·¿×øÂäÔÚÂÌÓÍÓÍµÄÂóÌïÖ®ÖĞ£¬»¹¿ÉÒÔ¿´µÀÒ»Ğ©Å©·òÕıÔÚÌïÖĞ
¸É»î¡£
LONG);
set("exits", ([ /* sizeof() == 4 */
"west" : __DIR__"uphill4",
]));
set("objects", ([ /* sizeof() == 2 */
"/d/lingtai/npc/zhangdaoling" : 1]));

        set("no_clean_up", 0);
   set("outdoors", 1);
        setup();
}


