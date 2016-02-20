//npc by yushu 2000.11
inherit NPC;
void create()
{
        set_name("Ã÷ÔÂ", ({"ming yue"}));
        set("long","ËûÊÇÊñÉ½ÅÉµÄµÜ×Ó¡£\n");
        set("title", "ÊØÉ½µÜ×Ó");
        set("gender", "ÄĞĞÔ");
        set("attitude", "friendly");
        set("class", "xiake");
        set("age", 30);
        set("per", 23);
        set("max_kee", 600);
        set("max_sen", 600);
        set("force", 700);
        set("max_force", 700);
        set("force_factor", 40);
        set("max_mana", 700);
        set("mana", 700);
        set("mana_factor", 30);
        set("combat_exp", 150000);
        set("daoxing", 80000);
        set_skill("force", 80);
        set_skill("zuixian-steps", 100);
        set_skill("sword", 80);
        set_skill("dodge", 100);
        set_skill("yujianshu", 80);
        set_skill("parry", 80);
        set_skill("spells", 80);
        set_skill("shushan-force", 80);
        set_skill("xianfeng-spells", 80);
        map_skill("spells", "xianfeng-spells");
        map_skill("force", "shushan-force");
        map_skill("sword", "yujianshu");
        map_skill("dodge", "zuixian-steps");
        map_skill("parry","yujianshu");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
            (: perform_action, "sword", "fumo" :),

       }) );
       setup();
       carry_object("/obj/cloth")->wear();
       carry_object("/d/obj/weapon/sword/qingfeng")->wield();
            
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        set("chat_chance", 20);
        set("inquiry", ([
                "ºóÉ½" : "ÄãÏëÈ¥ºóÉ½,ÏÈ´òÓ®ÎÒÔÙËµ!\n",
  ]) );
}


ÿ
