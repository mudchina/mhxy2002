// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// Room: some place in Î÷Å£ºØÖŞ
// uphill4.c

inherit ROOM;

void create()
{
  set ("short", "[32m±ÌÂÜÁë[m");
  set ("long", @LONG

ÕâÀïµÄµØÊÆ±äµÄÆ½Ì¹£¬Ò»Æ¬±ÌÂÌµÄ²İÆºÖĞ¿ª×Å¶ä¶äĞ¡»¨¡£ÍùÉ½ÏÂ
ÍûÈ¥£¬Äã³ÔÁËÒ»¾ª£¬²»Öª²»¾õÖĞÒÑÉÏÁËÕâÃ´¸ßÁË¡£Ò£ÍûÔ¶´¦£¬Ç§
·å¿ªêª£¬ÍòØğ¿ªÆÁ¡£ÈÕÓ³á°¹âÇáËø´ä£¬ÓêÊÕ÷ìÉ«Àäº¬Çà¡£
LONG);
set("exits", ([ /* sizeof() == 4 */
"east": __DIR__"guanjin",
"northeast" : __DIR__"uphill5",
"southwest": __DIR__"uphill3",
]));
set("objects", ([ /* sizeof() == 2 */
"/d/lingtai/npc/qiaofu.c" : 1]));

        set("no_clean_up", 0);
   set("outdoors", 1);
        setup();
        replace_program(ROOM);
}


