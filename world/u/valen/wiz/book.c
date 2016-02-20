//by tianlin 2001.5.1
//ÓĞÒ»¸öÖ¸ÁîÎÒÒÑĞŞ¸Ä¹ı.¾ÍbiguÕâ¸öÖ¸Áî,ÎÒÒÑ¼ÓÈëÔÚxfullÀïÃæÁË.
#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;


void create()
{
        set_name(WHT"¸ñ¶·Ö®ÍõÈ«¼¯"NOR, ({"book"}) );
        set_weight(10);
        set("no_steal", 1);
        set("no_beg", 1);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_get", 1);
        set("no_drop","ÍÛ£¿ÌìÊé¶¼Ïë¶ªµô,Ğ¡ĞÄÔâÌìÇ´¡£\n\n");
        set("long",@LONG
ÕâÊÇ°ËÉñâÖÁôÏÂÀ´µÄÒ»±¾Êé,Æä×÷ÓÃ¿É´óÁË,ÓĞÒâÕßÇë(kan)¾ÍĞĞÁË!
LONG );
        if( clonep() )
                        set_default_object(__FILE__);
        else
       {
                set("unit", "±¾");
                set("material", "unknow");
        }
}

void init()
{
        add_action( "kan_book", "kan" );
        add_action( "body_recover", "xfull");
        add_action( "cloud_goto", "flyto");
}

/* int query_autoload()
{
        return 1;
}*/

//½éÉÜ
int kan_book()
{
        object me;
        me=this_player();
        tell_object(me,
    "·¨¾÷ö                    ¹¦ÄÜ

Ò»Ç§°Ù°ËÊ½°ËÖ¯Å®(xfull)           Á¢Âí»Ö¸´¾«ÉñÌåÁ¦\n

½î¶·ÔÆ(flyto)         µ½ÏëÈ¥µÄµØ·½\n");
        return 1;
}

// ½î¶·ÔÆ

int cloud_goto(string arg)
{
        string home;
        object mme;
        int goto_inventory = 0;
        object obj;
        string msg;
        mme=this_player();
        if( !arg ) return notify_fail("ÄãÒªÈ¥ÄÄÀï£¿\n");

        if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

        if( !arg ) return notify_fail("ÄãÒªÈ¥ÄÄÀï£¿\n");

        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
        if(!obj || !mme->visible(obj)) {
                arg = resolve_path(mme->query("cwd"), arg);
                if( !sscanf(arg, "%*s.c") ) arg += ".c";
                if( !(obj = find_object(arg)) ) {
                        if( file_size(arg)>=0 )
                                return mme->move(arg);
                        return notify_fail("Ã»ÓĞÕâ¸öÍæ¼Ò¡¢ÉúÎï¡¢»òµØ·½¡£\n");
                }
        }

        if(!goto_inventory && environment(obj))
                obj = environment(obj);

        if( !obj ) return notify_fail("Õâ¸öÎï¼şÃ»ÓĞ»·¾³¿ÉÒÔ goto¡£\n");
        tell_object(mme,HIM"ÄãÒ»¸ö½î¶·´ÜÏò¿ÕÖĞ,Ö»¼ûÑÛÇ°ºìÔÆ·É¹ı,¶ú±ß·çºôºô×÷Ïì .
.\n\n"NOR);
        tell_object(mme,"ÍÛà¸,ºÃÍ´¿ì,ºÃË¬,Ë¬ÍáÍá!\n\n");
        mme->move(obj);

        tell_object(mme,"Äã¼İ×ÅÔÆ»º»ºÏÂ½µ,°Èß´Ò»Éù,ºÙ!°²È«×ÅÂ½...\n");
        return 1;
}
// »Ö¸´
int body_recover()
{
    object mme;
    mme=this_player();
    mme->set("sen",mme->query("max_sen"));
    mme->set("eff_sen",mme->query("max_sen"));
    mme->set("kee",mme->query("max_kee"));
    mme->set("eff_kee",mme->query("max_kee"));
    mme->set("force",mme->query("max_force"));
    mme->set("mana",mme->query("max_mana"));
    mme->set("food",mme->max_food_capacity()*2);
    mme->set("water",mme->max_water_capacity()*2);
    tell_object(mme,"ÍÛà¸,Ì«ºÃÁË,Äã¾õµÃÈ«Éí¶¼ÊÇ[5m[1;36mÁ¦Á¿![2;37;0m\n");
    return 1;
}
void owner_is_killed() {

        write(HIY"Ö»¼ûÑÛÇ°½ğ¹âÒ»ÉÁ...ºÃÏóÊÇ.....\n"NOR);
        destruct(this_object());
}
