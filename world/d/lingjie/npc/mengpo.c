// link

inherit NPC;
int give_soup();
void create()
{
        set_name("孟婆", ({ "mengpo", "meng"}) );
        set("gender", "女性" );
        set("age", 220);
        set("long", 
"据说孟婆追随老伴到灵界之后，因生活无着落，人心甚好，
所以玉帝特准她在这里做点生意，因为孟婆汤（ｓｏｕｐ）好，所以以卖汤为生，
后来长传其一方，可以使人忘却人生的苦痛，于是孟婆的生意便一日好过一日。
投生的人都爱在此买一碗后走上新的人生之路。
\n");
        set("combat_exp", 800000);
        set("attitude", "friendly");
        set_temp("apply/astral_vision",1);
        set("chat_chance", 8);
        set("chat_msg", ({
                "孟婆对你说：＂在这里受了不少苦吧，来碗汤吧！＂\n",
                "孟婆说：＂孩子，上去前喝一碗吧！＂\n",
        }) );
        set("inquiry", ([
                "孟婆汤" : (: give_soup:),
                "soup" : (: give_soup:)

        ]));
        setup();
        add_money("gold", 5);
        carry_object("d/obj/cloth/yuanxiang")->wear();
}

int give_soup()
{
        object obj;
if( !query("given"))
        {
message_vision("$N以熟练的手法舀起一碗汤递给$n。\n",this_object(),this_player());
command("say 别厌弃，快点儿喝，喝完好送你去该去的地方！\n");
obj = new(__DIR__"obj/tang");
obj->move(this_player());
if(!random(10))set("given",1);
        }
else
command("say 唉呦！刚刚卖光，你等着，我就去再熬一锅！\n");
        return 1;
}

void reset()
{
delete("given");
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
