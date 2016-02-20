//created by focus
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
       set_name("八叶的老师", ({"master baye","baye", "master"}));
       set("long", "与世界同时产生，从太古时代就主宰着灵界，是闺曼荼罗八叶的主宰\n");
       set("title", HIW"灵界师尊"NOR);
       set("gender", "男性");
       set("age", 300);
       set("class", "lingjie");/*法师，天师*/
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "天师");
       set("per", 30);
       set("int", 30);
       set("max_kee", 8000);
       set("max_gin", 8000);
       set("max_sen", 8000);
       set("force", 10000);
       set("max_force", 5000);
       set("force_factor", 200);
       set("max_mana", 5000);
       set("mana", 10000);
       set("mana_factor", 200);
       set("combat_exp", 3000000);
        set("daoxing", 10000000);

       set_skill("literate", 160);
       set_skill("unarmed", 200);
       set_skill("dodge", 200);
       set_skill("parry", 200);
       set_skill("sword", 200);
       set_skill("libieyu", 200);/*离别羽*/
        set_skill("spells", 200);
        set_skill("kongming-spells", 200);/*空明咒*/
        set_skill("guangming-shouyin", 200);/*光明大手印*/
        set_skill("guangming-force", 200);/*光明心法*/
        set_skill("force", 200);
        set_skill("fengtian-steps", 200);
        map_skill("spells", "kongming-spells");
        map_skill("unarmed", "guangming-shouyin");
        map_skill("force", "guangming-force");
        map_skill("parry", "libieyu");
        map_skill("dodge", "fengtian-steps");/*风天神紫云步*/
        map_skill("yumao", "libieyu");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "nine" :),/*大暗黑天咒*/
                (: perform_action, "zifu" :),/*风天神紫云步缚(pfm for dodge)*/
                (: perform_action, "piaofeng" :)/*柳絮飘风*/
        }) );

create_family("灵界", 1, "蓝");
setup();

        carry_object("/d/lingjie/obj/yuyi")->wear();
        carry_object("/d/lingjie/obj/xianlv")->wear();
        carry_object("/d/lingjie/obj/baiyu")->wield();
}

void attempt_apprentice(object ob)
{       ob=this_player();
        if( (string)ob->query("family/family_name")=="灵界") {
        if ((int)ob->query("daoxing") < 320000 ) {
        command("say 我们灵界注重修行，" + RANK_D->query_respect(ob) + "还需多加努力。\n");
        return;
        }

        if( (int)ob->query("pending/kick_out")) {
        command("say 这位" + RANK_D->query_respect(ob) + "反复无常，本天尊不再收你为徒！\n");
        command("sigh");
        return;
        }

        if ((int)ob->query_int() < 38) {
        command("say 这位" + RANK_D->query_respect(ob) + "悟性太低，恐怕收了你也难有作为！\n");
        command("sigh");
        return;
        }
        if( (int)ob->query_skill("kongming-spells", 1) < 180 ) {
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

