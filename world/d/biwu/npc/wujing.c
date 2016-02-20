//By tianlin@Mhxy for 2001.12.15

inherit NPC;

string ask_me();

void create()
{
	set_name("沙吾净", ({ "sha wujing", "sha", "wujing" }));
	set("gender", "男性");
	set("age", 67);

        set("inquiry", ([
                "比武大会" : (: ask_me :),
                "大会" : (: ask_me :),
                "比武"   : (: ask_me :),
                "fight"     : (: ask_me :),
        ]));

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        add_action("do_sign", "sign");
        add_action("do_join", "join");
}

void unconcious()
{
        die();
}

void die()
{
        message_vision("$N打了个喷嚏，随即恢复正常。\n", this_object());
}

string ask_me()
{
        object me;

        me = this_player();
        if (PK_D->is_pking())
                return "现在屠人大赛正在举行呢，你想干什么？";

        if (PK_D->is_ready())
                return "很好，现在屠人大赛正要开始，你要报名么(sign)？";

        return "屠人大赛？你慢慢等着吧。要是无聊，现在要是想进去玩玩(join)也行。";
}

int do_join()
{
        if (PK_D->is_pking())
                return notify_fail("乌老大眼睛一弹，喝道：“现在里面正比赛呢，你这些人等等吧。”\n");

        if (PK_D->is_ready())
                return notify_fail("乌老大懒懒道：“要想正式比赛就进去，其他人先等着。”\n");

        message_vision("$N赔笑对$n道：“我进去溜达溜达，放行可好？”\n",
                       this_player(), this_object());

        if (PK_D->join_competition(this_player()))
        {
                message("vision", this_player()->name() + "一溜小跑进了屠人场。\n",
                        environment());
                return 1;
        }

        return 0;
}

int do_sign()
{
        object me;
        string msg;
        object ob;

        me = this_player();
        message_vision("$N陪着笑脸对$n道：“您好，您好，我也来签个到。”\n",
                       me, this_object());
        if (me->query("combat_exp") < 1000)
        {
                message_vision("$n抬头看了看$N，不屑道：“就你"
                               "这点本事？只好参加被屠大赛！”\n",
                               me, this_object());
                return 1;
        }

        if (stringp(msg = PK_D->reject_join(me)))
        {
                command("say " + msg);
                return 1;
        }

        foreach (ob in deep_inventory(me))
                if (ob->is_character())
                {
                        command("say 你背的谁？去比赛还拖家带口的？快给我滚！");
                        message_vision("$N飞起一脚，把$n踢倒在地！\n",
                                       this_object(), me);
                        me->receive_damage("kee", 50);
                        return 1;
                }

        message_vision("$n点点头，对$N道：“好吧，你先进"
                       "去准备吧。”\n$N点点头，向北面的"
                       "准备室走去。\n", me, this_object());
        me->move("/d/pk/ready");
        message("vision", me->name() + "精神抖擞的走了进来。\n",
                environment(me), ({ me }));
        return 1;
}

