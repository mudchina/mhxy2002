//By tianlin@mhxy for 2001.9.25
//部分优化

#include <ansi.h>;
inherit NPC;

void create()
{
        set_name(HIY"老虎"NOR, ({ "laohu", "tiger","hu" }) );
        set("race", "野兽");
        set("age", 20);
        set("long", @LONG
一只斑斓猛虎，雄伟极了。

         _.-'"''--..__.("\-''-'")
 ('.__.-' (  *  ) .-'    ( @ _@'
  `-..-''.' _.'  (   _.  `(._Y_)
         `. `._`--\  \_-.._`--'.._
          `-.!))  `.(il)   ''-.(li)



LONG);
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("limbs", ({ "虎头", "虎身", "前爪", "后抓", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 30000);
        set("force",800);
        set("force_factor", 100);
        set("max_force",800);
        set("mana",500);
        set("max_mana",500);

       // set_temp("apply/attack", 20000);
       // set_temp("apply/defense", 30000);
       // set_temp("apply/armor", 1000);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "老虎在浚巡，吓得你大气都不敢出。\n",
                "老虎仰天长啸，声震山谷，黄叶纷坠。\n",
        }) );
}

