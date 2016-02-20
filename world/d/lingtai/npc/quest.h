#include "ansi.h"
void get_reward(object who)
{
   int exp,pot;    
   pot=40+random(20);
   exp=90+random(30);   
   tell_object(who,"皤不分说道：恭喜你！你又完成了一项任务！\n");
   who->add("combat_exp",exp);
   who->add("potential",pot);
   who->add("faith",1);
   tell_object(who,HIW"你被奖励了：\n" +
   chinese_number(exp) + "点实战经验；"+chinese_number(pot) + "点潜能\n" NOR);
    who->delete("lingtai_quest");
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me,HIC + sprintf("%s",this_object()->name()) +"说道：请在" + time + "内\n");
        return 1;
}

int give_quest()
{
  object me=this_player(),obj;
  int exp=me->query("combat_exp");
  mapping quest;
  int timep;
  
  if( me->query("combat_exp") > 100000)
 return notify_fail("你还是找点别的活干吧。\n");

  if(me->query("family/family_name")!="方寸山三星洞")
     return notify_fail("你我素无来往，不知有何贵干？\n");
  if(me->query("faith")>100)return notify_fail("不敢有劳您了!\n");
  if(exp>1000000){
        tell_object(me,"皤不分说道：你的经验已经足够高，该去闯一番天下了！\n"); 
        return 1;
  } 

  if((int) me->query("task_time") - time()>0)
     if(!me->query("lingtai_quest")){
    }
    else {
        tell_object(me,"皤不分说道：你不是还有任务么？\n");
        return 1;
    }
    else if(me->query("lingtai_quest")){
    tell_object(me,"皤不分说道：我白信任你了！再给你一次机会。\n");
    me->set("kee", me->query("kee")/2+1);
      me->delete_temp("lingtai_quest_number");
  }  
  
  quest="/d/lingtai/npc/quest_new"->query_quest();

   if((int)me->query_temp("lingtai_quest_number")<40)
      me->add_temp("lingtai_quest_number",1);
      
  timep=400+random(200);
  time_period(timep, me);      
  me->set("task_time", (int) time()+(int) timep);
  
  if(quest["quest_type"]=="sweep"){
      me->set("lingtai_quest/quest_type","打扫");
      me->set("lingtai_quest/quest",quest["location"]);
    if(!(obj=present("broom",me))){
        obj=new("/d/lingtai/obj/shaoba.c");
        obj->move(me);
    }
    tell_object(me,"皤不分说道：替我打扫"+quest["location"]+"，这是扫帚。\n");
    return 1;
  }
  if(quest["quest_type"]=="dig"){
      me->set("lingtai_quest/quest_type","种地");
      me->set("lingtai_quest/quest","");
    if(!(obj=present("hoe",me))){
        obj=new("/d/lingtai/obj/chutou.c");
        obj->move(me);
    }
    tell_object(me,"皤不分说道：去帮种地小道种地，这是锄头。\n");
    return 1;
  }
  if(quest["quest_type"]=="carry"){
      me->set("lingtai_quest/quest_type","挑水");
    tell_object(me,"皤不分说道：替晚风挑水。\n");
    return 1;
  }
  if(quest["quest_type"]=="volunteer"){
     me->set("lingtai_quest/quest_type","看守山门");
    tell_object(me,"皤不分说道：替晨月看守山门。\n");
    return 1;
  }
  if(quest["quest_type"]=="write"){
     me->set("lingtai_quest/quest_type","抄经");
    tell_object(me,"皤不分说道：广羲子正需要人帮忙抄经，你这就去吧。\n");
    return 1;
  }
}

int report_msg()
{
  object me=this_player();

  if(me->query("class")!="taoist"){
      command("shake");
      return 1;
    }
   if(!me->query("lingtai_quest"))
    return notify_fail(this_object()->query("name")+"说道：你在寻我开心吗！\n");
   if(!me->query("lingtai_quest/done"))
    return notify_fail(this_object()->query("name")+"说道：你在寻我开心吗！\n");
  if ((int) me->query("task_time") < time() )
  {
      tell_object(me,"皤不分说道：真可惜！你没有在指定的时间内完成！\n");
      me->delete_temp("lingtai_quest_number");
      me->delete("lingtai_quest");
      return 1;
  }
  get_reward(me);
  return 1;
}
