//By tianlin@mhxy for 2001.9.3.从新设定为了和center相对称
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "长安酒楼");
  set ("long", @LONG

长安历来就是风尘人士汇集之所。这间酒楼处在南来北往的人流中心。就
更加热闹有加。小二托着酒壶，穿梭在桌椅之间。猜拳行令之声、笑骂声、
叱喝声响成一片。也分不清那些是良家百姓、哪些是响马强人。这里真说
得上是龙蛇混杂。成为雇佣士兵的好去处。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"center",
  "west" : "d/city/misc/advise",
  "east" : "d/city/misc/giftroom",
  "up" : __DIR__"changan",
]));
  set("objects", ([ /* sizeof() == 2 */
//  __DIR__"npc/xiaoer" : 1,
]));
  set("no_fight", 1);
  set("no_magic", 1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));
  setup();
}

void init()
{
    add_action("do_zhaomu", "zhaomu");
    add_action("do_money", "yuexiang");
    add_action("do_muji", "muji");
    add_action("do_climb", "climb");
}

int do_zhaomu(string args)
{
  object me=this_player();
if(!args || (args != "soilder"))
return notify_fail("这里只可以募集士兵。其他的大家可是没有兴趣的哦！\n");
if(!me->query("office_number"))
return notify_fail("你还没有做官呢。征兵干啥？相当强盗造反不成？\n");
if(me->query("soilder") >= (me->query("office_number")*10000))
return notify_fail("你手下兵员已经满额，没有多余的指标了。要想多带兵。就去建功立业吧！\n");
message_vision("你彭的一下将酒壶甩在地上。剧烈的响声招来了大家惊异的目光。你清了清喉咙，
大声说道：有没有人跟我去当兵呀？\n",me);
tell_object(me,"你的最大带兵数为："+chinese_number(me->query("office_number"))+"万人。目前缺额:"+chinese_number(
me->query("office_number")*10000 - me->query("soilder"))+". \n");
tell_object(me,"征兵是要以金钱作为本钱的。没有军饷或者军饷太低，是没有人愿意跟你走的。\n
募兵你要先付一年的军饷，以后就不用再花钱了。你要出多少月饷募兵？(最低一两白银)\n");
tell_object(me,"请打出你要给的月饷。\n");
me->set_temp("zhaomu_ing",1);
return 1;
}

int do_money(string arg)
{
 object me=this_player();
 int pts;
if(!me->query_temp("zhaomu_ing")) return notify_fail("你先要引起大家的注意才行.\n");
if( !arg || !sscanf(arg, "%d", pts)) 
return notify_fail("指令格式：yuexiang <每月每个士兵的饷银>\n");
if(me->query("balance")/(1200*pts) < 100) return notify_fail("你的存款太少，还是去设法多赚点钱再来吧！\n");
me->set("soilder_pay",pts);
tell_object(me,"以你目前的财力，可以募兵："+me->query("balance")/(1200*pts)+"人。
实际缺额："+chinese_number(me->query("office_number")*10000 - me->query("soilder"))+" 你要募集多少人?
请用muji <人数> 来决定.\n");
me->delete_temp("zhaomu_ing");
me->set_temp("give_pay",1);
return 1;
}

int do_muji(string arg)
{
object me=this_player();
int pts,train;
if(!me->query_temp("give_pay")) return notify_fail("你不开工资，谁给你白干呀？\n");
if( !arg || !sscanf(arg, "%d", pts)) 
return notify_fail("指令格式：muji <士兵数>\n");
if(pts > (me->query("office_number")*10000 - me->query("soilder")) ) 
return notify_fail("你不能募集多过你最大带兵数的人数。\n");
message_vision("只见人头涌动。这些无事生非之徒纷纷过来报名。你从中挑了一些看上去精壮之人。\n",me);
tell_object(me,"你征召了"+chinese_number(pts)+"名士兵。\n");
me->add("balance",-pts*1200);
train=me->query("train_level")*me->query("soilder")+10*pts;
me->add("soilder",pts);
train=train/(me->query("soilder"));
me->set("train_level",train);   //士兵的训练度。
message("vision",HIY+"【战火纷飞】:"+NOR+HIC+me->query("name")+"在兵营募集了"+chinese_number(pts)+
"名士兵.\n"+NOR,users());
me->delete_temp("give_pay");
return 1;
}
int do_climb(string arg)
{
	object me=this_player();
	
	if( !arg || (arg!="down" && arg!="下树") )
		return notify_fail(HIG"你要爬什么？\n"NOR);
	if(me->is_busy())
		return notify_fail(YEL"你很忙，爬什么呀！\n"NOR);

	message_vision(HIY"$N慢慢的往地面爬去... \n"NOR, me);
	me->start_busy(3);

	if( (int)me->query("kee") < 500 || (int)me->query("sen") < 500) {
		call_out("faila", 3, me);
		return 1;
	}

	call_out("success", 3, me);
	return 1;
}
int success(object me)
{
	message_vision(CYN"$N你慢慢的往下爬,离地面不远了... \n"NOR, me);
	me->move("/d/city/center");
	message_vision(WHT"$N终于爬了下来,真累 !\n"NOR, me);
	return 1;
}
int valid_leave (object who, string dir)
{
  if (dir == "down")
    return notify_fail (HIR"你看了一下,只觉着挺高的,不大敢跳下去,心想还是爬吧。\n"HIG"(climb down)"NOR"\n"NOR);
  return ::valid_leave(who,dir);
}



