// Lly@FYSY
inherit ITEM;
void create()
{
	set_name("琴", ({ "琴","qin", "guqin" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "具");
		set("value", 2000);
                set("long", "这是一具古色古香的檀木琴,你不由的想去弹几下。\n");
		set("material", "wood");
		set("no_shown",1);
		set("no_drop",1);
		set("skill", ([
			"name": 		"perception",	
			"exp_required":	1000000,		
			"sen_cost":		50,	
			"difficulty":	15,	
			"max_skill":	200		
		]) );
	}
}
void init()
{
   add_action("do_play","play");
}

int do_play(string arg)
{
   object me;
   me = this_player();

   if (!arg || arg != "qin") {
      tell_object(me, "你要做什么？\n");
      return 1;
   }
   message_vision("$N一划琴，弹出一首如行云般的曲子。$N仿佛从琴音中听出了一些什么奥妙. . .\n",me);
   return 1;
}
