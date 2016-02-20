//  妖神之争 １。０


inherit NPC;
#include <ansi.h>

void create()
{
   set_name("犀牛精", ({ "xiniu jing","jing" }) );
   set("race", "野兽");
   set("age", 1000);
   set("long", "他就是天上逃跑来的犀牛精。\n");
   set("str", 50);
   set("max_kee",6000);
   set("kee",6000);
   set("mana",6000);
   set("max_mana",6000);
   set("max_force",6000);
   set("force",6000);
   set("dex", 36);

   set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
   set("verbs", ({ "bite", "claw" }) );
   set_skill("unarmed",300);
   set_skill("dodge",300);
   set_skill("force",300);
   set_skill("parry",300);
   set("attitude","aggressive");
   set("combat_exp",6000000);
   set_temp("apply/attack", 200);
   set_temp("apply/armor", 100);
   setup();
}

void die()
{
        object ob = this_object();
        message_vision(HIC"只见$N卧倒在地!  好，你也可以回去了。\n"NOR,ob);
        ob->set_name("坐骑",({"zuo qi","jing"}));
        ::die();
}
