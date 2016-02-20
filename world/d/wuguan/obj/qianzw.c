//Cracked by Roath
// qianzw.c
// By yfeng

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(CYN"千字文"NOR, ({ "qianzi wen", "shu", "book3" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "本");
		set("long","读书人必读的千字文。\n");
		set("value", 50000);
		set("material", "paper");
		set("treasure",1);
		set("skill",([
			"name": "literate",
			"exp_required": 10000,
			"read_pot":		1, // 读1下，费1 pot ,add by yfeng
			"jing_cost":    30,
			"difficulty":   22,
			"max_skill":    100,
			"min_skill":    60,
			]) );
	}
}
