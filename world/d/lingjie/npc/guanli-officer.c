// link

#include <ansi.h>

inherit NPC;

void reset_balance(object me);


void create()
{
        set_name("管理处人员", ({ "officer" }) );
        set("title", RED "一本万利" NOR);
        set("gender", "男性" );
        set("age", 22);
        set("richness",50000000000);
        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 30);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);
        set("no_arrest",1);
        set("long","这是个正在向大家学习如何用极差态度对待顾客而不被顾客投诉的方法的管理处人员。\n");
        set("combat_exp", 2000000);
        set("daoxing", 1000000);
        set("attitude", "friendly");
        set("max_atman", 1000);
        set("atman", 1000);
        set("atman_factor", 33);
        set("max_force", 1600);
        set("force", 1000);
        set("force_factor", 180);
        set("max_mana", 1800);
        set("mana", 1000);
        set("mana_factor", 200);
        set("chat_chance", 3 );
        set("chat_msg", ({
                (: exert_function, "heal" :),
        }) );
        set_skill("unarmed", 150);
        set_skill("dodge", 120);
        set_skill("force", 120);
        set_skill("guangming-force", 120);
        set_skill("guangming-shouyin", 120);
        set_skill("fengtian-steps", 120);
        map_skill("force", "guangming-force");
        map_skill("unarmed", "guangming-shouyin");
        map_skill("dodge", "fengtian-steps");
        set("inquiry", ([
                "抢劫" : "唉！这群灵界流氓真厉害！来无影，去无踪！\n",
                "rob" : "唉！这群灵界流氓真厉害！来无影，去无踪！\n",
        ]) );
        setup();
        carry_object("d/obj/cloth/linen")->wear();
        add_money("gold", 15);
}

void reset_balance(object me)
{
    int myexp;
    int allowed, removed_gold;
    string myid;
    string NPCNAME=this_object()->name();

    if(!me) return;

    myexp=me->query("combat_exp")/1000;
    myid=me->query("id");

    if(myexp<1) myexp=1;
    if(myexp>100) myexp=100;
    allowed=myexp*1000000;//each year can have 100 gold, range 100-10000. 
    if (me->query("balance") > allowed)
    {
        me->set("balance_old", me->query("balance"));
        me->set("balance", allowed);
        removed_gold = (me->query("balance_old") - me->query("balance"))/10000;
        log_file("MONEY_RESET", ctime( time() )+"：幽助收缴了"+me->query("name")+"("+me->query("id")+")"+removed_gold+"两黄金。\n");
        tell_object(me, GRN+NPCNAME+"在你的耳边悄声说道："+RANK_D->query_respect(me)+
                "，这、这真不知怎么说是好．．．\n"NOR);
        tell_object(me, GRN+NPCNAME+"在你的耳边悄声说道："+
                "昨日爱后余生派人前来察案，发觉你老的黄金来路．．．\n"NOR);
        tell_object(me, GRN+NPCNAME+"在你的耳边悄声说道："+
                "若不是在下帮你老辩解，你老的钱就全都充公给逍遥了．．．\n"NOR);
    }
    return;
}

void init()
{
	::init();
        add_action("do_loan","loan");
}

void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("fool");

        ob=present("hufa");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/lingjie/npc/hufa");
                ob->move(environment());
        }
        message_vision("\n忽然从门外冲进来个灵界护法，对$N大喊一声“干什么？你这个灵界流氓！\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
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
