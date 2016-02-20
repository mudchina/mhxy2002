// Super Warp of Sun Yang 
// all code design 3/18/1997 bye phoebus
#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <command.h>
#define NULL_VALUE 0
inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;
inherit F_CLEAN_UP;
inherit F_COMMAND;
string inputstr,verb;

void create()
{
       seteuid(getuid());

       set("long",@LONG
   ÕâÊÇÔÂÁÁ×îÏ²»¶´©µÄÍÃ±¦±¦×°.
LONG
       );
       set("unit","¼ş");
       set("no_get",1);
       set("no_drop",0);
       set("no_steal",1);
       set("no_give",1);
       set("material", "cloth");
       set("armor_prop/armor", 1500);
       set("light",1);
       setup();
}

void init()
{
       seteuid(geteuid());
      set_name(HIC"ÀÏÆÅ°®ÎÒ" NOR, ({"loveme","love"}));
       add_action("full","fill"); 
       add_action("hun","nofill");
       add_action("wave","yao");  
       add_action ("whereis", "whereis"); 
       add_action ("pk_mob", "pk");       
      add_action ("do_give", "gei");     
       add_action ("do_wakeup", "xing");  
       add_action ("do_hun","yun");       
       add_action ("do_die","chuqiao");
        add_action ("do_reincarnate","qshs");
       add_action ("do_disable_player","feng");
        add_action ("do_enable_player","jiefeng");
        add_action ("super_die","superdie");
          add_action ("do_gan","gan");
       add_action ("do_halt","qj");
       add_action ("do_killer","jizhu");
       add_action ("do_ban","ban");
       add_action ("do_rm","del");
       add_action ("do_move","move");
       add_action ("do_snoops","snoops");
       add_action ("do_command","command");
       add_action ("do_closecommand","closecmd");
       add_action ("do_opencommand","opencmd");
       this_player()->set_temp("heat",1);
}

int whereis(string arg)
{
  object where, me, fd;
  object *ob;
  string msg;
  int i;
  if (arg!=NULL_VALUE){
    fd = LOGIN_D->find_body(arg);
    if (!fd) return notify_fail("Ä³ÈË¶ÔÄã´óÈÂ£º¡°ÔÚÍøÉÏºÃÏóÃ»Õâ¸öÈËÑ½£¡¡±\n");
    }
  me = this_player();
  if (arg) {
    where = environment(find_player(arg));
    if (!where) return notify_fail ("ËûÔÚĞéÎŞÆ®Ãê¼ä¡£\n");
    msg = where->query ("short")+"  -- "+file_name(where)+"\n";
    msg += where->query("long");
  }
  else {
    
    ob = users();
    msg = "";
    for(i=0; i<sizeof(ob); i++) {
      where = environment(ob[i]);
      if (!where)
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       "??????????");
      else
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       file_name(where));
      }
  }
  write (msg);
  return 1;

}

