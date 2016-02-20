// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 4/20/1997
// room: /d/eastway/bingma.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "[0;31m±øÂíÙ¸Õó[m");
  set ("long", @LONG

ÄãÀ´µ½Ò»¸ö¾Ş´óµÄ±øÂíÙ¸ÕóÖĞ£¬Ìì¸ßÔÆÀ«£¬³ÉÇ§ÉÏÍò¸öèò
èòÈçÉúµÄ±øÂíÙ¸£¨£ç£õ£í£õ£©ÅÅÁĞ³É¼¸Ê®Â·×İ¶Ó£¬·Â·ğÕıÔÚ´ÓËÄÃæ°Ë·½
ºôĞ¥¶øÀ´£¬Äã²»½û±»Õâ¸öºêÎ°µÄ³¡Ãæ¾ªµ¹¡£

LONG);

  set("exits", ([
        "west"       : __DIR__"shihuang",
      ]));
  set("objects", ([ /* sizeof() == 1 */
        __DIR__"obj/bingma" : 9,
      ]));
  set("outdoors", __DIR__);

  setup();
}




void init()
{
add_action("do_dig","dig");

}
int do_dig(string arg)
{
     object me=this_player();

     if( (!arg) || !((arg == "gumu") || (arg == "¹ÅÄ¹")))
     return notify_fail("ÄãÒªÍÚÊ²Ã´£¿\n");

     me->move("/d/qujing/xuanyuan/entrance.c");
     message_vision(YEL"$NÉí×ÓÍùÏÂÏİÈ¥£¬µÈ»º¹ıÉñÀ´Äã·¢ÏÖÄãµ½ÁËÁíÒ»´¦ËùÔÚ¡£\n"NOR, me);
     return 1;
}


