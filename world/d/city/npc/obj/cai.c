// 侠客行100海洋版II
// panzi.c 洗好的盘子
// 星星lywin 2000/6/1 儿童节
#include <ansi.h>
inherit ITEM;
void create()
 {
 set_name( "各种各样的菜" , ({"cai"}));
set("value",200);
set_weight(3);
if (clonep()) 
set_default_object(__FILE__);
else {                 set("unit", "把");
set("long", "一把各种各样的菜。\n");
 }         setup();
 }
