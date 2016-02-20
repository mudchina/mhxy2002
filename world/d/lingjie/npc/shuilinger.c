inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("水灵儿", ({ "shui linger", "shuilinger", "linger"}));
        set("title", HIC"灵界四兽"NOR);   
        set("long", @LONG
长有一对大耳，如鸟之飞翼，通体成水蓝色，喜欢
在水域活动，一旦接近水边，便会在周身形成一个
蓝色的晶体，将其笼罩其中。因为如此，水灵儿便
能因此球的保护而在水中灵活如鱼。不过现以进化
成人。
LONG);
        set("gender", "女性");
        set("age", 21);
        set("attitude", "peaceful");
        set("per", 28);
        set("rank_info/self", "水灵");
        set("rank_info/rude", "水灵儿");
        set("class", "lingjie");
        set("max_kee", 1000);
        set("max_gin", 1000);
        set("max_sen", 1000);
        set("force", 2500);
        set("max_force", 2500);
        set("force_factor", 120);
        set("max_mana", 2500);
        set("mana", 2500);
        set("mana_factor", 120);
        set("combat_exp", 1500000);
        set("daoxing", 1000000);

        set_skill("literate", 140);
        set_skill("spells", 140);
        set_skill("kongming-spells", 140);
        set_skill("unarmed", 140);
        set_skill("guangming-shouyin", 140);
        set_skill("dodge", 140);
        set_skill("fengtian-steps", 140);
        set_skill("parry", 140);
        set_skill("force", 140);
        set_skill("guangming-force", 140);
        set_skill("umbrella", 140);
        set_skill("lingfan-san",140);

        map_skill("spells", "kongming-spells");
        map_skill("unarmed", "guangming-shouyin");
        map_skill("dodge", "fengtian-steps");
        map_skill("force", "guangming-force");
        map_skill("umbrella", "lingfan-san");

        create_family("灵界", 2, "弟子");

        setup();
        carry_object("/d/lingjie/obj/xianlv")->wear();
        carry_object("/d/lingjie/obj/zhehun")->wield();
        
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
