inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "龙之翼");
        set("long", @LONG

这是一块巨大的黑色山石，从悬崖中间申了出来，令人惊奇的是石面上的
几块掌印(strike)，每个掌印都有六七分深浅。向下望，可以看到翻腾的
岩浆；向上望，只见上面云雾缭绕，不知还有多高才会到顶。
LONG
        );
	set("outdoors","mojiao");
	setup();
}
void init()
{
	add_action("do_climb", "climb");
	add_action("do_step", "step");
}
int do_step(string arg)
{
	if(!arg || arg != "strike" )
		return notify_fail("你要拍什么？\n");
	message_vision(HIY "$N一掌拍在掌印上，只听到＂轰的＂一声，\n崖壁上裂开了一道门户！\n" NOR, this_player());
	set("exits/enter", __DIR__"hateroom");
        if(!this_player()->query("app/hate"))
        {
                this_player()->set("app/hate",1);
        }
	return 1;
}
int do_climb(string arg)
{
        object 	me;
	int	mlvl;

	if(!arg || (arg != "up" && arg != "down")) {
		write("你要往上或下爬？\n");
		return 1;
	}
	me = this_player();
	if( arg == "up") {
		message_vision(HIY "\n$N小心翼翼地向上爬去，身形慢慢被云雾遮掩。\n" NOR, me);
		message_vision(HIR "\n$N手上一个没抓稳，从危崖上掉了下去！\n" NOR, me);
		me->move(__DIR__"yadi");
                me->receive_wound("kee", 50);
                me->receive_wound("sen", 50);
		message_vision(HIR "\n$N从危崖上掉了下来，重重的摔在了睚底！\n" NOR, me);
		me->unconcious();
	}
	else {
		message_vision(HIY "$N小心翼翼地向下爬去，身形慢慢被云雾遮掩。" NOR, me);
		me->move(__DIR__"yadi");
	}
	return 1;
}
