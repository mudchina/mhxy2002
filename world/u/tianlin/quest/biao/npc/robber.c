//by LitChi /6/19/2001 

#include <ansi.h>
inherit NPC;
#include "robber.h"

int fresh=1;

void copy_weapon(object me, object ob)
{
   object *inv;
   int i,j, weapon_cnt, armor_cnt;
   inv = all_inventory(me);
   for(i=0; i<sizeof(inv); i++) 
   {
     destruct(inv[i]);
   }
   // save once here, an external bug might stop the following
//   me->setup();
   me->save();
   weapon_cnt = 0;
   armor_cnt = 0;
   inv = all_inventory(ob);
   for(i=0; i<sizeof(inv); i++) 
   {
     if ( !inv[i]->query_unique() && 
     inv[i]->query("skill_type") &&
     inv[i]->query("equipped") && !weapon_cnt ) 
     {
        object obj = new(base_name(inv[i]));
        if (obj)
        {
          if(obj->move(me)) // mon 8/13/97
          obj->wield();
        }
        me->set("weapon", base_name(inv[i]));
        weapon_cnt = 1;
     }
     else if ( !inv[i]->query_unique() && 
     !inv[i]->query("skill_type") && 
     inv[i]->query("equipped") && !armor_cnt ) 
     {
        object obj = new(base_name(inv[i]));
        if (obj)
        {
          if(obj->move(me))
          obj->wear();   //mon 8/13/97
        }
        me->set("armor", base_name(inv[i]));
        armor_cnt = 1;
     }
     else if( weapon_cnt && armor_cnt )
        break;
   }
}

void copy_status(object me, object ob)
{
//   object *inv;
   mapping hp_status, skill_status, map_status;
   string *sname, *mname,killme,killmeid;
   int i,j;//, weapon_cnt, armor_cnt;
   reset_eval_cost();
   hp_status = ob->query_entire_dbase();
   me->set("str", hp_status["str"]);
   me->set("per", hp_status["per"]);
   me->set("int", hp_status["int"]);
   me->set("age", hp_status["age"]);
   me->set("attitude","aggressive");
   set_name(HIW"劫匪"NOR,({"robber"}));
   me->set("gender",    hp_status["gender"]);
   me->delete("title");
   me->set("short",     capitalize(me->query("name"))+"("+capitalize(me->query("id"))+")");
   me->set("combat_exp",hp_status["combat_exp"]+hp_status["combat_exp"]/10);
   me->set("chat_chance_combat",40);
   me->set("chat_msg_combat", ({
        (: cast_spell, "bighammer" :),
        (: cast_spell, "jingang" :),
        (: cast_spell, "yinshen" :),
        (: cast_spell, "light" :),
        (: cast_spell, "fenshen" :),
        (: cast_spell, "dingshen" :),
        (: cast_spell, "invocation" :),
        (: cast_spell, "thunder" :),
        (: cast_spell, "arrow" :),
        (: cast_spell, "mihun" :),
        (: cast_spell, "gouhun" :),
        (: cast_spell, "freez" :),
        (: cast_spell, "hufa" :),
        (: cast_spell, "miwu" :),
        (: cast_spell, "huanying" :),
        (: cast_spell, "tudun" :),
        (: cast_spell, "suliao" :),
        (: cast_spell, "gouhun" :),
        (: cast_spell, "escape" :),
        (: cast_spell, "jieti" :),
        }) );//增加难度
   if(fresh==1) {
     fresh=0;
     me->set("eff_kee",  hp_status["eff_kee"]);
     me->set("kee",      hp_status["kee"]);
     me->set("eff_gin",  hp_status["eff_gin"]);
     me->set("gin",      hp_status["gin"]);
     me->set("eff_sen",  hp_status["eff_sen"]);
     me->set("sen",      hp_status["sen"]);
     me->set("eff_dx", me->query("combat_exp"));
     if(COMBAT_D->check_family(ob->query("family/family_name"))>0)
       me->set("eff_dx", -me->query("eff_dx"));
     if(me->query("combat_exp")>10000)
       me->set("nkgain",100); //maximum gain for killing yao.
   }
   me->set("max_gin",     hp_status["max_gin"]);
   me->set("max_kee",     hp_status["max_kee"]);
   me->set("max_sen",     hp_status["max_sen"]);
   me->set("max_force",   hp_status["max_force"]);
   me->set("max_mana",    hp_status["max_mana"]);
   me->set("eff_gin", me->query("max_gin"));
   me->set("gin",     me->query("max_gin"));
   me->set("eff_kee", me->query("max_kee"));
   me->set("kee",     me->query("max_kee"));
   me->set("eff_sen", me->query("max_sen"));
   me->set("sen",     me->query("max_sen"));
   me->set("force",   me->query("max_force")+me->query("max_force")*4/5);
   me->set("mana",    me->query("max_mana")+me->query("max_mana")*4/5);
   if(skill_status = me->query_skills()) {// delete old skills.
      sname  = keys(skill_status);
      j=sizeof(skill_status);
           for(i=0; i<j; i++) {me->delete_skill(sname[i]);}
   }
   if (skill_status = ob->query_skills() ) {//copy new skills.
      sname  = keys(skill_status);
      for(i=0; i<sizeof(skill_status); i++) {me->set_skill(sname[i], skill_status[sname[i]]);}
   }
   me->set("force_factor",me->query_skill("force")*4/5);
   me->set("mana_factor", me->query_skill("spells")*4/5);
   me->add_temp("apply/armor",(me->query_skill("spells")+me->query_skill("force"))/8);
   me->add_temp("apply/dodge",(me->query_skill("spells")+me->query_skill("force"))/8);
   me->add_temp("apply/damage",(me->query_skill("spells")+me->query_skill("force"))/10);
   reset_eval_cost();
   //delete old skill mappings.
   if(map_status = me->query_skill_map()) {
     mname  = keys(map_status);
     j=sizeof(map_status);
     for(i=0; i<j; i++) {
       me->map_skill(mname[i]);
   }}
   //add new skill mappings.
   if (map_status = ob->query_skill_map()) {
     mname  = keys(map_status);
     for(i=0; i<sizeof(map_status); i++) {
     me->map_skill(mname[i], map_status[mname[i]]);
   }}
   copy_weapon(me,ob);//复制装备
//   me->setup();
   me->save();
   reset_eval_cost(); //   return 1;
}


