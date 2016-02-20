#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
set_name(HIR"尸"HIG"血"HIM"神"HIC"兵"NOR, ({"shenbing", "dao"}));
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
set("long", "阿修罗界镇界之宝，传说中的上古神兵。\n");
                set("value", 25);
set("wield_msg", "$N「唰」地一声抽出一把$n握在手中，刹时间天地变色，鬼哭神嚎，$N感觉拥有了无上魔力！\n");
set("unwield_msg", "$N冷哼一声，$n转眼已经不见了。\n");
        set("weapon_prop/courage", 15);
}
        init_blade(160);
        setup();
}
