inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("胜奇", ({ "sheng qi", "shengqi", "qi"}));
        set("title", HIY"灵界四兽"NOR);   
        set("long", @LONG
全身覆盖长毛,仅脸与掌之毛稍短,双耳奇尖,掌肉
特厚,能以长尾缠树与藤蔓曳荡于林间。但以进化
为人行。
LONG);
        set("gender", "男性");
        set("age", 30);
        set("attitude", "peaceful");
        set("per", 20);
        set("rank_info/self", "雷音");
        set("rank_info/rude", "雷");
        set("class", "lingjie");
        set("max_kee", 1500);
        set("max_gin", 1500);
        set("max_sen", 1500);
        set("force", 2700);
        set("max_force", 2700);
        set("force_factor", 150);
        set("max_mana", 2800);
        set("mana", 2800);
        set("mana_factor", 160);
        set("combat_exp", 2000000);
        set("daoxing", 1500000);

        set_skill("literate", 150);
        set_skill("spells", 155);
        set_skill("kongming-spells", 155);
        set_skill("unarmed", 150);
        set_skill("guangming-shouyin", 150);
        set_skill("dodge", 160);
        set_skill("fengtian-steps", 160);
        set_skill("parry", 160);
        set_skill("force", 150);
        set_skill("guangming-force", 150);
        set_skill("umbrella", 160);
        set_skill("lingfan-san",160);

        map_skill("spells", "kongming-spells");
        map_skill("unarmed", "guangming-shouyin");
        map_skill("dodge", "fengtian-steps");
        map_skill("force", "guangming-force");
        map_skill("umbrella", "lingfan-san");

        create_family("灵界", 2, "弟子");

        setup();
        carry_object("/d/lingjie/obj/xianlv")->wear();
        carry_object("/d/lingjie/obj/yinyang")->wield();
        
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lingjie");
}

void attempt_apprentice(object ob)
{
	if ( (string)ob->query("family/family_name")=="灵界") {
	if (((int)ob->query("daoxing") < 200000 )) {
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