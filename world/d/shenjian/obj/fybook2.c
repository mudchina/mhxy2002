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
   tell_object(me, "流星的光芒虽短促，但天上还有什么星能比它更灿烂，辉煌。

    当流星出现的时候，就算是永恒不变的星座，也夺不去它的光辉。

    蝴蝶的生命是脆弱的甚至比鲜艳的花还脆弱。

    可是它永远是活在春天里。

    它美丽，它自由，它飞翔。

    它的生命虽短促却芬芳。

    只有剑，才比较接近永恒。

    一个剑客的光芒与生命，往往就在他手里握着的剑上，

    但剑若也有情，它的光芒是否也就会变得和流星一样短促。\n");
   return 1;
}
