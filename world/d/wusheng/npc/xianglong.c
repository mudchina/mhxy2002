// xianglong.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIY"½µÁúÂÞºº"NOR, ({"xianglong luohan", "luohan"}));
       set("long", "Óë·ü»¢ÂÞººÒ»Ñù£¬ÊÇÌìÉÏÉñ±øÖ®Ò»¡£\n");
       set("title", HIC"ÎäµÛÃÅ"NOR);
       set("gender", "ÄÐÐÔ");
       set("age", 50);
       set("class", "wusheng");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "ÂÞºº");
       set("looking", "ÓñÃæ¶à¹âÈó£¬²Ô÷×ò¢ÏÂÆ®£¬½ð¾¦·É»ðÑæ£¬³¤Ä¿¹ýÃ¼ÉÒ¡£");
       set("max_kee", 3000);
       set("max_gin", 500);
       set("max_sen", 3000);
       set("force", 3000);
       set("max_force", 1500);
       set("force_factor", 50);
       set("max_mana", 1500);
       set("mana", 2000);
       set("mana_factor", 50);
       set("combat_exp", 1400000);
       set("daoxing", 2100000);

        set_skill("unarmed", 140);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("spells", 100);  
        set_skill("feisheng", 100);
        set_skill("literate", 100);
        set_skill("sword", 100);  
        set_skill("wuying", 100);
        set_skill("fumobashi", 140);  
        set_skill("mizongbu", 100);
        set_skill("dodge", 100);  
        set_skill("force", 140);   
        set_skill("xiantian", 140);

        map_skill("spells", "feisheng");
        map_skill("unarmed", "fumobashi");
        map_skill("force", "xiantian");
        map_skill("sword", "wuying");
        map_skill("parry", "wuying");
        map_skill("dodge", "mizongbu");

create_family("ÎäÊ¥ÃÅ", 2, "ÂÞºº");
   setup();
   carry_object("/d/obj/weapon/sword/qinghong")->wield();
   carry_object("/d/obj/armor/jinjia")->wear();
}
void attempt_apprentice(object ob, object me)
{
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) +
"¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓÐ³É¡£\n");
        command("recruit " + ob->query("id") );
	return;
}		

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wusheng");
}

ÿ
