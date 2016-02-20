inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("温焰", ({ "wen yan", "wenyan", "yan"}));
        set("title", HIR"灵界四兽"NOR);   
        set("long", @LONG
全身覆有短毛,面部与身上皆有虎纹,一旦发怒
则全身转成火红,能行火中,狂奔时有如烈火行
走,行动迅速。但现在已经进化成人。
LONG);
        set("gender", "男性");
        set("age", 26);
        set("attitude", "peaceful");
        set("per", 10);
        set("rank_info/self", "火恨");
        set("rank_info/rude", "火尽杀");
        set("class", "lingjie");
        set("max_kee", 2500);
        set("max_gin", 2500);
        set("max_sen", 2500);
        set("force", 2800);
        set("max_force", 2800);
        set("force_factor", 200);
        set("max_mana", 2800);
        set("mana", 2800);
        set("mana_factor", 220);
        set("combat_exp", 2200000);
        set("daoxing", 1800000);

        set_skill("literate", 120);
        set_skill("spells", 160);
        set_skill("kongming-spells", 160);
        set_skill("unarmed", 150);
        set_skill("guangming-shouyin", 150);
        set_skill("dodge", 160);
        set_skill("fengtian-steps", 170);
     set_skill("parry", 160);
     set_skill("libieyu", 16);
     set_skill("force", 170);
    set_skill("yumao", 140);
        set_skill("guangming-force", 160);
        set_skill("umbrella", 150);
        set_skill("lingfan-san",150);

        map_skill("spells", "kongming-spells");
        map_skill("unarmed", "guangming-shouyin");
        map_skill("dodge", "fengtian-steps");
        map_skill("force", "guangming-force");
        map_skill("umbrella", "lingfan-san");
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: cast_spell, "nine" :),
                (: perform_action, "zifu" :),
                (: perform_action, "jiaoyang" :)
        }) );

        create_family("灵界", 2, "弟子");

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
