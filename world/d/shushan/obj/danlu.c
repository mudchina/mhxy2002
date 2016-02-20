//shushan2 by yushu@SHXY 2000.12
inherit ITEM;
void create()
{
  set_name("金丹炉", ({ "jin danlu", "danlu" }) );
  set_weight(300000);
  set_max_encumbrance(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "鼎");
    set("long", "这是一鼎道家用来炼丹的大金炉。\n");
    set("value", 2000);
  }
}
