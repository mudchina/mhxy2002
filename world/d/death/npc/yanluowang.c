//Cracked by Roath
// by happ@ys

#include <ansi.h>

inherit "/d/dntg/hell/wang.c";
//inherit NPC;
inherit F_MASTER;
string renru_me();
int send_me();
int work_me();
int rank_me();
string expell_me(object me);
string check_book();
int zhua_gui();
string ask_cancel();
string obstacle_sc();

void create()
{
       set_name("ÑÖÂŞÍõ", ({"yanluo wang","wang", "master", "yanluo"}));
       set("long", "Éí´©´óºìòşÅÛ£¬Í·´÷ºÚ³ñÈí½í£®
ÃæÈç¹øµ×£¬ĞëÈô¸ÖÕë£¬Õâ¾ÍÊÇÑÖÂŞÍõ£®\n");
       set("title", HIB"Òõ¼ä"HIY"Ê®ÍõÖ®"NOR);
        set("class", "youling");
       set("gender", "ÄĞĞÔ");
       set("age", 50);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("per", 10);
       set("max_kee", 1100);
       set("max_gin", 1100);
       set("max_sen", 1100);
       set("force", 1150);
       set("max_force", 1000);
       set("force_factor", 60);
       set("max_mana", 1500);
       set("mana", 1500);
       set("mana_factor", 50);
       set("combat_exp", 1000000);
       set("daoxing", 3000000);

        set_skill("jinghun-zhang", 150);
        set_skill("tonsillit", 100);
        set_skill("gouhunshu", 150);
       set_skill("unarmed", 150);
        set_skill("whip", 180);
        set_skill("sword", 150);
        set_skill("hellfire-whip",180);
        set_skill("zhuihun-sword", 150);
       set_skill("dodge", 120);
        set_skill("ghost-steps", 150);
       set_skill("parry", 150);
        set_skill("spells", 150);
        set_skill("force", 150);
        map_skill("sword", "zhuihun-sword");
        map_skill("parry", "zhuihun-sword");
        map_skill("dodge", "ghost-steps");
        map_skill("unarmed", "jinghun-zhang");
        map_skill("force", "tonsillit");
        map_skill("whip", "hellfire-whip");
        map_skill("spells", "gouhunshu");

        set("nk_gain", 500);

        set_temp("apply/armor", 50);
        set_temp("apply/dodge", 50);

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: exert_function, "sheqi" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: cast_spell, "gouhun" :)
        }) );

set("inquiry", ([
"cancel" :(: ask_cancel :),
"»¹Ñô": (: expell_me :),
"leave": (: expell_me :),
"ÈÌÈèÉñ¹¦": (: renru_me :),
"ºË¶ÔÉúËÀ²¾" : (: check_book :),
"watch":(:send_me:),
"Ê®°Ë²ãµØÓü":(: work_me :),
"18": (: work_me :),
"×¥¹í" : (: zhua_gui :),
"name": "ºß£¡Á¬ÀÏ·ò¶¼²»ÈÏµÃ£¬ÏëÀ´ÊÇ»îµÄÌ«¾ÃÁË£¡\n",
"here": "Õâ±ãÊÇÑÖÂŞµØ¸®£¬µ½Ñô¼äÒ»Ì¸£¬ºÙºÙ£¬Ã»ÈË²»ÅÂ£¡\n",
"Ñô¼ä": "ÈËËµÒõÑôÊâÍ¾£¬ÆäÊµ²»È»£¬ÒõÑô¼äÓĞÎåµãÏà½»£¬À´È¥ÏàÍ¨£¡\n",
"Îåµã": "¹ş¹ş£¬ÒªËµÖªµÀµÄÈËÈ´Ò²²»¶à£¬ÄÇ±ãÊÇÄê£¬ÔÂ£¬ÈÕ£¬Ê±ºÍ³¤°²ãşË®ÇÅ£¡\n",
"Áõ¸¸": (: obstacle_sc :),
"Áõ²®ÇÕµÄ¸¸Ç×": (: obstacle_sc :),
"Ö°Î»": (: rank_me :),
]) );


