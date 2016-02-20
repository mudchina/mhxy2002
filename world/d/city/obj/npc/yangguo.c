inherit NPC;
inherit F_MASTER;
#include <ansi.h> 
string ask_me();
void create()
{
        set_name("杨过", ({ "yang guo", "yang" }));
        set("nickname", "神雕侠");
      set("long", 
                "他就是神雕大侠杨过，一张清癯俊秀的脸孔，剑眉入鬓，凤眼生威。\n"
                "虽然他只有一只胳膊，但是魁伟的身材仍让人感觉英气逼人。\n");
        set("gender", "男性");
        set("age", 32);
        set("attitude", "friendly");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
     set("max_kee", 5000);
        set("max_sen", 3000);
        set("force", 10000);
        set("max_force", 5000);
        set("eff_sen", 3000);
        set("enforce_actor", 150);
        set("combat_exp", 2000000);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
            set("inquiry", 
                ([
                           "运气之道" : (: ask_me :),
              ]));
        create_family("古墓派", 2, "神雕侠侣");
        setup();
      carry_object("/u/fly/obj/jzj")->wield();
}

void attempt_apprentice(object ob)
{
        mapping fam; 
        ob = this_player();
        fam = ob->query("family");
       if (!fam || fam["family_name"] != "古墓派"){
                command("say "+RANK_D->query_respect(ob)+"非我古墓传人，不知此话从何谈起？");
                return;
                }    
//        for(i=0; i<sizeof(skl); i++) {
//		if (skl[sname[i]] < 100) 
//		command("say 古墓的基本武学未纯，难以学好我的功夫，还是回去先把武功根基打好吧。");
//                return;
//	}   
        if ((int)ob->query_skill("yunu-xinjing",1)<100){
                command("say 这位" + RANK_D->query_respect(ob) +
                        "你的玉女心经未纯，难以领悟更高的武学。");
                return;
        
}
       if ((int)ob->query_skill("yunu-shenfa",1)<100){
                command("say 这位" + RANK_D->query_respect(ob) +
                        "你的玉女身法未纯，难以领悟更高的武学。");
                return;
        }
        if ((int)ob->query_skill("yunu-jianfa",1)<100){
                command("say 这位" + RANK_D->query_respect(ob) +
                        "你的玉女剑法未纯，难以领悟更高的武学。");
                return;
        }
      if ((int)ob->query_skill("cuff",1)<100){
                command("say 这位" + RANK_D->query_respect(ob) +
                        "你的基本拳法未纯，难以领悟更高的武学。");
                return;
        }
        if ((int)ob->query_skill("sword",1)<100){
                command("say 这位" + RANK_D->query_respect(ob) +
                        "你的基本剑法未纯，难以领悟更高的武学。");
                return;
        }
     if ((int)ob->query_skill("strike",1)<100){
                command("say 这位" + RANK_D->query_respect(ob) +
                        "你的基本掌法未纯，难以领悟更高的武学。");
                return;
        }
       if (ob->query_int() < 30) {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "你目前的资质难以领悟更高的武学。");
                return;
        }
   message_vision(HIY "杨过突然微一提气，纵身越起演示了一套身法，似行云流水，又如流星追月。\n"NOR,ob);
       write(HIY"你看着看着，突然对身法体会深了一层，你的身法加1。\n"NOR);
       
        command("pat " + ob->query("id"));
        command("chat* 脸上浮现出一丝笑容，然后又深情的看了一眼小龙女。");
        command("recruit " + ob->query("id"));
        ob->set("title",HIW"古墓派神雕侠侣传人"NOR);
        ob->add("dex",1);
}
string ask_me()
{ 
       mapping fam; 
       object ob;
       ob = this_player();
       if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派"
             ||  fam["master_name"] != "杨过")
               return RANK_D->query_respect(this_player()) + 
               "非我古墓传人,不知道此话怎讲?";
          if (!ob->query_temp("xth_hm"))
            return RANK_D->query_respect(this_player()) + 
               "想知道什麽运气之道呢?";
                      ob->delete_temp("xth_hm");
               ob->set_temp("make/xtj_look1",1);
            ob->set_temp("yg_pbask",1);
       return "屏气具息,凝气守中,双肩放松,意守丹田,这是在洪水中运气的诀窍,你好好去领悟一下.";
}

void kill_ob(object me)
{
        command("chat* nomatch " + me->query("id"));
        
        ::kill_ob(me);
}
      
