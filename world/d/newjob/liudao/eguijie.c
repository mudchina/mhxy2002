//By Repoo and Xuexu
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short", HIG"饿鬼界"NOR);
set("long", @LONG
  
    这里是六道之中的饿鬼界，也是六道中最苦难的轮回世界，到处弥漫着地狱中
的火焰。在火焰中充满着被火所折磨的饿鬼的惨叫，它们眼中充满着复仇和逃生的
强烈愿望。
  
LONG );
     set("exits/east", __DIR__"eguijie"+(string)random(8));
     set("exits/west", __DIR__"eguijie"+(string)random(8));
     set("exits/south", __DIR__"eguijie"+(string)random(8));
     set("exits/north", __DIR__"eguijie"+(string)random(8));
     set("objects", ([ /* sizeof() == 4 */
       __DIR__"npc/egui" : 1,
]));
setup();
}
void init() 
{
              int i;
        object* inv;
        object me = this_object();
             delete("exits/out");
     if(this_player()->query_temp("liudao/eguijie_kill") >= 64)
    {
message_vision(HIR"\n$N眼前一红，面前出现了一个偌大的出口，里面红光闪闪，似乎有着可怕的预感。\n\n"NOR,this_player());
           set("exits/out", __DIR__"shenpanshi");
     } 
   if (this_player()->query_temp("liudao/eguijie") == "begin")
    {
    remove_call_out ("check_hp");
     call_out ("check_hp", 1,this_player());
    }
        inv = all_inventory(this_player());
        for(i=0; i<sizeof(inv); i++) 
        {
                if( inv[i]->query_unique() ) {
message_vision(HIW"突然间，$n化一道白光飞去，无影无踪！\n"NOR,me,inv[i]);
                        destruct(inv[i]);
                                                                    }
        }
   add_action ("do_cast","cast");
}
int check_hp(object who)
     {
  object where = this_object();
  if ( (! who)  ||    (! present(who, where)) )  return 1;
   if (random(4)==1 && who->query("sen") > 50 )
    {
      who->add("sen",-(100+random(50)));
     message_vision(HIR"突然地面伸出一双腐烂的手，想把你活生生得撕成碎片。\n"NOR,who);
     COMBAT_D->report_sen_status(who);
    }
  if ( (100*(who->query("kee")))/(who->query("max_kee")) <= 10)
    {
     message_vision(HIR"你快被这双腐烂的手捏得喘不过气来了。\n"NOR,who);
     who->delete_temp("last_damage_from");
who->set_temp("death_msg", "在饿鬼界被饿鬼撕成了碎片。\n");
     who->die();
     who->save();
     return 1;
    }
  remove_call_out ("check_hp");
  call_out ("check_hp", 1,who);
  return 1;
    }
int do_cast (string arg)
{
  object who = this_player();
  if (who->query_temp("liudao/eguijie")=="begin" && 
             (arg=="escape" || arg=="shuidun" || arg=="tudun"))
     {
      tell_object(who,"这里不能逃生！\n");
      return 1;
     }
  else return 0;
}
