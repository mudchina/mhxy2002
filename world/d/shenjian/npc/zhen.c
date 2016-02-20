//By tianlin@mhxy for 2002.1.10从新改编

inherit NPC;
inherit F_MASTER;
int rank_me();
string ask_mieyao();
string ask_cancel();
string ask_for_leave();
#include <ansi.h>
void create()
{
        set_name(HIG"铁真真"NOR, ({ "tie zhenzhen", "tie", "zhenzhen", "zhen"}) );
        set("gender", "女性" );
        set("age", 21);
        set("agi",30);
        set("str", 60);
        set("per", 21);
        set("int",30);
        set("nickname",HIR"一剑"HIW"舞雪"NOR);
        set("attitude","friendly");
        set("max_force", 3000);
        set("force", 3000);
        set("force_factor", 200);
        set("max_mana", 3000);
        set("mana", 3000);
        set("max_atman", 3000);
	 set("max_kee",2000);
        set("max_gin",2000);
        set("max_sen",2000);
        set("chat_chance", 30);
        set("long",
"她正是谢晓锋的入室大弟子，深得剑神的真传。\n"
        );
        create_family("神剑山庄",2,"掌门大弟子");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword", "jianqizongheng" :),
        }) );
       set("inquiry", ([
           "杀魔": (: ask_mieyao :),
           "cancel": (: ask_cancel :),
           "职位": (: rank_me :),
           "leave" : (: ask_for_leave :),
]));
       set("combat_exp", 2300000);
       set("daoxing", 2300000);
       set_skill("literate", 120);
       set_skill("unarmed", 120);
       set_skill("dodge", 120);
       set_skill("force", 140);
       set_skill("parry", 165);
       set_skill("sword", 185);
       set_skill("spells", 145);
       set_skill("blade", 125);
       set_skill("lianhuan-zhang", 155);
       set_skill("duo-sword", 185);
       set_skill("qingfeng-jian", 185);
       set_skill("cloudforce", 135);
       set_skill("shadowsteps", 145);
       set_skill("xueying-xianfa", 130);
       set_skill("shenji-blade", 150);
       map_skill("spells", "xueying-xianfa");
       map_skill("unarmed", "lianhuan-zhang");
       map_skill("force", "cloudforce");
       map_skill("sword", "qingfeng-jian");
       map_skill("parry", "duo-sword");
       map_skill("dodge", "shadowsteps");
       map_skill("blade", "shenji-blade");
        setup();
       // carry_object(__DIR__"obj/deitysword")->wield();
      //  carry_object(__DIR__"obj/sjcloth")->wear();
}

void attempt_apprentice(object ob)
{

   if ( (string)ob->query("family/family_name")=="神剑山庄") {
if (((int)ob->query("combat_exp") < 200000 )) {
   command("say " + RANK_D->query_respect(ob) +
"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
   return;
   }
        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"他日还要在剑法上多加以练习。\n");
       command("recruit " + ob->query("id") );
	   ob->set("title", HIW"神剑山庄"HIG"铁真真"HIY"坐下大弟子"NOR);
	   ob->set("class", "shenjian");
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"还是先去学些基础功夫吧。\n");
        return;
}
int accept_fight(object me)
{
   return 0;
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shenjian");
}

