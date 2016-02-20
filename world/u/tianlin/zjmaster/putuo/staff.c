//By tianlin@mhxy for 2002.1.23

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
        set_name(HIY"佛"HIW"光"NOR+HIW"圣"HIY"杖"NOR, ({"foguang shengzhang", "shengzhang", "zhang", "staff"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一根如来佛随身的圣杖,此杖曾经流落人间过。\n");
                set("value", 0);
                set("no_sell",1);
                set("no_give",1);
                set("no_drop",1);
                set("material", "steel");
                set("is_monitored", 1);
                set("wield_msg", HIW "$N刷的一声举起了一个千万吨重的$n"NOR+HIW"，在手中挥舞了半天。\n" NOR);
                set("unwield_msg",HIW "$N身上的佛光慢慢消退了，$n"+HIW"也化为一道光茫直奔西方。\n");
               set("value", 300000); 
               set("weapon_prop/cor", 1);
}
        init_staff(180);
        setup();
}
