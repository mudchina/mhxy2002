// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// Room: some place in Î÷Å£ºØÖŞ
// uphill3.c

inherit ROOM;

void create()
{
  set ("short", "[37m°×Ê¯Ïª[m");
  set ("long", @LONG

ÓÖÍùÉÏ×ßÁËÒ»¶Î£¬É½Â·ºÃÏó²»ÄÇÃ´¶¸ÇÍÁË¡£Â·ÅÔ»¹³öÏÖÁËÒ»Ìõ
Ğ¡Ïª¡£Ğ¡Ïª²»Éî£¬ÏªË®Çå³¹¼ûµ×¡£ÏªÖĞµÄĞ¡ÓãÓÎÀ´ÓÎÈ¥£¬°¶±ß
µÄÔÓ²İÖĞ´«À´ÇàÍÜßÉßÉµÄ½ĞÉù¡£Å¼¶û¼¸Ö»Ğ¡Äñ·É¹ı£¬ÄñÌäÅä×Å
ÇåÈª¶£µ±ÍğÈçÏÉÀÖ¡£
LONG);
set("exits", ([ /* sizeof() == 4 */
"northeast" : __DIR__"uphill4",
"southdown": __DIR__"uphill2",
"northwest": __DIR__"baixi",
]));

        set("no_clean_up", 0);
      set("resource", ([
         "water" : 1,
       ]) );
   set("outdoors", 1);
        setup();
}

int valid_leave (object me, string dir)
{
        if (dir == "northwest"){
                message_vision ("$NÍìÆğ¿ãÍÈ£¬Ìøµ½ÁËĞ¡ÏªÖĞ¡£\n",me);
        }
  return 1;
}