create_family("ÑÖÂŞµØ¸®", 2, "ÄãºÃ");
setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}
string obstacle_sc()
{
        object me = this_player();
        int i;
        if( me->query("obstacle/sc") == "done" )
        return("ÎÒ²»Ì«Çå³ş¡£\n");
                
        if( ! me->query_temp("can_ask") )
          return("ÎÒ²»Ì«Çå³ş¡£\n");

  i = random(600);
  me->add("obstacle/number",1);
  me->set("obstacle/sc","done");
    me->add("daoxing",i+8000);
  command("chat "+me->query("name")+"Ë«²æÆÂÃğ»¢£¬³¬¶ÈÁõ¸¸Áé»êÏÔ¹¦ÀÍ£¡");
message("channel:chat",HIY"¡¾¹ı¹ØÕ¶½«¡¿¹ÛÒôÆĞÈø(guanyin pusa)£º"+me->query("name")+"´³¹ıÎ÷ĞĞÈ¡¾­[1;37mµÚ¶ş¹Ø£¡\n"NOR,users());
  me->save();
  return("ÄãÓ®µÃÁË"+chinese_number(4)+"Äê"+
               chinese_number(i/4)+"Ìì"+
               chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀĞĞ£¡\n");

}
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "´óÁ¦¹íÍõ")
		return notify_fail("ÄãÒÑ¾­ÊÇÕÆÃÅÈËÁË£¬»¹À´ÒªÊ²Ã´Ö°Î»£®\n");
        if( (string)me->query("family/family_name") == "ÑÖÂŞµØ¸®"){
                if( exp <= 100000 ){
                        me->set("title", CYN"ÑÖÂŞµØ¸®"HIR"¹´»êĞ¡¹í"NOR);
                 } else if(exp <= 1000000 ){
                        me->set("title", CYN"ÑÖÂŞµØ¸®"HIR"±äÌìÎŞ³£"NOR);
                  } else if(exp < 2000000 ){
                        me->set("title", CYN"ÑÖÂŞµØ¸®"HIR"ÑªÊÖÍÀ·ò"NOR);
                  } else if(exp < 3000000 ){
                        me->set("title", CYN"ÑÖÂŞµØ¸®"HIR"ĞşÌì¹íÍõ"NOR);
                } else {
                        me->set("title", CYN"ÑÖÂŞµØ¸®"HIR"ÒõË¾Ö®Ö÷"NOR);
                }

                tell_object(me, "ÑÖÂŞÍõ¶ÔÄãËµ£ºÄã¿ÉÒÔ×ö"+me->query("title")+"¡£\n");
                tell_room(environment(me),
"ÑÖÂŞÍõ¶Ô"+me->query("name")+"Ëµ£ºÄã¿ÉÒÔ×ö"+me->query("title")+"¡£\n", ({me, me}));
         CHANNEL_D->do_channel(me,"chat","ÏÖÊÚÓè±¾ÃÅµÜ×Ó"+me->query("name")+""NOR+me->query("title")+HIC"Ò»Ö°¡£¹§Çë¸÷Î»ÏÉ³¤¶à¼ÓÅõ³¡£¡");
     me->save();  
        }
        return 1;
}
void attempt_apprentice(object ob, object me)
{
        if ( (string)ob->query("family/family_name")=="ÑÖÂŞµØ¸®") {
        if (((int)ob->query("combat_exp") < 50000 )) {
        command("say " + RANK_D->query_rude(ob) + "²»µàµà½ïÁ½£¬ÀÏ×ÓÃ»¿Õ½ÌÄã£¡\n");
        return;
        }
        command("grin");
        message_vision("ÑÖÂŞÍõ¶Ô$NºÙºÙµØĞ¦ÁË¼¸Éù¡£\n", ob);
        message_vision("ÑÖÂŞÍõÅÄÅÄ$NµÄ¼ç°òËµµÀ£ºÒÔºóÔÚÕâÀï¶àÓÃ¹¦£¬³ÙÔçÓĞ³öÍ·µÄÈÕ×Ó£¡\n", ob);
       command("recruit " + ob->query("id") );
        return;
        }
        message_vision("ÑÖÂŞÍõ¶Ô$NºÈµÀ£ºÄãÊÇÄÇÀïÀ´µÄÃ«Ôô£¬¸ÒÅÜµ½±¦µîÉÏÈöÒ°£¡ÓëÎÒºå³öÈ¥£¡\n", ob);
        message_vision("ÅÜ½øÀ´Á½¸öÇàÃæĞ¡¹í°Ñ$NÍÏÁË³öÈ¥¡£\n", ob);
        ob->move("/d/death/new-walk5");//by tianlin@mhxy for 2001.12.30
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
}


