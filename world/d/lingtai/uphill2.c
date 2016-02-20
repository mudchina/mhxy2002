// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
// Room: some place in Î÷Å£ºØÖŞ
// uphill2.c

inherit ROOM;

void create()
{
  set ("short", "[0;33m¿İËÉÆº[m");
  set ("long", @LONG

É½Â·ÒÀ¾ÉòêÑÓ¶øÉÏ£¬Î÷±ßµÄËÉÁÖ±»É½·çÒ»´µ£¬»©»©µØ×öÏì¡£
Ì§Í·ÉÏÍû£¬É½¸ßÁÖÃÜ£¬²»Öª»¹Òª×ß¶àÔ¶£®ÏòÎ÷±ßÍûÈ¥£¬ÁÖÖĞ
Ì«°µ£¬Ê²Ã´Ò²¿´²»Çå³ş¡£Ç°·½Ò»¿Ã´óËÉÊ÷(pine)ÉÏºÃÏóĞ´ÁË
Ğ©Ê²Ã´¡£
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "pine" : "Ğ¡ĞÄÁÖÖĞÓĞÀÇ£¡\n",
]));

set("exits", ([ /* sizeof() == 4 */
"northup" : __DIR__"uphill3",
"south": __DIR__"uphill1",
"west": __DIR__"forrest"
]));

        set("no_clean_up", 0);
   set("outdoors", 1);
        setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{       
   object me;
        me=this_player();

        if ( !arg || ((arg != "pine") ))
                return notify_fail("ÄãÒªÅÀÊ²Ã´£¿\n");
        else
                message_vision("$N×¥×¡Éì³öµÄÊ÷Ö¦£¬Ğ¡ĞÄÒíÒíµÄÅÀÁËÉÏÈ¥¡£\n",me);
                me->move("/d/lingtai/uptree");
     me->receive_damage("kee", 20);
     tell_room( environment(me), "Ê÷Ö¦»ÎÁË¼¸»Î£¬ÓĞ¸öÈËÅÀÁËÉÏÀ´£¡\n", ({me}));

                return 1;
}

