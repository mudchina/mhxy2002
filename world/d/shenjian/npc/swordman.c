// LLY@FYSY
//by tianlin@mhxy for 2001.12.1

inherit NPC;

void create()

{

        string *name = ({"西域雪山","昆仑月宫","冥界地府","武当派","将军府","无名","蜀山派"});
                set_name(name[random(sizeof(name))]+"剑客", ({ "swordman"}) );

        set("gender", "男性");

        set("age", random(20)+20);

        set("long",
                "一个到神剑山庄来的剑客，大概是想击败谢晓峰，从而扬名天下！\n");

	set("combat_exp", 1250000+random(2000000));

        set_skill("sword", 150+random(140));
        set("chat_chance", 5);

        set("chat_msg", ({
        	name()+"叹道：神剑山庄不愧神剑二字呀．．\n",
		name()+"道：我看神剑山庄也不过空有虚名！\n",     }) );

        set("attitude", "friendly");
        setup();
           carry_object("/obj/cloth")->wear();

        carry_object("/d/shenjian/npc/obj/sword")->wield();
}
