// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"



void create()
{
        set_name("达摩祖师", ({ "shouhuzhe", "shouhu zhe", "zhe" }) );
        set("gender", "男性" );
	set("long",
		"守护第三重天的守护者----万佛之子 达摩祖师\n"
	);
  set("str", 20);
  set("per", 130);
 set("age", 86);
  set("cor", 30);
  set("cps", 75);
  set("kar", 100);
  set("family/family_name","南海普陀山");

  set("int", 40);
  set("con", 40);
  set("spi", 40);
  set("title", "守护者");
  set("combat_exp", 3400000);
  set("daoxing", 3400000);
  set("max_sen", 6000);
  set("max_kee", 6000);
  set("force", 6000); 
  set("max_force", 6000);
  set("force_factor", 40);
  set("max_mana", 6000);
  set("mana", 6000);
  set("mana_factor", 50);
	
               set_skill("literate", 350);
        set_skill("spells", 350);
        set_skill("buddhism", 350);
        set_skill("unarmed", 350);
        set_skill("jienan-zhi", 350);
        set_skill("dodge", 350);
        set_skill("lotusmove", 350);
        set_skill("parry", 350);
        set_skill("force", 350);
        set_skill("lotusforce", 350);
        set_skill("staff", 350);
        set_skill("lunhui-zhang", 350);
        map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
                (: perform_action, "staff","pudu" :),
	
}) );

	setup();
        carry_object("/d/obj/weapon/staff/budd_staff")->wield();
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

        if((ob&&ob->query("9sky/er")=="done") && (ob&&ob->query("9sky/san")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【九重天】天极(Tian ji):"+ob->name()+
        "闯过了三重·普渡天\n"NOR,users());
        ob->set("9sky/san","done");
        ob->add("9sky/number",1);
         ob->add("daoxing", 30000);
           ob->save();
         tell_object(ob,"你赢得了三十年道行");

        }
       ::die();
}


