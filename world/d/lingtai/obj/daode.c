// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;

#include <ansi.h>

int do_read(string arg);
void create()
{
  set_name("道德经", ({"daode jing","dade","book"}));
  set_weight(200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "本");
    set("value", 100);
    set("no_sell", 1);
    set("long", " 这是一本老子道德经，请用 read 阅读。\n");
    set("material", "paper");
  }
}

void init()
{
  add_action("do_read", "read");
}

int do_read(string arg)
{
  object me = this_player();
  string content;
  
  content=read_file("/d/lingtai/npc/laozi.txt");
  me->start_more(content);
  return 1;
}

