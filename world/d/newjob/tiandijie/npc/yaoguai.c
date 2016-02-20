//Cracked by Roath
// bula and mon@xyj
// base file for inheritance.
inherit NPC;
#include <ansi.h>
int exp_reward, pot_reward;

string *death_msg= ({
"$n一看大势已去，化着一道白光，消失得无影无踪了。\n",
"$n阴深深地一笑:“你别得意，我还会回来的。。”\n说完化做一道青光，直冲云霄去了．．．\n",
"$n叹了口气:“早知今日，何必当初！”\n呆了半厢，化做一股清气，消散于无形之中．．．\n",
});

int random_place(object me, string* dirs);
void _leave();
void leave();
void leave2();
void copy_weapon(object me, object ob);

void create()
{
       set("title",HIR"魔教长老"NOR);
    set_name("心魔", ({"xinmo"}));
    set("long",HIC"由人的内心里跑出来的心魔，只有战胜心魔，才能超越自我。\n"NOR);
    set("attitude", "heroism");
        set("chat_chance", 5);
        set("chat_msg", ({
             (: random_move :)
        }) );
         setup();
}

void copy_status(object me, object ob) 
{
   mapping map_status,skill_status;
   string *mname, *sname;
   int i,j;
     j=random(10);
    me->set("str", ob->query("str"));
    me->set("int", ob->query("int"));
    me->set("cps", ob->query("cps"));
    me->set("cor", ob->query("cor"));
    me->set("age", ob->query("age"));
    me->set_name(ob->query("name")+"的心魔", ({"xinmo"}));
    me->set("gender",ob->query("gender"));
    me->set("owner",ob->query("id"));
//    me->set("short",query("name")+"("+capitalize( query("id"))+")");
    me->set("family/family_name",ob->query("family/family_name"));
    me->set("max_gin",     ob->query("max_gin"));
    me->set("max_kee",     ob->query("max_kee"));
    me->set("max_sen",     ob->query("max_sen"));
    me->set("max_force",   ob->query("max_force"));
    me->set("max_mana",    ob->query("max_mana"));
    me->set("eff_gin", ob->query("max_gin"));
    me->set("gin",     ob->query("max_gin"));
    me->set("eff_kee", ob->query("max_kee"));
    me->set("kee",     ob->query("max_kee"));
    me->set("eff_sen", ob->query("max_sen"));
    me->set("sen",     ob->query("max_sen"));
    me->set("force",   ob->query("max_force")+ob->query("max_force")*4/5);
    me->set("mana",    ob->query("max_mana")+ob->query("max_mana")*4/5); 
    me->set("force_factor",ob->query_skill("force")*4/5);
    me->set("mana_factor", ob->query_skill("spells")*4/5);
    me->set("combat_exp",ob->query("combat_exp")+ob->query("combat_exp")/10);
    me->set("daoxing",ob->query("daoxing")+ob->query("daoxing")/10);
   //copy new skills.
   skill_status = ob->query_skills(); 
   if(skill_status){
        sname  = keys(skill_status);
        for(i=0; i<sizeof(skill_status); i++) {
        me->set_skill(sname[i], skill_status[sname[i]]+j);
        }
    }
   //add new skill mappings.
   map_status = ob->query_skill_map();
   if(map_status){
        mname  = keys(map_status);
        for(i=0; i<sizeof(map_status); i++){
        me->map_skill(mname[i], map_status[mname[i]]);
        }
   }
   copy_weapon(me,ob);//复制装备
}
 
void copy_weapon(object me, object ob)
{
   object *inv;
   int i,j;
   inv = all_inventory(me);
   for(i=0; i<sizeof(inv); i++) 
   {
     destruct(inv[i]);
   }
   // save once here, an external bug might stop the following
    inv = all_inventory(ob);
    for(i=0; i<sizeof(inv); i++) 
    {
     if ( !inv[i]->query_unique() && 
     inv[i]->query("skill_type")&&
     inv[i]->query("equipped")) 
     {
        object obj = new(base_name(inv[i]));
        if (obj)
        {
          if(obj->move(me)) // mon 8/13/97
          obj->wield();
        }
        me->set("weapon", base_name(inv[i]));
     }
     else if ( !inv[i]->query_unique() && 
     !inv[i]->query("skill_type")&&
     inv[i]->query("equipped")) 
     {
        object obj = new(base_name(inv[i]));
        if (obj)
        {
          if(obj->move(me))
          obj->wear();   //mon 8/13/97
        }
        me->set("armor", base_name(inv[i]));
     }
   }
   me->set_skills();
}

int random_place(object me, string* dirs)
{
        int  i, j, k;
        object  newob;
        mixed*  file, exit;

        if( !sizeof(dirs) )  return 1;

        i = random(sizeof(dirs));    // pick up one directory

        file = get_dir( dirs[i]+"/*.c", -1 );
        if( !sizeof(file) )             return 1;
        for(k=0;k<30;k++) { // try 20 times
           j = random(sizeof(file));
           if( file[j][1] > 0 ) {
             newob=load_object(dirs[i]+"/"+file[j][0]);
             if (newob) {  
               if(newob->query("no_fight") ||
                       newob->query("no_magic") ||
                       newob->query("no_mieyao") ||
                       !(exit=newob->query("exits")) ||
                       sizeof(exit)<1)
                   continue;

               if( move(newob)) {
                   message_vision("$N走了过来。\n",me);
                   return 1;
               }
             }
           }
        }

        return 0;
}
void _leave()
{
    object me=this_object();
    
    // if in fighting, then don't disappear.
    if( is_fighting() ||  is_busy())
        return;
    leave();
}

