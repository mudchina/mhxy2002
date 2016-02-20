// LLY@FYSY 
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("谢王孙", ({ "master xie", "master", "xie wangsun"}) );
        set("nickname", YEL "暮色秋夕" NOR);
        set("gender", "男性" );
        set("age", 51);
        set("agi",30);
        set("str", 60);
        set("per", 35);
        set("int",30);
        set("attitude","friendly");
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 3000);
        set("mana", 3000);
        set("force_factor", 120);
        set("max_atman", 3000);
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
        (: perform_action,"sword", "jianqizongheng" :),
        }) );
        set("chat_chance", 10);
        set("chat_msg", ({
                "谢王孙握起了你的手，微笑道：你用不着介绍自己，我知道你。\n",
                "谢王孙道：到了这里，你就是我的客人,快进庄里去吧。\n",
                "谢王孙微笑着道：能够在这麽好的天气里，和一个像你这样的人散散步，聊聊
天，实在是件很偷快的事。\n",
		 }) );
        set("combat_exp", 13000000);
        set("daoxing", 13000000);
        set_skill("parry",320);
        set_skill("dodge", 220);
        set_skill("force", 240);
        set_skill("literate", 260);
        set_skill("unarmed",180);
        set_skill("shadowsteps",220);
        set_skill("qingfeng-jian",320);
        set_skill("cloudforce",200);
        set_skill("sword",320);
        map_skill("dodge", "shadowsteps");
        map_skill("force", "cloudforce");
        map_skill("parry","qingfeng-jian");
        map_skill("sword", "qingfeng-jian");    
        setup();
        carry_object(__DIR__"obj/sword")->wield();
        carry_object(__DIR__"obj/sjcloth")->wear();
}

void attempt_apprentice(object me)
{
	switch(random(3)) {
		case 0:
message_vision("$N对$n问道：什么是心剑？\n", this_object(),me);
			break;
		case 1:
message_vision("$N对$n问道：你的剑在什么地方？\n", this_object(),me);		
			break;
		case 2:
message_vision("$N对$n问道：剑术的最高境界是什么？\n", this_object(),me);
			break;
	}
                        return;

}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shenjian");
}


