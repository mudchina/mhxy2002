// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"


void create()
{
        set_name("独孤剑圣", ({ "shouhuzhe", "shouhu zhe", "zhe" }) );
        set("gender", "男性" );
	set("long",
		"守护第二重天的守护者----蜀山剑祖独孤剑圣\n"
	);
  set("str", 20);
  set("per", 130);
 set("age", 86);
  set("cor", 30);
  set("family/family_name","蜀山剑派");

  set("cps", 75);
  set("kar", 100);
  set("int", 40);
  set("con", 40);
  set("spi", 40);
  set("title", "守护者");
  set("combat_exp", 3200000);
  set("daoxing", 3200000);
  set("max_sen", 6000);
  set("max_kee", 6000);
  set("force", 6000); 
  set("max_force", 6000);
  set("force_factor", 40);
  set("max_mana", 6000);
  set("mana", 6000);
  set("mana_factor", 50);
	
        set_skill("spells",350);
        set_skill("force", 350);
        set_skill("dodge", 350);
        set_skill("parry", 350);
        set_skill("sword", 350);
        set_skill("zixia-shengong", 350);
        set_skill("sevensteps", 350);
        set_skill("hunyuan-zhang", 350);
        set_skill("literate", 350);
        set_skill("unarmed", 350);
        set_skill("mindsword", 350);
set_skill("shushan-jianfa", 350);
        set_skill("taoism",350);
        map_skill("spells", "taoism");
        map_skill("dodge", "sevensteps");
        map_skill("force", "zixia-shengong");
        map_skill("parry", "mindsword");
        map_skill("sword", "mindsword");
        map_skill("unarmed", "hunyuan-zhang");
       set("chat_chance_combat", 50);
              set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword","fenguang" :),

                (: cast_spell, "jianshen" :),                
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

        if((ob&&ob->query("9sky/yi")=="done") && (ob&&ob->query("9sky/er")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【九重天】天极(Tian ji):"+ob->name()+
        "闯过了二重·巴蜀天\n"NOR,users());
        ob->set("9sky/er","done");
        ob->add("9sky/number",1);
         ob->add("daoxing", 20000);
           ob->save();
         tell_object(ob,"你赢得了二十年道行");

        }
       ::die();
}

