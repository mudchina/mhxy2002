// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//created 4-8-97 pickle
inherit NPC;
string give_me();
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
               "白玉令" : (: give_me :),
        ]) );
        set("no_ling",0);
        setup();
        carry_object("/d/obj/cloth/longpao")->wear();
        carry_object("/d/sky/obj/tianguan")->wear();
        carry_object("/d/sky/obj/yunxue")->wear();
}
string give_me()
{
object me = this_player();
if( query("no_ling") == 0)
{
 object ob;
ob=new("/d/sky/obj/baiyu-ling");
command("fear");
say("玉帝说道:这白玉令是朕掌管天上诸神所用之物,上仙如何想要!!\n");
set("no_ling",1);
say("玉帝说道:不过上仙既然想要的话,朕今天就给了你!\n");
ob->move(me);
message_vision("玉帝给了$n一支白玉令!\n");
command("hehe");
if( environment() ) {
message("sound","\n\n玉皇大帝慌慌张张地驾起一朵彩云,向东南方飞去....\n\n
看他飞的方向,好像是直奔南海普陀山....\n\n", environment());
}
ob=new("/d/nanhai/npc/guanyin");
ob->move(environment());
message_vision("\n空中传来一声佛号:我佛慈悲!贫尼观音应玉帝之邀前来降魔.\n\n",me);
ob->kill_ob(me);
ob->set_leader(me);
me->fight_ob(ob);
destruct(this_object());
return "不好!\n";
}

  else {
return "玉帝说道: 这白玉令适才我已经给了别人,如何还有第二支给你!!\n";
}
}
void accept_kill(object me)
{ object ob;
if( is_fighting()) return;
if( query("called")) return;
command("help!");
ob=present("nezha santaizi");
if( !ob) {
seteuid(getuid());
ob=new("/d/sky/npc/nezha");
ob->move(environment());
}
message_vision("\n天上忽地传来一声怒喝,何人敢得罪陛下,我哪吒来也.\n\n",me);
ob->kill_ob(me);
ob->set_leader(me);
me->fight_ob(ob);
call_out("regenerate",300);
}
int regenerate()
{
  set("called",0);
  return 1;
}
