// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// tianwang.c
#include <ansi.h>
inherit NPC;
string send_me(object me);
void create()
{
        set_name(HIB"莫言"NOR, ({ "mo yan", "moyan", "mo" }) );
        set("gender", "女性" );
   set("long",
     "她是月影的妹妹,和青儿一样是会场的守护者。 \n"
     "这样一位美丽的女子,怎么会是让恶人丧胆的罚恶使者呢？？ 不知道武功究竟怎样\n"
   );
   set("age",14);
   set("title",HIR "罚恶使者"NOR);
   set("attitude", "peaceful");
   set("str",40);
   set("int",30);
   set("max_kee",11000);
   set("kee",11000);
   set("max_sen",11000);
   set("sen",11000);
   set("combat_exp",10000000);
   set("force",25000);
   set("max_force",15000);
   set("mana",25000);
   set("max_mana",16000);
   set("force_factor", 180);
   set("mana_factor",180);
   set("eff_dx", 4500000);
   set("nkgain", 5000);
   set_skill("unarmed",250);
   set_skill("yingzhaogong", 250);
   set_skill("parry",250);
   set_skill("dodge",250);
   set_skill("sword",250);
   set_skill("snowsword",250);
   set_skill("force",150);
   set_skill("spells", 150);
   set_skill("moshenbu", 250);
   map_skill("dodge", "moshenbu");
   map_skill("parry", "snowsword");
   map_skill("sword","snowsword");
   map_skill("unarmed", "yingzhaogong");
   set("inquiry", ([
     "name" : "莫言奉命在此接待比武人员。",
     "here" : "这里就是南天门, 入内就是比武场了。",
     "回去": (: send_me :),
     "back": (: send_me:),
   ]) );

   setup();
   carry_object("/d/obj/weapon/sword/snow_sword")->wield();
   carry_object("/d/obj/cloth/luoyi")->wear();
}

string send_me(object me)
{
        me=this_player();
           if( me->is_fighting() )
     return ("刚来就惹麻烦，鬼才要理你！\n");
        if( me->is_busy() || me->query_temp("pending/exercising"))
     return ("忙完再说吧。。。\n");

   message_vision("莫言看了$N一眼，对$N说道：那你就回去吧！\n", me);
   message_vision("莫言一脚把$N踢了下去。。。\n", me);
        me->move("/d/changan/nbridge");
   tell_room( environment(me), "「咕咚」一声，从天上掉下个人来！\n", ({me}));
   write("你从天上摔了下来，搞了个鼻青脸肿！\n");
   return ("本姑娘脚正痒痒。。。\n");
}

 void init()
{
        add_action("do_enter", "enter");
}
int do_enter()
{
        object me;
        me = this_player();
            if( ! me->query("marks/赏善罚恶令"))
             {
                command("say 没有赏善罚恶令，任何人不能进入会场。");
                write("你必须拥有赏善罚恶令才能进入 。\n");
                return 1;
             }
            else
                return 0;
}
int accept_object(object who, object ob)
{
        if ( (string)ob->name() != "赏善罚恶令")
        command("say 没有赏善罚恶令，任何人不能进入会场。");
        if ( (string)ob->name() == "赏善罚恶令")
        who->set("marks/赏善罚恶令",1);
        write(HIW"恭喜你! 可以参加水陆大会了, 请进!"HIR);
        if ( ob->query("id") != "ling")
        {
                command("say 这是什么东西啊！你想偷进去干什么？");
                return 0;
        }
        ob->destruct();
        return 1;
}

