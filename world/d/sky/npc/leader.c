inherit NPC;
void create()
{
     set_name("禁军统领",({"guard leader","leader"}));
     set("title","忠心为国");
     set("combat_exp",3000000);
     set("max_kee",2000);
     set("max_sen",2000);
     set("kee",2000);
     set("sen",2000);
     set("max_force",3000);
     set("force",3000);
     set("max_mana",3000);
     set("mana",3000);
     set("force_factor",100);
     set("mana_factor",100);
     set_skill("force",200);
     set_skill("parry",200);
     set_skill("dodge",200);
     set_skill("unarmed",200);
     set_temp("apply/unarmed",200);
     set_temp("apply/dodge",200);
     set_temp("apply/damage",500);
     set_temp("apply/armor",1000);
setup();
}
