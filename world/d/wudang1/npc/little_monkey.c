// little_monkey.c

inherit NPC;

void create()
{
	set_name("小猴",({ "little monkey", "monkey"}) );
	set("gender", "雄性");
	set("race", "野兽");
	set("age", 1);
	set("long", "这是一只调皮的小猴子，虽是畜牲，却喜欢模仿人样。\n");
	set("combat_exp", 500);
       set("limbs", ({ "猴头", "猴身", "猴爪", "猴腿", "尾巴" }) );
        set("verbs", ({ "hoof","sting", "claw" }) );
set("shen_type", -1);
	set("str", 11);
	set("dex", 41);
	set("con", 11);
	set("int", 11);
        set("attitude", "peaceful");
        setup();
}