void kill_ob (object ob)
{
        object me = this_object();
        object who= this_player();
        
        if(query("masterid") == ob->query("id"))
          {if (who->query_temp("robber_rec")==1)
          copy_status(me,ob);
          who->set_temp("robber_rec",0);
          }

//        me->kill_ob(who);

//        if( who->query("id") == query("masterid") || who->query("id") == "biao tou" ) me->kill_ob(who);
//        else { message_vision("劫匪叫道：“我又没抢你的镖，干吗打我？？”\n", who);  { me->remove_all_enemy(); who->remove_all_enemy(); } }
        return;
}

void create()
{ 
        set_name(HIW"劫匪"NOR,({"robber"}));
        set("long","这是一位武当派弃徒。\n");
        set("title","拦路抢劫");
        set("gender", "男性" );
        set("age", random(30)+14);
        
        set("vendetta/authority", 1);
  set("max_sen", 200);
  set("max_kee", 600);
  set("force", 500);
  set("max_force", 400);
  set("force_factor", 20);
  set("combat_exp", 80000);
     
        setup();
  create_family("将军府", 3, "蓝");
  carry_object("/d/obj/armor/tenjia")->wear();
  carry_object("/d/obj/weapon/spear/tieqiang")->wield();
}

void init()
{
    ::init();
    add_action("do_cast", "cast");
//    call_out("destroying",random(800)+1000,this_object());
}

void do_change(object ob)
{
      object me;
      mapping hp_status, skill_status;
      string *sname;
      int i, temp;
      me = this_object();
      ob = this_player();       
      if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname  = keys(skill_status);
                temp = sizeof(skill_status);
                for(i=0; i<temp; i++) {
                        me->delete_skill(sname[i]);
                }
      }
/*
      if ( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
                sname  = keys(skill_status);
                temp = skill_status[0];
                for(i=0; i<sizeof(skill_status); i++) {
                if(sname[i]=="force") i++;
                  if (skill_status[sname[i]] >= temp)
                  { temp = skill_status[sname[i]];}
              }
        }
*/
  set_skill("spear", 120);
  set_skill("force", 120);
  set_skill("dodge", 120);
  set_skill("parry", 120);
  set_skill("yanxing-steps", 120);
  set_skill("bawang-qiang", 120);
  set_skill("lengquan-force", 120);
  set_skill("unarmed", 120);
  set_skill("changquan", 120);
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "yanxing-steps");

/* copy hp */

        hp_status = ob->query_entire_dbase();
        me->set("str", hp_status["str"]+random(2));
        me->set("int", hp_status["int"]);
        me->set("con", hp_status["con"]+random(2));
        me->set("dex", hp_status["dex"]);
        me->set("combat_exp",hp_status["combat_exp"]);
        me->set("daoxing",hp_status["daoxing"]);

}

void unconcious()
{
   command("die");
   destruct(this_object());
}

void die()
{
   command("die");
   destruct(this_object());
}

int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N对着劫匪结结巴巴的念了几句咒语，自己都感觉难听死了。\n",who,me);

  return 1;
}
