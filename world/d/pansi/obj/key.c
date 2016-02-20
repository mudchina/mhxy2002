inherit ITEM;

void create()
{
  set_name("钥匙", ({ "key" }));
  set_weight(1000);
set("long", "这是一个进入盘丝洞内室的一把钥匙，据说只要能得到
 这把钥匙就能见到盘丝洞祖师。\n" );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "只");
    set("no_sell", 1);
    set("material", "bone");
  }
  setup();
}

