
inherit ITEM;
void create()
{
        set_name("»ðÇ¯", ({"tool"}));
        set_weight(1000);
                set("unit", "°Ñ");
                set("value", 50);
                set("material", "wood");
                set("wield_msg", "$N°Ñ$nÎÕÔÚÊÖÖÐ£®\n");

     set("no_get",1);
        setup();
}
void init()
{
add_action("do_make", "zao");
}
int do_make(string arg)
{
   object me=this_player();
   string env;
   if(!me->query("gm/dan"))
     return notify_fail("ÄãÕæµÄÊÇÀ´Á¶µ¤µÄ?ÔõÃ´¿´ÔõÃ´²»Ïó¡£\n");
   if(!arg && arg != "dan" )
     return notify_fail("ÄãÒªÁ¶Ê²Ã´£¿\n");

  if(me->is_busy())
    return notify_fail("ÄãÕýÃ¦×ÅÄØ£¡\n");
   env=environment(me)->query("short");
  if(env!="[1;33mÁ¶µ¤ÊÒ[m")
     return notify_fail("ÔÚÕâÁ¶Ê²Ã´µ¤°¡£¿\n");

   if((int)me->query("kee") <80)
     return notify_fail("ÄãÌ«ÀÛÁË£¬ÐªÐª°É£¡\n");
message_vision("$NÄÃÆð»ðÇ¯,°ÑÁ¶µ¤Â¯ÖÐµÄ»ðÌôÍúÁË¡£\n", me);
   me->start_busy(2);
call_out("zhai1",1,me);
call_out("zhai2",2,me);
call_out("zhai3",3,me);
call_out("zhai4",4,me);
   return 1;
}
void zhai1(object me)
{
   message_vision("$N°ÑÒ»°Ñ²ÝÒ©·Å½øÁËÁ¶µ¤Â¯¡£\n", me);
}
void zhai2(object me)

{
   message_vision("$NÖ»¼ûÒ»»áµÄ¹¦·ò£¬Â¯ÖÐµÄ²ÝÒ©±ä³ÉÁËÒ»¸öºÚÉ«µÄÍè×Ó\n",
me);
}
void zhai3(object me)
{
   message_vision("$NÓÃÁ¦µÄÉÈ·ç£¬Â¯ÖÐµÄ»ð¸ü´óÁË¡£ÕâÊ±$N·¢ÏÖÁËÒ»¿ÅÏÉµ¤¡£\n", me
);
}
void zhai4(object me)
{
   object where=environment(me);
	object dan=new("/d/qujing/xuanyuan/obj/foxdan");
   dan->move(me);
   me->delete("gm/dan");
   tell_object(me,"Äã´ÓÂ¯ÖÐÈ¡³öÁËÁ¶ºÃµÄÏÉµ¤¡£\n");
   me->add("sen", -50);
   me->add("faith",1);
   me->add("potential",8);
   me->add("combat_exp",10);
}
