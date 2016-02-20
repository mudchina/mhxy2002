inherit NPC;
string *first_name = ({ "¶öËÀ¹í", "µõËÀ¹í", "±¥ËÀ¹í", "ÐÞÂÞ¹í", "ÔÂ¹â¹í", "ÎüÑª¹í"});

void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];

        set_name(name, ({ "gui" }) );
        set("age", 3000);
        set("long", "Ò»Ö»±»¹ØÔÚºÚ°µÖ®Ô¨µÄ¶ñ¹í¡£\n");
        set("str", 20);
        set("cor", 30);
set("attitude", "aggressive");
        set("max_force", 3000);
        set("mana", 4000);
        set("force", 4000);
        set("max_mana", 3000);
        set("force_factor", 100);
        set("mana_factor", 150);
        set("max_kee", 2000);
        set("max_sen", 2000);
        set("combat_exp", 1000000+random(1000000));
  set("daoxing", 5000000);

    set_skill("dodge", 160);
        set_skill("unarmed", 100);
    set_skill("parry", 160);
    set_skill("moshenbu", 160);
    set_skill("force", 160);
    set_skill("wuxiangforce", 160);
    set_skill("sword", 200);
    set_skill("liangyi-sword", 200);
    set_skill("dao", 200);
    set_skill("spells", 200);
       map_skill("force", "wuxiangforce");
       map_skill("parry", "liangyi-sword");
       map_skill("sword", "liangyi-sword");
       map_skill("dodge", "moshenbu");
       map_skill("spells", "dao");
         set("chat_chance_combat", 30);
         set("chat_msg_combat", ({
        (: cast_spell, "light" :),
        (: cast_spell, "thunder" :),
        (: cast_spell, "dingshen" :)
       }));
        set_temp("apply/damage", 25);
        set_temp("apply/armor", 80);
        setup();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}

