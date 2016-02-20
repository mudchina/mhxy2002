//Cracked by Roath
//by tianlin 2001/5/1
#include <ansi.h>
#define LAST_PAR "bc"
#define THIS_PAR "bcsf"
inherit ITEM;
void create()
{
    set_name(HIG"ÀñÎïÌ¨"NOR, ({ "table"}));
    set_weight(5000000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "¸ö");
        set("no_get","Õâ¸öÌ¨×ÓÊÇÎ×Ê¦¸øÍæ¼Ò·¢ÀñÎïµÄ£¬Äã²»ÄÜÍµ×ß");
        set("long","Ò»¸ö¾Þ´óÎÞ±ÈµÄÀñÎïÌ¨£¬ÉÏÃæ·ÅÂúÁË·¢¸ø´ó¼ÒµÄÀñÎï£¬³Ã×ÅÃ»È¥µô´ó¼Ò¿ìÄÃÀñÎï(take gift)°¡£¡");
        set("value", 0);
        set("material", "stone");
    }
}
void init()
{
    add_action("do_pick", "take");
}
 
int do_pick(string arg)
{
       object me,obj;
       me = this_player();
       if( !arg || arg!="gift" ) return notify_fail("ÄãÒªÄÃÊ²Ã´£¿\n");

 //      return notify_fail("ÏÖÔÚÃ»ÓÐÀñÎïÄÃ¡£\n");

       if (me->query(THIS_PAR + "_pick")) {
       tell_object(me,CYN "Ë®ÖÐÔÂµÄÉíÓ°Í»È»³öÏÖÔÚÒ»ÕóÑÌÎíÖ®ÖÐ¡£\n\n");
       tell_object(me,HIR "Ë®ÖÐÔÂÒ»°ÍÕÆÇÃÔÚÄãÊÖÉÏ£ºÐ¡ÅóÓÑ£¬²»ÒªÌ«Ì°ÐÄÅ¶£¡Ã¿ÈËÖ»ÓÐÒ»·ÝÀñÎï£¡\n\n");
       tell_object(me,CYN "Ö»¼ûÒ»ÕóÑÌÎí¹ýáá£¬Ë®ÖÐÔÂµÄÉíÓ°ÒÑ¾­²»¼ûÁË¡£\n" NOR);
       return 1;
       }
      obj = new (__DIR__"gift");
      obj->move(me);
       message_vision("$N´Ó[1;32mÀñÎïÌ¨[2;37;0mÉÏÄÃÁËÒ»¸ö[1;33mÀñÎï°ü[2;37;0m¡£\n",me );
//Ã¿´Î¼ðÀñÎï£¬¶¼½«ÉÏ´ÎµÄ²ÎÊýÏû³ý£¬Ôö¼Ó±¾´ÎÄÃµÄ²ÎÊý¡£ 
       me->delete(LAST_PAR + "_pick");
       me->set(THIS_PAR + "_pick",1);
       return 1;
}

