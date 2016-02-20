#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(HIY "穷极之匙" NOR, ({ "qiongji zhishi","key","yaoshi","qiongjizhishi" }));
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一把能开启穷极魔洞的黑暗之匙. \n");
    set("unit", "把");
    set("material", "gold");
    set("no_give", 1);
  }
  setup();
}

void init ()
{
  call_out ("destruct_me",600,this_object());
}

void destruct_me (object me)
{
  message_vision(HIY "只见一道金光闪过，穷极之匙已飞向九天!\n" NOR,me);
  destruct (me);
}

