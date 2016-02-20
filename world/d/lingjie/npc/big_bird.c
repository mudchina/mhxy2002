// bigbird.c by LitChi 

#define DEBUG 1
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("大鸟", ({ "big bird", "bird" }) );
	set("race", "野兽");
	set("age", 1);
        set("long", "一只美丽的大鸟。\n");
        set("attitude", "friendly");
        set("max_kee", 100+random(50));
        set("kee", 100+random(50));
        set("gin", 100);
        set("max_gin", 100);
        set("max_sen", 100);
        set("sen", 100);
        set("eff_sen", 100);	
	set("limbs", ({ "嘴", "翅膀", "爪子" }) );
	set("verbs", ({ "bite", "claw" }) );
	set("combat_exp", 100+random(50));
	set_temp("apply/attack", 5+random(5));
	set_temp("apply/defense", 5+random(5));
	set_temp("apply/damage", 5+random(5));
	setup();
}

void invocation()
{
	object me=this_object();
	int i = 200 + random(100);
	if(DEBUG) i = 5;
	call_out("grow", i, me, i, 1);
}

int grow(object me,int time,int times)
{
	int i = time + random(200);
	object baiyu;
	
	if(DEBUG) i = 5;
	if(times > 1) 
	{       
		tell_room(environment(me), me->name()+"凝视远方，一个展翅飞走了。\n", ({me, me}));
		destruct(me);
		return 1;
	}
	times++;
	me->set("baiyu",1);
	tell_room(environment(me), me->name()+"兴奋的叫了几声，身上长出一片白羽。\n", ({me, me}));
	carry_object("/d/lingjie/obj/baiyu");
	call_out("grow", i, me, i, times);
	return 1;
}

int accept_object(object who, object ob)
{
        object baiyu;
        
        if( ob->query("id") == "xue guo" ) 
        {
          if(!who->query_temp("lingjie/bird_grow") || !this_object()->query("baiyu")) { command("shake"); return 0; }
          command("nod");
          message_vision(HIM+"$N感激的望着$n,用嘴从身上扯下了一根羽毛，放到$n的手中。"+NOR"\n",this_object(),who);
          baiyu = new("/d/lingjie/obj/baiyu");
          baiyu->move(who);
          who->delete_temp("lingjie/bird_grow");
          invocation();
          who->delete_temp("lingjie/bird_give"); 
          return 1;
        } 
        return 0;
}

void unconcious()
{
	int i;
	object me = this_object();
	message("sound", HIM"\n"+me->query("name")+"化成一股五彩清烟飞向天空。。。\n\n"NOR, environment());
	destruct(me);
}
void die()
{
	unconcious();
}
