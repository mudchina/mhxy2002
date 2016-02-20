// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */

// worker.c

inherit NPC;
#include <ansi.h>

string *msg = ({
        "ĞÂÊÖ¶à¶àhelpÀ­£¬Èçhelp news,help task,help joball£¡\n",
        "ÎÒÃÇµÄÖ÷Ò³µØÖ·ÊÇ http://yszz.myrice.com,»¶Ó­·ÃÎÊ£¡\n",
        "help chatÀïÃæÓĞ±¾MUD×îcoolµÄÁÄÌìÊÒ£¡\n",
        "help MHXYÀïÃæÓĞ¹ØÓÚMUDµÄ×îĞÂ±ä»¯£¡\n",
        "help zichuangÓĞÃÎ»ÃÎ÷ÓÎµÄ×Ô´´Îä¹¦ÏµÍ³\n",
        "help mieyaoµ±È»¾ÍÊÇÉ±¹ÖÏµÍ³ÁË¡£\n",
        "ÕæÕıµÄÃÅÅÉÕù¶·Óë´Ë¿ªÊ¼£¬ help shili £¡\n"
        });

void create()
{
        set_name("ÃÎ»ÃÎ÷ÓÎ", ({"mhxy"}));
        set("gender", "ÄĞĞÔ" );
        set("age", 13);
        set("title", "[1;32mÃÎ»ÃÎ÷ÓÎÓ­¿ÍĞ¡Í¯[m");
        set("long", "Ò»¸ö¿É°®µÄĞ¡Í¯£¬Ã¿Ìì¸ºÔğÔÚÕâÀïÓ­½ÓÔ¶µÀ¶øÀ´µÄ¿ÍÈË£®\n");
        set("combat_exp", 200);
        set("attitude", "friendly");
        set_skill("dodge", 10);
        set("per", 30);
        set("max_kee", 1500000);
        set("kee",1500000);
        set("sen",1500000);
        set("max_sen", 1500000);
        setup();
        remove_call_out("msg");
        call_out("msg",300);
}

void msg()
{
        command_function("es "+NOR+HBRED+msg[random(sizeof(msg))]+NOR);
        
        remove_call_out("msg");
        call_out("msg",300);

}
