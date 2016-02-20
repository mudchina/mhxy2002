// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
int do_hesword();

void create()
{
        set_name(HIR"×Ï"HIG"Û«"HIC"½£"NOR, ({ "ziying-sword","sword"})
);
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¶Ô");
                set("unit", "±ú");
  set("long",
"Ò»±ú¹Å½£,½£±úÉÏ¿ÌÓÐ"+MAG"¡¸×ÏÛ«¡¹"NOR+"Á½×Ö,½£ÉíÓÐÒ»²ã×ÏÆøÒþÒþÁýÕÖ.\n");
                set("value", 9000);
//        set("no_give","ÕâÃ´ºÃµÄ±¦Îï£¬¸ø±ðÈË? ÄãÈëµ³ÁËÃ»ÓÐ? \n");
        set("no_drop","ÕâÃ´ºÃµÄ±¦Îï£¬ÄãÈ¥ÈÓ ! Ô­À´³Ô±¥ÁËÃ»ÊÂ¸ÉÑ½ !!!\n");
        set("no_sell", 1);
                set("material", "blacksteel");
set("wield_msg",
MAG"$NÓÒÊÖÎ¢ÕÅ£¬Ò»ÉùÁúÒ÷¹ýºó,×ÏÆø×Ô¶«¶øÀ´,×êÈë$NÓÒÊÖ.\n");

set("unwield_msg","$NÓÒ¼çÇáÒ¡,"+MAG"×ÏÛ«½£"NOR+"±ã×ÔÐÐ·É»ØÇÊÖÐ.\n");
        }
    init_sword(100);
        setup();
}

int init()
{
        add_action("do_hesword", "hesword");
        return 1;
}

 int do_hesword()
{
        object who = this_player();
        object ziyingjian,qingsuojian;
        object doublesword;

        if(who->is_fighting())
           return notify_fail("ÄãÕý´òÕÌÄØ£¡ÏëËÀ°¡£¡\n");
        if(who->is_busy())
           return notify_fail("Äã»¹ÓÐÕâ¹¤·ò?ÕýÃ¦×ÅÄØ!\n");
        if(!ziyingjian = present("ziying-sword",who))
           return notify_fail("Äã»¹È±ÉÙ"+HIM "×ÏÛ«½£" NOR +",ÔõÃ´["+HIR"Ë«½£ºÏ±Ú"NOR+"]ÄØ?\n");
        if(!qingsuojian = present("qingsuo-sword",who))
           return notify_fail("Äã»¹È±ÉÙ"+HIC "ÇàË÷½£" NOR +",ÔõÃ´["+HIR"Ë«½£ºÏ±Ú"NOR+"]ÄØ?\n");
     if( ! who->query("sword_hesword") == 1 ) 
           return notify_fail("Ã»Ñ§Ë«½£ºÏ½£Ö®¼¼ÔõÃ´¸ÒºÏ½£ÄØ?\n");
message_vision("$NÇáÇá½«Ë«½£ºÍÌå,ÏòÉÏÌìÆíµ» !\n\nÍ»È»,Ò»ÉùÁúÒ÷¹ýºó,"+MAG"×ÏÆø"NOR+"×Ô¶«¶øÀ´,×êÈëÄãÓÒÊÖ \nÄãÐÄÄî·½²ÅÒ»¶¯,Ò»Éù·ïÃù¹ýºó,"+HIC"ÇàÆø"NOR+"´ÓÌì¶ø½µ,×êÈëÄã×óÊÖ\n\n½£ÉíÓÐÒ»²ã"+HIC"Çà"NOR+"ÆøÓë"+MAG"×Ï"NOR+"ÆøÒþÒþÁýÕÖ.ÇÒ½¥½¥ÈÚºÍ 
!!\nÒ»ÉùÇáÐ¥,ÄãÊÖÖ.¶à³öÒ»°Ñ"+HBRED"×ÏÇàË«½£\n\n"NOR,who);
        message("channel:rumor",HIR+"¡¾Ò¥ÑÔ¡¿Ä³ÈË£º"+who->query("name")+"ÄÃµ½ ["+HBRED"×ÏÇàË«½£"NOR+HIR"] ÁË£¡\n"+NOR,users() );
      tell_object(who,"Äã²»ÓÉµÃÎ¢Î¢Ò»Ð¦......\n");
         doublesword = new("/d/obj/weapon/sword/doublesword");
       doublesword->move(who);
        destruct(qingsuojian);
        destruct(this_object());
        return 1;
}
 
