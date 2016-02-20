#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIR"火部神兵"NOR, ({"huo bing", "bing"}));
        set("gender", "男性" );
        set("age", 33);
        set("long", HIC"天宫火部大将，久精沙场，手下猛将如云。\n"NOR);
        set("class", "xian");
        set("combat_exp", 200000);
        set("daoxing", 1000000);

        set("attitude", "aggressive");
        set_skill("unarmed", 100);
        set_skill("yingzhaogong", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("spear", 100);
        set_skill("huoyun-qiang", 100);

        set_skill("spells", 100);
        set_skill("taiyi", 100);
        set_skill("moshenbu", 100);
        set_skill("force", 100);   
        set_skill("huomoforce", 100);
        map_skill("force", "huomoforce");
        map_skill("spear", "huoyun-qiang");
        map_skill("dodge", "moshenbu");
        map_skill("unarmed", "yingzhaogong");
        map_skill("spells", "taiyi");

        set("max_kee", 2000);
        set("max_sen", 2000);
        set("mana", 3500);
        set("max_mana", 3500);
        set("mana_factor", 50);
        set("force", 3000);
        set("max_force", 3000);
        set("force_factor", 50);


        setup();

        carry_object("/d/dntg/laojunlu/obj/jinjia")->wear();
        carry_object("/d/dntg/laojunlu/obj/hyq")->wield();
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  call_out ("penhuo",5+random(5),me,ob);  
  ::kill_ob(ob);
}

void penhuo (object me, object ob)
{
  object huobing;
  if (! me)
    return;

  if( !living(me) )
    return;

  if (! ob)


    return;

  if (environment(ob) != environment(me))
    return;

  huobing = new (__DIR__"huobing");
  huobing->move(environment (me));
  me->command("exert recover");
  message_vision (HIY"只见$N，"HIY"将手中的令旗一展，顿时四壁熊熊大火向$n卷来！\n"NOR,me,ob);
  message_vision (HIY"火焰中现出一只 $N\n"NOR,huobing);

  remove_call_out ("penhuo");  
  call_out ("penhuo",random(15)+15,me,ob);  
}
void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  ob->add_temp("dntg/laojunlu_day",2);
  message_vision ("$N"HIY"消失在火海之中......\n"NOR,me);
  destruct (this_object());
  return ;
}