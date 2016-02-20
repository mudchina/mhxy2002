// Lly@FYSY
inherit ITEM;
void create()
{
	set_name("石头", ({ "石头","stone", "磨石" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("value", 2000);
                set("long", "这是一到处都能见到的磨刀石，看上去很光滑坚硬，好象很久没人动过的样子。\n");
		set("material", "stone");
		set("no_shown",1);
		set("no_drop",1);
			}
}
void init()
{
   add_action("do_pull","pull");
}

int do_pull(string arg)
{
   object me;
   me = this_player();

   if (!arg || arg != "stone") {
      tell_object(me, "你要拉动什么？\n");
      return 1;
   }
   message_vision("$N用尽全力将磨石拉开，惊讶的发现磨石下面的船板上有一个利刃刻出的大十字,十字之尖所指的方向，好象就是翠云峰顶！！！\n",me);
me->set_temp("looked_shizhi",1);   return 1;
}
