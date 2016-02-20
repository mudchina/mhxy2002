#include <armor.h>
#include <armor.h>
#include <ansi.h>
 
inherit SURCOAT;
 
void create()
{
        set_name(HIR"红玫瑰"NOR, ({ "rose"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather");
                set("unit", "朵");
                set("long", "这是一朵红色的玫瑰。\n"
"┌■■■    ┌■    ┌■■■┌■┌■┌■■■    ┌■  ■┌■■■┌■  ■\n"
"└┐■      │■    │■  ■│■│■│■─┘    │■  ■│■  ■│■  ■\n"
"  │■      │■    │■  ■│■│■│■■      │■■■│■  ■│■  ■\n"
"┌┘■      │■    │■  ■│■│■│■┘      └┐■  │■  ■│■  ■\n"
"│■■■    │■■■│■■■└┐■  │■■■      │■  │■■■│■■■\n"
"└──┘    └──┘└──┘  └┘  └──┘      └┘  └──┘└──┘\n"NOR);

                set("value", 0);
                set("armor_prop/armor", 10);
set("armor_prop/dodge", 5);
        }
        setup();
}

