//yaochu.c 药锄
//海洋II（云起云落）
//星星lywin 2000/6/15

#include <ansi.h>
inherit ITEM;

string *she1=({"/quest/npc/dushe","/quest/npc/jinshe","/quest/npc/qingshe"});
string *she2=({"/quest/npc/fushe"});
string *yao1=({"/quest/liandan/yaocao1","quest/liandan/yaocao2"});

void init()
{
	add_action("do_wayao", "wayao");
}

void create()
{
	set_name("药锄", ({"yao chu", "chu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("no_drop","不要乱丢，这东西打到人痛！\n");
		set("no_put",1);
		set("long", "这是一把破药锄，你可以用它来挖药（wayao）。\n");
		set("value", 0);
	}
	setup();
}

int do_wayao()
{
        object me=this_player();

        if ((me->query("sen") < 20))
        {  
          tell_object(me,"你的精力不能集中，不可以挖药！\n");
          return 1;
        }
        else
        if ((me->query("kee") < 30 ))
        {
          tell_object(me,"你的身体状态太差，不能挖药！\n");
          return 1;
        }
        else          
	if (environment(me)->query_temp("wayao1") >= 1)
        {
        message_vision(HIC"$N挥动药锄开始在地上挖了起来。\n"NOR,me);
        me->add("sen",-10);
        me->add("kee",-20);
        me->start_busy(3);   
       	call_out("wayao1",3,me);
       	me->stop_busy();
       	return 1;
      	}
      	else
	if (environment(me)->query_temp("wayao2") >= 1)
        {
        message_vision(HIC"$N挥动药锄开始在地上挖了起来。\n"NOR,me);
        me->add("sen",-20);
        me->add("kee",-30);
        me->start_busy(4);   
       	call_out("wayao2",4,me);
       	me->stop_busy();
       	return 1;
      	}
        return notify_fail("这里的药草早已被人挖光了。\n");
}

int wayao1(object me)
{
      object ob;
      object ob1;        

      if(random(7)<2) 
      {         
        tell_room(environment(me),HIY"草丛中一阵晃动，突然钻出一条蛇。\n"NOR );
        ob=new(she1[random(3)]);
        ob->move(environment(me));
      }
      else
      if (random(7)<3)
      {
          message_vision(CYN"一翻摸索后，草丛中似乎没有$N要找的东西，$N失望的叹了口气。\n"NOR,me);

      }
      else
      { 
        message_vision(HIG"$N找了半天，终于发现其中一株草苗与其它的草略有不同，小心翼翼地掘了出来。\n"NOR,me); 
        message_vision(HIG"药草倒是挖到了，可惜药锄却不小碰坏了。\n"NOR,me); 
        ob1 = new( __DIR__ "yaocao1");
        ob1->move(me);
        environment(me)->add_temp("wayao1",-1);
        destruct(this_object());
      }
      return 1;
}

int wayao2(object me)
{
      object ob;
      object ob1;        

      if(random(7)<2) 
      {         
        tell_room(environment(me),HIY"草丛中一阵晃动，突然钻出一条蛇。\n"NOR );
        ob=new(she2[random(1)]);
        ob->move(environment(me));
      }
      else
      if (random(7)<3)
      {
          message_vision(CYN"一翻摸索后，草丛中似乎没有$N要找的东西，$N失望的叹了口气。\n"NOR,me);

      }
      else
      { 
        message_vision(HIG"$N找了半天，终于发现其中一株草苗与其它的草略有不同，小心翼翼地掘了出来。\n"NOR,me); 
        message_vision(HIG"药草倒是挖到了，可惜药锄却不小碰坏了。\n"NOR,me); 
        ob1 = new(yao1[random(2)]);
        ob1->move(me);
        environment(me)->add_temp("wayao2",-1);
        destruct(this_object());
      }
      return 1;
}
