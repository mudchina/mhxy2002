// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"


void create()
{
        set_name("孔武大帝", ({ "shouhuzhe", "shouhu zhe", "zhe" }) );
        set("gender", "男性" );
	set("long",
		"守护第六重天的守护者----武帝圣君孔武大帝\n"
	);
  set("str", 20);
  set("per", 130);
 set("age", 86);
  set("cor", 30);
  set("cps", 75);
  set("kar", 100);
  set("int", 40);
  set("con", 40);
  set("spi", 40);
  set("title", "守护者");
  set("combat_exp", 4000000);
  set("daoxing", 4000000);
  set("max_sen", 6000);
  set("max_kee", 6000);
  set("force", 6000); 
  set("max_force", 6000);
  set("force_factor", 40);
  set("family/family_name","武圣门");

  set("max_mana", 6000);
  set("mana", 6000);
  set("mana_factor", 50);
	
               set_skill("unarmed", 350);
        set_skill("dodge", 350);
        set_skill("parry", 350);
        set_skill("spells", 350);  
        set_skill("feisheng", 350);
        set_skill("literate", 350);
        set_skill("sword", 350);  
        set_skill("wuying", 350);
        set_skill("fumobashi", 350);  
        set_skill("mizongbu", 350);
        set_skill("dodge", 350);  
        set_skill("force", 350);   
        set_skill("xiantian", 350);

        map_skill("spells", "feisheng");
        map_skill("unarmed", "fumobashi");
        map_skill("force", "xiantian");
        map_skill("sword", "wuying");
        map_skill("parry", "wuying");
        map_skill("dodge", "mizongbu");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        (: cast_spell, "feixian" :),
                (: perform_action, "sword","fhgr" :),

	}) );


	setup();
   carry_object("/d/obj/weapon/sword/qingfeng")->wield();
   carry_object("/d/obj/armor/jinjia")->wear();
}


void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","ji");
}
int do_none()
{
        object me = this_object();
        message_vision("此乃天界，岂容你乱来？\n",me);
        return 1;
} 


void die()
{

        object ob = query_temp("my_killer");

        if((ob&&ob->query("9sky/wu")=="done") && (ob&&ob->query("9sky/liu")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【九重天】天极(Tian ji):"+ob->name()+
        "闯过了六重·栖霞天\n"NOR,users());
        ob->set("9sky/liu","done");
        ob->add("9sky/number",1);
         ob->add("daoxing", 60000);
           ob->save();
         tell_object(ob,"你赢得了六十年道行");

        }
       ::die();
}

