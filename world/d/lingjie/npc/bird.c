// bird.c by LitChi

#define DEBUG 0
inherit NPC;
void create()
{
        set_name("小鸟", ({ "bird" }) );
	set("race", "野兽");
	set("age", 1);
        set("long", "一只美丽的小鸟。\n");
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
	int i = 400 + random(200);
	if(DEBUG) i = 5;
	call_out("grow_big", i, me);
}

int grow_big(object me)
{
	object bird;
	
	tell_room(environment(me), "\n"+me->name()+"突然振翅高兴的鸣叫，叫声中已慢慢长大为一只美丽的大鸟！\n", ({me, me}));
	bird = new("/d/lingjie/npc/big_bird");
	bird->move(environment(this_object()));
	bird->invocation();
	destruct(me);
	return 1;
}

int accept_object(object who, object ob)
{
        if( ob->query("id") == "mang guo" ) 
        { 
          who->add_temp("lingjie/bird_give",1);
          command("nod");
        }
        if( who->query_temp("lingjie/bird_give") > 5) 
        { 
        	invocation(); 
        	who->delete_temp("lingjie/bird_give"); 
                who->set_temp("lingjie/bird_grow",1);
        }
        return 1;
}