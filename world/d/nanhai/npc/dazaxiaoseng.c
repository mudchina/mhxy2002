// 打杂小僧xiaoseng.c

#include <ansi.h>

inherit NPC;

string ask_for_zhulan();

void create()
{
        set_name("打杂小僧", ({ "daza xiaoseng", "xiaoseng" }) );

        set("gender", "男性");
        set("age", 20);
        set("attitude", "peaceful");
        set("class", "bonze");

        set("str", 17);
        set("int", 30);
        set("spi", 30);
        set("con", 30);
        set("cps", 30);
        set("cor", 20);

        set("atman", 200);
        set("max_atman", 200);

        set("force", 150);
        set("max_force", 150);
        set("force_factor", 5);

        set("mana", 200);
        set("max_mana", 200);

        set("combat_exp", 10000);
//      set("score", 9000);

        set("inquiry", ([
                "竹篮" : (: ask_for_zhulan :),
                ]) );

        set_skill("blade", 20);
        set_skill("unarmed", 30);
        set_skill("force", 25);
        set_skill("dodge", 20);
        set_skill("literate", 20);
        set_skill("parry", 20);
        set_skill("spells", 10);

        set_skill("lotusforce", 20);
        set_skill("buddhism", 20);

        map_skill("force", "lotusforce");
        map_skill("spells", "buddhism");

        create_family("南海普陀山", 4, "弟子");

        setup();

        carry_object("/d/nanhai/obj/sengpao")->wear();
        carry_object("/d/nanhai/obj/kandao")->wield();  
}

string ask_for_zhulan()
{
   object me=this_player();
   object kandao=present("dao",this_object());

   if((string)me->query("family/family_name")!="南海普陀山")
      return ("您不是本门中人。");
   if(me->query("faith")>300||me->query("combat_exp")>50000)
      return ("您是本门大有名望之人，怎敢有劳您做这种杂务呢？");
   if(!kandao)return ("已经有人去砍紫竹做竹篮了。");

   me->set("nanhai/zhulan",1);
   kandao->move(me);
message_vision("$N递给你一把砍刀。\n",this_object());
   return ("这样，就有劳您去砍些竹子。");
}
