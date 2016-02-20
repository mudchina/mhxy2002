// LLY@FYSY 
inherit ITEM;
void create()
{
	set_name("书", ({ "书","shu", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("value", 1000);
		set("material", "paper");
                set("long", "这是一本天下读书人都看过的《百家姓》,无事可做的时候可以看看，用来消磨时间。\n");
		set("no_shown",1);
		set("no_drop",1);
		set("skill", ([
			"name": 		"sword",	
			"exp_required":	0,		
			"sen_cost":		40,	
			"difficulty":	30,	
			"max_skill":	200		
		]) );
	}
}
void init()
{
   add_action("do_kan","kan");
}

int do_kan(string arg)
{
   object me;
   me = this_player();

   if (!arg || arg != "shu") {
      tell_object(me, "你要看什么？\n");
      return 1;
   }
   message_vision("$N拿起《百家姓》，草草的翻了几页。$N发现书中的小字组成的好象是一些剑招. . .\n",me);
   return 1;
}
