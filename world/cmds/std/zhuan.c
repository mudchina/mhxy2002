// open.c

#include <room.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	int exp, pot, tpot,pot_cost;
            if( !arg
        ||      !sscanf(arg, "%d", pot_cost) )
                return notify_fail("你要花多少潜能修道？\n");

	tpot = (int) me->query("potential");
	pot = (int) me->query("potential")- (int) me->query("learned_points");
	exp = (int) me->query("combat_exp");
  if( pot < pot_cost )
                return notify_fail("你现在的潜能太少了，无法产生令你自己满意的效果。\n");
  else 
   //    if (pot_cost<-exp/2)
     if (pot_cost<0)
        return notify_fail("你无法这样转换潜能！！\n");
   else	
        exp = exp+pot_cost * 1;
	me->set("combat_exp",exp );
	me->set("potential", tpot-pot_cost);	
	write("ＯＫ,就原了你的愿望吧!\n");
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : transfer
 
这个指令可以让你将潜能转为经验（１：１）,
也就是1000点潜能可以转1000点武学
 
HELP
    );
    return 1;
}
