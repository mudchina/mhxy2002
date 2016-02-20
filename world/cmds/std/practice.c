//By tianlin@Mhxy for 2002.1.20,¼ÓÈëÉ±ÁËÈË²»ÄÜlian

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string skillname;
        int skill, skill_basic,time;
        int i;
        seteuid(getuid());
        if( environment(me)->query("no_fight") || 
                environment(me)->query("no_magic") )
                   return notify_fail("°²È«ÇøÄÚ½ûÖ¹Á·¹¦¡£\n");

        if( me->is_fighting() )
                return notify_fail("ÄãÒÑ¾­ÔÚÕ½¶·ÖĞÁË£¬Ñ§Ò»µãÊµÕ½¾­Ñé°É¡£\n");

        if( me->query("PKS")>0 )
                return notify_fail("Äã¸ÕÉ±¹ıÈË£¬»¹¸ÒÁ·¹¦²»ÅÂ±ğÈËÀ´É±Äã¡£\n");

        if( !arg ) return (__DIR__"enable")->main(me, arg);

        if(sscanf(arg, "%s %d", arg, time)!=2 )

        if(sscanf(arg, "%s %d", arg, time)!=2 )
            time=1;

        if(time<1) time=1;
        if(time>10) time=10;

        if( !stringp(skillname = me->query_skill_mapped(arg)) )
                return notify_fail("ÄãÖ»ÄÜÁ·Ï°ÓÃ enable Ö¸¶¨µÄÌØÊâ¼¼ÄÜ¡£\n");
        skill_basic = me->query_skill(arg, 1);
        skill = me->query_skill(skillname, 1);

        if( skill < 1 )
                return notify_fail("ÄãºÃÏñ»¹Ã»¡¸Ñ§»á¡¹ÕâÏî¼¼ÄÜ°É£¿×îºÃÏÈÈ¥Çë½Ì±ğÈË¡£\n");
        if( skill_basic < 1 )
                return notify_fail("Äã¶ÔÕâ·½ÃæµÄ¼¼ÄÜ»¹ÊÇÒ»ÇÏ²»Í¨£¬×îºÃ´ÓÏÈ´Ó»ù±¾Ñ§Æğ¡£\n");

        if( skill*skill*skill/10 > (int)me->query("combat_exp") )
                return notify_fail("ÄãµÄÎäÑ§»¹²»¹»£¬Á·µÃÔÙ¶àÒ²Ã»ÓÃ¡£\n");

        notify_fail("ÄãÏÖÔÚ²»ÄÜÁ·Ï°ÕâÏî¼¼ÄÜ¡£\n");
        if( !SKILL_D(skillname)->valid_learn(me) ) return 0;
        notify_fail("ÄãÊÔ×ÅÁ·Ï°" + to_chinese(skillname) + "£¬µ«ÊÇ²¢Ã»ÓĞÈÎºÎ½ø²½¡£\n");
        if(skill_basic <= skill && random(100)==0)
          write("ÄãµÄ" + to_chinese(skillname)+ 
            "ºÜÄÑÌá¸ßÁË£¬»¹ÊÇÏòÄãÊ¦¸¸Çë½ÌÇë½Ì°É£¡\n");
        if( SKILL_D(skillname)->practice_skill(me) ) 
        {
        for(i=0;i<=time;i++) {
                me->improve_skill(skillname, skill_basic/5+1, skill_basic > skill? 0: 1);
                me->add("sen", -5);
                              }
                write( HIY "ÄãµÄ" + to_chinese(skillname) + "½ø²½ÁË£¡\n" NOR);
                return 1;

        }

        else return 0;
}

int help(object me)
{
        write(@TEXT
Ö¸Áî¸ñÊ½£ºpractice <¼¼ÄÜÖÖÀà>

[36mÀı: practice parry <= 10 ×î¶à practice parry 10[2;37;0m

Õâ¸öÖ¸ÁîÈÃÄãÁ·Ï°Ä³¸öÖÖÀàµÄ¼¼ÄÜ£¬Õâ¸ö¼¼ÄÜ±ØĞëÊÇ¾­¹ı enable µÄ×¨Òµ¼¼ÄÜ¡£
Èç¹ûÄã¸ÃÏîµÄ»ù±¾¼¼ÄÜ×ã¹»¸ß£¬¿ÉÒÔ¾­ÓÉÁ·Ï°Ö±½ÓÉı¼¶£¬¶øÇÒÉı¼¶µÄÉÏÏŞÖ»¸ú
Äã»ù±¾¼¼ÄÜµÄµÈ¼¶ÓĞ¹Ø£¬»»¾ä»°Ëµ£¬ÇÚ¼ÓÁ·Ï°ÊÇÊ¹ÄãµÄËùÑ§¡¸Çà³öÓÚÀ¶Ê¤ÓÚÀ¶¡¹
µÄÎ¨Ò»Í¾¾¶£¬µ±È»£¬ÔÚÕâÖ®Ç°Äã±ØĞë´ÓÊµ¼ÊÔËÓÃÖĞ»ñµÃ×ã¹»µÄ¾­ÑéÒÔÌáÉıÄãµÄ»ù
±¾¼¼ÄÜ¡£
TEXT
        );
        return 1;
}

