#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include <obstacle.h>

void create()
{
        
   set_name("燕十三", ({ "master yan", "master",  "yan", "master shisan" }) );
        set("nickname", HIW "名剑纵然已消沉 可是如今剑仍在"NOR);
	set("gender", "男性");
	set("age", 20);
	set("attitude", "heroism");
	set("per", 9);
	set("max_kee", 2850);
	set("max_gin", 2800);
	set("max_sen", 2850);
	set("force", 8000);
	set("max_force", 15000);
	set("force_factor", 150);
	set("max_mana", 5600);
	set("mana", 8300);
	set("mana_factor", 100);
	set("combat_exp", 5500000);
	set("daoxing", 6500000);
        set("long",
"一个很冷静的人,带着一种已深入骨髓的冷漠与疲倦，却又偏偏带着种逼人的杀气。
他的人与剑十七岁时就已名满江湖，如今他年近中年，他已放不下手中的剑，别人也
不容他放下。当他放下剑时，他的生命就要结束。\n"	);
        create_family("神剑山庄", 1, "掌门");
       set_skill("literate", 180);
       set_skill("unarmed", 285);
       set_skill("dodge", 285);
       set_skill("force", 285);
       set_skill("parry", 285);
       set_skill("sword", 285);
       set_skill("spells", 285);
       set_skill("blade", 285);
       set_skill("lianhuan-zhang", 285);
       set_skill("duo-sword", 285);
       set_skill("qingfeng-jian", 285);
       set_skill("cloudforce", 285);
       set_skill("shadowsteps", 285);
       set_skill("xueying-xianfa", 285);
       set_skill("shenji-blade", 285);
       map_skill("spells", "xueying-xianfa");
       map_skill("unarmed", "lianhuan-zhang");
       map_skill("force", "cloudforce");
       map_skill("sword", "duo-sword");
       map_skill("parry", "qingfeng-jian");
       map_skill("dodge", "shadowsteps");
       map_skill("blade", "shenji-blade");
        setup();
        carry_object("/obj/cloth")->wear();
     //   carry_object("/obj/weapon/sword")->wield();
	//carry_object(__DIR__"obj/oldskin")->wear();

}


void attempt_apprentice(object ob)
{
	int size = sizeof(obstacles);
  	string *names = keys(obstacles);
  	int i;
  	for (i = 0; i < size; i++)
      	if (ob->query("obstacle/"+names[i])!="done" && !wizardp(ob))
      	{
 	   command("shake");
    	   command("say 这位" + RANK_D->query_respect(ob) + "尚未历尽西行难关，恐怕难以领悟高深武学。\n");
	   return;
      	}
	if ( (string)ob->query("family/family_name")=="神剑山庄") {
		command("smile");
		command("say 很好，我就收下你，希望你多加努力，早成正果。\n");

		command("recruit " + ob->query("id") );
        message("channel:rumor",HIM+"【谣言】某人："BLINK+HIR+ob->query("name")+NOR+HIM"历经种种磨难,终于寻得燕十三！\n"NOR,users() );
		return;
	}

	command("shake");
	command("say " + "走开走开。\n");
	return;
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shenjian");
                ob->set("title",HBRED+HIR"夺命"HIY"十三"HIC"剑"HIW"传人"NOR);
}
 
