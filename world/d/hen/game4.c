// by happ@YSZZ
inherit ROOM;
#include <ansi.h>
#define RESULT "/log/hen_game4"

void create ()
{
  set ("short", "美术比赛赛场");
  set ("long", @LONG

             小鸡们的美术比赛就在这举行,如果你要查询上次比赛结果,请输入last.


LONG);

  set("exits", ([ /* sizeof() == 4 */
        "down": __DIR__"baoming",
]));

  set("no_clean_up",1);
  set("no_fight", 1);
  set("no_magic", 1);
        setup();
}

void init()
{
           add_action("do_last","last");
}
int do_last()
{

   if( file_size("/log/hen_game4") <=0 )

                return notify_fail("暂时没有比赛结果.\n");

  if( this_player()->query_temp("hen/game_4") )
                return notify_fail("你现在正在比赛中。\n");
      cat(RESULT);
  return 1;
}

void begin()
{
        object me = this_object();
        object *list=all_inventory(me);
        object *gamer=({});
        object temp;
        string name,id;
        int i,x,n;
        object gold = new("/obj/money/gold");


        for(i=0;i<sizeof(list);i++)
        {
        if( present("zhandou ji",list[i]) && list[i]->query_temp("hen/game_4") )
        gamer+=({list[i]});
        }

        if( gamer==({}) )
        return ;

        for(n=0;n<sizeof(gamer);n++)
        {

                for(x=1;x<sizeof(gamer);x++)
                {
               if( gamer[x-1]->query("hen/art") > gamer[x]->query("hen/art") )
                        {
                        temp = gamer[x-1];
                   gamer[x-1] = gamer[x];
                   gamer[x] = temp;
                        }

                }    

        }
         for( i=0;i<sizeof(gamer);i++ )
         {
                     log_file("hen_game4",sprintf("%-12s[%-10s]在小鸡美术比赛中获得了第"+HIR
           +chinese_number(i+1)+NOR+"名。\n", gamer[sizeof(gamer)-i-1]->query("name"),
           gamer[sizeof(gamer)-i-1]->query("id")));
        if( i+1 > 10 ) continue;

        gold->set_amount((int)100/(i+1));
        gold->move(gamer[sizeof(gamer)-i-1]);
        gamer[sizeof(gamer)-i-1]->add("hen/money",(int)5000/(i+1));
        gamer[sizeof(gamer)-i-1]->start_busy(17);
         }
       tell_room(me,"比赛进行中......各位选手都在认真比赛中，期望得到最好的成绩！\n");
         me->start_busy(23);            
        remove_call_out("end1");
          call_out("end1",10);

}
        

void end1()
{
           object me = this_object();

             tell_room(me,"比赛快要结束了，马上就要公布结果了,每个人都有奖哦\n");

        remove_call_out("end");
        call_out("end",10);
}
void end()
{
        
        object me = this_player();
        cat(RESULT);
        me->delete_temp("hen_game");
       me->delete_temp("hen/game_4");
}