int accept_fight(object me)
{
        command("say " + "¹ş¹ş£¡ÑÖÍõ²»½Ğ£¬×Ô¼ºÉÏÃÅ£¡\n");
        return 1;
}
string expell_me(object me)
{       
        me=this_player();
        if((string)me->query("family/family_name")=="ÑÖÂŞµØ¸®") {
                message_vision("ÑÖÂŞÍõºú×Ó¶¶¶¶£¬ºÃÏñ·Ç³£ÉúÆø¡£\n", me);
                me->set_temp("betray", 1);
                message_vision("ÑÖÂŞÍõ¶Ô$NÈÂÈÂ×Å£ºĞ¡¶«Î÷£¬ÄãËµ»°ÊÇÕæĞÄ»°(true)£¿\n", me);
                return ("ÆøËÀÎÒÁË£¬ÆøËÀÎÒÁË£¡\n");
        }
        return ("ÎÊÊ²Ã´ÎÊ£¡×Ô¼ºÏëÈ¥£¡\n");
}
void init()
{
        add_action("do_true", "true");
        ::init();
}

int do_true(string arg)
{

        if(this_player()->query("family/family_name") != "ÑÖÂŞµØ¸®" )
                return 0;
        if(this_player()->query_temp("betray")) {
                message_vision("$N´ğµÀ£ºµÜ×Ó½²µÄÕæĞÄ»°£¡\n\n", this_player());
                message_vision("ÑÖÂŞÍõÌ¾ÁË¿ÚÆø£¬¼ÈÊÇÈç´Ë£¬Äã±ã»¹ÑôÈ¥°É£¡\n", this_player());
                this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
                this_player()->add("betray/count", 1);
                this_player()->add("betray/hell", 1);
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "ÆÕÍ¨°ÙĞÕ");
                 this_player()->set("faith",0);
                this_player()->set_temp("betray", 0);
                this_player()->save();
                message_vision("ÑÖÂŞÍõÉì³öÊÖ½«$NÒ»ÍÆ£¬$N»¯×÷Ò»¹ÉÇàÑÌÏò¶«¶øÈ¥¡£¡£¡£\n", this_player());
                this_player()->move("/obj/void");
                tell_room( environment(this_player()),"·¿ÁºÉÏàÛàÛàÂàÂ¼¸ÉùÏì£¬µôÏÂ¸öÈËÀ´£¡\n", ({this_player()}));
                this_player()->unconcious();            
                return 1;
                }
        return 0;
}

int zhua_gui()
{
        object ghost;
        object me = this_player();
        string* dirs;

        dirs = ({"/d/changan/","/d/city/","/d/gao/", "/d/jjf/",
"/d/lingtai/", "/d/meishan/","/d/moon/", "/d/nanhai/", "/d/penglai/",
"/d/sea/", "/d/xueshan/", "/d/qujing/nuerguo/",
"/d/qujing/wudidong/", "/d/qujing/firemount/"});

        seteuid(getuid());

        if( (string)me->query("family/family_name")!="ÑÖÂŞµØ¸®" ) {
                message_vision("$NĞ±Ğ±µÄÆ³ÁË$nÒ»ÑÛ£¬ÀäĞ¦µÀ£º¾ÍÄã£¬ºÃĞ¦ºÃĞ¦¡£¡£¡£\n", this_object(), me);
                return 1;
                }
        if( time() - me->query("last_time/zhuagui") < 120 )
                {
                command("say ÓĞÀÍÁË,ÄãÏÈÈ¥ĞİÏ¢ĞİÏ¢°É\n");
                return 1;
                }
if( me->query("faith") > 800|| me->query("combat_exp") > 500000 )
                {
                command("say ²»¸ÒÀÍÄú´ó¼İ£¡\n");
                return 1;
                }                
            if( ! me->query("Hell_Job/done")&& me->query("Hell_Job/time_start") )
                {
                command("say ÕâµãÊÂÇé¶¼°ì²»ºÃ£¬ÕæÊÇ¸ö·¹Í°£¬¹ı»áÔÙÀ´°É¡£\n");
            call_out("cancel",120 ,me);
                return 1;
                }

        ghost = new("/obj/npc/ghost");
        ghost->move("/obj/void");
        ghost->invocation(me, dirs);
        command("consider"); 
        command("say ¾İ´ŞÅĞ¹ÙËµ£¬ÅÜÁË¸öÀÎÖĞ¶ñ¹í£¬´ó¸ÅÔÚ¸½½ü£¬Ê¹ÓÃ cast xunguiºÍ cast yinyang °ÑËû×¥»ØÀ´.\n");
        me->set("Hell_Job/time_start", time());
        me->delete("Hell_Job/done");
        me->set("last_time/zhuagui",time());
        return 1;
}
void cancel(object me)
{
        me->set("Hell_Job/done",1);
}

