// labazou.c 腊八粥

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("腊八粥", ({"laba", "zhou"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "碗");
                set("long", "这是一碗热粥，其中蒸气上冒，兀自有一个个气泡从粥
底冲将上来，一碗粥尽作深绿之色，看上去说不出的诡异。闻着药气刺鼻，其毒可知。\n");
                set("value", 50000);
        }
        setup();
}

int do_eat(string arg)
{
        int force_limit, neili_limit, force_skill, add_skill, improve;

        object me = this_player();

        //force_limit = me->query_skill("force")*10;
        //neili_limit = me->query("max_force");
        //force_skill = me->query_skill("force", 1);

        if (!id(arg))
        return notify_fail("你要吃什么？\n");
        if ( (int)me->query_temp("num" ) > 0 )
        {
                me->add_temp("num", 1);
                me->add("max_force", -100);
                message_vision(HIR "$N又喝下一碗腊八粥，只觉得肝肠寸断，五脏欲裂
，原来喝得太急太多，药效适得其反！\n" NOR, me);
        }

        else
        {
/*              if ( improve < 100 ) {
                        add_skill = force_skill + (100 - improve)/5 + 1;
                        me->set_skill("force", add_skill );
                }
*/
                me->add("max_force", 100);
                me->add("force", 100);

                message_vision(HIY "$N喝下一碗腊八粥，顿然间只觉一股浩荡无比的真
气直冲顶门...\n" NOR, this_player());
                me->set_temp("num", 1);
        }

        me->unconcious();
        destruct(this_object());
        return 1;
}