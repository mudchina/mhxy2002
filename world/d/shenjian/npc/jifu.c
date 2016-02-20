//By tianlin@mhxy for 2002.1.10从新改编

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name(HIM"纪芙"NOR, ({ "ji fu", "ji","jifu", "fu",}) );
        set("gender", "女性" );
        set("age", 21);
        set("agi",30);
        set("str", 60);
        set("per", 29);
        set("nickname", HIG"燕十三"HIY"座下夺命圣女"NOR);
        set("int",30);
        set("attitude","friendly");
        set("max_force", 2100);
        set("force", 3000);
        set("force_factor", 80);
        set("max_mana", 2300);
        set("mana", 3000);
	 set("max_kee",1000);
        set("max_gin",1000);
        set("max_sen",1000);
        set("chat_chance", 30);
        set("long",
"这位就是燕十三的红颜知己纪芙小姐，也是夺名十三剑的传人\n"
        );
        create_family("神剑山庄",2,"夺命剑法传人");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword", "shisan" :),
        }) );

        set("combat_exp", 630000);
        set("daoxing", 1230000);
       set_skill("literate", 80);
       set_skill("unarmed", 100);
       set_skill("dodge", 100);
       set_skill("force", 120);
       set_skill("parry", 115);
       set_skill("sword", 105);
       set_skill("spells", 120);
       set_skill("blade", 125);
       set_skill("lianhuan-zhang", 155);
       set_skill("duo-sword", 185);
       set_skill("cloudforce", 115);
       set_skill("shadowsteps", 135);
       set_skill("xueying-xianfa", 115);
       map_skill("spells", "xueying-xianfa");
       map_skill("unarmed", "lianhuan-zhang");
       map_skill("force", "cloudforce");
       map_skill("sword", "duo-sword");
       map_skill("parry", "duo-sword");
       map_skill("dodge", "shadowsteps");
        setup();
    //    carry_object(__DIR__"obj/deitysword")->wield();
   //     carry_object(__DIR__"obj/sjcloth")->wear();
}

void attempt_apprentice(object ob)
{
   if( (string)ob->query("family/family_name")=="神剑山庄" )
     {
       if( (int)ob->query("family/generation") < 3  )
          command("say 不敢，不敢。我该拜" + RANK_D->query_respect(ob) + "您为师才是。\n");
       else if( (int)ob->query("family/generation") ==3  )
	  command("say 你这个" + RANK_D->query_rude(ob) + "还是别来消遣你姑奶奶了！\n");
      else 
         {
	  command(":D");
	  command("say 好！" + RANK_D->query_respect(ob) + "投入我门下保你学到上乘剑法！\n");
	  command("haha");
	  command("recruit " + ob->query("id") );
    //     ob->set("title", HIR"神剑山庄"NOR);
         ob->set("class", "shenjian");
	 }
     }

    else
      {
       command(":D ");
       command("say 好，"+ RANK_D->query_respect(ob) +"，你到我神剑山庄，必有出人头地的一天！\n");
       command("recruit " + ob->query("id") );
			message("system", HIB"我神剑山庄又多了一个弟子  "HIR+this_player()->name()+HIW"
                 神剑山庄"HIY"的势力加强了。\n"NOR,users());
   //    ob->set("title", HIR"神剑山庄"NOR);
       ob->set("class", "shenjian");
      }

  return;
}

