//by tianlin 2001.6.28
 
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string avenge();
string ask_taijitu();

void create()
{
       set_name("菩提祖师", ({"master puti","puti", "master"}));
       set("long", "大觉金仙没垢姿，西方妙相祖菩提\n");
       set("title", HIC"斜月三星"NOR);
       set("gender", "男性");
       set("age", 100);
	set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老师祖");
       set("per", 26);
	set("looking", "玉面多光润，苍髯颌下飘，金睛飞火焰，长目过眉梢。");
	set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 2500);
       set("force_factor", 150);
       set("max_mana", 2500);
       set("mana", 5000);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
	set("daoxing", 10000000);

       set_skill("literate", 170);
       set_skill("unarmed", 180);
      set_skill("dodge", 200);
       set_skill("parry", 180);
        set_skill("stick", 200);
        set_skill("sword", 180);
        set_skill("liangyi-sword", 190);
        set_skill("spells", 210);
        set_skill("dao", 180);
        set_skill("wuxiangforce", 200);
        set_skill("force", 180);
        set_skill("qianjun-bang", 170);
        set_skill("jindouyun", 180);
	map_skill("spells", "dao");
	map_skill("unarmed", "puti-zhi");
	map_skill("force", "wuxiangforce");
	map_skill("stick", "qianjun-bang");
	map_skill("parry", "qianjun-bang");
	map_skill("dodge", "jindouyun");
	map_skill("sword", "liangyi-sword");
   set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
      (: cast_spell, "taijitu" :),
     (: cast_spell, "light" :),
     (: cast_spell, "dingshen" :),
      (: cast_spell, "thunder" :),
      (:perform_action, "stick.qiankun":)
        }) );
    set("inquiry",([
      "太极图": (: ask_taijitu :),
      "复仇": (: avenge :) ]));

create_family("方寸山三星洞", 1, "蓝");
setup();

        carry_object("/d/lingtai/obj/pao")->wear();
        carry_object("/d/lingtai/obj/shoe")->wear();
        carry_object("/d/lingtai/obj/putibang")->wield();
}

string ask_taijitu()
{
    object me=this_player();

    if(me->query("class")!="taoist")
       return ("你不是本门弟子，居然来刺探本门机密！");
   if(me->query("faith")<100)
       return ("你对本门做了多少贡献，就想打听太极图！");
    if(!me->query("bagua_winner"))
       return ("你没能通过八卦阵，不知你能力如何！");
    if(me->query("taijitu_known"))
      return ("你不是已经知道了么，难道是来戏弄老道的！");
    command("pat "+me->query("id"));
    me->set("taijitu_known",1);
    return ("你附耳过来，太极图乃如此如此...");
}
string avenge()
{
    object who=this_player(),killer,where;
    string killid;
        
    if((string)who->query("family/family_name")!="方寸山三星洞")
        return ("你不是本派弟子，生死与老道何干？");
    if(who->query("faith")<1000)
        return ("你在本门名望还不够，还需多加努力才行。");
    if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
        return ("老道未闻死讯");
        
    killid=who->query("kill/last_killer");
    killer=find_living(killid);
    if(!killer||!userp(killer))
        return ("这个嘛，老道还得想一想");
           
    command("say 老道这就去为你抱仇。");
    who->set("avenge/mud_age",who->query("mud_age"));
    where=environment(who);
    tell_room(where,"只见菩提老祖向空中一指：\n");
    tell_room(where,"黄巾力士何在，速去将"+killer->query("name")+"抓来。\n");
    tell_room(environment(killer),"空中伸出一只大手将"+killer->query("name")+"抓走了。\n");
    killer->move(where);
    tell_room(where,killer->query("name")+"被从空中扔了下来。\n");
    command("say 大胆妖孽，胆敢杀害我方寸山弟子");
    this_object()->kill_ob(killer);
    return("拿命来。");        
}
void attempt_apprentice(object ob)
{   ob=this_player();
   if( (string)ob->query("family/family_name")=="方寸山三星洞") {
if ((int)ob->query("daoxing") < 400000 ) {
     command("say 我们修真之士最重的就是道行，" + RANK_D->query_respect(ob) + "还需多加努力才能早悟大道。\n");
   return;
   }
/*
   if( (int)ob->query("pending/kick_out")) {
   command("say 这位" + RANK_D->query_respect(ob) + "反复无常，老夫不原再收你为徒了！\n");
   command("sigh");
   return;
   }
*/
   if ((int)ob->query_int() < 35) {
   command("say 这位" + RANK_D->query_respect(ob) + "悟性太低，恐怕收了你也难有作为！\n");
   command("sigh");
   return;
   }
   if( (int)ob->query_skill("dao", 1) < 100 ) {
   command("say 这位" + RANK_D->query_respect(ob) + "对我道家仙法领会还不够深，现在收你也是勉为其难，不如作罢！\n");
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
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
}

int accept_fight(object me, object ob)
{   ob=this_player();
   command("say " + RANK_D->query_rude(ob) + "杀心太重，恐祸不久已！\n");
   return 0;
}
void die()
{

        if( environment() ) {
        message("sound", "\n\n菩提祖师微皱眉头，道：这厮果是个天成地就的！\n\n", environment());
        command("sigh");
        message("sound", "\n菩提祖师身形一转，化做青烟走了。。。\n\n", environment());
        }

        destruct(this_object());
}

