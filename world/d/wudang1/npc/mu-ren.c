//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m
//≤ø∑÷”≈ªØ

#include <ansi.h>
inherit NPC;
//inherit F_CLEAN_UP;

void create()
{
	set_name(YEL"ƒæ»À"NOR, ({ "mu ren", "mu", "wood man", "wood" }) );
	set("gender", "ƒ––‘" );
	set("age", 30);
	set("long", "“ª∏ˆ¡∑π¶”√µƒ±»Œ‰ƒæ»À£¨÷∆◊˜æ´«…£¨»ÁÕ¨’Ê»À“ª∞„°£\n");
	set("attitude", "heroism");

	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);

	set("no_get", "1");
	set("max_kee", 300);
	set("eff_kee", 300);
	set("kee", 300);
	set("max_sen", 100);
	set("sen", 100);
	set("force", 300);
	set("max_force", 300);
	set("mana", 300);
	set("max_mana", 300);
       set("force_factor", 10);
       set("mana_factor", 10);
	set("shen_type", 0);

	set("combat_exp", 50000);
	set("daoxing", 50000);

	set_skill("force", 30); 
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);

	set("fight_times", 0);	

	setup();
        
}

int accept_fight(object ob)
{
	object me;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

	me = this_object();

	if (is_fighting()) return 0;

	if (me->query("damaged"))
		return notify_fail("’‚∏ˆƒæ»À“—æ≠±ª¥Úªµ¡À£°\n");	

	if (random(me->query("fight_times")) >= 10) {
		me->set("damaged", 1);
		return notify_fail("’‚∏ˆƒæ»À“—æ≠±ª¥Úªµ¡À£°\n");	
	}

	if (me->query("last_fighter") == ob->query("id"))
		return notify_fail("ƒ„∏’∏˙’‚∏ˆƒæ»À¡∑π˝π¶£°\n");		

	me->set("last_fighter", ob->query("id"));
	me->add("fight_times", 1);

	remove_call_out("renewing");	
	call_out("renewing", 300 + random(300), me);	

/* delete and copy skills */

	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname  = keys(skill_status);

		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) {
			me->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]);
		}
	}
	
/* delete and copy skill maps */

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		temp = sizeof(map_status);
		for(i=0; i<temp; i++) {
			me->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			me->map_skill(mname[i], map_status[mname[i]]);
		}
	}
	
/* delete and copy skill prepares */

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i=0; i<temp; i++) {
			me->prepare_skill(pname[i]);
		}
	}

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}
	
	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);

		me->set("max_kee",    hp_status["max_kee"]);
		me->set("eff_kee",    hp_status["eff_kee"]);
		me->set("kee",        hp_status["kee"]);
		me->set("max_sen",  hp_status["max_sen"]);
		me->set("eff_sen",  hp_status["eff_sen"]);
		me->set("sen",      hp_status["sen"]);
		me->set("max_force", hp_status["max_force"]);
		me->set("force",     hp_status["force"]);
		me->set("force_factor",     hp_status["force_factor"]);
		me->set("mana_factor",     hp_status["mana_factor"]);
		me->set("combat_exp",hp_status["combat_exp"]);
		me->set("daoxing",hp_status["daoxing"]);

	return 1;
}

void renewing(object me)
{
	me->delete("last_fighter");
}
