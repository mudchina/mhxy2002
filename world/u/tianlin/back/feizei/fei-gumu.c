inherit __DIR__"fei.c";


void set_skills()
{
        object me=this_object();
        object weapon;

        int j;
        j=200+random(150);
        create_family("ÐùÔ¯¹ÅÄ¹", 3, "µÜ×Ó"); 
        set("gender", "Å®ÐÔ");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
        me->set_skill("needle",j); 
        
        me->set_skill("spells",j+random(15));
        me->set_skill("huxing-step",j+random(15));
        me->set_skill("xuanhu-shentong", j+random(15));
        me->set_skill("unarmed", j+random(15));        
        me->set_skill("fox-hand", j+random(15));
        me->set_skill("xuanhu-xinfa", j+random(15)); 

        me->map_skill("force", "xuanhu-xinfa");
        me->map_skill("needle", "tianyi-zhen");        
        me->map_skill("parry", "tianyi-zhen");
        me->map_skill("spells", "xuanhu-shentong");
        me->map_skill("dodge", "huxing-step");
        me->map_skill("unarmed", "fox-hand");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: perform_action,"needle", "jue" :),
        (: cast_spell, "luan" :),
        }) );        
        weapon=new("/clone/weapon/needle1");
        weapon->move(me);
     
        command("wield all");
}
