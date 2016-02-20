//by tianlin@mhxy 2001.9.18
#include <ansi.h>

inherit __DIR__"yaoguai.c";

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

        me->set("title",HBRED HIW"Ñ©É½ÀÏÑý"NOR);
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("blade", j+random(15));
        me->set_skill("bingpo-blade", j+random(15));
        me->set_skill("xiaoyaoyou", j+random(15));
        me->set_skill("dengxian-dafa", j+random(15));
        me->set_skill("ningxie-force", j+random(15));
        me->set_skill("cuixin-zhang", j+random(15));

        me->map_skill("force", "ningxie-force");
        me->map_skill("blade", "bingpo-blade");
        me->map_skill("parry", "bingpo-blade");
        me->map_skill("spells", "dengxian-dafa");
        me->map_skill("dodge", "xiaoyaoyou");
        me->map_skill("unarmed", "cuixin-zhang");

        set("chat_chance_combat", cast_chance(level));
        set("chat_msg_combat", ({
        (: cast_spell, "tuntian" :),
        }) );

           weapon=new("/d/obj/weapon/blade/jindao");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}
