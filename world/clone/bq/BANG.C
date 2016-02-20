#include <weapon.h>
#include <ansi.h>

inherit STICK;

void create()
{
        set_name(HIY "小金箍棒" NOR, ({"xiao jingu bang", "jingubang", "bang", "stick" }));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
		set("no_sell", 1);
		 set("no_drop", 1);
    set("no_get", 1);
       set("no_give", 1);
                  set("value", 0);
                set("material", "steel");
                set("long", "此棒以银为箍，中间乃一段乌铁。上铸小字：“小金箍棒”。\n");
    set("wield_msg", "$N拿起$n，迎风一晃。\n");
    set("unwield_msg", "$N收起$n，$n顿时一闪不见了。\n");

        }
        init_stick(80);
        setup();
}

