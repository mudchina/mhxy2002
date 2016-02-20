//By tianlin@mhxy for 2002.2.24

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <obstacle.h>

void create()
{
       set_name(HIY"善财童子"NOR, ({"shancai tongzi","tongzi"}));
       set("title", YEL"观音座下弟子"NOR);
       set("long", "仙界善财童子。\n");
       set("gender", "男性");
       set("age", 16);
       set("per", 25);
       set("str", 25);
       set("int", 25);
       set("con", 25);
       set("spi", 25);

        set("attitude", "heroism");
       set("combat_exp", 6200000);
       set("daoxing", 5500000);
       set("eff_dx", -500000);
       set("nkgain", 500);

       set("class","yaomo");
       set("max_kee", 3200);
       set("max_sen", 3200);
       set("force", 6200);
       set("max_force", 6200);
        set("force_factor", 100);
       set("max_mana", 6200);
       set("mana", 6200);
        set("mana_factor", 80);
       
       set_skill("spear", 285);
       set_skill("force", 285);
       set_skill("dodge", 285);
       set_skill("stick", 285);
       set_skill("sword", 285);
       set_skill("liehuo-sword", 285);
set_skill("literate", 180);
       set_skill("dali-bang", 285);
       set_skill("huoyun-qiang", 285);
       set_skill("parry", 285);
       set_skill("unarmed", 285);
       set_skill("wuyue-spear", 285);
       set_skill("spells", 285);
       set_skill("pingtian-dafa", 285);
       set_skill("moshenbu", 285);
       set_skill("huomoforce", 285);
       set_skill("moyun-shou", 285);
       map_skill("force", "huomoforce");
       map_skill("spells", "pingtian-dafa");
       map_skill("unarmed", "moyun-shou");
       map_skill("sword", "liehuo-sword");
       map_skill("spear", "wuyue-spear");
       map_skill("parry", "wuyue-spear");
       map_skill("stick", "dali-bang");
       map_skill("dodge", "moshenbu");

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: cast_spell, "sanmei" :),
        }));


        create_family("火云洞", 1, "蓝");
       setup();
        carry_object("/d/nanhai/obj/huojianqiang")->wield();
       carry_object("/d/qujing/bibotan/obj/zhanpao")->wear();
}

void attempt_apprentice(object ob)
{
        int size = sizeof(obstacles);
        string *names = keys(obstacles);
        int i;

        if(((string)ob->query("family/family_name")=="火云洞" )&& !wizardp(ob)) {
                command("say " + RANK_D->query_respect(ob) +"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
                return;
        }       
        if (((int)ob->query_skill("pingtian-dafa", 1) < 180 )&& !wizardp(ob))  {
                command("say " + RANK_D->query_respect(ob) + "的平天大法似乎级别还不够。\n");
                return;
        }
        if (((int)ob->query_skill("huomoforce", 1) < 180 )&& !wizardp(ob))  {
                command("say " + RANK_D->query_respect(ob) + "的火魔心法似乎级别还不够。\n");
                return;
        }
        for (i = 0; i < size; i++)
        if (ob->query("obstacle/"+names[i])!="done" && !wizardp(ob))
        {
           command("shake");
           command("say 这位" + RANK_D->query_respect(ob) + "尚未历尽西行难关，恐怕难以领悟高深武学。\n");
           return;
        }
        command("pat " + ob->query("id") );
        command("addoil " + ob->query("id") );
        command("recruit " + ob->query("id") );
        message("channel:rumor",HIM+"【"HIW"谣言"HIM"】某人："BLINK+HIR+ob->query("name")+NOR+HIM"西天取经感化众生得到"HIY"善财童子"HIM"的亲自指点！\n"NOR,users() );
        return; 
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "yaomo");
ob->set("title",RED"枯松涧火云洞"NOR+CYN"惊天震地"YEL"妖王"NOR);
}

