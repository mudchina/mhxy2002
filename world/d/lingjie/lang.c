// link
#include <ansi.h>
inherit ROOM;
int do_tiao(string arg);
int do_look(string arg);
int do_dao(string arg);
int do_jia(string arg);
void create()
{
	set("short", HIC"灵界练习地"NOR);
	set("long", @LONG
这里就是灵界供大家练习轻功用的沙池（shachi）了，你可以在这里通过
跳（tiao）沙池来练习你的身法，假如你有沙袋的话，还可以在里面加（jia）
上沙子。不过，这里除了灵界的弟子外谁也不愿来自找麻烦。
LONG
	);
	set("exits", ([ 
  "north" : __DIR__"lingjie7",
  "east" : __DIR__"mdc",
  "west" : __DIR__"pool",
]));
	set("item_desc", ([
	"shachi"  :  "这是一个大沙池，几个人在向沙坑中跳(tiao)去。\n",
	]));
	set("valid_startroom",1);
	set("coor/x",-20);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
}
void init()
{
	object me=this_player();
	add_action("do_tiao", "tiao");
	add_action("do_tiao", "jump");
	add_action("do_jia", "jia");
	add_action("do_dao", "dao");
	add_action("do_look", "look");
	if(me->query_temp("run/circle"))
	call_out("do_run",6,this_player());
}
void do_run(object me)
{
	int i=random(me->query_skill("force")/2);
	if(!me || environment(me) != this_object())
                return;
	tell_object(me,"你深吸一口气，奋力向前跑去……\n");
	me->receive_damage("kee",i);
	if (random(3)>2) {me->improve_skill("move",random(me->query("agi"))/2);}
	me->add_temp("run/circle",-1);
	me->move(__DIR__"pdindoor");
}
int do_tiao(string arg)
{
	object me=this_player();
	int costj=random((int)me->query("con"))+1;
	int costq=random((int)me->query("str"))+1;
	int weight=me->query_temp("shachi/weight");
	if (me->is_busy()) return notify_fail("你现在正忙着呢！\n");
	if (me->is_fighting()) return notify_fail("你正在战斗中，无法专心练功！\n");
	if ( !living(me)) return notify_fail("你发疯了？\n");
	if ( !arg || arg != "shachi" ) return notify_fail("你在沙池里蹦蹦跳跳了半天，别人还以为你发神经！\n");
	if (weight>(me->query("con")+me->query("str"))/5) return notify_fail("你至少还要去掉"+chinese_number(weight-(me->query("con")+me->query("str"))/5)+"公斤的沙才跳得动！\n");
	if ((int)me->query("gin") < costj || (int)me->query("kee") < costq){
		message_vision(RED"$N奋力一跳，结果脚一滑，在沙坑里摔了个狗吃屎！\n"NOR,me);
		me->unconcious();
		return 1;
		}
	else if ((int)me->query_skill("dodge")<20&&random(10)>6||me->query("guild/name")=="运动队"){
	if (weight){
	me->receive_damage("gin", costj+weight/2);
	me->receive_damage("kee", costq+weight/2);
	me->improve_skill("dodge",(int)(me->query("int")/4)+weight/2);
	}
	else {
	me->receive_damage("gin", costj);
	me->receive_damage("kee", costq);
	me->improve_skill("dodge",(int)(me->query("int")/4));
	}
	message_vision("$N奋力助跑，向着沙池跳去！\n", me);
	write(MAG"你的这一跃又有进步，自己觉得自己的基本轻功有了提高！\n"NOR);
	me->start_busy(2);
	return 1;
	}
	return notify_fail("你的水平都这么强了还跳？给点机会给别人吧！\n");
}
int do_jia(string arg)
{
	object me=this_player();
	int weight;
	if (me->is_busy()) return notify_fail("你现在正忙着呢！\n");
	if (me->is_fighting()) return notify_fail("你正在战斗中，无法专心练功！\n");
	if ( !living(me)) return notify_fail("你发疯了？\n");
	if (!present("shadai",me)) return notify_fail("你都没有沙袋，加什么加？\n");
	if (!arg ||sscanf(arg, "%d kilo", weight)!=1) return notify_fail("请指定一个数值，比如jia 10 kilo。\n");
	if (weight <5 )	return notify_fail("增加的重量至少是五公斤！\n");
	me->add_temp("shachi/weight",weight);
	message_vision("$N弯下腰，从沙池里捧出"+chinese_number(weight)+"公斤重的沙子。\n装在沙袋中。\n",me);
	return 1;
}
int do_dao(string arg)
{
	object me=this_player();
	int weight;
	if (me->is_busy()) return notify_fail("你现在正忙着呢！\n");
	if (me->is_fighting()) return notify_fail("你正在战斗中，无暇顾及沙袋的问题！\n");
	if ( !living(me)) return notify_fail("你发疯了？\n");
	if (!present("shadai",me)) return notify_fail("你都没有沙袋，倒什么倒？\n");
	if (!arg ||sscanf(arg, "%d kilo", weight)!=1) return notify_fail("请指定一个数值，比如dao 10 kilo。\n");
	if ( weight <=0 )	return notify_fail("倒掉的重量至少是一公斤！\n");
	if (me->query_temp("shachi/weight")<weight) return notify_fail("开什么玩笑，沙袋里面总共还没有"+chinese_number(weight)+"公斤！\n");
//	write(weight);
	me->add_temp("shachi/weight",-weight);
	message_vision("$N弯下腰，从打开沙袋，从里面倒出了"+chinese_number(weight)+"公斤的沙子。\n",me);
	return 1;
}
int do_look(string arg)
{
	object me=this_player();
	int weight=me->query_temp("shachi/weight");
	if (arg!="shadai") return 0;
	if (weight<=0) return 0;
	write("一个用来跳沙池和绑着跑步的沙袋。\n");
	write("这是个里面装有"+chinese_number(weight)+"公斤沙的沙袋，你带上它应该是想跳（tiao）沙池或者\n把里面的沙倒（dao）掉。\n");
	return 1;
}
int valid_leave(object me, string dir)
{
	if (me->query_temp("shachi")) {
	message_vision(YEL"$N倒掉了所有沙袋中的沙。\n" NOR,me);
	me->delete_temp("shachi");
	return 1;
	}
	else return 1;
}