inherit F_VENDOR_SALE;

string heal_me(object me);

void create()
{
	reload("yangzhongshun");
        set_name("ÑîÖÐË³", ({"yang zhongshun", "yang", "boss"}));
        set("title", "[37mÒ©ÆÌÕÆ¹ñ[2;37;0m");
        set("gender", "ÄÐÐÔ");
        set("age", 37);
        set("long",
"ÑîÀÏ°åÊÇ³¤°²³ÇÀï×æ´«µÄÃûÒ½¡£ËäÈ»ÄêÇá£¬È´ÔçÒÑÃûÉùÔÚÍâ¡£\n");
        set("kee", 300); 
        set("max_kee", 300);
        set("sen", 200);
        set("max_sen", 200);
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("env/wimpy", 50);

        set("inquiry", ([
                "ÖÎÉË": (: heal_me :),
                "ÁÆÉË": (: heal_me :),
                "¿ªÒ©": (: heal_me :),
        ]) );

        set("vendor_goods", ([
		"taogan": "/d/obj/drug/fake-tao",
                "yao": "/d/obj/drug/jinchuang",
                "dan": "/d/obj/drug/hunyuandan",
        ]) );

        set_skill("literate", 70);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);

        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        add_money("gold", 1);
}


string heal_me(object ob)
{
        int ratio;
        object me;
        me = this_player();
        ratio = (int)me->query("eff_kee") * 100 /
(int)me->query("max_kee");
        if( ratio >= 100 )
                return "ÕâÎ»" + RANK_D->query_respect(me) +
"£¬Äú¿´ÆðÀ´ÆøÉ«ºÜºÃ°¡£¬²»ÏñÓÐÊÜÉËµÄÑù×Ó¡£";
        if( ratio >= 95 )
                return
"Å¶....ÎÒ¿´¿´....Ö»ÊÇÐ©Æ¤ÈâÐ¡ÉË£¬ÄúÂò°ü½ð´´Ò©»ØÈ¥·ó·ó¾ÍÃ»ÊÂÁË¡£";

}



void init()
{
        object ob;

        ::init();
        add_action("do_vendor_list", "list");


}

void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("xunluo guanbing");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/city/npc/xunluobing");
                ob->move(environment());
        }
        message_vision("\nºöÈ»´ÓÃÅÍâ³å½øÀ´¸öÑ²Âß¹Ù±ø£¬¶Ô$N´óº°Ò»Éù¡°¸ÉÊ²Ã´£¿ÏëÉ±ÈËÄ±²ÆÃ´£¡\n\n",me);        

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

