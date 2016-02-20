// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("美路斯", ({"meilu si", "si"}));
        set("long", "冥界三巨头之--天捷星美路斯。\n");
        set("gender","男性");
        set("title", "【天捷星】");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
          set("combat_exp",4800000);
        set("daoxing",4800000);
        set("chat_chance",20);
        set("chat_msg", ({
                "美路斯而自豪的说道：“我就是冥界三巨头之--天捷星美路斯！\n"   
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
        set("max_force", 4800);
        set("force", 9600);
        set("max_mana",4800);
        set("mana",9600);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 4800);
        set("max_gin", 4800);
        set("max_sen", 4800);

        setup();
        carry_object(__DIR__"obj/tjxx_cloth")->wear();
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
        message_vision(HIR"$N使出绝招：“红莲花切刀”！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIR"$N被砍中了，身上有无数的刀痕！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*17);
              me->add("eff_sen",-query("max_sen")/100*17);

                }
        else
        message_vision(HIR"$N拿出一个盾牌，轻蔑的笑了笑！\n"NOR,me);
        }
        break;


                case 1:
        {
        message_vision(HIR"$N使出绝招：“红莲花切刀”！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIR"$N被砍中了，身上有无数的刀痕！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*17);
              me->add("eff_sen",-query("max_sen")/100*17);

                }
        else
        message_vision(HIR"$N拿出一个盾牌，轻蔑的笑了笑！\n"NOR,me);
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

        if((ob&&ob->query("mingjie/tu1")=="done") && (ob&&ob->query("mingjie/tu2")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【冥界】雅典娜(Ya dian na):"+ob->name()+
        "打败了冥界三巨头之--天捷星美路斯。\n"NOR,users());
        ob->set("mingjie/tu2","done");
        ob->add("mingjie/number",1);
         ob->add("daoxing", 110000);
      ob->set("title",HIW"天捷星冥斗士"NOR);
           ob->save();
         tell_object(ob,"你赢得了一百一十年道行");

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
