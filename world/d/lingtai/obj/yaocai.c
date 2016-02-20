// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// songguo.c

inherit COMBINED_ITEM;

void create()
{
        set_name("药材", ({"yaocai"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一堆珍贵药材．\n");
                set("unit", "堆");
                set("base_unit","斤");
                set("cass","genis");
        }
        set_amount(500);
}
