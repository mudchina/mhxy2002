//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m
//≤ø∑÷”≈ªØ

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("ƒ™…˘π»", ({ "mo shenggu", "mo" }));
        set("nickname", HIW"Œ‰µ±"NOR+HIR"∆ﬂœ¿"NOR);
        set("long",
                "À˚æÕ «’≈»˝∑·µƒ◊Ó–°µ‹◊”°¢Œ‰µ±∆ﬂœ¿÷Æƒ©µƒƒ™…˘π»°£\n"
                "…Ì¥©“ªº˛∏…∏…æªæªµƒª“…´µ¿≈€°£\n"
                "À˚≤ªπ˝∂˛ Æ≥ˆÕ∑ƒÍºÕ£¨œ‘µ√÷…∆¯Œ¥Õ—£¨…Ì≤ƒ ›≥§£¨√º”Ó∑…—Ô°£°£\n");
        set("gender", "ƒ––‘");
        set("age", 21);
        set("attitude", "peaceful");
        set("class", "wudang");
        set("shen_type", 1);
        set("str", 26);
        set("int", 26);
        set("con", 26);
        set("dex", 26);

        set("max_kee", 1800);
        set("max_sen", 800);
        set("force", 1800);
        set("max_force", 1800);
        set("mana", 1800);
        set("max_mana", 1800);
        set("force_factor", 50);
        set("mana_factor", 50);
        set("combat_exp", 200000);
        set("daoxing", 560000);

        set_skill("force", 80);
        set_skill("wudang-force", 90);
        set_skill("spells", 80);
        set_skill("wudang-xianfa", 90);
        set_skill("dodge", 90);
        set_skill("tiyunzong", 90);
        set_skill("unarmed", 80);
        set_skill("taiji-quan", 85);
        set_skill("parry", 90);
        set_skill("sword", 90);
        set_skill("liangyi-jian", 90);

        map_skill("force", "wudang-force");
        map_skill("spells", "wudang-xianfa");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "liangyi-jian");
	set("chat_chance", 20);
        set("chat_msg", ({
            "ƒ™…˘π»«·…˘Àµµ¿£∫‘⁄ Ø÷˘√Ê±⁄ø…“‘¥Û”– ’ªÒµƒ°£\n",
            "ƒ™…˘π»–±¡Àƒ„“ª—€£∫≤ªπ˝–∞ƒßÕ‚µ¿æÕ≤ªƒ‹√Ê±⁄µƒ¡À°£\n",
            "ƒ™…˘π»ÕµÕµ∏ÊÀﬂƒ„£∫√Ê±⁄ «“ª∂®“™◊¢√˜ººƒ‹µƒ°£\n",
            "ƒ™…˘π»◊‘∫¿µÿÀµµ¿£∫÷ª”–Œ“Œ‰µ±≤≈ «ÃÏœ¬µƒ’˝◊⁄°£\n",
            "ƒ™…˘π»∂‘’≈»˝∑·µƒ«’—ˆ“Á”⁄—‘±Ì£∫»Áπ˚œÎ≥…Œ™æ¯∂•∏ﬂ ÷£¨“ª∂®“™—ßµ¿µ¬æ≠°£\n"
        }));

        create_family("Œ‰µ±≈…", 2, "µ‹◊”");

        setup();
        set("inquiry", ([
           " Ø÷˘":     "‘⁄ Ø÷˘√Ê±⁄ø…“‘¥Û”– ’ªÒµƒ°£",
           "√Ê±⁄":     "√Ê±⁄ «“ª∂®“™◊¢√˜ººƒ‹µƒ°£",
           "’≈»˝∑·":   "Œ“∂˜ ¶—ßæøÃÏ»À£¨”»∆‰ «À˚µƒµ¿—ß–ƒ∑®°£"]) );
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang1/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
        if ( ((int)ob->query("combat_exp") < 100000)) {
                command("say " + RANK_D->query_respect(ob) +
                        " «∑Òªπ”¶‘⁄µ¿µ¬º∞Œ‰π¶∑Ω√Ê∂‡œ¬≈¨¡¶£¨¿¥»’∑Ω≥§¬£°");
                return;
        }
        if ((int)ob->query_skill("wudang-force", 1) < 130) {
                command("say Œ“Œ‰µ±≈…ƒÀƒ⁄º“Œ‰π¶£¨◊Ó÷ÿ ”ƒ⁄π¶–ƒ∑®°£");
                command("say " + RANK_D->query_respect(ob) +
                        " «∑Òªπ”¶∏√‘⁄Ã´º´…Òπ¶…œ∂‡œ¬µ„π¶∑Ú£ø");
                return;
        }
        command("say ∫√∞…£¨Œ“æÕ ’œ¬ƒ„¡À°£");
        command("recruit " + ob->query("id"));
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wudang");
}
