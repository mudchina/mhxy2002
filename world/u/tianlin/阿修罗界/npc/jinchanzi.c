inherit NPC;
#include <ansi.h>

void create()
{
       set_name("金婵子", ({"jinchan zi", "jinchan", "zi"}));
       set("gender", "男性");
       set("age", 3000);
        set("long", "如来佛祖的弟子，唐三藏的前世，奉命在此看守穷极魔洞。\n");
        set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 10);
        set("str", 20);
     set("combat_exp", 2200000);
    set("daoxing", 15000000);
        set_skill("literate", 250);
       set_skill("unarmed", 250);
       set_skill("dodge", 250);
       set_skill("parry", 250);
        set_skill("sword", 250);
          set_skill("sanqing-jian", 250);
        set_skill("spells", 250);
        set_skill("buddhism", 250);
        set_skill("wuxing-quan", 250);
        set_skill("zhenyuan-force", 250);
        set_skill("force", 250);
        set_skill("xiaoyaoyou", 250);
        map_skill("spells", "buddhism");
        map_skill("force", "zhenyuan-force");
          map_skill("sword", "sanqing-jian");
          map_skill("parry", "sanqing-jian");
        map_skill("dodge", "xiaoyaoyou");
        set("force", 6000);
        set("max_force", 6000);
        set("force_factor", 200);
        set("max_kee",3000);
        set("max_sen",2500);
        set("mana", 8000);
        set("mana_factor", 200);
        set("max_mana", 4000);
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
  (: cast_spell, "bighammer" :),
  }) );
setup();
       carry_object("/u/tianlin/阿修罗界/obj/key");
      carry_object("/d/obj/weapon/sword/qingjian")->wield();
}
void die()
{  
 object killer,yao;
killer = query_temp("last_damage_from");
yao =this_object();
if(killer->query("xiuluo/jinchanzi")!="done" )
{
           killer->set("xiuluo/jinchanzi","done");	  
	   killer->add("daoxing",80000);   
	   tell_object(killer,"你赢得了八十年道行!\n");
           message("channel:rumor", HIR+"【阿修罗界】金婵子(jinchan zi): 佛祖，不好了！"+killer->query("name")+"已经拿到"HIM"穷极之匙"NOR"了！\n"+NOR,users());
}
::die();
}
