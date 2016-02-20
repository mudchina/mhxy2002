// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"


void create()
{
        set_name("孙行者", ({ "shouhuzhe", "shouhu zhe", "zhe" }) );
        set("gender", "男性" );
	set("long",
		"守护第九重天的守护者----斗占胜佛孙行者\n"
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
  set("combat_exp", 4800000);
  set("daoxing", 4800000);
  set("max_sen", 6000);
  set("max_kee", 6000);
  set("family/family_name","方寸山三星洞");

  set("force", 6000); 
  set("max_force", 6000);
  set("force_factor", 40);
  set("max_mana", 6000);
  set("mana", 6000);
  set("mana_factor", 50);
	
              set_skill("literate", 500);
       set_skill("unarmed", 500);
       set_skill("dodge", 500);
       set_skill("parry", 500);
        set_skill("stick", 500);
        set_skill("sword", 500);
        set_skill("liangyi-sword", 500);
        set_skill("spells", 500);
        set_skill("dao", 500);
        set_skill("puti-zhi", 500);
        set_skill("wuxiangforce", 500);
        set_skill("force", 500);
        set_skill("qianjun-bang", 500);
        set_skill("jindouyun", 500);
        map_skill("spells", "dao");
	map_skill("unarmed", "puti-zhi");
	map_skill("force", "wuxiangforce");
	map_skill("stick", "qianjun-bang");
	map_skill("parry", "qianjun-bang");
	map_skill("dodge", "jindouyun");
	map_skill("sword", "liangyi-sword");
	set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
		(: cast_spell, "light" :),
		(: cast_spell, "dingshen" :),
                (: perform_action, "stick","pili" :),
        }) );

	setup();
   carry_object("/d/obj/weapon/stick/fake-jingubang")->wield();
   carry_object("/d/obj/armor/jinjia")->wear();
}


void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","exert");

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

        if((ob&&ob->query("9sky/ba")=="done") && (ob&&ob->query("9sky/jiu")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【九重天】天极(Tian ji):"+ob->name()+
        "闯过了九重·灵佛天\n"NOR,users());
        ob->set("9sky/jiu","done");
        ob->add("9sky/number",1);
         ob->add("daoxing", 90000);
           ob->save();
         tell_object(ob,"你赢得了九十年道行");

        }
       ::die();
}


