inherit __DIR__"fei.c";


void set_skills()
{
        object me=this_object();
        object weapon;

        int j;
        j=200+random(150);
        create_family("ÊñÉ½ÅÉ", 3, "µÜ×Ó"); 
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
        me->set_skill("sword",j); 
        
        me->set_skill("yujianshu", j+random(15));
        me->set_skill("songhe-sword", j+random(15));        
        me->set_skill("spells",j+random(15));
        me->set_skill("zuixian-steps",j+random(15));
        me->set_skill("xianfeng-spells", j+random(15));
        me->set_skill("unarmed", j+random(15));        
        me->set_skill("fumozhang", j+random(15));
        me->set_skill("shushan-force", j+random(15)); 

        me->map_skill("force", "shushan-force");
        me->map_skill("sword", "songhe-sword");        
        me->map_skill("parry", "songhe-sword");
        me->map_skill("spells", "xianfeng-spells");
        me->map_skill("dodge", "zuixian-steps");
        me->map_skill("unarmed", "fumozhang");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: perform_action,"sword", "wanjian" :),
        (: cast_spell, "jianshen" :),
        }) );        
        weapon=new("/d/obj/weapon/sword/qingfeng");
        weapon->move(me);
     
        command("wield all");
}