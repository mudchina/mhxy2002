//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m
//²¿·ÖÓÅ»¯

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("Óáá·ÑÒ", ({ "yu daiyan", "yu" }));
        set("nickname", HIW"Îäµ±"NOR+HIR"ÈıÏÀ"NOR);
        set("long",
                "Ëû¾ÍÊÇÕÅÈı·áµÄ×î²»ĞÒµÄµÜ×Ó¡¢Îäµ±ÆßÏÀÖ®ÈıµÄÓáá·ÑÒ¡£\n"
                "Éí´©Ò»¼ş¸É¸É¾»¾»µÄÇà²¼³¤ÉÀ¡£\n"
                "Ëû²»¹ıÈıÊ®³öÍ·Äê¼Í£¬Ë«ÍÈ²Ğ·Ï£¬ÕÅÕæÈËÃüËûÖ÷³ÖÕæÎä½£Õó¡£\n");
        set("gender", "ÄĞĞÔ");
        set("age", 31);
        set("attitude", "peaceful");
        set("class", "swordsman");
        set("shen_type", 1);
        set("str", 28);
        set("int", 30);
        set("con", 28);
        set("dex", 28);

        set("max_kee", 3000);
        set("max_sen", 3000);
        set("force", 3500);
        set("max_force", 1500);
        set("mana", 3000);
        set("max_mana", 3000);
        set("force_factor", 90);
        set("mana_factor", 70);
        set("combat_exp", 250000);
        set("daoxing", 250000);

        set_skill("force", 100);
        set_skill("wudang-force", 140);
        set_skill("spells", 170);
        set_skill("wudang-xianfa", 100);
        set_skill("dodge", 150);
        set_skill("tiyunzong", 150);
        set_skill("unarmed", 100);
        set_skill("taiji-quan", 100);
        set_skill("parry", 110);
        set_skill("sword", 120);

        map_skill("force", "wudang-force");
        map_skill("spells", "wudang-xianfa");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
	set("chat_chance", 1);

        set("chat_msg", ({
            "Óáá·ÑÒËµµÀ£ºÕæÎä½£ÕóÊÇ¶÷Ê¦µÄĞÄÑª¡£",
            "Óáá·ÑÒÑöÌìÌ¾µÀ£ºÄÄÎ»Î×Ê¦ÄÜÖÎºÃÎÒµÄÍÈ£¬ÎÒÒ²ÇëÑ¼×¯Ò»¶Ù¡£"
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
   int i;
   if (((int)ob->query_skill("wudang-force", 1) == 0))
   {
      message_vision(CYN"Ê®ÈıµÜ×Ó¶Ô$NÆëÉùºÈµÀ£ºÄãÕâ¸öĞ°Ä§ÍâµÀ£¬¸ÒÀ´ÕæÎä½£Õó£¿\n\n"NOR,ob);
      ob->set("kee",30);
      if ((int)ob->query("combat_exp") <2000) ob->set("combat_exp",1);
         else ob->add("combat_exp",-1000);
      message_vision(CYN"ÕæÎä½£Õó¶ÙÊ±Æô¶¯£¬¸ßÌ¨ÉÏ½£Æø×İºá£¬°Ñ$NÎ§ÔÚÖĞÑë¡£\n"NOR,ob);
      message_vision(CYN"Ê®Èı¿Ú³¤½£Æë³ö£¬ÔÚ$NÉíÉÏ»®³öÁËÊ®ÈıµÀ¿Ú×Ó£¬ÏÊÑªÁÜÀì¡£\n"NOR,ob);
      say(CYN"\n\nÓáá·ÑÒÁ³ÏÖÅ­Èİ£º¡°Ğ°Ä§ÍâµÀ£¬Ò²¸Ò´³ÕæÎä½£Õó£¡¡±\n");
      message_vision("Óáá·ÑÒ¾Ó¸ßÁÙÏÂ£¬ÆğÊÖÒ»ÕÆ°Ñ$NÅüÂä¸ßÌ¨¡£\n\n\n"NOR,ob);
      ob->move("/d/wudang1/nanyangong");
      CHANNEL_D->do_channel(this_object(),"chat",sprintf("%s Ë½´³ÕæÎä½£Õó£¬ÄîÆä³É³¤²»Ò×£¬ÔİÃâÒ»ËÀ£¡",ob->name(1)));
   }
}

void attempt_apprentice(object me)
{
       if ( ((int)me->query("combat_exp") < 100000)) {
         command("say " + RANK_D->query_respect(me) +
                        "ÊÇ·ñ»¹Ó¦ÔÚµÀµÂ¼°Îä¹¦·½Ãæ¶àÏÂÅ¬Á¦£¬À´ÈÕ·½³¤Âğ£¡");
                return;
        }
        if ((int)me->query_skill("wudang-force", 1) < 30) {
                command("say ÎÒÎäµ±ÅÉÄËÄÚ¼ÒÎä¹¦£¬×îÖØÊÓÄÚ¹¦ĞÄ·¨¡£");
                command("say " + RANK_D->query_respect(me) +
                        "ÊÇ·ñ»¹Ó¦¸ÃÔÚÌ«¼«Éñ¹¦ÉÏ¶àÏÂµã¹¦·ò£¿");
                return;
        }
        command("say ºÃ°É£¬ÎÒ¾ÍÊÕÏÂÄãÁË¡£");
        command("recruit " + me->query("id"));
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wudang");
                ob->set("title", "[1;33mÎäµ±ÅÉ[1;37mµÚ[1;36mÈı[1;37m´úµÜ×Ó[2;37;0m");
}
