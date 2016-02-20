//¸ºÔð´æ·Å¸÷ÃÅÅÉÖ®¼äµÄ¡°ÓÑºÃ¶È¡±¡£
//Qyz
//By tianlin@mhxy for 2002.1.3
#include <ansi.h>

inherit F_SAVE;

#define FAMILY_ENEMY    2
#define FAMILY_FRIEND   1

mapping ALL_FAMILYS=(["·½´çÉ½ÈýÐÇ¶´":1,
                 "ÄÏº£ÆÕÍÓÉ½":1,
                 "ÌìÅîË§¸®":1,//By tianlin@mhxy for 2001.7.2
                 "½«¾ü¸®":1,
                 "Îå×¯¹Û":1,
                 "Îäµ±ÅÉ":1,//By tianlin@mhxy for 2001.9.27
		   "ÎäÊ¥ÃÅ":1,//ÒÑÐÞ¸Ä¹ý
                 "ÊñÉ½ÅÉ":1,//ÒÑ¸üÐÂ
                 "ÉÙÁÖÅÉ":1,//By tianlin@mhxy for 2001.12.13.ÔÚ1ÔÂÖÐÑ®Íê³ÉÖÆ×÷
                 "Éñ½£É½×¯":1,//By tianlin@mhxy for 2001.12.13.
                 "ÑÖÂÞµØ¸®":0,
                 "Ìì¿Õ½ç":0,
                 "ÔÂ¹¬":0,
                 "Áé½ç":0,
                 "¶«º£Áú¹¬":0,
		   "Áú¹¬":0,
                 "ÒÆ»¨¹¬":0,//ÔÚ2001.11ÔÂÇ°Íê³ÉÖÆ×÷
                 "ÅÌË¿¶´":-1,
                 "´óÑ©É½":-1,
                 "Ä§½Ì":-1,
                 "»ðÔÆ¶´":-1,//moyun-shouÔöÇ¿,²¢ÐÞ¸Ä¼ÓÆäpfm 2¸ö
                 "ÐùÔ¯¹ÅÄ¹":-1,//ÐÞ¸ÄÍê±Ï
                 "´äÔÆÉ½°Å½¶¶´":-1,//ÔÝ²»¿ª·Å
                 "ÏÝ¿ÕÉ½ÎÞµ×¶´":-1,
                 "ÂÒÊ¯É½±Ì²¨Ì¶":-1, 
]);

mapping MASTERS=(["·½´çÉ½ÈýÐÇ¶´":"ÆÐÌáÀÏ×æ",
                 "ÄÏº£ÆÕÍÓÉ½":"¹ÛÒôÆÐÈø",
                 "½«¾ü¸®":"ÇØÇí",
                 "Îå×¯¹Û":"ÕòÔª´óÏÉ",
                 "ÑÖÂÞµØ¸®":"ÑÖÂÞÍõ",
                 "ÔÂ¹¬":"æÏ¶ð",
                 "¶«º£Áú¹¬":"°Á¹ã",
                 "´óÑ©É½":"´óÅôÃ÷Íõ",
                 "ÏÝ¿ÕÉ½ÎÞµ×¶´":"ÓñÊó¾«",
                 "ÌìÅîË§¸®":"Öí°Ë½ä",
                 "Îäµ±ÅÉ":"ÕÅÈý·á",
                 "ÎäÊ¥ÃÅ":"¿×Îä´óµÛ",
                 "ÊñÉ½ÅÉ":"½£Ê¥",
                 "Éñ½£É½×¯":"Ð»Ïþ·å",
                 "ÅÌË¿¶´":"×ÏÏ¼ÏÉ×Ó",
                 "»ðÔÆ¶´":"»Æ·É»¢",
                 "ÐùÔ¯¹ÅÄ¹":"æ§¼º",
                 "Áé½ç":"°ËÒ¶µÄÀÏÊ¦",
                 "Ä§½Ì":"ÎÞºÞ",
]);

mapping family;

void create()
{
    seteuid(getuid());
    if ( !restore() && !mapp(family) ){
        family = ([]);
    }
}

int remove()
{
    save();
    return 1;
}

int family_relation(string your_fam,string my_fam )
{
        return ALL_FAMILYS[your_fam]*ALL_FAMILYS[my_fam];
}

string query_save_file() { return DATA_DIR + "familyd"; }

int set_relation(string my_fam, mapping relation)
{
    family[my_fam] = relation;
    save();
    return 1;
}

int add_family_enemy( string my_fam, string name, int score )
{
    if( undefinedp( family[my_fam] ) )
        family[my_fam] = ([ name : score ]);
    if( !undefinedp(family[my_fam][name] ) )
        family[my_fam][name] += score;
    else family[my_fam] += ([ name : score ]);
    save();
    return 1;
}

int remove_family_enemy( string my_fam, string name )
{
    if( undefinedp( family[my_fam] ) ) return 0;
    else if( !undefinedp( family[my_fam][name] ) )
    {
        map_delete(family[my_fam] , name);
        save();
            return 1;
    }
    else return 0;
}

int is_family_enemy( string my_fam, string name )
{
    if( undefinedp( family[my_fam] )) return 0;
    else if( !undefinedp( family[my_fam][name])&&family[my_fam][name]>100)
        return 1;
    else return 0;
}

