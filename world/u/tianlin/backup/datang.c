// by fly 2000.12.6

#include <ansi.h>
#include <room.h>
string look_sign();
inherit ROOM;

void create()
{
    set ("short", "»§²¿´óÌÃ");
  set ("long", @LONG

´óÌÃÖ®ÉÏÓĞÒ»ÖÖÍşÑÏÖ®ÊÆ£¬²»ÓÉÈÃÈËĞÄ¾ªµ¨²ü¡£Ç°·½Ò»ÕÅ´ó×À£¬ºóÃæ
×ø×ÅÖª¸®´óÈË¡£ÉÏÓĞÒ»·ù´óØÒ£¬Ğ´×Å£¢ÇåÕıÁ®Ãû£¢ËÄ¸öÌÌ½ğ´ó×Ö¡£
           [1;35m¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù
           [1;35m¡ù¡ù¡ù¡ù¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ù¡ù¡ù¡ù
          [1;35m ¡ù¡ù¡ù¡ù    [1;37mÇå    Õı    Á®    Ãû    [1;35m¡ù¡ù¡ù¡ù
          [1;35m ¡ù¡ù¡ù¡ù¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ù¡ù¡ù¡ù
           [1;35m¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù[2;37;0m

×ÀÅÔÁ¢×ÅÒ»Î»ÀÏÏÈÉú¡£°ø±ßÈ´ËÆºõ¹ÒÁË¸öÄ¾ÖÆµÄÅÆ×Ó(Sign)¡£
LONG);
        set("item_desc", ([
                "sign" : (: look_sign :),
          ]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/huanggong/chaoyangmen",
]));
set("objects", ([
            "/d/city/npc/yayi1":1+random(2),
              "/d/city/obj/npc/change_couple":1,
              "/d/city/obj/npc/zhifu":1,
]));
        set("no_fight", 1);
        set("no_magic", 1);
  set("light_up", 1);
  setup();
}
string look_sign()
{
       return
       "\n\n"
       "    ¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù\n"
       "    ¡ù"+HIG"¸ÄÃû»»ĞÕ(ask wei about ¸ÄÃû»»ĞÕ)"NOR+" ¡ù\n"       
       "    ¡ù"+HIG"ĞŞ¸Ä»éÒö(ask guan jia about »éÒö)"NOR+"¡ù\n"       
       "    ¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù¡ù\n\n";
}
void init()
{ 
          object me = this_player();
          call_out("wait", 2, me);         
}

void wait(object me)
{
        tell_room(environment(me),"\n "+me->name()+"´Ò´ÒÃ¦Ã¦´ÓÍâÃæ×ßÁË¹ıÀ´¡£\n");
          write(" "+me->name()+"ËÄÏÂÉ¨ÊÓÁËÒ»ÏÂ£¬ËÆºõÃ»Ò²·¢ÏÖÊ²Ã´ÌØÊâµÄµØ·½¡£\n",me);
          call_out("wait2", 5, me);         
                return;
}
void wait2(object me)
{
          write(WHT" Í»È»Äã·¢ÏÖÕâÎ»ÀÏÏÈÉú°ø±ßËÆºõ¹ÒÁË¸öÄ¾ÖÆµÄÅÆ×Ó(sign)¡£\n"NOR);
                return;
}
