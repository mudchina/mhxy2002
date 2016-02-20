//creat by focus

#include <weapon.h>
#include <ansi.h>
inherit YUMAO;
void create()
{
            set_name(HIW"白毫翎羽"NOR, ({"baiyu yumao", "yumao"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "翎羽雪白无染，长一尺一寸，握于掌中轻若鸿毛.....\n");
                set("value", 5000);
 //             set("material", "crimsonsteel");
                set("wield_msg","$N小心翼翼的从怀里拿出$n握在手中．翎羽迎风，如诗如梦.\n");
                set("unwield_msg","翎羽飘起，飞入$N的怀中........\n");
                set("weapon_prop/spi", 10);
                set("no_sell","白毫翎羽对小店没什么用途....\n");
              }
        
            init_yumao(80);
        setup();
}
