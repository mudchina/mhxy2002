//By tianlin@mhxy for 2002.2.10,为大年30做礼物
#include <ansi.h>
inherit ITEM;

void create()
{
        object a,b,c,d,e,f,g,h,i;

        set_name(HIR"新年礼物大礼包"NOR, ({ "gift bag", "bag", "giftbag" ,"gift" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        if( clonep() )
          {
          seteuid(getuid());
          a=new("/u/tianlin/wiz/m.c");
          a->move(this_object());
          b=new("/d/obj/drug/xianjiu.c");
          b->move(this_object());
          e=new("/u/tianlin/obj/jiaozi.c");
          e->move(this_object());
          f=new("/u/tianlin/wiz/book.c");
          f->move(this_object());
          g=new("/u/tianlin/obj/gift.c");
          g->move(this_object());
          h=new("/u/tianlin/clone/jinjia.c");
          h->move(this_object());
          i=new("/u/tianlin/clone/bing.c");
          i->move(this_object());
          set_default_object(__FILE__);
          }
        else 
          {
          set("unit", "个");
          set("long", "一个奇怪的布袋。\n");
          set("no_give", 1);
          }
}

int is_container() { return 1; }
