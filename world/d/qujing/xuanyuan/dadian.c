inherit ROOM;

#include <ansi.h>

void check_time(object where);
void feel_hungry(object where);
void feel_full(object where);
int do_xianmei();

void create()
{
set("short","[1;33m´óµî[m");
set("long",@LONG

    ËäÈ»ÕâÊÇÔÚµØÏÂ£¬¿ÉÊÇÄã²»ÄÜÏëÏóÔÚÕâÀï³äÂú×Å¹¬µîµÄ
ÆøÏ¢£¬¶øæ§¼ºÕý¶Ë×øÔÚÌ«Ê¦ÒÎÉÏ£¬µ±Äã½øÀ´µÄÊ±ºò£¬ËýÓÃÓà
¹âî©ÁËÄãÒ»ÑÛ£¬Äã²»½ûµÍÏÂÍ·£¬²»¸ÒÔÙ¶à¿´ËýÒ»ÑÛ£¬Ëý×ÔÉÌ
´úÃðÍöºó¾ÍÌÓµ½ÁËÕâ¸ö¶´Àï£¬¾Ó×¡ÖÁ½ñ¡£

LONG);
set("exits", ([
         "north" : __DIR__"nei2",
     //  "west" : __DIR__"road4",
     //  "north": __DIR__"chufang",
       "south":__DIR__"mishi",
]));
set("objects", ([
  __DIR__"npc/daji2" : 1,
]) );

  set("valid_startroom", 1);
setup();
"/obj/board/xy_b"->foo();

}

void init()
{
   object where=this_object();
  remove_call_out("check_time");
   check_time(where);
        add_action("do_xianmei","xianmei");
}
void check_time(object where)
{
   mixed *local = localtime(time()*60);
   int t = local[2] * 60 + local[1];
  int phase=((int)(t/120));
if((phase==3)&&(!query("hungry"))) feel_hungry(where);
if((phase==4)&&query("hungry")) feel_full(where);
   call_out("check_time",60,where);
}

void feel_hungry(object where)
{
message("channel:chat",HIW+"¡¾"HIM"ÐùÔ¯¹ÅÄ¹"HIW"¡¿"NOR+YEL"æ§¼º(Da ji)£º"HIY"æªÉíÐÄÇé²»ºÃ£¬²»ÖªÄÇÎ»°®Í½ÄÜºÍÎÒÁÄÁÄÌì°¡¡£(Xianmei)\n"+NOR,users());
   set("hungry",1);
}
void feel_full(object where)
{
tell_object(where,"æ§¼ºÐ¦µÀ£ºÏÖÔÚÐÄÇéºÃ¶àÁË¡£\n");
  set("hungry",0);
}
int do_xianmei()
{
   object me=this_player();
   if(me->is_busy())
      return notify_fail("ÄãÕýÃ¦×ÅÄØ¡£\n");
   if(!query("hungry"))
      return notify_fail("æ§¼ºÅ­µÀ£ºÎÒÐÄÇéºÃµÄºÜ£¡²»ÒªÈÇÎÒ¡£\n");
   if((string)me->query("family/family_name")!="ÐùÔ¯¹ÅÄ¹")
      return notify_fail("æ§¼ºËµµÀ£ºÎÒÐÄÇéºÃ²»ºÃ£¬¹ØÄãÊ²Ã´ÊÂ£¡\n");
 if(me->query("faith")>400)
      return notify_fail("ÕâÐ©ÊÂÇé¾ÍÈÃÆäËüÐ¡ºüÀêÀ´×ö°É¡£\n");
    tell_object(me,"Äã¶Ô×Åæ§¼º²»Í£µÄÏ×ÃÄ£¬Ö±°Ñæ§¼ºÀÖµÄÆ¨µßÆ¨µßµÄ¡£\n");
   me->start_busy(5);
      me->add("faith",1);
   me->add("combat_exp",9);
   me->add("potential",2);
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}
