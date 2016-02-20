// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("迪多利比杜而", ({"di duo", "duo"}));
        set("long", "天丑星的迪多利比杜而，第八狱的看守。\n");
        set("gender","男性");
        set("title", "【天丑星】");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
          set("combat_exp",4500000);
        set("daoxing",4500000);
        set("chat_chance",20);
        set("chat_msg", ({
                "迪多利比杜而说道：“这里是圣斗士的坟墓！\n"   
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
        set("max_force", 4500);
        set("force", 9000);
        set("max_mana",4500);
        set("mana",9000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 4500);
        set("max_gin", 4500);
        set("max_sen", 4500);

        setup();
        carry_object(__DIR__"obj/tc_cloth")->wear();
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
        message_vision(RED"$N高举双手，使出绝学：“真实的欲望”！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(RED"$N心中一阵迷乱！\n"NOR,me);
              me->add("eff_sen",-query("max_sen")/100*15);
                }
        else
        message_vision(RED"$N赶紧放松心情，躲过了这一劫！\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIW"$N把咒语一念，说道：“寒冰地狱”！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIW"$N被埋在冰中！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
                }
        else
        message_vision(HIW"$N飞向天空，冰没埋到$N。\n"NOR,me);
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

        if((ob&&ob->query("mingjie/qi")=="done") && (ob&&ob->query("mingjie/ba1")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【冥界】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第八狱。\n"NOR,users());
        ob->set("mingjie/ba1","done");
        ob->add("mingjie/number",1);
         ob->add("daoxing", 100000);
      ob->set("title",HIW"天丑星冥斗士"NOR);
           ob->save();
         tell_object(ob,"你赢得了一百年道行");

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
