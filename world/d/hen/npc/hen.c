

// by happ@YSZZ 

#include <ansi.h>
#include <hen.h>

inherit NPC;
static int last_age_set;

void create()
{
        set_name("ÐÇ¿ÕÕ½¶·¼¦", ({ "zhandou ji","ji" }) );
        set("race", "Ò°ÊÞ");
        set("long","Ò»Ö»ÐÇ¿ÕÕ½¶·¼¦£¬Èç¹ûÒªÎªËüÆðÃû×Ö£¬¾ÍÓÃsetname°É¡£\n");
        set("deathstamp",1);            
        set("value",100000);
        set("no_drop",1);
        set("no_give",1);
        set("no_sell",1);
        set("no_steal",1);
        set("max_kee",300);
        set("weight",0);
        set("max_sen",300);
        set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°ÐÄ", "áá±³", "Î²°Í" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("obedience",60);
        setup();
}

void init()
{
        if( interactive(environment()) && !query("owner") )
        set("owner",environment()->query("id"));
        add_action("do_shape","shape");
        add_action("do_setname","setname");
        add_action("do_kiss","kiss_hen");
        add_action("do_diuqi","diuqi");
}
int do_diuqi()
{
        object me = this_player();
        cat(DEATH2);
        tell_object(me,"°Ö°Ö²»ÒªÎÒÁË£¡\n");
        me->delete("hen");
        call_out("des",1);
        return 1;
}

int do_setname (string arg)
{

  object me = this_player();
  this_object()->set("name",arg);
  tell_object(me,"ÄãµÄÐ¡¼¦µÄÃû×Ö¾ÍÊÇ"+arg+"ÁË!\n");
  return 1;
}

void init_data(object owner)
{
    
        owner->set("hen/owner",owner->query("id"));
        owner->set("hen/age",0);                  
        owner->set("hen/max_life",50);
        owner->set("hen/tired",0);
        owner->set("hen/life",owner->query("hen/max_life"));
        owner->set("hen/ill",0);           // ²¡Æø
        owner->set("hen/dirty",0);         // ÔàÔà
        owner->set("hen/weight",30);       //30*age Õý¸º (30*age)/3
        owner->set("hen/max_dirty",100);
        owner->set("hen/fali",0);
        owner->set("hen/max_fali",0);
        owner->set("hen/affection",1000);    // Ç××Ó¹ØÏµ 
        owner->set("hen/money",5000);      // ½ðÇ®
        owner->set("hen/mold",0);          // ÆøÖÊ
        owner->set("hen/might",0);         // ÖÇÁ¦
        owner->set("hen/love",0);          // °®ÐÄ
        owner->set("hen/art",0);           // ÒÕÊõ
        owner->set("hen/ethics",0);        // µÀµÂ
        owner->set("hen/homework",0);      // ¼ÒÊÂ
        owner->set("hen/decorum",0);       // ÀñÒÇ
        owner->set("hen/reflect",0);       // Ó¦¶Ô
        owner->set("hen/cook",0);          // ³øÊ¦
        owner->set("hen/happy",50);        // ¿ìÀÖ
        owner->set("hen/satisfy",50);      // ÂúÒâ¶È
        owner->set("hen/relation",0);      // ÈË¼Ê¹ØÏµ
        owner->set("hen/charm",0);         // ÷ÈÁ¦
        owner->set("hen/brave",0);         // ÓÂ¸Ò
        owner->set("hen/belief",0);        // ÐÅÑö
        owner->set("hen/impurity",0);      // ×ïÄõ
        owner->set("hen/feel",0);          // ¸ÐÊÜ
        owner->set("hen/evaluation", ([
                        "combat"        :0,
                        "society"       :0,
                        "magic"         :0,
                        "homework"      :0,
                        ]));

        owner->set("hen/inventory", ([
                         "food"         :20,
                         "lingshi"      :5,
                         "dabu"         :1,
                         "lingzhi"      :1,
                         "renshen"      :1,
                         "xuelian"      :1,
                        ]));

        owner->set("hen/attack",10);
        owner->set("hen/defence",10);
        owner->set("hen/speed",10);
        owner->set("hen/anticmagic",0);
        owner->set("hen/combat_ski",0);
        owner->set("hen/magic_ski",0);
}


