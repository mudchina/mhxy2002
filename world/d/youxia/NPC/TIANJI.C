// 大唐西游·幻想
//created 03-07-2001 海上飘(piao)

//tianji.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("天机老人", ({ "tianji laoren", "tianji","laoren" }) );
          set("title", HIM"闲云野鹤"NOR);
        set("loc_name", "天机老人");
        set("gender", "男性" );
        set("age", 100);
        set("int", 30);
        set("con", 30);
        set("per", 35);
        set("class", "youxia");
        set("attitude", "friendly");
        set("apprentice_available", 50);
        create_family("江湖浪子", 1, "蓝");
        set("long",
                "百晓生兵器谱中天下第一的天机老人，近几年很少在江湖中
出现的人物。\n" );
        set("force_factor", 100);
        set("mana_factor", 100);
        set("chat_chance", 5);
        set("max_gin", 5000);
        set("max_kee", 5000);
        set("max_sen", 5000);
        set("eff_gin", 5000);
        set("eff_kee", 5000);
        set("eff_sen", 5000);
        set("gin", 5000);
        set("kee", 5000);
        set("sen", 5000);
        set("max_force", 6000);
        set("force",3000);
        set("max_mana", 6000);
        set("mana", 3000);
        set("combat_exp", 2000000);
        set("daoxing", 2000000);
        set_skill("sword", 400);
        set_skill("baiyun-sword", 400);
        set_skill("force", 400);
        set_skill("dodge", 400);
        set_skill("piaoxiang", 400);
        set_skill("mozi-sword", 400);
        set_skill("unarmed", 400);
        set_skill("literate", 400);
        set_skill("parry", 400);
        set_skill("wuji-force", 400);
        set_skill("tanzhishentong", 400);
        set_skill("spells", 400);
        set_skill("tianjijue", 400);
        map_skill("spells", "tianjijue");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
           (: cast_spell, "freeze" :),
           (: random_move :),
        }) );

        setup();
//         carry_object("/d/youxia/obj/tianjipao")->wear();
//         carry_object("/d/youxia/obj/guai")->wield();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 1);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 1, ob);
        } else {
                command("say 老夫一天只收一个徒弟。");
        }
}
void do_recruit(object ob)
{
   if ( (string)ob->query("family/family_name")=="江湖浪子") {
   if (((int)ob->query("combat_exp") < 100000 )) {
   command("say 这位"+ RANK_D->query_respect(ob) + "你武功低微．．．．还是几年后再来找我吧。\n");
   return;
   }
        command("smile");
   command("say 很好，原来这位"  + RANK_D->query_respect(ob) +"是游侠儿的徒弟，好吧，本城主就收你为徒！\n");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。\n");
       command("recruit " + ob->query("id") );
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) + "既然已经派入他门,还是另寻他人吧！\n");
        return;
}


int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youxia");
                ob->set("title", HIM"天机老人亲授弟子"NOR);
        add("apprentice_availavble", -1);
}
int accept_object(object me,object ob)
{
        object m;
        if (ob->query("id")=="book") {
                command("pat" + this_player()->query("id") );
                m=new("/d/youxia/obj/tianji");
                m->move(this_player());
                message_vision("天机老人交给$N一本书，我留着也没多大用处，就送给你吧。\n", this_player());
                call_out("destroy", 1, ob);
        return 1;
        }
        else return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}

void announce_gift()
{
        object *alluser,obj,gift;
        int s;
        object me = this_object();

        alluser=users();        

        CHANNEL_D->do_channel(this_object(),"party","七夕佳节，我弟子可得礼物。");
        s=sizeof(alluser);
        for (int i=0;i<s;i++) {
            obj=alluser[i];
            if (obj!=me && obj->query("family/family_name")=="江湖浪子")
            {
            gift=new("/d/youxia/obj/tianji.c");
            gift->move(obj);
            message("vision",me->query("name")+"给你一"+gift->query("unit")+gift->name()+"。\n",obj);
            }
        }

        destruct(me);
        return;
}

