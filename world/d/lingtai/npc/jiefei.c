// mengmian.c 蒙面大汉

inherit NPC;

void create()
{
        set_name("蒙面大汉", ({ "mengmian dahan", "dahan" }));
        set("long",
                "他是一个蒙面大汉。\n");
        set("gender", "男性");
        set("age", 30);
        set("attitude", "aggressive");
        set("shen_type", 1);

        set("str", 30);
        set("int", 30);
        set("con", 35);
        set("dex", 30);

        set("max_kee", 400+random(200));
        set("max_sen", 200);
        set("force",3000);
        set("max_force", 2000);
        set("force_factor",100);
        set("max_mana",2000);
        set("mana",2000);
        set("mana_factor",100);

        set("combat_exp",600000+random(400000));

        set_skill("force", 160);
        set_skill("dodge", 160);
        set_skill("parry", 160);
        set_skill("sword", 160);
        set_skill("birds-sword", 160);
        set_skill("ningxie-force", 140);
        set_skill("spells",150);
        set_skill("buddhism",180);
        set_skill("xiaoyaoyou",150);

        map_skill("parry", "birds-sword");
        map_skill("sword","birds-sword");
        map_skill("force", "ningxie-force");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("spells", "buddhism");

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chaofeng" :),
                (: cast_spell, "bighammer" :),
        }) );

        
        setup();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}

int unconcious()
{
   ::die();
}
