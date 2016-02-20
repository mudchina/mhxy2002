// 新冬值功曹                                                                 
//created 4-8-97 pickle                                                     
inherit NPC;
#include <ansi.h>
#include "zzzjob.c"
#include "teamjob.c"
string ask_newjob();
string ask_newover();
int job_over(string arg);
                                                            
                                                                            
void create()                                                               
{                                                                           
        set_name("时值功曹", ({ "shizhi gongcao", "shi", "hour",            
"gongcao" }) );                                                             
        set("gender", "男性" );                                             
        set("long","                                                        
四值功曹乃是托塔李天王帐前猛将。因经验不足而                                
出战失利，被罚为巡逻官。四人因志同道合而结为                                
金兰兄弟。时值功曹排行老么，身份最是神秘。他                                
功夫在众兄弟中最高，但最缺乏经验。\n"                                       
        );                                                                  
        set("age",35);                                                      
        set("str",25);                                                      
        set("int",25);                                                      
        set("max_kee",1000);                                                
        set("kee",1000);                                                    
        set("max_sen",1000);                                                
        set("sen",1000);                                                    
        set("daoxing",1490000);                                              
        set("combat_exp",1490000);                                           
        set("force",2000);                                                  
        set("max_force",2800);                                               
        set("mana",2500);                                                   
        set("max_mana",2000);                                                
        set("force_factor", 150);                                            
        set("mana_factor", 150);                                             
                                                                            
//        set("eff_dx", 200000);                                              
//        set("nkgain", 300);                                                 
                                                                            
        set_skill("unarmed",300);                                           
        set_skill("parry",300);                                             
        set_skill("dodge",300);                                             
        set_skill("spear",300);                                             
        set_skill("bawang-qiang",300);                                      
        set_skill("moshenbu", 300);                                         
        set_skill("force",300);                                             
        set_skill("spells", 300);                                           
        set_skill("dragonfight",300);                                        
        map_skill("unarmed", "dragonfight");                                
        map_skill("dodge", "moshenbu");                                     
        map_skill("spear", "bawang-qiang");                                 
        map_skill("parry","bawang-qiang");                                  
        set("inquiry", ([                                                   
                "name" : "在下就是时值功曹，乃托塔天王帐前大将。",          
                "here" : "这里就是天宫。下官奉天王将令，在此巡查。",        
                       "job"   : (: ask_job :),
         "功劳"  : (: ask_gonglao :),
         "fangqi": (: ask_fangqi :),
         "放弃"  : (: ask_fangqi :),
                 "奸细"  : (: ask_jianxi :),
                "守宫" : (: ask_newjob :),
                "job2"  : (: ask_newjob :),
                "撤退"  : (: ask_newover :),
                ]));
 
               
 setup();
        carry_object("/d/obj/weapon/spear/biyuqiang")->wield();
        carry_object("/d/obj/armor/yinjia")->wear();
}

void init()
{
        add_action("job_over","task");
}

string ask_newjob()
{
        object *ene;
        object me = this_player();

        if(is_fighting()) 
        {
                ene=query_enemy();
                
                if(sizeof(ene)>1) return "“请"+RANK_D->query_respect(me)+"稍等片刻，我先和这"+sizeof(ene)+"位高手切磋几下！”\n";
                if(sizeof(ene)==1) return "“请"+RANK_D->query_respect(me)+"稍等片刻，我先和"+ene[0]->name()+"切磋几下！”\n";
        }

        if(me->query_temp("mark/job_shadi")>0 ) return "“"+RANK_D->query_respect(me)+"不是已有任务了吗！”\n";

/*        if((int)me->query("shen") < 0) return "“"+RANK_D->query_respect(me)+"心术不正，我们不欢迎！”\n";
*/     
        if ((int)me->query("combat_exp")<100000) return "“"+RANK_D->query_respect(me)+"手无缚鸡之力，还是别领任务的为好！”\n";

    if ( (int)me->query_skill("force") < 80 )
       return "守天宫是件危险工作，我看"+RANK_D->query_respect(me)+"的基本内力不足！\n";

      if ((int)me->query_condition("jobshadi_failed"))
{
     message_vision("$N对着$n摇了摇头说：逃跑失败了还来见我??\n", this_object(), me);
return "“"+RANK_D->query_respect(me)+"你还是别领任务的为好！”\n";
//return;
}

      if ((int)me->query_condition("jobshadi_limit")>1)
{
     message_vision("$N对着$n摇了摇头说：你不是正做着吗??\n", this_object(), me);
return "“"+RANK_D->query_respect(me)+"你快点回你的老家去！”\n";
//return;
}
   if ((int)me->query_condition("guojob2_busy"))
{
     message_vision("$N对着$n摇了摇头说：现在魔界妖神正在攻天界天宫！！\n", this_object(), me);
return "“"+RANK_D->query_respect(me)+"你等会再来！”\n";
//return;
}
        if (me->query("force")>0)
        {
        switch( random(2) ) {
                case 0:
                        me->set_temp("mark/job_shadi",1);
                        me->set_temp("carry_location","northgate1");            
                me->apply_condition("guojob2_busy",4);
                return "“现在魔界妖神侵犯天界天宫，这位"+RANK_D->query_respect(me)+"去难南天门帮助天界天宫吧。";

                       break;
                case 1:
                        me->set_temp("mark/job_shadi",2);
                        me->set_temp("carry_location","northgate1");            
                me->apply_condition("guojob2_busy",4);
                return "“现在魔界妖神侵犯天界天宫，这位"+RANK_D->query_respect(me)+"去东天门帮助天界天宫吧。";

                       break;
                }       
        }
        else
        {
        switch( random(2) ) {
                case 0:
                        me->set_temp("mark/job_shadi",3);
                        me->set_temp("carry_location","southgate1");
                me->apply_condition("guojob2_busy",4);
                return "“现在魔界妖神侵犯天界天宫，这位"+RANK_D->query_respect(me)+"去北天门帮助天界天宫吧。";

                       break;
                case 1:
                        me->set_temp("mark/job_shadi",4);
                        me->set_temp("carry_location","southgate1");
                me->apply_condition("guojob2_busy",4);
                return "“现在魔界妖神侵犯天界天宫，这位"+RANK_D->query_respect(me)+"去西天门帮助天界天宫吧。";

                       break;
                }
        }
}

int job_over(string arg)
{
        int job_pot,job_exp;
        object me = this_player();

        if(!arg) return 1;

        if(arg!="over") return 1;
        if(me->query_temp("help_killed")>0)
        {
                message_vision(CYN "$N拍了拍$n的肩膀说道：“"+RANK_D->query_respect(me)+"，为天界天宫杀魔，不错不错！”\n" NOR, this_object(), me);
                job_exp=((int)me->query_temp("killed_mgb"))*80;
                  job_pot=job_exp*2/3;
                  job_exp=job_exp;


