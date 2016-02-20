#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIG "陷仙剑" NOR, ({ "xianxian jian", "jian", "sword", "xianxian" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "陷仙剑\n");
                set("value", 0);
                set("material", "purplegold");
                set("sheenness", 50);
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }

        init_sword(100);
        setup();

}
 
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        int damm;
        pro = (int) victim->query_temp("apply/armor_vs_spells");
        dam = (int) me->query("force");

        damm = (int) me->query("force_factor");
        if(dam > pro)
        {
        victim->receive_damage("kee",damm);
        return HIR "陷仙剑一闪。\n" NOR;
        }
}

