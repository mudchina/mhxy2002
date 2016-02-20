// by happ@YSZZ
 
inherit NPC;
#include "star.h"
#include <ansi.h>;
 
void create()
{
        set_name("路尼", ({"lu ni", "ni"}));
        set("long", "冥界法庭的代庭长\n");
        set("gender","男性");
          set("title", HIY"【天英星】"NOR);
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
          set("combat_exp",3600000);
          set("daoxing",3600000);
        set("chat_chance",20);
        set("chat_msg", ({
                "路尼说道：“肃静，这里是法庭”！\n"   
        }));
        set_skill("dodge", 350);
        set("attitude", "friendly");
        set_skill("force", 350);
        set_skill("parry", 350);
        set_skill("unarmed", 350);
        set_skill("westsword",350);
        set_skill("balei",350);
        set_skill("spells",350);
        set_skill("jinniu", 350);
        map_skill("sword","westsword");
        map_skill("spells","jinniu");
        map_skill("dodge","balei");
        set("max_force", 3600);
        set("force", 7200);
        set("max_mana",3600);
        set("mana",7200);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 3600);
        set("max_gin", 3600);
        set("max_sen", 3600);

        setup();
        carry_object(__DIR__"obj/ty_cloth")->wear();
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

     switch(random(8))
     {        
        case 0:
        {
        message_vision(YEL"$N手持巴比隆之鞭，使出绝技：“火焰绞绳”！\n",ob,me);


       if(random(4)==0)
                {
              message_vision(YEL"$N被巴比隆之鞭，绞了个正着，顿时伤痕累累！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*11);
              me->add("eff_sen",-query("max_sen")/10*11);
                }
        else
        message_vision(YEL"$N看见他拿出巴比隆之鞭，飞一般的跑了，巴比隆之鞭根本就打不中！\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(YEL"$N念念有词，你被$N送到了火焰地狱受苦！\n",ob,me);

                if(random(4)==0)

                {
              message_vision(YEL"$N快被烧化了！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*11);
              me->add("eff_sen",-query("max_sen")/100*11);
                }
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

        if((ob&&ob->query("mingjie/river")=="done") && (ob&&ob->query("mingjie/yi")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【冥界】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第一狱!\n"NOR,users());
        ob->set("mingjie/yi","done");
        ob->add("mingjie/number",1);
          ob->add("daoxing", 20000);
      ob->set("title",HIW"天英星冥斗士"NOR);
        ob->save();
          tell_object(ob,"你赢得了二十年道行");

        }
       ::die();
      }
