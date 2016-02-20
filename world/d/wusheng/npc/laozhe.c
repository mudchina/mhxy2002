// laozhe.c

#include <ansi.h>

inherit NPC;
int rank_me();
string ask_mieyao(object me);
string ask_cancel();

void create()
{
       set_name(HIG"ÀÏÕß"NOR, ({"lao zhe", "laozhe"}));
       set("long", "Ò»¸öÓÆÏĞµÄÀÏÈË¼Ò£¬×øÔÚÊ÷ÏÂ³ËÁ¹¡£\n");
       set("title", HIC"ÎäµÛÃÅ"NOR);
       set("gender", "ÄĞĞÔ");
       set("age", 1000);
       set("class", "wusheng");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "»¤·¨");
       set("looking", "Ó¢¿¡äìÈ÷£¬ÓñÊ÷ÁÙ·ç£¬·çÁ÷ÙÃÙÎ¡£");
       set("max_kee", 1000);
       set("max_gin", 100);
       set("max_sen", 1000);
       set("force", 1000);
       set("max_force", 500);
       set("force_factor", 10);
       set("max_mana", 500);
       set("mana", 1000);
       set("mana_factor", 10);
       set("combat_exp", 500000);
       set("daoxing", 1100000);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("spells", 100);  
        set_skill("feisheng", 100);
        set_skill("literate", 100);
        set_skill("sword", 100);  
        set_skill("wuying", 100);
        set_skill("fumobashi", 100);  
        set_skill("mizongbu", 100);
        set_skill("dodge", 100);  
        set_skill("force", 100);   
        set_skill("xiantian", 100);

        map_skill("spells", "feisheng");
        map_skill("unarmed", "fumobashi");
        map_skill("force", "xiantian");
        map_skill("sword", "wuying");
        map_skill("parry", "wuying");
        map_skill("dodge", "mizongbu");
        create_family("ÎäÊ¥ÃÅ", 2, "µÜ×Ó");

   set("inquiry", ([
//          "¸´³ğ" : (: avenge :),
//		  "×íÉúÃÎËÀ" : (: give_zui :),
           "ĞŞÁ¶": (: ask_mieyao :),
           "cancel": (: ask_cancel :),
		   "Ö°Î»": (: rank_me :),
]));
	setup();
	carry_object("/d/obj/armor/jinjia")->wear();

}
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "ÕÆÃÅ")
		return notify_fail("ÄãÒÑ¾­ÊÇÕÆÃÅÈËÁË£¬»¹À´ÒªÊ²Ã´Ö°Î»£®\n");
        if( (string)me->query("family/family_name") == "ÎäÊ¥ÃÅ"){
                if( exp <= 100000 ){
                        me->set("title", WHT"ÎäÊ¥ÃÅ"HIG"ĞŞÎäÕß"NOR);
                 } else if(exp < 1000000 ){
                        me->set("title", WHT"ÎäÊ¥ÃÅ"HIG"ÉñÁ¦ÂŞºº"NOR);
                 } else if(exp < 2000000 ){
                        me->set("title", WHT"ÎäÊ¥ÃÅ"HIG"»¤ÅÉ½ğ¸Õ"NOR);
                 } else if(exp < 3000000 ){
                        me->set("title", WHT"ÎäÊ¥ÃÅ"HIG"ÉñÎäÌì×ğ"NOR);
                } else {
                        me->set("title", WHT"ÎäÊ¥ÃÅ"HIG"°Á½£Ìì»Ê"NOR);
                }

                tell_object(me, "ÀÏÕß¶ÔÄãËµ£ºÄã¿ÉÒÔ×ö"+me->query("title")+"¡£\n");
                tell_room(environment(me),
"ÀÏÕß¶Ô"+me->query("name")+"Ëµ£ºÄã¿ÉÒÔ×ö"+me->query("title")+"¡£\n", ({me, me}));
         CHANNEL_D->do_channel(me,"chat","ÏÖÊÚÓè±¾ÃÅµÜ×Ó"+me->query("name")+""+me->query("title")+"Ò»Ö°¡£¹§Çë¸÷Î»ÏÉ³¤¶à¼ÓÅõ³¡£¡");
     me->save();  
        }
        return 1;
}
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("Ã»ÓÃµÄ¶«Î÷£¡");
}
else
{
     return ("ÄãÓĞÈÎÎñÂğ£¿£¡");
}
}
string ask_mieyao(object me)
{
    me=this_player();
     if((string)me->query("family/family_name")=="ÎäÊ¥ÃÅ") {
    tell_room(environment(me),"ÀÏÕßËµµÀ.....\n");
    return "/d/obj/mieyao"->query_yao(me);
}
     return ("ÀÏ·ò²»ÖªµÀÄãÔÚËµĞ©Ê²Ã´¡£");
}


ÿ
