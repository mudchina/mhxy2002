inherit F_VENDOR_SALE;

string heal_me(object me);

void create()
{
	reload("yangzhongshun");
        set_name("ÒõÀÏ°å", ({"yinlao ban", "yin", "boss"}));
        set("title", "[37mÒ©µêÀÏ°å[2;37;0m");
        set("gender", "ÎŞĞÔ");
        set("age", 18);
        set("long",
"ËûÊÇÒ»¸ö´÷×ÅÑÛ¾µµÄÖĞÄêÀÏ°å,³¤µÄ²»¿°ÈëÄ¿,¾ø¶ÔÊÇ¼«Æ·ÖĞµÄ¼«Æ·¡£\n");
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
        add_money("gold", 5);
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
"£¬Äú¿´ÆğÀ´ÆøÉ«ºÜºÃ°¡£¬²»ÏñÓĞÊÜÉËµÄÑù×Ó¡£";
        if( ratio >= 95 )
                return
"Å¶....ÎÒ¿´¿´....Ö»ÊÇĞ©Æ¤ÈâĞ¡ÉË£¬ÄúÂò°ü½ğ´´Ò©»ØÈ¥·ó·ó¾ÍÃ»ÊÂÁË¡£";

}



void init()
{
        object ob;

        ::init();
        add_action("do_vendor_list", "list");


}


