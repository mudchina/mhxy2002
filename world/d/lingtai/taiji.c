// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "[33mÌ«¼«Õó[m");
        set("long", @LONG
´ËÕóÄËÀÏ¾ýÅüµØ¿ªÌì£¬·ÖÇåÀí×Ç£¬¶¨µØË®»ð·ç£¬°üÂÞÍòÏóÖ®±¦-Ì«¼«Í¼Ëù»¯¶ø³É¡£
´ËÕó±ä»¯ÎÞÇî£¬µ½´¦ÃÖÂþ×Å½ðÉ«µÄÔÆ²Ê¡£
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"room",
]));

        setup();
}

/* void init()
{
    add_action("do_arrest","arrest");   
}

int do_arrest(string arg)
{
       string msg;
       int ap,dp,success;
       object me,target;
       
       me=this_player();       
       if(!arg||arg=="")return 1; 
       if(me->query_temp("taiji_arrest")){
           notify_fail("ÄãÒÑ¾­×¥ÁËÒ»¸öÈË£¡\n");
           return 1;
       }       
                
       msg = HIC
        "$N¿ÚÖÐÄîÁË¾äÖäÎÄ£¬³¯¿ÕÖÐÒ»Ö¸£º»Æ½íÁ¦Ê¿ºÎÔÚ£¡\n" 
        NOR;
        
        message_vision(msg, me);        
    if(!objectp(target = find_living(arg))|| !environment(target)){
            tell_room(environment(me),"°ë¿ÕÖÐÏÖ³öÒ»¶ä½ðÉ«ÔÆ²Ê£¬Ò»¸ö»Æ½íÁ¦Ê¿¹°ÊÖÐÐÀñ£ºÙ÷·¨Ö÷£¬ÕÒ²»µ½Õâ¸öÈË£¡\n");
            return 1;
        }
        msg = HIC
        "ËÙÈ¥½«$n×¥À´£¡\n°ë¿ÕÖÐÏÖ³öÒ»¶ä½ðÉ«ÔÆ²Ê£¬Ò»¸ö»ëÉí½ð¼×µÄ»Æ½íÁ¦Ê¿ÏÖ³öÉíÐÎ£ºÊÇ£¡È»ºó¾Í·ç³Ûµç³¸°ãµØÈ¥ÁË¡£\n"
        NOR;

        message_vision(msg,me,target);
      
        me->add("mana", -600);
        me->receive_damage("sen", 30);

        success = 1;
        ap = me->query_skill("spells");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) < dp ) success = 0;
        //here we compared exp and spells level. 
        //note: has nothing to do with target's spells level.
      if(success == 1 ){
          tell_room(environment(target),"¿ÕÖÐÉì³öÒ»Ö»´óÊÖ½«"+target->query("name")+"×¥×ßÁË¡£\n");       
          target->move(environment(me));
          msg =  HIR "²»Ò»»á¶ù£¬½ðÉ«ÔÆ²Ê¶¸ÏÖ£¬»Æ½íÁ¦Ê¿½«$nÍùµØÉÏÒ»ÈÓ£¬°Ñ$nË¤ÁË¸öÍ·ÔÎÄÔÕÍ\n" NOR;
          message_vision(msg,me,target);
          me->kill_ob(target);
          target->kill_ob(me);
          target->start_busy(1);
          
          call_out("blowing",1,me,target);
      }       
      else {
         msg =  HIR "²»Ò»»á¶ù£¬°ë¿Õ´«À´»Æ½íÁ¦Ê¿´ó½Ð£ºÇë·¨Ö÷Êê×ï£¬ÎÒÎÞ·¨×¥»ñ$n£¡\n" NOR;   
         message_vision(msg,me,target);         
         me->start_busy(1);
      } 
      return 1;
}

void blowing(object me,object target)
{
  int ap,dp,damage;
  string msg;
        
  if(!me||!target||environment(me)!=this_object()||environment(target)!=this_object()){
        remove_call_out("blowing");
        return;
  }
    
  if(random(2)){
    msg = HIC
         "\n°ë¿ÕÖÐ½ðÔÆ·­ÌÚ£¬×ß³öÒ»Î»¼âÍ·Ó¥±ÇµÄÀ×¹«£¬×óÊÖÖ´¸«£¬ÓÒÊÖÌá×¶¡£
         ¸«×¶Ïà»÷£¬ÔÚ$nµÄÍ·¶¥Õ¨ÆðÒ»Æ¬ÏìÀ×£¡\n"NOR;

    ap = me->query_skill("spells");
    ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
    ap += (int)me->query("combat_exp");
    dp = target->query("combat_exp");
    if( random(ap + dp) > dp ) {
       damage = (int)me->query("max_mana") / 10 +
           random((int)me->query("eff_sen") / 5);
       damage -= (int)target->query("max_mana") / 10 +
           random((int)target->query("eff_sen") / 5);                   
       damage+=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
//here we can see if 2 players are at same status, the attacker has higher chance.
       if( damage > 0 ) {
           msg +=  HIR "\n$n±»À×ÉùÕðµÄÑÛÃ°½ðÐÇ£¬ÐÄÉñ²»¶¨£¬²îµãµøµ¹ÔÚµØ£¡\n" NOR;
          //finally damage also depends on enabled spells level.
           damage +=random((damage*(int)me->query_skill("spells"))/100);
                        target->receive_damage("sen", damage/5, me);
                        target->receive_wound("sen", damage/10, me);
         }else msg += "\nË­Öª$nºÁÎÞ·´Ó¦£¬ÒÀ¾ÉÒ»ÐÄÒ»ÒâµØºÍ$NÕ½¶·¡£\n";
    }else msg += "\nË­Öª$nºÁÎÞ·´Ó¦£¬ÒÀ¾ÉÒ»ÐÄÒ»ÒâµØºÍ$NÕ½¶·¡£\n";     
    message_vision(msg, me, target);
  }else {
     msg = HIC
     "\n°ë¿ÕÖÐ½ðÔÆ·­ÌÚ£¬×ß³öÒ»Î»ÈÝÃ²ÐãÑÅµÄµçÄ¸£¬Ë«ÊÖ¸÷³ÖÒ»Ã¶Í­¾µ¡£
     Í­¾µÏà×ª£¬ºöµÄÉÁ³öÒ»µÀ½ð¹âÉäÏò$n£¡\n" NOR;

     ap = me->query_skill("spells");
     ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
     ap += (int)me->query("combat_exp");
     dp = target->query("combat_exp");
     if( random(ap + dp) > dp ) {
         damage = (int)me->query("max_mana") / 10 +
            random((int)me->query("eff_sen") / 5);
         damage -= (int)target->query("max_mana") / 10 +
            random((int)target->query("eff_sen") / 5);                   
         damage+=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
         //here we can see if 2 players are at same status, the attacker has higher chance.
         if( damage > 0 ) {
            msg +=  HIR "\n½á¹û¡¸àÍ¡¹µØÒ»Éù£¬½ð¹â´Ó$nÉíÉÏÍ¸Ìå¶ø¹ý£¬\nÍÏ³öÒ»Ìõ³¤³¤µÄÑª¼ý£¬Ö±Éäµ½Á½ÈýÕÉÍâµÄµØÏÂ£¡\n" NOR;
            //finally damage also depends on enabled spells level.
            damage +=random((damage*(int)me->query_skill("spells"))/100);
            target->receive_damage("kee", damage/5, me);
            target->receive_wound("kee", damage/10, me);
          }else msg += "\nµ«ÊÇ±»$n¶ã¿ªÁË¡£\n";
      }
      else msg += "\nµ«ÊÇ±»$n¶ã¿ªÁË¡£\n";
      message_vision(msg, me, target);
  }
  call_out("blowing",5,me,target);      
}

void reset()
{
        ::reset();
        remove_call_out("blowing");
}

int valid_leave(object me, string dir)
{
        remove_call_out("blowing");
        return 1;
}
}  */
