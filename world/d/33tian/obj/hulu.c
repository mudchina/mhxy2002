// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// hulu.c 

inherit ITEM;
void create()
{
   set_name("紫玉葫芦", ({"hulu", "hu"}));
   set_weight(700);
   set_max_encumbrance(100000000);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "太上老君用来盛放丹药的葫芦,由采自极北之处的紫玉制成.\n");
     set("unit", "个");
     set("value", 100);
     set("no_sell", 1);
     set("no_give", 1);
     set("no_drop", 1);
     set("no_put", 1);
   }
    setup();
}
  int is_container()
{ 
  return 1;
}
  void init()
{
  object me = this_object();
  object dan = new("/d/obj/drug/lihen");
  dan->move(me);
}
