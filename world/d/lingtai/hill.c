// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// Room: some place in Î÷Å£ºØÖŞ
// hill.c

inherit ROOM;

void create()
{
  set ("short", "[32m·½´çÉ½ÏÂ[m");
  set ("long", @LONG

Ì§Í·ÍûÈ¥£¬µ½ÁËÒ»×ùÉ½ÏÂ¡£É½Ëä²»¸ß£¬ÍûÈ¥È´ÆøÏóÍòÇ§£¬æ¹ÄÈ¶à
×Ë¡£Ò»¶ä°×ÔÆĞ±Ğ±µÄ¿¿ÔÚÉ½Ñü£¬ÎªÉ½Æ½Ôö¼¸·ÖÁéÆø¡£ÒşÒşÔ¼Ô¼ÄÜ
Ìıµ½É½ÖĞéÔ·ò³ªµÄÉ½¸è£¬¼¸Ö»Ğ¡ÄñÒ²ËæÖ®Ò»³ªÒ»ºÍ¡£
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup" : __DIR__"uphill1",
"southeast" : "/d/gao/road4",
]));

        set("no_clean_up", 0);
   set("outdoors", 1);
        setup();
        replace_program(ROOM);
}

