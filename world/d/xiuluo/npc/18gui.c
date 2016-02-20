#include <ansi.h>
inherit NPC;
int random_go(object me, string* dirs,int i);
mapping maps;

string *first_name = ({ "赤","红","黄","绿","青","蓝","金","木","火","土" });
string *last_name  = ({ "噩鬼","厉鬼","死鬼","无常" });

void create()
{
   string name;
        name = COLOR_D->random_color()+first_name[random(sizeof(first_name))];
        name += COLOR_D->random_color()+last_name[random(sizeof(last_name))]+NOR;
        set_name(name, ({"gui","wuchang","e gui"}));
  set("age", 2500 + random(1000) );
  set("max_kee", 500*(5+random(5)) );
  set("kee",query("max_kee"));
  set("max_sen", 500*(5+random(5)) );
  set("sen",query("max_sen"));
  set("max_force", 500*(5+random(5)) );
  set("force_factor", 20*(2+random(5)) );
  set("mana_factor",20*(2+random(5)));
  set("force", 7000);
  set("max_mana",500*(5+random(5)));
  set("mana",7000);
  set("combat_exp", 200000*(10+ random(5)) );
  set("daoxing",200000*(10+ random(5)));
  set("attitude", "aggressive");
  set_skill("sword", 250);
//  set_skill("westsword", 250);
  set_skill("unarmed",250);
  set_skill("parry",250);
  set_skill("dodge",250);
  set_skill("ghost-steps",250);
  set_skill("jinghun-zhang",250);
//  map_skill("sword", "westsword");
  map_skill("unarmed","jinghun-zhang");
//  map_skill("parry", "westsword");
  map_skill("dodge", "ghost-steps");  
//        set("chat_chance",90);
//        set("chat_msg", ({ 
//                (: random_move :)
//                }));

  setup();
//  carry_object("/d/obj/weapon/sword/westsword")->wield();
}
/*
void die()
{  
 object killer,yao;
killer = query_temp("last_damage_from");
yao =this_object();
if(killer->query("18/1")!="done" )
{
           killer->set("18/1","done");   
           killer->add("daoxing",10000);   
           tell_object(killer,"你赢得了十年道行!\n");
           message("channel:rumor", HIG+"【阿修罗界】: 听说"+killer->query("name")+"勇敢的闯过了吊筋狱！\n"+NOR,users());

}
// destruct(this_object());
::die();
}
*/