string condition()
{
        object owner=find_player(query("owner"));

        if( owner->query("hen/age") == 0 )
                return "µ®Éú";
        
        if( owner->query("hen/age") <=3 && owner->query("hen/age") > 0 )
                return "Ð¡Ð¡¼¦";

        if( owner->query("hen/age") <=15 && owner->query("hen/age") > 3 ) 
                return "¶ùÍ¯";

        if( owner->query("hen/age") <=30 && owner->query("hen/age") > 15 )       
                return "ÇàÄê";

        if( owner->query("hen/age") <=50 && owner->query("hen/age") > 30 )
                return "ÖÐÄê";

        if( owner->query("hen/age") <=80 && owner->query("hen/age") > 50 )            
                return "ÀÏÄê";

        if( owner->qurey("hen/age") > 80 )
                return "ÀÏµôÑÀ";
}
 
                          
string dirty()
{
        object owner=find_player(query("owner"));
 
       if ( owner->query("hen/dirty") > 2*owner->query("hen/max_dirty") )
                return "[31m¿ì³ôËÀÁË![m";

        if ( owner->query("hen/dirty") >owner->query("hen/max_dirty") )
                return "[32mÓÐµã³ôÁË[m";

                return "[1;37mÎÒÊÇ¸É¾»µÄÐ¡¼¦![m";
}
string tired()
{
        object owner=find_player(query("owner"));

        if( owner->query("hen/tired") > 90 )
                return "[35m¿ìÀÛËÀÁË[m";
        if( owner->query("hen/tired") > 60 )
                return "[32mÓÐµãÐ¡ÀÛ[m";
                return "";
}

string happy()
{
        object owner=find_player(query("owner"));

        if( owner->query("hen/happy") > 90 )
                return "[32mÌØ±ð¿ìÀÖ[m";

        if( owner->query("hen/happy") > 60 )
                return "[34mÐÄÇé²»´í[m";

        if( owner->query("hen/happy") > 30 )
                return "[33m²»Ì«¸ßÐË[m";

                return "[36mºÜ²»¸ßÐË[m";
}
string eat()
{
        object owner=find_player(query("owner"));

        if ( owner->query("hen/max_life")/3 > owner->query("hen/life") )
                return "[33m¿ì¶öËÀÁË[m";

        if ( owner->query("hen/max_life")/2 > owner->query("hen/life") )
                return "[32m¶Ç×Ó¿Õ¿Õ[m";

                return "[36m¶Ç×Ó±¥±¥[m";
 }

string statisfy()
{

        object owner=find_player(query("owner"));

        if( owner->query("hen/satisfy") > 90 )
                return "[32mÐÄÂúÒâ×ã[m";

        if( owner->query("hen/satisfy") > 30 )
                return "[33m²»Ì«ÂúÒâ[m";

                return "[35mºÜ²»ÂúÒâ[m";
}

