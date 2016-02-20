
#include <ansi.h>
inherit NPC;
 
void create()
{
        set_name(HIY"魔礼寿"NOR, ({ "tian wang", "chiguo tianwang", "shou", "tianwang", "wang" }) );
        set("gender", "男性" );
        set("long",HIC"
四大天王之一，身担着保护后宫安全的重担，非同小可。他
的武功似乎属佛门一派，护国天王还有另外的杀手绝招，但
没有人知道是什么。也许正因为如此，玉皇才放心让他独担
重任。\n"NOR);
        set("class", "xian");
	 set("nickname", HIW"持国天王"NOR);
	 set("title", HIG"四大天王"NOR);
        set("age",43);
        set("str",30);
        set("int",37);
        set("max_kee",3100);
        set("kee",3100);
        set("max_sen",3100);
        set("sen",3100);
        set("combat_exp",4000000);
        set("daoxing",3500000);
        set("force",5000);
        set("max_force",3000);
        set("mana",5000);
        set("max_mana",3000);
        set("force_factor", 120);
        set("mana_factor",120);

        set("eff_dx", 4500000);
        set("nkgain", 1500);

        set_skill("unarmed",140);
        set_skill("changquan", 180);
        set_skill("parry",180);
        set_skill("dodge",180);
        set_skill("mace",180);
        set_skill("spells", 180);
        set_skill("wusi-mace",180);
        set_skill("force",180);
        set_skill("moshenbu", 180);

        map_skill("dodge", "moshenbu");
        map_skill("mace","wusi-mace");
        map_skill("parry","lunhui-zhang");
        map_skill("unarmed", "changquan");
        set("inquiry", ([
                "name" : "在下就是持国天王，奉圣谕把守北天门。",
                "here" : "这里就是北天门，里面是后宫禁地。",
        ]) );
        setup();
        carry_object("/d/dntg/laojunlu/obj/goldjian")->wield();
        carry_object("/d/dntg/laojunlu/obj/jinjia")->wear();
}


void kill_ob (object ob)
{
  object me = this_object();

  call_out ("huahudiao",5+random(5),me,ob);  
  ::kill_ob(ob);
}




void huahudiao (object me, object ob)
{
  object huobing;
  int damage;

  if (! me)
    return;

  if( !living(me) )
    return;

  if (! ob)
    return;

  if (environment(ob) != environment(me))
    return;

  message_vision ("$N"HIC"从囊中取出"HIR"花"HIB"狐"HIM"貂 "HIC"祭在空中，化作一只"HIW"白象"
       HIR+"口似血盆，牙如利刀，向$n咬来！\n"NOR,me,ob);

  if ( (ob->query("force")+random(1000)) > 4000 )


     message_vision (HIY"$N大喝一声：大胆！\n"
       +HIR"花"HIB"狐"HIM"貂"HIY" 吓的连忙钻回$n"HIY"的囊中。\n"NOR,ob,me);
  else 
    {
     message_vision (HIR"结果$N被咬出一条血肉模糊的口子！\n"NOR,ob,me);
     damage=(me->query("force"))/5; 
     if ( ob->query("kee") < damage ) ob->unconcious();
     else ob->add("kee",-damage);
    } 

  remove_call_out ("huahudiao");  
  call_out ("huahudiao",random(15)+15,me,ob);  
}


void die ()
{
  object me = this_object();
  message_vision ("$N"HIY"吓得撒腿就跑......\n"NOR,me);
  destruct (this_object());
  return ;
}