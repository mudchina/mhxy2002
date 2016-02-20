//By tianlin@mhxy for 2002.2.1
#include <weapon.h>
#include <ansi.h>
inherit YUMAO;
void create()
{
        set_name(HIM"漫"HIC"天"HIY"飞"HIW"羽"NOR, ({"baiyu yumao", "yumao"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "翎羽雪白无染，长一尺一寸，握于掌中轻若鸿毛.....\n");
                set("value", 5000);
                set("rumor_msg",1);
                set("no_sell",1);
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
                set("is_monitored", 1);
                set("wield_msg","$N小心翼翼的从怀里拿出$n握在手中．翎羽迎风，如诗如梦.\n");
                set("unwield_msg","翎羽飘起，飞入$N的怀中........\n");
                set("weapon_prop/spi", 10);
                set("no_sell","白毫翎羽对小店没什么用途....\n");
              }
        
        init_yumao(100+random(100));
        setup();
}
