#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int rank_me();
string ask_bad(object me);
string ask_mieyao();
string ask_cancel();
void create()
{
  set_name("秦琼", ({ "qin qiong", "qin", "shubao", "qiong", "qin shubao", "master", "shifu" }));
  set("title", HIY"开国元勋"NOR);
  set("gender", "男性");
  set("age", 43);
  set("str", 30);
  set("per", 26);
  set("int", 30);
  set("cor", 50);
  set("cps", 50);
  set("long", "秦叔宝是大唐国开国名臣，更是一位出名的武将。\n");
  set("combat_exp", 1200000);
  set_skill("literate", 200);
  set_skill("spear", 220);
  set_skill("force", 220);
  set_skill("dodge", 280);
  set_skill("parry", 250);
  set_skill("xuanyuan-archery",280);
  set_skill("mace", 300);
  set_skill("archery", 250);
  set_skill("wusi-mace", 280);
  set_skill("yanxing-steps", 250);
  set_skill("bawang-qiang", 200);
  set_skill("lengquan-force", 220);
 set_skill("unarmed", 260);
  set_skill("changquan", 220);
  map_skill("mace", "wusi-mace");
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
  map_skill("archery", "xuanyuan-archery");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 2800);
  set("max_kee", 4400);
  set("force", 2000);
  set("max_force", 1800);
  set("force_factor", 80);
  set("inquiry", ([
                   "name": "在下秦琼，字叔宝。",
                   "here": "这里就是将军府啊，难道你不知道？",
                   "rumors": "在下不在江湖行走很久了，江湖上的事情在下可不太清楚。",
                   "cancel": (: ask_cancel :),
                   "除魔": (: ask_mieyao :),
                   "逃犯": (: ask_bad :),
				            "职位": (: rank_me :),
                   ]) );

  create_family("将军府", 2, "蓝");
  set("chat_chance_combat", 60);
  set("chat_msg_combat", ({
                (: perform_action, "spear", "qiangjian" :),
  }) );

  setup();
  carry_object("/d/obj/weapon/spear/yinqiang")->wield();
  carry_object("/d/obj/armor/tiejia")->wear();
  carry_object("/d/obj/weapon/mace/copperjian");
}

string ask_bad(object me)
{
    me=this_player();
    if ( me->query("office_number") > 1000 )
        return ("不敢有劳大驾。");
    if(me->query("combat_exp") < 100000 )
        return ("我怎么能放心你去呢？");
    return "/d/obj/bad"->query_yao(me);
}

int accept_object(object who, object ob)
{
                object me=this_player();
int exp,qn;
      string bname = who->name()+"的"+who->query("bad/name") + "的头颅";
     
     if ( (string)ob->query("name") != bname )
        return notify_fail("秦琼怒道：你竟敢糊弄我！\n");
        
if (!ob->query("killer") ||ob->query("killer") != who->query("id"))
       return notify_fail("秦琼大怒：不是你杀的也敢拿来,小心我扁你！\n");

      who->add("office_number", 1);
  if(who->query("family/family_name")!="将军府")
{
who->add("daoxing",(1000+random(200))/2);
 who->add("potential",(100+random(250))/2);
}
else {
who->add("daoxing",1000+random(200));
 who->add("potential",100+random(250));
}
// exp=1000 + random(100);
// qn=100 + random(250);
  tell_object(me,HIR"你把逃犯的头颅交给了秦琼。\n"NOR);
  tell_object(me,HIC"秦琼点点头：干的不错，应该奖励。\n");
tell_object(me,HIG"你得到了些道行和点潜能。\n"NOR);
      command("smile");
      command("addoil " + who->query("id"));
  message("channel:chat",HIY+"【将军府】秦琼(Qin qiong)："NOR+YEL+who->query("name")+HIY"杀死了"NOR+HIR+who->query("bad/name")+HIY"，为民除害，功加一等。\n"+NOR,users());
      who->delete("bad");
      return 1;
}


string ask_mieyao()
{
  object me=this_player();
  if(me->query("family/family_name")!="将军府")
     return ("你不是本门中人！");
  command("smile "+me->query("id"));
  return "/d/obj/mieyao"->query_yao(me);
}
int accept_fight(object me)
{
  command("say 老夫久未和江湖人动手过招了，今日也不想破例。\n");
  return 0;
}
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "将军府掌门")
		return notify_fail("你已经是掌门人了，还来要什么职位．\n");
        if( (string)me->query("family/family_name") == "将军府"){
                if( exp <= 100000 ){
                        me->set("title", HIW"大唐将军府"YEL"护院亲兵"NOR);
                  } else if(exp <= 1000000 ){
                        me->set("title", HIW"大唐将军府"YEL"先锋大将"NOR);
                  } else if(exp <= 2000000 ){
                        me->set("title", HIW"大唐将军府"YEL"守城提督"NOR);
                  } else if(exp <= 3000000 ){
                        me->set("title", HIW"大唐将军府"YEL"兵马大元帅"NOR);
                } else {
                        me->set("title", HIW"大唐将军府"YEL"开国元勋"NOR);
                }

                tell_object(me, "秦琼对你说：你可以做"+me->query("title")+"。\n");
                tell_room(environment(me),
"秦琼对"+me->query("name")+"说：你可以做"+me->query("title")+"。\n", ({me, me}));
         CHANNEL_D->do_channel(me,"chat","现授予本门弟子"+me->query("name")+""NOR+me->query("title")+HIC"一职。恭请各位仙长多加捧场！");
     me->save();  
        }
        return 1;
}
int attempt_apprentice(object me)
{
  string myname=RANK_D->query_respect(me);
  if ((int)me->query("combat_exp")< 100000)
    {
      command("say 这位"+myname+"还是先去跟本府家将打打基础吧！");
      return 0;
    }
  command("haha");
  command("say 很好，时下正是用人之际，"+myname+"多加努力，他日必定有成。\n");
  command("recruit " + me->query("id") );
  return 1;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "fighter");
}
int prevent_learn(object me, string skill)
{
  string myname=RANK_D->query_respect(me);

  if (me->query("combat_exp") < 100000)
    {
      command("emote 皱了皱眉头，说道："+myname+"还欠修练，老夫所教"+myname+"恐怕难以理解。");
      return 1;
    }
  return 0;
}

string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="将军府")
    {
      me->set_temp("betray", 1);
      command("sigh");
      return ("按我大唐律法，却须受罚，你可愿意(agree)？");
    }
  return ("去问问袁先生吧，或许他知道！");
}
void init()
{
  add_action("do_agree", "agree");
}
int do_agree(string arg)
{
  if(this_player()->query_temp("betray"))
    {
      message_vision("$N答道：弟子愿意。\n\n", this_player());
      command("say 那你便去吧，江湖险恶，好自为之。。。");
      this_player()->add("betray/count", 1);
      this_player()->add("betray/jjf", 1);
      this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
      this_player()->delete("family");
      this_player()->delete("class");
      this_player()->set("title", "普通百姓");
      this_player()->set_temp("betray", 0);
      this_player()->save();
      return 1;
    }
  return 0;
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


