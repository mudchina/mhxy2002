#include <ansi.h>
#include <weapon.h>
inherit STICK;
inherit F_UNIQUE;

void create()
{
        set_name(HIW"真武大棍"NOR, ({"zhenwu gun", "stick", "bang"}));
        set_weight(15000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把毫不起眼的大棍,棍身不规则的花纹上似乎还带有些铁锈,边缘上居然还有几个缺口。\n");
                set("value", 0);
                set("unique", 1);
                set("rigidity", 5);
                set("no_give", "这是你的心血啊怎么能轻易送人呢?\n");
                set("sharpness", 9); 
                set("material", "blacksteel");
                set("weapon_prop/dodge", -2);
                set("weapon_prop/parry", 3);
                set("treasure",1);       
                set("wield_force", 300);
                set("wield_maxforce", 700);
                set("wield_str", 22);        
                set("skill", ([
                        "name": "sword",
                        "exp_required": 500000,
                        "difficulty": 25,
                        "min_skill": 100,
                        "max_skill": 150,                       
                ]) );
                set("wield_msg",HIW"$N[噌]的一声抽出一根真武大棍,空气中顿时充满了无边的杀气。\n"NOR);
                set("unwield_msg",HIW"$N把手中的真武大棍插入腰间。四周的杀气也跟着消失了。\n"NOR);
}
        init_stick(100);
        setup();
} 