inherit NPC;
#include "star.h"
 
void create()
{
        set_name("可洛诺斯", ({"kelowooz", "mo jie"}));
        set("long", "传说中的作物之神，守护着摩羯座.\n");
        set("gender","男性");
        set("title", "【作物之神】");
        set("attitude", "friendly");
        set("age",37);
        set("con",45);
        set("per",30);
        set("str",63);
        set("int",64);
        set("combat_exp",1000000);
        set("daoxing",3000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "可洛诺斯说道：不知何时能再见到雅典娜！\n"   
        }));
        set_skill("dodge", 250);
        set("attitude", "friendly");
        set_skill("force", 250);
        set_skill("parry", 250);
        set_skill("unarmed", 250);
        set_skill("sword", 250);
        set_skill("westsword",250);
        set_skill("boxing",250);
        set_skill("balei",250);
        set_skill("spells",250);
        set_skill("renma", 250);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","renma");
        map_skill("dodge","balei");
        set("max_force",4000);
        set("force", 8000);
        set("max_mana",4000);
        set("mana",8000);
        set("mana_factor",50);
        set("force_factor", 50);
        set("max_kee", 2000);
        set("max_gin", 2000);
        set("max_sen", 2000);

        setup();
        carry_object(__DIR__"obj/mj_cloth")->wear();
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
        message_vision("$N冷笑一声：我乃$N，你想耍什么花样？\n",me);
        return 1;
} 
void check()
{
        object ob=this_object();
        object ghost;
        object me2=new("/d/12gong/npc/mojie2.c");
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
        message_vision(HIY"$N跪在地上，大地剧烈的震撼着！\n",ob);

        if(random(3)==0)
                {
              message_vision(HIY"$N被震的东倒西歪，失去了平衡！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
                }
        else
        message_vision(HIW"$N站稳脚跟，和$n继续搏斗着。\n"NOR,me,ob);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N摆出射箭的姿势，一条鲨鱼向$n急速飞来！\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIM"$N一个不小心，被挲鱼咬了个血窟窿！\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(HIG"$N轻身跃起，鲨鱼从$N的身下飞过。\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIW"$N摇身一变，分出另外一个自己来！\n",ob);
//        if( present("kelowooz two",environment()));
  //      return;
        me2->move(environment());
        me2->kill_ob(me);
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

        if((ob&&ob->query("12gong/renma")=="done") && (ob&&ob->query("12gong/mojie")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第十宫摩羯座，继续向黄金战士努力！\n"NOR,users());
        ob->set("12gong/mojie","done");
        ob->add("12gong/number",1);
        ob->add("daoxing", 10000);
        ob->add("kill/nkgain",10000);
        tell_object(ob,"你赢得了十年NK道行");

        }
       ::die();
}
