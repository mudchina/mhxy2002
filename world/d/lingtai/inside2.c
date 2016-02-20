// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// Room: some place in Î÷Å£ºØÖŞ
// inside2.c

inherit ROOM;

void create()
{
  set ("short", "[0;33mÁ·¹¦³¡[m");
  set ("long", @LONG

Ò»¸öĞ¡Ğ¡µÄÁ·¹¦³¡£®³¡ÄÚÒ»¸öÖĞÄêµÀÊ¿ÔÚ½ÌÒ»Ğ©Ğ¡µÀÃÇÎä¹¦¡£ÖÜ
Î§±øÆ÷¼ÜÉÏ·Å×ÅÒ»Ğ©±øÆ÷¡£
LONG);
set("exits", ([ /* sizeof() == 4 */
"west": __DIR__"gate1",
"east": __DIR__"inside7",
"north": __DIR__"inside8",
"south": __DIR__"sleep",
]));
set("objects", ([
                __DIR__"npc/xiao": 3, 
                __DIR__"npc/zhangmen": 1,
     __DIR__"obj/rack": 1,
]) );
        set("no_clean_up", 0);
   set("outdoors", 1);
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
        if (dir == "south" ) {
        if (objectp(present("zhang men", environment(me)))) {
        if((string)me->query("family/family_name")=="·½´çÉ½ÈıĞÇ¶´") {
        return ::valid_leave(me, dir);
        }
        return notify_fail("ÕÆÃÅ´óµÜ×ÓÈÂµ½£ºÄÇ²»ÊÇÄã¸ÃÈ¥µÄµØ·½£¡\n");
        }
        }
        return ::valid_leave(me, dir);
}


