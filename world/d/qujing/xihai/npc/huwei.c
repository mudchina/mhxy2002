inherit NPC;
#include <ansi.h>

void create()
{
       set_name("龙宫护卫", ({"longgong huwei", "huwei"}));

        set("long","一个穿着金甲的龙宫护卫，尽忠职守地守卫在水晶宫正殿前。\n");
       set("gender", "男性");
       set("age", 20+random(50));
        set("per", 10);
        set("str", 25);
       set("shen_type", 1);
        set("combat_exp", 100000);
        set_skill("parry", 60);  
        set_skill("force", 80); 
        set_skill("spells", 60); 
        set_skill("seashentong", 60); 
        set_skill("dragonstep", 60); 
        set_skill("fork", 60); 
        set_skill("fengbo-cha", 60); 
        set_skill("dragonfight", 60); 
        set_skill("dodge", 60);
        set_skill("unarmed", 50); 

        map_skill("parry", "fengbo-cha");
        map_skill("fork", "fengbo-cha");
        map_skill("unarmed", "dragonfight");
        map_skill("dodge", "dragonstep"); 
        map_skill("spells", "seashentong");
        map_skill("force", "dragonforce");
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 20); 
        set("mana", 600);
        set("max_mana", 600);
        set("mana_factor", 30);
        set("max_kee", 600);
        set("max_sen", 500);
        setup();
        carry_object("/d/obj/weapon/fork/gangcha")->wield();
        carry_object("/d/obj/armor/tiejia")->wear();  
 
}

