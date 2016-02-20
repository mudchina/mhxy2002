//By tianlin@Mhxy for 2002.1.20
 
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "水帘洞内部");
  set ("long", @LONG

这里是水帘洞的深处。洞内一片黑暗，石缝内依稀可以看见什么东西
黑乎乎的。你试图将石缝扩大(expand)一些，从中取出那件东西。
LONG);

  setup();
}

void init()
{
   add_action("do_expand", "expand");
}

int do_expand(string arg)
{
   object me=this_player();
   object ob; 

   if( (!arg) || !((arg == "gap") || (arg == "石缝")))
     return notify_fail("你要扒开什么？\n");

   if( !(ob = me->query_temp("weapon")) || ( (string)ob->query("skill_type")!="axe" && (string)ob->query("skill_type")!="blade" && (string)ob->query("skill_type")!="sword" ) ) 
     return notify_fail("没有工具怎么干活？\n");

   if( me->query_str() < 50 )
     return notify_fail("你的力量不够大！\n");

   if (me->query("kee") < 200) {
     message_vision(HIR"\n只听得轰的一声，一大块石壁塌了下来，将$N砸晕了过去。\n\n"NOR, me);
     me->unconcious();
     }
   else {
     me->receive_damage("kee", 200);
     message("vission", HIR "\n只听得轰的一声，一大块石壁塌了下来。\n\n" NOR, environment(me));
     }
     

    if( "/d/obj/weapon/stick/fake-jingubang"->in_mud() )  {
        message("vission", HIR "你看见石块之中空空如也。\n"NOR, me);
        return 1;
    }
   ob=new("/d/obj/weapon/stick/fake-jingubang.c");
   ob->move(environment(me));
   message("vission", HIR "你看见石块之中露出一把金箍棒。\n"NOR, me);
   CHANNEL_D->do_channel(this_object(),"rumor",me->name()+HIM"在"HIG"花果山"HIM"密室,发现了传说中"HIW"孙悟空"HIM"遗留的"BLINK+HIY"金箍棒"NOR+HIM"。"NOR);
   return 1;
}

