//By tianlin@Mhxy for 2002.1.7

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
	object room,ob;
	mapping baobiao_path;
	int value,number;

	if(me->is_busy()) return notify_fail("你上一个动作还没有完成！\n");
	room=environment(me);
        message_vision("$N在地上掘了一个大坑,什么也没找到,只好把坑又填平了!\n",me);
        me->receive_damage("kee",random(10)+5);
        me->start_busy(3+random(3));
	if( !(baobiao_path=room->query("dig_money")) ) return 1;
	if( !mapp(baobiao_path) || random(4) ) return 1;

	if(!(value=baobiao_path["value"])) return 1;
	if(!(number=baobiao_path["number"])) return 1;
	room->delete("dig_money");	

	ob=new("/obj/money/gold");
	if(!ob) return 1;
	message("channel:chat",HIR"【寻宝精灵】某人："+"据说"+me->query("name")+HIR"找到了财神爷藏在人间的宝贝。\n"NOR,users());
	message_vision(CYN"突然，火星四射，被$N挖到了一罐财宝！仔细一看，竟然是"+chinese_number(value)+"两黄金！\n"NOR,me);
	ob->set_amount(value);
	"/adm/daemons/moneyd"->del_log(""+number);
	ob->move(room);
	return 1;
}
