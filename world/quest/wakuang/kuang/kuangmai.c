#include <ansi.h>
inherit ITEM;

string *kuang1=({"/quest/wakuang/kuang/tong-kuang","/quest/wakuang/kuang/tie-kuang"});
string *kuang2=({"/quest/wakuang/kuang/tong-kuang","/quest/wakuang/kuang/tie-kuang","/quest/wakuang/kuang/ying-kuang"});
string *kuang3=({"/quest/wakuang/kuang/tong-kuang","/quest/wakuang/kuang/tie-kuang","/quest/wakuang/kuang/ying-kuang","/quest/wakuang/kuang/jing-kuang"});
string *kuang4=({"/quest/wakuang/kuang/tong-kuang","/quest/wakuang/kuang/tie-kuang","/quest/wakuang/kuang/ying-kuang","/quest/wakuang/kuang/jing-kuang","/quest/wakuang/kuang/xuantie-kuang"});
string *kuang5=({"/quest/wakuang/kuang/tong-kuang","/quest/wakuang/kuang/tie-kuang","/quest/wakuang/kuang/ying-kuang","/quest/wakuang/kuang/jing-kuang","/quest/wakuang/kuang/xuantie-kuang","/quest/wakuang/kuang/hantie-kuang1"});
string *kuang6=({"/quest/wakuang/kuang/tong-kuang","/quest/wakuang/kuang/tie-kuang","/quest/wakuang/kuang/ying-kuang","/quest/wakuang/kuang/jing-kuang","/quest/wakuang/kuang/xuantie-kuang","/quest/wakuang/kuang/hantie-kuang1","/quest/wakuang/kuang/hantie-kuang2"});

void init()
{
        add_action("do_wakuang", "wakuang");
}


void create() 
{
        set_name("矿脉",({"kuang mai", "mai"}));
        set_weight(1000000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("no_drop","不要乱丢，这东西打到人痛！\n");
                set("no_put",1);
                set("no_give","你辛苦挖来的矿那能随便给人！\n");
                set("no_get", "这么重的矿脉哪里拿得起来？\n");
                set("long", "这是一条很好的矿脉，你可以用（wakuang）来试试你的运气如何。\n");
             }
        setup();
}

int do_wakuang()
{
        object me=this_player();
        if( me->query("combat_exp") <= 200000)
        return notify_fail("你好象还不可以挖矿! \n");
//      if( me->query("combat_exp") > 600000)
//              return notify_fail("你好象不太适合挖矿了! \n");
        if( me->is_busy() ) return notify_fail("你现在很忙！不能挖！\n");
        if ((me->query("sen") < 100))
        {  
          tell_object(me,"你的精力不能集中，不可以挖矿石！\n");
          return 1;
        }
        else
        if ((me->query("kee") < 100 ))
        {
          tell_object(me,"你的身体状态太差，不能挖矿石！\n");
          return 1;
        }
        message_vision(HIC"$N挥动铁镐开始在地上挖了起来。\n"NOR,me);
        if( me->query("combat_exp") >= 500000)
        {
        me->add("sen",-(100+random(101)));
        me->add("kee",-(100+random(101)));
        me->start_busy(6);   
        call_out("wakuang",5,me);
        me->stop_busy();        
        }
        else
        {
        me->add("sen",-(50+random(50)));
        me->add("kee",-(50+random(50)));
//        me->add("combat_exp",25+random(25));
//        me->add("potential",25+random(25));
//        me->add("daoxing",25+random(25));
        me->start_busy(3);   
        call_out("wakuang",5,me);
        me->stop_busy();
        }
        return 1;
}

int wakuang(object me)
{
        object ob;
        object ob1;        
        int i;
        if( me->query("combat_exp") >= 500000) i=random(11);
        else i=random(4);
        if (i<2)
        {
          message_vision(CYN"一阵挖掘之后，$N什么也没挖到。\n"NOR,me);
          this_player()->add("work/wakuang",1);
          return 1;
        }
        else
        if ((int)me->query("work/wakuang") > 600 )
        {
                message_vision(HIR"$N熟练的在矿脉中找来查去，不一会儿就找出一块好矿石。\n"NOR,me); 
                me->add("work/wakuang",random(2));
                ob=new(kuang6[random(7)]);
                ob->move(me);
                destruct(this_object());
                return 1;
        }
        else
        if ((int)me->query("work/wakuang") > 500 )
        {
                message_vision(HIY"$N熟练的在矿脉中找来查去，不一会儿就找出一块好矿石。\n"NOR,me); 
                me->add("work/wakuang",1);
                ob=new(kuang5[random(6)]);
                ob->move(me);
                destruct(this_object());
                return 1;
        }
        else
        if ((int)me->query("work/wakuang") > 400 )
        {
                message_vision(HIY"$N熟练的在矿脉中找来查去，不一会儿就找出一块好矿石。\n"NOR,me); 
                me->add("work/wakuang",2);
                ob=new(kuang4[random(5)]);
                ob->move(me);
                destruct(this_object());
                return 1;
        }       
        else
        if ((int)me->query("work/wakuang") > 300 )
        {
                message_vision(HIY"$N在矿脉中翻来覆去，找出一块好矿石。\n"NOR,me); 
                me->add("work/wakuang",3);
                ob=new(kuang3[random(4)]);
                ob->move(me);
                destruct(this_object());
                return 1;
        }
        else
        if ((int)me->query("work/wakuang") > 200 )
        {
                message_vision(HIY"$N在矿脉中找来查去，好久才找出一块矿石。\n"NOR,me); 
                me->add("work/wakuang",4);
                ob=new(kuang2[random(3)]);
                ob->move(me);
                destruct(this_object());
                return 1;
        }
        else
        if ((int)me->query("work/wakuang") > 100 )
        {
                message_vision(HIY"$N在矿脉中摸来摸去，好不容易找出一块矿石。\n"NOR,me); 
                me->add("work/wakuang",5);
                ob=new(kuang1[random(2)]);
                ob->move(me);
                destruct(this_object());
                return 1;
        }
        else
        { 
                message_vision(HIG"$N找了半天，终于发现其中一块石头是矿石。\n"NOR,me); 
                me->add("work/wakuang",6);
                ob1 = new( __DIR__ "tong-kuang");
                ob1->move(me);
                destruct(this_object());
        }
        return 1;
}
