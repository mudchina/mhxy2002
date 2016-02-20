#include <ansi.h>
inherit NPC;

int do_copy(object me,int maxpot);
int do_back(object me);

void create()
{
      string weapon;
        set_name("煞神", ({ "shashen","shen"}));
        set("gender", "男性");
        set("age", random(30) + 25);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("cps", 23);
        //set("long", "一个穿着黑色夜行衣的人。\n");
        set("combat_exp", 200000 + random(100000)); 
        set("daoxing", 200000 + random(100000)); 
        set("attitude", "friendly");
        set_skill("force", 150);
        set_skill("sword", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("zileidao", 150);
        set_skill("spells", 150);
        set_skill("unarmed",150);
        set_skill("huxiaojian",150);
        set_skill("huxiaoquan",150); 
        set_skill("blade", 150);
        set_skill("huntianforce", 150); 
        set_skill("zhaoyangbu", 150); 
        map_skill("sword","huxiaojian"); 
        map_skill("blade","zileidao");
        map_skill("parry","zileidao");
        map_skill("unarmed","huxiaoquan");
//        prepare_skill("unarmed", "huxiaoquan");

        map_skill("dodge", "zhaoyangbu");
        map_skill("force", "huntianforce");

//        prepare_skill("cuff", "taizu-quan");         
        set("max_kee",1000);     
        set("kee",1000);         
        set("max_sen",1000);     
        set("sen",1000);         
//        set("daoxing",490000);  
//        set("combat_exp",490000)  
        set("force",1000);       
        set("max_force",2800);   
        set("mana",2500);        
        set("max_mana",2000);    
        set("force_factor", 50);
        set("mana_factor", 50); 
        weapon = random(2)?"/d/obj/stey/sttt":"/d/obj/stey/guiblade";
        setup();
        carry_object(weapon)->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}

int do_copy(object me,int maxpot)
{
        int i,j;
        object ob;
        ob = this_object();
        i=maxpot;
        i = i +10+ random(10);
        if( i < 100) i = 100;
        
        ob->set("combat_exp", (me->query("combat_exp")+random(me->query("combat_exp")))*3/4);
        ob->set("daoxing", (me->query("daoxing")+random(me->query("daoxing")))*3/4);
        ob->set_skill("force", i);
        ob->set_skill("sword", i);
        ob->set_skill("blade", i);
//        ob->set_skill("cuff", i);
        ob->set_skill("dodge", i);
        ob->set_skill("parry", i);
        ob->set_skill("huxiaojian", i);       
        ob->set_skill("huxiaoquan", i); 
//        set_skill("yijinjing",i);
                ob->set("max_kee", 2000+i*30); 
                ob->set("max_sen",2000+i*30);
//        ob->set("eff_jingli", me->query("eff_jingli")*2/3); 
        ob->set("max_force", 1000+i*15);
        ob->set("max_mana",1000+i*15); 
        ob->set("force_factor", i/6);
        ob->set("mana_factor",i/6); 
        ob->reincarnate(); 
        ob->set("kee",ob->query("max_kee"));
        ob->set("force",ob->query("max_force"));
        ob->set("mana",ob->query("max_mana"));
        ob->set("sen",ob->query("max_sen")); 
                call_out("do_back", 200,  ob);  
        return 1;
}
int do_back(object me)
{                       
  tell_room(environment(me), me->query("name")+"匆匆忙忙的离开了。\n", ({me})); 
  destruct(me); 
  return 1;
}
