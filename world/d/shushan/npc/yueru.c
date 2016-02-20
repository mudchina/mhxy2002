//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("林月如", ({ "lin yueru", "yueru"}));
        set("long", 
"刁蛮少女贵千金，比武招亲动芳心．\n");
        set("gender", "女性");
        set("age", 15);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("spi", 50);
        set("per", 40);
        set("kee", 2000);
        set("max_kee", 2000);
        set("sen", 3000);
        set("max_sen", 3000);
        set("force", 4000);
        set("max_force", 2000);
        set("mana", 6000);
        set("max_mana", 3000);
        set("force_factor", 60);
        set("mana_factor", 100);

        set("combat_exp", 1500000);
        set("daoxing", 2000000);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("yirubian", 200);
        set_skill("whip",180);
        set_skill("force",120);
        setup();
        create_family("蜀山剑派", 2, "红");
        carry_object("/d/obj/cloth/skirt")->wear();
        carry_object("/d/obj/cloth/xiuhuaxie")->wear();
}
int attempt_apprentice(object me)
{
  if ( (me->query("per") < 20 ) && 
       (me->query("gender") != "女性") )
     {
           command("heng "+me->query("id");
		command("say " + "君本无缘，何必强求．\n");
		return;
	}
  command("ok "+me->query("id"));
  command("say 缘由天定，我也只好如此。");
  command("recruit " + me->query("id") );
  return 1;
}
