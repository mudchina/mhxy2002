//by tianlin@mhxy 2001.5.1.
//check.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
        object ob;
        int mana_cost;
        int sen_cost;
        string msg;

        if(!arg) 
                return notify_fail("ÄãÏë´òÌıË­µÄ×´Ì¬£¿\n");
        if((int)me->query("daoxing")<5000)
                return notify_fail("ÄãµÄµÀĞĞ²»¹»£¬ÓÃ²»ÁËµØ¶úÁé¡£\n");
        if((int)me->query("mana")<60) 
                return notify_fail("ÄãµÄ·¨Á¦²»¹»£¬ÓÃ²»ÁËµØ¶úÁé¡£\n");
        if((int)me->query("sen")<=50)
                return notify_fail("ÄãÏÖÔÚÌ«ÀÛÁË£¬ĞİÏ¢ĞİÏ¢°É£¡\n");
        mana_cost=-(100-(int)me->query_skill("spells"))/4-40;
        mana_cost=mana_cost+10;
        if(mana_cost > -50) mana_cost=-50;
        me->add("mana", mana_cost);
        sen_cost=50;
        message_vision(HIY "$NÄîÁË¸öÖä£¬¶ÔÌì´óºğ£ºÓñ»ÊÀÏ¶ù£¬°³¼±ÕĞ[1;37m¡°Ë³·ç¶ú¡±[2;37;0m[1;33mÈçÓĞ²»´Ó£¬±Ø´òÉÏÁéÏö±¦µî£¡\nÖ»¼ûÒ»¹ÉÑÌÎí¹ıºó£¬Ò»¸öÉñÉ«»ÅÕÅµÄ¼Ò»ïÔÚ$N¶ú±ßµÍÉùËµÁË¼¸¾ä»°¡£\n" NOR, me);
        ob = find_player(arg);
        if(!ob) {
            ob=present(arg,environment(this_player()));
            if(ob && !living(ob)) ob=0;
        }
        if( !ob ) ob = find_living(arg);
        if(!ob || (ob->query("env/invisibility") && wizardp(ob) ))
                return notify_fail("Ë³·ç¶ú¶ÔÄã¾ÏÁË¸ö¹ªËµµ½£ºĞ¡ÈË·¨Á¦ÊèÇ³£¬ÊµÔÚÕÒ²»µ½Õâ¸öÈË£®£®£®\n");
        
        write("Ë³·ç¶ú¸æËßÄã£º"+ob->query("name")+"[2;37;0mµÄ[1;33mµÀĞĞ[2;37;0mÒÑ´ï"+RANK_D->describe_dx((int)ob->query("daoxing"))+"µÄ¾³½ç¡£\n");  
        write("Ë³·ç¶ú¸æËßÄã£º"+ob->query("name")+"[2;37;0mµÄ[1;36mÎä¹¦[2;37;0mÒÑ´ï"+RANK_D->describe_exp((int)ob->query("combat_exp"))+"µÄ¾³½ç¡£\n");
        write("Ë³·ç¶ú¸æËßÄã£º"+ob->query("name")+"[2;37;0mµÄ[1;37m·¨Á¦[2;37;0mĞŞÎªÒÑ´ï"+RANK_D->describe_fali((int)ob->query("max_mana"))+"µÄ¾³½ç¡£\n");   
        write("Ë³·ç¶ú¸æËßÄã£º"+ob->query("name")+"[2;37;0mµÄ[1;31mÄÚÁ¦[2;37;0mĞŞÎªÒÑÓĞ"+RANK_D->describe_neili((int)ob->query("max_force"))+"µÄ»ğºò¡£\n"); 


        message_vision("$NºöÈ»ÄªÃûÆäÃîµØ¶ßàÂÁËÒ»ÏÂ¡£\n",ob); 
        msg="Äã¼±Ã¦ÆşÖ¸Ò»Ëã£¬";
        if(ob->query("daoxing")>me->query("daoxing")/5)
          msg+="Ô­À´ÊÇ[5m[1;32m"+me->name()+"("+me->query("id")+")"+
               "[2;37;0mÕıÔÚ´òÌıÄãµÄµÀĞĞ¡£\n";
        else
          msg+="ĞÄÖĞÈ´Ö»ÊÇÒ»Æ¬Ã£È»¡£[2;37;0m\n";//By tianlin@mhxy for 2001.10.7ÎÒ¸ø¼ÓÉÏÁËÉùÒô
        tell_object(ob, msg);

        return 1;
}

int help(object me)
{
        string desc_dx, desc_fali, desc_exp;

        write(@HELP
Ö¸Áî¸ñÊ½ : check|cha [<Ä³ÈË>]

µØ¶úÁé: ´òÌı±ğÈËÏÖÔÚµÄµÀĞĞ,·¨Á¦¼°Îä¹¦¼¶±ğ¡£

HELP
    );

        write("µÀĞĞ¾³½ç£º\n\n");
        write(RANK_D->query_description(0));
        write("\nÎäÑ§¾³½ç£º\n\n");
        write(RANK_D->query_description(1));
        write("\n·¨Á¦ĞŞÎª£º\n\n");
        write(RANK_D->query_description(2));
        write("\n\n");  
                
    return 1;
}