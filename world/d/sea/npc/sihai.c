//modified by sgzl for dntg/donghai quest
//By tianlin@mhxy for 2002.3.7修改拜师要求
#include <skill.h>

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <obstacle.h>
string back_me(object me);

void create()
{
       	set_name(HIC"四海龙王"NOR, ({"sihai longwang", "longwang"}));

	set("long","此乃天下四海之王，敖广之父，统领天下水军，一声号令，天下水族
莫敢不从俨然是跳出三界外不在五行中。\n");
       set("gender", "男性");
       set("age", 1100);
	set("title", HIW"万源之尊"NOR);
	set("class","dragon");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("combat_exp", 5000000);
       set("daoxing", 3000000);
       set("rank_info/respect", "陛下");
       set("per", 30);
       set("str", 30);
       set("max_kee", 10000);
       set("max_gin", 1000);
       set("max_sen", 2500);
       set("force", 5000);
       set("max_force", 5000);
       set("force_factor", 300);
       set("max_mana", 5000);
       set("mana", 5000);
       set("mana_factor", 200);
       set("combat_exp", 3200000);
       set("daoxing", 5500000);
       set_skill("huntian-hammer", 285);
       set_skill("hammer", 285);
       set_skill("literate", 180);
       set_skill("unarmed", 285);
       set_skill("dodge", 285);
       set_skill("force", 285);
       set_skill("parry", 285);
       set_skill("fork", 285);
       set_skill("spells", 285);
       set_skill("seashentong", 285);
       set_skill("dragonfight", 285);
       set_skill("dragonforce", 285);
       set_skill("fengbo-cha", 285); 
       set_skill("dragonstep", 285);
       set_skill("whip", 285); 
       set_skill("snowwhip", 285);
       map_skill("hammer", "huntian-hammer");
       map_skill("spells", "seashentong");
       map_skill("unarmed", "dragonfight");
       map_skill("force", "dragonforce");
       map_skill("fork", "fengbo-cha");
       map_skill("parry", "fengbo-cha");
       map_skill("dodge", "dragonstep");
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
                (: cast_spell, "hufa" :),
                (: cast_spell, "dragonfire" :),
                (: perform_action, "unarmed", "sheshen" :),
                }) );
        create_family("东海龙宫", 1, "水族");
         set_temp("apply/armor",100);
         set_temp("apply/damage",125);
setup ();
       carry_object("/d/obj/new/moon_pao")->wear();
        if ("/d/obj/new/fork"->in_mud())
            carry_object("/d/obj/weapon/fork/gangcha")->wield();
        else carry_object("/d/obj/new/fork")->wield();
}
void init()
{
       ::init();
       set("inquiry",([
                  "name" : "我就是"+HIC" 四海总龙王"NOR+"!!!\n",
                  "回去" : (: back_me :),
                  "back" : (: back_me :),
                  ]) );
}
void destroy(object ob)
{
        destruct(ob);
        return;
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
 if (((int)ob->query("combat_exp")+(int)ob->query("daoxing") < 5000000))
 {
command("say " + RANK_D->query_respect(ob) +
"还是先到我儿处先把基础打好了再来我这儿吧。\n");
return;
}
        command("smile");
        command("say 难得" + RANK_D->query_respect(ob) +
		"有此心志，还望日后多加努力，为我东海龙宫争光。\n");
        command("recruit " + ob->query("id") );
        message("channel:rumor",HIM+"【谣言】某人："HIC+ob->query("name")+NOR+HIM"历经种种磨难，拜其四海龙王为师潜心修炼！\n"NOR,users() );
	return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dragon");
}
string back_me(object me)
{
 me=this_player();
 message_vision(HIC"四海龙王"NOR+CYN"龙须一动，把：$N送到了岸边。\n"NOR, me);
 me->move("/d/changan/eastseashore");  
 return "";
}
