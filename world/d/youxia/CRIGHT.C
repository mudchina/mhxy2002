#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "ÓÒÆ«Ôº");
  set ("long", @LONG

ÕâÊÇÒ»¸ö¿É°®µÄĞ¡²İÆº£¬²İÆºÉÏÓĞÒ»Ô²Ê¯×À£¬×À±ßÓĞÊ¯µÊ¡£×ÀÃæ
ÊÇ¾«ÖÂ´óÀíÊ¯£¬Ê¯ÉÏ¿Ì×ÅÒ»¸öÆåÅÌ¡£ÅÌÉÏ»¹·Å×ÅÒ»¾ÖÎ´ÍêµÄ²ĞÆå
¡£ËÆºõÑ§Ï°£¨£ø£é£á£©Ò»ÏÂ¿ÉÒÔµÃµ½²»ÉÙÖªÊ¶¡£×ÀÉÏ»¹ÓĞÁ½±­²Ğ
¾Æ£¬ÉĞÓĞÓàÎÂ¡£

LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "canqi" : "Ò»¾ÖÎ´ÍêµÄ²ĞÆå£¬ÆåÊÆ°ÂÃîÎŞÇî£®£®£®\n",
]));


  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
    "west" : __DIR__"yard",
]));
 set("objects", ([
__DIR__"obj/canqi" : 1,
__DIR__"npc/oldman" :1,

                       
 ]) );

  setup();
}

void init()
{
        add_action("do_study", "xia");
}

int do_study(string arg)
{       
        object me=this_player();
        int sen_cost, kee_cost, force_cost, gain;

        if( !arg || (arg != "canqi"))
                return notify_fail("ÄãÒªÏÂÊ²Ã´Æå£¿\n");
        if( me->is_busy() )
                return notify_fail("ÄãÃ¦µÄºÜ£¬ÄÄÓĞ¹¦·òÈ¥ÑĞ¾¿Æå¾Ö£¡\n");
        if( me->is_fighting() )
                return notify_fail("ÏÖÑ§ÏÖÂôÒÑÀ´²»¼°ÁË£¡\n");
        if( (int)me->query_skill("literate", 1) < 100)
                return notify_fail("Äã¿´ÁË°ëÌìÒ²¿´²»¶®ÆåÅÌÉÏÃæ°ÚÁËĞ©Ê²Ã´£¡\n");
        if( (int)me->query_skill("literate", 1) < 180)
                return notify_fail("Äã¿´ÁË°ëÌìºÃÏóËä¿´³öÁËµãÏÂÆåµÄÃÅµÀ£¬È´»¹²»ÊÇÀÏÈËµÄ¶ÔÊÖ¡£\n");
        if( (int)me->query_skill("literate", 1) >= 500)
                return notify_fail("ÀÏÈËËµµÀ:²»ÓÃÔÙÏÂÁË£¬ÀÏ·òÒÑ¾­ÈÏÊäÁË¡£\n");
        if( (int)me->query("max_force") < 1000)
                return notify_fail("Äãµ×Æø²»×ã£¬Á·²»ÁË¡£\n");

        sen_cost = 80 - (int)me->query_int();
        if( (int)me->query("sen") < sen_cost )
                return notify_fail("ÄãÏÖÔÚÍ·ÔÎÄÔÕÍÔõÃ´ÏÂÆå£¬¸ÃĞİÏ¢ĞİÏ¢ÁË¡£\n");

        kee_cost = 80 - (int)me->query_con();
        if( (int)me->query("kee") < kee_cost )
                return notify_fail("ÄãÏÖÔÚ»ëÉíÎŞÁ¦ÔõÃ´ÏÂÆå£¬¸ÃĞİÏ¢ĞİÏ¢ÁË¡£\n");

        force_cost = 20;
        if( (int)me->query("force") < force_cost )
                return notify_fail("ÄãÏÖÔÚÒÑÌá²»ÆğÆøÁËÔõÃ´ÏÂÆå£¬¸ÃĞİÏ¢ĞİÏ¢ÁË¡£\n");

        me->receive_damage("sen", sen_cost);
        me->receive_damage("kee", kee_cost);
        me->add("force", - force_cost);

        gain = (int)me->query("int")/2 + (int)me->query("con")/2 + 1 + random(10);

        me->improve_skill("literate", gain);

        write("ÄãºÍÀÏÈË×øÏÂÀ´¿ªÊ¼ÂıÂıµÄÏÂÆå£®£®£®ÀÏÈËÅÄÅÄÄãµÄ¼çËµµÀ£ºÄãµÄÆåÒÕ²»´íÂï¡£
[33mÄãµÄ¡¸¶ÁÊéÊ¶×Ö¡¹½ø²½ÁË£¡[0m\n");

        tell_room( environment(me), me->name() + "ËÆºõÕıÔÚºÍÀÏÈË½ò½òÓĞÎ¶ÏÂÆå£®£®£®\n", ({me}));

        return 1;
}

