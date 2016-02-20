//Cracked by Roath
//¡¾ÊñÉ½½£ÅÉ¡¿dhxy-evil 2000.7.5
inherit NPC;

void create()
{
        set_name("ÊØÉ½½£Í¯", ({ "jian tong", "tong" }));
        set("title", "ÊñÉ½½£ÅÉ");
        set("gender", "ÄÐÐÔ");
        set("age", 8 + random(10));
        set("attitude", "peaceful");
        set("str", 18);
        set("int", 25);
        set("con", 20);
        set("cor", 20);
        set("class","swordsman");
        
        set("max_kee", 800);
        set("max_sen", 800);
        set("force", 1500);
        set("max_force", 1000);
        set("force_factor", 30);
        set("mana", 1500);
        set("max_mana", 1000);
        set("mana_factor", 30);
        set("combat_exp", 300000);
        set("daoxing", 500000);

        set_skill("force", 70);
        set_skill("shushan-force", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
        set_skill("sword", 70);
        set_skill("unarmed", 70);
        set_skill("spells", 70);
        set_skill("fumozhang", 70);
        set_skill("yujianshu", 70);
        set_skill("zuixian-steps", 70);    
        set_skill("xianfeng-spells",70);

        map_skill("dodge", "zuixian-steps");
        map_skill("spells", "xianfeng-spells");
        map_skill("force", "shushan-force");
        map_skill("parry", "yujianshu");
        map_skill("sword", "yujianshu");
        map_skill("unarmed", "fumozhang");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "jianshen" :),
                (: exert_function, "recover" :),
        }) );
   add_temp("apply/damage", 15);
   add_temp("apply/armor", 15);
        setup();
        carry_object("/d/obj/cloth/daopao")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}

