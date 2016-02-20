// LLY@FYSY
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("谢王孙", ({ "master xie", "master", "xie", "xie wangsun"}) );
        set("nickname", YEL "暮色秋夕" NOR);
        set("gender", "男性" );
        set("age", 51);
        set("agi",30);
        set("str", 60);
        set("per", 35);
        set("int",30);
        set("attitude","friendly");
        set("max_force", 5000);
        set("force", 5000);
        set("force_factor", 200);
        set("max_mana", 5000);
        set("mana", 5000);
        set("max_atman", 5000);
        set("long",
"这个人并不特殊。他是个中年人，也许比中年还老些，他的两鬓已斑，眼色中已
露出老年的疲倦。他穿得很朴素，一缕青衫，布鞋白袜。他就这麽样随随便便的走
着，就这麽样随随便便的站下来。许就因为他太平凡，平凡得就像是这残秋的暮色
，所以你才看见了他。看见他，也正如看见秋夕暮色一样，心里只会感觉到很平静
，很舒服，很美，绝不会有一点点惊诧和恐惧，这麽随和，这麽平易的人，看起来
他虽然并不太老，可是他的生命却已到了黄昏，就正如这残秋的黄昏般平和宁静，
这世上已不再有什麽今他动心的事。\n"
        );
        create_family("神剑山庄", 4, "前任庄主");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jianqizongheng" :)
        }) );
        set("chat_msg_combat", ({
 "谢王孙平静的说道：每个人都有他自己的命运。\n是幸运？或是不幸？都怨不上别人，所以这些年来，我也渐渐看开了！\n", "谢王孙低沈如叹息的说：你想挑战晓峰？现在你已经面对着他,晓峰已死了十七天。\n谢王孙指着木架後用黑布蒙着的东西，一件长长的方方的东西。\n"
	     }) );

        set("combat_exp", 2300000);
        set("daoxing", 1300000);
        set_skill("parry",200);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("literate", 120);
        set_skill("unarmed",180);
        set_skill("shadowsteps",240);
        set_skill("qingfeng-jian",300);
        set_skill("cloudforce",200);
        set_skill("sword",200);
        map_skill("dodge", "shadowsteps");
        map_skill("force", "cloudforce");
        map_skill("parry","softsword");
        map_skill("sword", "softsword");    
        setup();
        carry_object(__DIR__"obj/deitysword")->wield();
        carry_object(__DIR__"obj/sjcloth")->wear();
}

void attempt_apprentice(object me)
{
        if(me->query_temp("won_master_xie"))
        {
        command("say 一个人要学剑，就应该诚心正意，绝不能太骄傲，骄傲最易造成疏
忽，任何一点疏忽，都足以致命。\n");
        command("recruit " + me->query("id") );
                return;
        }
        else
        {
        command("sigh");
        command("say 神剑山庄后继无人呀。\n");
        }
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shenjian");
}

void re_rank(object student)
{
                student->set("title","剑神");
                return ;
}

