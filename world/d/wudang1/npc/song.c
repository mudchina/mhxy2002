//by elva@mhxy and tianlin@mhxy 2001.9.30

inherit NPC;
inherit F_MASTER;
int rank_me();
string ask_me();
string ask_for_leave();
#include <ansi.h>

void create()
{
	set_name("ËÎÔ¶ÇÅ", ({ "song yuanqiao", "song" }));
	set("nickname", "[1;37mÎäµ±[1;31mÊ×ÏÀ[2;37;0m");
	set("long", 
		"Ëû¾ÍÊÇÕÅÈı·áµÄ´óµÜ×Ó¡¢Îäµ±ÆßÏÀÖ®Ê×µÄËÎÔ¶ÇÅ¡£\n"
		"Éí´©Ò»¼ş¸É¸É¾»¾»µÄ»ÒÉ«µÀÅÛ¡£\n"
		"ËûÒÑÄê¹ıÁùÊ®£¬Éí²ÄÊİ³¤£¬ÂúÁ³ºì¹â¡£Ìñµ­³åºÍ£¬³ÁÄ¬¹ÑÑÔ¡£\n");
	set("gender", "ÄĞĞÔ");
	set("age", 61);
	set("attitude", "peaceful");
	set("class", "wudang");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_kee", 3000);
	set("max_sen", 3000);
	set("force", 5000);
	set("max_force", 2000);
	set("mana", 5000);
	set("max_mana", 2000);
	set("jiali", 50);
	set("combat_exp", 350000);
	set("daoxing", 1110000);

	set_skill("force",130);
set_skill("wudang-force", 150);
	set_skill("dodge", 130);
        set_skill("wudang-xianfa", 130);
        set_skill("spells", 130);
	set_skill("tiyunzong", 130);
	set_skill("unarmed", 120);
	set_skill("taiji-quan", 120);
	set_skill("parry", 120);
	set_skill("sword", 130);
	set_skill("taiji-jian", 140);
	set_skill("wudang-jian", 130);
	set_skill("literate", 110);

	map_skill("force", "wudang-force");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("Îäµ±ÅÉ", 2, "µÜ×Ó");
        set("inquiry", ([
              "leave" : (: ask_for_leave :),
              "Ö°Î»": (: rank_me :),
		"ÃØ¼®" : (: ask_me :),
                ]) );
create_family("Îäµ±ÅÉ", 2, "µÜ×Ó");
setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang1/obj/greyrobe")->wear();
}
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "Îäµ±ÅÉÕÆÃÅ")
		return notify_fail("ÄãÒÑ¾­ÊÇÕÆÃÅÈËÁË£¬»¹À´ÒªÊ²Ã´Ö°Î»£®\n");
        if( (string)me->query("family/family_name") == "Îäµ±ÅÉ"){
                if( exp <= 100000 ){
                        me->set("title", HIY"Îäµ±ÅÉ"NOR+HIR"ÊØÉ½µÀÍ¯"NOR);
                  } else if(exp <= 1000000 ){
                        me->set("title", HIY"Îäµ±ÅÉ"NOR+HIR"ĞşºüµÀ³¤"NOR);
                  } else if(exp <= 2000000 ){
                        me->set("title", HIY"Îäµ±ÅÉ"NOR+HIR"½µÑıµÀÊ¿"NOR);
                  } else if(exp <= 3000000 ){
                        me->set("title", HIY"Îäµ±ÅÉ"NOR+HIR"åĞÒ£ÕæÈË"NOR);
                } else {
                        me->set("title", HIY"Îäµ±ÅÉ"NOR+HIR"ÌìÍõÀÏ×æ"NOR);
                }

                tell_object(me, "ËÎÔ¶ÇÅ¶ÔÄãËµ£ºÄã¿ÉÒÔ×ö"+me->query("title")+"¡£\n");
                tell_room(environment(me),
"ËÎÔ¶ÇÅ¶Ô"+me->query("name")+"Ëµ£ºÄã¿ÉÒÔ×ö"+me->query("title")+"¡£\n", ({me, me}));
CHANNEL_D->do_channel(me,"chat","ÏÖÊÚÓè±¾ÃÅµÜ×Ó"+me->query("name")+""NOR+me->query("title")+NOR+HIC"Ò»Ö°¡£¹§Çë¸÷Î»ÏÉ³¤¶à¼ÓÅõ³¡£¡");
     me->save();  
        }
        return 1;
}
void attempt_apprentice(object ob)
{

        if( (string)ob->query("family/family_name")=="Îäµ±ÅÉ" ){
                if( (int)ob->query("family/generation") < 2  ){
                        command("say ²»¸Ò£¬²»¸Ò¡£ÎÒ¸Ã°İ" + RANK_D->query_respect(ob) + "ÄúÎªÊ¦²ÅÊÇ¡£\n");
                }
                else if( (int)ob->query("family/generation") ==2  ){
                        command("say ÄãÕâ¸ö" + RANK_D->query_rude(ob) + "±ğÀ´ÏûÇ²Äã¼ÒÒ¯Ò¯ÎÒÁË£¡\n");
                }
                else if( (int)ob->query("family/generation") ==3  ){
                        command("hoho ");
                        command("say ºÃ°É£¬Æ¶µÀ¾ÍÊÕÏÂÄãÁË¡£");
                        command("recruit " + ob->query("id") );
                        message("system", HIY"ÎÒÎäµ±ÅÉÓÖ¶àÁËÒ»¸öµÜ×Ó  "+this_player()->name()+HIW"
                 Îäµ±ÅÉµÄÊÆÁ¦¼ÓÇ¿ÁË¡£\n"NOR,users());
                }
                else {
                        if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 200000 ){
                                command(":) ");
                                command("say ºÃ£¬" + RANK_D->query_respect(ob) + "¼ÈÈ»µ½ÎÒÃÅÏÂ¾ÍµÃ¸øÎÒÕùÆø£¬¿É²»ĞíÍµÀÁ£¡\n");
                                command("recruit " + ob->query("id") );
                        }
                        else {
                                command("say Äã»¹ÊÇÕÒ±ğÈËÏÈÁ·×Å°É¡£\n");
                        }
                }
        }

        else{
                command("hmm");
                command("say ÕâÎ»" + RANK_D->query_respect(ob) + "£¬Äã»¹ÊÇÕÒ±ğÈËÏÈÁ·Á·°É¡£\n");
        }

        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wudang");
                ob->set("title", "[1;33mÎäµ±ÅÉ[1;37mµÚ[1;36mÈı[1;37m´úµÜ×Ó[2;37;0m");
}
void init()
{
        add_action("do_agree", "agree");
}

