// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("阿路里", ({"alu li", "li"}));
        set("long", "天魔星的阿路里，第六狱的看守。\n");
        set("gender","男性");
        set("title", "【天魔星】");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
          set("combat_exp",4100000);
        set("daoxing",4100000);
        set("chat_chance",20);
        set("chat_msg", ({
                "阿路里说道：“这里是第六狱，想过么？打倒我把！\n"   
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
        set("max_force", 4100);
        set("force", 8200);
        set("max_mana",4100);
        set("mana",8200);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 4100);
        set("max_gin", 4100);
        set("max_sen", 4100);

        setup();
        carry_object(__DIR__"obj/tm_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
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
        message_vision(HIG"$N不顾一切使出：天魔解体！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIG"$N被打了个冷不防！\n"NOR,me);
              message_vision(HIG"$N被打退了！\n"NOR,me);

              me->add("eff_kee",-query("max_kee")/100*15);
              me->move("/d/mingjie/liu");

                }
        else
        message_vision(HIG"$N被吓了一跳，但还是躲了过去！\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N一挥手中令旗，一股毒烟吹向$n！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIC"$N被熏的差点昏了过去！\n"NOR,me);
              message_vision(HIC"$N被毒烟带走了！\n"NOR,me);

              me->add("eff_sen",-query("max_sen")/100*15);
              me->move("/d/mingjie/liu1");

                }
        else
        message_vision(HIC"$N张嘴一吹，把烟吹散了。\n"NOR,me);
        }
        break;
    }
        if( random(10) == 3 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}

void die()
{

        object ob = query_temp("my_killer");

        if((ob&&ob->query("mingjie/wu")=="done") && (ob&&ob->query("mingjie/liu2")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【冥界】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第六狱。\n"NOR,users());
        ob->set("mingjie/liu2","done");
        ob->add("mingjie/number",1);
         ob->add("daoxing", 70000);
      ob->set("title",HIW"天魔星冥斗士"NOR);
           ob->save();
         tell_object(ob,"你赢得了七十年道行");

        }
       ::die();
}

