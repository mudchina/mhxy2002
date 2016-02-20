// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("米诺陶而", ({"miluo taoer", "miluo"}));
        set("long", "天牢星的米诺陶而，第七狱的看守。\n");
        set("gender","男性");
        set("title", "【天牢星】");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
          set("combat_exp",4200000);
        set("daoxing",4200000);
        set("chat_chance",20);
        set("chat_msg", ({
                "米诺陶而自豪的说道：“冥界十壕，就是我管的！\n"   
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
        set("max_force", 4200);
        set("force", 8400);
        set("max_mana",4200);
        set("mana",8400);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 3500);
        set("max_gin", 3500);
        set("max_sen", 3500);

        setup();
        carry_object(__DIR__"obj/tn_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}
 
void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","ji");
//        add_action("do_none","exert");

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


     switch(random(9))
     {        
        case 0:
        {
        message_vision(HIG"$N说：“你去第一壕把”！\n",ob,me);

                if(random(1)==0)

                {
              message_vision(HIG"$N被一阵狂风吹到第一壕！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
              me->move("/d/mingjie/qi");

                }
        else
        message_vision(HIG"$N在风中旋转着，借助风的力量继续作战！\n"NOR,me);
        }
        break;

  case 1:
        {
        message_vision(HIG"$N说：“你去第二壕把”！\n",ob,me);

                if(random(1)==0)

                {
              message_vision(HIG"$N被一阵狂风吹到第二壕！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
              me->move("/d/mingjie/qi1");

                }
        else
        message_vision(HIG"$N在风中旋转着，借助风的力量继续作战！\n"NOR,me);
        }
        break;
  case 2:
        {
        message_vision(HIG"$N说：“你去第三壕把”！\n",ob,me);

                if(random(1)==0)

                {
              message_vision(HIG"$N被一阵狂风吹到第三壕！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
              me->move("/d/mingjie/qi2");

                }
        else
        message_vision(HIG"$N在风中旋转着，借助风的力量继续作战！\n"NOR,me);
        }
        break;
       case 3:
        {

        message_vision(HIC"$N说道：“你去第四壕把”！\n",ob,me);

                if(random(1)==0)

                {
              message_vision(HIC"$N被一道光带走了！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
              me->move("/d/mingjie/qi3");
                
}
        else
        message_vision(HIC"$N拿出镜子，把光挡住了。\n"NOR,me);
        }
        break;
case 4:
        {

        message_vision(HIC"$N说道：“你去第五壕把”！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIC"$N被一道光带走了！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
              me->move("/d/mingjie/qi4");
                
}
        else
        message_vision(HIC"$N拿出镜子，把光挡住了。\n"NOR,me);
        }
        break;
case 5:
        {

        message_vision(HIC"$N说道：“你去第六壕把”！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIC"$N被一道光带走了！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
              me->move("/d/mingjie/qi5");
                
}
        else
        message_vision(HIC"$N拿出镜子，把光挡住了。\n"NOR,me);
        }
        break;
 case 6:
        {

        message_vision(HIC"$N说道：“你去第七壕把”n！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIC"$N的身影被影子抓走了！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
              me->move("/d/mingjie/qi6");

                }
        else
        message_vision(HIC"$N理都不理，一巴掌打的影子又缩了回去。\n"NOR,me);
        }
        break;
 case 7:
        {

        message_vision(HIC"$N说道：“你去第八壕把”n！\n",ob,me);

                if(random(1)==0)

                {
              message_vision(HIC"$N的身影被影子抓走了！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
              me->move("/d/mingjie/qi7");

                }
        else
        message_vision(HIC"$N理都不理，一巴掌打的影子又缩了回去。\n"NOR,me);
        }
        break;
 case 8:
        {

        message_vision(HIC"$N说道：“你去第九壕把”n！\n",ob,me);

                if(random(1)==0)

                {
              message_vision(HIC"$N的身影被影子抓走了！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/100*15);
              me->move("/d/mingjie/qi8");

                }
        else
        message_vision(HIC"$N理都不理，一巴掌打的影子又缩了回去。\n"NOR,me);
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

        if((ob&&ob->query("mingjie/liu2")=="done") && (ob&&ob->query("mingjie/qi")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【冥界】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第七狱。\n"NOR,users());
        ob->set("mingjie/qi","done");
        ob->add("mingjie/number",1);
         ob->add("daoxing", 80000);
      ob->set("title",HIW"天牢星冥斗士"NOR);
           ob->save();
         tell_object(ob,"你赢得了八十年道行");

        }
       ::die();
}

