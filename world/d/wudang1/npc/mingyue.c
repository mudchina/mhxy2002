//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m

inherit NPC;

void create()
{
	set_name("Ã÷ÔÂ", ({ "ming yue", "ming", "yue" }));
	set("long", 
		"ËûÊÇÎäµ±É½µÄĞ¡µÀÍ¯¡£\n");
	set("gender", "ÄĞĞÔ");
	set("age", 16);
	set("attitude", "peaceful");
	set("shen_type", 1);
        set("class", "taoist");

	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
	set("max_kee", 150);
	set("max_sen", 100);
	set("force", 150);
	set("max_force", 150);
	set("mana", 380);
	set("max_mana", 390);

	set("combat_exp", 5000);
	set("daoxing", 10000);

	set_skill("force", 30);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);

	create_family("Îäµ±ÅÉ", 5, "µÜ×Ó");

	setup();
	
	carry_object("/d/wudang1/obj/greyrobe")->wear();
}
