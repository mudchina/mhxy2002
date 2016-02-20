#include <armor.h>
#include <ansi.h>
 
inherit SURCOAT;
 
void create()
{
        set_name(HIR"米老鼠内裤"NOR, ({ "lueku"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather");
                set("unit", "条");
                set("long", "一条窄窄的三角内裤,上面锈着一只漂亮的米老鼠和几个字。\n"
"┌■■■    ┌■    ┌■■■┌■┌■┌■■■    ┌■  ■┌■■■┌■  ■\n"
"└┐■      │■    │■  ■│■│■│■─┘    │■  ■│■  ■│■  ■\n"
"  │■      │■    │■  ■│■│■│■■      │■■■│■  ■│■  ■\n"
"┌┘■      │■    │■  ■│■│■│■┘      └┐■  │■  ■│■  ■\n"
"│■■■    │■■■│■■■└┐■  │■■■      │■  │■■■│■■■\n"
"└──┘    └──┘└──┘  └┘  └──┘      └┘  └──┘└──┘\n"NOR);

                set("value", 0);
                set("armor_prop/armor", 1);
set("armor_prop/dodge", 1);
        }
        setup();
}
