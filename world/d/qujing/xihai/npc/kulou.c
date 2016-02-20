//EDIT BY LUCAS
inherit NPC;
#include <ansi.h>
int do_remove(string var);
void create()
{
       set_name("骷髅龙", ({"kulou long", "dragon"}));

        set("long","这是一具威猛的海龙之骨，虽然已成白骨，仍然佩刀饰剑，威风凛凛。\n");
       set("gender", "男性");
       set("age", 1000);
        set("per", 10);
        set("str", 40);
        set("combat_exp", 2000000);
        set_skill("parry", 180);  
        set_skill("force", 150); 
        set_skill("spells", 200); 
        set_skill("seashentong", 190); 
        set_skill("dragonstep", 200); 
        set_skill("fork", 180); 
        set_skill("fengbo-cha", 180); 
        set_skill("dragonfight", 200); 
        set_skill("dodge", 200);
        set_skill("unarmed", 200); 

        map_skill("parry", "fengbo-cha");
        map_skill("fork", "fengbo-cha");
        map_skill("unarmed", "dragonfight");
        map_skill("dodge", "dragonstep"); 
        map_skill("spells", "seashentong");
        map_skill("force", "dragonforce");
        set("force", 2500);
        set("max_force", 2500);
        set("force_factor", 50); 
        set("mana", 3000);
        set("max_mana", 3000);
        set("mana_factor", 100);
        set("max_kee", 3000);
        set("max_sen", 1000);
        setup();
        carry_object("/d/sea/obj/tuotiancha")->wield();
        carry_object("/d/obj/armor/yinjia")->wear();  
 
}
int do_remove(string target)
{
        object me;
 
        me = this_player();
        if (target=="skeleton") 
                   message("vision",
   HIY "骷髅龙突然一震，活了过来，怒道：何处小贼，敢来此处盗宝！\n" NOR, environment(), this_object() );
                   kill_ob(this_player()); 
}