string ask_for_leave()
{
        object me=this_player();

        if (me->query("family/family_name") == "Îäµ±ÅÉ" ) {
                command("say Äã¼ÈÊÇÖ´ÒâÏÂÉ½£¬Æ¶µÀÈ´ÓĞ¼¸¾ä»°Ëµ¡£");
                me->set_temp("betray", 1);
                return ("ÍÑÀëÊ¦ÃÅÒªĞèÒªÓĞÒ»¶¨³Í·££¬Äã¿ÉÔ¸Òâ(agree)£¿");
        }

        return ("ÀÏĞà²»Öª¡£\n");
}
int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N´ğµÀ£ºµÜ×ÓÔ¸Òâ¡£\n\n", this_player());
                command("say ¼ÈÊÇÄãÓëÎäµ±ÅÉÎŞÔµ£¬Äã±ãÏÂÉ½°É£¡");
                this_player()->add("betray/count", 1);
                this_player()->add("betray/moon", 1);
                this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
                this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
                if( this_player()->query_skill("wudang-force") )
                    this_player()->delete_skill("taiji-jian");
                if( this_player()->query_skill("wudang-jian") )
                    this_player()->delete_skill("taiji-quan");

                
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "ÆÕÍ¨°ÙĞÕ");
                this_player()->set_temp("betray", 0);
                this_player()->save();
                command("say ½­ºş·ç²¨£¬ÉÆ¶ñÎŞĞÎ£¬ºÃ×ÔÎªÖ®¡£¡£¡£\n");
                return 1;
        }
}
string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "Îäµ±ÅÉ")
		return RANK_D->query_respect(this_player()) + 
		"Óë±¾ÅÉËØÎŞÀ´Íù£¬²»Öª´Ë»°´ÓºÎÌ¸Æğ£¿";
	if (query("book_count") < 1)
		return "ÄãÀ´ÍíÁË£¬±¾ÅÉµÄÄÚ¹¦ĞÄ·¨²»ÔÚ´Ë´¦¡£";
	add("book_count", -1);
	ob = new("/d/wudang1/obj/force_book");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"ÄÃµ½Ì«¼«Ê®ÈıÊ½À²¡£\n");
	return "ºÃ°É£¬Õâ±¾¡¸Ì«¼«Ê®ÈıÊ½¡¹ÄãÄÃ»ØÈ¥ºÃºÃ×êÑĞ¡£";
}
