//created by focus
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
       set_name("浦饭幽助", ({"pufan youzhu","youzhu", "master"}));
       set("long", "小小年纪，却以深得波动拳的精华，威名远拨于魔、灵、人三界。\n");
       set("title", HIG"闽屋敷中学" HIR"No.1"NOR);
       set("gender", "男性");
       set("age", 20);
       set("class", "lingjie");/*法师，天师*/
       set("attitude", "heroic");
       set("shen_type", 1);
       set("rank_info/respect", "天师");
       set("per", 30);
       set("int", 30);
       set("max_kee", 80000);
       set("max_gin", 80000);
       set("max_sen", 80000);
       set("force", 100000);
       set("max_force", 50000);
       set("force_factor", 2000);
       set("max_mana", 50000);
       set("mana", 100000);
       set("mana_factor", 200);
       set("combat_exp", 35000000);
        set("daoxing", 80000000);

       set_skill("literate", 260);
       set_skill("unarmed", 300);
       set_skill("dodge", 300);
       set_skill("parry", 300);
       set_skill("libieyu", 300);
        set_skill("spells", 300);
        set_skill("kongming-spells", 300);
        set_skill("guangming-shouyin", 300);
        set_skill("guangming-force", 300);
        set_skill("force", 300);
        set_skill("fengtian-steps", 300);
        set_skill("umbrella", 300);
        set_skill("lingfan-san", 300);
        set_skill("yumao", 300);
        map_skill("spells", "kongming-spells");
        map_skill("unarmed", "guangming-shouyin");
        map_skill("force", "guangming-force");
        map_skill("parry", "libieyu");
        map_skill("dodge", "fengtian-steps");/*风天神紫云步*/
        map_skill("yumao", "libieyu");
        map_skill("umbrella", "lingfan-san");
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
        carry_object("/d/lingjie/obj/san");
}

void attempt_apprentice(object ob)
{       
      ob=this_player();
      if( (int)ob->query("family/generation") > 2) {
      command("shake");
      command("say 你还是先去找八叶老师吧！\n");
      return;      
      }
      if( (string)ob->query("family/family_name")=="灵界") {
        if ((int)ob->query("combat_exp") < 5000000 ) {
        command("say 就着点本事也跟想跟我学？，" + RANK_D->query_respect(ob) + "还是再去练练吧。\n");
        return;
        }

        if( (int)ob->query("pending/kick_out")) {
        command("say 这位" + RANK_D->query_respect(ob) + "反复无常，本天尊不再收你为徒！\n");
        command("sigh");
        return;
        }
        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
        command("recruit " + ob->query("id") );
        return;
      }
      command("shake");
      command("say 不是灵界的？，" + RANK_D->query_respect(ob) + "我可不敢受，莹子会骂我的哦！\n");
      return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lingjie");
}

int accept_fight(object me, object ob)
{       ob=this_player();
        command("say " + RANK_D->query_rude(ob) + "来吧，我最喜欢打架了！！\n");
        return 0;
}

