// 孔方兄, bookseller.
// 5-3-97, pickle

#include <dbase.h>
inherit F_VENDOR_SALE;

void create()
{
set_name("卖书童", ({ "shu tong", "seller", "vendor" }) );
  set("gender", "男性" );
    set("age", 27);
set("long","据说他曾是个武林高手，后来因为江湖纷争才投奔孔方，\n他的武功可是十分了得哦。\n");
    set("combat_exp", 800000);
  set("daoxing", 20000);

  set("attitude", "friendly");
set_skill("force",140);
set_skill("wuxiangforce",140);
set_skill("dodge",140);
set_skill("jindouyun",140);
set_skill("parry",140);
set_skill("unarmed",140);
set_skill("puti-zhi",140);
map_skill("unarmed","puti-zhi");
map_skill("force","wuxiangforce");
map_skill("dodge","jindouyun");
  set("per",25);
  set("force",2000);
set("max_force",2000);
set("mana",200);
set("max_mana",200);
set("force_factor",100);
  set("vendor_goods", ([
      "xiyouji": "/u/tianlin/wiz/newbook/xiyouji",
      "honglou": "/u/tianlin/wiz/newbook/honglou",
      "sanguo": "/u/tianlin/wiz/newbook/sanguo",
      "forcebook2": "/d/obj/book/forcebook2",
      "shuifu": "/u/tianlin/wiz/newbook/shuifu",
   ]));
  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  object ob;

  ::init();
  if( interactive(ob = this_player()) && !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
  add_action("do_vendor_list", "list");
    add_action("do_bid", "bid");
      add_action("do_status", "status");
    add_action("do_cast", "cast");
}

void greeting(object ob)
{
  if( !ob || !visible(ob) || environment(ob) != environment() ) return;
    command("say 这位" + RANK_D->query_respect(ob) +"快请进，本店新到了几本武功秘籍，快看看吧。");
}

mixed buy_object (object who, object item)
{
  object npc = this_object();
  string st;

  st= "total"+(string)item;
  if (npc->query_temp("total_books") < 30)
      {
	if (npc->query_temp(st)<10)
	  {
	  //  npc->add_temp(st,1);
	      // limit needed only for non-skills books
  	    return ::buy_object(who,item);
	  }
	else
	  {
	    return notify_fail(name()+"说道：对不起，您老要的书卖完了！您等下一批进货吧。\n");
	  }
	//npc->add_temp("total_books", 1);
      }
      else
      {
	return notify_fail(name()+"说道：小店本小，今日以将存货卖完了。您老等下一批吧。\n");
      }
}

int do_bid()
{
    return notify_fail("这个店不能盘！\n");
}
  int do_status()
  {
    return notify_fail("什么？\n");
  }
int do_cast(string arg)
{
     object who = this_player();
     object me = this_object();
     message_vision("$N对着$n结结巴巴的想念咒语，却怎么也张不开嘴。\n",who,me);
 return 1;
}
