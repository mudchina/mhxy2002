#include <ansi.h>

inherit NPC;

string *names = ({
  HIR"火"HIW"龙"NOR,
  HIR"火"HIY"马"NOR,
  HIR"火"HIG"鸦"NOR,
  HIR"火"HIB"鼠"NOR,
});


void create()
{
        set_name(names[random(sizeof(names))], ({"huo bing", "bing"}));
        set("gender", "男性" );
        set("age", 33);
        set("long", HIC"天宫火部战将，久精沙场。\n"NOR);
        set("class", "xian");
        set("combat_exp", 500000);
        set("daoxing", 3500000);

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

        set("max_kee", 3000);
        set("max_sen", 3000);
        set("mana", 4000);
        set("max_mana", 4000);
        set("mana_factor", 50);
        set("force", 4000);
         set("max_force", 3000);
        set("force_factor", 50);


        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
          (: cast_spell, "zhenhuo" :),
           }) );

        setup();
        carry_object("/d/dntg/laojunlu/obj/jinjia")->wear();
        carry_object("/d/dntg/laojunlu/obj/hyq")->wield();
}

void kill_ob (object ob)
{
  object me = this_object();
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}


void die ()
{



  object me = this_object();
  object ob = query_temp("my_killer");
  ob->add_temp("dntg/laojunlu_day",1);
  message_vision ("$N"HIY"消失在火光之中......\n"NOR,me);
  destruct (this_object());
  return ;
}