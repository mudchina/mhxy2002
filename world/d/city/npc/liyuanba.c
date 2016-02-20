// by gslxz@mhsj 1/7/2001
#include <ansi.h>
inherit NPC;

int test_player (object me);

void create()
{
  set_name("李元霸", ({"li yuanba", "li", "yuanba"}));
  set("long", "掌管天下各门派的事务。\n");
  set("title", HIY"御赐钦差"NOR);
  set("gender", "男性");
  set("age", 36);
  set("per", 18);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 2000);
  set_skill("unarmed", 10);
  set_skill("dodge", 10);
  set_skill("parry", 10);
  set("max_gin",200);
  set("max_kee",200);
  set("max_sen",200);
  set("max_force",200);
  set("max_mana",200);
  set("force_factor",12);
  set("inquiry", ([
        "奖励":   (: test_player :),
        "钱": (: test_player :),
        "奖赏": (: test_player :),
      ]));

  setup();
    carry_object("/d/obj/armor/jinsijia.c")->wear();//by tianlin 2001.9.4修改,因为gslxz是个笨蛋,只把这个npc文件,copy
//下来了,没有带上clone/armor/pao.c文件,肯定是个bug错误,我现在给修正
}
// by gslxz@mhsj 1/7/2001

int test_player (object me)
{
  object who = this_player();

  if (who->query("weiwang")<150)
  {
  me->command_function("shake");
  me->command_function("say 以你的师门威望，还不能够领取奖赏。");
    return 1;
  }  

  me->command_function("nod");
  call_out ("give_money",2,me,who);
  return 1;
}

void give_money (object me, object who)
{

  object money = new ("/obj/money/gold");
  add_money("gold", 1000);
  command("give 1000 gold to " + this_player()->query("id"));
  this_player()->add("weiwang",-150);
  me->command_function ("give "+who->query("id")+" money");
 message("shout",HIY+"【大唐天朝】李元霸(Li yuanba)："HIW+this_player()->query("name")+HIY"多次圆满完成师门任务，勇气可嘉，皇上赐其黄金千两。\n"+NOR,users());
}
// by gslxz@mhsj 1/7/2001
void die()
{
  if (environment())
    message("sound", "\n\n李元霸大喊一声:皇帝救命,李元霸又复活了！\n\n", environment());

  set("eff_kee", 600);
  set("eff_gin", 600);
  set("eff_sen", 600);
  set("kee", 600);
  set("gin", 600);
  set("sen", 600);
  set("force", 600);
  set("mana", 600);
}

void unconcious()
{
  die ();
}
