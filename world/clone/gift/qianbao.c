//By tianlin@mhxy for 2002.1.20
//配合story内容制作一个钱包,里面我放了50 gold,hehe

#include <ansi.h>
inherit ITEM;

void create()
{
	int i;
        object a;

        set_name(HIY"钱包"NOR, ({ "qian bao","qianbao","bao" }) );
        set_weight(500);
        set_max_encumbrance(10000);
        if( clonep() )
          {
          seteuid(getuid());
	  for (i=1;i<=50;i++) 	
            {
            a=new("/obj/money/gold");
            a->move(this_object());
            }
          set_default_object(__FILE__);
          }
        else 
          {
          set("unit", "个");
          set("long", "这是白晶晶的钱包,流落人间已经很多年了。\n");
          set("no_give", "这可是宝物啊,你就这么随便给人?\n");
          }
}

int is_container() { return 1; }

