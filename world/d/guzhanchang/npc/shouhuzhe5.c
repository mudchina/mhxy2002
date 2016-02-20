// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"


void create()
{
        set_name("姜子牙", ({ "shouhuzhe", "shouhu zhe", "zhe" }) );
        set("gender", "男性" );
	set("long",
		"守护第四重天的守护者----封神尊者姜子牙\n"
	);
  set("str", 20);
  set("per", 130);
 set("age", 86);
  set("cor", 30);
  set("cps", 75);
  set("kar", 100);
  set("int", 40);
  set("family/family_name","五庄观");

  set("con", 40);
  set("spi", 40);
  set("title", "守护者");
  set("combat_exp", 3800000);
  set("daoxing", 3800000);
  set("max_sen", 6000);
  set("max_kee", 6000);
  set("force", 6000); 
  set("max_force", 6000);
  set("force_factor", 40);
  set("max_mana", 6000);
  set("mana", 6000);
  set("mana_factor", 50);
	
         set_skill("unarmed", 350);
   set_skill("wuxing-quan", 350);
   set_skill("dodge", 350);
   set_skill("baguazhen", 160);
   set_skill("parry", 350);
   set_skill("sword", 350);
   set_skill("sanqing-jian", 350);
   set_skill("staff", 350);
   set_skill("fumo-zhang", 350);
   set_skill("hammer", 350);
   set_skill("kaishan-chui", 350);
   set_skill("blade", 350);
   set_skill("yange-blade", 350);
   set_skill("force", 350);   
   set_skill("zhenyuan-force", 350);
   set_skill("literate", 350);
   set_skill("spells", 350);
   set_skill("taiyi", 350);
   map_skill("spells", "taiyi");
   map_skill("force", "zhenyuan-force");
   map_skill("unarmed", "wuxing-quan");
   map_skill("sword", "sanqing-jian");
   map_skill("dodge", "baguazhen");
   map_skill("staff", "fumo-zhang");
   map_skill("blade", "yange-blade");
   map_skill("hammer", "kaishan-chui");

   set("chat_chance_combat", 90);
   set("chat_msg_combat", 
   ({
     (: cast_spell, "zhenhuo" :),
     (: cast_spell, "qiankun" :),
                (: perform_action, "sword","jianzhang" :),

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

        if((ob&&ob->query("9sky/si")=="done") && (ob&&ob->query("9sky/wu")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【九重天】天极(Tian ji):"+ob->name()+
        "闯过了五重·千紫天\n"NOR,users());
        ob->set("9sky/wu","done");
        ob->add("9sky/number",1);
         ob->add("daoxing", 50000);
           ob->save();
         tell_object(ob,"你赢得了五十年道行");

        }
       ::die();
}


