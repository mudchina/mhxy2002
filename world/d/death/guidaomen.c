inherit ROOM;

void create()
{
  set ("short", "³¬Éú¹óµÀÃÅ");
  set ("long", @LONG

ÕâÀï±ßÊÇÒõ¼äÍ¨ÍùÑô¼äµÄÎ¨Ò»³ö¿Ú£­¹óµÀÃÅ¡£ÈôÊÇÓÐÔ©ËÀ¹íÍ¶
Ì¥£¬¾ÍÓÉ´Ë³öÒõ¼ä¡£ÄÏ·½ÓÐÒ»×ù´óÅÆ·»ËÊÁ¢£¬ÅÆ·»µÄÁíÒ»ÃæÊ²
Ã´Ò²¿´²»µ½¡£´ó¸ÅÒª³öÈ¥[1;33m(out)[2;37;0m²ÅÄÜ¿´µ½¡£
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "out" : "ÅÆ·»µÄÁíÒ»ÃæÊ²Ã´Ò²¿´²»µ½¡£\n",
]));

set("exits", ([ /* sizeof() == 4 */
"northwest" : __DIR__"pingyang",
]));
	set("hell", 1);
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_out", "out");
}

int do_out()
{//	string owner;
        object me, zhenshen;
	me=this_player();
	message_vision("$NÂõÍÈÏòÅ¨ÎíÖÐ×ßÁË½øÈ¥¡£\n", me);
	if( me->query_temp("in_hell")) {
		if( zhenshen=me->query_temp("zhenshen")) {
			me->move(environment(zhenshen));
			destruct(zhenshen);
			me->delete_temp("in_hell");
			message_vision("$NÈàÈàÑÛ¾¦£¬ËÆºõÇåÐÑÁË¹ýÀ´¡£\n", me);
			return 1;
		}
	}
        me->move("/d/death/out");
	message_vision("$NÍ´¿àµÄºßÁËÒ»Éù¡£\n", me);
    if(me->is_ghost()) me->reincarnate();
        me->delete_temp("in_hell");
        return 1;
}

