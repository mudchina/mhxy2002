#include <ansi.h>
inherit NPC;

int do_copy(object me,int flag);
int do_back(object me);

void create()
{
      string weapon;
        set_name("魔界黑杀神", ({ "heiyi ren","ren"}));
        set("gender", "男性");
        set("age", random(20) + 25);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
//        set("long", "一个穿着黑色夜行衣的人。\n");
        set("combat_exp", 500000 + random(400000));
        set("daoxing", 500000 + random(400000)); 
        set("attitude", "friendly");
        set_skill("force", 150);
        set_skill("sword", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("spells", 150);
        set_skill("zileidao", 150);
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
   
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: perform_action,"blade", "tulong" :), 
        (: perform_action,"sword", "pili" :),
        (: cast_spell, "zhui" :),
        (: cast_spell, "sishi" :),        
        }) );
        set("max_kee",1000);     
        set("kee",1000);         
        set("max_sen",1000);     
        set("sen",1000);         
//        set("daoxing",490000);  
//        set("combat_exp",490000)  
        set("force",2000);       
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

int do_copy(object me,int flag)
{
        int i,j;
        object ob;
        ob = this_object();

        i = me->query_skill("dodge",1);
        j = me->query_skill("force",1);
//        j = me->query_skill("force",1);
        i = i>j?i:j;
                if(flag==0)
                i = i - random(20);
                else 
            i = i + random(20);
        if( i < 60) i = 60;
        
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
        ob->reincarnate(); 
        ob->set("kee",ob->query_skill("force",1)*10);
        ob->set("sen", me->query("max_sen")*2/3);
        ob->set("force",ob->query_skill("force",1)*8);
                call_out("do_back", 350,  ob);  
        return 1;
}
int do_back(object me)
{                       
  tell_room(environment(me), me->query("name")+"匆匆忙忙的离开了。\n", ({me})); 
  destruct(me); 
  return 1;
}
void die()
{
        object corpse;
        mixed killer;
        if( !living(this_object()) ) revive(1);
        else delete_temp("faint_by");
        COMBAT_D->announce(this_object(), "dead");
        if( !(killer = query_temp("last_damage_from")) )
        killer = "莫名其妙地";
        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
        corpse->move(environment());
        set_temp("last_damage_from", "莫名其妙地");
    corpse->set_temp("must_killby",this_object()->query_temp("must_killby"));
        this_object()->remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());
    destruct(this_object());
}
