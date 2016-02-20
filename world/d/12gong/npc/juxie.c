inherit NPC;
#include "star.h"
 
void create()
{
        set_name("阿提米斯", ({"adimis", "ju xie"}));
        set("long", "传说中的月亮女神－阿提米斯，守护着巨蟹座。\n");
        set("gender","女性");
        set("title", "【月亮神】");
        set("age",37);
        set("con",30);
        set("spi",40);
        set("per",30);
        set("str",25);
        set("int",35);
          set("combat_exp",1000000);
        set("daoxing",3000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "阿提米斯说道：不知何时能再见到雅典娜！\n"   
        }));
        set("attitude", "friendly");
        set_skill("dodge", 250);
        set_skill("force", 250);
        set_skill("parry", 250);
        set_skill("unarmed", 250);
        set_skill("sword", 250);
        set_skill("westsword",250);
        set_skill("boxing",250);
        set_skill("balei",250);
        set_skill("spells",250);
        set_skill("jinniu", 250);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","jinniu");
        map_skill("dodge","balei");
        set("max_force", 3000);
        set("force", 6000);
        set("max_mana",3000);
        set("mana",6000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 1200);
        set("max_gin", 1200);
        set("max_sen", 1200);

        setup();
        carry_object(__DIR__"obj/jx_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}
 
void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
        if( ! me ) return ;
   if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }                               
 if( me->is_ghost() )
     {
     remove_call_out("check");
     return;
     }

     switch(random(6))

     {        
        case 0:
        {
        message_vision(HIC"$N高举双手，$n的面前忽然出现了万丈波浪！\n",ob,me);

        if(random(3)==0)

                {
              message_vision(HIC"$N被波浪冲了个大踉镪，差点摔倒！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
                }
        else
        message_vision(HIC"$N一声轻笑，躲开了这万丈波浪。\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N眼望天空，一轮圆月忽然出现在$n的面前！\n",ob,me);

        if(random(3)==0)

                {
              message_vision(HIC"原来这一轮圆月竟锋利无比，$N的身上被划了一大血口！\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(HIC"$N躲避及时，圆月在地上嘣出了一道裂痕。\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIC"$N口念咒语，一只巨蟹从天而降，落在$n的面前。\n",ob,me);
                              
        if(random(3)==0)

                {
              message_vision(HIR"巨蟹伸出一双大铁钳，夹住了$N！\n"NOR,me);
              me->start_busy(1);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(HIR"$N定睛一看，原来是个幻象！\n"NOR,me,ob);
        }
        break;

  }
        if( random(8) == 5 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{

        object ob = query_temp("my_killer");

        if((ob&&ob->query("12gong/shuangzi")=="done") &&(ob&&ob->query("12gong/juxie")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第四宫巨蟹座，继续向黄金战士前进。\n"NOR,users());
        ob->set("12gong/juxie","done");
        ob->add("12gong/number",1);
        ob->add("daoxing", 10000);
        ob->add("kill/nkgain",10000);
        tell_object(ob,"你赢得了十年NK道行");

        }
       ::die();
}
