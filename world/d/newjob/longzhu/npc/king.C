// 兰陵国王.c

inherit NPC;

void create()
{
       set_name("国王", ({"guo wang", "wang", "king"}));
       set("title", "兰陵国郡");
       set("long","兰陵城的国王,据说是个爱财的家伙。\n");
       set("gender", "男性");
       set("age", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
        set("per", 30);
        set("combat_exp", 1000000);
        set_skill("unarmed", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        setup();
       add_money("gold", 3);
      carry_object("/d/calvin/armor/armor")->wear();
        carry_object("/d/longzhu/obj/jingshi2");
}
