// ying-kuang.c 矿脉
// 星星lywin 2000/8/27

#include <ansi.h>
inherit ITEM;  

string *kuang1=({"quest/skills2/wunon/jiu/eat1","quest/skills2/wunon/jiu/eat2","quest/skills2/wunon/jiu/eat3"});
string *kuang2=({"quest/skills2/wunon/jiu/eat1","quest/skills2/wunon/jiu/eat2","quest/skills2/wunon/jiu/eat3","quest/skills2/wunon/jiu/eat4"});
string *kuang3=({"quest/skills2/wunon/jiu/eat1","quest/skills2/wunon/jiu/eat2","quest/skills2/wunon/jiu/eat3","quest/skills2/wunon/jiu/eat4","quest/skills2/wunon/jiu/eat5"});
string *kuang4=({"quest/skills2/wunon/jiu/eat1","quest/skills2/wunon/jiu/eat2","quest/skills2/wunon/jiu/eat3","quest/skills2/wunon/jiu/eat4","quest/skills2/wunon/jiu/eat5","quest/skills2/wunon/jiu/eat6"});
string *kuang5=({"quest/skills2/wunon/jiu/eat1","quest/skills2/wunon/jiu/eat2","quest/skills2/wunon/jiu/eat3","quest/skills2/wunon/jiu/eat4","quest/skills2/wunon/jiu/eat5","quest/skills2/wunon/jiu/eat6","quest/skills2/wunon/jiu/eat7"});
string *kuang6=({"quest/skills2/wunon/jiu/eat1","quest/skills2/wunon/jiu/eat2","quest/skills2/wunon/jiu/eat3","quest/skills2/wunon/jiu/eat4","quest/skills2/wunon/jiu/eat5","quest/skills2/wunon/jiu/eat6","quest/skills2/wunon/jiu/eat7","quest/skills2/wunon/jiu/eat8"});

void init()
{
	add_action("do_wakuang", "zhaojiu");
}


void create() 
{
        set_name("造酒场",({"daliechang", "chang"}));
        set_weight(500000000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "座");
		set("no_drop","不要乱丢，这东西打到人痛！\n");
		set("no_put",1);
		set("no_get:",1);
                set("long", "这是一块很好的造酒场，你可以用（zhaojiu）来试试你的运气如何。\n");
             }
        setup();
}

int do_wakuang()
{
        object me=this_player();

        if( me->is_busy() ) return notify_fail("你现在很忙！不能造酒！\n");
        if ((me->query("jing") < 30))
        {  
          tell_object(me,"你的精力不能集中，不可以造酒！\n");
          return 1;
        }
        else
        if ((me->query("qi") < 50 ))
        {
          tell_object(me,"你的身体状态太差，不能造酒！\n");
          return 1;
        }
        else
        if ((int)me->query_condition("skill2_busy"))  
            {
         tell_object(me,"你刚刚才干过活,要休息一会了！\n");
                      return 1;
            }

        message_vision(HIC"$N拿起造酒工具开始在造酒场里造酒。\n"NOR,me);
        me->add("jing",-40);
        me->add("qi",-50);
        me->add("combat_exp",30+random(20));
        me->add("potential",20+random(5));
        me->apply_condition("skill2_busy",1+random(3));
        me->start_busy(6);   
       	call_out("wakuang",5,me);
       	me->stop_busy();
       	return 1;
}

int wakuang(object me)
{
      object ob;
      object ob1;        

      if (random(7)<3)
      {
          message_vision(CYN"一阵劳动之后，$N什么酒也没造出。\n"NOR,me);
//          this_player()->add("work/zhaojiu",1);
          return 1;
      }
      else
      if ((int)me->query("work/zhaojiu") > 600 )
        {
           message_vision(HIR"$N熟练的在造酒场做了一会，不一会儿就有了好的收获。\n"NOR,me); 
           me->add("work/zhaojiu",1);
           ob=new(kuang6[random(8)]);
           ob->move(me);
           destruct(this_object());
           return 1;
       }
       else
      if ((int)me->query("work/zhaojiu") > 500 )
        {
           message_vision(HIY"$N熟练的在造酒场里干了一会，不一会儿就有了好的收获。\n"NOR,me); 
           me->add("work/zhaojiu",1);
           ob=new(kuang5[random(7)]);
           ob->move(me);
           destruct(this_object());
           return 1;
       }
       else
      if ((int)me->query("work/zhaojiu") > 400 )
        {
           message_vision(HIY"$N熟练的在造酒场里干了一会，不一会儿就有了收获。\n"NOR,me); 
           me->add("work/zhaojiu",1);
           ob=new(kuang4[random(6)]);
           ob->move(me);
           destruct(this_object());
           return 1;
       }       
       else
      if ((int)me->query("work/zhaojiu") > 300 )
        {
           message_vision(HIY"$N在造酒场里干了一会，有了收获。。\n"NOR,me); 
           me->add("work/zhaojiu",1);
           ob=new(kuang3[random(5)]);
           ob->move(me);
           destruct(this_object());
           return 1;
       }
       else
      if ((int)me->query("work/zhaojiu") > 200 )
        {
           message_vision(HIY"$N在造酒场里干了一会，好长时间才有了收获。\n"NOR,me); 
           me->add("work/zhaojiu",1);
           ob=new(kuang2[random(4)]);
           ob->move(me);
           destruct(this_object());
           return 1;
       }
       else
      if ((int)me->query("work/zhaojiu") > 100 )
        {
           message_vision(HIY"$N在造酒场中跑来跑去，好不容易有了收获。\n"NOR,me); 
           me->add("work/zhaojiu",1);
           ob=new(kuang1[random(3)]);
           ob->move(me);
           destruct(this_object());
           return 1;
       }
      else
      { 
        message_vision(HIG"$N造了半天的酒，终于有了一点收获。\n"NOR,me); 
        me->add("work/zhaojiu",1);
        ob1 = new( __DIR__ "eat1");
        ob1->move(me);
        destruct(this_object());
      }
      return 1;
}
