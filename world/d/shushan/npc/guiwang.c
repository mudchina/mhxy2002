// modified by vikee 2000.11
//【蜀山剑派】dhxy-evil 2000.7.5
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("鬼王", ({ "gui wang", "wang" }));
        set("title", "");
        set("age", 300);
        set("attitude", "aggressive");
        set("str", 40);
        set("per", 20);
        set("con", 30);
        set("cor", 30);
        
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("force", 3000);
        set("max_force", 2000);
        set("force_factor", 60);
        set("mana", 3000);
        set("max_mana", 2000);
        set("mana_factor", 60);
        set("combat_exp", 800000);
        set("daoxing", 1000000);

        set_skill("spells",120);
        set_skill("force", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("unarmed", 120);
        set_skill("shushan-force", 120);
        set_skill("zuixian-steps", 120);
        set_skill("xianfeng-spells",120);
        set_skill("fumozhang",120);
        map_skill("spells", "xianfeng-spells");
        map_skill("dodge", "zuixian-steps");
        map_skill("force", "shushan-force");
        map_skill("unarmed", "fumozhang");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: cast_spell, "jiushen" :),
        }) );
   add_temp("apply/damage", 20);
   add_temp("apply/armor", 20);

        setup();
        carry_object("/obj/cloth")->wear();

}

void die()
{
        if( environment() ) {
        message("sound", CYN"\n鬼王道：“请原谅我，因为这里的妖精都认为只要能吃九百九十九个妖精\n或者一百个人类就可以出去，所以...”\n", environment());
        message("sound", "\n鬼王又道：“从你身上，我发现了希望，希望你能够带我们离开这个塔...前面如果有麻烦的话，尽管找我！”\n", environment());
        message("sound", "\n鬼王消失得无影无踪...\n"NOR, environment());
        }
        destruct(this_object());
}


