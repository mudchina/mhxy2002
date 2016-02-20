// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
//int do_hesword();

void create()
{
        set_name(MAG"紫郢剑"NOR, ({ "ziying-sword","sword","jian"})
);
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "对");
                set("unit", "柄");
  set("long",
"一柄古剑,剑柄上刻有"+MAG"「紫郢」"NOR+"两字,剑身有一层紫气隐隐笼罩.\n");
                set("value", 9000);
//        set("no_give","这么好的宝物，给别人? 你入党了没有? \n");
        set("no_drop","这么好的宝物，你去扔 ! 原来吃饱了没事干呀 !!!\n");
        set("no_sell", 1);
                set("material", "blacksteel");
set("wield_msg",
MAG"$N右手微张，一声龙吟过后,紫气自东而来,钻入$N右手.\n");

set("unwield_msg","$N右肩轻摇,"+MAG"紫郢剑"NOR+"便自行飞回鞘中.\n");
        }
    init_sword(100);
        setup();
}
/*
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

        if(who->is_fighting())
           return notify_fail("你正打仗呢！想死啊！\n");
        if(who->is_busy())
           return notify_fail("你还有这工夫?正忙着呢!\n");
        if(!ziyingjian = present("ziying-sword",who))
           return notify_fail("你还缺少"+HIM "紫郢剑" NOR +",怎么["+HIR"双剑合壁"NOR+"]呢?\n");
        if(!qingsuojian = present("qingsuo-sword",who))
           return notify_fail("你还缺少"+HIC "青索剑" NOR +",怎么["+HIR"双剑合壁"NOR+"]呢?\n");
 //    if( ! who->query("sword_hesword") == 1 ) 
 //          return notify_fail("没学双剑合剑之技怎么敢合剑呢?\n");
message_vision("$N轻轻将双剑和体,向上天祈祷 !\n\n突然,一声龙吟过后,"+MAG"紫气"NOR+"自东而来,钻入你右手 \n你心念方才一动,一声凤鸣过后,"+HIC"青气"NOR+"从天而降,钻入你左手\n\n剑身有一层"+HIC"青"NOR+"气与"+MAG"紫"NOR+"气隐隐笼罩.且渐渐融和 
!!\n一声轻啸,你手?.多出一把"+HBRED"紫青双剑\n\n"NOR,who);
        message("channel:rumor",HIM+"【谣言】某人：听说"+who->query("name")+"在"HIW+MISC_D->find_place(environment(this_player()))+HIM"拿到 ["+HBRED"紫青双剑"NOR+HIR"] 了！\n"+NOR,users() );
//      tell_object(who,"你不由得微微一笑......\n");
         doublesword = new("/d/obj/weapon/sword/doublesword");
       doublesword->move(who);
        destruct(qingsuojian);
        destruct(this_object());
        return 1;
}
 
*/