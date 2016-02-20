//icejia.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
       set_name(RED"血·舞"NOR, ({"xie wu", "xie", "wu","master"}));
       set("long", "破坏神，希望毁灭世界再重塑世界的人。\n");
       set("title", HIR"破 坏 神"NOR);
       set("gender", "男性");
       set("age", 20);
        set("class", "xian");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "神");
       set("per", 30);
       set("int", 30);
       set("max_kee", 10000);
       set("max_gin", 1000);
       set("max_sen", 10000);
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
       set_skill("blade", 320);
       set_skill("tianlang-blade", 320);
       set_skill("heimofa", 300);
   set_skill("piaoyun-zhang", 280);
   set_skill("shouya-force", 300);
   set_skill("shanbishu", 300);
   
   map_skill("spells", "heimofa");
   map_skill("unarmed", "piaoyun-zhang");
   map_skill("force", "shouya-force");
   map_skill("blade", "tianlang-blade");
   map_skill("parry", "tianlang-blade");
   map_skill("dodge", "shanbishu");
   set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: cast_spell, "zhonglixin" :),
              (: cast_spell, "heijie" :),
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
        command("say 你的实战经验不足，" + RANK_D->query_respect(ob) + "多练练再来。要不你会丢我的脸了。\n");
        return;
        }

      if( (int)ob->query_skill("shouya-force", 1) < 150 ) {
        command("say 这位" + RANK_D->query_respect(ob) + "的内力不够深厚，不能跟随我修行。\n");
        command("sigh");
        return;
        }
        command("smile");
        command("say 好！" + RANK_D->query_respect(ob) + "以后一定要好好努力！让世界重生。");
        command("recruit " + ob->query("id") );
        ob->set("title",HIR"神军领袖"NOR);
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
        message("sound", "\n\n看来天界大乱在即，哈哈！\n\n", environment());
        command("sigh");
        message("sound", "\n血·舞消失在一阵血光之后！\n\n", environment());
        }

        destruct(this_object());
}


