// link /2001/2/13
#define KICK_TO	"/d/city/kezhan"
#include <ansi.h>

inherit ROOM;

int do_sit(string arg);
int do_stand();
int do_order(string arg);
int do_eat(string arg);
int do_drink(string arg);
int do_pay();
int do_buy();
int do_quit();
string look_sign();
string look_table();
void quarter_pass();

mapping *food = ({
([	"name" : "薯条",
	"unit" : "包",
	"short" : "xshutiao",
	"value" : 10,
	"time" : "早",
	"remaining" : 1,
	"supply" : 30
]),
([	"name" : "麦香鸡汉堡",
	"unit" : "个",
	"short" : "mxjhbg",
	"value" : 30,
	"time" : "早",
	"remaining" : 2,
	"supply" : 30
]),
([	"name" : "猪肉汉堡",
	"unit" : "个",
	"short" : "jshbg",
	"value" : 40,
	"time" : "午",
	"remaining" : 4,
	"supply" : 30
]),
([	"name" : "巨无霸汉堡",
	"unit" : "个",
	"short" : "jwbhbg",
	"value" : 120,
	"time" : "午",
	"remaining" : 6,
	"supply" : 50
]),
([	"name" : "麦乐鸡",
	"unit" : "份",
	"short" : "liyu",
	"value" : 90,
	"time" : "午",
	"remaining" : 9,
	"supply" : 50
]),
([	"name" : "巨无霸汉堡",
	"unit" : "个",
	"short" : "jwbhbg",
	"value" : 120,
	"time" : "晚",
	"remaining" : 4,
	"supply" : 50
]),
([	"name" : "麦辣鸡翅",
	"unit" : "份",
	"short" : "mljc",
	"value" : 100,
	"time" : "晚",
	"remaining" : 6,
	"supply" : 50
]),
([	"name" : "麦香鱼汉堡",
	"unit" : "个",
	"short" : "mxyhbg",
	"value" : 90,
	"time" : "晚",
	"remaining" : 9,
	"supply" : 50
]),
([	"name" : "大包薯条",
	"unit" : "袋",
	"short" : "shutiao",
	"value" : 100,
	"time" : "晚",
	"remaining" : 8,
	"supply" : 60
])
});

mapping *liquid = ({
([	"name" : "小可乐",
	"unit" : "杯",
	"short" : "xkele",
	"value" : 10,
	"time" : "早",
	"remaining" : 2,
	"supply" : 12
]),
([	"name" : "中可乐",
	"unit" : "杯",
	"short" : "zkele",
	"value" : 16,
	"time" : "早",
	"remaining" : 2,
	"supply" : 18
]),
([	"name" : "小可乐",
	"unit" : "杯",
	"short" : "xizhou",
	"value" : 16,
	"time" : "午",
	"remaining" : 2,
	"supply" : 18
]),
([	"name" : "中可乐",
	"unit" : "杯",
	"short" : "zkele",
	"value" : 50,
	"time" : "午",
	"remaining" : 7,
	"supply" : 40
]),
([	"name" : "大可乐",
	"unit" : "杯",
	"short" : "dkele",
	"value" : 70,
	"time" : "午",
	"remaining" : 8,
	"supply" : 24
]),
([	"name" : "玉米粥",
	"unit" : "杯",
	"short" : "ymzhou",
	"value" : 16,
	"time" : "晚",
	"remaining" : 2,
	"supply" : 18
]),
([	"name" : "中可乐",
	"unit" : "坛",
	"short" : "zkele",
	"value" : 50,
	"time" : "晚",
	"remaining" : 7,
	"supply" : 40
]),
([	"name" : "大可乐",
	"unit" : "杯",
	"short" : "dkele",
	"value" : 70,
	"time" : "晚",
	"remaining" : 8,
	"supply" : 24
]),
([	"name" : "玉米粥",
	"unit" : "杯",
	"short" : "ymzhou",
	"value" : 90,
	"time" : "晚",
	"remaining" : 8,
	"supply" : 28
])
});

