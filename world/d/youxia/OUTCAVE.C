inherit ROOM;
void create()
{
        set("short", "瀑后山洞");
        set("long", @LONG
飞流的水珠不时地溅入山洞，地下布满冰碴，又硌又扎。山洞
内很暗，但隐约还可看出里面空间很大，慢慢往前走去，发现前面
有几个矮小的洞分别通向更深的山腹中。但是由于洞内极冷，洞口
都被寒冰盖住了。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	//   "west" : __DIR__"waterfall",
	]));
        set("objects", ([
                "/obj/money/thousand-cash" :1,
                        ]) );
	set("frozen",10);
        set("item_desc", ([
                "寒冰": "
除非把寒冰砸开（ｐｏｕｒ），根本没办法进入山腹中。\n",
        ]) );

        set("coor/x",230);
	set("coor/y",-290);
	set("coor/z",40);
	setup();
}

void init()
{
	add_action("do_break", "break");
}

int do_break()
{
	object me=this_player();
	int i;
	i=(int)me->query("force_factor")*5 + (int)me->query("str");

	if( this_object()->query("open") )
		return notify_fail("寒冰已经化开了一个小洞．．．不用在费尽了。\n");

	message_vision("$N用力想把寒冰砸开！\n", me);
	
	if( i > 200)
		tell_room(this_object(), "寒冰有点松动了………\n");
	else if( i > 150)
		tell_room(this_object(), "寒冰砸开了一点………\n");
	else
		tell_room(this_object(), "寒冰好象没有什么动静………\n");

	this_object()->add("break", i);
	me->receive_damage("kee", 30);
	me->add("force", -(int)me->query("force_factor"));
	
	if( (int)me->query("force") < 0 ){
		me->set("force", 0);
	}

	if ( (int)this_object()->query("break") > 3000 ){
		tell_room(this_object(),"寒冰间的缝隙足够一个人钻出去了。\n");
		this_object()->set("open", 1);
		set("long", @LONG

钻进洞中抬头望去，黑暗中依稀看到山洞顶部凹凸不平，上面有许
多草藤交织成的巢穴，也不知是如何固定在上面的，刚好有一只小
鸟从穴中飞出，沿洞壁盘旋一周，鸣叫着又钻了回去。到处都是寒
冰！
LONG);
		this_object()->set("exits/enter", "/d/youxia/leftcave");
	}
	return 1;
}

int valid_leave(object me, string dir)
{
        if (dir == "enter" ) {
		if( !this_object()->query("exits/enter"))
			return notify_fail("这个方向没有出路。\n");
		message_vision("$N躬身从寒冰缝隙中钻了出去。\n", me);
		return 1;
        }   
	
}





