



inherit NPC;
inherit F_MASTER;
string ziyingsword(object me);

void create()
{
       set_name("太上老君", ({"taishang laojun","laojun"}));
       set("long", "红尘一笑牵青牛,世人皆浊我独清.\n");
       set("title", "紫气东来");
       set("gender", "男性");
       set("age", 100);
   set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老师祖");
       set("per", 26);
   set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 3000);
       set("force_factor", 150);
       set("max_mana", 3000);
       set("mana", 5000);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
       set_skill("literate", 150);
       set_skill("unarmed", 150);
       set_skill("dodge", 180);
       set_skill("parry", 170);
   set_skill("sword",200);
   set_skill("spells", 200);
   set_skill("taiyi", 180);
   set_skill("puti-zhi", 150);
   set_skill("wuxiangforce", 180);
   set_skill("force", 200);
   set_skill("sanqing-jian", 200);
   set_skill("jindouyun", 180);
   map_skill("spells", "taiyi");
   map_skill("unarmed", "puti-zhi");
   map_skill("force", "wuxiangforce");
   map_skill("sword", "sanqing-jian");
   map_skill("parry", "qianjun-bang");
   map_skill("dodge", "jindouyun");
   set("chat_chance_combat",80);
   set("chat_msg_combat", ({
   (: cast_spell,"zhenhuo" :),
}));
   set("inquiry", ([
    "紫玉葫芦": "紫玉葫芦本为玉帝开万丹大会所备,内盛灵丹,可起死回生.\n",
      "剑": (: ziyingsword :),
      "紫郢剑": (: ziyingsword :),
      "ziying-sword": (: ziyingsword :),
]));

setup();

        carry_object("/d/lingtai/obj/pao")->wear();
}


string ziyingsword(object me)  
{
        object jian;
   me=this_player();
   if((string)me->query("family/family_name")!="五庄观") {
         message_vision("\n太上老君道：即非道友，这剑也就算了...\n", me);
         return ("你回去吧\n");
        }
    if(me->query("faith")<1000)
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
          jian = new("/d/doublesword/obj/zijian.c");
          jian->move(me);
          me->delete("laojun_trye_yes");
          me->delete("laojun_jing");
          me->delete("laojun_killjing");
          me->delete("laojun_killjingover");
          me->delete("laojun_enter");
          return ("据说，那一把剑是西王母收藏的...也不世道是真是假！！\n");
}

