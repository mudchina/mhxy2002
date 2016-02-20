
inherit ROOM;
void create()
{
set("short","[35mÁ·Õë·¿[m");
set("long",@LONG
  
    ÔÚÕâ¸öµØ·½£¬ÊÇĞí¶àĞ¡ºüÀêÁ·ĞÄ³¦µÄµØ·½£¬ºüÀê×î¼ÉµÄ
¾ÍÊÇµ¨Ğ¡£¬æ§¼¸ÎªÁËÈÃÃ¿¸öĞ¡ºüÀê³öÈ¥ÒÔºó¶¼ÄÜºÍËıÒ»ÑùĞÄ
ºİÊÖÀ±£¬ÌØµØÔÚ±øÂíÙ¸ÀïÃæÑ¡ÁËÒ»Ğ©ÏóÕæÈËµÄÄ¾ÈË£¬¸øĞ¡ºü
ÀêÃÇ×öÁ·Ï°¡£Ò»ÏÂĞ¡ºüÀêÔÚÕâ´ÌÉ±£¨cisha£©Ä¾ÈËÀ´Ôö¼Óµ¨Á¿¡£

LONG);
set("exits", ([
       "north" : __DIR__"nei1",
]));
set("objects", ([
  __DIR__"npc/bingma":2,
   __DIR__"npc/master2":1,
]) );
setup();

}


void init()
{
add_action("do_cisha","cisha");
}
int do_cisha()
{
   object me=this_player();
   if(me->is_busy())
    return notify_fail("ÄãÕıÃ¦×ÅÄØ¡£\n");
   if((string)me->query("family/family_name")!="ĞùÔ¯¹ÅÄ¹")
    return notify_fail("Äã²»ÊÇÎÒÃÇ ĞùÔ¯¹ÅÄ¹µÄ£¬ÓÃ²»×ÅÀ´Ôö¼Óµ¨Á¿¡£\n");
  if(me->query("combat_exp")>100000)
        return notify_fail("Äã¸ÃÈ¥´³Ò»·¬ÌìµØÁË.\n"); 
  if(me->query("faith")>200)
      return notify_fail("ÄãÒÑ¾­²»ĞèÒªÔÚÕâÖÖµØ·½Ôö¼Óµ¨Á¿.\n");
tell_object(me,"ÄãÄÃ×ÅÕë¶ÔÄ¾ÈËµÄÒªº¦²¿Î»´ÌÁËÈ¥£¬¶ÙÊ±Äã¸Ğµ½Õâ¸öÊÀ½çÉÏÃ»ÓĞÈË¸ĞÈÇÄã.\n");

   me->start_busy(2);
      me->add("faith",1);
      me->add("combat_exp",10);
      me->add("potential",2);
        me->add("kee",-50);
   return 1;
}
