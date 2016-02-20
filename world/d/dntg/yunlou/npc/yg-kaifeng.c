//by tianlin@mhxy 2001.9.18
#include <ansi.h>

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

        me->set("title",HBBLU HIY"ÌìÅî¸®"NOR+HBBLU+HIC"ÅÑÍ½"NOR);
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("rake", j+random(15));
        me->set_skill("skyriver-rake", j+random(15));
        me->set_skill("chaos-steps", j+random(15));
        me->set_skill("tianpeng-zhang", j+random(15));
        me->set_skill("bajie-force", j+random(15));
        me->set_skill("fofa", j+random(15));

        me->map_skill("force", "bajie-force");
        me->map_skill("rake", "skyriver-rake");
        me->map_skill("parry", "skyriver-rake");
        me->map_skill("spells", "fofa");
        me->map_skill("dodge", "chaos-steps");
        me->map_skill("unarmed", "tianpeng-zhang");

        set("chat_chance_combat", cast_chance(level));
        set("chat_msg_combat", ({
        (: perform_action,"rake", "daoda" :),
        (: perform_action,"rake", "zplw" :),
        (: cast_spell, "yading" :),
        (: exert_function, "bianda" :),
        (: exert_function, "recover" :),
        }) );

        weapon=new("/d/obj/weapon/rake/gangpa");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}
