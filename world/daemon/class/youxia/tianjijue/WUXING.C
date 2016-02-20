// 妖法－－幻影

#include <ansi.h>
#include <command.h>

inherit SSERVER;

mapping default_dirs = ([
        "north":        "北",
        "south":        "南",
        "east":         "东",
        "west":         "西",
        "northup":      "北边",
        "southup":      "南边",
        "eastup":       "东边",
        "westup":       "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":     "东边",
        "westdown":     "西边",
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":           "上",
        "down":         "下",
        "out":          "外",
        "enter":        "里",
]);

int cast(object me, object target)
{
	object env, obj;
	int mymana=me->query("mana"), cost=100, i, n;
	int success, ap, dp;
	string msg;
	string *dirs, target_dir, dest;
	mapping exit;

	seteuid(getuid());

	if( !target ) target = offensive_target(me);

	if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「天机无形」？\n");

	if( !me->is_fighting(target))
      return notify_fail(target->query("name")+"已不在战斗中，你要对他施展「天机无形」嘛？\n");

	if(target->query_temp("no_move"))
                return notify_fail(target->query("name")+"已经自顾不暇了！\n");

	if(me->is_busy())
                return notify_fail("你正忙着呢，过会儿运天机咒吧！\n");

        if((int)me->query_skill("spells") < 100 || (int)me->query_skill("tianjizhou", 1) < 100)
                return notify_fail("你的法术修为不够纯熟，无法掌握「天机无形」。\n");

        if( mymana < cost )
                return notify_fail("你的法力不够。\n");

	if((int)me->query("sen") < 10 )
                return notify_fail("你的精神不足，无法施展「天机无形」！\n");

	env = environment(me);
	exit = env->query("exits");

	if( !mapp(exit)) 
                return notify_fail("你想用「天机无形」将"+target->query("name")+"幻到什么地方？\n");

	dirs = keys(exit);
	n = sizeof(exit);
	i = random(n);
	dest = exit[dirs[i]];

	if( !undefinedp(default_dirs[dirs[i]]) )
                target_dir = default_dirs[dirs[i]];
        else
                target_dir = dirs[i];

	if(!(obj = load_object(dest)) )
                return notify_fail("此处无法施展「天机无形」！\n");

	me->add("mana", -cost);
	me->receive_damage("sen", 10);

      msg = HIM "$N口中喃喃地念著咒文，手中一团紫光渐渐扩大，灵动无比！\n" NOR;
        msg += HIM "紫光中只见一条人影被幻向" + target_dir + "。\n" NOR;

	success = 1;
        ap = me->query_skill("spells");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) < dp ) success = 0;

        ap = (int)me->query("max_mana");
        dp = (int)target->query("max_mana");
        if( random(ap + dp) < dp ) success = 0;

        ap = (int)me->query("mana");
        dp = (int)target->query("mana");
        if( random(ap + dp) < dp ) success = 0;

	message_vision(msg, me, target);
	if(success==1 && !GO_CMD->main(target, dirs[i], 0)) {
	    success=0; // failed to go.
	}

	if(success == 1) {
		msg = HIR +target->name()+
                    "被幻向" + target_dir + "去。\n" NOR;
	}
	else {
                msg = HIM "$n看破了你的天机咒，「天机无形」失败了。\n" NOR;
	}

	message_vision(msg, me, target);

	if(success == 1) {
		msg = HIR "只见"+target->name()+
                    "被人用「天机无形」幻得不知方向了。\n" NOR;
               	message( "vision", msg, environment(target), ({target}));
		tell_object(target,
                        "你被人用「天机无形」幻得不知方向了。\n");
               	return 5;
	} else {
		me->start_busy(1+random(2));
		return 3;
	}
}


