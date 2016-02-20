inherit NPC;
#include <ansi.h>
int big_blowing();
void create()
{
 set_name("鬼王", ({ "gui wang", "gui" }) );
 set("gender", "雄性");
 set("age", 1500);
 set("long",
"这是古战场最老，也是最凶狠的一个鬼，被称为鬼王 ！\n");
 set("str", 48);
 set("cor", 52);
 set("cps", 22);
 set("max_kee", 15000);
 set("max_gin", 15000);
 set("max_sen", 15000);
 set("force",4500);
 set("max_force",4500);
 set("mana",4500);
 set("max_mana",4500);
 set("force_factor",50);
 set_skill("parry",300);
 set_skill("dodge",300);
        set_skill("lingfu-steps",300);
 set_skill("unarmed",200);
 set_skill("yinfeng-zhua",300);
 map_skill("unarmed","yinfeng-zhua");
 map_skill("parry","yinfeng-zhua");
        map_skill("dodge","lingfu-steps");
 set("attitude", "aggressive");
 set("combat_exp", 4000000+random(2000000));
 setup();
 carry_object("/obj/money/gold")->set_amount(50);
  carry_object("/d/guzhanchang/obj/piduzhu");
}
void die()
{
 int i;
 object me,*inv;
 if(objectp(me=query_temp("last_damage_from") ))
        {
            inv = all_inventory(this_object());
            for(i=0; i<sizeof(inv); i++)
            {
                if (inv[i]->query("id")=="piduzhu" || inv[i]->query("id")=="pidu zhu")
                {
                   inv[i]->move(me);
                   message_vision("$N张开大嘴吐出一个绿色的宝珠，$n赶忙一把抓到怀里。\n",this_object(),me);
            message("channel:rumor",RED+"【谣言】某人："+me->query("name")+"拿到辟毒珠了！\n"+NOR,users());
         }
        }
  }
 ::die();
}
