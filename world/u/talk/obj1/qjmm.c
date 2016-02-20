// keeangjian.c

#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
     object obj;// where = environment(me);
    int oexp,mexp;
    seteuid(getuid());

//    if (environment(me)->query("no_steal")||environment(me)->query("no_fight"))
//         return notify_fail("光天化日之下，你想干嘛？\n");

    if (!arg || !objectp(obj = present(arg, environment(me))))
         return notify_fail("你现在很冲动，可是一点辙都没有。\n");

    if (me->query("gender") =="无性")
         return notify_fail("你连那个工具都没有，还想干好事？\n");

    if (me->query("gender") =="女性")
         return notify_fail("哇！现在女人也想强奸别人了，太可怕了！\n");

    if (me->query("age") < 17)
         return notify_fail("你连十七岁都没到，就学坏啊！\n");

    if (obj==me) return notify_fail("自己强奸自己？好象做不到嘛。\n");

    if (obj->query("gender") != "女性")
         return notify_fail("不对吧。他好象不是女人吧。\n");

    if (obj->query("age") < 10)
         return notify_fail("人家还是幼女啊！\n");

    if (!obj->is_character()) return notify_fail("哇，死的东西都不放过！\n");

    if (!living(obj) )
         return notify_fail(obj->name() + "立马被强奸了。好可怜！\n");

    if( !wizardp(me) && wizardp(obj) )
         return notify_fail("强奸巫师？你不怕杀档？\n");

    if( me->is_fighting() )
         return notify_fail("一边打架一边色迷迷？你真是活腻了！\n");

    if( obj->is_fighting() ) 
         return notify_fail(obj->name() + "正在打架，你不怕被阉？\n");

    tell_object(me,"你色胆横生，一把向" + obj->name() + "扑过去，伸手便要去扯"
             + obj->query("name") + "的衣服！\n\n");
    tell_object(obj,me->name()+"凶巴巴地扑了过来，伸手就想扯脱你的衣服！\n\n");
    message("vision", "只见" + me->name() + "恶狠狠地扑向"+obj->name()
            + "一把抓住她的衣服！\n\n\n", environment(me), ({ me,obj }) );
    oexp=obj->query("daoxing");
    mexp=me->query("daoxing");

    if ((mexp<oexp)||(random(2))==1)
    {
      tell_object(me, HIR "糟糕！你惹错人了！\n\n" NOR);
      message_vision("$N粉脸一板，冲着$n大喝道：「大色狼！」\n", obj, me);
      if( userp(obj) ) obj->fight_ob(me);
      else obj->kill_ob(me);
      me->fight_ob(obj);
      me->start_busy(3);
    }
    else 
    {
      message_vision("$N被按到在地，大声呼救：有色狼！拼命挣扎。\n",obj,me);
      message_vision("$n一脸坏笑，继续着$n的下个动作。\n",obj,me);
      message_vision("悲惨的事终于发生在$N的身上了。\n",obj,me);
 CHANNEL_D->do_channel(this_object(),"rumor","据说"HIR+me->name()+HIM"把"HIY+obj->name()+HIM"给强奸了。");
      me->set("kee",me->query("eff_kee"));
      me->set("force",me->query("max_force"));
      me->add("daoxing",2);
      me->add("sen",-1000);
      me->add("max_atman",1);
      obj->add("max_atman",1);
//      me->set("couple/have_couple",1);
      me->start_busy(3);
      obj->add("eff_gin",-5);
    }
    return 1;
}

int help(object me)
{
write(@HELP
指令格式 : rape | keeangjian <某人>

HELP
    );
    return 1;
}