string ill()
{
        object owner=find_player(query("owner"));

        if( owner->query("hen/ill") > 90 )
                return "[31m²¡Î£[m";

        if( owner->query("hen/ill") > 60 )
                return "[32m²¡ÖØ[m";

        if( owner->query("hen/ill") > 30 )
                return "[33mÉú²¡ÁË[m";
                return "";
}
int do_shape(string arg)
{ 
        object me;

       if( ! query("owner") )
                return notify_fail("ÄãÃ»ÓÐÐÇ¿ÕÕ½¶·¼¦°¡£¬È¥ÑøÒ»Ö»°É£¡\n");    
        me = find_player(query("owner"));

printf(HIG+BCYN"ÐÇ¿ÕÕ½¶·¼¦      [33m%10s      Ö÷ÈË: %10s                              \n[m",name(),this_object()->query("owner"));
printf(HIG+"[×´Ì¬]:      %6s      [ÄêÁä]:       %3d      [½ðÇ®]:  %6d    [Ç×Çé]: %4d\n",condition(),query("age"),me->query("hen/money"),me->query("hen/affection"));
printf(HIY+"[ÉúÃü]: %5d/%5d      [·¨Á¦]: %5d/%5d    [ÌåÖØ]: %4d       [Æ£ÀÍ]: %3d\n",me->query("hen/life"),me->query("hen/max_life"),me->query("hen/fali"),me->query("hen/max_fali"),me->query("hen/weight"),me->query("hen/tired"));
printf(HIR+"[ÔàÔà]:   %3d            [²¡Æø]:    %2d          [¿ìÀÖ]:  %3d       [ÂúÒâ]:  %3d\n"NOR,me->query("hen/dirty"),me->query("hen/ill"),me->query("hen/happy"),me->query("hen/satisfy"));
printf("%-16s   %-8s   %-8s      %-8s       %-6s\n",dirty(),eat(),happy(),statisfy(),ill()); 
printf("/-----------------------------------------------------------------------------\\");
printf("\n");

        if( me->query("hen/affection") < 0 )
        {
        cat(DEATH3);
        message_vision("$N´ó¿Þ£º$n²»ÒªÎÒÁË¡££º£¨\n",this_object(),me);
        me->delete("hen");
        call_out("des",3);
        return 1;
        }

        if( me->query("hen/dirty") > 90 )
        {
        cat(DEATH1);
        message_vision("$NÒªËÀÁË£¬$n²»¸øÎÒÏ´Ôè¡££º£¨\n",this_object(),me);
        me->delete("hen");
        call_out("des",3);

        return 1;
        }

        if( me->query("hen/life") < 0 )
        {
        cat(DEATH1);
        message_vision("$NÒªËÀÁË£¬$n²»¸øÎÒ³Ô·¹¡££º£¨\n",this_object(),me);
        me->delete("hen");
        call_out("des",3);
        return 1;
        }

        if( me->query("hen/tired") > 90 )
        {
        cat(DEATH2);
        message_vision("$NÒªËÀÁË£¬$n²»ÈÃÎÒÐÝÏ¢¡££º£¨\n",this_object(),me);
        me->delete("hen");
        call_out("des",3);
        return 1;
        }


        if( me->query("hen/ill") > 90 )
        {
        cat(DEATH1);
        message_vision("$NÒªËÀÁË£¬$n²»¸øÎÒÖÎ²¡¡££º£¨\n",this_object(),me);
        me->delete("hen");
        call_out("des",3);
        return 1;
        }

  return 1;
}

int do_kiss()
{
        object ob = this_player();
        ob->add("hen/dirty",5);

       ob->query("hen/happy") > 95 ?
        ob->set("hen/happy",100):
        ob->add("hen/happy",5+random(2));

        ob->query("hen/satisfy") > 95 ?
        ob->set("hen/satisfy",100):
        ob->add("hen/satisfy",5+random(2));
        ob->add("hen/affection",1);
        ob->command_function("cls");
        ob->command_function("shape");
        cat(KISS);
        write("À´Âï! à£Ò»¸ö.....\n");
        return 1;
}

void update_age()
{

        if( !last_age_set ) last_age_set = time();
        add("mud_age", time() - last_age_set);
        last_age_set = time();
        set("age", (int)query("mud_age") / 172800);
}

int heal_up()
{
        object ob;

        if( ! query("owner") )
        {
        call_out("des",3);
        return 1;
        }
/*
        ob = find_player(query("owner"));
        
        if( ! interactive(ob) )
        {
        call_out("des",3);
        return 1;
        }
        update_age();

        if( ob->query("hen/affection") < 0 )
        {
        message_vision("$N´ó¿Þ£º$n²»ÒªÎÒÁË¡££º£¨\n",this_object(),ob);
        ob->delete("hen");
        call_out("des",3);
        return 1;
        }

        if( ob->query("hen/dirty") > 90 )
        {
        message_vision("$NÒªËÀÁË£¬$n²»¸øÎÒÏ´Ôè¡££º£¨\n",this_object(),ob);
        ob->delete("hen");
        call_out("des",3);
        return 1;
        }

        if( ob->query("hen/life") < 0 )
        {
        message_vision("$NÒªËÀÁË£¬$n²»¸øÎÒ³Ô·¹¡££º£¨\n",this_object(),ob);
        ob->delete("hen");
        call_out("des",3);
        return 1;
        }

        if( ob->query("hen/tired") > 90 )
        {
        message_vision("$NÒªËÀÁË£¬$n²»ÈÃÎÒÐÝÏ¢¡££º£¨\n",this_object(),ob);
        ob->delete("hen");
        call_out("des",3);
        return 1;
        }


        if( ob->query("hen/ill") > 90 )
        {       
        message_vision("$NÒªËÀÁË£¬$n²»¸øÎÒÖÎ²¡¡££º£¨\n",this_object(),ob);
        ob->delete("hen");
        call_out("des",3);
        return 1;
        }

*/        set_heart_beat(1);
        return ::heal_up();
}

void des()
{
        destruct(this_object());
}
