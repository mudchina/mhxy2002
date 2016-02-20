//by LitChi /6/19/2001 
#include <ansi.h>
inherit NPC;

#include "biaotou.h"

void create()
{
        set_name(HIR"镖头"NOR, ({ "biao tou" }));
        set("long", "他原是峨嵋派弟子，后来做了镖头。");
        set("age", random(20) + 20);
        set("str", 26);
        set("int", 28);
        set("con", 26);
        set("dex", 26);

        set("max_sen", 200);
        set("max_kee", 600);
        set("force", 500);
        set("max_force", 400);
        set("force_factor", 20);
        set("combat_exp", 80000);
        set("daoxing", 500000);

        set_skill("spear", 100);
        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("yanxing-steps", 100);
        set_skill("bawang-qiang", 100);
        set_skill("lengquan-force", 100);
        set_skill("unarmed", 100);
        set_skill("changquan", 100);
        map_skill("force", "lengquan-force");
        map_skill("unarmed", "changquan");
        map_skill("spear", "bawang-qiang");
        map_skill("parry", "bawang-qiang");
        map_skill("dodge", "yanxing-steps");
        
        setup(); 
        add_money("gold", 2);        
  carry_object("/d/obj/armor/tenjia")->wear();
  carry_object("/d/obj/weapon/spear/tieqiang")->wield();
      }

void unconcious()
{
   command("die");
   destruct(this_object());
}

void die()
{
   command("die");
   destruct(this_object());
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        message("vision","\n" 
                + name() + "一路小跑，寻镖车而去。。。\n\n" NOR, environment(),
                this_object() );
        destruct(this_object());
}