void create()
{
	set("short", HIY"麦当劳餐厅"NOR);
	set("long", @LONG
麦当劳餐厅是灵界卖快餐的地方，但是最近不知是人手不足还是怎样，竟然非
用餐时间不卖吃的了，你要吃东西可得找准时间，这里的东西虽然好吃，可是
贵也是太贵，即便如此，来这里吃东西的也是络绎不绝，看来后面出访的人手
不太够，你要是想勤工俭学，不妨去看看有没有活干，大厅内一溜摆着几排桌
子(table)，四周放着些椅子(chair)。两个服务员正在忙个不停。柜台上立
着一个价目表(sign)。
LONG
	);
	set("valid_startroom",1);
	set("exits", ([
		"east" : KICK_TO,
		"west" : __DIR__"lang",
                "north" : __DIR__"hguitai",
	]));

	set("item_desc", ([
		"sign" : (: look_sign :),
		"table" : (: look_table :),
		"chair" : "木制的坐椅，看起来好象很结实。\n",
	]) );

	set("objects", ([
		__DIR__"npc/fuwu" : 1,
		__DIR__"npc/fuwu2" : 1,
		__DIR__"npc/fuwu3" : 1,
	]));
	set("coor/x",-40);
	set("coor/y",140);
	set("coor/z",0);
	setup();
	quarter_pass();
}

void init()
{
	add_action("do_quit", "quit");
	add_action("do_buy", "buy");
	add_action("do_pay", "pay");
	add_action("do_pay", "jiezhang");
	add_action("do_eat", "eat");
	add_action("do_eat", "chi");
	add_action("do_drink", "drink");
	add_action("do_drink", "he");
	add_action("do_order", "order");
	add_action("do_order", "dian");
	add_action("do_stand", "stand");
	add_action("do_stand", "zhan");
	add_action("do_sit", "sit");
	add_action("do_sit", "zuo");
}

void kick_all()
{
	object *ob;
	int i, pay;

	set_temp("serve", "无");
	tell_room(this_object(), "服务员略带歉意的告诉你：“对不起，现在是下班时间。”\n", ({}));
	ob = all_inventory(this_object());
	for(i = 0; i < sizeof(ob); i++) {
		if (userp(ob[i])) {
			if (pay = ob[i]->query_temp("total_pay")) {
				message_vision("服务员对$N喝道：“付帐走人！”\n", ob[i]);
				if (!ob[i]->query_temp("to_pay")) {
					message_vision("服务员把$N从座位上拽了起来，拉到柜台前。\n", ob[i]);
					message_vision("服务员翻出菜单，敲打了一阵键盘后告诉$N：“一共" + chinese_number(pay) + "分钱。”\n", ob[i]);
					ob[i]->delete_temp("marks/sit");
					ob[i]->set_temp("to_pay", 1);
				}
			}
			else {
				if (!living(ob[i])) message_vision("服务员把$N扔出了餐厅。\n", ob[i]);
				else message_vision("服务员把$N推出了餐厅。\n", ob[i]);
				ob[i]->delete_temp("marks/sit");
				ob[i]->delete_temp("cai_count");
				ob[i]->delete_temp("cai_1");
				ob[i]->delete_temp("cai_2");
				ob[i]->delete_temp("cai_3");
				ob[i]->delete_temp("cai_4");
				ob[i]->delete_temp("cai_5");
				ob[i]->move(KICK_TO);
				if (!living(ob[i])) tell_room(KICK_TO, ob[i]->name() + "被扔出了餐厅。\n", ({ob[i]}));
				else tell_room(KICK_TO, ob[i]->name() + "被推出了餐厅。\n", ({ob[i]}));
			}
		}
	}
}

void quarter_pass()
{
	mixed *local;
	object *ob;
	int i, paytime;

	local = localtime(time() * 60);
	if (local[2] < 6) kick_all();
	else if (local[2] < 9) set_temp("serve", "早");
	else if (local[2] < 11) set_temp("serve", "无");
	else if (local[2] < 14) set_temp("serve", "午");
	else if (local[2] < 17) set_temp("serve", "无");
	else if (local[2] < 21) set_temp("serve", "晚");
	else kick_all();
	ob = all_inventory(this_object());
	for(i = 0; i < sizeof(ob); i++) {
		if (paytime = ob[i]->query_temp("to_pay")) {
			paytime++;
			if (paytime == 6 && ob[i]->query_temp("total_pay")) {
				message_vision("服务员对$N大喝一声：“怎么还不付帐？！想吃霸王餐啊！”\n", ob[i]);
				message_vision("服务员叫来几个大汉，指着$N说：“给我打！”\n", ob[i]);
				message_vision("大汉们围住$N，乱拳齐下。\n", ob[i]);
				ob[i]->delete_temp("total_pay");
				ob[i]->delete_temp("to_pay");
				ob[i]->delete_temp("cai_count");
				ob[i]->delete_temp("cai_1");
				ob[i]->delete_temp("cai_2");
				ob[i]->delete_temp("cai_3");
				ob[i]->delete_temp("cai_4");
				ob[i]->delete_temp("cai_5");
				ob[i]->unconcious();
				message_vision("服务员撇撇嘴，说：“丢出去！”\n", ob[i]);
				message_vision("大汉们抬起$N，扔出了店门。\n", ob[i]);
				ob[i]->move(KICK_TO);
				tell_room(KICK_TO, "只见餐厅大门一开，几个大汉将一个昏迷不醒的家伙丢了出来。\n", ({ob[i]}));
			}
			else ob[i]->set_temp("to_pay", paytime);
		}
	}
	call_out("quarter_pass", 30);
}

