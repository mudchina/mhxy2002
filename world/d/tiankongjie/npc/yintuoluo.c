//icejia.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
       set_name(HIB"因 陀 罗"NOR, ({"yintuo luo", "yintuo", "luo","master"}));
       set("long", "十二罗帝，雷帝转世。\n");
       set("title", HIR"雷   帝"NOR);
       set("gender", "男性");
       set("age", 9000);
        set("class", "xian");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老爷子");
       set("per", 30);
       set("int", 30);
       set("max_kee", 6000);
       set("max_gin", 1000);
       set("max_sen", 6000);
       set("force", 20000);
       set("max_force", 10000);
       set("force_factor", 300);
       set("max_mana", 10000);
       set("mana", 20000);
       set("mana_factor", 200);
       set("combat_exp", 10000000);
        
      set_skill("literate", 210);
       set_skill("unarmed", 210);
       set_skill("dodge", 210);
       set_skill("force", 210);
       set_skill("parry", 210);
       set_skill("spells", 210);
       set_skill("blade", 220);
       set_skill("tianlang-blade", 220);
       set_skill("heimofa", 200);
   set_skill("piaoyun-zhang", 180);
   set_skill("shouya-force", 200);
   set_skill("shanbishu", 200);
   
   map_skill("spells", "heimofa");
   map_skill("unarmed", "piaoyun-zhang");
   map_skill("force", "shouya-force");
   map_skill("blade", "tianlang-blade");
   map_skill("parry", "tianlang-blade");
   map_skill("dodge", "shanbishu");
   set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: cast_spell, "zhonglixin" :),
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
        if ((int)ob->query("combat_exp") < 300000 ) {
        command("say 你的实战经验不足，" + RANK_D->query_respect(ob) + "多练练再来。要不你会丢我的脸了。\n");
        return;
        }

        if( (int)ob->query_skill("shouya-force", 1) < 100 ) {
        command("say 这位" + RANK_D->query_respect(ob) + "的内力不够深厚，不能跟随我修行。\n");
        command("sigh");
        return;
        }
        command("smile");
        command("say 好！" + RANK_D->query_respect(ob) + "以后一定要好好努力！让天空界重生。");
        command("recruit " + ob->query("id") );
        ob->set("title",HIW"十二 罗帝"NOR);
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
        message("sound", "\n因陀罗消失在一阵雷鸣之后！\n\n", environment());
        }

        destruct(this_object());
}


