//Cracked by Roath
// happ@YSZZ
 
// gao.c
#include <ansi.h>

inherit NPC;
string ask_girl();

void create()
{
       set_name("¸ßÔ±Íâ", ({"gao yuanwai", "gao"}));

set("long","¸ß¼Ò×¯µÄÖ÷ÈË£¬³ÔµÄÅÖºõºõµÄ£®\n°´Ëµ´ó²ÆÖ÷Ó¦¸ÃÀÖºÇºÇµØ£¬ËûÈ´³îÃ¼¿àÁ³£¬ÏóÊÇÓöµ½ÁËÊ²Ã´ÄÑÊÂ£®\n");
       set("gender", "ÄĞĞÔ");
       set("age", 46);
       set("title", "×¯Ö÷");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("combat_exp", 425000);
       set("daoxing", 2555000);
       set("mana", 3250);
       set("force", 2000);
       set("max_mana", 4000);
       set("max_force", 1700);
       set_skill("unarmed", 150);
       set_skill("dodge", 300);
       set_skill("parry", 215);
       set_skill("tianpeng-zhang", 215);
       map_skill("unarmed", "tianpeng-zhang");
set("inquiry", ([
"name": "ÀÏ·òĞÕ¸ß£¬ÄËÊÇ¼ÒÖĞµÄÖ÷ÈË£®\n",
"here": "¸ßÀÏ×¯ÊÇÒ²£®\n",
"¸ßĞ¡½ã": (: ask_girl :),
"´äÀ¼" : (: ask_girl :),
]) );

   setup();
       add_money("silver", 3+random(5));
   carry_object("/d/ourhome/obj/choupao")->wear();
}

void init()
{
        remove_call_out("check");
        call_out("check",1);
}
void check()
{
          object room = environment();
          object lady = present("cui lan",room);        
          object ob;
          if (!lady) return ;
          if( lady->query_leader() == 0 )
                return ;
          ob = present(lady->query_leader(),room);
          if( ob == 0 )
                return ;
          remove_call_out("check2");
          call_out("check2",1,ob);
}
void check2(object ob)
{
          int i;
          if (ob->query("obstacle/yz") == "done")
                return;
          if( !ob->query_temp("pig_killed") )
                return;
        i = random(500);
        ob->add("obstacle/number",1);
        ob->set("obstacle/yz","done");
        ob->add("combat_exp",i+2000);
        command("chat ¸ĞĞ»"+ob->query("name")+"¾È³öÎÒµÄĞ¡Å®´äÀ¼£¡");
message("channel:chat",HIY"¡¾¹ı¹ØÕ¶½«¡¿¹ÛÒôÆĞÈø(guanyin pusa)£º"+ob->query("name")+"´³¹ıÎ÷ĞĞÈ¡¾­[1;37mµÚÎå¹Ø£¡\n"NOR,users());//this is by tianlin 2001.5.8
        tell_object (ob,"ÄãÓ®µÃÁË"+chinese_number(3)+"Äê"+
               chinese_number(i/4)+"Ìì"+
               chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀĞĞ£¡\n");
        ob->delete_temp("pig_killed");
        ob->save();
        return;
}
string ask_girl()
{
        object ob = this_player();
        object cloth = new("/d/gao/obj/cloth");
        if( ob->query("obstacle/yz") == "done" 
        || !ob->query("obstacle/hf") 
        || ob->query_temp("girl_asked") )
                {
                command("?");
                return("ÄãÎÊÕâ¸ÉÊ²Ã´£¿");
                }
        command("disapp1 gao");
        command("cry1");
        cloth->move(ob);
        ob->set_temp("girl_asked",1);
        command("say ÎÒÄÇÅ®¶ù£¬±»¸£ÁêÉ½Ò»¸öÒ°Öí¹Ö°ÔÕ¼ÁË£¬²»ÖªÄúÓĞÃ»ÓĞÊÖ¶Î£¬°ïÎÒ¾È»ØÅ®¶ù£¿ ");
        return("ÕâÊÇËıÒÔÇ°´©µÄÒÂ·ş¡£");       
}        
