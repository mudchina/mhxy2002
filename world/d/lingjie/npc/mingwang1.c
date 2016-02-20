//created by focus
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
       set_name("降世明王", ({"jiangshi mingwang","jiangshi", "mingwang"}));
       set("long", "八叶老师的二大弟子之一\n");
       set("title", HIB"灵主"NOR);
       set("gender", "男性");
       set("age", 100);
       set("class", "lingjie");/*法师，天师*/
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "明王");
       set("per", 26);
       set("int", 30);
       set("max_kee", 2000);
       set("max_gin", 1000);
       set("max_sen", 2000);
       set("force", 4000);
       set("max_force", 3000);
       set("force_factor", 100);
       set("max_mana", 3000);
       set("mana", 6000);
       set("mana_factor", 100);
       set("combat_exp", 1000000);
        set("daoxing", 1000000);

       set_skill("literate", 120);
       set_skill("umbrella", 120);
       set_skill("lingfan-san", 120);
       set_skill("unarmed", 120);
       set_skill("dodge", 120);
       set_skill("parry", 120);
        set_skill("spells", 120);
        set_skill("kongming-spells", 120);
        set_skill("guangming-shouyin", 120);
        set_skill("guangming-force", 120);
        set_skill("force", 120);
        set_skill("fengtian-steps", 120);
        map_skill("spells", "kongming-spells");
        map_skill("unarmed", "guangming-shouyin");
        map_skill("force", "guangming-force");
        map_skill("umbrella", "lingfan-san");
        map_skill("dodge", "fengtian-steps");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "fengtianfu" :),
                (: perform_action, "lieshi" :),
}) );
create_family("灵界", 1, "红");
setup();

        carry_object("/d/lingjie/obj/yuyi")->wear();
        carry_object("/d/lingjie/obj/xianlv")->wear();
        carry_object("/d/lingjie/obj/hufa")->wield();
}

void attempt_apprentice(object ob)
{       ob=this_player();
        if( (string)ob->query("family/family_name")=="灵界") {
        if ((int)ob->query("daoxing") < 120000 ) {
        command("say 我们灵界注重修行，" + RANK_D->query_respect(ob) + "还需多加努力。\n");
        return;
        }
/*
        if( (int)ob->query("pending/kick_out")) {
        command("say 这位" + RANK_D->query_respect(ob) + "反复无常，本天尊不再收你为徒！\n");
        command("sigh");
        return;
        }
*/
/*        if ((int)ob->query_int() < 30) {
        command("say 这位" + RANK_D->query_respect(ob) + "悟性太低，恐怕收了你也难有作为！\n");
        command("sigh");
        return;
        }*/

        if( (int)ob->query_skill("kongming-spells", 1) < 60 ) {
        command("say 这位" + RANK_D->query_respect(ob) + "对我空明咒法领会还不够深，现在收你也是勉为其难，不如作罢！\n");
        command("sigh");
        return;
        }
        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
        command("recruit " + ob->query("id") );
        return;
        }
        command("shake");
        command("say 老夫不收非灵界弟子，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lingjie");
}

int accept_fight(object me, object ob)
{       ob=this_player();
        command("say " + RANK_D->query_rude(ob) + "杀心太重，恐祸不久已！\n");
        return 0;
}
void die()
{

        object ob;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
	if (ob){
        CHANNEL_D->do_channel(this_object(),"chat",sprintf("我被%s杀了，灵界的弟子为我报仇啊！",ob->name(1)));
        ::die();}

    
}

