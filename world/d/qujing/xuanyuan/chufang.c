inherit ROOM;
void create()
{
set("short","[36m³ø·¿[m");
set("long",@LONG

        ÕâÀïµ±È»¶¼ÊÇºüÀêÃÇÏ²»¶µÄÊÂÎïÁË£¬ºüÀêÃÇ
Æ½Ê±Ò²Ï²»¶¸ÉÐ©Íµ¼¦Ãþ¹·µÄÊÂÇé£¬µ«ÊÇÕâÐ©ÏëÉýÌìµÄ
ºüÀêÃÇºÃÏó¸üÏ²»¶³Ô»îÈË£¬À´Ôö¼ÓËûÃÇµÄÐÞÐÐ¡£²»ÐÅ
µÄ»°£¬ÄãÀ´×ö£¨make£©Ò»¸öÈËÍ·ÊÔÊÔ¡£

LONG);
set("exits", ([
       "south" : __DIR__"nei1",
]));
set("objects", ([
"/clone/misc/head":1,
"/d/qujing/xuanyuan/obj/renxue":2,
"/clone/misc/head2":1,
"/d/obj/food/jitui":3,
]));
setup();

}


void init()
{
add_action("do_make","make");
}
int do_make()
{
   object me=this_player();
   if(me->is_busy())
    return notify_fail("ÄãÕýÃ¦×ÅÄØ¡£\n");
    if((string)me->query("family/family_name")!="ÐùÔ¯¹ÅÄ¹")
    return notify_fail("Äã²»ÊÇÎÒÃÇ ÐùÔ¯¹ÅÄ¹µÄ£¬ÓÃ²»×ÅÀ´ÎÒÃÇÕâ×öÈËÍ·\n");
 if(me->query("faith")>200||me->query("combat_exp")>100000)
      return notify_fail("Äú²»ÐèÒªÔÚÕâÖÖµØ·½¸É»îÁË£®\n");
   tell_object(me,"Äã×¥ÆðÒ»¸ö»îÈË£¬......ÈýÏÂÎå³ý¶þ£¬¶ÙÊ±Ò»¸öÍ·Â­³öÏÖÁË¡£\n");
   me->start_busy(5);
      me->add("faith",1);
      me->add("combat_exp",15);
      me->add("potential",4);
      me->add("bellicosity",1);
me->improve_skill("spells",2);
   me->receive_damage("kee",50);
message_vision("$N¾õµÃ·¨Êõ½ø²½ÁË!\n",me);
  ("/clone/misc/head")->move(me);
 return 1;
}
