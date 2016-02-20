//侠客行100海洋版II
// xiaoer.c 平安城店小二
//星星lywin 2000/6/1 儿童节

#include <ansi.h>
#include <command.h>
inherit NPC;

void consider();
int do_gongzuo();
int ask_done();
void create()
{
        set_name("店小二", ({"xiao er", "xiao"}));
        set("gender", "男性");
        set("age", 25);
        set("long", 
                "他是春醇茶栈的店小二。\n");
        set("kee", 100);
        set("max_kee", 100);
        set("sen", 100);
        set("max_sen", 100);
        set("per", 25);
        
        set("combat_exp", 1500);
        set("score", 200);
        
        set("inquiry", ([
                "工作" : (: do_gongzuo :),
                "job"  : (: do_gongzuo :),
                "work" : (: do_gongzuo :),
        ]) );

        setup();
        carry_object("/d/obj/cloth/pink_cloth")->wear();
}
int do_gongzuo()
{      
        object me;
        me = this_player(); 
        
         if (me->query("daoxing")>=10000000)
    {
                tell_object(me,"大仙我可不敢请,haha..kick\n");
               
                return 1;
    } 
    
    if (me->query("PKS")>=1)
    {
                tell_object(me,"杀人犯我可不敢请,haha..kick\n");
               
                return 1;
    } 
    
         if (me->query("combat_exp")>=100000)
    {
                tell_object(me,"这点小事怎么敢劳您的大驾。\n");
                return 1;
    }
    
    if (me->query("combat_exp")<=50000)
    {
                tell_object(me,"打鸟这点小事情都不愿意做，我可不想请你\n");
                return 1;
    } 

    if (me->query("betrayer") || me->query("betray/count"))
        {
                tell_object(me,"本店可不想请曾叛过师的人。\n");
                return 1;
        } 
    if( me->query_temp("gongzuo/xipanzi")>0)
    {
                tell_object(me,"快去洗盘子吧。\n");
                return 1;
    }  
    message_vision(CYN"小二对$N说道：这几天客人多！盘子洗不过来，你去厅堂找管事要点盘子来洗吧。\n"NOR,me); 
        me->set_temp("gongzuo/xipanzi", 1);
        return 1;   
}
int accept_object(object me, object ob)
{
        object ob1;
        if (me->query_temp("gongzuo/xipanzi")<1)
        {
         command("say 你没有找我要过工作吧。\n");
        }
        else if ( ob->query("name") != "盘子" )
//        else if (strsrch(ob->query("name"), "盘子") < 0) 
        {
            command("say 这是洗好的盘子？你不是开玩笑吧！\n");
        }
        else
        {
    message_vision(CYN"小二对$N说道：辛苦了，这是你的工钱。\n"NOR,me);
    message_vision(CYN"小二递给$N一些银子。\n"NOR,me);  
                me->delete_temp("gongzuo/xipanzi");
                me->delete_temp("gongzuo/gepanzi");
                if (me->query("combat_exp")>=200000)
                {
                  me->add("combat_exp",50);
                 me->add("potential",8);
                 me->add("daoxing",8);
                 ob1=new("/obj/money/silver");
                  ob1->move(me); 
                  call_out("destroying", 1, this_object(), ob);
                }
                else if (me->query("combat_exp")< 300000)
                {
                me->add("combat_exp",50+random(10));
               me->add("potential",6+random(10));
               me->add("daoxing",8+random(10));
             ob1=new("/obj/money/silver");
                ob1->move(me); 
                call_out("destroying", 1, this_object(), ob);
                }
            return 1;
        }
    return 0;
}

void destroying(object me, object obj)
{
//        destruct(obj);
        return;
}

