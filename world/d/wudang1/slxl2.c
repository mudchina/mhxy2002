//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m
// ²¿·Ö´ÓÐÂ±àÐ´

#include <ansi.h>
inherit ROOM;

string look_shibei();

void create()
{
      set("short",YEL"ËÉÁÖÐ¡Â·"NOR);
      set("long",@LONG
ÕâÊÇÉ½½ÅËÉÁÖÖÐµÄÐ¡Â·£¬Á½±ß³¤Âú²ÎÌìµÄºìËÉÊ÷£¬Ö»ÄÜ¿´¼ûÒ»ÏßÌì¿Õ¡£
Â·ÅÔÓÐµÀÊ¿ÔÚ·ÜÁ¦¿³Ê÷¡£¶«±ß¿É»Ø´óµÀ¡£
    Â·±ßÓÐ¸öÊ¯±®[1;32m([4;53m[1;31mshibei[2;37;0m[1;32m)[2;37;0m£¬ºÜ¶àÓÎ¿ÍÔÚÎ§ÄÇÀï¡£Ô­À´Î÷±ßÉÏÈ¥¾ÍÊÇÃûÕò
ÌìÏÂµÄ½â½£ÑÒÁË£¬
LONG);
      set("outdoors", "wudang");
      set("item_desc", ([
          "shibei" : (: look_shibei :),
      ]));
      set("exits",([ /* sizeof() == 1 */
          "westup" : __DIR__"jiejianyan",
          "east"   : __DIR__"slxl1",
          "south"  : __DIR__"songlin1",
          "north"  : __DIR__"songlin2",
      ]));
      set("no_clean_up", 0);
      set_temp("wayao1",1);
      setup();
}

string look_shibei()
{
        return
        HIM"¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù\n"
        HIM"¡ù¡ù¡ù¡ù¡¡        ¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ù¡ù¡ù¡ù\n"
        HIM"¡ù¡ù¡ù¡ù¡¡        ¡¡"NOR+HIW"[4;53mÎäµ±ÅÉÍ¨¸æ"NOR+HIM"    ¡¡¡¡¡¡¡¡¡ù¡ù¡ù¡ù\n"
        HIM"¡ù¡ù¡ù¡ù¡¡                            ¡¡¡¡¡ù¡ù¡ù¡ù\n"
        HIM"¡ù¡ù¡ù¡ù¡¡    "NOR+HIY"ÍùÇ°¾ÍÊÇÎäµ±É½½â½£ÑÒ¡£ËùÓÐ"NOR+HIM"¡¡¡ù¡ù¡ù¡ù\n"
        HIM"¡ù¡ù¡ù¡ù¡¡"NOR+HIY"ÍâÀ´ÈË¿ÍÇë×Ô¾õ½â½£¡£Ð°Ä§ÍâµÀµ½"NOR+HIM"¡¡¡ù¡ù¡ù¡ù\n"
        HIM"¡ù¡ù¡ù¡ù¡¡"NOR+HIY"´ËÖ¹²½¡£"NOR+HIM"                ¡¡¡¡¡¡¡¡¡ù¡ù¡ù¡ù\n"
        HIM"¡ù¡ù¡ù¡ù¡¡¡¡¡¡¡¡¡¡                ¡¡¡¡¡¡¡¡¡ù¡ù¡ù¡ù\n"
        HIM"¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù\n"NOR;
}
