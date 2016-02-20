
inherit ITEM;

void create()
{
        set_name("百宝袋", ({ "bag" }) );
        set_weight(0);
        set_max_encumbrance(8000000);
                set_max_items(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("long", "一个天界才有的百宝袋。\n");
                set("value", 50000);
        }
}

int is_container() { return 1; }


