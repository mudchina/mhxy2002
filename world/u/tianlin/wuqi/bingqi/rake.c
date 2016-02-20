//By tianlin@mhxy for 2002.1.2.
#include <ansi.h>
#include <weapon.h>

inherit RAKE;

void create()
{
        set_name(HIM"斗转"HIY"金星"HIC"耙"NOR, ({ "douzhuan pa", "pa","rake","jinxing" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 1000);
                set("rumor_msg",1);
                set("no_sell",1);
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
                set("is_monitored", 1);
                set("material", "iron");
                set("long", HIG"此耙结合北斗七星的精华,七七四十九天炼制而成。\n"NOR);
                set("wield_msg", YEL"$N"NOR+YEL"大喝一声起,只见$n"NOR+YEL"嗖的一声腾空而起,在头上挥舞了一圈。\n"NOR);
        }
        init_rake(100+random(100));
        setup();
}