int send_me()
{
        object who;
        who=this_player();
        message_vision("$N¶Ô$nµãÁËµãÍ·£¬µÀ£ºÊÇÄã×Ô¼ºÒªÈ¥£¬»Ø²»À´±ğÔ¹ÎÒ¡£\n",this_object(),who);
        who->move("/d/death/emptyroom");
        return 1;
}
string renru_me()
{
        object me;
        int myskill;
        me=this_player();
        myskill=me->query_skill("zhuihun-sword",1);
        if(me->query("family/family_name") != "ÑÖÂŞµØ¸®" )
        return ("ÄãÎÊÕâ¸ÉÊ²Ã´£¿");
        if (myskill<100)
        return ("Äã×·»ê½£ÊõÌ«µÍ£¬¾ÍÊÇÖªµÀÁËÒ²Ã»Ê²Ã´ÓÃ¡£\n");
        if (me->query("renru")==1)
        return ("ÄãÒÑ¾­¶®ÁË£¬¿ìÈ¥°É...");
        message_vision(CYN"$NÅÄÁËÅÄ$nµÄÄÔ´ü£¬Õâ¾ÍÊÇÈÌÈèÉñ¹¦£¬È¥°É¡£\n"NOR,this_object(),me);
        me->set("renru",1);
        return ("±ğÍüÁËÑ§É½×Ö¾­°¡£¡");
}
int work_me()
{
        object who;
        who=this_player();

        if( (int)who->query("combat_exp") < 300000 ) {
                message_vision("$N¶Ô$nÒ»¹°ÊÖ£¬µÀ£ºµÀĞĞ²»¹»£¬Ç¿ÇóÒàÊÇÍ÷È»¡£\n", this_object(),who);
                return 1;
        }
        if( who->query("HellZhenPass") ) {

message_vision("$N¶Ô$nÒ»¹°ÊÖ£¬µÀ£º¼´ÊÇÎä¹¦¸ßÇ¿£¬ÎÒµÈÅå·ş±ãÊÇ£¬Õâ¡£¡£¡£±ãÊÇÃâÁË°É£¡\n",this_object(),who);
        return 1;
        }
        if( this_object()->query_temp("SomeonePassing") ) {
                message_vision("$N¶Ô$nÒ»¹°ÊÖ£¬µÀ£ºÕæÊ±»úÔµ²»ÇÉ£¬¸ÄÈÕÔÙÀ´°É¡£\n",this_object(),who);
                return 1;
        }


message_vision("$N¶Ô$nÒõÒõµØĞ¦ÁË¼¸Éù£¬Ëµ£ºÌìÌÃÓĞÂ·Äã²»×ß£¬µØÓüÎŞÃÅÄã´³½øÀ´¡£\n",this_object(),who);
        this_object()->set_temp("SomeonePassing");
//add a chat here.
        command("chat "+who->query("name")+"Òª´³°³µØ¸®Ê®°Ë²ãµØÓü£¬ºß£¡µÈ×ÅÊÕÊ¬°É£¡\n");

        message_vision("$NË«ÊÖÅÄÁËÒ»ÏÂ£¬$n½ÅÏÂÍ»È»ÏİÁËÏÂÈ¥¡£¡£¡£\n", this_object(),who);
        who->delete("env/brief_message");
        who->move("/d/death/emptyroom");

        command("grin");
        this_object()->move("/obj/void");
        
//      call_out("get_all",1,who);
        call_out("message",3,who);
        call_out("round_1",4, who);
        return 1;
}
/*
int get_all(object who)
{
  object me = this_object();
  object *obs = all_inventory (who);
  int i = sizeof(obs);

  message_vision ("Ò»Õó¿ñ·ç´µÀ´£¬·ğÒ¯³öÏÖ£¡\n",who);
  while (i--)
  {
    object ob = obs[i];

    if (ob == me)
      continue;
    if (ob->query("no_get"))
      continue;
    if (ob->query("no_drop"))
      continue;

    message_vision ("·ğÒ¯´Ó$NÉíÉÏËÑ³ö$n£¡\n",who,ob);
    if (! interactive(ob))
      destruct (ob);
    else
      ob->move(environment(who));
  }  
    return 1;
}
*/
int check_status(object who)
{
        if( (int)who->query("kee") < 50 
        ||      (int)who->query("eff_kee") < 50 ) {
                remove_call_out("round_2");
                remove_call_out("round_3");
                remove_call_out("round_4");
                remove_call_out("round_5");
                remove_call_out("round_6");
                remove_call_out("round_7");
                remove_call_out("round_8");
                remove_call_out("round_9");
                remove_call_out("round_10");
                remove_call_out("round_11");
                remove_call_out("round_12");
                remove_call_out("round_13");
                remove_call_out("round_14");
                remove_call_out("round_15");
                remove_call_out("round_16");
                remove_call_out("round_17");
                remove_call_out("round_18");
                remove_call_out("message");
                remove_call_out("winning");
                call_out("failed",1,who);
                return 1;
        }
}
int failed(object who)
{       
        command("chat* ÑÖÂŞÍõ¿ñĞ¦ÁË¼¸Éù¡£");
        command("chat ¹ûÕæÓĞ²»ÅÂËÀµÄ£¬¿ÉÏ§»¹ÊÇÌÓ²»³ö°³µÄÊÖÕÆĞÄ£¡\n");
        this_object()->delete_temp("SomeonePassing");
        who->move("obj/void");
        who->unconcious();
        this_object()->move("/d/death/zhengtang");
        call_out("remove_all", 3);
        return 1;
}
int remove_all()
{       int i;
        object *list,empty;

        if( !(empty = find_object("/d/death/emptyroom")) )
                empty = load_object("/d/death/emptyroom");
        write("ËÄÖÜ¹ÎÆğÒ»ÕóÒõ·ç¡£¡£¡£\n");
        if( empty = find_object("/d/death/emptyroom") ) {

                list=all_inventory(empty);
                i = sizeof(list);
                while (i--)
                {
                        object ob=list[i];
                        ob->move("/d/changan/fendui");
                }
        }
        return 1;
}

