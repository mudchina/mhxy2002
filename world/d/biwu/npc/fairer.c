//FY3@linxue
#include <ansi.h>
#include <net/dns.h>
inherit NPC;
void create()
{
        set_name( "公平子", ({ "fairer" }) );
        set("title", HIY "铁面无私" NOR);
        set("gender", "男性" );
        set("age", 42);
        set("int", 30);
        set("long",
                "公平子的来历师承谁也不知道，但他人不但性情豪爽，且
                 铁面无私，凡是由他裁定的事都绝对公平。\n"
                );
       set("chat_chance", 2);
        set("chat_msg", ({
                "公平子说道：这个月的比武大会就要举行了！有人出面招集吗？\n",
                "公平子说道：比武大会（biwu）的事．．．．\n",
        }) );
        set("attitude", "peaceful");
        set_skill("unarmed", 300);
        set_skill("changquan", 300);
        set_skill("literate", 300);
        set_skill("force", 300);
        set_skill("dodge",300);
        set_skill("parry",300);
        map_skill("unarmed", "changquan");
        set("combat_exp", 9000000);
        setup();
        carry_object("/d/city/obj/cloth")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}

void init()
{
        ::init();
        add_action("do_ask", "biwu");
        add_action("do_join", "join");
        add_action("do_decide", "decide");
        add_action("do_hold", "hold");
        add_action("do_show", "list");
        add_action("do_over", "over");
}

int do_ask()
{
        object ob;
        ob=this_player();
        command("say 风云比武大会即将举行，你可愿意参加？(join)");
        ob->set("asking",1);
        return 1;
}

int do_join()
{    
        object ob;
        ob=this_player();
        if (ob->query("比武"))  return notify_fail("你已经报名参加比武大会了，还要参加啊？\n");
        if (!ob->query("asking")) return 0;
        ob->set("joining",1);
        ob->delete("asking");
        return notify_fail("公平子郑重的说道：请看过比武章程，真的决定参加？(decide)\n");
}

int do_decide()
{
        object ob;
        string arg;
        ob=this_player();
        if (!ob->query("joining")) return 0;
        ob->delete("joining");
        ob->set("比武",1);
        arg=ob->query("name");
        command("chat 现在"+arg+"报名参加比武大会。");
        return notify_fail("公平子微笑着说：你现在已经报名参加比武大会了，好好努力吧！\n");
}

int do_hold()
{
        object obj,*ob,*inv,me,room;
        int i,j;
        string wiz_status;
        me = this_player();
        wiz_status = SECURITY_D->get_status(me);
        if(!me->query_temp("marks/linxue_allow") && wiz_level(me)<wiz_level("(arch)"))
        {return notify_fail("你无权召开比武大会！\n");}
        room = load_object("/u/biwu/gate");
        ob=users();
        command("chat 比武大会现在开始！！！");
        for(i=0;i<sizeof(ob);i++) {
          if (ob[i]->query("比武")){
             tell_object(ob[i],sprintf(HIW"公平子告诉你:现在比武大会开始了，赶快去吧！\n"NOR));
             tell_object(ob[i],sprintf(HIW"于是你放下手头一切杂事，急急忙忙赶去。\n"NOR));  }
          if (!ob[i]->query("比武")){
             tell_object(ob[i],sprintf(HIW"公平子告诉你:现在比武大会开始了，虽然你没参加，但去看看吧！\n"NOR));
             tell_object(ob[i],sprintf(HIW"于是你放下手头一切杂事，急急忙忙赶去。\n"NOR));  }
             ob[i]->move(room);
             inv = all_inventory(ob[i]);
             for(j=0; j<sizeof(inv); j++)
                {   destruct(inv[j]);  }
          }
        return 1;
}

int do_over()
{
        object obj,*ob,*inv,me,room;
        int i,j;
        string wiz_status;
        me = this_player();
        wiz_status = SECURITY_D->get_status(me);
        if( wiz_status != "(admin)" && wiz_status != "(arch)" )
        {return notify_fail("你无权召开比武大会！\n");}
        room = load_object("/d/fy/fysquare");
        ob=users();
        command("chat 比武大会现在结束！！！");
        for(i=0;i<sizeof(ob);i++) {
             tell_object(ob[i],sprintf(HIW"公平子告诉你:现在比武大会结束了，路上走好。\n"NOR));
             tell_object(ob[i],sprintf(HIW"公平子告诉你:请退出后再登录以获得自造物品。\n"NOR));
             ob[i]->move(room);
             ob[i]->delete("比武");
             inv = all_inventory(ob[i]);
             for(j=0; j<sizeof(inv); j++)
                {   destruct(inv[j]);  }
          }
        return 1;
}

int do_show()
{
        object *ob,me;
        int i;
        string arg;
        me = this_player();
        ob=users();
        tell_object(me,sprintf(HIW"公平子告诉你:现在在线玩家参加比武大会的有：\n"NOR));
        for(i=0;i<sizeof(ob);i++) {
          if (ob[i]->query("比武"))
            {  arg=ob[i]->query("name");
               write(arg+"报名参加比武大会。\n");
            }
          }
        return 1;
}

