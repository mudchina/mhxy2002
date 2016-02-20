inherit NPC;
#include <ansi.h>
 
void create()
{
        set_name("天魔", ({"tianmo", "arch devil"}));
        set("long", "你看见一个满身杀气的人，他看起来很不好惹。\n");
        set("gender","男性");
        set("title", "魔教镇教明王");
        set("age",37);
        set("con",40);
        set("spi",50);
        set("per",30);
        set("str",35);
        set("int",45);
        set("combat_exp",9000000);
//      set("daoxing",3000000);
        set("chat_chance",20);
        set("attitude", "friendly");
        set_skill("dodge", 350);
        set_skill("force", 350);
        set_skill("parry", 350);
        set_skill("unarmed", 350);
        set_skill("sword", 350);
        set_skill("tianxian-sword",350);
        set_skill("tianmo",350);
        set_skill("dimo-steps",350);
        set_skill("spells",350);
        set_skill("huolong-zhang", 350);
        map_skill("sword","tianxian-sword");
        map_skill("unarmed","huolong-zhang");
        map_skill("spells","tianmo");
        map_skill("dodge","dimo-steps");
        set("max_force", 6000);
        set("force", 9000);
        set("max_mana",8000);
        set("mana",16000);
        set("mana_factor",250);
        set("force_factor", 250);
        set("max_kee", 5500);
        set("max_gin", 5500);
        set("max_sen", 5500);

        setup();
        carry_object("/d/mojiao/obj/hands")->wear();
        carry_object("/d/obj/weapon/sword/qingfeng")->wield();
}
 
void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
        int mywx, obwx;
     mywx=me->query("combat_exp");
     obwx=ob->query("combat_exp");
     obwx=obwx * 8;

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
        message_vision(HIC"$N喃喃念了句咒语，突然从天上射下一到焦雷劈向了$n！\n",ob,me);

        if(obwx>random(mywx+obwx))      

                {
              message_vision(HIC"结果$n被砸了个正着！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
                }
        else
        message_vision(HIC"但是被$N躲开了。\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIR"$N大喝一声＂血染长空＂！\n",ob,me);

        if(obwx>random(mywx+obwx))      


                {
              message_vision(HIR"只见长空中一条血光一闪，$n已被一把巨大无比的魔刃砍了个半死。\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
                }
        else
        message_vision(HIW"但是被$n躲开了。\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIR"$N大喝一声＂饮血河山＂。\n",ob,me);
                              
        if(obwx>random(mywx+obwx))      


                {
              message_vision(HIR"$N手一挥，顿时半空血云密布，一阵骷髅像狂风暴雨般的砸向了$n！\n"NOR,me);
              me->start_busy(1);
              me->add("eff_kee",-2*query("max_kee")/15);
                }
        else
        message_vision(HIY"还没等$N咒语念完，$n就一掌打翻了$N！\n"NOR,me,ob);
        }
        break;

  }

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{
        object ob = query_temp("my_killer");        
        ob->start_busy(3);
        ob->set("mojiao/pk","done");
}
