//By tianlin@mhxy for 2002.1.2.
 
#include <ansi.h>
inherit NPC;
string ziyingsword(object me);
void create()
{
       set_name("太上老君", ({"taishang laojun","laojun"}));
       set("long", "红尘一笑牵青牛,世人皆浊我独清.\n");
       set("title", HBRED+MAG"紫气东来"NOR);
       set("gender", "男性");
       set("age", 100);
       set("class", "xian");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("rank_info/respect", "老师祖");
	create_family("五庄观", 1, "老师祖");
       set("per", 26);
       set("int", 30);
       set("combat_exp", 3000000);
       set("daoxing", 3000000);
       set_skill("unarmed", 285);
       set_skill("wuxing-quan", 285);
       set_skill("dodge", 285);
       set_skill("baguazhen", 285);
       set_skill("parry", 285);
       set_skill("medical",285);
       set_skill("sword", 285);
       set_skill("sanqing-jian", 285);
       set_skill("staff", 285);
       set_skill("fumo-zhang", 285);
       set_skill("hammer", 285);
       set_skill("kaishan-chui", 285);
       set_skill("blade", 285);
       set_skill("yange-blade", 285);
       set_skill("force", 285);   
       set_skill("zhenyuan-force", 285);
       set_skill("literate", 180);
       set_skill("spells", 285);
       set_skill("taiyi", 285);
       map_skill("spells", "taiyi");
       map_skill("force", "zhenyuan-force");
       map_skill("unarmed", "wuxing-quan");
       map_skill("sword", "sanqing-jian");
       map_skill("dodge", "baguazhen");
       map_skill("staff", "fumo-zhang");
       map_skill("blade", "yange-blade");
       map_skill("hammer", "kaishan-chui");

       set("max_kee", 4500);
       set("max_sen", 4500);
       set("force", 6000);
       set("max_force", 5500);
       set("mana", 7000);
       set("max_mana", 4000);   
       set("force_factor", 200);
       set("mana_factor", 200);

       set("spell_qiankun_on", 1); //to use cast qiankun, must set this.
       set("chat_chance_combat", 90);
       set("chat_msg_combat", 
   ({
     (: cast_spell, "zhenhuo" :),
     (: perform_action, "sword", "jianmang" :),
   }) );
      set("inquiry", ([
      "紫玉葫芦": "紫玉葫芦本为玉帝开万丹大会所备,内盛灵丹,可起死回生.\n",
      "剑": (: ziyingsword :),
      "紫郢剑": (: ziyingsword :),
      "ziying-sword": (: ziyingsword :),
      "jian": (: ziyingsword :),
]));

setup();

        carry_object("/d/lingtai/obj/pao")->wear();
        carry_object("/d/33tian/obj/yunxue")->wear();
        carry_object("/d/obj/weapon/sword/zijian")->wield();
}
void init ()
{
  add_action("do_back", "back");
}
int accept_object(object who, object ob)
{
 if((string)ob->query("id") !="baiyu-ling"){
 command("say 你没有玉帝的信物,怎么能给你紫玉葫芦.");
 return 0;
}
else {  
 command("smile");
 command("say 不过这紫玉葫芦非同小可,若在路上被人抢了去,我怎生向玉帝交侍.");
 command("say 除非你胜了我,这才能放心得把它交给你!");
 this_player()->set_temp("laojun_fight", 1);
 return 1;
}
}
int accept_fight(object who)
{
 object me;
 me = this_object();
     if (!who->query_temp("laojun_fight")){
     command("say 修道之人不宜妄动无明!!\n");
         return 0;
   }

 say("太上老君笑道:今日老道就拼了这身老骨头,陪你过几招吧!\n");
  me->set("eff_kee", (int)me->query("max_kee"));
        me->set("kee", (int)me->query("max_kee"));
        me->set("eff_sen", (int)me->query("max_sen"));
        me->set("sen", (int)me->query("max_sen"));
     who->set_temp("laojun_fight",0);
     remove_call_out("check_fight");
     call_out("check_fight", 1, me, who);
     return 1;
}
void player_win(object me, object who)
{
       object hulu;

      hulu=new("/d/33tian/obj/hulu");
      command("sigh");
      say("太上老君叹道:小神仙果然是法力高强,看来我是真的老了!!\n");
      hulu->move(who);
message_vision("太上老君道:这紫玉葫芦今日就交给$N了,路上可得小心了.\n",who);
}
void player_lose (object me, object who)
{
     string msg;
     msg = RANK_D->query_respect(who);

   command("jump");
   say("太上老君笑道:"+msg+"看来还要再练几年,才有资格拿这紫玉葫芦!\n");
}
void check_fight (object me, object who)
{
     int my_kee, whos_kee;
     int my_max_kee, whos_max_kee;

   if(!who) return;
     my_kee = me->query("kee");
     whos_kee = who->query("kee");
     my_max_kee = me->query("max_kee");
     whos_max_kee = who->query("max_kee");

     if (me->is_fighting()){
         call_out ("check_fight",1,me,who);
         return;
     }

     if (!present(who, environment(me)))
         return;
   if ((my_kee*100/my_max_kee) <= 50)
     player_win (me, who);
   else if ((whos_kee*100/whos_max_kee) <= 50)
     player_lose (me, who);
}

