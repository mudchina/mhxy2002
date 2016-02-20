// By tianlin 2001.5.1
//By tianlin@mhxy for 2002.2.25重新修改

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include <obstacle.h>
void create()
{
        set_name("孔雀大明王菩萨", ({"kongque mingwang", "kongque", "mingwang", "wang", "pusa"}));
        set("title", HBRED+HIW"大雪山"HIY"开山祖师"NOR);
        set("gender", "男性" );
        set("age", 90);
        set("per", 30);
        set("str", 30);
        set("long", "这位孔雀明王是大鹏的师兄,武功诡异无比,其招数远远胜过大鹏明王。\n特别是他手上的这把剑,真是世间难得的把宝剑,听说他把这把剑当宝似的看待,\n据说大鹏明王还是跟孔雀明王学会的解体大法呢.\n");
        set("class", "yaomo");
        set("combat_exp", 11800000);
        set("daoxing", 3456000);

        set("attitude", "peaceful");
        create_family("大雪山", 1, "祖师");
        set("rank_info/respect", "明王");
        set_skill("unarmed", 285);
        set_skill("cuixin-zhang", 285);
        set_skill("dodge", 285);
        set_skill("xiaoyaoyou", 285);
        set_skill("parry", 285);
        set_skill("sword", 285);
        set_skill("bainiao-jian", 285);
        set_skill("blade", 285);
        set_skill("bingpo-blade", 285);
        set_skill("throwing", 285);
        set_skill("force", 285);   
        set_skill("ningxie-force", 285);
        set_skill("literate", 180);
        set_skill("spells", 285);
        set_skill("dengxian-dafa", 285);
        set_skill("yingzhaogong", 285);
        map_skill("spells", "dengxian-dafa");
        map_skill("force", "ningxie-force");
        map_skill("unarmed", "cuixin-zhang");
        map_skill("sword", "bainiao-jian");
        map_skill("blade", "bingpo-blade");
        map_skill("dodge", "xiaoyaoyou");

        set("max_kee", 3500);
        set("max_sen", 3500);
        set("force", 8500);
        set("max_force", 4800);
        set("mana", 3000);
        set("max_mana", 4000);  
        set("force_factor", 200);//我想了想,还是设他内力enforce高,法力enchant低吧,这样最起码能有个人杀的了他.snicker
        set("mana_factor", 10);

        set_temp("apply/damage", 50);
        set_temp("spply/armor", 50);
        set_temp("apply/dodge", 50);
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
                (: cast_spell, "juanbi" :),
                (: cast_spell, "jieti" :),//防止player杀他,我在入口处写名,孔雀大鹏最善长就是解体了.snicker By tianlin 2001.5.1
                (: cast_spell, "tuntian" :),
                (: perform_action, "sword", "chaofeng" :),

       }) );
            setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        carry_object("d/xueshan/obj/ningbi-jian")->wield();
}

void attempt_apprentice(object ob)
{
                int size = sizeof(obstacles);
        string *names = keys(obstacles);
        int i;
        for (i = 0; i < size; i++)
        if (ob->query("obstacle/"+names[i])!="done" && !wizardp(ob))
        {
           command("shake");
           command("say 这位" + RANK_D->query_respect(ob) + "尚未历尽西行难关，恐怕难以领悟高深武学。\n");
           return;
        }

        if( (string)ob->query("family/family_name")=="大雪山" ){
                if( (int)ob->query("family/generation") > 3   ){
                        command("say 没有四大护法的推荐，本王很难考虑。\n");
                }
                else {
                        if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 1500000 ){
                                command("nod ");
                                command("say 好，" + RANK_D->query_respect(ob) + "好好跟我干，将来大有可为！\n");
                                command("recruit " + ob->query("id") );
        message("channel:rumor",HIM+"【谣言】某人："BLINK+HIR+ob->query("name")+NOR+HIM"历经种种磨难,终于寻得孔雀明王！\n"NOR,users() );
                        }
                        else {
                                command("say 你还是先到大鹏明王那里练练吧。\n");
                        }
                }
        }

        else{
                command("hmm");
                command("say 这位" + RANK_D->query_respect(ob) + "，在本门可没有一步登天的事。\n");
        }

        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "yaomo");
              ob->set("title",HBWHT+HIG"孔雀明王座下寒冰使"NOR);
}

