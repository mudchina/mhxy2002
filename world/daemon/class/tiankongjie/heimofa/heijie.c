//cast heijiejie
//暗黑结界

#include <ansi.h>

inherit SSERVER;

#define WIND_FILE "/d/jjf/obj/wind_seal.c"

void get_out(object where);

int cast(object me, object target)
{
        string msg;
        int success, ap, dp;
        object sleeveroom,sleeve;
        string sname;
        object env, *inv;
        int size, i, heimofa_level;
        int maxenc;

        seteuid(getuid());

        
//      if( !target ) target = offensive_target(me);

        if(!target) 
        {
          //see if I am fighting someone...this is useful for NPC...
          if(  (offensive_target(me)) ) target = offensive_target(me);
          else
         {
          // then take stuff out.
          sleeveroom=load_object("/d/wiz/sleeveroom");
          if(!sleeveroom) return notify_fail("你的袖子恐怕破了。\n");

          sname=me->query("id")+"'s sleeve";
          if(!sleeve=present(sname,sleeveroom)) {
             message_vision(
             "$N念动真言释放结界里的一切东西！！\n",me);
             return 1;
          }

          size=sizeof(inv=all_inventory(sleeve));
          if(!size) {
             message_vision(
             "$N念动真言释放结界里的一切东西！！\n",me);
             return 1;
          }

          msg="$N念动真言释放结界里的东西，";
          for(i=0;i<size;i++) {
            if(inv[i]->is_character())
              msg+="$n咻的一声从结界的开口处窜了出来。\n";
            else
              msg+="$n迷迷糊糊的从结界的出口走了出来。\n";

            env=environment(me);
            while(!(inv[i]->move(env))) env=environment(env);

            message_vision(msg,me,inv[i]);
           msg="";
          }
          return 1;
        }
       }

        if( !target
        || !target->is_character()
        || target->is_corpse()
        || target==me)
                return notify_fail("你要对谁施展按黑结界？\n");

        if( (int)me->query("mana") < 400 )
                return notify_fail("你的法力不够了！\n");
        if((string)me->query("family/family_name")!="天空界")
                return notify_fail("你不是天空界的人，没有那么强大的暗黑结界。\n");

        if( (int)me->query("sen") < (int)me->query("max_sen")/2 )
                return notify_fail("你现在头脑不清醒，哪里能布置暗黑结界！\n");

        if( random(me->query("max_mana")) < 50 ) {
                write("你失败了！\n");
                return 1;
        }

        msg =  WHT "$N喃喃念动暗黑咒语：“噫嘛啦萨……”，$n四周的景色突然全变！！
黑蒙蒙的一偏四周漫无边际！已然是另一空间！！！\n" NOR;
        message_vision(msg, me, target);
        
        target->kill_ob(me);

        success = 1;
        ap = me->query_skill("spells");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("daoxing");
        ap = 3*ap; 
        dp = target->query("daoxing");
        if( random(ap + dp) < dp ) success = 0;
//here we compared exp and spells level. 
//note: has nothing to do with target's spells level.

        ap = (int)me->query("max_mana");
        dp = (int)target->query("max_mana");
        if( ap < random(dp) ) success = 0;
//here we compared max_mana.
//if the attacher has half of the max_mana of the target, 
//he has 50% chance to success.

        if(success == 1 )
        {
                me->add("mana", -400);
        
                sleeveroom=load_object("/d/wiz/sleeveroom");
                if(!sleeveroom) return notify_fail("你的结界里似乎有异物，你不得不收回了真言！\n");

                sname=me->query("id")+"'s sleeve";
                if(!sleeve=present(sname,sleeveroom)) {
                  sleeve=new("/d/obj/fabao/sleeve");
                  if(!sleeve) return notify_fail("你的结界里似乎有异物，你不得不收回了真言！\n");

                heimofa_level = (int)me->query_skill("heimofa", 1);
                maxenc=heimofa_level*2000;
                if(maxenc>400000) maxenc=400000;
                sleeve->set_max_encumbrance(maxenc);
                // mon 4/15/98
/*
                if( taiyi_level < 50 ) sleeve->set_max_encumbrance(100000);
                else if( taiyi_level < 100 ) sleeve->set_max_encumbrance(200000);
                else if( taiyi_level < 150 ) sleeve->set_max_encumbrance(300000);
                else sleeve->set_max_encumbrance(400000);
*/
                  //400000 correspondes to about 4 people?
                //note...if we want a npc can not be moved...can set its str very high...:)

                  sleeve->set_name(
                    me->query("name")+"的暗黑结界中",({sname,"sleeve"}));
                  sleeve->set("short",
                    me->query("name")+"的暗黑结界中");
                  if(!sleeve->move(sleeveroom)) 
                    return notify_fail("你的结界里似乎有异物！\n");
                }

                if(target->move(sleeve)) {
                  msg =  MAG "$n惊慌失措愣在当场，$N一见大喜，回身打开一个小的结界缺口，
转身跳出自己的结界，只将$n关在里面！！！\n" NOR;
                  message_vision(msg, me, target);
                  
                  // mon 7/31/98
                  if(!userp(me)) {
                      call_out("get_out", 120+random(240), sleeve);
                  } else
                      call_out("get_out", 240+random(480), sleeve);


                } else {
                  msg=HIR"$n大惊失色不管三七二十一展开身型紧随着你，\n" NOR;
                  msg+="$N无奈一挥手散开了自己的结界。\n";
                  message_vision(msg, me, target);
                }
                
        }
        else 
        {
                msg =  HIR "$n似乎已经识得$N的伎俩，不动声色，待$N回身打开缺口时$n抢先一步冲出结界，毫发无损。\n" NOR;
                message_vision(msg, me, target);

                me->add("mana", -400);
        } 

        return 3+random(5);
}

void get_out(object where)
{
   object wind, *inv;
   int i;

   if(!where) return;

   i=sizeof(inv=all_inventory(where));
   while(i--) {
      if(inv[i]->is_character()) { // NPC or players 
         wind=new(WIND_FILE); // wind can only be used once, so need to new.
         wind->do_blow(inv[i]);
         message_vision("$N慌慌张张看到一线空隙，急忙挤了出去！！\n",
           inv[i]);
//         inv[i]->unconcious();
         destruct(wind);
      } else  // objects.
          destruct(inv[i]); 
   }

   return;
}


