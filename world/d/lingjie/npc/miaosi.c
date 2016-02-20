inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("妙思", ({ "miao si", "miaosi", "si"}));
        set("title", HIW"灵界四兽"NOR);   
        set("long", @LONG
脸部似熊,形体较其他灵兽大许多,全身长有黄
色的短毛,行动时有如海狗,喜欢在雪地里翻滚
因为常常以前肢支撑脸部,做出思考状。但现在
以进化成人。
LONG);
        set("gender", "女性");
        set("age", 35);
        set("attitude", "peaceful");
        set("per", 25);
        set("rank_info/self", "金皆覆");
        set("rank_info/rude", "金迷");
        set("class", "tianshi");
        set("max_kee", 3000);
        set("max_gin", 3000);
        set("max_sen", 3000);
        set("force", 3000);
        set("max_force", 3000);
        set("force_factor", 250);
        set("max_mana", 3000);
        set("mana", 3000);
        set("mana_factor", 250);
        set("combat_exp", 2800000);
        set("daoxing", 2000000);

        set_skill("literate", 150);
        set_skill("spells", 180);
        set_skill("kongming-spells", 180);
        set_skill("unarmed", 180);
        set_skill("guangming-shouyin", 180);
        set_skill("dodge", 180);
        set_skill("fengtian-steps", 180);
        set_skill("parry", 170);
        set_skill("force", 180);
        set_skill("guangming-force", 180);
        set_skill("umbrella", 200);
        set_skill("lingfan-san",200);

        map_skill("spells", "kongming-spells");
        map_skill("unarmed", "guangming-shouyin");
        map_skill("dodge", "fengtian-steps");
        map_skill("force", "guangming-force");
        map_skill("umbrella", "lingfan-san");

        create_family("灵界", 1, "弟子");

        setup();
        carry_object("/d/lingjie/obj/xianlv")->wear();
        carry_object("/d/lingjie/obj/yinyang")->wield();
        
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "tianshi");
}

void attempt_apprentice(object ob)
{
	if ( (string)ob->query("family/family_name")=="灵界") {
	if (((int)ob->query("daoxing") < 1000000 )) {
	command("say 不行，" + RANK_D->query_respect(ob) + "你道行过底，我受了你怕别人不服。\n");
	return;
	}
        command("jump");
	command("say 乐哉，快哉。你"  + RANK_D->query_respect(ob) +
"这样的人才却是少见！\n");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日振兴我灵界。\n");
       command("recruit " + ob->query("id") );
	return;
	}
	command("shake");
	command("say 你是谁，我好象没见过" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
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