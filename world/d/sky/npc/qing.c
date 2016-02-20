// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// shangshan.c
#include <ansi.h>
inherit F_VENDOR_SALE;
string ask_me_2();
string send_me(object me);
void create()
{
        set_name(HIG"青儿"NOR, ({ "qing er", "qinger", "qing" }) );
        set("gender", "女性" );
   set("long",
     "她是赵雅的贴身丫环,代理申请赏善罚恶令 \n"
     "她长的貌胜天仙,楚楚动人!\n"
     "武林赏善使者,不过从没有人见过她与人交手,不知道到底武功如何。\n"
   );
   set("age",20);
   set("title",HIW "赏善使者"NOR);
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
     "name" : "小女子小青，奉命在此接待比武人员。",
     "here" : "这里就是南天门, 入内就是比武场了。",
     "回去": (: send_me :),
     "back": (: send_me:),
     "赏善罚恶令" :     (: ask_me_2 :)
   
]) );

   setup();
   carry_object("obj/weapon/sword")->wield();
   carry_object("/d/obj/armor/jinjia")->wear();
}

string send_me(object me)
{
        me=this_player();
           if( me->is_fighting() )
     return ("刚来就惹麻烦，鬼才要理你！\n");
        if( me->is_busy() || me->query_temp("pending/exercising"))
     return ("忙完再说吧。。。\n");

   message_vision("青儿妩媚一笑，对$N说道：本姑娘这就送你回去！\n", me);
   message_vision("小青飞起一脚把$N踢了下去。。。\n", me);
        me->move("/d/changan/nbridge");
   tell_room( environment(me), "「咕咚」一声，从天上掉下个人来！\n", ({me}));
   write("你从天上摔了下来，搞了个鼻青脸肿！\n");
   return ("姑娘脚正痒痒。。。\n");
}
string ask_me_2()
{
        mapping fam, skl;
        object ob;
        string *sname;
        int i;

     skl = this_player()->query_skills();
        sname  = sort_array( keys(skl), (: strcmp :) );

        for(i=0; i<sizeof(skl); i++) {
                if (skl[sname[i]] < 100)
                return RANK_D->query_respect(this_player()) +
                "功力不够，不能领取赏善罚恶令。";
        }

        ob = new("/d/suburb/xkx/shaolin/obj/damo-ling");
        ob->move(this_player());
        message_vision("$N获得一面令牌。\n",this_player());

        return "好吧,凭这面赏善罚恶令,你可自由出入大会会场。";
}
