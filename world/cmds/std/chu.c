// by tianlin 2001.7.3
#include <dbase.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object room,obj;
	int argg;

	seteuid( geteuid(me) );

	if( me->is_busy() ) return notify_fail("你现在没有空！\n");

	if( !arg )
		return notify_fail("指令格式：chu <数量>\n");

	sscanf(arg,"%d",argg);
//拍卖师放置的路径
	if( !(room=find_object("/d/city/center")) )
		room= clone_object("/d/city/center");
	
	if( !(obj=present("paimai shi",room)) )
	{
		obj=new("/d/city/npc/paimaishi");
		obj->move("/d/city/npc/paimaishi");

		return notify_fail("拍卖师现在在十字街头，但没有在拍卖。\n");
	}

	else
	{
		if( !(obj->query("on_paimai")) ) 
			return notify_fail("现在没有在拍卖。\n");
	}

//	if( me->query("id") == obj->query("forbid") )
//		return notify_fail("你现在被禁止参与竞拍。\n");
	
	if( argg <= obj->query("value")*21/20 )
	{
		tell_object(me,"你出价太低。\n");
		return notify_fail("现在是"+chinese_number(obj->query("value"))+"两银子！\n");
	}

	if( argg*105 > me->query("balance") )
		return notify_fail("你没有这么多的存款！\n");

	obj->report_paimai(me,argg,obj->query("number"));
	tell_object(me,"你出价"+chinese_number(argg)+"两银子！\n");

	me->start_busy(2);

	return 1;

}

int help(object me)
{
   write( @HELP
指令格式: chu <数量> 

这一指令让你可以参与投标，单位为 两银子。
HELP
   );
   return 1;
}
 