int do_sit(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting())	return notify_fail("你正忙着呢！\n");
	if (arg == "table" || arg == "zhuozi")
		return notify_fail("你要坐在桌子上？那先把你煮熟了再端上来吧。\n");	

	if ( !arg || (arg != "chair" && arg != "yizi") )
		return notify_fail("你要坐在地板上？有个性！不过这样的话恐怕你会被轰出餐厅了。\n");	
	
	if (me->query_temp("marks/sit"))
		return notify_fail("你已经坐在座位上了。\n");	
			
	if (me->query_temp("total_pay"))
		return notify_fail("先把旧帐结清了！\n");	
			
	remove_call_out("check_payed");
	message_vision("$N找了个空位座下，准备吃饭。\n", me);	
	if (query_temp("serve") == "无") {
		message_vision("服务员走过来对$N说：“对不起您哪，现在不是用餐时间。”\n", me);	
		message_vision("$N无奈地又站了起来。\n", me);	
		return 1;
	}
	me->set_temp("marks/sit", 1);
	return 1;
}

int do_stand()
{
	object me = this_player();

	if (!me->query_temp("marks/sit"))
		return notify_fail("你已经站着了，是不是站久了有点发昏啊？\n");	
	if (me->query_temp("total_pay"))
		return notify_fail("没付钱(pay)就想走吗？\n");	
			
	message_vision("$N拍拍屁股，站了起来。\n", me);	
	me->delete_temp("marks/sit");
	return 1;
}

int do_order(string arg)
{
	object me = this_player();
	string serve;
	int i, count;

	if (me->is_busy() || me->is_fighting())	return notify_fail("你正忙着呢！\n");
	if (!me->query_temp("marks/sit")) return notify_fail("服务员用好象瞧见一个怪物一样的眼神打量着你：“站着吃喝？有位子不坐，您不嫌累呀？”\n");
	if (!arg) return notify_fail("服务员不耐烦地说：“你究竟要什么啊？”\n");
			
	serve = query_temp("serve");
	if (serve == "无") return notify_fail("服务员赔笑道：“请您见谅，厨房已经停火了！”\n");
	if (!me->query_temp("total_pay")) me->set_temp("total_pay", 0);
	if (!(count = me->query_temp("cai_count"))) me->set_temp("cai_count", 0);
	for (i = 0; i < sizeof(food); i++)
		if ((arg == food[i]["name"] || arg == food[i]["short"]) 
		&&  serve == food[i]["time"]) {
			message_vision("$N冲服务员喊道：“来" + food[i]["unit"] + food[i]["name"] +"。”\n", me);
			if (me->query_temp("cai_count") >= 5) {
				message_vision("服务员奇怪地问$N：“您打算开宴呀？！先把桌上的吃完了再说！”\n", me);
				return notify_fail("");
			}
			message_vision("服务员喊着：“来～啦～”，给$N端来了" + food[i]["unit"] + food[i]["name"] +"。\n", me);
			me->add_temp("total_pay", food[i]["value"]);
			me->add_temp("cai_count", 1);
			me->set_temp("cai_" + count + "/name", food[i]["name"]);
			me->set_temp("cai_" + count + "/short", food[i]["short"]);
			me->set_temp("cai_" + count + "/unit", food[i]["unit"]);
			me->set_temp("cai_" + count + "/remaining", food[i]["remaining"]);
			me->set_temp("cai_" + count + "/supply", food[i]["supply"]);
			me->set_temp("cai_" + count + "/type", "food");
			return 1;
		}
	for (i = 0; i < sizeof(liquid); i++)
		if ((arg == liquid[i]["name"] || arg == liquid[i]["short"]) 
		&&  serve == liquid[i]["time"]) {
			message_vision("$N冲服务员喊道：“来" + liquid[i]["unit"] + liquid[i]["name"] +"。”\n", me);
			if (me->query_temp("cai_count") >= 5) {
				message_vision("服务员奇怪地问$N：“您打算开宴呀？！先把桌上的吃完了再说！”\n", me);
				return notify_fail("");
			}
			message_vision("服务员喊着：“来～啦～”，给$N端来了" + liquid[i]["unit"] + liquid[i]["name"] +"。\n", me);
			me->add_temp("total_pay", liquid[i]["value"]);
			me->add_temp("cai_count", 1);
			me->set_temp("cai_" + count + "/name", liquid[i]["name"]);
			me->set_temp("cai_" + count + "/short", liquid[i]["short"]);
			me->set_temp("cai_" + count + "/unit", liquid[i]["unit"]);
			me->set_temp("cai_" + count + "/remaining", liquid[i]["remaining"]);
			me->set_temp("cai_" + count + "/supply", liquid[i]["supply"]);
			me->set_temp("cai_" + count + "/type", "liquid");
			return 1;
		}
	return notify_fail("服务员不耐烦地说：“没这样菜！”\n");
}

