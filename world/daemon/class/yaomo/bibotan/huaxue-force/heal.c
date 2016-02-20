// heal.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("Õ½¶·ÖÐÁÆÉË£¿ÕÒËÀÂð£¿\n");

        if( (int)me->query("force") < 50 )
                return notify_fail("ÄãµÄÕæÆø²»¹»¡£\n");

        if( (int)me->query("eff_kee") == (int)me->query("max_kee") )
                return notify_fail("ÄãÆøÑªÔ²Âú£¬²»ÐèÒªÁÆÉË¡£\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return notify_fail("ÄãÒÑ¾­ÊÜÉË¹ýÖØ£¬Ö»ÅÂÒ»ÔËÕæÆø±ãÓÐÉúÃüÎ£ÏÕ£¡\n");

        message_vision("[1;36m$NÅÌÍÈ¶ø×ø£¬È«Éí·¢³ö¹ÉÇàÆø£¬ÉË¿ÚÒ²½¥½¥ÓúºÏÁË¡£\n[2;37;0m", me);

        me->receive_curing("kee", 20 + (int)me->query_skill("force")/5 );
        me->add("force", -50);

        return 1;
}