void die()
{

        if( environment() ) {
message("sound", "\n\n太上老君怒道,你这厮怎地这生无礼！\n\n", environment());
message("sound", "\n说罢起身上了青牛,架云朝瑶池而去。。。\n\n", environment());

        }

        destruct(this_object());
}
void attempt_apprentice(object ob)
{
   if( (string)ob->query("class")=="dao" )
     command("say 好，好！道仙本一家。\n");
   
  //}

   if( (string)ob->query("family/family_name")=="五庄观" )
   {
     if( (int)ob->query("family/generation") > 3   )
     {
        command("say 福禄寿他们正想多收几个弟子，你先到那边看看吧。\n");
     }
     else 
     {
        if( (int)ob->query("combat_exp") >= 300000 && (int)ob->query_skill("taiyi", 1) >= 120 )
        {
          command("nod ");
          command("say 好，" + RANK_D->query_respect(ob) + "不愧是本门的人才！\n");
          command("recruit " + ob->query("id") );
        message("channel:rumor",HIM+"【谣言】某人：听说"HIW"<<"BLINK+HIW+ob->query("name")+NOR+HIW">>"HIY"西天取经"NOR+HIM"得以正果得到"HIC"太上老君"HIM"的指点，真是可喜可贺。\n"NOR,users() );
        }
        else
        {
          command("say 有心上进是不错，不过还是要循序渐进。\n");
        }
     }
   }

   else
   {
     command("nod");
     command("say 这位" + RANK_D->query_respect(ob) + "，本门讲究长幼之礼，尊卑之分。一下让你成为二代弟子恐人心不服。\n");
   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "xian");
              ob->set("title",HIW"兜率宫道法真传"NOR);
}
int do_back(string arg)
{
  object who = this_player();
  object me = this_object();
  string here = (string)environment(me);
  string there = who->query_temp("33tian/from");

  message_vision("$N请求$n送$N回返。\n",who,me);
  there = "/d/city/kezhan";

  message_vision("$N的手掌轻轻托起$n向远方伸去……\n",me,who);
  who->move(there);
  message_vision("……云中伸出一只巨大的佛手轻轻一翻，只见$N从里面跳出来。\n",who);
  
  return 1;
}
string ziyingsword(object me)  
{
        object jian;
   me=this_player();
 //  if((string)me->query("family/family_name")!="五庄观") {
 //        message_vision("\n太上老君道：即非道友，这剑也就算了...\n", me);
 //        return ("你回去吧\n");
 //       }
    if(me->query("faith")<500)
          command("say 我怎么相信你呢？");
     if( me->query("laojun_killjing") != 1 ) 
        {
          me->set("laojun_jing", 1);
          message_vision("\n太上老君道：你叫我如何来相信你呢？!\n", me);
          return ("据说，在五庄观后花园里有犀牛精，铁拐里比较清楚，你且去看看！\n");
        }
     if( me->query("laojun_killjing") != 1 ) 
        {
          message_vision("\n太上老君道：你叫我如何来相信你呢？!\n", me);
          message_vision("太上老君掐指一算.....\n\n", me);
          message_vision("太上老君道：是在皇宫!\n", me);
          return ("既然如此，还不快去！\n");
        }
     if( me->query("enter") != 1 ) 
        {
          message_vision("\n太上老君道：你叫我如何来相信你呢？!\n", me);
          message_vision("\n太上老君道：是在皇宫!你进后院看看呀！\n", me);
          return ("既然如此，还不快去！\n");
        }
     if( me->query("laojun_killjingover") != 1 ) 
        {
          message_vision("\n太上老君道：你叫我如何来相信你呢？!\n", me);
          message_vision("\n太上老君道：是在皇宫!你进后院看看呀！\n", me);
          return ("既然如此，还不快去！\n");
        }

          message_vision("\n太上老君道：好好，理当奖励，这把剑也就送给你了。\n", me);
          message_vision("太上老君阴声到：如若叫我看见你为非作歹，莫怪我心狠手辣！\n", me);
          message_vision("太上老君送给你一把紫郢剑。\n", me);
          jian = new("/d/obj/weapon/sword/zijian.c");
          jian->move(me);
          me->delete("laojun_trye_yes");
          me->delete("laojun_jing");
          me->delete("laojun_killjing");
          me->delete("laojun_killjingover");
          me->delete("laojun_enter");
          return ("据说，那一把剑是西王母收藏的...也不世道是真是假！！\n");
}
