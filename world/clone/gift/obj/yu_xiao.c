#pragma save_binary
 
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{  
set_name( CYN"玉箫" NOR,({ "yu xiao","sword","jian","xiao","yu","yuxiao" }));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "只");
        set("long","一只晶莹透亮的玉箫。拿在手里。滑腻腻的。上面刻着几个字\n"
					HIM"\t\t盈盈送\n"NOR);
        set("value", 10000);
        set("material", "异类金属");
        set("wield_msg", "$N从怀里摸出一只$n作为武器。\n");
        set("unwield_msg", "$N将手中的$n放入怀里。\n");
        set("owner","令狐冲");
		set("task",1);	
        set("no_put_in",1);
            }
        init_sword(180);
        setup();
}

