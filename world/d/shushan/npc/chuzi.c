//shushan2 by yushu@SHXY 2000.12
inherit NPC;
void create()
{
        set_name("´ó³ø×Ó", ({"da chuzi", "chuzi"}));
        set("gender","ÄÐÐÔ");
	 set("class", "xiake");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
        set("combat_exp",100000);
        set("attitude","heroism");
        set("chat_chance", 10);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("unarmed", 80);
        set_skill("sword", 120);
        set_skill("literate", 120);
 	 set("max_force", 200);
	 set("force", 200);
	 set("force_factor", 10);
        set("max_kee", 700);
        set("max_gin", 400);
        set("max_sen", 500);
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("silver", 40);
}

void init()
{
::init();
        add_action("do_yao", "yao");
}

int do_yao(string arg)
{
        object m,mm;
        message_vision("$NÏò´ó³ø×ÓÎÊµÀ£ºÊ¦¸µ£¬¿ª·¹ÁËÂð£¿\n", this_player());

        if((int)this_player()->query("food") >=
             (int)this_player()->max_food_capacity()*90/100 )
        return notify_fail("³ø×ÓÐ¦µÀ£º»¹Ã»×öºÃ£¡\n");

        if((present("gongbao jiding", this_player())))
        return notify_fail("´ó³ø×ÓÐ¦µÀ£º²»ÒªÄÃ×ÅÊÖÀïµÄ£¬»¹¿´×Å¹øÀïµÄ!\n");
	
	 if ( present("gongbao jiding", environment()) )
         return notify_fail("´ó³ø×ÓÐ¦µÀ£ºÄÇ²»ÊÇÓÐÒ»ÅÌÂï£¬³ÔÍêÔÙËµ£¡\n");

        m=new("d/obj/food/dishes/dish10");
        mm=new("d/obj/food/dishes/dish10");


        m->move(this_player());
        mm->move(this_player());
             
        command("hoho");
        message_vision("´ó³ø×Ó¶Ô$NÐ¦µÀ£º¶öÁË°É£¬Âýµã³Ô£¡£¡\n", this_player());
        return 1;
}

 

ÿ