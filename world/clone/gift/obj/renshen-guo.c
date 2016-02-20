// renshen-guo.c 人参果
// suppose to be able to be given and got,
// please let me know before changing...weiqi980417

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
      if(this_player()==environment())
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIW "人参果" NOR, ({"renshen guo", "renshenguo", "guo"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("long", "白白胖胖的一枚人参果。好象还没有完全熟透，更奇怪的是，隐隐散发着臭味。\n");
                set("value", 500);
                set("drug_type", "补品");
        }
        set("no_drop",1);
        set("no_put",1);
        set("is_monitored",1);
        setup();
  set("is_monitored",1);
}

int do_eat(string arg)
{
        int howmany;

        object me = this_player();
  
        if (!id(arg)) return notify_fail("你要吃什么？\n");

        howmany = (int)me->query("rsg_eaten");
  
        me->set("food", (int)me->max_food_capacity());

                if( howmany <= 10 ) me->add_maximum_force(5);
               if( howmany <= 10 ) me->add_maximum_mana(5);

        me->set("rsg_eaten", howmany+1);

            message_vision(HIW "$N把人参果往嘴里一塞，忍不住大叫一声：人参果啊人参果，不愧是人参果！ \n说罢兴奋得都快晕了过去。\n\n"NOR,me);
message_vision(HIR"可是你仔细又一看，不由得大叫：“原来是假的啊！哪个神仙这么缺德哟?? \n"NOR, me); 

write(HIG"\n一个声音在你耳边响起...............\n"NOR);
write(BLU"恭喜你吃人参果的数量又加了一.现在你总共吃了"+chinese_number(howmany+1)+"次人参果了\n"NOR);
        destruct(this_object());

        return 1;

}
