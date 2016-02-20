//By tianlin@mhxy for 2002.2.25

#include <ansi.h>
inherit ROOM;
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create()
{
        set("short", "瀑布");
        set("long", @LONG
你猛听得水声响亮，轰轰隆隆，便如潮水大至一般，抬头一看，只见一
条大瀑布，犹如银河倒悬，从高崖上直泻下来。下面是万丈深渊，云雾弥漫，
望不到尽头。。。。
LONG );
        set("exits", ([ /* sizeof() == 2 */
                "south" :  __DIR__"tao_out",
        ]));
                    set("objects",([
                __DIR__"npc/qingxia" : 1,
        ]));
        set("outdoors", "xiaoyao" );
        set("no_clean_up", 0);
        setup();
}
 
void init()
{
    object where=this_object();
    remove_call_out("check_time");
    check_time(where);
add_action("do_jump","jump");
    add_action("do_hear","hear");
}

int do_jump(string arg)
{
        object ob;
        int new_sen;
        ob = this_player();
        new_sen = random( ob->query("max_sen")*3 );
        if ( new_sen > ob->query("sen") ) new_sen = ob->query("sen") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "down" )
                return notify_fail("你想要跳崖自杀？这么想不开啊？\n");
        tell_object(ob, HIR"你不加思索，纵身一跃，跳下了悬崖。。。。\n"NOR);
        message("vision", NOR"只见" + ob->query("name") + "万念俱灰，纵身跳入了悬崖之中。。。。\n"NOR, environment(ob), ob);
        if((ob->query_skill("dodge",1)<30)){ ob->unconcious();
        ob->receive_damage("sen",new_sen);
        ob->move(__DIR__"yanfeng");
                }else{
           ob->move(__DIR__"yanfeng");
        }
        return 1;
}
void check_time(object where)
{
   mixed *local = localtime((time()-900000000)*60);
   int t = local[2] * 60 + local[1];

   int phase=((int)(t/120));
   if(phase==5&&(!query("maren"))) jiang_jing(where);
   if(phase==6&&query("maren")) finish_jing(where);
call_out("check_time",60,where);
}
void jiang_jing(object where)
{
message("channel:chat",CYN+"◇"MAG"花果山盘丝洞"CYN"◇"NOR+HIM"青霞仙子[Qingxia xianzi]："NOR+HIY"大喝一声: "NOR+CYN"花果山盘丝洞弟子弟子何在。"HIR"(Hear)\n"+NOR,users());
tell_object(where,"你听到青霞仙子说道: 我那姐姐......这样....那样.....。\n");
tell_object(where,"你听到青霞仙子说道：那个贱人....天天冒充我....这样.....那样...。\n");
tell_object(where,"........................................\n");
   set("maren",1);
}
void finish_jing(object where)
{
   tell_object(where,"你看到青霞仙子的气慢慢消了。\n");
   set("maren",0);
}
int do_hear()
{
 object yao;
   object me=this_player();

   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
   if(!query("maren"))
      return notify_fail("还没有开始呢。\n");

 if((string)me->query("family/family_name")!="盘丝洞")
      return notify_fail("你是哪里的？\n");
   if(me->query("faith")>1000)
      return notify_fail("青霞仙子对你说道：别在这里惹我上火。\n");
   tell_object(me,"你看着青霞仙子的遭遇真是十分痛心。\n");
   me->start_busy(4);
   me->add("faith",1);
   me->add("combat_exp",60);
   me->add("potential",50);
   me->improve_skill("pansi-dafa",1000);  
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}



