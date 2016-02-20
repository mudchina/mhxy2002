inherit NPC;

void create()
{
        set_name("伙计", ({"huoji"}));
        set("age", 28);
        set("gender", "男性");
        set("long",
"早年得到成仙,因犯了天条,被贬入灵界。\n");
        set("attitude", "peaceful");

        set("combat_exp", 5000);
        set("shen_type", 1);
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        setup();
        carry_object("/d/obj/cloth/linen")->wear();
}


