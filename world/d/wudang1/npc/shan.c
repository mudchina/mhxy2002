//By tianlin@mhxy and elva@mhxy for 2001.9.25

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("ÕÅ´äÉ½", ({ "zhang cuishan", "zhang" }));
        set("nickname", HIC"Îä"NOR+HIY"µ±Îå"NOR+HIW"ÏÀ"NOR);
        set("long",
                "Ëû¾ÍÊÇÕÅÈı·áµÄ×î´ÏÃ÷µÄµÜ×Ó¡¢Îäµ±ÆßÏÀÖ®ÎåµÄÕÅ´äÉ½¡£\n"
                "Éí´©Ò»¼ş¸É¸É¾»¾»µÄÇà²¼³¤ÉÀ¡£\n"
                "Ëû²»¹ı¶şÊ®³öÍ·Äê¼Í£¬äìÈ÷Ó¢¿¡£¬Ò»¸±°×ÂíÍõ×ÓÅÉÍ·¡£\n");
        set("gender", "ÄĞĞÔ");
        set("age", 25);
        set("attitude", "peaceful");
        set("class", "wudang");
        set("shen_type", 1);
        set("str", 28);
        set("int", 30);
        set("con", 28);
        set("dex", 28);

        set("max_kee", 3000);
        set("max_sen", 2500);
        set("force", 2100);
        set("max_force", 2100);
        set("mana", 2000);
        set("max_mana", 2000);
        set("force_factor", 90);
        set("mana_factor", 90);
        set("combat_exp", 500000);
        set("daoxing", 1200000);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ren" :),
        }) );
        set_skill("force", 140);
        set_skill("wudang-force", 140);
        set_skill("dodge", 140);
        set_skill("tiyunzong", 140);
        set_skill("unarmed", 140);
        set_skill("taiji-quan", 140);
        set_skill("parry", 140);
        set_skill("sword", 140);
        set_skill("spells", 140);
        set_skill("wudang-xianfa", 140);
        set_skill("liangyi-jian", 140);
        set_skill("taiji-jian", 140);
        set_skill("literate", 150);

        map_skill("force", "wudang-force");
        map_skill("spells", "wudang-xianfa");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "liangyi-jian");
	set("chat_chance", 20);
        set("chat_msg", ({
            "ÕÅ´äÉ½¶ñºİºİµØËµµÀ£ºÃ»ÓĞÁ½°ÑË¢×Ó£¬ÎÒ¸ÒÀ´½â½£ÑÒ£¿\n",
            "ÕÅ´äÉ½ÑöÌìÌ¾µÀ£ºÄÄ¸öÎ×Ê¦°ïÎÒÕÒµ½ËØËØ£¬ÎÒÇëÑ¼×¯Ò»¶Ù¡£\n"
        }));

        create_family("Îäµ±ÅÉ", 2, "µÜ×Ó");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang1/obj/bluecloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",2 , ob);
        }
}

void greeting(object ob)
{
        if( (string)ob->query("class")=="yaomo")
        {
            say(CYN"\n\nÕÅ´äÉ½Á³ÏÖÅ­Èİ£º¡°Ğ°Ä§ÍâµÀ£¬³ÔÁË±ª×Óµ¨ÁË£¬¸ÒÇ¿´³Îäµ±£¡¡±\n\n");
            message_vision("ÕÅ´äÉ½¾Ó¸ßÁÙÏÂ£¬ÆğÊÖÒ»ÕÆ£¬$NÖ»µÃÓ²½Ó£¬Éí×Ó»ÎÁËÒ»ÏÂ¡£\n",ob);
            message_vision("¶Ô·½ÓÒÊÖ³¤½£Ëæ¼´µİ³ö£¬$NÎŞ·¨ÕĞ¼Ü£¬ÍËÁËÒ»²½¡£\n\n\n"NOR,ob);
            ob->move("/d/wudang1/slxl2");
        }
}

void attempt_apprentice(object ob)
{
        if (ob->query_int() < 30)
        {
                command("say ÄãµÄ×ÊÖÊ½«À´µ½²»ÁËÌú»®Òø¹³µÄ¾³½ç£¬ÊÕÄãÒ²ÊÇ°×´î¡£\n");
                return;
        }
        command("say ºÃ°É£¬ÎÒ¾ÍÊÕÏÂÄãÁË¡£");
        command("recruit " + ob->query("id"));
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wudang");
                ob->set("title", "[1;33mÎäµ±ÅÉ[1;37mµÚ[1;36mÈı[1;37m´úµÜ×Ó[2;37;0m");
}
