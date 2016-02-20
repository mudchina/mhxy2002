//By tianlin@mhxy for 2002.1.7

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
       set_name("谢晓峰", ({"xiexiao feng", "master xie", "master","xie"}));
       set("long", "谢晓峰五岁学剑,十六岁剑成,十九岁败华少坤,一手清风细雨温柔剑法当世无双
更兼风度潇洒绝伦,得七星塘慕容秋荻芳心,惹来一生情债．．\n");
       set("nickname", HIG"剑神"NOR);
       set("title", HIW"神剑山庄"BLINK+HIR"剑神"NOR);
       set("gender", "男性");
       set("age", 20);
       set("class","shenjian");
       set("attitude", "friendly");
       set("rank_info/respect", "剑神");
       set("cor", 30);
       set("per", 21);
       set("max_kee", 4000);
       set("max_gin", 1000);
       set("max_sen", 4000);
       set("max_force", 5600);
       set("force", 5600);
       set("max_mana", 6000);
       set("mana", 6000);
       set("force_factor", 100);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
       set("daoxing", 2000000);
       set_skill("literate", 140);
       set_skill("unarmed", 185);
       set_skill("dodge", 185);
       set_skill("force", 195);
       set_skill("parry", 185);
       set_skill("sword", 200);
       set_skill("spells", 185);
       set_skill("blade", 185);
       set_skill("lianhuan-zhang", 185);
       set_skill("duo-sword", 210);
       set_skill("qingfeng-jian", 190);
       set_skill("cloudforce", 200);
       set_skill("shadowsteps", 185);
       set_skill("xueying-xianfa", 185);
       set_skill("shenji-blade", 185);
       map_skill("spells", "xueying-xianfa");
       map_skill("unarmed", "lianhuan-zhang");
       map_skill("force", "cloudforce");
       map_skill("sword", "duo-sword");
       map_skill("parry", "qingfeng-jian");
       map_skill("dodge", "shadowsteps");
       map_skill("blade", "shenji-blade");
       set("chat_chance_combat", 50);
       create_family("神剑山庄", 1, "红");
       setup();

        if ("/d/shenjian/obj/jueshijian.c"->in_mud())
            carry_object("/d/obj/weapon/sword/qinghong")->wield();
        else carry_object("/d/shenjian/obj/jueshijian.c")->wield();
//carry_object("/d/ourhome/obj/shoes")->wear();
}
void attempt_apprentice(object ob)
{
   if ( (string)ob->query("family/family_name")=="神剑山庄") {
   if (((int)ob->query("daoxing") < 500000 )) {
   command("say " + RANK_D->query_respect(ob) +
"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
   return;
   }
        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们神剑山庄发扬光大。\n");
       command("recruit " + ob->query("id") );
           ob->set("title", HIW"神剑山庄"HIG"谢晓峰"HIY"坐下亲传弟子"NOR);
             ob->set("class", "shenjian");
ob->set("baishi-xie", 1);
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"还是先去学些基础功夫吧。\n");
        return;
}
/*
int accept_fight(object me)
{
   return 0;
}
*/

