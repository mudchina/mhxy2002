inherit ROOM;
void create()
{
set("short","[35mÃÜÊÒ[m");
set("long",@LONG

   ÕâÊÇÒ»¸ö³äÂúÉ§³ôµÄ·¿×Ó£¬»è°µµÄµÆ¹âÈçÈËµÄÏÊÑªÒ»°ã£¬
ÁîÄã²»º®¶øÀõ£¬ÄãÒÀÏ¡¿ÉÒÔ¿´µ½Ò»Ğ©ºüÀêµÄ·à±ã£¬¿´À´Õâ¸ö
·¿¼ä»¹ÊÇ¾­³£ÓĞÈË¹âÁÙµÄ¡£

LONG);
set("exits", ([
       "north": __DIR__"dadian",
       "south":__DIR__"mishi2",
]));
set("objects", ([
  __DIR__"npc/zhangmen" : 1,
]) );
setup();

}

void init()
{
object *inv;
int i;

 inv = all_inventory();
  for(i=sizeof(inv)-1; i>=0; i--)
{
if(!interactive(inv[i]))
if (!living(inv[i])) destruct(inv[i]);
}

        add_action("do_none","get");
        add_action("do_none","ji");
        add_action("do_none","steal");
    add_action("do_none","put");
    add_action("do_none","drop");
}

int do_none()
{
        object zm=present("zhang men");
        if( zm )
        {
        message_vision("$N¶Ô$nÒ¡ÁËÒ¡Í·¡£\n",zm,this_player());
        return 1;
        }
        return 1;
}
int valid_leave(object me, string dir)
{
        if (! (me->query_temp("can_in")) && dir == "south" &&
        (string)me->query("family/family_name") != "ĞùÔ¯¹ÅÄ¹" )
        return notify_fail("Ö»ÓĞæ§¼ºµÄÇ×ĞÅ²ÅÄÜÈ¥ÄÇ¡£\n");
        return ::valid_leave(me, dir);
}
