// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

// jiudai.c  酒袋

inherit ITEM;
inherit F_LIQUID;
inherit F_AUTOLOAD;

int query_autoload() { return 1; }
void create()
{
   set_name("红塔山", ({"yan"}));
   set_weight(20);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "这是一根来自未来社会任何人都没有见过的香烟,香烟上印着四个小字:终级消愁\n");
     set("unit", "根");
     set("value", 20);
     set("max_liquid", 9000000000);
   }
}