int do_eat(string arg)
{
	object me = this_player();
	int i, count, remaining;

	if (!arg) return 0;
			
	if (!(count = me->query_temp("cai_count"))) return 0;
	for (i = 0; i < count; i++)
		if (me->query_temp("cai_" + i + "/type") == "food" && (arg == me->query_temp("cai_" + i + "/name") || arg == me->query_temp("cai_" + i + "/short")))
			break;
	if (i == count) return 0;
	if (!me->query_temp("marks/sit")) {
		write("服务员用好象瞧见一个怪物一样的眼神打量着你：“站着吃喝？有位子不坐，您不嫌累呀？”\n");
		return 1;
	}
	if (me->is_busy()) {
		write("你上一个动作还没有完成。\n");
		return 1;
	}
	if (me->query("food") >= me->max_food_capacity()) {
		write("你已经吃太饱了，再也塞不下任何东西了。\n");
		return 1;
	}

	me->add("food", me->query_temp("cai_" + i + "/supply"));
	if (me->is_fighting()) me->start_busy(2);

	message_vision("$N端起一" + me->query_temp("cai_" + i + "/unit") + me->query_temp("cai_" + i + "/name") +"，吃了两口。\n", me);
	remaining = me->query_temp("cai_" + i + "/remaining");
	remaining--;
	if (remaining == 0) {
		message_vision("$N将一" + me->query_temp("cai_" + i + "/unit") + me->query_temp("cai_" + i + "/name") +"吃得一干二净。\n", me);
		for (; i < count - 1; i++)
		{
			me->set_temp("cai_" + i + "/name", me->query_temp("cai_" + (i + 1) + "/name"));
			me->set_temp("cai_" + i + "/short", me->query_temp("cai_" + (i + 1) + "/short"));
			me->set_temp("cai_" + i + "/unit", me->query_temp("cai_" + (i + 1) + "/unit"));
			me->set_temp("cai_" + i + "/remaining", me->query_temp("cai_" + (i + 1) + "/remaining"));
			me->set_temp("cai_" + i + "/supply", me->query_temp("cai_" + (i + 1) + "/supply"));
			me->set_temp("cai_" + i + "/type", me->query_temp("cai_" + (i + 1) + "/type"));
		}
		me->add_temp("cai_count", -1);	
	}
	else
		me->set_temp("cai_" + i + "/remaining", remaining);
	return 1;
}

int do_drink(string arg)
{
	object me = this_player();
	int i, count, remaining;

	if (!arg) return 0;
			
	if (!(count = me->query_temp("cai_count"))) return 0;
	for (i = 0; i < count; i++)
		if (me->query_temp("cai_" + i + "/type") == "liquid" && (arg == me->query_temp("cai_" + i + "/name") || arg == me->query_temp("cai_" + i + "/short")))
			break;
	if (i == count) return 0;
	if (!me->query_temp("marks/sit")) {
		write("服务员用好象瞧见一个怪物一样的眼神打量着你：“站着吃喝？有位子不坐，您不嫌累呀？”\n");
		return 1;
	}
	if (me->is_busy()) {
		write("你上一个动作还没有完成。\n");
		return 1;
	}
	if (me->query("water") >= me->max_water_capacity()) {
		write("你已经喝太饱了，再也灌不下任何东西了。\n");
		return 1;
	}

	me->add("water", me->query_temp("cai_" + i + "/supply"));
	if (me->is_fighting()) me->start_busy(2);

	message_vision("$N端起一" + me->query_temp("cai_" + i + "/unit") + me->query_temp("cai_" + i + "/name") +"，喝了两口。\n", me);
	remaining = me->query_temp("cai_" + i + "/remaining");
	remaining--;
	if (remaining == 0) {
		message_vision("$N将一" + me->query_temp("cai_" + i + "/unit") + me->query_temp("cai_" + i + "/name") +"喝得一干二净。\n", me);
		for (; i < count - 1; i++)
		{
			me->set_temp("cai_" + i + "/name", me->query_temp("cai_" + (i + 1) + "/name"));
			me->set_temp("cai_" + i + "/short", me->query_temp("cai_" + (i + 1) + "/short"));
			me->set_temp("cai_" + i + "/unit", me->query_temp("cai_" + (i + 1) + "/unit"));
			me->set_temp("cai_" + i + "/remaining", me->query_temp("cai_" + (i + 1) + "/remaining"));
			me->set_temp("cai_" + i + "/supply", me->query_temp("cai_" + (i + 1) + "/supply"));
			me->set_temp("cai_" + i + "/type", me->query_temp("cai_" + (i + 1) + "/type"));
		}
		me->add_temp("cai_count", -1);	
	}
	else
		me->set_temp("cai_" + i + "/remaining", remaining);
	return 1;
}

