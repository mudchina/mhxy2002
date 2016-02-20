//modify by ken 2001.7.2
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
        if (!wizardp(this_player())) {
                set("no_get", "嘿嘿，你做梦吧! \n");
                set("no_drop","这么好的东西你想丢掉，去死吧! \n");
                set("no_sell","你找死啊，这玩意你也敢卖？\n");
                set("no_give","想去送人，没这回事．\n");
        }
                                              
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIY "火龙丹" NOR, ({"jiuzhuan jindan", "dan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("long", "这就是魔教四宝之一的火龙丹。\n");
                set("value", 100000);
        }

        set("is_monitored", 1);
        setup();
}

int do_eat(string arg)
{
        object victim = this_player();
        int abc;


        if (!id(arg))
                return notify_fail("你要吃什么？\n");
//        if(victim->query("family/family_name") != "魔教")
//                return notify_fail("你最好是别吃，小心中了毒．\n");

        abc = (int)victim->query("JZD_eat");
            if ( abc > 2 ) 
     {
     message_vision(HIR "$N吃下一颗火龙丹，只觉得腹内传来一阵撕心裂肺般的剧痛.......\n" NOR, victim); 
       victim->unconcious();
       victim->die();
       destruct(this_object());
      }
    else
    {
        victim->add("combat_exp", (int)victim->query("combat_exp") / 40);
        victim->add("max_mana",99);
        victim->add("max_force",99);
        victim->add("force",9999);
        victim->add("mana",9999);
        victim->add("JZD_eat",1);
        victim->skill_death_recover();
        victim->save();
        message_vision(HIR "\n$N吃下一粒火龙丹，全身冒出一阵阵金光，功力又进步不少。\n\n" NOR, victim);

        destruct(this_object());
        return 1;
}
}
