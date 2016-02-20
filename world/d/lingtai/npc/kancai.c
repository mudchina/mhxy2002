// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// worker.c

string ask_kancai();
inherit NPC;
void create()
{
        set_name("砍柴道士", ({ "taoist", "dao shi", "dao" }) );
        set("gender", "男性" );
        set("age", 35);
   set("per", 30);
   set("class", "taoist");
        set("long", "一位道长，想是山中道观里的。\n");
        set("combat_exp", 10000);
        set("attitude", "peaceful");
   set_skill("axe", 10);
   set_skill("dodge", 20);
   set_skill("parry", 20);
   set_skill("unarmed", 20);
     set("chat_chance",5);
     set("chat_msg",({
        "只听砍柴道士唱道：云际依依认旧林，断崖荒草路难寻。\n",
        "砍柴道士唱道：西山望见朝来雨，南涧归时渡处深。\n",
   "砍柴道士唱道：观棋柯烂，伐木丁丁，云边谷口徐行，卖薪沽酒，狂笑自陶情。\n",
   "砍柴道士低声唱道：相逢处，非仙即道，静坐讲黄庭。\n",
       }));
   set("inquiry", ([
          "砍材": (: ask_kancai :),
          ]));


        setup();
        add_money("coin", 50);
        carry_object("/d/lingtai/obj/axe")->wield();
}
int accept_fight(object me)
{       me=this_player();
        if((int)this_player()->query("combat_exp") < 30000) {
        this_object()->set("combat_exp", (int)this_player()->query("combat_exp")+500);
        }
        return 1;
}
void init()
{
        add_action("do_vendor_list", "list");
}

string ask_kancai()
{
   object me=this_player();
   object futou=present("lumber axe",this_object());
   if((string)me->query("family/family_name")!="方寸山三星洞")
      return ("您不是本门中人。");
   if(me->query("faith")>1000)
      return ("您是本门大有名望之人，怎敢有劳您做这种杂务呢？");
   if(!("lumber axe"))return ("已经有人去砍材了。");
   me->set("lingtai/kancai",1);
   futou->move(me);
   return ("这样，就有劳您去帮我砍砍材吧。");
}
