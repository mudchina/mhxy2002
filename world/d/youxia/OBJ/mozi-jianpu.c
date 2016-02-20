//mozi-sword, created 17-06-2001 海上飘(piao)


// mozi-jianpu.c
inherit F_UNIQUE;

#include <ansi.h>

inherit ITEM;

void init();
int do_read(string arg);

void create()
{
        set_name(BLK"【墨子剑谱】"NOR, ({"mozi jinpu","book","shu","jianpu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
       set("no_get", 1);
       set("no_give", 1);
       set("no_put", 1);
	set("long",
	"一本失传多年的武功秘籍，上面工整地写着“墨子剑谱”。\n");
        set("material", "paper");
        set("value", 0);   
	set("no_sell",1);
              set("no_sell", "" + (string)this_object()->query("name") + "是无价之宝，不可进行买卖。\n");
        }
}

void init()
{
  	add_action("do_read", "read");
	add_action("do_read", "study");

	if( (int)this_object()->query("created") != 1 )
	{
		this_object()->set("created", 1);	}
		remove_call_out ("destroy_book");
		call_out ("destroy_book", 9000);//2.5 hours


}

void destroy_book()
{
	message_vision("一阵风吹来，" + (string)this_object()->query("name") + "片片碎落，随风而去了。\n", environment(this_object()));
	destruct(this_object());
}

int do_read(string arg)
{
	object me;
	int sen_cost, gain;
	
	me=this_player();

    	if( !this_object()->id(arg) ) return 0;
	if( environment(this_object())!=me ) return notify_fail("书要拿起来读。\n");



	if( environment(me)->query("no_fight") )
		return notify_fail("安全区内不能读书。\n");



    	if( me->is_busy() )
        		return notify_fail("你现在忙着呢，哪有可能静心研读...\n");
   	if( me->is_fighting() )
        		return notify_fail("现在才想到精研武功秘籍，太晚了吧？\n");
	
	if( (int)me->query_skill("literate",1)<100 )
        return notify_fail("你看来看去，就是没明白这本秘籍里写的都是啥。\n");
	if( (int)me->query_skill("mozi-sword",1)>280 )
		return notify_fail("你对墨子剑法已经很有领悟，这本书不会让你长进多少。\n");

	sen_cost = 35 + (35-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("你现在头晕脑胀，该休息休息了。\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("mozi-sword", 1)+(int)me->query("int")+1;
	me->improve_skill("mozi-sword", gain);

    	message_vision("$N拿着" + (string)this_object()->query("name") + "仔细研读了起来，惊叹到：世间竟有如此高深莫测的武功！
"HIY"你的「墨子剑法」进步了！"NOR"\n", me);
		
	return 1;
}

