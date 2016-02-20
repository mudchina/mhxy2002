// full.c
#include "/doc/help.h"
#include "ansi.h"
inherit F_CLEAN_UP;
int main(object ob,string arg)
{
        object me,obj;
        int force, mana;
        int jin, qi, neili, fali, shiwu, yinshui;
     if (!arg)  me = ob;
     else
      {
        me = present(arg, environment(ob));
        if (!me) me =  find_player(arg);
        if (!me) return notify_fail("你要恢复谁的状态？\n");
      }
		log_file("static/full",
			sprintf("%s(%s) full %s(%s) 时间 %s\n",
				ob->name(1), geteuid(ob), me->name(1), geteuid(me),ctime(time()) ) );
/*	        if (!wizardp(me)){
	message("channel:rumor",HIM"【谣言】某人："+"据说"+ob->query("name")+"恢复了 "HIW+me->query("name")+HIM" 的个人身体。\n"NOR,users());
	        }*/
       force = (int)me->query("max_force");
       mana  = (int)me->query("max_mana");
       me->set("eff_kee",me->query("max_kee"));
       me->set("kee",me->query("max_kee"));
       me->set("eff_gin",me->query("max_gin"));
       me->set("gin",me->query("max_gin"));
       me->set("eff_sen",me->query("max_sen"));
       me->set("sen",me->query("max_sen"));
       me->set("force",force*2);
       me->set("mana",mana*2);
       me->set("food",me->max_water_capacity()*3);
       me->set("water",me->max_food_capacity()*3);
       write("Ok.\n");
       ob->clear_condition();
//       ob->reincarnate();
     return 1;
}
int help()
{
       write( @TEXT
指令格式：full
这个指令让你加满精气神。
TEXT
       );
       return 1 ;
}
