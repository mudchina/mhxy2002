// yuchangjian.c 
//create by lixin
#include <weapon.h>
#include <ansi.h>
inherit STAFF;
//inherit F_UNIQUE; 

void create()
{
        set_name(BLINK HIW"普渡" NOR+HIC "杖" NOR, ({"pudu zhang", "zhang", "staff"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "我佛慈悲，普渡众生。\n");
                set("value", 0);
                set("no_sell",1);
                set("no_give",1);
                set("no_drop",1);
                set("no_get",1);
                set("material", "steel");
                set("is_monitored", 1);
                set("wield_msg", YEL "阿弥陀佛，一声佛号化为普渡众生落在$N手里，$N眼出发出柔和的光茫，如同佛祖化身。\n" NOR);
                set("unwield_msg",YEL "$N身上的佛光慢慢消退了，$n"+YEL"也化为一道光茫直奔西方。\n");
               set("value", 300000); 
               set("weapon_prop/cor", 1);
}
        init_staff(120);
        setup();
}
