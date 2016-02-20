// LLY@FYSY 
inherit ITEM;
void create()
{
	set_name("棋", ({ "棋","qi", "qipu" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "局");
                set("long", "一局很精妙的棋，但现在没人和你下，你只可以自己一个人打打棋谱。\n");
		set("value", 70);
		set("material", "wood");
		set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);
		set("skill", ([
			"name": 		"qidaoforce",	
			"exp_required":	1200000,		
			"sen_cost":		50,	
			"difficulty":	20,	
			"max_skill":	180		
		]) );
	}
}
void init()
{
   add_action("do_da","da");
}

int do_da(string arg)
{
   object me;
   me = this_player();

   if (!arg || arg != "qi") {
      tell_object(me, "你要做什么?\n");
      return 1;
   }
   message_vision("$N一个人兴致勃勃的打起了棋谱。$N好象从棋局中看出了一些什么. . .\n",me);
   return 1;
}
