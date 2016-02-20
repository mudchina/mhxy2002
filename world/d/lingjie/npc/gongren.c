
inherit NPC;

void create()
{
        set_name("园林工人", ({ "gongren", "ren"}) );
        set("gender", "男性" );
        set("age", 35);
        set("long", "这是一位普普通通的园林工人。\n");
        set("combat_exp", 5000+random(5000));
	set("class","lingjie");
        set_skill("unarmed", 50+random(30));
        set_skill("dodge", 50+random(30));
        set("chat_chance", 20);
        set("chat_msg", ({
                "园林工人摇头晃脑地说：“环滁皆山也，其西南诸峰．．．\n",
                (: random_move :),

        }) );
	
	setup();
	add_money("silver", 50+random(20));
        carry_object("/d/obj/cloth/linen")->wear();
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