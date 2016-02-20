//by tianlin or valen 2001.7.28

#include <ansi.h>

inherit NPC;

void create()
{
	object ob1, ob2;
	
	set_name("猪兵", ({"bing"}) );
	set("long", "这是一位来自开封城的神兵，专门担任护法之责。\n");
	set("attitude", "friendly");

	set("max_gin", 2000);
	set("max_kee", 2000);
	set("max_sen", 2000);

	set("max_mana", 2000);
	set("max_force", 1800);
	set("force", 3000);
	set("mana", 2500);
       set("force_factor", 120);
       set("mana_factor", 140);

	set("str", 140);
	set("cor", 130);
	set("cps", 125);

	set("combat_exp", 1300000);
	set("daoxing", 456789);
	set_skill("dodge", 280);
	set_skill("parry", 280);
	set_skill("rake", 280);
	set_skill("skyriver-rake", 280);
       map_skill("rake", "skyriver-rake");


	setup();

	ob1=carry_object("/d/obj/armor/jinjia");
	ob1->wear();
	ob1->set("no_sell", "掌柜的瞟了一眼道：这东西一看就是劣等品，不要！不要！\n");
	ob2=carry_object("/d/kaifeng/obj/jiuchipa");
	ob2->wield();
	ob2->set("no_sell", "掌柜的瞟了一眼道：这东西一看就是劣等品，不要！不要！\n");
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",
		HIY + name() + "说道：末将奉猪爷召唤，现在已经完成护法任务，就此告辞！\n\n"
		+ name() + "化成一道金光，冲上天际消失不见了。\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

void invocation(object who)
{
	int i;
	object *enemy;

	message("vision",
		HIY "只听咣！的一声，一团金光爆开，现出一个身穿金甲手执九齿钉钯,开封猪兵。\n\n"
		+ name() + "说道：末将奉猪爷召唤，特来护法！\n" NOR,
		environment(), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	set_leader(who);
}
