//2001.5.22
//by yxm
#include <ansi.h>
inherit NPC;
void create()
{
set_name("阿依那伐", ({ "ayi nafa", "ayinafa", "nafa" }));
set("long", "他就是天下第一神刀，掌管阿修罗界的大神，如来佛祖的大弟子阿依那伐。
传说他精通三界内的任何机关，暗器,奇门遁甲之术！是佛界里不可多得的人才。
可惜他心术不正，所以被如来佛祖冷眼相看。\n");
set("title", HIW"天下"HIR"第一"HIW"神刀"NOR);
  set("gender", "男性");
  set("age", 800);
  set("str",40);
  set("per",40);
  set("max_kee", 5000);
  set("max_gin", 5000);
  set("max_sen", 5000);
  set("force", 5000);
  set("max_force", 5000);
  set("force_factor", 300);
  set("max_mana", 5000);
  set("mana", 5000);
  set("mana_factor", 300);
  set("combat_exp", 3900000);
  set("daoxing", 28000000);
  set_skill("buddhism", 300);
  set_skill("dodge", 300);
  set_skill("force", 300);
  set_skill("jienan-zhi", 300);
  set_skill("literate", 300);
  set_skill("lotusforce", 300);
  set_skill("lotusmove", 300);
  set_skill("bingpo-blade", 300);
  set_skill("parry", 300);
  set_skill("spells", 300);
  set_skill("blade", 300);
  set_skill("unarmed", 300);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("blade", "bingpo-blade");
  map_skill("parry", "bingpo-blade");
  set("chat_chance_combat", 80);
  set("chat_msg_combat", ({
   (: cast_spell, "bighammer" :),
                (: perform_action, "blade", "yaowu" :),
  }) );
         set("inquiry", ([
  "孔雀明王": "嘿嘿，她是我平生最恨的人，如果你能帮我杀了她，我就带你去一个好地方。",
  "孔雀": "嘿嘿，她是我平生最恨的人，如果你能帮我杀了她，我就带你去一个好地方。",
  "佛母": "嘿嘿，她是我平生最恨的人，如果你能帮我杀了她，我就带你去一个好地方。",
  ]));
  setup();
  carry_object("/d/obj/cloth/jia_sha")->wear();
carry_object("/u/tianlin/阿修罗界/obj/shixieshendao")->wield();
}

int accept_object(object me, object ob)
{
	 me=this_player();


        if( (string)ob->query("id")=="ziying-sword" )
        {
                   if ( me->query("xiuluo/lingjiu_ok") != 1)
                           return notify_fail("你是怎么得到这把剑的?!哼！\n");
              {
                    command("u&me " + me->query("id"));
                   command("say 这位" + RANK_D->query_respect(me) + "真是明白我意！\n你既然帮我除掉了大仇，我也不会食言。\n让我的狂风把你吹到另外一个世界去吧。\n........\n");
                   tell_object(me,"\n一阵狂风向你吹来...\n\n你揉揉眼睛，已经到了另外一个世界。\n\n");
command("rumor 听说"HIR""+me->query("name")+""HIM"被"HIR"阿依那伐"HIM"带进了"WHT"阿修罗界"NOR"！");
                 me->set("xiuluo/lingjiu_ok",0);  
                 me->move("/u/tianlin/阿修罗界/jiemen");
                return 1;
        }
}
}