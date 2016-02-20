// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("吉多", ({"ji duo", "duo"}));
        set("long", "冥界三巨头之--天媚星吉多。\n");
        set("gender","女性");
        set("title", "【天媚星】");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
          set("combat_exp",4800000);
        set("daoxing",4800000);
        set("chat_chance",20);
        set("chat_msg", ({
                "吉多而自豪的说道：“我就是冥界三巨头之--天媚星吉多！\n"   
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
        set("force", 9200);
        set("max_mana",4800);
        set("mana",9200);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 4800);
        set("max_gin", 4800);
        set("max_sen", 4800);

        setup();
        carry_object(__DIR__"obj/tmm_cloth")->wear();
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
        message_vision(YEL"$N使出绝招：“大斧粉碎”！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(YEL"$N被砍中一斧！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*18);
       
                }
        else
        message_vision(YEL"$N飞了起来，斧头根本砍不到！\n"NOR,me);
        }
        break;


                case 1:
        {
        message_vision(HIR"$N使出绝招：“永恒的诱惑”！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIR"$N被迷的丢了魂！\n"NOR,me);
              
              me->add("eff_sen",-query("max_sen")/100*18);

                }
        else
        message_vision(HIR"$N轻蔑的笑了笑，拿出一张照片，说：“我有女朋友”！\n"NOR,me);
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

        if((ob&&ob->query("mingjie/tu2")=="done") && (ob&&ob->query("mingjie/tu3")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【冥界】雅典娜(Ya dian na):"+ob->name()+
        "打败了冥界三巨头之--天媚星吉多。\n"NOR,users());
        ob->set("mingjie/tu3","done");
        ob->add("mingjie/number",1);
         ob->add("daoxing", 110000);
      ob->set("title",HIW"天媚星冥斗士"NOR);
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
