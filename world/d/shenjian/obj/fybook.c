// Lly@FYSY
inherit ITEM;
void create()
{
	set_name("风云志", ({ "fybook" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
                set("long", "一本神秘的古书，书页已经翻黄了！你可以好好看看(kan)。\n");
		set("value", 0);
		set("material", "paper");
				
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

   if (!arg || arg != "fybook") {
      tell_object(me, "你要看什么？\n");
      return 1;
   }
   tell_object(me, "「天涯远不远？」
「不远！」
「人就在天涯，天涯怎麽会远？」

「明月是什麽颜色？」
「是蓝的，就像海一样蓝，一样深，一样忧郁。」

「明月在那？」
「就在他的心，他的心就是明月。」

「刀呢？」
「刀就在他手！」
「那是柄什麽样的刀？」
「他的刀如天涯般辽阔寂寞，如明月般皎洁忧郁，有时一刀挥出，
又彷佛是空的！」

「空的？」
「空空蒙蒙，缥缈虚幻，彷佛根本不存在，又彷佛到处都在。」
「可是他的刀看来并不快。」
「不快的刀，什麽能无敌於天下？」
「因为他的刀已超越了速度的极限！」

「他的人呢？」
「人犹未归，人已断肠。」
「何处是归程？」
「归程就在他眼前。」
「他看不见？」
「他没有去看。」
「所以他找不到？」
「现在虽然找不到，迟早总有一天会找到的！」
「一定会找到？」
「一定！」\n");
   return 1;
}