int do_pay()
{
	object me = this_player();
	int pay;

	if (!(pay = me->query_temp("total_pay")))		
		return notify_fail("服务员赔笑道：“您是来做善事是吗？不吃也付帐？”\n");
	if (me->query_temp("marks/sit")) {
		message_vision("$N站起身来，走到柜台前结帐。\n", me);
		message_vision("服务员翻出菜单，敲打了一阵键盘后告诉$N：“一共" + MONEY_D->price_str(pay) + "。”\n", me);
		message_vision("服务员把桌子上的剩菜收拾干净。\n", me);
	}
	else {
		message_vision("$N向服务员问道：“还差多少？”\n", me);
		message_vision("服务员翻了翻白眼，说道：“还差" + MONEY_D->price_str(pay) + "。”\n", me);
	}
	me->delete_temp("marks/sit");
	me->delete_temp("cai_count");
	me->set_temp("to_pay", 1);
	return 1;
}

int do_buy()
{
	write("服务员说道：“本店暂时不办理外卖，请坐下来(sit)点菜(order)。”\n");
	return 1;
}

int do_quit()
{
	if (this_player()->query_temp("total_pay")) {
		write("吃饱喝足了不付钱就想退出？！\n");
		return 1;
	}
	return 0;
}

string look_sign()
{
	string serve;
	int i;

	write("牌子上写着：\n");
	serve = query_temp("serve");
	if (serve == "无") {
		write("    非用餐时间。\n");
		return "";
	}
	write("    " + serve + "餐供应以下饭食，随便您点(order)：\n");
	for (i = 0; i < sizeof(food); i++)
		if (serve == food[i]["time"]) 
			printf("    %30s    每%s分钱。\n", food[i]["name"] + "(" + food[i]["short"] + ")", food[i]["unit"] + chinese_number(food[i]["value"]));
	for (i = 0; i < sizeof(liquid); i++)
		if (serve == liquid[i]["time"]) 
			printf("    %30s    每%s分钱。\n", liquid[i]["name"] + "(" + liquid[i]["short"] + ")", liquid[i]["unit"] + chinese_number(liquid[i]["value"]));
	return "";
}

string look_table()
{
	object me = this_player();
	int i, j, num, count;
	string name;

	if (!(count = me->query_temp("cai_count"))) {
		write("桌子上是空的。\n");
		return "";
	}
	write("你面前的桌子上放着：\n");
	for (i = 0; i < count; i++)
	{
		name = me->query_temp("cai_" + i + "/name");
		num = 1;
		for (j = 0; j < count; j++)
		{
			if (j == i) continue;
			if (name == me->query_temp("cai_" + j + "/name")) {
				if (j < i) {
					num = 0;
					break;
				}
				num++;
			}
		}
		if (!num) continue;
		write("    " + chinese_number(num) + me->query_temp("cai_" + i + "/unit") + name + "(" + me->query_temp("cai_" + i + "/short") +")。\n");
	}
	return "";
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("marks/sit"))
		return notify_fail("你打算连椅子也搬出去？\n");	

	if (me->query_temp("total_pay"))
		return notify_fail("服务员拦住你说：“不付钱就想溜？找扁啊！”\n");	

	me->delete_temp("cai_count");
	me->delete_temp("cai_1");
	me->delete_temp("cai_2");
	me->delete_temp("cai_3");
	me->delete_temp("cai_4");
	me->delete_temp("cai_5");
	return ::valid_leave(me, dir);
}
