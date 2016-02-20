// Room: donglang2.c ¶«Ïá×ßÀÈ

inherit ROOM;

void init();
int close_men();
int force_open(object room);
int do_push(string arg);
int do_knock(string arg);
int valid_leave(object me, string dir);
string look_men();

void create()
{
    set("short", "¶«Ïá×ßÀÈ");
    set("long", @LONG
Äã×ßÔÚÒ»Ìõ×ßÀÈÉÏ£¬ÒşÔ¼¿ÉÒÔÌıµ½¶«±ß´«À´ºôÎüÉù£¬ËÆºõÓĞÈËÕıÔÚÄÇÀïÁ·¹¦£¬
±±±ßÓĞÒ»ÉÈÃÅ£¨men£©£¬ºÃÏóÊÇĞéÑÚ×Å¡£ÄÏ±ßÊÇ¼äÖñ×ÓÔú¾ÍµÄÎİ×Ó£¬Ê®·ÖµÄËØÑÅ£¬
ÀïÃæÆ®³öÒ»ÕóÕóµÄ²èÏã£¬ÓĞÈËÇáÉùÏ¸ÓïµØ²»ÖªËµÄÇĞ©Ê²Ã´£¬ÒıµÃÅ®º¢×Ó£¢³Ô³Ô£¢
Ğ¦³öÉùÀ´¡£
LONG );

    set("exits", ([
        "east" : __DIR__"liangongfang",
        "south" : __DIR__"chashi",
        "west" : __DIR__"donglang1",
    ]));

    set("item_desc",([
        "men"        :    (: look_men :),
    ]));

    set("no_clean_up", 0);
    setup();
}

void init()
{
    add_action("do_knock", "knock");
    add_action("do_push", "push");
}

int close_men()
{
    object room;

    if(!( room = find_object(__DIR__"xiuxishi")) )
        room = load_object(__DIR__"xiuxishi");
    if(objectp(room))
    {
        delete("exits/north");
        message("vision", "ÃÅÖ¨Ö¨Ñ½Ñ½µØ×Ô¼ººÏÉÏÁË¡£\n", this_object());
        room->delete("exits/south");
        message("vision", "ÃÅÖ¨Ö¨Ñ½Ñ½µØ×Ô¼ººÏÉÏÁË¡£\n", room);
    }
    else message("vision", "ERROR: men not found(close).\n", room);
}

int do_knock(string arg)
{
    object room;

    if (query("exits/north"))
        return notify_fail("´óÃÅÒÑ¾­ÊÇ¿ª×ÅÁË¡£\n");

    if (!arg || (arg != "door" && arg != "men"))
        return notify_fail("ÄãÒªÇÃÊ²Ã´£¿\n");

    if(!( room = find_object(__DIR__"xiuxishi")) )
        room = load_object(__DIR__"xiuxishi");

    if(objectp(room))
    {
    if ((int)room->query_temp("sleeping_person") > 0)
    {
        message_vision(
        "$N¸ÕÇáÇáµØÇÃÁËÒ»ÏÂÃÅ£¬¾ÍÌı¼ûÀïÃæ´«³öÒ»ÕóÀ×Ãù°ãµÄ÷ıÉù£¬\n"
        "ÏÔÈ»ÀïÃæµÄÈËË¯µÃ¸úËÀÖíËÆµÄ£¬ÔõÃ´ÇÃ¶¼Ã»ÓÃÁË\n",
        this_player());
    } else if ((int)room->query_temp("person_inside") > 0)
    {
        switch( random(2) )
        {
        case 0:
                message_vision(
                "$NÇáÇáµØÇÃÁËÇÃÃÅ£¬Ö»Ìı¼ûÀïÃæÓĞÈËºÜ²»ÄÍ·³µØºğµ½£º\n"
                "¸ÕÌÉÏÂ¾ÍÀ´ÇÃÃÅ£¡ÎÒË¯×ÅÁË£¬Ìı²»¼û£¡£¡£¡\n",
                this_player());
        case 1:
                message_vision(
                "$NÇáÇáµØÇÃÁËÇÃÃÅ£¬Ö»Ìı¼ûÀïÃæÓĞĞ©Ïì¶¯£¬\n"
                "ºÃÏóÓĞÈËÔÚõâÀ´õâÈ¥£¬ÄÃ²»¶¨Ö÷ÒâÊÇ·ñ¿ªÃÅ¡£\n",
                this_player());

                break;
        }

    } else
    {
        room->delete_temp("sleeping_person");
        message_vision("$NÇáÇáµØÇÃÁËÇÃÃÅ£ºßË¡¢ßË¡¢ßË£®£®£®ßË¡¢ßË¡¢ßË£®£®£®\n",
            this_player());
    }
    }

    if(objectp(room))
        message("vision",
        "ÍâÃæ´«À´Ò»ÕóÇÃÃÅÉù£¬Äã´ÓÃÅ·ìÍùÍâÒ»ÇÆ£¬ÊÇ"+this_player()->query("name")+
"Ò»Á³½¹¼±µØÕ¾ÔÚÃÅÍâ£¬\n"
        "¿´Ñù×ÓÒ²Ïë½øÀ´ĞİÏ¢¡£\n", room);
    return 1;
}