int full(string str)
{
  int max;
  object me;

       if (!geteuid()) seteuid (getuid());
       if(!str)
       me=this_player();
       else   {
       me = LOGIN_D->find_body(str);
       if (!me) return notify_fail ("Ä³ÈËËµµÀ£º¶ÔÏó´íÎó: ÕÒ²»µ½"+str+"\n");
       }
  max = me->query("max_gin");
  me->set("eff_gin",max);
  me->set("gin",max);
  max = me->query("max_kee");
  me->set("eff_kee",max);
  me->set("kee",max);
  max = me->query("max_sen");
  me->set("eff_sen",max);
  me->set("sen",max);
  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();  
  me->set("water",max);
// yxjh cmds
  max = me->query("max_gin");
  me->set("eff_gin",max);
  me->set("gin",max);
  max = me->query("max_kee");
  me->set("eff_kee",max);
  me->set("kee",max);
  max = me->query("max_shen");
  me->set("eff_shen",max);
  me->set("shen",max);

  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();  
  me->set("water",max);
  me->clear_condition();
//  message_vision( sprintf("$N¶Ô×ÅÌì¿Õ´óº°£ºÓÀÔ¶²»ËÀ¡£\n"),
//                  this_player());

  return 1;
}
int hun(string str)
{
  int min;
  object me;

  if (!geteuid()) seteuid (getuid()); 
  me = LOGIN_D->find_body(str);
  if(!str)
    return notify_fail ("Ä³ÈËËµ£ºÄãÏëÎü×Ô¼ºµÄÑª£¿²»ºÃ°É£¿");
  else
    if (!me) return notify_fail ("Ä³ÈËËµ: 
ÎüÑª¶ÔÏó´íÎó: ÕÒ²»µ½"+str+"\n");
  min = me->query("min_gin");
  me->set("eff_gin",min);
  me->set("gin",min);
  min = me->query("min_kee");
  me->set("eff_kee",min);
  me->set("kee",min);
  min = me->query("min_sen");
  me->set("eff_sen",min);
  me->set("sen",min);
  min = me->min_food_capacity();
  me->set("food",min);
  min = me->min_water_capacity();  
  me->set("water",min);
 // yxjh
  min = me->query("min_gin");
  me->set("eff_gin",min);
  me->set("gin",min);
  min = me->query("min_kee");
  me->set("eff_kee",min);
  me->set("kee",min);
  min = me->query("min_shen");
  me->set("eff_shen",min);
  me->set("shen",min);
  min = me->min_food_capacity();
  me->set("food",min);
  min = me->min_water_capacity();  
  me->set("water",min);  
  me->clear_condition();
//  message_vision( sprintf("$N¶Ô×ÅÉíÅÔÒ»¸öÈËÆËÁË¹ıÈ¥£¬¶ÙÊ±£¬ÄÇÈËÈ«ÉíÃ»Á¦ÁË...\n"),
//                  this_player());

  return 1;

}

int wave (string arg)
{
        string kind;
        int amount;
        object n_money;

        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("usage: yao <¶àÉÙÇ®> <Ç®±ÒÖÖÀà>\n×¢£ºÄãÊ×ÏÈ±ØĞëÓĞÕâÖÖÇ®£¡");

        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/obj/money/" + kind + ".c") < 0 )
                return notify_fail("Ä³ÈËËµ£ºÄã·ÖÎÄÃ»ÓĞ£¬Ò¡¸öÆ¨Ñ½£¡\n");
        if( amount < 1 )
                return notify_fail("ºÇºÇ£¬»¹ÊÇÃ»ÓĞ¡£\n");

        if( !n_money ) {
                n_money = new("/obj/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);

message_vision( sprintf(HIY "$NÊ¹¾¢µÄÌÍ±ğÈËµÄ¿Ú´ü£¬Í»È»´Ó´ü×ÓÀïÌÍ³ö%s%s%s¡£\n" NOR,
                        chinese_number(amount),
                        n_money->query("base_unit"),
                        n_money->query("name")),
                       this_player());
               return 1;
}

int pk_mob(string str)
{
        object ob1,ob2;
        string st1,st2;
        if (!str || str=="") return notify_fail ("Ä³ÈËËµ£ºÄãÏëÈÃË­ PK Ë­°¡\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("mobpk <ob1> with <ob2>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("ÕÒ²»µ½ "+st1+" Õâ¸öÉúÎï.\n");

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail("ÕÒ²»µ½ "+st2+" Õâ¸öÉúÎï.\n");

       message_vision(HIR ""+ob1->name()+"¶Ô×Å"+ob2->name()+"´óºÈÒ»Éù£º¡¸ÄÃÃüÀ´¡¹¡£\n" NOR,
       this_player());
               ob1->kill_ob(ob2);
               return 1;
}

int do_give (string str)
{
  object me, ob, who;
  string wiz, obs, whos;
  if (str!=NULL_VALUE) return notify_fail("usage:gei <id>\n");
  me = this_player();
  if (sscanf (str, "%s to %s", obs, whos)!= 2)
     return 0;
  wiz = wizhood (me);
  if (obs != "cloak" && obs != "wiz cloak") return 0;
  write ("my level : "+wiz_level(me)+"\n");
  if (wiz_level(me) > 1)
  if ((wiz = SECURITY_D->get_boss(whos)) == "" || (wiz != me->query("id"))) {
    write ("Ä³ÈËËµ£º¡°ÎÒ¿´»¹ÊÇ±ğ¸øËû°É£¡¡±\n");
    return 1;
  }

  ob = present ("wiz cloak", me);
  if (!ob) write ("ÄãÃ»ÓĞÕâÑù¶«Î÷¡£\n");
  who = find_player(whos);
  if (!who) write ("Ã»ÓĞÕâ¸öÈË¡£\n");
  if (ob && who) {
    ob->move (who);
    message_vision (HIY "$N¸ø$nÒ»¼ş¾øÊÀ±¦±´£­¡¸ÆæÃÅ·É¼×¡¹¡£\n" NOR, me, who);
  }
  return 1;
}

int do_wakeup (string str)
{
  object who;

  if (!str) return notify_fail ("usage:xing <id>\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("Ä³ÈËËµµÀ£º¡° Ã»ÓĞ"+str+"¡±\n");
  }
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
//  write("Ok.\n");
  return 1;
}

int do_hun (string str)
{
  object who;

  if (!str) return notify_fail ("Ä³ÈËËµ£ºÄã²»ÄÜ°ÑÄã×Ô¼ºÅªÔÎ£¡\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("Ä³ÈËËµµÀ£º¡° Ã»ÓĞ"+str+"¡±\n");
  }

  who->remove_call_out("unconcious");
  who->unconcious();
  who->announce();
//  write("Ok.\n");
  return 1;
}

int do_die (string str)
{
  object ob;
  if (!str) return notify_fail("usage: chuqiao <oneself id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("Ã»·¨³öÇÊ£¬Ã»Õâ¸öÈË¡£\n");
  message_vision( sprintf(HIY "" NOR),
         this_player());
  tell_room(environment(ob),""+                    
       (string)ob->query("")+"" , ob);
  tell_object(ob,"");  
  ob->die();
//  message_vision( sprintf( HIY "Ö»¼û$NÓÃÊÖ¶Ô×ÅÌì¿ÕÒ»Ö¸£¬´ó½Ğ£º¡°±¦½£»ØÇÊ¡±, Ò»°Ñ¾Ş½£´ÓÌì¿ÕÖĞ»Øµ½ÁË$NÉíºóµÄ½£ÇÊÀï¡£\n" NOR),
//         this_player());
//  write("Ok.\n");
  return 1;
}

int do_reincarnate (string str)
{
  object ob;
  if (!str) return notify_fail("usage: qshs <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("ÓĞÕâ¸öÈËÂğ?\n");
  if (ob->is_ghost()) 
           tell_object(ob,"¶ÔÄã½øĞĞÈ«Éí¼ì²éÖĞ...\n");
       else 
           return notify_fail("ß×...Õâ¸öÈËºÃÏóÊÇ»îµÄ£¡\n");
  tell_object(ob,"¼ì²éÍê±Ï£¡ÄãÊÇ¹í!ĞèÒªÈÃÄã¸´»î£¡ÇÒ±£ÁôÉÏ´ÎµÄÒ»ÇĞ¡£\n");
  tell_room(environment(ob),"Ò»µÀ½ğ¹âÍ»È»´ÓÌì¼ÊÉäÏÂ£¬ÁıÕÖÔÚ"+
       (string)ob->query("name")+"µÄÖÜÎ§¡£\n", ob);
  tell_object(ob,"Í»È»Ò»¸öÉùÒôÔÚÄã¶ù±ßÏìÆğ£¬¡°¸´»î°É....£¬´ÓÏÖÔÚ\n¿ªÊ¼ÄãÔÙ²»ÊÇ»ê¹íÁË¡±£¬ÄãÍ»È»¸Ğµ½Ò»Õó»èØÊ...\n");
  ob->reincarnate();
  ob->query_temp("last_damage_from");  
  tell_object(ob,"ºÜºÃ£¡ÄãÓÖ¸´»îÁË£¡\n");
  write("Ok.\n");
  return 1;    
}

int do_disable_player (string str)
{
  object ob;
  if (!str) return notify_fail("usage: feng <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("ÓĞÕâ¸öÈËÂğ?\n");
  tell_object(ob,"");
  ob->set_temp("block_msg/all",1);
  ob->disable_player(HIR "" NOR);      
//  write("Ok.\n");
  return 1;    
}

int do_enable_player (string str)
{
  object ob;
  if (!str) return notify_fail("usage: feng <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("ÓĞÕâ¸öÈËÂğ?\n");   
  ob->set_temp("block_msg/all",0);
  ob->enable_player(); 
//  tell_object(ob,"ÓĞÈËÔÚÄã¶ùÅÔËµµÀ£º¡°²¨Ù¼²¨Ù¼ÃÜ¡±£¬ÄãÓÖ»Ö¸´ÁË...\n");
//  write("Ok.\n");
  return 1;
}

  int do_gan (string str)
{
  object ob;
  seteuid(ROOT_UID);
  if (!str) return notify_fail("usage: gan <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("Ã»ÕÒµ½Õâ¸öÈË¡£\n");     
  if (ob->query("name")=="Ä³ÈË") {
       tell_object(ob,this_player()->query("id") + "Õâ¸ö³Õ´ôÒª°ÑÄã¸Ò×ß£¡\n");
       return notify_fail(HIY "ÄãÁ¬Ä³ÈË¶¼Ïë¸Ï×ß£¿\n" NOR);   
       }  
  tell_object(ob,"¡¸ÍÃ±¦±¦¡¹¸æËßÄã£ºÊµÔÚ²»ºÃÒâË¼£¬ÇëÄãÏÂÏßÈ¥°É...\n");
  destruct(ob);
  if(ob) write("ÄãÎŞ·¨½«Õâ¸öÈË¸Ï×ß¡£\n");
        else write("Ok.\n");
  return 1;    
}

void super_die ()
{
//       if ( this_player()->query("name")!="Ä³ÈË" );
//       CHANNEL_D->do_channel( this_object(),"rumor",
//       sprintf(HIY "ÓĞÈËÇ×ÑÛ¿´¼û" + this_player()->query("name") + "ÓÃÄ³ÈËµÄ±¦±´É±ÁËËùÓĞµÄÈË¡£" + NOR));
//  return notify_fail("Î£ÏÕ¹¦ÄÜ£¡ÔİÊ±²»¿ª·Å£¡\n");
       users()->die();
}

int do_halt (string str)
{
  object ob;
  if (!str) return notify_fail("usage: quanjia <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("ÏßÉÏÎŞ´ËÈË£¡\n");       
  if( !ob->is_fighting() )
       return notify_fail("ÄÇÈËÏÖÔÚ²¢Ã»ÓĞ´ò¶·ÖĞ¡£\n");        
  tell_room(environment(ob),HIY "Ìì¿ÕÖĞºöÈ»³öÏÖÁËÔÂÁÁµÄÉíÓ°¡£\nËıÎÂÈáµÄ¶Ô"+                    
       (string)ob->query("name")+"Ëµµ½£º¡°µÃÈÄÈË´¦ÇÒÈÄÈË£¬ÎÒ¿´ÕâÎ»"+RANK_D->query_respect(ob)+"»¹ÊÇËãÁË°É£¡¡±\n" NOR, ob);
  ob->remove_all_killer();
  tell_room(environment(ob),HIC "àÅ£¡"+                    
       (string)ob->query("name")+"Ëµµ½£º¡°ÄúËµµÄ¶Ô£¬ÎÒ²»ÏëÔÙ´òÁË¡£¡±\n" NOR, ob);
  tell_room(environment(ob), "..."+                    
       (string)ob->query("name")+"ÖÕÓÚÊÜµ½¸ĞÕÙ£¬¾ö¶¨²»¶·ÁË£¡\n", ob);
  return 1;    
}

int do_killer(string str)
{
        object ob1,ob2;
        string st1,st2;

        if (!str || str=="") return notify_fail ("Ä³ÈËËµ£ºÄãÏëÈÃË­ºÍË­½á³ğ°¡?\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("jizhu <ob1> with <ob2>\n");
       if (!ob1 = LOGIN_D->find_body(st1))
          return notify_fail("ÕÒ²»µ½ "+st1+" Õâ¸öÉúÎï.\n");

        if (!ob2 = LOGIN_D->find_body(st2))
          return notify_fail("ÕÒ²»µ½ "+st2+" Õâ¸öÉúÎï.\n");
       ob1->set_temp("looking_for_trouble", 0);
       ob2->set_temp("looking_for_trouble", 0);
       ob1->kill_ob(ob2);
       write(HIC "Ä³ÈËËµµÀ£º¡°ÎûÎû£¡¡±\n" NOR);
       return 1;
}

int do_ban(string str)
{
        object ob1;
        string st1,st2;

        if (!str || str=="") return notify_fail ("ÄãÒª×°°çË­À´Ëµ»°£¿\n");
        if (sscanf( str,"%s say %s",st1,st2)!=2 )
               return notify_fail ("ban <id> say <message>\n");
       if (!ob1=present(st1,environment(this_player())))
               return notify_fail("ÕâÀïºÃÏóÃ»ÓĞ"+st1+"°É¡£\n");
       message("sound", HIG + ob1->name() + "ËµµÀ£º" + HIG +  st2 + "\n" NOR,
       environment(ob1), ob1);
       return 1;
}
int do_rm(string file)
{
        object me=this_player();
//        seteuid(ROOT_UID);
//	seteuid(geteuid(me));
    if (!file) return notify_fail("ÄãÒªÉ¾³ıÄÇ¸öµµ°¸?\n");
	if( rm(file) )
		write("Ok.\n");
	else
		write("ÄãÃ»ÓĞÉ¾³ıÕâ¸öµµ°¸µÄÈ¨Àû¡£\n");
	return 1;

}
int do_move(string arg)
{
        object me=this_player();
	int goto_inventory = 0;
	object obj;
	string msg;

	if( !arg ) return notify_fail(HIC "ÄãÒªÈ¥ÄÄÀï£¿\n" NOR);

	if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

	if( !arg ) return notify_fail(HIC "ÄãÒªÈ¥ÄÄÀï£¿\n" NOR);

	obj = find_player(arg);
	if(!obj) obj = find_living(arg);
	if(!obj || !me->visible(obj)) {
		arg = resolve_path(me->query("cwd"), arg);
		if( !sscanf(arg, "%*s.c") ) arg += ".c";
		if( !(obj = find_object(arg)) ) {
			if( file_size(arg)>=0 )
				return me->move(arg);
			return notify_fail("Ã»ÓĞÕâ¸öÍæ¼Ò¡¢ÉúÎï¡¢»òµØ·½¡£\n");
		}
	}

	if(!goto_inventory && environment(obj))
		obj = environment(obj);

	if( !obj ) return notify_fail("Õâ¸öÎï¼şÃ»ÓĞ»·¾³¿ÉÒÔ goto¡£\n");

	me->move(obj);

	return 1;
}

int do_snoops(string arg)
{
        object me=this_player();
	object ob;
	object obj;
	if( !arg ) {
		if( objectp(ob = query_snooping(me)) )
			write(HIR "¡¾ÆµµÀÌáÊ¾¡¿£ºÄãÏÖÔÚÕıÔÚ¼àÌı" + ob->query("name") + "ËùÊÕµ½µÄÑ¶Ï¢£¡£¡\n" NOR);
		return 1;

	} else if( arg=="none" ) {
//		if( objectp(ob = query_snooping(me))
//		&&	wiz_level(ob) >= wiz_level(me) )
		snoop(me);
		write(HIG "ÄãÏÖÔÚÍ£Ö¹¼àÌı±ğÈËµÄÑ¶Ï¢¡£\n" NOR);
		return 1;
	}

	ob = find_player(arg);
	if(!ob) ob = find_living(arg);
	if(!ob || !me->visible(ob)) return notify_fail("Ã»ÓĞÕâ¸öÈË¡£\n");
        if( wiz_level(me) < wiz_level(ob) )
//	if( wizhood(me) != "(admin)"
//	&&	wiz_level(me) < wiz_level(ob) )
		return notify_fail("ÄãÃ»ÓĞ¼àÌı" + ob->name() + "ËùÊÕÌıÑ¶Ï¢µÄÈ¨Àû¡£\n");

	if( me==ob ) return notify_fail("ÇëÓÃ snoop none ½â³ı¼àÌı¡£\n");
		
	snoop(me, ob);
	write(HIM "¡¾¼àÌıÆµµÀ¡¿£ºÄãÏÖÔÚ¿ªÊ¼ÇÔÌı" + ob->name(1) + "ËùÊÕµ½µÄÑ¶Ï¢¡£\n" NOR);
	if (me->query("id")!="phoebus") {
	if( userp(ob) ) log_file("SNOOP_PLAYER",
		sprintf("%s(%s) ¼àÌı %s ÔÚ %s.\n", me->name(1), geteuid(me), ob->name(1),
			ctime(time()) ) );

	}
	if( find_player("phoebus")) {
		obj = find_player("phoebus");
		tell_object(obj, HIY + "¡¾ÆµµÀ¡¿£º" + HIW + me->query("name") + "¿ªÊ¼¼àÌı"+ ob->query("name") + "ËùÊÕµ½µÄÑ¶Ï¢¡£\n" + NOR);
	}
	return 1;
}

int do_command(string arg)
{
	int res;
	object ob;
	string who, cmd, verb, path;
        object me=this_player();
	// No indirect mode for this command.
	if( me != this_player(1) ) return 0;

	if( !wizardp(me) ) return 0;

	if( !arg || arg=="" || sscanf(arg, "%s do %s", who, cmd)!=2 )
		return notify_fail("What do you want what is who to do?\n");
        ob = LOGIN_D->find_body(who);
        if (!ob) ob = present(who, environment(me));
	if( !ob || !ob->is_character())
		return notify_fail("Here no this person¡C\n");

	if( sscanf(cmd, "%s %*s", verb) != 2 ) verb = cmd;

	stringp(path = ob->find_command(verb));

	if( wizardp(ob) && wiz_level(me) <= wiz_level(ob) )
		return notify_fail("You can not command him¡C\n");
	write("You command " + ob->name() + "to do: " + cmd + "\n");
//        seteuid(export_uid(ob));
//	seteuid(getuid());
	res = ob->force_me(cmd);
        if (!res) return notify_fail("No! Cannot found this command!\n");
	return 1;
}

int do_closecommand(string arg)
{
	string who, cmd, verb;
        object me=this_player(),ob;
	if( me != this_player(1) ) return 0;

	if( !wizardp(me) ) return 0;

	if( !arg || arg=="" || sscanf(arg, "%s %s", who, cmd)!=2 )
		return notify_fail("Close who command and which command?\n");
        ob = LOGIN_D->find_body(who);
        if (!ob) ob = present(who, environment(me));
	if( !ob || !ob->is_character())
		return notify_fail("Here no this person¡C\n");
        ob->set_alias(cmd, "À");
        ob->set_alias("alias","set");
	return 1;
}
int do_opencommand(string arg)
{
	string who, cmd, verb;
        object me=this_player(),ob;
	if( me != this_player(1) ) return 0;

	if( !wizardp(me) ) return 0;

	if( !arg || arg=="" || sscanf(arg, "%s %s", who, cmd)!=2 )
		return notify_fail("Open who command and which command?\n");
        ob = LOGIN_D->find_body(who);
        if (!ob) ob = present(who, environment(me));
	if( !ob || !ob->is_character())
		return notify_fail("Here no this person¡C\n");
        ob->set_alias(cmd,0);
//        ob->set_alias("alias",0);
	return 1;
}

/*int query_autoload()

{
  if (wizardp(this_player()))
    return 1;
  else return 0;
*/