void re_rank(object who)
{
    int faith=who->query("faith");
    if(who->query("class")!="taoist")return;
    if(faith<=100){
        if(who->query("gender")=="女性")
           who->set("title",HIW"神剑山庄"BLINK+HIM"玉女护法"NOR);
        else who->set("title",HIW"神剑山庄"BLINK+HIR"左护法"NOR);
        return;
     }else if(faith<=300){
        who->set("title",HIW"神剑山庄"BLINK+HIG"右护法"NOR);
        return;
     }else if(faith<=600){
        who->set("title",HIW"神剑山庄"BLINK+HIY"剑魂"NOR);
        return;
    }else if(faith<=1000){
        who->set("title",HIW"神剑山庄"BLINK+HIC"剑王"NOR);
        return;
    }else if(faith<=1800){
        who->set("title",HIW"神剑山庄"BLINK+BLK"剑贫"NOR);
        return;
    }else if(faith<=3000){
        who->set("title",HIW"神剑山庄"BLINK+HIC"剑神"NOR);
        return;
    }else if(faith<=6000){
        who->set("title",HIW"神剑山庄"BLINK+HIG"剑帝"NOR);
        return;
    }else who->set("title",HIW"神剑山庄"BLINK+HBRED+HIW"剑魔"NOR);
    return;
}
void init()
{
        add_action("do_agree", "agree");
}
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "掌门")
		return notify_fail("你已经是掌门人了，还来要什么职位．\n");
        if( (string)me->query("family/family_name") == "神剑山庄"){
                if( exp <= 100000 ){
                        me->set("title", HBRED+WHT"神 剑 山 庄"NOR+HIY"舞剑总提督"NOR);
                 } else if(exp < 1000000 ){
                        me->set("title", HBRED+WHT"神 剑 山 庄"NOR+HIM"梦魂使者"NOR);
                 } else if(exp < 2000000 ){
                        me->set("title", HBRED+WHT"神 剑 山 庄"NOR+HIR"狂刀剑魔"NOR);
                 } else if(exp < 3000000 ){
                        me->set("title", HBRED+WHT"神 剑 山 庄"NOR+HIB"夺魂剑贫"NOR);
                } else {
                        me->set("title", HBRED+WHT"神 剑 山 庄"NOR+HIC"剑神传人"NOR);
                }

                tell_object(me, "谢晓峰对你说：你可以做"+me->query("title")+"。\n");
                tell_room(environment(me),
"谢晓峰对"+me->query("name")+"说：你可以做"+me->query("title")+"。\n", ({me, me}));
         CHANNEL_D->do_channel(me,"chat","现授予本门弟子"+me->query("name")+""NOR+me->query("title")+HIC"一职。恭请各位仙长多加捧场！");
     me->save();  
        }
        return 1;
}

string ask_mieyao()
{
    object who=this_player();

    if((string)who->query("family/family_name")=="神剑山庄") {
      command("smile "+who->query("id"));
      return "/d/obj/mieyao"->query_yao(who);
    }
    return ("非我门人,何故来此?\n");
}
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("没用的东西！");
}
else
{
     return ("你有任务吗？！");
}
}
string ask_for_leave()
{
        object me=this_player();

        if (me->query("family/family_name") == "神剑山庄" ) {
                command("say 你既是执意要出庄，妾身却有几句话说。");
                me->set_temp("betray/sj", 1);
                return ("脱离师门要需要有一定惩罚，你可愿意(agree)？");
        }

        return ("妾身不知。\n");
}
int do_agree(string arg)
{
        if(this_player()->query_temp("betray/sj")) {
                message_vision("$N答道：弟子愿意。\n\n", this_player());
                command("say 既是你与神剑山庄无缘，你便出庄去吧！");
                this_player()->add("betray/count", 1);
                this_player()->add("betray/shenjian", 1);
                this_player()->set("combat_exp", this_player()->query("combat_exp")*60/100);
                this_player()->set("daoxing", this_player()->query("daoxing")*60/100);
                if( this_player()->query_skill("duo-sword") )
                    this_player()->delete_skill("duo-sword");
                if( this_player()->query_skill("xueying-xianfa") )
                    this_player()->delete_skill("xueying-xianfa");

                
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "普通百姓");
                this_player()->set_temp("betray", 0);
                this_player()->save();
                command("say 江湖风波，善恶无形，好自为之。。。\n");
                command("rumor "HBRED+HIW"神剑山庄"NOR+HIG"江湖通达令"HIC+this_player()->query("name")+HIY"已再不是我"HBRED+HIW"神剑山庄"NOR+HIY"的人了！"NOR);
                return 1;
        }
}
