inherit ROOM;
#include <ansi.h>
void create()
{
set("short", HIY"日"NOR+HIB"月"NOR+HIR"祭坛"NOR);
set("long", @LONG

    走进这里，空旷的大厅里立着一个祭坛，有无数颜色诡异的光芒在大厅闪耀，
你定睛看去，原来是太阳神和月亮神的祭坛。

LONG);
        set("exits", 
        ([ 
                        ]));
set("objects", ([ /* sizeof() == 1*/ 
]));
setup();
}
void init()
{
int i,j;
        object* inv;
        object me = this_player();
        inv = all_inventory(this_player());
        for(i=0; i<sizeof(inv); i++) 
       {
                if( inv[i]->query("id") == "tai yang") {
message("channel:rumor",HIY+"【"+HIB" 六道轮回 "NOR+HIY"】："NOR+HIR"众人眼前腾飞起一道无可描述的强烈白色光芒，你努力睁开眼睛\n                看到"NOR+HIY"☆太阳☆"NOR+HIR"正散发着炽热的白光，在你面前徐徐升起！\n"+NOR,users() );
         call_out ("dest",1,inv[i]);  
               this_player()->set_temp("eguijie/sun","done");
                            }
       }
        for(j=0; j<sizeof(inv); j++) 
        {
                if( inv[j]->query("id") == "yue") {
message("channel:rumor",HIY+"【"+HIB" 六道轮回 "NOR+HIY"】："NOR+HIM"紧接着"+HIB"☆月亮☆"NOR+HIM"化成一团阴柔而不耀眼的光芒，在太阳旁边形成\n                一个美丽的景色。\n"+NOR,users() );
                        destruct(inv[j]);
               this_player()->set_temp("eguijie/moon","done");
                            }
       }
if(me->query_temp("eguijie/moon") == "done" && me->query_temp("eguijie/sun") == "done")
  {
            call_out ("pass",1,me);  
  }
}
void dest (object me)
{
  destruct(me);
  return;
}
void pass (object ob)
{
if (ob->query("liudao/eguijie") == "done")
return;
  ob->delete_temp("liudao/eguijie","begin");
  ob->set("liudao/eguijie","done");
  ob->add("liudao/number",1);
    ob->add("combat_exp",10000);
tell_object(ob,"你赢得了"+chinese_number(1)+"万点武学奖励！\n");
message("channel:chat",HIY+"【"+HIB" 六道轮回 "NOR+HIY"】："NOR+ob->query("name")+HIB"顺利闯过六道中的饿鬼界。\n"+NOR,users() );
  ob->move("/d/changan/fendui");
  return;
}
