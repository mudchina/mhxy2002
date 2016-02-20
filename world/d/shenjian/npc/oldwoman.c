// LLY@FYSY
inherit NPC;
int impart();
void create()
{
        set_name("老妇人", ({ "oldwoman" }) );
        set("gender", "女性" );
        set("age", 49);
	set("str",40);
        set("long",
                "一个衰老而憔悴的妇人，默默的坐在孤灯畔,彷佛在等待,仿佛已历尽了人世间一切悲欢和苦难。\n");
	set("combat_exp", 5000000);
        set("chat_chance", 15);
        set("chat_msg", ({
                "老妇人忽然问：“阿吉还没有回来？”\n",
                "老妇人说道：我知道他迟早一定会回来的，你说是不是?\n",
	        }) );
        set("inquiry", ([
                "阿吉" : (: impart :),
                "aji" : (: impart :)

        ]));


        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/ncloth")->wear();

}

int impart()
{
	object me;
	me = this_player();
	message_vision("$N对$n说道：晓峰的小名就叫阿吉！\n",this_object(),me);
	        if(!me->query("m_success/阿吉"))
        {
                me->set("m_success/阿吉",1);
                me->add("score",50);

        }

	return 1;
}

int accept_object(object me, object obj, string arg)
{   string name;
	if(obj->query("for_sjwoman"))
	{
	me->set_temp("for_shenjian",1);
        message_vision("$N衰老疲倦的眼睛里已有了泪光.\n",this_object(),me);
        command("say 你既然将信送来了，从今天开始你就姓谢，就是我神剑山庄的人了！\n");
        name = (string) this_player()->query("name");
	name = "谢"+name[2..];
	this_player()->set("name",name);
	this_player()->save();
        return 1;
	}
	return 0;
}