inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("仙草-灵", ({ "ling", "xiancao", "cao"}));
        set("title", CYN"八叶老师的开门首徒"NOR);   
        set("long", @LONG
灵以前本是昆仑山的一支仙草,后不知在什么地方
修炼成妖,后被八叶老师收服,并为其传授武功。
LONG);
        set("gender", "女性");
        set("age", 21);
        set("attitude", "peaceful");
        set("per", 40);
        set("rank_info/self", "灵");
        set("rank_info/rude", "仙草");
        set("class", "lingjie");
        set("max_kee", 600);
        set("max_gin", 500);
        set("max_sen", 750);
        set("force", 1200);
        set("max_force", 1200);
        set("force_factor", 80);
        set("max_mana", 1500);
        set("mana", 1500);
        set("mana_factor", 100);
        set("combat_exp", 300000);
        set("daoxing", 500000);

        set_skill("literate", 60);
        set_skill("spells", 110);
        set_skill("kongming-spells", 120);
        set_skill("unarmed", 100);
        set_skill("guangming-shouyin", 100);
        set_skill("dodge", 80);
        set_skill("fengtian-steps", 80);
        set_skill("parry", 80);
        set_skill("force", 90);
        set_skill("guangming-force", 80);
        set_skill("umbrella", 80);
        set_skill("lingfan-san",80);

        map_skill("spells", "kongming-spells");
        map_skill("unarmed", "guangming-shouyin");
        map_skill("dodge", "fengtian-steps");
        map_skill("force", "guangming-force");
        map_skill("umbrella", "lingfan-san");

        create_family("灵界", 3, "弟子");

        setup();
        carry_object("/d/lingjie/obj/xianlv")->wear();
        carry_object("/d/lingjie/obj/anhun")->wield();
        
}

void attempt_apprentice(object ob,object me)

{
                         command("xf");
                         command("say 知道了!" + RANK_D->query_respect(ob) +
                        "你要听话呀,不然我定不饶你。\n");
                        command("recruit " + ob->query("id") );
      

        return;
        
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lingjie");
}

void greeting(object me)
{
  if(me->query("family/family_name") == "灵界")
    return;
 
      command("say 这是你该去的地方吗！?");
      kill_ob(me);
      return;
}

void die()
{
  if (environment())
    command("die");

  set("eff_kee", 600);
  set("eff_gin", 650);
  set("eff_sen", 650);
  set("kee", 600);
  set("gin", 650);
  set("sen", 650);
}

void unconcious()
{
  die ();
}
