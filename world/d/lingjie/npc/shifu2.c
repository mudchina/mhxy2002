
inherit NPC;
#include <ansi.h>
#define FOOD_D(x)       ("/obj/food/" + x)
int give_food();
int give_water();
string* foods = ({
       FOOD_D("rice"),
       FOOD_D("mantou"),
       FOOD_D("doufu"),
       FOOD_D("baozi"),
       FOOD_D("yuebing"),
       FOOD_D("zongzi"),
       FOOD_D("shanguo"),
       FOOD_D("fan"),
       });
void create()
{
       set_name("灵界大师傅", ({ "shifu"}) );
       set("gender", "男性" );
       set("age", 50);
       set("long","他是灵界饭堂的厨子，胖胖的，敦厚老实\n");
       set("combat_exp", 2500);
       set("attitude", "friendly");
       set("inquiry", ([
	"手艺" : "我做饭的手艺可是灵界一绝，整个灵界谁不夸我！嘿嘿！",
	"食物" : (: give_food :),
	"food" : (: give_food :),
	"水" : (: give_water :),
	"water" : (: give_water :),
       ]) );
       setup();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int give_food()
{
       object food, me, ob, *obj;
       int i;
	me = this_object();
	ob = this_player();
	obj = all_inventory(ob);
	for(i=0; i<sizeof(obj); i++)
	if (obj[i]->query("food_remaining")){
	command("say 谁知盘中餐，粒粒皆辛苦！你先把身上的食物吃掉再说吧。");
	return 1;} 
	if ((time()- ob->query_temp("food_give"))<100){command("say 你好像刚刚才问我要过食物嘛！你先把你身上的食物吃掉再说吧。");
	return 1;}
	obj = all_inventory(environment(me));
	for(i=0; i<sizeof(obj); i++)
	if (obj[i]->query("food_remaining"))
	{
	   command("say 谁知盘中餐，粒粒皆辛苦！你先把地上的食物捡起来吃掉吧。");
	   return 1;
	} 

	if (ob->query("age")>30)
	{  
	   command("say 哎，都这么大了，还要东西吃，你羞也不羞？");
	   return 1;
	}
	else
	{
          command("say 谁知盘中餐，粒粒皆辛苦！别浪费了。用 i 看看你身上的食物，用 eat 吃食物。");
          food = new( foods[random(sizeof(foods))] );
          food->move(ob);
          ob->set_temp("food_give",time());
          message_vision("$N交给$n一碗吃的。\n", me, ob);
          return 1;
        }
}
 
int give_water()
{
       object water, me, ob;
       me = this_object();
       ob = this_player();
	if (ob->query("age")>30){
	command("say 哎，都这么大了，还要水喝，你羞也不羞？");
	return 1;
             } 
       if ( objectp(present("cocacola", environment(me)))){ 
	     command("say 谁知盘中餐，粒粒皆辛苦！你先把地上的可口可乐喝掉吧。");
             return 1;
             } 
       if (present("cocacola", ob)) { 
	     command("say 你先把身上的可口可乐喝掉吧。");
             return 1;
	     } 
       water = new("/d/lingjie/npc/obj/kekou");
       water->move(ob);
       command("say 用 i 看看你身上的食物，用 drink 来喝水。");
       message_vision("$N拿了一盒可口可乐交给$n。\n", me, ob);
       return 1;
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() || ob->query("age") > 15 ) return;
         
       command("pat "+ob->query("id"));
       command("say 这里是饭厅，可以向我要食物"RED"(ask shifu about 食物)"NOR"和喝的"RED"(ask shifu about 水)"NOR"。\n");
}
