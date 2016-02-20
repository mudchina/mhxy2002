#include <ansi.h>

inherit NPC;

int reset_status();
void create()
{
        set_name(HIW"骷髅兵"NOR, ({ "kulou bing","bing", "guard" }) );

        set("people", 1);
        set("long", "一具被人用咒语控制着的骷髅。\n");
        set("attitude", "heroism");

        set("max_gin", 800);
        set("max_kee", 800);
        set("max_sen", 800);

        set("max_mana", 100);
        set("mana", 100);
        set("max_force", 100);
        set("force", 100);

        set("str", 40);
        set("per", 100);
        set("looking", "全身只有一副骨架，看起来甚是恐怖。");

        set("combat_exp", 50000);
        set("daoxing", 50000);

        set_skill("blade", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);

        setup();

        
        carry_object("/d/obj/weapon/blade/blade")->wield();
}

void init()
{
        add_action("do_attack", "attack");
}

int do_attack(string arg)
{
        object obj, owner;

        if( this_player() != this_object()->query("owner") )
                return notify_fail("骷髅兵口中呜呜两声，好像不愿理你！\n");

        if( !arg || !objectp(obj=present(arg,environment(this_player()))))
           return notify_fail("你想让骷髅兵去攻击谁？\n");

        if( !obj->is_character() )
                return notify_fail("看清楚一点，那并不是生物。\n");

        if( userp(obj) )
                return notify_fail("骷髅兵不会去攻击玩家。\n");

        message_vision("$N附耳对$n说了些什么。\n", this_player(), this_object());
        message_vision("$N对$n喊道：去死吧！\n", this_object(), obj);

        command("kill "+obj->query("id"));
        return 1;
}

void invocation(object who)
{
        set_leader(who);
        command("protect " + who->query("id"));
        set("owner", who);
        reset_status();
        return;
}

void die()
{
        message_vision("\n$N倒了下去，化为一堆枯骨。\n", this_object());
        destruct(this_object());
}

void unconcious()
{
        message_vision("\n$N倒了下去，化为一堆枯骨。\n", this_object());
        destruct(this_object());
}

int reset_status()
{
        object owner,env;
        int n;
        
        owner= query("owner");

        if(  !query("owner"))
        {
                message_vision("$N倒了下去，化为一堆枯骨。\n", this_object());
                destruct( this_object());
                return 1;
        }

        if(!present(owner->query("id"), environment(this_object())))
            {env=environment(owner);
             this_object()->move(env);
             message_vision("$N走了过来。\n",this_object());
            }
        
        
        if( (int)this_object()->query("eff_kee") < (int)this_object()->query("eff_sen") ) {
                n=(int)this_object()->query("eff_kee")/200;
        } else {
                n=(int)this_object()->query("eff_sen")/200;
        }

        if( (int)this_object()->query("eff_kee") < 200
        || (int)this_object()->query("eff_sen") < 200 ) {
                n=1;
        }

        set("people", n);
        set("combat_exp", 50000 + 30000 * n );
        set("combat_exp", 50000 + 30000 * n );
        set_skill("blade", 50 + 15 * n );
        set_skill("parry", 50 + 15 * n );
        set_skill("dodge", 50 + 15 * n );

        set("short", chinese_number(n)+"具骷髅兵(Kulou bing)");
        set("long", chinese_number(n)+"具被人用咒语控制着的骷髅。\n");
        call_out("reset_status", 3);
        return 1;
}