int do_push(string arg)
{
    object room;

    if (query("exits/north"))
        return notify_fail("ÃÅÒÑ¾­ÊÇ¿ª×ÅÁË¡£\n");

    if (!arg || (arg != "door" && arg != "men"))
        return notify_fail("ÄãÒªÍÆÊ²Ã´£¿\n");

    if(!(room = find_object(__DIR__"xiuxishi")))
        room = load_object(__DIR__"xiuxishi");

    if(objectp(room))
    {
    if((int)room->query_temp("person_inside")<=0)
    {
                room->delete_temp("person_inside");
        set("exits/north", __DIR__"xiuxishi");
        message_vision("$NÇáÇáµØ°ÑÃÅÍÆ¿ª¡£\n", this_player());
        room->set("exits/south", __FILE__);
//      message("vision", "ÓĞÈË´ÓÍâÃæ°ÑÃÅÍÆ¿ªÁË¡£\n", room);
        remove_call_out("close_men");
        call_out("close_men", 10);
    } else
    {
        message_vision("$NÏë°ÑÃÅÍÆ¿ª£¬È´·¢¾õÃÅ±»ÈË´ÓÀïÃæãÅÉÏÁË¡£\n",
                this_player());
    }
    }

    return 1;
}


string look_men()
{
    object room;

    if (query("exits/north"))
        return ("ÃÅÉÏ¹ÒÁË¸öÅÆ×Ó£ºÄÏ¿ÂÃÎ´¦\n");

    if(!( room = find_object(__DIR__"xiuxishi")) )
        room = load_object(__DIR__"xiuxishi");

    if( objectp(room) )
    if( (int)room->query_temp("person_inside") > 0 )
    {
        return ("ÃÅÉÏ¹ÒÁË¸öÅÆ×Ó£ºÇëÎã´òÈÅ\n");
    }

    return ("ÃÅÉÏ¹ÒÁË¸öÅÆ×Ó£ºĞİÏ¢ÊÒ\n");
}

int valid_leave(object me, string dir)
{

        object room;

        if(!( room = find_object(__DIR__"xiuxishi")) )
                room = load_object(__DIR__"xiuxishi");

        if(objectp(room) && dir == "north")
        {
                room->add_temp("person_inside", 1);
                // will open the door if ppl inside stay too long
                remove_call_out("force_open");
                call_out("force_open", 599, room);
        }

        return ::valid_leave(me, dir);
}

int force_open(object room)
{
        if ( !objectp(room) ) return 0;
    if((int)room->query_temp("person_inside")<=0) return 0;

/***
    if((int)room->query_temp("sleeping_person")>0)
    {
                remove_call_out("force_open");
                call_out("force_open", 599, room);
                return 0;
        }
***/

        room->delete_temp("person_inside");
    set("exits/north", __DIR__"xiuxishi");
    room->set("exits/south", __FILE__);
    message("vision", "ÍâÃæÍ»È»ÏìÆğ´ÖÖØµÄ½Å²½Éù£¬ÓÉÔ¶¶ø½ü£¬µ½ÃÅÇ°Í£ÁËÏÂÀ´£®£®£®\
n"
        "ÕÅËÉÏªÅ¾µØ°ÑÃÅ´ò¿ª£¬Éì¸öÍ·½øÀ´£¬Ò»Á³ºüÒÉ£º´ô´ó°ëÌìÁË»¹²»³öÈ¥£¬¸ãÊ²Ã´¹í£
¿\n", room);
    remove_call_out("close_men");
    call_out("close_men", 10);
}
