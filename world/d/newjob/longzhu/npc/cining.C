inherit NPC;

void create()
{
        set_name("慈宁公主", ({"cining gongzhu","cining", "gongzhu","shitai"}));
        set("long",
                "慈宁公主是宁心宫的主人。\n");
        set("title", "宁心宫主人");
        set("gender", "女性");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 55);
        set("per", 23);
        set("max_kee", 9000);
        set("max_sen", 9000);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 40);
        set("max_mana", 500);
        set("mana", 900);
        set("mana_factor", 30);
        set("combat_exp", 200000);
        set("daoxing", 9000000);

        set("shen_type", 1);

        set("eff_dx", 90000);
        set("nkgain", 300);


        set_skill("force", 90);
        set_skill("unarmed", 90);
        set_skill("dodge", 90);
        set_skill("jienan-zhi", 90);
        set_skill("parry", 90);
        set_skill("spells", 90);
        set_skill("buddhism", 90);
        map_skill("unarmed", "jienan-zhi");
        map_skill("spells", "buddhism");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: cast_spell, "bighammer" :),
        }) );

        setup();
        carry_object("/d/obj/cloth/monkcloth")->wear();
        carry_object("/d/longzhu/obj/jingshi3");

        setup();
}
