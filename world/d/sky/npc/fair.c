// referee.c

inherit NPC;
#include <ansi.h>;

int do_bihua(string arg);
string ask_me();
int do_halt();

void create()
{
        set_name(HIB"¹«Æ½×Ó"NOR, ({ "gongping zi", "zi", "referee" }) );
        set("gender", "ÄĞĞÔ");
        set("age", 35);
        set("long",
                "[2;33mÕâÊÇÒ»Î»ÏÉ·çµÀ¹ÇµÄÖĞÄêµÀÈË£¬ÔçÄêÔÆÓÎËÄ·½£¬ĞÔºÃÈÎÏÀ£¬¹«ÕıÎŞË½¡£[2;0m\n");

        set("combat_exp",600000);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("per",40);
         set("apply/attack", 50);
        set("apply/defense", 50);

        set("max_kee", 800);
        set("max_gin", 800);
        set("max_force", 8000);

        set_skill("force", 180);
        set_skill("unarmed",180);
        set_skill("sword",180);
        set_skill("parry",180);
        set_skill("dodge", 180);

        set("inquiry", ([
                "±ÈÎä´ó»á"       : (: ask_me :),
        ]));

        setup();

        carry_object("/obj/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}


void init()
{
        ::init();       
        add_action("do_bihua", "bihua");
        add_action("do_bihua", "bi");
        add_action("do_bihua", "fight");
        add_action("do_halt", "halt");
        add_action("do_halt", "h");
}

string ask_me()
{
        object* ob;
        int i;
        ob = users();

        if ( !wizardp(this_player()) ) return "ÄãÎŞÈ¨ÕÙ¿ª±ÈÎä´ó»á£¡\n";

        for ( i=sizeof(ob); i>0; i-- ) {
                        ob[i-1]->move("/d/huashan/sheshen");
        }

        return "[1;32mºÃ£¬ÏÖÔÚ±ÈÎä´ó»áµÚÒ»×éÕıÊ½¿ªÊ¼£¬È«Ìå³ÉÄêÑ¡ÊÖ¼¯ºÏ£¡[1;0m\n";
}

int do_bihua(string arg)
{     
        object ob1, ob2;
        object old_target;

        ob1 = this_player();
        
        if( !arg || arg=="" ) return 0;  

        if ( arg == "gongping zi" || arg == "zi" || arg == "referee" )
           {
             command("say " + "Äã²»ÄÜ¸úÎÒ±È»®£¡\n");
             return 1;
            }

        if ( this_object()->query_temp("busy") ) 
                return notify_fail("Ã¿´ÎÖ»ÄÜÓĞÁ½ÈË²Î¼Ó±ÈÎä¡£\n");

        if (!ob2 = present(arg,environment(ob1)) ) 
                return notify_fail("ÄãÏë¸úË­±È»®£¿\n");
        if (ob1 == ob2)    return notify_fail("Äã²»ÄÜ¹¥»÷×Ô¼º¡£\n");


        if( userp(ob2) && (object)ob2->query_temp("pending/fight") !=ob1 ) {
                message_vision("\n$N¶Ô×Å$nËµµÀªº" 
                        + RANK_D->query_self(ob1) 
                        + ob1->name() + "ª¬Áì½Ì"
                        + RANK_D->query_respect(ob2) + "µÄ¸ßÕĞ¢¦\n\n", ob1, ob2);
                if( objectp(old_target = ob1->query_temp("pending/fight")) )
                        tell_object(old_target, YEL + ob1->name() + "È¡ÏûÁËºÍÄã±ÈÊÔµÄÄîÍ·¡£\n" NOR);
                ob1->set_temp("pending/fight", ob2);
                tell_object(ob2, YEL "Èç¹ûÄãÔ¸ÒâºÍ¶Ô·½½øĞĞ±ÈÊÔª¬ÇëÄãÒ²¶Ô" + ob1->name() + "("+(string)ob1->query("id")+")"+ "ÏÂÒ»´Î bihua Ö¸Áî¡£\n" NOR);

                write(YEL "ÓÉì¶¶Ô·½ÊÇÓÉÍæ¼Ò¿ØÖÆµÄÈËÎïª¬Äã±ØĞëµÈ¶Ô·½Í¬Òâ²ÅÄÜ½øĞĞ±ÈÊÔ¡£\n" NOR);
                return 1;
        }
            
        ob1->delete_temp("halted");
        ob2->delete_temp("halted");

        remove_call_out("check");
        call_out("check",2, ob1, ob2);

//      ob1->set("kee",(int)ob1->query("max_kee"));
//      ob2->set("kee",(int)ob2->query("max_kee"));

        remove_call_out("fighting");
        call_out("fighting",2, ob1, ob2);

        return 1;
}

void fighting(object ob1, object ob2)
{
        ob1->fight_ob(ob2);
        ob2->fight_ob(ob1);
}

void check(object ob1, object ob2)
{
        this_object()->set_temp("busy",1);
        command("chat " + ob1->query("name") 
                + "Óë" + ob2->query("name") + MAG"£¬ÏÖÔÚË®Â½´ó»á±ÈÎä³¡ÇĞ´êÎäÒÕ £¡\n"NOR);
        call_out("observe",1,ob1,ob2);
}

int observe(object ob1,object ob2)
{
        object ob;

        if(ob1->is_fighting()) 
        {
                call_out("observe",1,ob1,ob2);
                return 1;
        }

        this_object()->delete_temp("busy");
        ob1->delete_temp("pending/fight");
        ob2->delete_temp("pending/fight");

        if ( !present(ob1, environment()) ) 
        {
                command("chat " + ob1->query("name") + MAG"Âä»Ä¶øÌÓÁË£¡\n"NOR);
                return 1;
        }

        if ( !present(ob2, environment()) ) 
        {
                command("chat " + ob2->query("name") + MAG"Âä»Ä¶øÌÓÁË£¡\n"NOR);
                return 1;
        }
           
        if (ob1->query_temp("halted"))
         {
               ob1->delete_temp("halted");
               command("chat " + ob1->query("name") + 
                       MAG"ÖĞÍ¾·ÅÆú±ÈÎä£¡\n"NOR);
                return 1;
         }
        if (ob2->query_temp("halted"))
         {
               ob2->delete_temp("halted");
               command("chat " + ob2->query("name") + 
                       MAG"ÖĞÍ¾·ÅÆú±ÈÎä£¡\n"NOR);
                return 1;
         }

        if ( ob1->query("kee")*2 > ob1->query("max_kee")) 
        {
                if  (ob2->query("kee")*2 > ob2->query("max_kee")) {
                        command("chat " + ob1->query("name") 
                                + "Óë" + ob2->query("name") + "±ÈÎä²»·ÖÊ¤¸º£¡\n");
                        return 1;
                }
                command("chat " + ob1->query("name") 
                        + HIY"±ÈÎäÕ½Ê¤"NOR + ob2->query("name") + "£¡\n");
                ob = new("obj/money/silver");
                ob->move(ob1);
        }
        else
        {
                command("chat " + ob2->query("name") 
                        + HIY"±ÈÎäÕ½Ê¤"NOR + ob1->query("name") + "£¡\n");
                ob = new("obj/money/silver");
                ob->set_amount(2);
                ob->move(ob2);
        }
        
        return 1;

}

int do_halt()
{
 object me = this_player();
if (me->is_fighting())
 me->set_temp("halted",1);
return 0;
}
