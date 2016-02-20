//modify by ken 2001.7.2
#include <ansi.h>

inherit ITEM;

int do_eat(string);
int do_tun(string);
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
        add_action("do_tun", "tun");
}

void create()
{
        set_name(HIC "虎丸" NOR, ({"hu wan", "dan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("long", "这就是魔教四宝之二的虎丸。\n");
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
        if(victim->query("family/family_name") != "魔教")
                return notify_fail("你虽不是魔教中人，但是也可吞(tun)。\n");

        abc = (int)victim->query("HY_eat");
            if ( abc > 2 ) 
     {
     message_vision(HIR "$N吃下一颗虎丸，只觉得腹内传来一阵撕心裂肺般的剧痛.......\n" NOR, victim); 
       victim->unconcious();
       destruct(this_object());
      }
    else
    {
        victim->add("combat_exp", (int)victim->query("combat_exp") / 40);
        victim->add("max_mana",99);
        victim->add("max_force",99);
        victim->add("force",9999);
        victim->add("mana",9999);
        victim->add("HY_eat",1);
        victim->skill_death_recover();
        victim->save();
        message_vision(HIG "\n$N吃下一粒虎丸，两目炯炯有神。\n\n" NOR, victim);

        destruct(this_object());
        return 1;
      }
}
int do_tun(string arg)
{
        object victim = this_player();
        int aa;


        if (!id(arg))
                return notify_fail("你要吞什么？\n");
        
        aa = (int)victim->query("HY_tun");
            if ( aa > 1 ) 
     {
     message_vision(HIR "$N吞下一颗虎丸，觉得眼前金星直冒，丹田内一道热气直冲顶门.......\n" NOR, victim); 
       victim->unconcious();
       victim->die();
       victim->set_temp("death_msg","火毒发作死了。\n");

       destruct(this_object());
      }
    else
    {
        victim->add("combat_exp", (int)victim->query("combat_exp") / 40);
        victim->add("max_mana",33);
        victim->add("max_force",33);
        victim->add("force",3333);
        victim->add("mana",3333);
        victim->add("HY_tun",1);
//      victim->skill_death_recover();
        victim->save();
        message_vision(HIG "\n$N吞下一粒虎丸，两目炯炯有神。\n\n" NOR, victim);

        destruct(this_object());
        return 1;
      }
}
