//icejia.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
       set_name(HIG"晦明大师"NOR, ({"huiming dashi", "huiming", "dashi","master"}));
       set("long", "调和神晦明大师是一位非常慈善的长者\n");
       set("title", HIW"调 和 神"NOR);
       set("gender", "女性");
       set("age", 30);
        set("class", "xian");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "妹妹");
       set("per", 30);
       set("int", 30);
       set("max_kee", 8000);
       set("max_gin", 1000);
       set("max_sen", 8000);
       set("force", 20000);
       set("max_force", 10000);
       set("force_factor", 300);
       set("max_mana", 10000);
       set("mana", 20000);
       set("mana_factor", 200);
       set("combat_exp", 10000000);
        
      set_skill("literate", 310);
       set_skill("unarmed", 310);
       set_skill("dodge", 310);
       set_skill("force", 310);
       set_skill("parry", 310);
       set_skill("spells", 310);
       set_skill("sword", 320);
       set_skill("throwing", 320);
       set_skill("xiaoyao-sword", 320);
       set_skill("feiyu", 320);
       set_skill("baimofa", 300);
   set_skill("piaoyun-zhang", 280);
   set_skill("mtl-force", 300);
   set_skill("shanbishu", 300);
   
   map_skill("spells", "baimofa");
   map_skill("unarmed", "piaoyun-zhang");
   map_skill("force", "mtl-force");
   map_skill("sword", "xiaoyao-sword");
   map_skill("throwing", "feiyu");
   map_skill("parry", "xiaoyao-sword");
   map_skill("dodge", "shanbishu");
   set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: cast_spell, "zhanyan" :),
//              (: cast_spell, "suliao" :),
        }) );

create_family("天空界", 1, "师傅");
setup();

//        carry_object("/d/obj/armor/jinjia.c")->wear();
//        carry_object("/d/qujing/wudidong/obj/xueyin.c")->wield();
}

void attempt_apprentice(object ob)
{       ob=this_player();
        if( (string)ob->query("family/family_name")=="天空界") {
     if ((int)ob->query("combat_exp") < 1000000 ) {
        command("say 你的实战经验不足，" + RANK_D->query_respect(ob) + "多练练再来。要不你会丢了天空界的脸了。\n");
        return;
        }

    if( (int)ob->query_skill("mtl-force", 1) < 150 ) {
        command("say 这位" + RANK_D->query_respect(ob) + "的内力不够深厚，不能跟随我修行。\n");
        command("sigh");
        return;
        }
        command("smile");
        command("say 好！" + RANK_D->query_respect(ob) + "以后一定要好好努力！保卫天空界。");
        command("recruit " + ob->query("id") );
        ob->set("title",HIY"守 护 神"NOR);
        ob->save();
        return;
        }
        command("shake");
        command("say 你是什么人？" + RANK_D->query_respect(ob) + "想死么！！！\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                  ob->set("class", "tiankongjie");
}

int accept_fight(object me, object ob)
{       ob=this_player();
        command("say 不行" + RANK_D->query_rude(ob) + "还是快走吧。\n");
        return 0;
}
void die()
{

        if( environment() ) {
        message("sound", "\n\n看来天界的安宁要被打乱了。\n\n", environment());
        command("sigh");
        message("sound", "\n金光过后，晦明大师消失不见了。\n\n", environment());
        }

        destruct(this_object());
}