int winning(object who)
{
// add a chat here.
        command("chat "+who->query("name")+"£¬ËãÄã×ßÔË£¬ÏÂ»Ø¿ÉÃ»ÕâÃ´±ãÒËÁË£¡\n");
// add reward here.
        who->add("kar", 10);
        who->add("potential", 1000);
        who->add("combat_exp", 5000);
        tell_object(who,"ÄãµÃµ½ÁËÒ»Ç§µãÇ±ÄÜºÍÎåÄêµÀĞĞ¡£\n");
        who->set("HellZhenPass",1);
        this_object()->move("/d/death/zhengtang");
        this_object()->delete_temp("SomeonePassing");
        call_out("remove_all", 3);
        return 1;
}
int message(object who)
{
        switch(random(5)) {

                case 0:
tell_room(environment(who),"\nÄã¾õµÃ×Ô¼º²»¶ÏÏÂ½µ£¬ÖÜÎ§¾°ÎïÈç²Êµû·­·É£¬²»¿É×¢Ä¿¡£\n");
break;
                case 1:
tell_room(environment(who),"\nÄã¾õµÃ×Ô¼º²»¶ÏÏÂ½µ¡£\n");
break;
                case 2:
tell_room(environment(who),"\nÄã¾õµÃ×Ô¼º²»¶ÏÏÂ½µ£¬ÌìµØËÆºõÃ»ÁË½çÏŞ¡£¡£¡£\n");
break;
                case 3:
tell_room(environment(who),"\nÄã¾õµÃ×Ô¼º²»¶ÏÏÂ½µ£¬ÖÜÎ§Ò»ÇĞ¶¼ÔÚĞı×ª¡£¡£¡£\n");
break;
                case 4:
tell_room(environment(who),"\nÄã¾õµÃ×Ô¼º²»¶ÏÏÂ½µ£¬ÏÂ½µ£¬ËÆºõÂäÏòÁËÎŞ¾¡µÄÉîÔ¨¡£\n");
break;
        }
        return 1;
}
int round_1(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/1");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ı£º\n\n");
        tell_room(environment(who),RED"                **************************************\n"NOR);
        tell_room(environment(who),RED"                **               µõ½îÓü             **\n"NOR);
        tell_room(environment(who),RED"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_2", 3, who);
        return 1;
}

