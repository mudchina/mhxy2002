// xisuidan.c �ɵ�

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL "ϴ�赤" NOR, ({ "dan", "xisui dan", "xisuidan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ��԰԰���ɵ�����˵���˿�����ǿ���ǡ�\n");
                set("value", 10000);
		set("unit", "��");
	}
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        me = this_player();
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
        
                tell_object(me, HIY "������Ĺ�����ʱ�������������ͣ���ɰ����Ż��ˣ�"
                                "����һ����������������ƺ���Ǹ�����ˡ�\n" NOR);
                me->add("con", 1);
       
        destruct(this_object());
	return 1;
}
void self_dest(object me)
{
    if(!me) return;
    if(!environment(me)) return;
    tell_object(environment(me),name()+
	    "���ڵ��ϣ������ˡ�\n");
    destruct(me);
}
void announce(object who)
{
 //   if(!this_object()) return;
//    if(!who) return;
//              if(this_player()->query("get")=="dan")
  CHANNEL_D->do_channel(this_object(), "rumor", 
	    this_player()->name()+"��"HIW+
	         	MISC_D->find_place(environment(this_player()))+HIM"�õ��˴�˵�е�"NOR+name()+HIM"��\n");
}
void init()
{ 
	add_action("do_eat", "eat");
       call_out("self_dest",1200000+random(600),this_object());
    remove_call_out("announce");
    call_out("announce",random(10),this_player());
}
