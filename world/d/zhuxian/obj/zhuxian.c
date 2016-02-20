#include <ansi.h>
#include <weapon.h>
inherit SWORD;
int do_hejian();
void create()
{
        set_name( HIR "诛仙剑" NOR, ({ "zhuxian jian", "jian", "sword", "zhuxian"}) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",

"诛仙剑\n"
);
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
        pro = (int) victim->query_temp("apply/armor_vs_spells");
        dam = (int) me->query("force");

        if(dam > pro)
        {
        victim->receive_damage("sen",150);
        return HIR "诛仙剑闪出妖异的红光。\n" NOR;
        }
}

int init()
{       
        add_action("do_hejian", "hesword");
        return 1;
}
int do_hejian()
{
        object xianxian,juexian,luxian;
        object me = this_player();
        object wuchen;

        if(me->is_fighting())
           return notify_fail("你正打仗呢！想死啊！\n");
        if(me->is_busy())
           return notify_fail("你正忙着呢!\n");
        if ("/d/zhuxian/obj/wuchen.c"->in_mud())
           return notify_fail("你拿着这四把剑反复研究怎么也觉着合并不到一起去!\n");
        if(!xianxian = present("xianxian",me))
           return notify_fail("你还缺少"HIG"陷仙剑"NOR"呢！\n");
        if(!juexian = present("juexian",me))
           return notify_fail("你还缺少"HIW"绝仙剑"NOR"呢！\n");
        if(!luxian = present("luxian",me))
           return notify_fail("你还缺少"HIC"戮仙剑"NOR"呢！\n");
if ((xianxian->query("equipped")!="worn") && (juexian->query("equipped")!="worn") && (luxian->query("equipped")!="worn") && (this_object()->query("equipped")!="worn"))
{        
        message_vision(HIY"$N运足全身的"HIC"内力"HIY"把这四把宝剑和为了一柄利剑，仔细一看原来是失传很久的"HIW"无尘剑"NOR+HIY"！\n",me);

        message("channel:rumor",HIW+"【"HIR"十绝大阵"NOR+HIW"】"HIM"某人："NOR+YEL+me->query("name")+CYN"得到了传说中的"HIW"无尘剑"NOR+CYN"！\n"+NOR,users() );
        
        wuchen = new("/d/zhuxian/obj/wuchen.c");
        wuchen->move(me);
        destruct(xianxian);
        destruct(juexian);
        destruct(luxian);
        destruct(this_object());
        return 1;
}
return notify_fail("你必须放心武器才能合并！\n");
}
