// create by snowcat.c 4/8/1997
// room: /d/westway/jiuquan.c

inherit ROOM;
#include <ansi.h>


void create ()
{
  set ("short","¾ÆÈª½¼Íâ");
  set ("long", @LONG

¾ÆÈª½¼ÍâÊÇ³¤Í¾³µÂí¶ÓĞª½ÅµÄÁíÒ»¸öÖØÒªµØµã¡£ÕâÀï±È½ÏÈÈÄÖ£¬
ÓÈÆäÒÔ²ú¾Æ¶øÎÅÃû£¬[1;35m¡°ÆÏÌÑÃÀ¾ÆÒ¹¹â±­¡±[2;37;0mÓÉ´Ë¶øÀ´¡£¶«ÃæÊÇÒ»
ÌõÂíµÀ£¬Î÷ÃæÊÇÒ»ÌõÊ¯Õ»µÀ£¬±±²¿ÊÇ×ùÉñÃØµÄĞ¡É½Çğ¡£

LONG);

  set("exits", ([
        "east"      : __DIR__"madao",
        "west"      : __DIR__"shizhan",
        "northup"   : __DIR__"yunti",
      ]));
  set("outdoors", __DIR__);

  setup();
}



