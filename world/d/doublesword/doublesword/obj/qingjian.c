// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

// blackthorn.c

#include <weapon.h>
inherit SWORD;
#include <ansi.h>

int do_hesword();

void create()
{
       set_name(HIC"青索剑"NOR, ({ "qingsuo-sword","sword"}));
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
  set("long",
"一柄古剑,剑柄上刻有"+HIC"「青索」"NOR+"两字,剑身有一层青气隐隐笼罩.\n");
                set("value", 9000);
                set("material", "gold");
        set("no_drop","这么好的宝物，你去扔 ! 原来吃饱了没事干呀 !!!\n");
        set("no_give","这么好的宝物，给别人? 你入党了没有? \n");
        set("no_sell", 1);
                set("female_only", 1);
set("wield_msg",
HIY"一声凤鸣过后,"HIC"青气"HIY"从天而降,钻入$N左手.\n"NOR);

set("unwield_msg","$N心念方才一动,"+HIC"青索剑"NOR+"便自行飞回鞘中.\n");
        }
    init_sword(180);
        setup();
}
int init()
{
        add_action("do_hesword", "hesword");
        return 1;
}
int do_hesword()
{
        object who = this_player();
        object ziyingjian,qingsuojian;
        object doublesword;
        if(!ziyingjian = present("ziying-sword",who))
           return notify_fail("你还缺少"+HIM "紫郢剑" NOR +",怎么["+HIR"双剑合壁"NOR+"]呢?\n");
        if(!qingsuojian = present("qingsuo-sword",who))
           return notify_fail("你还缺少"+HIC "青索剑" NOR +",怎么["+HIR"双剑合壁"NOR+"]呢?\n");
     if( ! who->query("sword_hesword") == 1 ) 
           return notify_fail("没学双剑合剑之技怎么敢合剑呢?\n");
message_vision("$N轻轻将双剑和体,向上天祈祷 !\n\n突然,一声龙吟过后,"+MAG"紫气"NOR+"自东而来,钻入你右手 \n你心念方才一动,一声凤鸣过后,"+HIC"青气"NOR+"从天而降,钻入你左手\n\n剑身有一层"+HIC"青"NOR+"气与"+MAG"紫"NOR+"气隐隐笼罩.且渐渐融和 !!\n一声轻啸,你手中多出一把"+HBRED"紫青双剑\n\n"NOR,who);
        message("channel:rumor",HIR+"【谣言】某人："+who->query("name")+"拿到 ["+HBRED"紫青双剑"NOR+HIR"] 了！\n"+NOR,users() );
         doublesword = new("/d/obj/weapon/sword/doublesword");
       doublesword->move(who);
        destruct(qingsuojian);
        destruct(ziyingjian);
           return notify_fail("你不由的得意一笑......\n");
        destruct(this_object());
}