void leave()
{
      if(this_object()) { 
        if(environment())
          message("vision",HIB + name() + 
                  "身子一晃，变成一股青烟散去了。\n" NOR,environment());
        this_object()->move("/obj/empty");
        call_out("leave2",5);
      }
      return;
}

void leave2()
{
    if(this_object()) {
        destruct(this_object());
    }
}
void check_room()
{
    object me=this_object();
    object env=environment(me);
    
    if(!living(me)) return;
    if(env && (env->query("no_fight") ||
                env->query("no_magic"))) {
        random_move();
    }
}

void init()
{
    object me=this_object();
    object who=this_player();
    string type;
    int t=query("stay_time");
    ::init();
    
    // if overtime too long, then destroy. mon 7/14/99
    if(t && time()>(t+600)) {
        remove_call_out("leave");
        call_out("leave",1);
        return;
    }

    if(t && time()>t) {
        remove_call_out("_leave");
        call_out("_leave",200);
    }
    
    if(!userp(this_player())) return;
    if(!living(this_object())) return;
    
    remove_call_out("check_room");
    call_out("check_room",2);
}

void unconcious()
{
  if (query("kee")<0 || query("sen")<0) die();
   else ::unconcious();
}

void die()
{
        string skill;
        object *inv,who,me=this_object();
        object ob = query_temp("last_damage_from");
        string str;
        string msg;
        int exp,i,max_kee, max_sen, ratio, exp_r, pot_r;
        int reword;

       inv = all_inventory( environment(this_object()) );
      for(i=0; i<sizeof(inv); i++)
      {
        who=inv[i];
        reword=who->query("xinmo/rekee")+who->query("xinmo/resen");
        if( !userp(inv[i])||reword<=0)continue; 
        // determine reward
        exp=(query("combat_exp")+query("daoxing"))/2;
        if(exp<30000) {
            exp_reward=500+exp/60;
            pot_reward=200+exp/300;
        } else if(exp<300000) {
            exp_reward=1000+exp/600;
            pot_reward=300+exp/6000;
        } else if(exp<3000000) {
            exp_reward=1500+exp/6000;
            pot_reward=350+exp/20000;
        } else {
            exp_reward=2000;
            pot_reward=500;
        }

            if(living(who)) {
                    max_kee=query("max_kee");
                    max_sen=query("max_sen");
                    ratio=100*reword/max_kee;
//                      ratio=ratio*(who->query("daoxing")+who->query("combat_exp"))/2/exp;
                    if(ratio>100) ratio=100;
//                  ratio=ratio*reword_sen/max_sen;
//                  if(ratio<0) ratio=0;
                    if(who->query("id")!=query("owner")
                     &&who->query("family/family_name")!=query("family/family_name"))
                    ratio=ratio*0.2;
                    if(who->query("id")!=query("owner")
                     &&who->query("family/family_name")==query("family/family_name"))
                     ratio=ratio*0.4;
                    exp_r=exp_reward*ratio/100;
                    pot_r=pot_reward*ratio/100;
                            
                    str="kill xinmo got "+exp_r+"/"+exp_reward+" daoxing "+
                        pot_r+"/"+pot_reward+" pot.\n";

                    MONITOR_D->report_system_object_msg(who, str);

                    who->add("daoxing",exp_r);
                    who->add("potential",pot_r);
                    who->delete("xinmo");
        CHANNEL_D->do_channel( this_object(), "rumor",
        sprintf("攻打%s的"NOR+YEL"<%s>"HIM"被%s杀死了。"NOR,query("family/family_name"),query("name"), ob->name() ));
                    tell_object(who, "你得到了"+COMBAT_D->chinese_daoxing(exp_r)
                            +"道行和"+chinese_number(pot_r)+"点潜能！\n");
                }
        }
        message_vision(death_msg[random(sizeof(death_msg))],who,me);
        DISASTER_D->add("xinmo_die",1);
        destruct(me);

}
varargs int receive_wound(string type, int damage, object who)
{
      if(objectp(who)){
        if(userp(who)) {
     
           // can't use other's NPC to help kill.
         if(damage>0) {
            switch(type) {
                case "kee": who->add("xinmo/rekee",damage); break;
                case "sen": who->add("xinmo/resen",damage); break;
            }
         }
     }
     }
    return ::receive_wound(type, damage, who);
}

varargs int receive_damage(string type, int damage, object who)
{
    
      if(objectp(who)){
        if(userp(who)) {
           // can't use other's NPC to help kill.
        if(damage>0) {
            switch(type) {
                case "kee": who->add("xinmo/rekee",damage); break;
                case "sen": who->add("xinmo/resen",damage); break;
            }
        }
       }
     }
    return ::receive_damage(type, damage, who);
}
