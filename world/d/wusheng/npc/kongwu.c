// kongwu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
//string expell_me(object me);
string ask_mieyao(object me);
string ask_cancel();

void create()
{
       set_name(HIW"孔武大帝"NOR, ({"master dadi", "dadi", "master"}));
       set("long", "中国五千年传奇人物，自盘古开天以来便掌管着所有的武技。\n");
       set("title", HIC"武帝圣君"NOR);
       set("gender", "男性");
       set("age", 100);
       set("class", "wusheng");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "大帝");
       set("looking", "玉面多光润，苍髯颌下飘，金睛飞火焰，长目过眉梢。");
        set("max_kee", 5000);
        set("max_gin", 5000);
        set("max_sen", 5000);
        set("force", 4000);
        set("max_force", 2000);
        set("force_factor", 145);
        set("max_mana", 3000);
        set("mana", 6000);
        set("mana_factor", 150);
        set("combat_exp", 2000000);
        set("daoxing", 10000000);


        set_skill("unarmed", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_skill("spells", 280);
        set_skill("feisheng", 280);
        set_skill("literate", 200);
        set_skill("sword", 280);
        set_skill("wuying", 300);
        set_skill("fumobashi", 280);  
        set_skill("mizongbu", 270);
        set_skill("dodge", 280);  
        set_skill("force", 280); 
        set_skill("xiantian", 280);

        map_skill("spells", "feisheng");
        map_skill("unarmed", "fumobashi");
        map_skill("force", "xiantian");
        map_skill("sword", "wuying");
        map_skill("parry", "wuying");
        map_skill("dodge", "mizongbu");
        set("chat_chance_combat", 60);
/*           set("inquiry", ([
                "下山":    (: expell_me :),
                "leave":   (: expell_me :),
 ]) );     */

	create_family("武圣门", 1, "尊者");
	
        setup();
        //carry_object("/d/wusheng/obj/armor")->wear();
        //carry_object("/d/wusheng/obj/cloth")->wear();
        //carry_object("/d/wusheng/obj/pifeng")->wear();
        //carry_object("/d/wusheng/obj/sword")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="武圣门") {
	if ((int)ob->query("daoxing") < 500000 ) {
  	command("say 我们降魔除妖之人最重的就是道行，" + RANK_D->query_respect(ob) + "还需多加努力才能早悟大道。\n");
	return;
	}

	if( (int)ob->query("pending/kick_out")) {
	command("say 这位" + RANK_D->query_respect(ob) + "反复无常，老夫不原再收你为徒了！\n");
	command("sigh");
	return;
	}

	if ((int)ob->query_int() < 35) {
	command("say 这位" + RANK_D->query_respect(ob) + "悟性太低，恐怕收了你也难有作为！\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("feisheng", 1) < 140 ) {
	command("say 这位" + RANK_D->query_respect(ob) + "对我飞升大法领会还不够深，现在收你也是勉为其难，不如作罢！\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say 老夫不收外门弟子，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-1000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("没用的东西！");
}
else
{
     return ("你有任务吗？！");
}
 }
string ask_mieyao(object me)
{
    me=this_player();
     if((string)me->query("family/family_name")=="武圣门") {
    tell_room(environment(me),"孔武大帝说道.....\n");
    return "/d/obj/mieyao"->query_yao(me);
}
     return ("老夫不知道你在说些什么。");
}




int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "wusheng");
}
/*string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="武圣门") {
                me->set_temp("betray", 1);
                return ("按我武圣门规，却须受罚，你可愿意(agree)?");
        }
        return ("去问问本门弟子吧，或许他们知道。");
}
void init()
{
::init();
        add_action("do_agree", "agree");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N答道：弟子愿意。\n\n", this_player());
                this_player()->add("betray/count", 1);
                this_player()->add("betray/wusheng", 1);
	        this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
                if( this_player()->query_skill("xiantian") )
		  this_player()->delete_skill("xiantian");
                if( this_player()->query_skill("fumobashi") )
		  this_player()->delete_skill("fumobashi");
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "普通百姓");
                this_player()->save();
                command("say 那你去吧！\n");
                return 1;
                }
        return 0;
}
*/
