// Room: /d/death/walk.c
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", HIR"¹íÃÅ¹Ø"NOR);
  set ("long", @LONG

ÒşÔ¼±±·½ÏÖ³öÒ»×ùºÚÉ«³ÇÂ¥£¬³ÇÂ¥ÉÏÓĞÒ»·ù½ğØÒ£¬ÉÏÃæ¿Ì×Å¡°ÓÄÚ¤
½ç¡±Èı¸ö´ó×Ö¡£³ÇÂ¥ÏÂ³ÇÃÅ½ô±Õ£¬ºÚÆáÆáµØÊ²Ã´Ò²¿´²»Çå³ş¡£Â·±ß
Ò»¸öÆÆÄ¾ÅÆÖ±Ö±µØÖ¸Ïò±±·½£¬ÖÜÎ§Ö»ÓĞÉÙĞí°µºìÉ«µÄ»ğ¹âÈôÒşÈôÏÖ
µØÉÁË¸×Å¡£
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"new-out5",
  "west" : __DIR__"new-out7",
  "south": __DIR__"gate",
]));
  set("hell", 1);

  setup();
}

void init()
{
        object me=this_player();
		remove_call_out("greeting");
                call_out("greeting", 60, me);
	add_action("do_pass", "north");


}
void greeting(object ob)
{
        if( !ob || environment(ob) != this_object() ) return;
	ob->set_temp("time_enough", 1);
	return;
}
int do_pass()
{
	object me=this_player();
	
	if( me->is_ghost() && !me->query_temp("time_enough") )
		return notify_fail("³ÇÂ¥ÉÏÒşÔ¼´«À´º°Éù£ºÑôÆøÌ«Ê¢£¬²»µÃÈë³Ç£¡\n");

	if( me->is_ghost() ) {
		me->reincarnate();
		me->set("gin", (int)me->query("max_gin"));
		me->delete_temp("time_enough");
	}

	tell_object(me, "[1;36mÄãÖ±Ö±µØÏò±±¶Ô×Å³ÇÃÅ×ßÈ¥£¬¾ÓÈ»·¢ÏÖºÚÉ«µÄ³ÇÃÅÖ»ÊÇµÀÆøÁ±¡£¡£¡£[2;37;0m\n");
	tell_room(environment(me), me->name()+"Ö±Ö±µØÏò±±¶Ô×Å³ÇÃÅ×ßÈ¥£¬¾ÓÈ»´Ó½ô±ÕµÄÃÅÖĞ´©ÁË¹ıÈ¥£¡\n",
({me, me}));
	me->move("/d/death/new-zhaopo");
	tell_room(environment(me), me->name()+"×ßÁË¹ıÀ´¡£\n", ({me, me}));
	return 1;
}
