// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// worker.c

inherit NPC;

void create()
{
        set_name("晨月", ({"chen yue"}));
        set("gender", "男性" );
        set("age", 13);
   set("title", "山门迎客");
        set("long", "一个小道士，每天负责在山门迎接远道而来的客人．\n");
        set("combat_exp", 200);
        set("attitude", "friendly");
        set_skill("dodge", 10);
        set("per", 30);
        set("max_kee", 150);
        set("max_gin", 150);
        set("max_sen", 150);
        setup();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting()
   && !this_player()->query("env/invisibility") ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
       add_action("do_volunteer","volunteer");
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "晨月说道：这位" + RANK_D->query_respect(ob) +
"，欢迎到我们斜月三星洞来！\n");
}

int do_volunteer()
{
        object me=this_player();
        object* ob;
        int i;

       if((string)me->query("family/family_name")!="方寸山三星洞")
        {
           command("smile");
           return notify_fail("晨月对你说道：您不是本门中人。\n");
        }
    if(me->query("lingtai_quest/quest_type")!="看守山门")
      return notify_fail("不敢劳您的大驾！\n");
        if (me->query_temp("in_guard")) 
           return notify_fail("晨月对你说：你专心守好山门，别想打两份工。\n");
    ob=all_inventory(environment(me));
        for (i=sizeof(ob); i>0; i--)
        {
                if (ob[i-1]->query_temp("in_guard"))
                return notify_fail("晨月对你说：已经有人守山门了，你一会再来吧。\n");
        }
        command("say 那好，就请你守一会儿山门吧。");
        tell_room(environment(me),me->query("name")+"开始在方寸山山门值守。\n");
        me->set_temp("in_guard","1"); 
        me->save();
        remove_call_out("end_guard");
      call_out("end_guard",70,me);
        call_out("clone_meng",20,me);
        return 1;
}
void clone_meng(object me)
{
        object ob;
        tell_room(environment(me),"山下突然冲上来一伙蒙面大汉。\n");
        ob=new("/d/lingtai/npc/mengmian.c");
        ob->set("combat_exp",me->query("combat_exp"));
        ob->move("/d/lingtai/gate");
        call_out("clone_meng", 20, me);
}
void end_guard(object me)
{
        int reward=me->query("combat_exp")/5000;
      object yao;
        
    tell_object(me,"晨风对你表示衷心的感谢！\n");
    me->set("lingtai_quest/done",1);
    me->delete("in_guard");
        remove_call_out("clone_meng");
        tell_room(environment(me),me->query("name")+"在方寸山山门值守期已满。\n");
        command("say 你在方寸山山门值守期已满，多谢了。");
      while(yao=present("dahan",environment(me)))
      {  tell_object(me,"只见蒙面大汉呼啸而去，很快消失在远方。\n");
          destruct(yao);
      }
}
void die()
{
        object *me;
        int i;

        me = users();
        for (i = 0; i < sizeof(me); i ++)
            me[i]->delete_temp("in_guard"); 

        ::die();
}

