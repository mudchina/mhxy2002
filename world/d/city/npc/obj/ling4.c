#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"绿豹令"NOR, ({ "lvbaoling" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
 	     set("value", 200000);
            set("material", "paper");
            set("long", "龙门镖局的令牌。你可以用huwei来要求护卫.\n");
          }

    setup();
}

void init()
{
	add_action("do_alert", "huwei");
}

int do_alert()
{
       object ob,me=this_player();
       object man;
	int strategy,leadership;
       if( !me->is_fighting() )
       return notify_fail("好象没有人要杀你！\n");
       man=new("/d/pingan/npc/lvbao");
       man->move(environment(me));
       man->set("possessed", me);
       man->invocation(me, (leadership+strategy));
       me->remove_all_killer();
       destruct(this_object());
//	message_vision(HIB "\n$N发出一声长求援！\n" NOR, me);	
//	message_vision(HIB "\n$N应声而来！\n" NOR, soldier);
       return 1;
}
