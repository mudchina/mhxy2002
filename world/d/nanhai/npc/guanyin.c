// guanyin.c ¹ÛÒôÆĞÈø
// By Dream Dec. 19, 1996
//BY tianlin@mhxy for 2002.1.20,ĞŞ¸Ä¼¼ÄÜÈ«²¿»Ö¸´Õı³£
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int rank_me();
int do_drop(object, object);

void create()
{
        set_name("¹ÛÒôÆĞÈø", ({ "guanyin pusa", "guanyin", "pusa" }));
        set("title", "¾È¿à¾ÈÄÑ´ó´È´ó±¯");
        set("long", @LONG
ÀíÔ²ËÄµÂ£¬ÖÇÂú½ğÉí¡£Ã¼ÈçĞ¡ÔÂ£¬ÑÛËÆË«ĞÇ¡£À¼ĞÄĞÀ×ÏÖñ£¬
Ş¥ĞÔ°®µÃÌÙ¡£Ëı¾ÍÊÇÂäÙ¤É½ÉÏ´È±¯Ö÷£¬³±Òô¶´Àï»î¹ÛÒô¡£
LONG);
        set("gender", "Å®ĞÔ");
        set("age", 35);
        set("attitude", "peaceful");
        set("rank_info/self", "Æ¶É®");
        set("rank_info/respect", "ÆĞÈøÄïÄï");
        set("class", "bonze");
        set("str",24);
        set("per",100);
        set("max_kee", 5000);
        set("max_gin", 5000);
        set("max_sen", 5000);
        set("force", 4000);
        set("max_force", 2000);
        set("force_factor", 145);
        set("max_mana", 3000);
        set("mana", 6000);
        set("mana_factor", 150);
        set("combat_exp", 2000000);
        set("daoxing", 10000000);

        set_skill("literate", 180);
        set_skill("spells", 200);
        set_skill("buddhism", 200);
        set_skill("unarmed", 180);
        set_skill("blade", 200);
        set_skill("cibei-dao", 200);
        set_skill("huadao", 200);
        set_skill("jienan-zhi", 200);
        set_skill("dodge", 200);
        set_skill("lotusmove", 200);
        set_skill("parry", 200);
        set_skill("force", 180);
        set_skill("lotusforce", 200);
        set_skill("staff", 200);
          set_skill("lunhui-zhang", 200);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");
        set("inquiry", ([
//        "»ØÈ¥"    : (: kick_back :),
//        "back"  : (: kick_back :),
         "Ö°Î»": (: rank_me :),
      "¾»Æ¿": "Ç°Ğ©Ìì£¬¸£ĞÇ½èÎÒµÄ¾»Æ¿ÓÃ£¬µ½ÏÖÔÚÒ²Ã»ÓĞ»¹£¬ÄãÈ¥¿´¿´°É¡£" ]));

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "bighammer" :),
        }) );
        //hehe, since guanyin was killed several times
        //let's use cast bighammer to protect her...weiqi:)
        create_family("ÄÏº£ÆÕÍÓÉ½", 1, "ÆĞÈø");

        setup();
        carry_object("/d/nanhai/obj/jiasha")->wear();
        carry_object("/d/nanhai/obj/nine-ring")->wield();
}
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "ÆÕÍÓÉ½ºë·¨´óÊ¦")
                return notify_fail("ÄãÒÑ¾­ÊÇÕÆÃÅÈËÁË£¬»¹À´ÒªÊ²Ã´Ö°Î»£®\n");
        if( (string)me->query("family/family_name") == "ÄÏº£ÆÕÍÓÉ½"){
                if( exp <= 100000 ){
                        me->set("title", HIB"ÄÏº£ÆÕÍÓÉ½"HIY"Öª¿ÍĞ¡ºÍÉĞ"NOR);
                 } else if(exp <= 1000000 ){
                        me->set("title", HIB"ÄÏº£ÆÕÍÓÉ½"HIY"½äÂÉÔºÊ××ù"NOR);
                 } else if(exp < 2000000 ){
                        me->set("title", HIB"ÄÏº£ÆÕÍÓÉ½"HIY"ÂŞººÌÃÊ××ù"NOR);
                 } else if(exp < 3000000 ){
                        me->set("title", HIB"ÄÏº£ÆÕÍÓÉ½"HIY"¹ÛÒô»¤·¨"NOR);
                } else {
                        me->set("title", HIB"ÄÏº£ÆÕÍÓÉ½"HIY"åĞÒ£ÆĞÈø"NOR);
                }
                tell_object(me, "¹ÛÒôÆĞÈø¶ÔÄãËµ£ºÄã¿ÉÒÔ×ö"+me->query("title")+"¡£\n");
                tell_room(environment(me),
"¹ÛÒôÆĞÈø¶Ô"+me->query("name")+"Ëµ£ºÄã¿ÉÒÔ×ö"+me->query("title")+"¡£\n", ({me, me}));
         CHANNEL_D->do_channel(me,"chat","ÏÖÊÚÓè±¾ÃÅµÜ×Ó"+me->query("name")+""+me->query("title")+HIC"Ò»Ö°¡£¹§Çë¸÷Î»ÏÉ³¤¶à¼ÓÅõ³¡£¡");
     me->save();  
        }
        return 1;
}

