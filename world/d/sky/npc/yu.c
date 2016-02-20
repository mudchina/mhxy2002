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
        setup();
        carry_object("/d/obj/cloth/longpao")->wear();
        carry_object("/d/sky/obj/tianguan")->wear();
        carry_object("/d/sky/obj/yunxue")->wear();
}
string give_me()
{
object me = this_player();
carry_object("/d/sky/obj/yuling");
command("give yu to " +me->query("id"));
command("fear");
say("玉帝说道:这白玉令是朕掌管天上诸神所用之物,上仙如何想要!!\n");
say("玉帝又道:不过上仙既然想要的话,朕今天就给了你!\n");
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
