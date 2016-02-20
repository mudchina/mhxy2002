#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void init()
{
  cloth::init();
}
void create()
{
              set_name(HIB"超短裙"NOR, ({"chao duan qun", "skirt","qun" }) );
          set("long", "一条短的不能再短的裙子。\n");
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                  set("unit", "条");
                  set("material", "lamp");
                set("female_only", 1);
                  set("armor_prop/armor", 20);
                set("armor_prop/personality", 10);
                set("value", 0);
        }
        setup();
}