void attempt_apprentice(object ob)
{
        if (!((string)ob->query("bonze/class") =="bonze" )) {
                command("say ÎÒ·ğÃÅÉñÍ¨¹ã´ó£¬" + RANK_D->query_respect(ob) + "Óû³ÉÕı¹û£¬ÏÈÈëÎÒÃÅ¡£\n");
                write("¿´Ñù×Ó¹ÛÒôÆĞÈø¶ÔÄãÎ´Ìê¶È³ö¼ÒÆÄÎª²»¿ì¡£\n");
                return;
        }       
        if (((int)ob->query_skill("buddhism", 1) < 100 )) {
                command("say " + RANK_D->query_respect(ob) + "²»ÔÚ·ğ·¨ÉÏ¿àĞŞ£¬¿ÖÅÂÄÑ³ÉÕı¹û¡£\n");
                return;
        }
        command("pat " + ob->query("id") );
        command("say ºÃ£¡Õâ²ÅÊÇÎÒ·ğÃÅµÄºÃµÜ×Ó¡£Ö»Òª¶à¼ÓÅ¬Á¦£¬¶¨¿ÉÔç³ÉÕı¹û¡£\n");

        command("recruit " + ob->query("id") );
        return; 
}
void die()
{
        int i;
        string file;
        object *inv;

        if( environment() ) {
        message("sound", "\n\n¹ÛÒôÆĞÈøÒ¡Í·Ì¾µÀ£º¸ÕÀëÃÔÕÏ£¬ÓÖÈëÄ§ÕÏ£¬ÊÀ¼ä¼²¿à£¬ºÎÈË¶ÈÖ®£¡\n\n", environment());
        command("sigh");
        message("sound", "\n¹ÛÒôÆĞÈø¼İÏéÔÆ£¬µÇ²ÊÎí£¬¾¶ÍùÎ÷·½È¥ÁË¡£¡£¡£\n\n", environment());
        inv = all_inventory(this_object());
        for(i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("no_drop")) continue;
                do_drop(this_object(), inv[i]);
//              if (stringp(file = find_command("drop")) && 
//                      call_other(file, "do_drop", this_object(), inv[i])) ;
        }
        }

        destruct(this_object());
}

int do_drop(object me, object obj) {
  if (obj->move(environment(me))) {
      //d_mana>0 is for "bian". mon 11/05/97
      if((obj->query_temp("d_mana"))>0) {
            if( obj->query_temp("is_living")==1 )
                 message_vision("$N½«$n´Ó±³ÉÏ·ÅÁËÏÂÀ´£¬ÌÉÔÚµØÉÏ¡£\n", me, obj);
            else {
                 message_vision( sprintf("$N¶ªÏÂÒ»%s$n¡£\n",
                 undefinedp(obj->query_temp("unit"))?
                         "¸ö":obj->query_temp("unit")
                         ), me, obj );
           }
      } else {
           if( obj->is_character() )
                  message_vision("$N½«$n´Ó±³ÉÏ·ÅÁËÏÂÀ´£¬ÌÉÔÚµØÉÏ¡£\n", me, obj);
           else {
             message_vision( sprintf("$N¶ªÏÂÒ»%s$n¡£\n", obj->query("unit")),
                     me, obj );
             if( !obj->query("value") && !obj->value() ) {
                tell_object(me,"ÒòÎªÕâÑù¶«Î÷²¢²»ÖµÇ®£¬ËùÒÔÈËÃÇ²¢²»»á×¢Òâµ½ËüµÄ´æÔÚ
                   ¡£\n");
                destruct(obj);
             }
           }
      }
      return 1;
  }
  return 0;
}

int accept_object(object me,object ob)
{       object who;
        me=this_object();
        who=this_player();
        if (ob->query("id")=="sheng lingzhu" ){
        if(who->query("obstacle/niulang")!="done")
         return 0;
        if(who->query("obstacle/shenglingzhu")=="done") {
                command("say "+RANK_D->query_respect(who)+ "ÒÑÌæÎÒÈ¡»ØÁËÊ¥ÁéÖé£¬ÕæÊÇĞÁ¿àÁË£¡\n");
                call_out("destroy", 1, ob);
 return 1;
        }       
                call_out("announce_success", 3, me, who);
                call_out("destroy", 1, ob);
                return 1;
        }
        return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}
void announce_success(object me,object who)
{//disabled announce and reward...
    int i;
  who->add("obstacle/number",1);
  who->set("obstacle/shenglingzhu","done");
  who->delete_temp("obstacle/shenglingzhu");
  i = random(800);
  who->add("daoxing",i+8000);
  command("chat "+who->query("name")+"ÌæÎÒÈ¡»ØÊ¥ÁéÖé£¬ÕæÊÇ¿ÉÏ²¿ÉºØ£¡");
message("channel:chat",HIY"¡¾¹ı¹ØÕ¶½«¡¿¹ÛÒôÆĞÈø(guanyin pusa)£º"+who->query("name")+"´³¹ıÎ÷ĞĞÈ¡¾­[1;37mµÚÈıÊ®Æß¹Ø£¡\n"NOR,users());//this is by tianlin 2001.5.8
tell_object(who,"ÄãÓ®µÃÁË"+chinese_number(3)+"Äê"+
               chinese_number(i/4)+"Ìì"+
               chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀĞĞ£¡\n");
  who->save();
}


