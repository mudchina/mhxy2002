//guinu.c 龟奴by swagger

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("龟奴", ({ "gui nu", "gui", "nu" }) );
        set("gender", "男性" );
        set("title", HIR"翠花楼总管"NOR);
        set("age", 32);
        set("long", 
            "翠花楼的总管，干尽了逼良为娼的坏事。\n");
        set("str", 35);
        set("dex", 35);
        set("con", 25);
        set("int", 25);
        set("per", 10);
        set("shen_type", -1);

        set_skill("unarmed", 100);
        set_skill("force", 100);
        set_skill("dodge", 100);

        set("combat_exp", 200000);

        set("max_kee", 600);
        set("max_sen", 600);
        set("force", 600);
        set("max_force", 600);

        set("attitude", "friendly");
        set("inquiry", ([
            "name" : "老子就是这儿的总管，想找小姐找我。",
            "here" : "这儿就是闻名天下的翠花楼了，要不要找个小姐?",
            "赎身" : "好啊，赎身是可以的，不过这价钱可得好好商量商量。",
       ]) );

        setup();
        set("chat_chance", 6);
        set("chat_msg", ({
        "龟奴奸笑着说：我们这儿正缺小姐，如果你有老婆，妹妹，就卖到我这儿来。\n",
        "龟奴嘿嘿的奸笑着，不知道又在想什么坏事了。\n",
        }) );
        carry_object("/obj/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_sell","sell");
}

void greeting(object me)
{
    object * ob;
    int found,i;
    
    found = 0;
    
    if (me->query("jinu")) {
        command("say 好啊，"+me->name() + "，你再跑试试，看我不打断你的腿！");
        return;
    }
   {
      ob = all_inventory(environment());
      for(i=sizeof(ob)-1; (i>=0) && !found; i--) {
      if( !userp(ob[i]) ) continue;
      if (ob[i]->query("jinu")) {
         found = 1;
         command ("say "+ob[i]->name() + "，没看见来客人了，还不快迎接！ ");
      }
      }   
    }
    return ;
}
int do_sell(string arg)
{
    object ob;
    int value, per, extra = 1;
   
    if (!arg || !(ob = present(arg, this_player())))
       return notify_fail("请问你要卖谁啊？\n");
       
    if (!ob->is_character())
       return notify_fail("这我可不要，你得卖到当铺去。\n");
              
//    if (!userp(ob))
//       return notify_fail("这个不行，我只要玩家。\n");
       
    if (ob->query("gender")!="女性")
       return notify_fail("对不起了，本院目前没有这项服务。\n");
      
    if ((value = ob->query("age")) < 18)
       return notify_fail("不行，幼女我可不要。\n");

    if ((value = ob->query("per")) < 20)
       return notify_fail("她也的太丑了，我买下来只会赔本，不要。\n");

    if (ob->query("jinu"))
       return notify_fail("她本身就是我们这儿的小姐，你想干嘛？\n");
       
    if ((value = ob->query("daoxing")) < 100000)
       return notify_fail("她还是个雏儿呢，等大一些再来吧。\n");

    if ((value = ob->query("combat_exp")) < 200000)
       return notify_fail("她还是个雏儿呢，等大一些再来吧。\n");

    per = ob->query("per")*100;
    if( ob->query_temp("top_girl") ) {
        extra = 10 ;
        per = ob->query("per")*1000;
        command("say 这次的货色不错，这小妞真不赖！\n");
    }

    message_vision("$N把"+ ob->name()+"卖到了翠花楼。\n", this_player());
    MONEY_D->pay_player(this_player(), (per+value)*extra);
    this_player()->set("shen",this_player()->query("shen")-(value/100));
    this_player()->set("sell_woman/" + ob->query("id"), 1);
    this_player()->set("title","翠花楼皮条客");
    command("admire "+this_player()->query("id"));
    command("rumor 大新闻!据说"+ ob->name()+"被卖到了翠花楼! \n");
    command ("chat 我们翠花楼又新来了一位小姐，欢迎各位大爷光顾！");
    command ("say 好，干的不错，这是你的金子！");
    ob->move(this_object());
    ob->set("title","翠花楼小姐");
    ob->set("jinu",1); 

    return 1;
}
 
int accept_object(object me, object obj)
{
  if(obj->query("money_id")) {
    if(me->query("jinu")) {
        if (obj->value()>= me->query("combat_exp")
*2)  {  
        command ("say 好吧，即然你要从良我也不留你了，多多保重。");
        command ("cry "+me->query("id"));
        me->set("title",me->query("family/family_name")+"第"+
                chinese_number(me->query("family/generation"))+
                "代弟子");
        me->set("jinu",0); 
        command("kissbye "+me->query("id"));
        command("rumor 据说"+me->name()+"赎身脱离了翠花楼! \n");
        return 1;
        }
        else {
        command("say 谢谢"+me->query("nickname")+"赏钱。");
        command("bow "+ me->query("id"));
        return 1;
        }
    }
  }
  else return 0;
} 


