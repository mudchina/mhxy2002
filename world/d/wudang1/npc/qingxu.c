//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m
//≤ø∑÷”≈ªØ

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("«Â–Èµ¿≥§", ({ "qingxu daozhang", "qingxu","daozhang" }));
        set("long",
                "À˚æÕ «ÀŒ‘∂«≈µƒµ‹◊”«Â–Èµ¿≥§°£\n"
                "À˚ΩÒƒÍ»˝ Æ∞ÀÀÍ£¨÷˜π‹Œ‰µ±≈…∫Û…ΩµƒÀ◊ ¬°£\n");
        set("gender", "ƒ––‘");
        set("age", 38);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "taoist");
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("max_kee", 1000);
        set("max_sen", 800);
        set("force", 1000);
        set("max_force", 1000);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 40);
        set("mana_factor", 40);
        set("combat_exp", 60000);
        set("daoxing", 60000);

        set_skill("force", 50);
        set_skill("wudang-force", 50);
        set_skill("spells", 50);
        set_skill("wudang-xianfa", 50);
        set_skill("dodge", 50);
        set_skill("tiyunzong", 40);
        set_skill("unarmed", 60);
        set_skill("taiji-quan", 60);
        set_skill("parry", 50);
        set_skill("sword", 60);
        set_skill("wudang-jian", 40);
        set_skill("taoism", 50);
        set_skill("literate", 50);

        map_skill("force", "wudang-force");
        map_skill("spells", "wudang-xianfa");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "wudang-jian");
        map_skill("sword", "wudang-jian");

        create_family("Œ‰µ±≈…", 3, "µ‹◊”");
        set("class", "wudang");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        if ( ((int)ob->query("combat_exp") < 10000)) {
                command("say " + RANK_D->query_respect(ob) +
                        " «∑Òªπ”¶‘⁄µ¿µ¬º∞Œ‰π¶∑Ω√Ê∂‡œ¬≈¨¡¶£¨¿¥»’∑Ω≥§¬£°");
                return;
        }
        command("say ∫√∞…£¨∆∂µ¿æÕ ’œ¬ƒ„¡À°£");
        command("recruit " + ob->query("id"));
}
