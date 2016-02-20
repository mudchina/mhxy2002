//by tianlin 2001.7.30
inherit NPC;
inherit F_MASTER;
int rank_me();
string ask_for_leave();
#include <ansi.h>

void create()
{
       set_name("春春", ({"chun chun", "chunchun", "master"}));
       set("long",
"她乃是开封城数一数二的高手．\n");
       set("title", MAG"小靓妹"NOR);
       set("gender", "女性");
       set("age", 20);
       set("class", "kaifeng");
       set("attitude", "friendly");
       set("rank_info/respect", "漂亮");
       set("per", 30);
	set("int", 30);
	set("str", 730);
       set("max_kee", 19500);
       set("max_gin", 19500);
       set("max_sen", 19500);
       set("force", 1500);
       set("max_force", 1700);
       set("force_factor", 80);
       set("max_mana", 2000);
       set("mana", 3000);
       set("mana_factor", 120);
       set("combat_exp", 1200000);
  set("daoxing", 1100000);


        set("eff_dx", 70000);
        set("nkgain", 260);

  set_skill("unarmed", 142);
  set_skill("dodge", 127);
  set_skill("parry", 130);
  set_skill("rake", 150);
  set_skill("force", 120);
  set_skill("spells", 130);
  set_skill("fofa", 130);
  set_skill("literate", 160);
  set_skill("tianpeng-zhang", 120);
  set_skill("bajie-force", 140);
  set_skill("chaos-steps", 120);
  set_skill("skyriver-rake", 120);
  map_skill("force", "bajie-force");
  map_skill("spells", "fofa");
  map_skill("rake", "skyriver-rake");
  map_skill("unarmed", "tianpeng-zhang");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "chaos-steps");
        set("inquiry", ([
         "leave" : (: ask_for_leave :),
         "职位": (: rank_me :),
                ]) );
create_family("天蓬帅府", 2, "弟子");
setup();

  carry_object("/d/kaifeng/obj/jiuchipa")->wield();
  carry_object("/d/obj/armor/tongjia")->wear();
}
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "天蓬帅府掌门")
		return notify_fail("你已经是掌门人了，还来要什么职位．\n");
        if( (string)me->query("family/family_name") == "天蓬帅府"){
                if( exp <= 100000 ){
                        me->set("title", HIY"天蓬帅府"WHT"伺女"NOR);
                  } else if(exp <= 1000000 ){
                        me->set("title", HIY"天蓬帅府"WHT"惊虹舞姬"NOR);
                  } else if(exp <= 2000000 ){
                        me->set("title", HIY"天蓬帅府"WHT"飘渺舞仙"NOR);
                  } else if(exp <= 3000000 ){
                        me->set("title", HIY"天蓬帅府"WHT"逍遥圣女"NOR);
                } else {
                        me->set("title", HIY"天蓬帅府"WHT"补天圣母"NOR);
                }

                tell_object(me, "春春对你说：你可以做"+me->query("title")+"。\n");
                tell_room(environment(me),
"春春对"+me->query("name")+"说：你可以做"+me->query("title")+"。\n", ({me, me}));
         CHANNEL_D->do_channel(me,"chat","现授予本门弟子"+me->query("name")+""+me->query("title")+"一职。恭请各位仙长多加捧场！");
     me->save();  
        }
        return 1;
}
void attempt_apprentice(object ob)
{

        if( (string)ob->query("family/family_name")=="天蓬帅府" ){
                if( (int)ob->query("family/generation") < 2  ){
                        command("say 不敢，不敢。我该拜" + RANK_D->query_respect(ob) + "您为师才是。\n");
                }
                else if( (int)ob->query("family/generation") ==2  ){
                        command("say 你这个" + RANK_D->query_rude(ob) + "别来消遣你家姑奶奶我了！\n");
                }
                else if( (int)ob->query("family/generation") ==3  ){
                        command("blush ");
                        command("say 你这个" + RANK_D->query_rude(ob) + "，这是你自愿的，可不算我挖墙角...\n");
                        command("recruit " + ob->query("id") );
                        message("system", HIY"我天蓬帅府又多了一个弟子  "+this_player()->name()+HIW"
                 天蓬帅府的势力加强了。\n"NOR,users());
                }
                else {
                        if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 200000 ){
                                command(":) ");
                                command("say 好，" + RANK_D->query_respect(ob) + "既然到我门下就得给我争气，可不许偷懒！\n");
                                command("recruit " + ob->query("id") );
                        }
                        else {
                                command("say 你还是找别人先练着吧。\n");
                        }
                }
        }

        else{
                command("hmm");
                command("say 这位" + RANK_D->query_respect(ob) + "，你还是找别人先练练吧。\n");
        }

        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "tianpeng");
}
void init()
{
        add_action("do_agree", "agree");
}

string ask_for_leave()
{
        object me=this_player();

        if (me->query("family/family_name") == "天蓬帅府" ) {
                command("say 你既是执意出城，妾身却有几句话说。");
                me->set_temp("betray/tp", 1);
                return ("脱离师门要需要有一定惩罚，你可愿意(agree)？");
        }

        return ("妾身不知。\n");
}
int do_agree(string arg)
{
        if(this_player()->query_temp("betray/tp")) {
                message_vision("$N答道：弟子愿意。\n\n", this_player());
                command("say 既是你与天蓬帅府无缘，你便出城吧去吧！");
                this_player()->add("betray/count", 1);
                this_player()->add("betray/tianpeng", 1);
                this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
                this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
                if( this_player()->query_skill("fofa") )
                    this_player()->delete_skill("fofa");
                if( this_player()->query_skill("skyriver-rake") )
                    this_player()->delete_skill("skyriver-rake");

                
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "普通百姓");
                this_player()->set_temp("betray", 0);
                this_player()->save();
                command("say 江湖风波，善恶无形，好自为之。。。\n");
                return 1;
        }
}
