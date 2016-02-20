//by tianlin@mhxy 部分优化 for 2001.8.11
#include <ansi.h>

void over(object,object);

int main(object me, string arg)
{
        object obj, old_target;
        object *ob,*inv;

        int i,j;

        if(!arg || !objectp(obj = present(arg, environment(me))))
                return notify_fail("你想和谁做爱？\n");


        if( !obj->is_character()||me->query("gender")==obj->query("gender") )
                return notify_fail("这样...?!恐怕不行吧?\n");

        if(!living(obj))
                return notify_fail("人家都这样了，你还...\n");

//by darksnow 5.27
  //      if(!me->query("married") ||me->query("couple/id")!=arg )
         //        return notify_fail("对方不是你的伴侣,你这样是违法的。\n");


        if( !environment(me)->query("sleep_room")||
                 environment(me)->query("no_sleep_room"))
                return notify_fail("总得找个温馨点儿的地方吧。\n");

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++)
                if( ob[i]->is_character()&&ob[i]!=me
                        &&ob[i]!=obj&&!wizardp(ob[i]) )
                        return notify_fail("这儿还有别人呢，多不好意思呀！\n");
        if(!me->query_temp("makelove/quest"))
        {

            if((me->query("gender")=="男性"))
                {
                   message_vision(HIM "$N轻轻来到$n身后，双手环抱在$n的腰间,
在$n耳边柔声说道：亲爱的，今晚...\n"NOR,me,obj);
                tell_object(obj, HIR "傻子也能看出来他想和你共渡良宵,
如果你愿意，请你也对" + me->name() + "("+(string)me->query("id")+")"+ "下一次 ma
kelove 指令。\n" NOR);
                }
            else
                {
                        message_vision(HIM "不知是因为烛光，还是酒精，亦或是因为兴奋，$N的小脸儿红红的，
端着酒杯,$N直勾勾地盯着$n:亲爱的...听说...喝酒...乱性...\n"NOR,me,obj);
                tell_object(obj, HIR "傻子也能看出来她想和你共渡良宵，
如果你愿意，请你也对" + me->name() + "("+(string)me->query("id")+")"+ "下一次 ma
kelove 指令。\n" NOR);
                }
                obj->set_temp("makelove/quest",1);

        }
        else
        {
            if((me->query("gender")=="男性"))
                {
                        message_vision(HIM "$N回敬似的盯着$n的眼睛，半晌一言不发，突然一把抱住$n,一双热唇堵住了$n的嘴，
让$n简直喘不上来气，酒杯、红烛打了一地...\n"NOR,me,obj);
                call_out("over", 1, me,obj);
                }
                else
                {
                        message_vision(HIM "$n甚至能看见$N羞红的耳根，$N轻轻挣开$n的怀抱，
默默地焚香沐浴，$n却再也忍不住，一把将$N抱了起来...\n"NOR,me,obj);
                call_out("over", 1, obj,me);
                }
                me->delete_temp("makelove/quest");
        }


        return 1;
}


void over(object me,object obj)
{
        message_vision(HIR"...一阵疾风骤雨\n"NOR,me);
        if(me->query("kee")<30||me->query("sen")<30||obj->query("kee")<30||obj->query("sen")<30)
        {
                if(me->query("kee")<30||me->query("sen")<30)
                {
                    message_vision(HIR "$N突然口吐鲜血，晕倒在地。看来是纵欲过度了."NOR,me);
                    me->unconcious();
                }
                else
                {
                    message_vision(HIR "$N突然口吐鲜血，晕倒在地。看来是纵欲过度了."NOR,obj);
                    obj->unconcious();
                }
        }
        else
        switch(random(10))
        {
        case 0:
                message_vision(HIR "$N突然大叫一声，显然是极度兴奋，紧接着竟晕死
过去！\n"NOR,me);
                me->unconcious();
                obj->add("kee",obj->query_str()-55+random(10));
                obj->add("sen",obj->query_con()-55+random(10));
                break;
        case 1:
                message_vision(HIR "$N突然大叫一声，显然是极度兴奋，紧接着竟晕死
过去！\n"NOR,obj);
                obj->unconcious();
                me->add("kee",obj->query_str()-55+random(10));
                me->add("sen",obj->query_con()-55+random(10));
                break;
        default:
                if(random(1))
                {
                        message_vision(YEL "$N坐在一旁闷头不语，望了一眼仍在微微娇喘的$n,
喃喃说到：要不然...再让我试一次...\n"NOR,me,obj);
                }
                else
                {
                        message_vision(HIY "$n静静地躺在$N的怀里，靠着那起伏的胸膛，
听着那均匀的呼吸，感到无限的幸福...\n"NOR,me,obj);
                }
                obj->add("kee",obj->query_str()-55+random(10));
                obj->add("sen",obj->query_con()-55+random(10));
                me->add("kee",obj->query_str()-55+random(10));
                me->add("sen",obj->query_con()-55+random(10));
        }


}

int help(object me)
{
  write(@HELP
指令格式 : makelove <人物>
做爱！
相关知识参看初中《生理卫生》课本

HELP
    );
    return 1;
}

