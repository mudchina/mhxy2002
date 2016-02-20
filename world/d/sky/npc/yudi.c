// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//created 4-8-97 pickle
inherit NPC;
int do_drop(object, object);

void create()
{
        set_name("玉皇大帝", ({ "yu di", "yudi","di" }) );
        set("title", "高天上圣");        
        set("gender", "男性" );
        set("long","
宝座上端坐着一位看上去刚入中年的男子,龙冠蟒带,确有一番气魄。\n");
        set("age",35);
        set("str",30);
        set("int",30);
        set("per",30);        
        set("max_kee",10000);
        set("kee",10000);
        set("max_sen",10000);
        set("sen",10000);
        set("combat_exp",3000000);
        set("force",3200);
        set("max_force",3200);
        set("mana",3000);
        set("max_mana",3000);
        set("force_factor", 80);
        set("mana_factor", 80);

        set("eff_dx", 250000);
        set("nkgain", 350);
   
        set_skill("spells", 80);
        set_skill("unarmed",80);
        set_skill("parry",80);
        set_skill("dodge",80);
        set_skill("force",80);
        set("inquiry", ([
                "name" : "寡人就是四海的主人玉皇大帝.",
                "here" : "这里就是灵霄宝殿。",
        ]) );
        set("no_ling",0);
        setup();
        carry_object("/d/obj/cloth/longpao")->wear();
        carry_object("/d/sky/obj/tianguan")->wear();
        carry_object("/d/sky/obj/yunxue")->wear();
}

void accept_kill(object me)
{ object ob1,ob2;
if (me->query("obstacle/sky","done")) return;
if( is_fighting()) return;
if( query("called")) return;
command("help!");
ob1=present("nezha santaizi");
if( !ob1) {
seteuid(getuid());
ob1=new("/d/sky/npc/nezha3");
ob2=new("/d/sky/npc/guanyin");
ob1->move(environment());
ob2->move(environment());
}
message_vision("\n天上忽地传来一声怒喝,何人敢得罪陛下,我哪吒来也.\n\n",me);
message_vision("\n空中传来一声佛号:我佛慈悲!贫尼观音应玉帝之邀前来降魔.\n\n",me);
message_vision("\n玉帝狂笑道：哈哈哈哈！妖孽还不赶快降服！\n\n",me);
ob1->kill_ob(me);
ob2->kill_ob(me);
ob2->set_leader(me);
ob1->set_leader(me);
me->fight_ob(ob1);
me->fight_bo(ob2);
call_out("regenerate",300);
}
int regenerate()
{
  set("called",0);
  return 1;
}

void destruct_me (object me)
{
  destruct (me);
}


void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
void die()
{
   int i;
   string file;
   object *inv;
   object me = this_object();
   object ob = query_temp("my_killer");
    if(ob)  { ob->set_temp("yudi_killed",1);
             call_out ("puti_appearing",1,ob);}
    if( environment() ) {
     message("sound", "\n\n玉皇大帝狼狈不堪地在众人的护卫下躲了起来。\n\n",environment());
     command("ah");
     message("sound", "\n玉皇大帝大叫到：快到西天去请如来佛祖！！！\n\n", environment());
        inv = all_inventory(this_object());
        for(i=0; i<sizeof(inv); i++) {
        if (inv[i]->query("no_drop")) continue;
        do_drop(this_object(), inv[i]);
   }
   }
 load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);

}
void puti_appearing (object who)
{
  object puti = new ("/d/sky/npc/puti");
  puti->announce_success (who);
  destruct (puti);
}
void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{

  command("say 这是什么地方，企容你如此放肆！");
  return 0;
}
int do_drop(object me, object obj) {
  if (obj->move(environment(me))) {
      if((obj->query_temp("d_mana"))>0) {
            if( obj->query_temp("is_living")==1 )
                 message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
            else {
                 message_vision( sprintf("$N丢下一%s$n。\n",
                 undefinedp(obj->query_temp("unit"))?
                    "个":obj->query_temp("unit")
                         ), me, obj );
           }
      } else {
           if( obj->is_character() )
                  message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
           else {
             message_vision( sprintf("$N丢下一%s$n。\n", obj->query("unit")),
                     me, obj );
             if( !obj->query("value") && !obj->value() ) {
            tell_object(me,"因为这样东西并不值钱，所以人们并不会注意到它的存在
        。\n");
                destruct(obj);
             }
           }
      }
      return 1;
  }
  return 0;
}
