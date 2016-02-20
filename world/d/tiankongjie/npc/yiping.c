// yiping
//By tianlin@mhxy for 2002.1.24.加入mieyao系统

inherit NPC;
#include <ansi.h>
inherit F_MASTER;
string ask_chuxian();
string ask_cancel();
void create()
{
        set_name("日高一平", ({"rigao yiping", "yiping"}));
        set("gender", "男性" );
        set("age", 18);
        set("title", "八部众-修罗王");
        set("long", "八部众-阿修罗——修罗王。掌管狮子 神甲胄的人。\n");
        set("combat_exp", 700000);

        set("attitude", "peaceful");
        set("int", 25);
        set("class", "xian");
        create_family("天空界", 2,"战士");
        
        set("eff_dx", 30000);

       set("nkgain", 200);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("spells", 100);  
        set_skill("baimofa", 100);
        set_skill("literate", 100);
        set_skill("sword", 100);  
        set_skill("xiaoyao-sword", 100);
        set_skill("piaoyun-zhang", 100);  
        set_skill("shanbishu", 100);
        set_skill("dodge", 100);  
        set_skill("force", 100);   
        set_skill("mtl-force", 120);

        map_skill("spells", "baimofa");
        map_skill("unarmed", "piaoyun-zhang");
        map_skill("force", "mtl-force");
        map_skill("sword", "xiaoyao-sword");
        map_skill("parry", "xiaoyao-sword");
        map_skill("dodge", "shanbishu");


        set("per", 30);
        set("max_kee", 3000);
        set("max_gin", 3000);
        set("max_sen", 3000);
        set("force", 6000);
        set("max_force", 3000);
        set("force_factor", 100);
        set("mana", 6000);
        set("max_mana", 3000);
        set("mana_factor", 100);

    set("inquiry", ([
     "除仙" : (:ask_chuxian:),
   "cancel": (:ask_cancel:),
   "放弃": (:ask_cancel:),
    ]));
        setup();
        carry_object("d/tiankongjie/obj/shizi")->wear();
//        carry_object("/d/tiankongjie/obj/qingfeng")->wield();
}
void attempt_apprentice(object ob, object me)
{
        command("say 很好，" + RANK_D->query_respect(ob) +
"多加努力，他日必定有成。\n");
        command("recruit " + ob->query("id") );
        ob->set("title",HIW"八部众门徒"NOR);
        ob->save();
        return;
}               

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                  ob->set("class", "tiankongjie");
}

string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("没用的东西！");
}
else
{
     return ("你有任务吗？！");
}
}
string ask_chuxian()
{
   object me=this_player();
   
   if(me->query("family/family_name")!="天空界")
      return ("你不是本门中人!");

   command("pat "+me->query("id"));
   command("say 好好好,快去快回！");
   return "/d/obj/mieyao"->query_yao(me);
}

