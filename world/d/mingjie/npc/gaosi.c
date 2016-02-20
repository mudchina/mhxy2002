// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("艾雅高斯", ({"aiya gaosi", "gaosi"}));
        set("long", "天雄星的艾雅高斯，第五狱的看守。\n");
        set("gender","男性");
        set("title", "【天雄星】");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
          set("combat_exp",4000000);
        set("daoxing",4000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "艾雅高斯说道：“不遵守神的教诲的罪人，都将被我审判！\n"   
        }));
        set_skill("dodge", 350);
        set("attitude", "friendly");
        set_skill("force", 350);
        set_skill("parry", 350);
        set_skill("unarmed", 350);
        set_skill("sword", 350);
        set_skill("westsword",350);
        set_skill("balei",350);
        set_skill("spells",350);
        set_skill("shinu", 350);
        map_skill("sword","westsword");
        map_skill("spells","shinu");
        map_skill("dodge","balei");
        set("max_force", 4000);
        set("force", 8000);
        set("max_mana",4000);
        set("mana",8000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 4000);
        set("max_gin", 4000);
        set("max_sen", 4000);

        setup();
        carry_object(__DIR__"obj/tx_cloth")->wear();
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


     switch(random(6))
     {        
        case 0:
        {
        message_vision(HIG"$N高举双手，使出绝学：“神鹫襟翼”！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIG"$N被一阵狂风吹上了天空，又跌了下来！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
                }
        else
        message_vision(HIG"$N在风中旋转着，借助风的力量继续作战！\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N一挥手中令旗，无数秃鹫飞向$n！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIC"$N被秃鹫围住，啄了个体无完肤！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
                }
        else
        message_vision(HIC"$N发出一声大吼，把秃鹫吓跑了。\n"NOR,me);
        }
        break;
    }
        if( random(10) == 5 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}

void die()
{

        object ob = query_temp("my_killer");

        if((ob&&ob->query("mingjie/si")=="done") && (ob&&ob->query("mingjie/wu")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【冥界】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第五狱。\n"NOR,users());
        ob->set("mingjie/wu","done");
        ob->add("mingjie/number",1);
         ob->add("daoxing", 60000);
      ob->set("title",HIW"天雄星冥斗士"NOR);
           ob->save();
         tell_object(ob,"你赢得了六十年道行");

        }
       ::die();
}

void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","ji");

}
int do_none()
{
        object me = this_object();
        message_vision("$N冷笑一声：这里是我的管区，我说了算！！！\n",me);
        return 1;
} 