int query_enemy_quantity( string my_fam, string name )
{
    if( undefinedp( family[my_fam] )) return 0;
    else if( !undefinedp( family[my_fam][name] ) )
        return family[my_fam][name];
    else return 0;
}
        
mapping query_relation(string my_fam)
{
    if ( !undefinedp(family[my_fam]) )
        return family[my_fam];
    else
        return ([]);
}

int deal_family_relation( object victim, object killer )
{
    mapping my_family, your_family;
   
    int c_score, y_relation, m_relation; 
    string my_fam, your_fam, my_id, your_id, declare;

    string* sname;
    int i;

    your_id = killer->query("id");
    if( your_family = killer->query("family") )
    {
        your_fam = your_family["family_name"];
        my_id = victim->query("id");    
        if( !undefinedp(family[your_fam]) &&
        !undefinedp(family[your_fam][my_id]) )
        {
            killer->add("daoxing" , (victim->query("daoxing")/100) );
            {
                declare = sprintf("[33m%s[37mÉ±ËÀ±¾ÃÅ³ðµÐ[32m%s[m£¬ÕæÄË´ó¿ìÈËÐÄ¡£\n",
                                killer->name(1), victim->name(1) );
                message("channel:chat",GRN+MASTERS[your_fam]+declare+NOR,users());
            }
            map_delete(family[your_fam] , my_id );
            return 1;
        }

        if( my_family = victim->query("family") )
        {
            my_fam = my_family["family_name"];
            c_score = victim->query("faith");
            if( my_fam == your_fam )
            {
                killer->add("daoxing", -(victim->query("daoxing")/100));
                if(c_score > 30 )  
                {
                    declare = sprintf("[32m%s[37m²»¿ÉÔÙÍÀÂ¾±¾ÃÅÊ¦ÐÖµÜ£¬ÇÐ²»¿ÉÎÑÀï·´£¡¡£\n", killer->name(1) );
                    message("channel:chat",GRN+MASTERS[your_fam]+declare+NOR,users());                    
                }     
                return 1;                                             
            }
            else
            {    
                if( userp( killer ) )
                    add_family_enemy( my_fam, your_id, c_score );
                if( y_relation = family_relation( your_fam, my_fam ) )
                {                                           
                    if( y_relation == FAMILY_ENEMY )
                    {
                        killer->add("daoxing" , (victim->query("daoxing")/100) );
                        killer->add("relation/"+my_fam,c_score/100);
                        sname=keys(ALL_FAMILYS);
                        if(c_score > 30 )
                        {
                            declare = sprintf("[32m%s[37mÉ±ËÀÁË±¾ÃÅ¶ÔÍ·[33m%s[37mµÄ[35m%s£¬[m¹¦µÂÎÞÁ¿Ò²£¡\n",
                                    killer->name(1), my_fam, victim->name(1) );
                            message("channel:chat",GRN+MASTERS[your_fam]+declare+NOR,users());                            
                        }
                    }
                    else if( y_relation == FAMILY_FRIEND )
                    {
                        killer->add("daoxing" , (victim->query("daoxing")/100) );
                        killer->add("relation/"+my_fam,-c_score/100);       
                        if(c_score > 30 )
                        {
                            declare = sprintf("[0;37m±¾ÃÅµÜ×ÓÓ¦¸ÃÓë[33m%s[37mµÄµÜ×ÓºÍÄÀÏà´¦£¬²»Ó¦»¥ÏàÉ±Â¾¡£\n",
                                        my_fam );
                            message("channel:chat",GRN+MASTERS[your_fam]+declare+NOR,users());
                        }
                    }
                }
                if( m_relation = family_relation( my_fam, your_fam ))
                {
                    if( m_relation == FAMILY_ENEMY )
                    declare = sprintf("[0;37m±¾ÃÅÓë[32m%s[mÊÆ²»Á½Á¢£¬µÜ×ÓÃÇÒªÇÐ¼Ç³ðºÞ°¡£¡\n",
                                        your_fam );
                    else
                    declare = sprintf("[0;37m±¾ÃÅ[31m%s[37m±»[33m%s[37mµÄ[32m%s[37mÉ±ËÀÁË£¬Í¬ÃÅµÜ×Ó½ÔÓ¦ÒÔ±¨³ðÎª¼ºÈÎ£¡\n",
                                    victim->name(1), your_fam, killer->name(1) );
           
                    message("channel:chat",GRN+MASTERS[my_fam]+declare+NOR,users());
                }
                return 1;                                              
            }             
        }
        else return 0;
    }
    else if( my_family = victim->query("family") )                   
    {
        my_fam = my_family["family_name"];
        c_score = victim->query("faith");
        if( userp(killer) )
            add_family_enemy( my_fam, your_id, c_score );
       killer->add("relation/"+my_fam,c_score/100);
        {
            declare = sprintf("[0;37m±¾ÃÅµÜ×Ó±»[32m%s[37mÉ±ËÀÁË¡£\n", killer->name(1) );
            message("channel:chat",GRN+MASTERS[my_fam]+declare+NOR,users());
        }
        return 1;
    }
    else return 0;
}

void clear_all_family_relation( string id )
{
    int i;
    string *familys = keys(ALL_FAMILYS);
    for( i = 0; i<sizeof(familys); i++ )
    {
        if( undefinedp( family[familys[i]] ) ||
            undefinedp( family[familys[i]][id] ) )
        continue;
        map_delete( family[familys[i]], id );
    }
}
 
