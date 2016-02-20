
inherit NPC;

void create()
{
	set_name("服务员", ({ "waiter2", "fuwuyuan2", "yuan2" }));
	set("str", 20);
	set("gender", "男性");
	set("age", 45);
	set("long", "他也是一名服务员。\n");
	set("combat_exp", 2000);
	set("attitude", "friendly");
	setup();
}

void init()
{	
}

int accept_object(object who, object ob)
{
	int pay, value;

	if (ob->query("money_id")) {
		if (!(pay = who->query_temp("total_pay"))) {
			tell_object(who, "服务员忙不迭地笑道：“客官您又不欠小店的钱，就别拿老头儿寻开心了。”\n");
			return 0;
		}
		if (!who->query_temp("to_pay")) {
			tell_object(who, "服务员说道：“客官您先结帐(pay)再付款。”\n");
			return 0;
		}
		value = ob->value();
		if (value >= pay) {
			who->delete_temp("to_pay");
			who->delete_temp("total_pay");
			if (value == pay) message_vision("服务员满脸堆着笑，冲$N哈腰道：“谢客官您啦，走好。”\n", who);
			else message_vision("服务员满脸堆着笑，冲$N哈腰道：“谢客官您的小费，老儿不客气就收下了，您走好。”\n", who);
			return 1;
		}
		else {
			pay -= value;	
			message_vision("服务员对着$N说道：“不够！还差" + chinese_number(pay) + "分钱。”\n", who);
			who->set_temp("total_pay", pay);
			return 1;
		}
	}
	return 0;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N沮丧地发现服务员躲在高高的柜台后面，够不到。\n", ob);
}

void unconcious()
{
	say( "服务员大喊一声：“我不行了，快来救我！”\n");
	say( "结果从柜台后面钻出一个小童来，往服务员的嘴里塞了一个药丸就走了。\n");
	say( "片刻之间，服务员又恢复了精神，“嘿嘿”奸笑了两声。\n");
	reincarnate();
	set("eff_kee", query("max_kee"));
	set("kee", query("max_kee"));
	set("eff_gin", query("max_gin"));
	set("gin", query("max_gin"));
}

void die()
{
	unconcious();
}

