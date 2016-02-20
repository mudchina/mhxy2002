#include <ansi.h>
inherit NPC;

int do_copy(object me,int maxpot,int type);

void create()
{
      string weapon;
        set_name("魔界妖神大汉", ({ "menggu dahan","dahan"}));
        set("gender", "男性");
        set("age", random(20) + 25);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("cps", 23);
        set("combat_exp", 380000 + random(40000));
        set("daoxing", 380000 + random(40000)); 
        set("attitude", "friendly");
        set_skill("force", 80);
        set_skill("sword", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("spells", 80);
        set_skill("zileidao", 80+random(180));
        set_skill("unarmed",50);
        set_skill("huxiaojian",50);
        set_skill("huxiaoquan",50); 
        set_skill("blade", 50);
        set_skill("huntianforce", 50); 
        set_skill("zhaoyangbu", 50); 
        map_skill("sword","huxiaojian"); 
        map_skill("blade","zileidao");
        map_skill("parry","zileidao");
        map_skill("unarmed","huxiaoquan");
        prepare_skill("unarmed", "huxiaoquan");
       
        set_temp("apply/damage", 150);        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: perform_action,"blade", "tulong" :), 
        (: perform_action,"sword", "pili" :),
        (: cast_spell, "zhui" :),
        (: cast_spell, "sishi" :),        
        }) );
         set("max_kee",800);     
        set("kee",800);         
        set("max_sen",1000);     
        set("sen",1000);         
//        set("daoxing",490000);  
//        set("combat_exp",490000)  
        set("force",1500);       
        set("max_force",1500);   
        set("mana",2500);        
        set("max_mana",2000);    
        set("force_factor", 50);
        set("mana_factor", 50); 

        
        weapon = random(2)?"/d/obj/stey/sttt":"/d/obj/stey/guiblade";
        setup();
        carry_object(weapon)->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}

int do_copy(object me,int maxpot,int type)
{
        int i,j;
        object ob;
        ob = this_object();
        i=maxpot;
        if(type==1)
                i = i - random(20);
                else  
            i = i +10+ random(10);
        if( i < 100) i = 100;
        ob->set("combat_exp", (me->query("combat_exp")+random(me->query("combat_exp")))*3/4);
        ob->set("daoxing", (me->query("daoxing")+random(me->query("daoxing")))*3/4);
        ob->set_skill("force", i);
        ob->set_skill("spells", i);
        ob->set_skill("sword", i);
        ob->set_skill("blade", i);
        ob->set_skill("dodge", i);
        ob->set_skill("parry", i);
        ob->set_skill("zileidao", i);       
        ob->set_skill("huxiaoquan", i); 
        ob->set("max_kee",     ob->query_skill("force",1)*10); 
        ob->set("max_sen", me->query("max_sen")*2/3); 
        ob->set("max_force",  ob->query_skill("force",1)*8); 
        ob->set("force_factor", ob->query_skill("force",1)/6);
        ob->set("max_mana",  ob->query_skill("spells",1)*8); 
        ob->set("mana_factor", ob->query_skill("spells",1)/6);
        
        ob->set("kee",ob->query_skill("force",1)*10);
        ob->set("sen", me->query("max_sen")*2/3);
        ob->set("force",ob->query_skill("force",1)*8);
        ob->reincarnate(); 
                
        if(type==3)
                {ob->set("max_kee",     i*30);
                 ob->set("max_force",  i*15); 
                }
                if(type==2)
        ob->set("max_kee",     i*20); 
                ob->reincarnate(); 
        ob->set("kee",ob->query("max_kee"));
        ob->set("force",ob->query("max_force"));
            return 1;
}
