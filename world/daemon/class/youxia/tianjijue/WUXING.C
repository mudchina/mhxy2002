// ����������Ӱ

#include <ansi.h>
#include <command.h>

inherit SSERVER;

mapping default_dirs = ([
        "north":        "��",
        "south":        "��",
        "east":         "��",
        "west":         "��",
        "northup":      "����",
        "southup":      "�ϱ�",
        "eastup":       "����",
        "westup":       "����",
        "northdown":    "����",
        "southdown":    "�ϱ�",
        "eastdown":     "����",
        "westdown":     "����",
        "northeast":    "����",
        "northwest":    "����",
        "southeast":    "����",
        "southwest":    "����",
        "up":           "��",
        "down":         "��",
        "out":          "��",
        "enter":        "��",
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
                return notify_fail("��Ҫ��˭ʩչ��������Ρ���\n");

	if( !me->is_fighting(target))
      return notify_fail(target->query("name")+"�Ѳ���ս���У���Ҫ����ʩչ��������Ρ��\n");

	if(target->query_temp("no_move"))
                return notify_fail(target->query("name")+"�Ѿ��Թ˲�Ͼ�ˣ�\n");

	if(me->is_busy())
                return notify_fail("����æ���أ�������������ɣ�\n");

        if((int)me->query_skill("spells") < 100 || (int)me->query_skill("tianjizhou", 1) < 100)
                return notify_fail("��ķ�����Ϊ�������죬�޷����ա�������Ρ���\n");

        if( mymana < cost )
                return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 10 )
                return notify_fail("��ľ����㣬�޷�ʩչ��������Ρ���\n");

	env = environment(me);
	exit = env->query("exits");

	if( !mapp(exit)) 
                return notify_fail("�����á�������Ρ���"+target->query("name")+"�õ�ʲô�ط���\n");

	dirs = keys(exit);
	n = sizeof(exit);
	i = random(n);
	dest = exit[dirs[i]];

	if( !undefinedp(default_dirs[dirs[i]]) )
                target_dir = default_dirs[dirs[i]];
        else
                target_dir = dirs[i];

	if(!(obj = load_object(dest)) )
                return notify_fail("�˴��޷�ʩչ��������Ρ���\n");

	me->add("mana", -cost);
	me->receive_damage("sen", 10);

      msg = HIM "$N�����૵��������ģ�����һ���Ϲ⽥�������鶯�ޱȣ�\n" NOR;
        msg += HIM "�Ϲ���ֻ��һ����Ӱ������" + target_dir + "��\n" NOR;

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
                    "������" + target_dir + "ȥ��\n" NOR;
	}
	else {
                msg = HIM "$n�������������䣬��������Ρ�ʧ���ˡ�\n" NOR;
	}

	message_vision(msg, me, target);

	if(success == 1) {
		msg = HIR "ֻ��"+target->name()+
                    "�����á�������Ρ��õò�֪�����ˡ�\n" NOR;
               	message( "vision", msg, environment(target), ({target}));
		tell_object(target,
                        "�㱻���á�������Ρ��õò�֪�����ˡ�\n");
               	return 5;
	} else {
		me->start_busy(1+random(2));
		return 3;
	}
}

