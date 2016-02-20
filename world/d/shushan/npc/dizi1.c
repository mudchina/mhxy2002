//by yushu.2000.11
inherit NPC;
void create()
{
        set_name("Å®µÜ×Ó", ({"di zi"}));
        set("long","ËûÊÇÊñÉ½ÅÉµÄµÜ×Ó¡£\n");
        set("title", "ÊñÉ½ÅÉµÜ×Ó");
        set("gender", "Å®ÐÔ");
        set("attitude", "friendly");
        set("class", "xiake");
        set("age", 20);
        set("per", 23);
        set("max_kee", 400);
        set("max_sen", 400);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 40);
        set("max_mana", 500);
        set("mana", 900);
        set("mana_factor", 30);
        set("combat_exp", 80000);
        set("daoxing", 80000);
        set_skill("force", 40);
        set_skill("zuixian-steps", 40);
        set_skill("whip", 40);
        set_skill("dodge", 40);
        set_skill("snowwhip", 40);
        set_skill("parry", 40);
        set_skill("spells", 40);
        set_skill("shushan-force", 40);
        set_skill("xianfeng-spells", 40);
        map_skill("spells", "xianfeng-spells");
        map_skill("force", "shushan-force");
        map_skill("whip", "snowwhip");
        map_skill("dodge", "zuixian-steps");
        map_skill("parry", "snowwhip");
        setup();
        carry_object("/obj/cloth")->wear();
        carry_object("/d/obj/weapon/whip/pibian")->wield();
            
}

ÿ
