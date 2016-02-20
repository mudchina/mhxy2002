// yuyi.c

inherit EQUIP;

void create()
{
        set_name("Ìì²õÓðÒÂ", ({"cloth", "yuyi"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("value", 50000);
 //               set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/armor", 80);
                set("armor_prop/spells", 20);
             }
}
