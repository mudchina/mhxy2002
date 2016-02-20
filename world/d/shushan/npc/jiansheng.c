//jiansheng.c by yushu 2000.11
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int rank_me();
string kick_back();
void create()
{
       set_name("蜀山派剑圣", ({"shushan jiansheng","jiansheng", "master"}));
       set("title", "蜀山派祖师");
       set("gender", "男性");
       set("age", 120);
        set("class", "xiake");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老师祖");
       set("per", 26);
       set("looking", "玉面多光润，苍髯颌下飘，金睛飞火焰，长目过眉梢。");
       set("int", 30);
       set("max_kee", 4500);
       set("max_gin", 800);
       set("max_sen", 4500);
       set("force", 4000);
       set("max_force", 2000);
       set("force_factor", 125);
       set("max_mana", 2000);
       set("mana", 4000);
       set("mana_factor", 100);
       set("combat_exp", 2000000);
       set_skill("literate", 200);
       set_skill("dodge", 190);
       set_skill("parry", 200);
       set_skill("whip", 210);
       set_skill("fumozhang", 190);
       set_skill("unarmed", 200);
       set_skill("sword", 200);
       set_skill("songhe-sword", 200);
       set_skill("spells", 190);
       set_skill("xianfeng-spells", 210);
       set_skill("yujianshu",180);
       set_skill("shushan-force", 200);

       set_skill("force", 200);
       set_skill("zuixian-steps", 190);
         map_skill("spells", "xiaofeng-spells");
       map_skill("force", "shushan-force");
       map_skill("unarmed", "fumozhang");
       map_skill("sword", "yujianshu");
       map_skill("spells","xianfeng-spells");
       map_skill("parry", "yujianshu");
       map_skill("dodge", "zuixian-steps");
       map_skill("whip", "yirubian");
        set("inquiry", ([
        "回去"    : (: kick_back :),
        "back"  : (: kick_back :),
         "职位": (: rank_me :),
       ]) );
       set("chat_chance_combat", 60);
       set("chat_msg_combat", ({
                  (: cast_spell, "fu" :),
                (: perform_action, "sword", "fumo" :),
        }) );
        create_family("蜀山派", 1, "弟子");
        setup();

//  carry_object("/d/obj/cloth/mangpao")->wear();
// carry_object("/d/shushan/obj/jueshi")->wield();
}
string kick_back()
{
    object me=this_player();
    message_vision(HIC"$n说道：不许跟别人说你来过这里。。。。\n"NOR, me, this_object());
    me->move("/d/shushan/woshi");
    message_vision(HIC"$N发现自己已经来到了卧室里。。。。。\n"NOR, me);
    return "";
}
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "蜀山剑派掌门大师兄")
		return notify_fail("你已经是掌门人了，还来要什么职位．\n");
        if( (string)me->query("family/family_name") == "蜀山派"){
                if( exp <= 100000 ){
                        me->set("title", HIC"蜀山剑派"HIR"迎客剑童"NOR);
                } else if(exp <= 1000000 ){
                        me->set("title", HIC"蜀山剑派"HIR"斩妖剑客"NOR);
                } else if(exp < 2000000 ){
                        me->set("title", HIC"蜀山剑派"HIR"伏魔剑侠"NOR);
                } else if(exp <= 3000000 ){
                        me->set("title", HIC"蜀山剑派"HIR"伤心剑神"NOR);
                } else {
                        me->set("title", HIC"蜀山剑派"HIR"通天剑圣"NOR);
                }

                tell_object(me, "蜀山派剑圣对你说：你可以做"+me->query("title")+"。\n");
                tell_room(environment(me),
"蜀山派剑圣对"+me->query("name")+"说：你可以做"+me->query("title")+"。\n", ({me, me}));
         CHANNEL_D->do_channel(me,"chat","现授予本门弟子"+me->query("name")+""+me->query("title")+"一职。恭请各位仙长多加捧场！");
     me->save();  
        }
        return 1;
}
void attempt_apprentice(object ob)
{       ob=this_player();
        if( (string)ob->query("family/family_name")=="蜀山派") {
        if ((int)ob->query("daoxing") < 200000 ) {
        command("say 你的道行还不够，对我的招法难以领悟。\n");
        return;
        }
       if( (int)ob->query_skill("xianfeng-spells", 1) < 160 ) {
        command("say 这位" + RANK_D->query_respect(ob) + "你的仙风云体术还不到火候,你还是找酒剑仙练着吧!\n");
        command("sigh");
        return;
        }
        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
        command("recruit " + ob->query("id") );
        return;
        }
        command("shake");
        command("say 你是本派的吗?，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "蜀山剑圣亲传第子");

}

        return 0;
}

