//Cracked by Roath
//¡¾ÊñÉ½½£ÅÉ¡¿dhxy-evil 2000.7.5
//by yushuÐÞ¸Ä
inherit NPC;
void create()
{
        set_name("½£Í¯", ({ "jian tong", "tong" }));
        set("title", "ÊñÉ½½£ÅÉ");
        set("gender", "ÄÐÐÔ");
        set("age", 8 + random(10));
        set("attitude", "peaceful");
        set("str", 18);
        set("int", 25);
        set("con", 20);
        set("cor", 20);
        set("class","xiake");
        
        set("max_kee", 500);
        set("max_sen", 500);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 20);
        set("combat_exp", 10000);
        set("score", 500);

        set_skill("force", 30);
        set_skill("shushan-force", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_skill("sword", 30);
        set_skill("unarmed", 30);
        set_skill("spells", 30);
        set_skill("fumozhang", 30);
        set_skill("yujianshu", 30);
        set_skill("zuixian-steps", 30);    
        set_skill("xianfeng-spells",30);

        map_skill("dodge", "zuixian-steps");
        map_skill("spells", "xianfeng-spells");
        map_skill("force", "shushan-force");
        map_skill("parry", "yujianshu");
        map_skill("sword", "yujianshu");
        map_skill("unarmed", "fumozhang");

        setup();
        carry_object("/d/obj/cloth/daopao")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}