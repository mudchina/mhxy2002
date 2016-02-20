inherit NPC;
#include <ansi.h>

void create()
{
  set_name(HIR"猪大肠"NOR, ({"zhu dachang", "dachang", "zhu"}));
  set("age", 28);
  set("gender","男性");
  set("attitude", "peaceful");
  set("str", 40);
  set("per",11);
  set("combat_exp",30000);
  set("daoxing",30000);
  set("title",HIG"天蓬迎宾"NOR);
  set("chat_chance",30);
  set("chat_msg", ({
        "猪大肠喃喃地道：我就是这里的迎宾了。这里的迎宾就是我--猪大肠\n",
        "猪大肠低吟道：九世乞丐九世好，九世皇帝也不换。\n",
        "猪大肠大声喊道：这里除了八戒哥哥就数我最大！\n",
        }));



  set("max_kee", 500);
  set("max_sen", 500);
  set_skill("unarmed", 30);
  set_skill("dodge", 30);
  set_skill("parry", 30);
  setup();
  carry_object("/d/obj/cloth/bingfu")->wear();
}

void inint ()
{
  call_out ("looking",1,this_player());
}

void looking (object who)
{
  command ("look "+who->query("id"));
}
void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "猪大肠热情地说道：这位猪哥哥，欢迎来咱们天蓬府！\n");
}

