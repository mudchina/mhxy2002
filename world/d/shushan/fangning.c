//shushan2 by yushu@SHXY 2001.2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","访宁桥");
  set ("long", @LONG

白玉石砌成的小桥,上面刻满了稀奇古怪的花纹,仔细看好像不是花纹，
而是密密麻麻的文字，好像是一些诗,最好是读(read)一读。下面是一个
池塘，有许多鱼在里面游来游去。
LONG);
   
   set("outdoors", 2);
   set("exits", ([      
       "north" : __DIR__"zushi",
       "south" : __DIR__"tianshi",
   ]));
  setup();
}

void init()
{
  add_action("do_read", "read");
}

int do_read(string arg)
{
  object me=this_player();
  string *poem = ({
		"情丝难断心难负，怒向险中辟征途。",
		"良缘未成身已陨，只求痴心永随君。",
		"红颜自古多薄命，幽梦一帘几时醒。",
		"苦忆昔日旧容音，青鸟难传云外信。",
		"锁妖塔下成永诀，天涯何处觅行云！",
		"情至深处无怨尤，弃道却把夫君救。",
		"悠悠春梦随云散，片片飞花逐水流。",
		"翩翩双翅独飞去，柔肠寸断复何求？",
		"香魂一缕随风散，芳容几时入梦还？",
		"愿君莫忘旧缠绵，来世再续前生缘。",
		"细数长路多情恋，难忆当时几悲欢。 ",
		});

        if(me->is_busy() )
          return notify_fail("你现在忙着呢，哪有功夫读桥上的诗...\n");

        if((int)me->query_skill("literate",1)<100 )
               return notify_fail("你还看不懂上面的诗。\n");
   
        if(me->query("family/family_name") != "蜀山派")
        {
        tell_object(me,"你不是蜀山的你来下搅和什么。\n"); 
        return 1;
        }
        if(me->query("sen") < 100)
        {
        tell_object(me,"你还是先休息一会儿吧。\n");     
        return 1;
        }
        message_vision("$N仔细的读着桥上的诗：" + poem[random(sizeof(poem))] + "\n", me);
        me->add("sen",-50);
        me->start_busy(2);
        if(me->query("shushan/jinsheng_perform")) 
        {
        tell_object(me,"你似乎不能在这里悟到什么了。\n");       
        return 1;
        }
        if((int)me->query_skill("yujianshu", 1) > 149){
        tell_object(me,HIW"你感觉到了什么是「情」！\n"NOR);
        me->improve_skill("literate", 50+random(10));
        me->add("shushan/dushi",1);
        me->start_busy(2);
        }
        if(me->query("shushan/dushi",1) > 500)
        {
        me->set("shushan/jinsheng_perform",1);
        tell_object(me,HIG"读罢你顺口吟了一句："HIY"仗剑江湖梦已远，浪漫唯有《奇侠传》"HIG" 顿时你领悟出了"HIR"「御剑今生」！\n"NOR);
        me->delete("shushan/dushi");
        }
        return 1;
}             



       















