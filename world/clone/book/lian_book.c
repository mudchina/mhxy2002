// blade-book.c

inherit ITEM;

void create()
{
	set_name( "连城剑谱残篇",({ "liansword book","book"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
                set("long","这是一本连城剑谱的几页残篇。\n");
		set("value", 0);
		set("no_put", 1);
		set("material", "paper");
		set("skill", ([
                        "name":         "liancheng-jian",      //name of the skill
                        "exp_required": 100000 ,        //minimum combat experience required
			"jing_cost":    20+random(100),// jing cost every time study this
			"difficulty":	60,           // the base int to learn this skill
			"min_skill":	0,           // the minimum level you can learn
			"max_skill":	200            // the maximum level you can learn
		]) );
	}
}