int round_2(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/2");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ı£º\n\n");
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        tell_room(environment(who),GRN"                **               ÓÄÍ÷Óü             **\n"NOR);
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_3", 3, who);
        return 1;
}
int round_3(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/3");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ı£º\n\n");
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        tell_room(environment(who),YEL"                **               »ğ·»Óü             **\n"NOR);
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_4", 3, who);  
        return 1;
}
int round_4(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/4");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ı£º\n\n");
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        tell_room(environment(who),BLU"                **               Ûº¶¼Óü             **\n"NOR);
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_5", 3, who);  
        return 1;
}
int round_5(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/5");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ı£º\n\n");
        tell_room(environment(who),MAG"                **************************************\n"NOR);
        tell_room(environment(who),MAG"                **               °ÎÉàÓü             **\n"NOR);
        tell_room(environment(who),MAG"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_6", 3, who);  
        return 1;
}
int round_6(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/6");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ı£º\n\n");
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        tell_room(environment(who),CYN"                **               °şÆ¤Óü             **\n"NOR);
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_7", 3, who);  
        return 1;
}
int round_7(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/7");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ı£º\n\n");
        tell_room(environment(who),HIR"                **************************************\n"NOR);
        tell_room(environment(who),HIR"                **               Ä¥ÑÄÓü             **\n"NOR);
        tell_room(environment(who),HIR"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_8", 3, who);  
        return 1;
}
int round_8(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/8");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ı£º\n\n");
        tell_room(environment(who),HIG"                **************************************\n"NOR);
        tell_room(environment(who),HIG"                **               ×¶µ·Óü             **\n"NOR);
        tell_room(environment(who),HIG"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_9", 3, who);  
        return 1;
}
int round_9(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/9");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ı£º\n\n");
        tell_room(environment(who),HIY"                **************************************\n"NOR);
        tell_room(environment(who),HIY"                **               ³µ±ÀÓü             **\n"NOR);
        tell_room(environment(who),HIY"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_10", 3, who);  
        return 1;
}
int round_10(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/10");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ı£º\n\n");
        tell_room(environment(who),HIB"                **************************************\n"NOR);
        tell_room(environment(who),HIB"                **               º®±ùÓü             **\n"NOR);
        tell_room(environment(who),HIB"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_11", 3, who);  
        return 1;
}
int round_11(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/15");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/11");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ı£º\n\n");
        tell_room(environment(who),HIM"                **************************************\n"NOR);
        tell_room(environment(who),HIM"                **               ÍÑ¿ÇÓü             **\n"NOR);
        tell_room(environment(who),HIM"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_12", 3, who);  
        return 1;
}
int round_12(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/11");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/12");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ı£º\n\n");
        tell_room(environment(who),HIC"                **************************************\n"NOR);
        tell_room(environment(who),HIC"                **               ³é³¦Óü             **\n"NOR);
        tell_room(environment(who),HIC"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_13", 3, who);  
        return 1;
}
int round_13(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/16");

        seteuid(getuid());
        ghost=new("/d/death/HellZhen/13");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ı£º\n\n");
        tell_room(environment(who),HIW"                **************************************\n"NOR);
        tell_room(environment(who),HIW"                **               ÓÍ¹øÓü             **\n"NOR);
        tell_room(environment(who),HIW"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_14", 3, who);  
        return 1;
}
int round_14(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/18");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/14");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ı£º\n\n");
        tell_room(environment(who),RED"                **************************************\n"NOR);
        tell_room(environment(who),RED"                **               ºÚ°µÓü             **\n"NOR);
        tell_room(environment(who),RED"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_15", 3, who);  
        return 1;
}
int round_15(object who)
{
        object ghost;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/15");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ı£º\n\n");
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        tell_room(environment(who),GRN"                **               µ¶É½Óü             **\n"NOR);
        tell_room(environment(who),GRN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_16", 3, who);  
        return 1;
}
int round_16(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/15");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/16");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ı£º\n\n");
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        tell_room(environment(who),YEL"                **               Ñª³ØÓü             **\n"NOR);
        tell_room(environment(who),YEL"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_17", 3, who);  
        return 1;
}
int round_17(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/16");
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/17");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ı£º\n\n");
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        tell_room(environment(who),BLU"                **               °¢±ÇÓü             **\n"NOR);
        tell_room(environment(who),BLU"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("message",2,who);
        call_out("round_18", 3, who);  
        return 1;
}
int round_18(object who)
{
        object ghost,ghostb;
        seteuid(getuid());
        ghost=new("/d/death/HellZhen/18");
        seteuid(getuid());
        ghostb=new("/d/death/HellZhen/17");
        tell_room(environment(who),"\nÍ»È»¼äÒ»µÀºÚÅÆÉÁ¹ı£º\n\n");
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        tell_room(environment(who),CYN"                **               ³Ó¸ËÓü             **\n"NOR);
        tell_room(environment(who),CYN"                **************************************\n"NOR);
        ghost->move(environment(who));
        ghost->invocation(who);
        ghostb->move(environment(who));
        ghostb->invocation(who);
        call_out("check_status",1,who);
        call_out("winning", 3, who);  
        return 1;
}
string check_book()
{
        object me=this_player();

    if(me->query("family/family_name")!="ÑÖÂŞµØ¸®")
      return ("Äã²»ÊÇ±¾ÃÅÖĞÈË£¡");
   if(me->query("faith")>200)
      return ("ÄãÏÖÔÚµÄÉí·İÒÑ²»ÓÃ²éÉúËÀ²¾ÁË¡£"); 
      if(me->is_busy())
      return ("ÄãÕıÃ¦×ÅÄØ£¡");

   command("say Õâ¶ùÓĞÒ»¾íÉúËÀ²¾¿ÉÄÜÓĞÎó£¬ÄãÈ¥ÌæÎÒºË¶ÔÒ»ÏÂ¡£");
    message_vision("$NÔÚ×À×ÓÅÔ×øÏÂ£¬¾Û¾«»áÉñµØ½øĞĞºË¶Ô¡£\n",me);
   me->start_busy(5);
   call_out("finish_check_book",5,me,this_object());
   command("nod");
   return ("¹ûÈ»ÊÇÒ»¸öÇÚ¿ìÈË¡£");
}

void finish_check_book(object me,object master)
{
    message_vision("$N²éÁËĞí¾Ã£¬ÖÕÓÚ½«Ò»¾íÉúËÀ²¾²éÍêÁË£¬ËÉÁËÒ»¿ÚÆø£¬Ö»¾õµÃË«ÑÛ·¢Ëá£¡\n");
    me->receive_damage("sen",20);
    message_vision("$N×ßµ½ÑÖÂŞÍõÃæÇ°£¬¹§¹§¾´¾´µØËµÁËÉù£ºÙ÷¸æÍõÒ¯£¬²éÍêÁË£¬Ã»´í£¡\n",me);
    command("pat "+me->query("id"));
    command("say ºÃµÜ×Ó£¡");
    tell_object(me,"Äã¾õµÃ¶Ô¹´»êÊõÓĞÁËÒ»Ğ©ÁìÎò¡£\n");
    me->add("faith",1);
    me->add("combat_exp",9);
    me->add("potential",3);
    me->improve_skill("gouhunshu",random(me->query("int")),1);  
}
