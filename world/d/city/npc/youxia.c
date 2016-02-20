//Cracked by Roath
inherit NPC;
#include <weapon.h>
#include <ansi.h>

inherit F_MASTER;
  string expell_me(object me);

void create()
{
  set_name("游侠儿", ({ "youxia er","er","xia", "man"}) );
  set("gender", "男性");
  set("age", 10);
  set("title", HIW"江湖浪子"NOR);
  set("long","时下游侠之风甚重，连长安街头也可看到华装佩剑少年。\n\
此人为游侠中的杰出人物。武功高深莫测，喜欢行侠仗义，除强扶弱。\n\
长安城中声望极高，不少普通百姓即拜他为师。\n");
  set("combat_exp", 2000000+random(3000000));
  set("daoxing", 1000000);

  set("per", 15);

  set_skill("piaoxiang", 150);
        set_skill("sword", 180);
        set_skill("force", 180);
        set_skill("spells", 180);
        set_skill("lingxiyizhi", 150);
        set_skill("tianjijue", 150);
        set_skill("wuji-force", 180);
        set_skill("tanzhishentong", 150);
        set_skill("spells", 180);
        set_skill("literate", 120);
         set_skill("baiyun-sword", 150);
           set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
            map_skill("force", "wuji-force");
            map_skill("unarmed", "lingxiyizhi");
            map_skill("spells", "tianjijue");
            map_skill("dodge", "piaoxiang");
        map_skill("sword", "baiyun-sword");
        map_skill("parry", "baiyun-sword");
  set("max_sen",800);
  set("force", 1800);
  set("max_force", 1800);
  set("force_factor", 100);
  set("mana", 2000);
  set("max_mana", 2000);
  set("mana_factor", 100);

        set("inquiry", ([
          "leave": (: expell_me :),
//                 "leave": (: expell_me :),
]) );

   create_family("江湖浪子", 2, "绿");

  setup();

  carry_object("/d/qujing/kusong/obj/tongjia")->wear();
}

void attempt_apprentice(object ob)
{       ob=this_player();

 if( (string)ob->query("family/family_name") == "江湖浪子") {;
 command("say 小王八蛋，没经过你师傅同意就敢来拜我，biang 的带死！\n");
  return;
  }
                command("grin");
                command("recruit " + ob->query("id"));
                return ;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "yaomo");
                ob->set("title", "江湖浪子");
        }
}


string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="江湖浪子") {
                me->set_temp("betray", 1);
                return ("既是要出山，却需受山规惩罚，你可愿意(agree)?");
        }
        return ("不知。");
}
void init()
{
::init();
        add_action("do_agree", "agree");
}

int do_agree(string arg)
{
      if(this_player()->query_temp("betray") &&
                  this_player()->query("family/family_name")=="江湖浪子") {
                message_vision("$N答道：愿意。\n\n", this_player());
                this_player()->add("betray/count", 1);
                this_player()->add("betray/huoyun", 1);
                this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "普通百姓");
                this_player()->save();
                command("say 那你去吧！\n");
                return 1;
                }
        return 0;
}


