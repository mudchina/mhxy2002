
#include <ansi.h>
inherit NPC;

void create()
{
        object ob;

        set_name(HIC"魔礼青"NOR, ({ "tian wang", "zengzhang tianwang", "qing", "tianwang" }) );
        set("gender", "男性" );
        set("long",HIC
                "增长天王为四大天王之首, 身高二丈四尺, 善用一杆长枪, \n"
                "枪法登峰造极, 更有密传「青云宝剑」, 「地，水，火，风」\n"
                "四式一出, 大罗金仙也难逃。\n"NOR);

        set("age",50);
	 set("nickname", HIW"增长天王"NOR);
	 set("title", HIG"四大天王"NOR);
        set("attitude", "heroism");
        set("str",40);
        set("int",30);
        set("max_kee",3100);
        set("kee",3100);
        set("max_sen",3100);
        set("sen",3100);
        set("combat_exp",4000000);
        set("daoxing",3500000);
        set("force",6000);
        set("max_force",3000);
        set("mana",6000);
        set("max_mana",3000);
        set("force_factor", 150);
        set("mana_factor",150);

        set("eff_dx", 4500000);
        set("nkgain", 1500);

        set_skill("unarmed",180);
        set_skill("yingzhaogong", 180);
        set_skill("parry",180);
        set_skill("dodge",180);
        set_skill("sword",180);
        set_skill("ningxie-force",180);
        set_skill("bainiao-jian",180);
        set_skill("force",180);
        set_skill("spells", 180);

        set_skill("moshenbu", 180);
        map_skill("dodge", "moshenbu");
        map_skill("force", "ningxie-force");
        map_skill("parry", "bainiao-jian");
        map_skill("sword","bainiao-jian");
        map_skill("unarmed", "yingzhaogong");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword", "chaofeng" :),
        }) );

        setup();

        ob=carry_object("/d/dntg/laojunlu/obj/qingfeng");
        ob->wield();
        ob->set_name(HIC"青云宝剑"NOR, ({ "sword", "bao jian" }) );

        carry_object("/d/dntg/laojunlu/obj/jinjia")->wear();
}





void die ()
{
  object me = this_object();
  message_vision ("$N"HIY"吓得撒腿就跑......\n"NOR,me);
  destruct (this_object());
  return ;
}