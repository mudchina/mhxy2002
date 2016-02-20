// created 19/3/2001 by xuexu
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
set_name(HIR"罗睺"NOR, ({"luo hou"}));
set("long","以龙的形态出现的恶魔。据说罗睺能够把太阳和月亮捉住，让它们发不出光。\n");
set("title", HIW"饿鬼界主宰之神"NOR);
set("gender", "男性");
set("age", 50);
set("class", "yaomo");
set("attitude", "friendly");
set("rank_info/respect", "主宰之神");
set("per", 30);
set("int", 30);
set("max_kee", 2900);
//       set("max_gin", 2600);
set("max_sen", 2800);
set("force", 6000);
set("max_force", 3000);
set("force_factor", 150);
set("max_mana", 3000);
set("mana", 6000);
set("mana_factor", 150);
set("combat_exp", 4000000);
set("daoxing", 4000000);
set("eff_dx", 200000);
set("nkgain", 350);
set_skill("literate", 180);
set_skill("unarmed", 180);
set_skill("dodge", 220);
set_skill("force", 220);
set_skill("parry", 220);
set_skill("sword", 220);
set_skill("spells", 220);
set_skill("dengxian-dafa", 230);
set_skill("ningxie-force", 230);
set_skill("bainiao-jian", 230);
set_skill("dragonfight", 220);
set_skill("xiaoyaoyou", 220);
map_skill("spells", "dengxian-dafa");
map_skill("force", "ningxie-force");
map_skill("unarmed", "dragonfight");
map_skill("dodge", "xiaoyaoyou");
map_skill("sword", "bainiao-jian");
map_skill("parry", "bainiao-jian");
   set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword", "chaofeng" :),
                   (: cast_spell, "juanbi" :),   
        }) );
set("inquiry", ([
]));
create_family("饿鬼界主宰", 1, "饿神");
setup();
carry_object("/d/obj/armor/jinjia")->wear();
carry_object("/d/obj/weapon/sword/feijian")->wield();
carry_object("/d/newjob/liudao/obj/sun");
carry_object("/d/newjob/liudao/obj/moon");
}
