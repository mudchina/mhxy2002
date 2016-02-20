// 神龙 by Calvin 

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int long();
string leave();
void create()
{
       set_name(HIW"神龙"NOR, ({"shen long", "long"}));
       set("long",
"它是一条具有很大法力的神龙,它可以实现你的愿望。\n");
       set("title", HIR"七色龙珠"HIG"之"NOR);
       set("gender", "男性");
       set("age", 1000);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("rank_info/respect", "龙神");
       set("per", 40);
       set("int", 40);
       set("max_kee", 30000);
       set("max_sen", 30000);
       set("force", 30000);
       set("max_force", 30000);
       set("force_factor", 3000);
       set("max_mana", 30000);
       set("mana", 30000);
       set("mana_factor", 3000);
       set("combat_exp", 100000000);
       set("daoxing", 100000000);
       set("eff_dx", 10000);
       set("nkgain", 10000);
       set_skill("literate", 1000);
       set_skill("unarmed", 1000);
       set_skill("dodge", 1000);
       set_skill("force", 1000);
       set_skill("parry", 1000);
        setup();
      carry_object("/d/longzhu/armor/pao")->wear();
      add_money("zuanshi", 5+random(50));
}

void init()
{
add_action("do_wish","wish");
}
int do_wish(string arg)
{
object me=this_player();
string *ans=({"道行","武学","潜能"});
int ans1;
if (arg=="0"||arg=="1"||arg=="2")
{sscanf(arg,"%d",ans1);arg=ans[ans1];}
 if( !arg ||
     (arg != "道行"
   && arg != "潜能"
&& arg != "武学"))
return notify_fail(CYN"神龙说道：对不住，我只能听懂三句你们这里的泥语:1.wish 道行,2.wish 武学,3.wish 潜能。你告诉我你想要什么,我会帮你实现!\n"NOR);
  if (arg=="道行"&& !(me->query("shenlonggive1")))
{
 me->add("daoxing",random(100000));
 me->set("shenlonggive1",1);
message_vision (HIG "$N闭上眼睛想了一下说道：我要"+arg+"吧!\n",me);
message_vision("$N对着$n说道:"+HIW"好吧,我马上帮你实现愿望.\n"+HIC"神龙闭目冥思,嘴里喃喃的念叨:"+HIR "赞裰龠挲,尼尻喏。 天神赐于我神的力量! 呜玛莫西~~~ \n",this_object(),me);
 message_vision(HIC "$N感觉到一股神气的力量在身体里涌动,慢慢的扩散到全身.立刻,身体发生了微妙的变化!\n\n",me);
message_vision(HIC "$N对着$n说道:"+HIC+"你实现愿望了.我该回到我的世界了!\n说罢,转身消失在茫茫时空之中.\n\n",this_object(),me);
destruct(this_object());
}
else if (arg=="武学"&& !(me->query("shenlonggive2"))) { 
me->add("combat_exp",random(100000));
 me->set("shenlonggive2",1);
message_vision (HIG "$N闭上眼睛想了一下说道：我要"+arg+"吧!\n",me);
message_vision("$N对着$n说道:"+HIW"好吧,我马上帮你实现愿望.\n"+HIC"神龙闭目冥思,嘴里喃喃的念叨:"+HIR "赞裰龠挲,尼尻喏。 天神赐于我神的力量! 呜玛莫西~~~ \n",this_object(),me);
 message_vision(HIC "$N感觉到一股神气的力量在身体里涌动,慢慢的扩散到全身.立刻,身体发生了微妙的变化!\n\n",me);
message_vision(HIC "$N对着$n说道:"+HIC+"你实现愿望了.我该回到我的世界了!\n说罢,转身消失在茫茫时空之中.\n\n",this_object(),me);
destruct(this_object());
}
else if (arg=="潜能"&&!(me->query("shenlonggive3"))) {
  me->add("potential",random(100000));
  me->set("shenlonggive3",1);
 message_vision (HIG "$N闭上眼睛想了一下说道：我要"+arg+"吧!\n",me);
message_vision("$N对着$n说道:"+HIW"好吧,我马上帮你实现愿望.\n"+HIC"神龙闭目冥思,嘴里喃喃的念叨:"+HIR "赞裰龠挲,尼尻喏。 天神赐于我神的力量! 呜玛莫西~~~ \n",this_object(),me);
message_vision(HIC "$N感觉到一股神气的力量在身体里涌动,慢慢的扩散到全身.立刻,身体发生了微妙的变化!\n\n",me);
 message_vision(HIC "$N对着$n说道:"+HIC+"你实现愿望了.我该回到我的世界了!\n说罢,转身消失在茫茫时空之中.\n\n",this_object(),me);
}
if((me->query("shenlonggive1"))||(me->query("shenlonggive2"))||(me->query("shenlonggive3"))) return notify_fail(CYN "神龙愤怒的说道:你的这个愿望我已经给你了,不要太贪心呀!\n");
if((me->query("shenlonggive1"))&&(me->query("shenlonggive2"))&&(me->query("shenlonggive3"))) {message_vision(CYN "神龙愤怒的说道:$n的所有愿望我已经给你了,不能再帮你了!\n",me);destruct(this_object());}
return 1;
}
string leave()
{
destruct(this_object());
message("vision",
HIM"........................................................................................................................"HIG"寂静的天空忽然传来一阵雷般的呼唤声:"HIW"神龙归位~~~~~"HIM"........................................................................................................................"

     HIW"神龙"HIB"说道:"HIW"上天在召唤我了,我得回去了"HIB"。"HIB"话毕,一道绚光,神龙逝去了威严的身影。"HIM".............................................................................................................\n"NOR
  NOR,environment(),  this_object() );
}
