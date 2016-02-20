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
                "公平子的来历师承谁也不知道，但他人不但性情豪爽，且\n铁面无私，凡是由他裁定的事都绝对公平。\n"

                );
       set("chat_chance", 2);
        set("chat_msg", ({
                "公平子说道：各位远道而来，辛苦了！\n",
                "公平子说道：谁会荣膺天下第一呢．．．．\n",
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
       add_action("do_gogo", "enter");
       add_action("do_allow","allow");
}

int do_gogo()
{
        object me;
        string wiz_status;
        me = this_player();
        wiz_status = SECURITY_D->get_status(me);
          if(! me->query_temp("marks/allow_biwu")&&( wiz_status != "(admin)" && wiz_status != "(arch)" ))
        {
          write(HIC"公平子说道：现在还没到你呢? 别急。\n"NOR);
          write(HIC"你没法进去,请少安毋躁，再等等吧!! \n"NOR);

          return 1;
        }
        else
{
         return 0;
}
}

int do_allow(string arg)
{ string wiz_status;
  object me;
  object obj;

  me = this_player();
  wiz_status = SECURITY_D->get_status(me);
    if( wiz_status != "(admin)" && wiz_status != "(arch)" )        
     { return 0;}  
        if(!arg || arg=="")
        {
                write("你要让谁进去？\n");
                return 1;
        }

        obj=find_player(arg);
        if (!objectp(obj)) return notify_fail("这个人目前不在线上。\n");
    if(!obj->query("比武")) return notify_fail("此人并未报名参赛\n");
        arg=obj->query("name");
        obj->set_temp("marks/allow_biwu",1);
       command("say 现在轮到"+arg+"进入比武了，快进去(enter)吧。");
      return 1;
 }

void die()
{
}
