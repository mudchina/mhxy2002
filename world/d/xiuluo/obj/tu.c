inherit ITEM;

void init();
int do_read(string arg);

void create()
{
        set_name("【乾坤图】", ({"qiankun-tu","tu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
        set("long",
        "薄薄的一张人皮，上面画着各式各样的人物穴位。\n");
        set("material", "paper");
        set("value", 500);   
        set("no_sell",1);
         set("no_drop",1);
         set("no_get",1);
        }
}

void init()
{
        add_action("do_read", "read");
        add_action("do_read", "study");

        if( (int)this_object()->query("created") != 1 )
        {
                this_object()->set("created", 1);
                remove_call_out ("destroy_book");
//             call_out ("destroy_book", 18000/5*2);//5 hours

        }
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
        if( environment(this_object())!=me ) return notify_fail("乾坤图要拿起来读。\n");



        if( environment(me)->query("no_fight") )
                return notify_fail("安全区内不能读。\n");


        if(me->query("xiuluo/jinchanzi")!="done" )
        return notify_fail("这书是你的？\n");

        if( me->is_busy() )
                        return notify_fail("你现在忙着呢，哪有可能静心研读...\n");
        if( me->is_fighting() )
                        return notify_fail("现在才想到精研上乘武学，太晚了吧？\n");
        
        if( (int)me->query_skill("literate",1)<200 )
                return notify_fail("你看来看去，就是没明白这图上画的是什么玩意。\n");
   if( (int)me->query_skill("dianxue",1)>160 )
                return notify_fail("你在乾坤点穴大法方面已经很有造诣，这张人皮对你而言已经没用了。\n");

        sen_cost = 35 + (35-(int)me->query("int"));
        if( (int)me->query("sen")<sen_cost )
                return notify_fail("你现在头晕脑胀，该休息休息了。\n"); 
        me->receive_damage("sen", sen_cost*3/2);

        gain = (int)me->query_skill("dianxue", 1)/5+(int)me->query("int")+1;
        me->improve_skill("dianxue", gain);

        message_vision("$N拿着乾坤图欢喜的叫到，果然厉害，不愧为上乘武学！\n", me);
                
        return 1;
}
