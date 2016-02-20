// feizei.c
//星星(lywin)2000/5/30为一个任务系统写此npc

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("飞贼",({ "fei zei","fei" }) );
	set("title",HIY"飞天遁地"NOR);
        set("gender", "男性" );
        set("age", 33);
        set("long", 
"这是无恶不做的飞贼，背上有一个小小包裹，看样子是才偷了什么东西在手。\n");

	set("int", 30);
	set("str", 25);
	set("con", 25);
	set("dex", 25);
        set("attitude", "aggressive");
/*        set("shen_type", -1);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 800);
	set("neili", 800);
	set("max_neili", 1000);
	set("jiali", 20);
	set("combat_exp", 500000);
	set("score", 15000);
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 40);
*/
	set_skill("unarmed",90);
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("parry", 90);
	set_skill("sword", 100);
	set_skill("staff", 100);
	set_skill("literate", 80);
/*	set_skill("huashan-zhangfa", 60);
	set_skill("huashan-shenfa",80);
	set_skill("huashan-jianfa", 90);
	set_skill("zixia-shengong", 80);
	set_skill("shenlong-xinfa", 90);
	set_skill("shedao-qigong", 90);

	map_skill("force", "zixia-shengong");
	map_skill("unarmed", "huashan-zhangfa");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
*/	
        set("chat_chance", 60);
        set("chat_msg", ({
                (: random_move :),
        }) );

        setup();
        carry_object( __DIR__ "changjian")->wield();
        carry_object( __DIR__ "lingzhi");
	add_money("gold",1);

}
