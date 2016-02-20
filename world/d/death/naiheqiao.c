// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
#include <ansi.h> 
inherit ROOM;
int do_jump(string arg);
int do_volunteer();
void create ()
{
  set ("short", "[0;31mÄÎºÎÇÅ[m");
  set ("long", @LONG

ÕâÊÇÒ»×ù½öÊı´çÖ®¿í£¬Êı³¤Ö®³¤µÄÊ¯ÇÅ¡£ÉÏÓĞº®·ç¹ö¹ö£¬ÏÂÊÇ
ÑªÀËÌÏÌÏ¡£ÇÅÉÏ×óÓÒÎŞ·öÊÖ£¬ÏÕ¾şÖ®Â·ÈçÍ¬Æ¥Á·´î³¤½­£¬ÇÅÏÂ
Ö®Ë®ÒõÆø±ÆÈË£¬ĞÈ·çÆË±Ç¡£
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bidouya",
  "north" : __DIR__"huangwai",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shizhe" : 2,
]));
  set("no_spells",1);
  setup();
}

void init()
{
        add_action("do_jump", "jump");
        add_action("do_volunteer", "volunteer");
}
int do_jump(string arg)
{       
        object me;
        me=this_player();

        if ( !arg || ((arg != "bridge") ))
                return notify_fail("ÄãÒªÍùÄÄÌø£¿ÍùÇÅÏÂÌø×¼ËÀ£®£®£®\n");
        else

message_vision("$N²»¹ËÒ»ÇĞµÄÍùÇÅÏÂÌøÈ¥£®£®£®\n",me);
    		me->move("/d/death/room10");
            //  me->die();
                return 1;
}

int do_volunteer()
{
object me=this_player();
        object* ob;
        int i;
       if((string)me->query("family/family_name")!="ÑÖÂŞµØ¸®")
           return notify_fail("Äú²»ÊÇ±¾ÃÅÖĞÈË¡£\n");
       if(me->query("faith")>500)
        return notify_fail("ÄúÊÇ±¾ÃÅ´óÓĞÃûÍûÖ®ÈË£¬Ôõ¸ÒÓĞÀÍÄú×ö¿´ÇÅÕâÑùµÄÔÓÎñÄØ£¿\n");
       if (me->query_temp("in_guard"))
           return notify_fail("ÇÅÁºÊ¹Õß¶ÔÄãËµ:Äã×¨ĞÄÊØºÃÇÅÍ·£¬±ğÏë´òÁ½·İ¹¤¡£\n");
      if(time()-me->query("last_guard")<300)
         return notify_fail("ÇÅÁºÊ¹Õß¶ÔÄãËµ£ºÄãÔõÃ´ÕâÃ´¿ìÓÖÒªµ±°àÁË£¿ĞªĞª°É!\n");
        ob = users();
        for (i=sizeof(ob); i>0; i--)
        {
                if (ob[i-1]->query_temp("in_guard"))
                return notify_fail("ÇÅÁºÊ¹Õß¶ÔÄãËµ£ºÒÑ¾­ÓĞÈËÊØÄÎºÎÇÅÁË£¬ÄãÒ»»áÔÙÀ´°É£¡\n");
        }
        tell_object(me,"ÄÇºÃ£¬¾ÍÇëÄãÊØÒ»»á¶ùÄÎºÎÇÅ°É¡£\n");
        tell_room(environment(me),me->query("name")+"¿ªÊ¼ÔÚÄÎºÎÇÅÖµÊØ¡£\n");
        me->set("last_guard",time());
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
        tell_room(environment(me),"Í»È»³åÉÏÀ´Ò»»ï¹í£¬¿´À´ËûÃÇÏë»ØÑô¼ä¡£\n");
        ob=new("/d/lingtai/npc/mengmian");
        ob->set("combat_exp",me->query("combat_exp"));
        ob->move("/d/death/naiheqiao");
        call_out("clone_meng", 20, me);
}
void end_guard(object me)
{
        object ob;
        int reward=me->query("combat_exp")/5000;
        me->delete("guard");
        me->add("faith",2+random(4));
        me->add("combat_exp",100+random(reward));
        me->add("potential",30+random(reward/4));
        me->delete_temp("in_guard");
        me->save();
        remove_call_out("clone_meng");
        tell_room(environment(me),me->query("name")+"ÔÚÉ½ÃÅÖµÊØÆÚÒÑÂú¡£\n");

        tell_object(me,"ÄãÔÚÉ½ÃÅÖµÊØÆÚÒÑÂú¡£\n");
        while(ob = present("dahan",environment(me)))
                    destruct(ob);
}
