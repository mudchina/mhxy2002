//By tianlin@mhxy for 2002.1.2.
#include <ansi.h>
#include <weapon.h>

inherit SPEAR;

void create()
{
            set_name(WHT "雷霆"YEL"霸王枪" NOR, ({ "leiting spear","qiang", "leiting", "spear"}));
            set_weight(14000);
       if( clonep() )
            set_default_object(__FILE__);
       else {
            set("unit", "杆");
            set("value", 120000);
            set("rumor_msg",1);
            set("no_sell",1);
            set("no_get",1);
            set("no_give",1);
            set("no_drop",1);
            set("is_monitored", 1);
            set("material", "gold");
            set("long", HIY"这是一杆从天庭移落下来的一杆神枪。\n"NOR);
            set("wield_msg", CYN"$N狂笑一声，反手从自己的胸口拔出了沾满鲜血的"NOR"$n "CYN" ！\n"NOR);
            set("unwield_msg", CYN"$N面露痛苦之色，将"NOR"$n"CYN"转了几转，往自己心口插下直至末柄！\n"NOR);
  }
    init_spear(100+random(100));
    setup();
}

