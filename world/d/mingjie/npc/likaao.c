// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("力卡奥", ({"lika ao", "ao"}));
        set("long", "天罪星力卡奥 第四狱，黑暗沼泽的看守。\n");
        set("gender","男性");
        set("title", "【天罪星】");
        set("age",37);
        set("con",40);
        set("spi",50);
        set("per",30);
        set("str",35);
        set("int",45);
            set("combat_exp",3900000);
        set("daoxing",3900000);
        set("chat_chance",20);
        set("chat_msg", ({
                "力卡奥说道：这里只有坐鬼筏才能通过！\n"   
        }));
        set("attitude", "friendly");
        set_skill("dodge", 350);
        set_skill("force", 350);
        set_skill("parry", 350);
        set_skill("unarmed", 350);
        set_skill("sword", 350);
        set_skill("westsword",350);
          set_skill("balei",350);
        set_skill("spells",350);
        set_skill("jinniu", 350);
        map_skill("sword","westsword");
        map_skill("spells","jinniu");
        map_skill("dodge","balei");
        set("max_force", 3900);
        set("force", 7800);
        set("max_mana",3900);
        set("mana",7800);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 3900);
        set("max_gin", 3900);
        set("max_sen", 3900);

        setup();
        carry_object(__DIR__"obj/tz_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}
 
void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
        if( ! me ) return ;

 if( me->is_ghost() )
     {
     remove_call_out("check");
     return;
     }
if(!present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }
     switch(random(6))
     {        
        case 0:
        {
        message_vision(HIC"$N突然把鬼筏弄没了！\n",ob,me);

        if(random(3)==0)
                {
              message_vision(HIC"$N被气的半死！\n"NOR,me);
              me->add("eff_sen",-query("max_sen")/100*14);
              

                }
        else
        message_vision(HIC"$N定睛一看，原来是幻觉。\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N使出绝学：“震鸣地狱”！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIC"$N被震的耳朵都聋了。\n"NOR,me);
              me->add("eff_kee",-query("max_sen")/100*14);
          

                }
        else
        message_vision(HIC"$N捂住耳朵，什么也没听见。\n"NOR,me);
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

        if((ob&&ob->query("mingjie/san")=="done") && (ob&&ob->query("mingjie/si")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【冥界】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第四狱。\n"NOR,users());
        ob->set("mingjie/si","done");
        ob->add("mingjie/number",1);
       ob->add("daoxing", 50000);
       tell_object(ob,"你赢得了五十年道行");
       ob->set("title",HIW"天罪星冥斗士"NOR);
         ob->save();

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

