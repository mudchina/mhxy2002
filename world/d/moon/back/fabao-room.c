// By tianlin 2001.5.1
#include <ansi.h>
#include <weapon.h>
#include <armor.h>
#include <login.h>

inherit ROOM;

#define MAX_FABAO	3

int  do_sm();
int  do_dispose(string arg);
int  do_upgrade(string arg);
int  do_list();
int  do_cost(string arg);

void get_type(string arg, object ob);
void get_subtype(string arg, object ob);
void get_id(string arg, object ob);
void get_name(string arg, object ob);
void get_desc(string arg, object ob);
void get_unit(string arg, object ob);
void build_weapon(object ob);
void build_armor(object ob);
int check_legal_name(string name, int max_len);
int check_legal_id(string name);
void confirm_dispose(string arg, object ob, object fabao_ob);

void init()
{
	add_action("do_sm", "make_fabao");
	add_action("do_dispose", "dispose");
	add_action("do_list", "list");
	add_action("do_cost", "cost");
	add_action("do_upgrade", "upgrade");
	add_action("do_change_name", "change_name");
	add_action("do_change_id", "change_id");
	add_action("do_change_desc", "change_desc");
	add_action("do_change_unit", "change_unit");
	add_action("do_change_wield", "change_wield");
	add_action("do_change_unwield", "change_unwield");
       add_action("do_koujian","koujian");

	seteuid(getuid());
}

void create ()
{
        set ("short", "Å®æ´²¹Ìì´¦");
        set ("long", @LONG

ÕâÀïÊÇÒ»Æ¬¿ªÀ«µØ¡£µØÉÏÆÌÂúÁËÒ»¶ÑÓÖÒ»¶ÑÆæĞÎ¹Ö×´É«²Ê°ßìµµÄ
²ĞÑÒËéÊ¯£¬ÔÚÑ©É«Ó³ÕÕÏÂÒç²ÊÁ÷¹â¡£±ßÉÏÒ»¿é´óÊ¯ÉÏ¿Ì×Å¼¸ĞĞ´ó
×Ö£º

		[4;53mÀ¥ÂØ¾ø´¦[0m
		[4;53mÅ®æ´²¹Ìì[0m
		[4;53m²ÊÊ¯Î´¾¡[0m
		[4;53mÒÅ¸£ºóÈË[0m

µ×ÏÂ»¹ÃÜÃÜÂéÂéµØ¿ÌÁËÒ»ÆªĞ¡×Ö[1;33m(words)[0m£¬¸ôÔ¶ÁËÒ²¿´²»ÇåËµµÄÊÇ
Ê²Ã´¡£
LONG);

	set("item_desc", ([ "words" : 
		"make_fabao     Á¶ÖÆ·¨±¦\n" +
		"dispose        ×¢Ïû·¨±¦\n" +
		"list           ÁĞ¾Ù¿ÉÖÆ·¨±¦ÖÖÀà\n" +
		"upgrade        ·¨±¦ĞŞÁ¶\n" +
		"cost ·¨±¦      ·¨±¦Á¶ÖÆ¼°ĞŞÁ¶¿ÉÄÜ·ÑÓÃ\n" +
		"change_name    ¸ø·¨±¦¸ÄÃû\n" +
		"change_id      ¸ø·¨±¦¸Ä´úºÅ\n" +
		"change_desc    ¸ø·¨±¦¸ÄÃèÊö\n" +
		"change_wield   ¸ø·¨±¦¸Ä×°±¸ÉÏµÄÃèÊö\n" +
		"change_unwield ¸ø·¨±¦¸Ä·ÅÏÂÊ±µÄÃèÊö\n" +
		"change_unit    ¸ø·¨±¦¸Äµ¥Î»Ãû³Æ\n\n", ]) );

	set("exits", 
	([ //sizeof() == 1 
		"east" : __DIR__"fabao-road2",
	]));


	set("no_fight", 1);
	set("no_magic", 1);
	set("no_time",1);

	setup();
}

int do_sm()
{
	object me = this_player();
	int  fabao_num;
		   
	if( me->query("daoxing") < 20000)
		return notify_fail("ÄãµÄµÀĞĞÌ«µÍ£¬²»ÄÜ×ÔÔì·¨±¦¡£\n");

	if( RANK_D->grade_fali( RANK_D->describe_fali( (int)me->query("max_mana") ) ) 
                < RANK_D->grade_fali(HIB "ÌÚÔÆ¼ÜÎí" NOR) ) //max_mana 360+.
		return notify_fail("ÄãµÄ·¨Á¦ĞŞÎª²»¹»£¬ÎŞ·¨¿ØÖÆ·¨±¦¡£\n");
		
	if( me->query("max_force") < 300)
		return notify_fail("ÄãµÄÄÚÁ¦ĞŞÎª²»¹»£¬ÎŞÁ¦×ÔÔì·¨±¦¡£\n");
	
	if( me->query("force") < (me->query("max_force")+100) )
		return notify_fail("×îºÃÔÚÄÚÁ¦³äÅæÊ±×ÔÔì·¨±¦¡£\n");
	
	if( me->query("mana") < (me->query("max_mana")+100) )
		return notify_fail("ÄãµÄÄ¿Ç°·¨Á¦²»¹»³äÓ¯£¬ÎŞ·¨¿ØÖÆ·¨±¦¡£\n");
	
	fabao_num = 0;		
	if( me->query("fabao/weapon") )		fabao_num++;
	if( me->query("fabao/armor1") )		fabao_num++;
	if( me->query("fabao/armor2") )		fabao_num++;
	
	if( fabao_num >= MAX_FABAO )
		return notify_fail("Äã²»ÄÜÔÙÁ¶ÖÆ·¨±¦ÁË£¬ÇëÓÃ dispose ×¢Ïû²»ÒªµÄ·¨±¦¡£\n");
		
	write("ÄúÒªÔìÄÄÀà·¨±¦£º\n");
	if( !me->query("fabao/weapon") )
		write("w. ÎäÆ÷\n");
	if( !me->query("fabao/armor1") || !me->query("fabao/armor2") )
		write("a. ·À¾ß\n");
	write("o. ÆäËû(ÔİÈ±)\n");

	seteuid(getuid());
	// Other kinds of fabao can be added too.. if there is somefile
	// we can use as a default object.
	write("ÇëÑ¡Ôñ£º(q ¼üÈ¡Ïû)");
	input_to( (: get_type :), me );
	
	return 1;	
}

void get_type(string arg, object ob)
{
	if( arg == "q" || arg == "Q" )
	   return;

	if( (arg != "w" || ob->query("fabao/weapon"))
	  && (arg != "a" || ( ob->query("fabao/armor1")
	  && ob->query("fabao/armor2") )) )   {
		write("ÄúÒªÔìÄÄÀà·¨±¦£º\n");
		if( !ob->query("fabao/weapon") )
			write("w. ÎäÆ÷\n");
		if( !ob->query("fabao/armor1") || !ob->query("fabao/armor2") )
			write("a. ·À¾ß\n");
	    write("o. ÆäËû(ÔİÈ±)\n");
	    write("ÇëÑ¡Ôñ£º(q ¼üÈ¡Ïû)");
		input_to( (: get_type :), ob );
		return;
	}

	if( arg == "w" )    {
		ob->set_temp("fabao_type", "weapon");
		write("\n");
		write("¿ÉÑ¡ÔñÎäÆ÷ÖÖÀà£º\n");
		write("1. ¸«  2. µ¶  3. ²æ  4. ´¸  5. ïµ  6. Ç¹\n");
		write("7. ÕÈ  8. °ô  9. ½£  10. ±Ş\n");
	    write("ÇëÑ¡Ôñ£º(q ¼üÈ¡Ïû)");
	}
	else if( arg == "a" )   {
		ob->set_temp("fabao_type", "armor");
		write("\n");
		write("¿ÉÑ¡Ôñ·À¾ßÖÖÀà£º\n");
		write("1. ¼×  2. Ğ¬  3. ÒÂ·ş  4. Ö¸Ì×  5. »¤ÕÆ  6. Í·ÕÖ\n");
		write("7. ²±Ì×  8. ¶Ü  9. Åû·ç  10. »¤Íó  11. Ñü´ø\n");
	    write("ÇëÑ¡Ôñ£º(q ¼üÈ¡Ïû)");
	}
	input_to( (: get_subtype :), ob);
}

void get_subtype(string arg, object ob)
{
    int  order;
	string fabao_type = ob->query_temp("fabao_type");
   
	if( arg == "q" || arg == "Q" )    return;

    sscanf(arg, "%d", order);
    
	if( (fabao_type == "weapon" && order <= 0 && order > 10) ||
	  (fabao_type == "armor" && order <= 0 && order > 11) )  {
		if( arg == "w" )    {
			fabao_type = "weapon";
			write("\n");
			write("¿ÉÑ¡ÔñÎäÆ÷ÖÖÀà£º\n");
			write("1. ¸«  2. µ¶  3. ²æ  4. ´¸  5. ïµ  6. Ç¹\n");
			write("7. ÕÈ  8. °ô  9. ½£  10. ±Ş\n");
	        write("ÇëÑ¡Ôñ£º(q ¼üÈ¡Ïû)");
		}
		else if( arg == "a" )   {
			fabao_type = "armor";	
			write("\n");
			write("¿ÉÑ¡Ôñ·À¾ßÖÖÀà£º\n");
			write("1. ¼×  2. Ğ¬  3. ÒÂ·ş  4. Ö¸Ì×  5. »¤ÕÆ  6. Í·ÕÖ\n");
			write("7. ²±Ì×  8. ¶Ü  9. Åû·ç  10. »¤Íó  11. Ñü´ø\n");
	        write("ÇëÑ¡Ôñ£º(q ¼üÈ¡Ïû)");
		}
		ob->set_temp("fabao_type", fabao_type);
		input_to( (: get_subtype :), ob);
		return;
	}
	
	ob->set_temp("fabao_subtype",  order);

	write("\n");
	write("ÇëÉè¶¨Ó¢ÎÄ id £º");
	input_to( (: get_id :), ob ); 
}


int check_legal_id(string id)
{
	int i;
	string	*legalid;
	
	i = strlen(id);
    if( (strlen(id) < 3) || (strlen(id) > 20 ) ) {
		write("¶Ô²»Æğ£¬Ó¢ÎÄ id ±ØĞëÊÇ 3 µ½ 20 ¸öÓ¢ÎÄ×ÖÄ¸¡£\n");
		return 0;
    }
    while(i--)
    	if( id[i] != ' ' && (id[i]<'a' || id[i]>'z') )  {
    		write("¶Ô²»Æğ£¬Ó¢ÎÄ id Ö»ÄÜÓÃÓ¢ÎÄ×ÖÄ¸¡£\n");
    		return 0;
    	}
    
    legalid = explode(read_file(BANNED_ID), "\n");
    for(i=0; i<sizeof(legalid); i++)   {
    	if( id == legalid[i] )   {
    		write("¶Ô²»Æğ£¬ÕâÖÖ id »áÔì³ÉÆäËûÈËµÄÀ§ÈÅ¡£\n");
    		return 0;
    	}
    }
    
    return 1;
}

int check_legal_name(string name, int max_len)
{
	int i;
	string	*legalname;		//not implemented..may add later
	
	i = strlen(name);
    if( (strlen(name) < 2) || (strlen(name) > max_len ) ) {
    	write( sprintf("¶Ô²»Æğ£¬·¨±¦ÖĞÎÄ×Ö±ØĞëÊÇ 1 µ½ %d ¸öÖĞÎÄ×Ö¡£\n",
    	 max_len/2) );
		return 0;
    }
    while(i--)   {
    	if( name[i]<=' ' )   {
    		write("¶Ô²»Æğ£¬·¨±¦ÖĞÎÄ×Ö²»ÄÜÓÃ¿ØÖÆ×ÖÔª¡£\n");
    		return 0;
    	}
    	if( i%2==0 && !is_chinese(name[i..<0]) )  {
    		write("¶Ô²»Æğ£¬ÇëÄúÓÃ¡¸ÖĞÎÄ¡¹¸ø·¨±¦È¡Ãû×Ö¡£\n");
    		return 0;
    	}
    }
   
    return 1; 
}


void get_id(string arg, object ob)
{
	arg = lower_case(arg);
	if( !check_legal_id(arg) )   {
		write("ÇëÉè¶¨Ó¢ÎÄ id £º");
		input_to( (: get_id :), ob ); 
		return;
	}

	arg = replace_string(arg, " ", "_");	
	ob->set_temp("fabao_id",arg);
	
	write("\n");
	write("ÇëÉè¶¨ÖĞÎÄÃû£º(¿É¼ÓÑÕÉ«)");
	input_to( (: get_name :), ob);
}

void get_name(string arg, object ob)
{
	string  arg_old;
	
	arg += "$NOR$";
	arg_old = arg;
        arg = replace_string(arg, "$BLK$", "");
        arg = replace_string(arg, "$RED$", "");
        arg = replace_string(arg, "$GRN$", "");
        arg = replace_string(arg, "$YEL$", "");
        arg = replace_string(arg, "$BLU$", "");
        arg = replace_string(arg, "$MAG$", "");
        arg = replace_string(arg, "$CYN$", "");
        arg = replace_string(arg, "$WHT$", "");
        arg = replace_string(arg, "$HIR$", "");
        arg = replace_string(arg, "$HIG$", "");
        arg = replace_string(arg, "$HIY$", "");
        arg = replace_string(arg, "$HIB$", "");
        arg = replace_string(arg, "$HIM$", "");
        arg = replace_string(arg, "$HIC$", "");
        arg = replace_string(arg, "$HIW$", "");
        arg = replace_string(arg, "$NOR$", "");

	if( !check_legal_name(arg, 12) )  {
 	    write("ÇëÉè¶¨ÖĞÎÄÃû£º(¿É¼ÓÑÕÉ«)");
		input_to( (: get_name :), ob);
		return;
	}

	arg = arg_old;

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
	
	ob->set_temp("fabao_name", arg + NOR);
	
	write("\n");
	write("ÇëÃèÊö·¨±¦£º");
	input_to( (: get_desc :), ob);
}

void get_desc(string arg, object ob)
{
	if( !check_legal_name(arg, 60) )  {
		write("ÇëÃèÊö·¨±¦£º");
		input_to( (: get_desc :), ob);
		return;
	}

	ob->set_temp("fabao_desc",  arg);
	
	write("\n");
	write("·¨±¦ÓÃÁ¿´Ê£º(Return for default)");
	input_to( (: get_unit :), ob);
}


void get_unit(string arg, object ob)
{
	string fabao_unit, fabao_type;

    if( arg == "" )
       fabao_unit = "";
	else if( !check_legal_name(arg, 2) )  {
 	   write("·¨±¦ÓÃÁ¿´Ê£º(Return for defult)");
	   input_to( (: get_unit :), ob);
	   return;
    }
    else
       fabao_unit = arg; 
   
	fabao_type = ob->query_temp("fabao_type");
	ob->set_temp("fabao_unit", fabao_unit);
	if( fabao_type == "weapon" )
		build_weapon(ob);	
	else if( fabao_type == "armor" )
		build_armor(ob);	
	// may have more later
}

void build_weapon(object ob)
{
	object newob;
	string weapon_dir, ob_file;
	string *id_list, *t_list;
	int rev;
	int    fabao_subtype = ob->query_temp("fabao_subtype");
	string fabao_id = ob->query_temp("fabao_id");
	string fabao_name = ob->query_temp("fabao_name");
	string fabao_desc = ob->query_temp("fabao_desc");
	string fabao_unit = ob->query_temp("fabao_unit");
	
	newob = new("/obj/fabao");
	if(!newob)
		return;
		
	seteuid(fabao_id);
	rev = export_uid(newob);
	seteuid(getuid());

	newob->set("value", 1);
	newob->set("no_get", 1);	
	newob->set("no_give", 1);	
	newob->set("no_sell", 1);	
	newob->set("no_drop", 1);	
	newob->set("no_put", 1);	
	
	weapon_dir = "/d/obj/weapon/";
	newob->set("weapon_prop/damage", 10);
	newob->set("flag", TWO_HANDED);
	newob->set("weight", 1000);
	switch( fabao_subtype )   {
		case 1:
			ob_file = weapon_dir + "axe/bigaxe";
			break;
		case 2:
			ob_file = weapon_dir + "blade/blade";
			break;
		case 3:
			ob_file = weapon_dir + "fork/gangcha";
			break;
		case 4:
			ob_file = weapon_dir + "hammer/hammer";
			break;
		case 5:
			ob_file = weapon_dir + "mace/ironmace";
			break;
		case 6:
			ob_file = weapon_dir + "spear/gangqiang";
			break;
		case 7:
			ob_file = weapon_dir + "staff/muzhang";
			break;
		case 8:
			ob_file = weapon_dir + "stick/qimeigun";
			break;
		case 9:
			ob_file = weapon_dir + "sword/changjian";
			break;
		case 10:
			ob_file = weapon_dir + "whip/pibian";
			break;
	}

	newob->set_default_object( ob_file );
	
	newob->set("long", fabao_desc);

	newob->set("fabao/max_attack_qi", 1);
	newob->set("fabao/max_attack_shen", 1);
	
	if( fabao_unit != "" )
	   newob->set("unit", fabao_unit);
	id_list = ({ fabao_id });
	t_list = explode( fabao_id, "_");
	if( sizeof(t_list) > 1 )   {
		id_list += t_list;
	}
	newob->set_name( fabao_name, id_list ); 

	// set owner of fabao
	newob->set("owner_id", getuid(ob));
	newob->set("series_no", "1");
	newob->set("default_file", ob_file);


    newob->save();	

	ob->add("force", -200);
	ob->add("mana", -200);

	ob->set("fabao/weapon",  newob->query("series_no"));
	//make a mark: attack fabao already made

	newob->setup();
	if( !newob->move(ob) )
	   newob->move(environment(ob));
	ob->save();
	
	write("·¨±¦Á¶ÖÆ³É¹¦¡£\n");

	return;
}

void build_armor(object ob)
{
	object	newob;
	string	armor_dir, ob_file;
	string	*id_list, *t_list;
	int		rev;
	string  fabao_id = ob->query_temp("fabao_id");
	string  fabao_name = ob->query_temp("fabao_name");
	string  fabao_desc = ob->query_temp("fabao_desc");
	string  fabao_unit = ob->query_temp("fabao_unit");
	int     fabao_subtype = ob->query_temp("fabao_subtype");

	newob = new("/obj/fabao");
	if(!newob)
		return;
	
	seteuid(fabao_id);
	rev = export_uid(newob);
	seteuid(getuid());

	newob->set("value", 1);
	newob->set("no_get", 1);	
	newob->set("no_sell", 1);	
	newob->set("no_give", 1);	
	newob->set("no_drop", 1);	
	newob->set("no_put", 1);	

	armor_dir = "/d/obj/";
	newob->set("armor_prop/armor", 5);		
	newob->set("armor_prop/dodge", 0);		
	newob->set("armor_prop/spells", 0);
	newob->set("weight", 1000);
	// anything else need to be set?
	
	switch( fabao_subtype )   {
	
	// Add ob_file if you can find the same kind of file
		case 1:
			ob_file = armor_dir + "armor/tenjia";
			break;
		case 2:
			ob_file = armor_dir + "cloth/buxie";
			break;
		case 3:
			ob_file = armor_dir + "cloth/linen";
			break;
		case 4:
			ob_file = armor_dir + "cloth/ring";
			break;
		case 5:
			ob_file = armor_dir + "cloth/gloves";
			break;
		case 6:
			ob_file = armor_dir + "cloth/hat";
			break;
		case 7:
			ob_file = armor_dir + "cloth/necklace";
			break;
		case 8:
			ob_file = armor_dir + "armor/niupi";
			break;
		case 9:
			ob_file = armor_dir + "cloth/surcoat";
			break;
		case 10:
			ob_file = armor_dir + "cloth/wrists";
			break;
		case 11:
			ob_file = armor_dir + "cloth/belt";
			break;
	}
	
	newob->set_default_object( ob_file );
	
	newob->set("long", fabao_desc);

	newob->set("fabao/max_defense_qi", 1);
	newob->set("fabao/max_defense_shen", 1);
	newob->set("fabao/max_defense_shou", 1);

	if( fabao_unit != "" )
	   newob->set("unit", fabao_unit);
	id_list = ({ fabao_id });
	t_list = explode( fabao_id, "_");
	if( sizeof(t_list) > 1 )   {
		id_list += t_list;
	}
	newob->set_name( fabao_name, id_list ); 

	// set owner of fabao
	newob->set("owner_id", getuid(ob));
	if( !ob->query("fabao/armor1") )
		newob->set("series_no", "2");
	else if( !ob->query("fabao/armor2") )
		newob->set("series_no", "3");
	newob->set("default_file", ob_file);

    newob->save();	

	ob->add("force", -200);
	ob->add("mana", -200);
	
	if( !ob->query("fabao/armor1") )
		ob->set("fabao/armor1",  newob->query("series_no"));
	else if( !ob->query("fabao/armor2") )
		ob->set("fabao/armor2",  newob->query("series_no"));
	
	newob->setup();
	if( !newob->move(ob) )
	   newob->move(environment(ob));
	ob->save();

	write("·¨±¦Á¶ÖÆ³É¹¦¡£\n");
	
	return;
}

int  do_dispose(string arg)
{
   object ob = this_player();
   object fabao_ob;
  
   if( !arg || arg == "" )
	  return notify_fail("ÄãÒªÏû³ıÊ²Ã´·¨±¦£¿\n");

   if( !objectp(fabao_ob=present(arg, ob)) )
      return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷°¡¡£\n");
      
   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("ÄÇ¸ö²»ÊÇ·¨±¦Ò®£¡\n");
      
   write("ÄãÈ·¶¨Òª»ÙÃğ¸Ã·¨±¦Âğ£¿(y/n)");
   input_to( (: confirm_dispose :), ob, fabao_ob); 
   return 1;
}

void confirm_dispose(string arg, object ob, object fabao_ob)
{
   mapping  fabao_list;
   string*  names;
   string fabao_name;
   int      i;

   if( arg == "y" || arg == "Y" )  {
	  fabao_list = ob->query("fabao");
	  if( !mapp(fabao_list) )		return;
	  names = keys(fabao_list);
	  for(i=0; i<sizeof(names); i++)  {
		 if( fabao_list[names[i]] == fabao_ob->query("series_no") )  {
			//seteuid(getuid(ob));
			//rm( fabao_ob->query_save_file() + __SAVE_EXTENSION__ );
			ob->delete("fabao/"+names[i]);
			fabao_name = fabao_ob->query("name");
			destruct( fabao_ob );
			write("Ö»Ìıºä£¡µÄÒ»Éù£¬"+fabao_name+"Õ¨ÁË¿ªÀ´¡£\n");
			break;
		 }
	  }
   }

   return;
}

int  do_list()
{
	write("Ä¿Ç°¿ÉÔì·¨±¦ÖÖÀàÓĞ£º\n\n");   
	write("w. ÎäÆ÷Àà£º\n");
	write("       ¸«  µ¶  ²æ  ´¸  ïµ  Ç¹\n");
	write("       ÕÈ  °ô  ½£  ±Ş¡£\n\n");
	write("a. »¤¾ßÀà£º\n");
	write("       »¤¼×  Ğ¬  ÒÂ·ş  Ö¸Ì×  »¤ÕÆ  Í·ÕÖ\n");
	write("       ²±Ì×  ¶Ü  Åû·ç  »¤Íó  Ñü´ø¡£\n\n");

	write("Ä¿Ç°·¨±¦¿ÉĞŞÁ¶ÖÖÀà£º\n\n");
	write("w. ÎäÆ÷Àà£º\n");
	write("       ÆøÑªÉËº¦Á¦(attack_qi)£¬\n"); //0-25
	write("       ¾«ÉñÉËº¦Á¦(attack_shen)¡£\n\n");//0-25
	write("a. »¤¾ßÀà£º\n");
	write("       ÆøÑª±£»¤Á¦(defense_qi)£¬\n");//0-25
	write("       ¾«Éñ±£»¤Á¦(defense_shen)£¬\n");//0-25
	write("       ÊÕÈ¡µĞÈË·¨±¦(defense_shou)¡£\n\n");//0-25

	return 1;
}

int do_cost(string arg)
{
	int neili_req, fali_req, dx_req;
	int neili_cost, fali_cost, dx_cost;
	int a_qi, a_shen, d_qi, d_shen, d_shou;

	object fabao_ob, me=this_player();
   
	if( !arg || arg == "" )  
	{
		write("ÖÆÔì·¨±¦µÀĞĞ±ØĞëÔÚ¶şÊ®ÄêÒÔÉÏ£¬·¨Á¦ĞŞÎªÖÁÉÙÄÜÌÚÔÆ¼İÎí£¬ÄÚÁ¦ĞŞÎªÖÁÉÙÈıÄêÒÔÉÏ·½¿É¡£\n");
		write("ĞŞÁ¶·¨±¦Ôò¸ú·¨±¦Ç¿¶ÈÓĞ¹Ø£¬ĞèÒªËğºÄµÀĞĞ£¬·¨Á¦£¬ÄÚÁ¦µÈ¡£\n");		
		return 1;
	}
  
	if( !objectp(fabao_ob=present(arg, me)) )
		return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷°¡¡£\n");
      
	if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
		return notify_fail("ÄÇ¸ö²»ÊÇ·¨±¦Ò®£¡\n");
      
	a_qi = fabao_ob->query("fabao/max_attack_qi");
	a_shen = fabao_ob->query("fabao/max_attack_shen");
	d_qi = fabao_ob->query("fabao/max_defense_qi");
	d_shen = fabao_ob->query("fabao/max_defense_shen");
	d_shou = fabao_ob->query("fabao/max_defense_shou");

	if( fabao_ob->query("series_no") == "1" )  
	{
		write( fabao_ob->show_status() );
		
		if(a_qi >= 25 )
			write("ÆøÑªÉËº¦Á¦ÒÑĞŞÁ·µ½¶¥¡£\n\n");
		else
		{
			dx_req = (a_qi + 1)*100000;
			neili_req =  ( a_qi + 1)*200;
			dx_cost = ( a_qi + 1)*1000;
			neili_cost = (a_qi + 1)*3;
			
			write("©¤©¤©¤ĞŞÁ¶ÆøÑªÉËº¦Á¦(attack_qi)©¤©¤©¤\n");
			write("ÒªÇó£ºµÀĞĞ"+chinese_number(dx_req/1000)+"Äê£¬ÄÚÁ¦ĞŞÎª"+chinese_number(neili_req/100)+"Äê¡£\n");
			write("ËğºÄ£ºµÀĞĞ"+chinese_number(dx_cost/1000)+"Äê£¬ÄÚÁ¦ĞŞÎª"+chinese_number(neili_cost)+"µã(100µãÏàµ±ÓÚÒ»Äê)¡£\n\n");
		}

		if( a_shen >= 25 )
			write("¾«ÉñÉËº¦Á¦ÒÑĞŞÁ·µ½¶¥¡£\n\n");
		else
		{
			dx_req = ( a_shen + 1)*100000;
			fali_req =  ( a_shen + 1)*200;
			dx_cost = (a_shen + 1)*1000;
			fali_cost = ( a_shen + 1)*3;
			
			write("©¤©¤©¤ĞŞÁ¶¾«ÉñÉËº¦Á¦(attack_shen)©¤©¤©¤\n");
			write("ÒªÇó£ºµÀĞĞ"+chinese_number(dx_req/1000)+"Äê£¬·¨Á¦ĞŞÎª"+RANK_D->describe_fali(fali_req)+"¡£\n");
			write("ËğºÄ£ºµÀĞĞ"+chinese_number(dx_cost/1000)+"Äê£¬·¨Á¦ĞŞÎª"+chinese_number(fali_cost)+"µã¡£\n\n");
		}
	}

	else
	{//fabao is defense type
		write( fabao_ob->show_status() );
		
		if( d_qi >= 25 )
			write("ÆøÑª±£»¤Á¦ÒÑĞŞÁ·µ½¶¥¡£\n\n");
		else
		{
			dx_req = ( d_qi + 1)*100000;
			neili_req =  ( d_qi + 1)*200;
			dx_cost = ( d_qi + 1)*1000;
			neili_cost = ( d_qi + 1)*3;
			
			write("©¤©¤©¤ĞŞÁ¶ÆøÑª±£»¤Á¦(defense_qi)©¤©¤©¤\n");
			write("ÒªÇó£ºµÀĞĞ"+chinese_number(dx_req/1000)+"Äê£¬ÄÚÁ¦ĞŞÎª"+chinese_number(neili_req/100)+"Äê¡£\n");
			write("ËğºÄ£ºµÀĞĞ"+chinese_number(dx_cost/1000)+"Äê£¬ÄÚÁ¦ĞŞÎª"+chinese_number(neili_cost)+"µã(100µãÏàµ±ÓÚÒ»Äê)¡£\n\n");
		}

		if( d_shen >= 25 )
			write("¾«Éñ±£»¤Á¦ÒÑĞŞÁ·µ½¶¥¡£\n\n");
		else
		{
			dx_req = ( d_shen + 1)*100000;
			fali_req =  ( d_shen + 1)*200;
			dx_cost = ( d_shen + 1)*1000;
			fali_cost = ( d_shen + 1)*3;
			
			write("©¤©¤©¤ĞŞÁ¶¾«ÉñÉËº¦Á¦(defense_shen)©¤©¤©¤\n");
			write("ÒªÇó£ºµÀĞĞ"+chinese_number(dx_req/1000)+"Äê£¬·¨Á¦ĞŞÎª"+RANK_D->describe_fali(fali_req)+"¡£\n");
			write("ËğºÄ£ºµÀĞĞ"+chinese_number(dx_cost/1000)+"Äê£¬·¨Á¦ĞŞÎª"+chinese_number(fali_cost)+"µã¡£\n\n");
		}

		if( d_shou >= 25 )
			write("·¨±¦ÊÕÈ¡Á¦ÒÑĞŞÁ·µ½¶¥¡£\n\n");
		else
		{
			dx_req = ( d_shou + 1)*100000;
			fali_req =  ( d_shou + 1)*200;
			neili_req =  ( d_shou + 1)*200;
			dx_cost = ( d_shou + 1)*1000;
			fali_cost = ( d_shou + 1)*3;
			neili_cost = ( d_shou + 1)*3;
			
			write("©¤©¤©¤ĞŞÁ¶·¨±¦ÊÕÈ¡Á¦(defense_shou)©¤©¤©¤\n");
			write("ÒªÇó£ºµÀĞĞ"+chinese_number(dx_req/1000)+"Äê£¬·¨Á¦ĞŞÎª"+RANK_D->describe_fali(fali_req)+"£¬ÄÚÁ¦ĞŞÎª"+chinese_number(neili_req/100)+"Äê¡£\n");
			write("ËğºÄ£ºµÀĞĞ"+chinese_number(dx_cost/1000)+"Äê£¬·¨Á¦ĞŞÎª"+chinese_number(fali_cost)+"µã£¬ÄÚÁ¦ĞŞÎª"+chinese_number(neili_cost)+"µã(100µãÏàµ±ÓÚÒ»Äê)¡£\n\n");
		}
	}
   
	return 1;
}

int  do_upgrade(string arg)
{
	int neili_req, fali_req, dx_req;
	int neili_cost, fali_cost, dx_cost;
	int a_qi, a_shen, d_qi, d_shen, d_shou;
	int my_dx, my_fali, my_neili;

	string name, property;
	object fabao_ob, me=this_player();
  
	if( !arg || arg == "")   
	{
		write("ÇëÓÃ upgrade <·¨±¦Ãû> for <ĞŞÁ¶ÌØĞÔ> À´ĞŞÁ¶¡£\n");
		write("ĞŞÁ¶ÌØĞÔ¿ÉÓÃ cost <·¨±¦Ãû> À´²é¿´¡£\n");
		return 1;
	}
      
	if( sscanf(arg, "%s for %s", name, property) != 2)  
	{
		write("ÇëÓÃ upgrade <·¨±¦Ãû> for <ĞŞÁ¶ÌØĞÔ> À´ĞŞÁ¶¡£\n");
		write("ĞŞÁ¶ÌØĞÔ¿ÉÓÃ cost <·¨±¦Ãû> À´²é¿´¡£\n");
		return 1;
	}
   
	if( !objectp(fabao_ob=present(name, me)) )
		return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷°¡¡£\n");
      
	if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
		return notify_fail("ÄÇ¸ö²»ÊÇ·¨±¦Ò®£¡\n");
     
	if( fabao_ob->query("equipped") )
		return notify_fail("Äã±ØĞë·ÅÏÂ·¨±¦²ÅÄÜĞŞÁ¶¡£\n");

	a_qi = fabao_ob->query("fabao/max_attack_qi");
	a_shen = fabao_ob->query("fabao/max_attack_shen");
	d_qi = fabao_ob->query("fabao/max_defense_qi");
	d_shen = fabao_ob->query("fabao/max_defense_shen");
	d_shou = fabao_ob->query("fabao/max_defense_shou");
          
	my_dx = me->query("daoxing");
	my_fali = me->query("max_mana");
	my_neili = me->query("max_force");

	if( fabao_ob->query("series_no") == "1")  
	{// weapon
		if( property == "attack_qi" )
		{
			if(a_qi >= 25 )
				return notify_fail("Õâ¼ş·¨±¦µÄÆøÑªÉËº¦Á¦ÒÑĞŞÁ·µ½¶¥¡£\n");

			dx_req = (a_qi + 1)*100000;
			neili_req =  ( a_qi + 1)*200;
			dx_cost = ( a_qi + 1)*1000;
			neili_cost = (a_qi + 1)*3;
			
			if( my_dx < dx_req )
				return notify_fail("ÒÔÄãµÄµÀĞĞ£¬Ä¿Ç°»¹²»ÄÜĞŞÁ¶Õâ¸ö·¨±¦µÄÆøÑªÉËº¦Á¦¡£\n");
			if( my_neili < neili_req )
				return notify_fail("ÒÔÄãµÄÄÚÁ¦ĞŞÎª£¬Ä¿Ç°»¹²»ÄÜĞŞÁ¶Õâ¸ö·¨±¦µÄÆøÑªÉËº¦Á¦¡£\n");
			//now, let's upgrade...
			me->add("daoxing", -dx_cost);
			me->add("max_force", -neili_cost);
			fabao_ob->set("fabao/max_attack_qi", a_qi+1);
			fabao_ob->add("weapon_prop/damage", 3);//will be 75+10 in max.
			me->save();
			fabao_ob->save();
			message_vision(HIR "$N»º»º½«ÄÚÁ¦×¢Èë$nÖĞ£¬Ö»¼û$n·Å³öÎå²ÊÏ¼¹â£¬»¶Ìø²»Ö¹£¡\n" NOR, me, fabao_ob);
			return 1;
		}

		else if( property == "attack_shen" )
		{
			if(a_shen >= 25 )
				return notify_fail("Õâ¼ş·¨±¦µÄ¾«ÉñÉËº¦Á¦ÒÑĞŞÁ·µ½¶¥¡£\n");

			dx_req = (a_shen + 1)*100000;
			fali_req =  ( a_shen + 1)*200;
			dx_cost = ( a_shen + 1)*1000;
			fali_cost = (a_shen + 1)*3;
			
			if( my_dx < dx_req )
				return notify_fail("ÒÔÄãµÄµÀĞĞ£¬Ä¿Ç°»¹²»ÄÜĞŞÁ¶Õâ¸ö·¨±¦µÄ¾«ÉñÉËº¦Á¦¡£\n");
			if( my_fali < fali_req )
				return notify_fail("ÒÔÄãµÄ·¨Á¦ĞŞÎª£¬Ä¿Ç°»¹²»ÄÜĞŞÁ¶Õâ¸ö·¨±¦µÄ¾«ÉñÉËº¦Á¦¡£\n");
			//now, let's upgrade...
			me->add("daoxing", -dx_cost);
			me->add("max_mana", -fali_cost);
			fabao_ob->set("fabao/max_attack_shen", a_shen+1);
			me->save();
			fabao_ob->save();
			message_vision(HIR "$N»º»º½«·¨Á¦×¢Èë$nÖĞ£¬Ö»¼û$n·Å³öÎå²ÊÏ¼¹â£¬»¶Ìø²»Ö¹£¡\n" NOR, me, fabao_ob);
			return 1;
		}

		else 
		{
			return notify_fail("Õâ¼ş·¨±¦Ã»ÓĞÕâ¸öĞŞÁ¶ÌØĞÔ£¬ÇëÓÃ cost <·¨±¦Ãû> À´²é¿´¡£\n");
		}
	}
	
	else //armor
	{
		if( property == "defense_qi" )
		{
			if(d_qi >= 25 )
				return notify_fail("Õâ¼ş·¨±¦µÄÆøÑª±£»¤Á¦ÒÑĞŞÁ·µ½¶¥¡£\n");

			dx_req = (d_qi + 1)*100000;
			neili_req =  ( d_qi + 1)*200;
			dx_cost = ( d_qi + 1)*1000;
			neili_cost = (d_qi + 1)*3;
			
			if( my_dx < dx_req )
				return notify_fail("ÒÔÄãµÄµÀĞĞ£¬Ä¿Ç°»¹²»ÄÜĞŞÁ¶Õâ¸ö·¨±¦µÄÆøÑª±£»¤Á¦¡£\n");
			if( my_neili < neili_req )
				return notify_fail("ÒÔÄãµÄÄÚÁ¦ĞŞÎª£¬Ä¿Ç°»¹²»ÄÜĞŞÁ¶Õâ¸ö·¨±¦µÄÆøÑª±£»¤Á¦¡£\n");
			//now, let's upgrade...
			me->add("daoxing", -dx_cost);
			me->add("max_force", -neili_cost);
			fabao_ob->set("fabao/max_defense_qi", d_qi+1);
			me->save();
			fabao_ob->save();
			message_vision(HIR "$N»º»º½«ÄÚÁ¦×¢Èë$nÖĞ£¬Ö»¼û$n·Å³öÎå²ÊÏ¼¹â£¬»¶Ìø²»Ö¹£¡\n" NOR, me, fabao_ob);
			return 1;
		}

		else if( property == "defense_shen" )
		{
			if(d_shen >= 25 )
				return notify_fail("Õâ¼ş·¨±¦µÄ¾«Éñ±£»¤Á¦ÒÑĞŞÁ·µ½¶¥¡£\n");

			dx_req = (d_shen + 1)*100000;
			fali_req =  ( d_shen + 1)*200;
			dx_cost = ( d_shen + 1)*1000;
			fali_cost = (d_shen + 1)*3;
			
			if( my_dx < dx_req )
				return notify_fail("ÒÔÄãµÄµÀĞĞ£¬Ä¿Ç°»¹²»ÄÜĞŞÁ¶Õâ¸ö·¨±¦µÄ¾«Éñ±£»¤Á¦¡£\n");
			if( my_fali < fali_req )
				return notify_fail("ÒÔÄãµÄ·¨Á¦ĞŞÎª£¬Ä¿Ç°»¹²»ÄÜĞŞÁ¶Õâ¸ö·¨±¦µÄ¾«Éñ±£»¤Á¦¡£\n");
			//now, let's upgrade...
			me->add("daoxing", -dx_cost);
			me->add("max_mana", -fali_cost);
			fabao_ob->set("fabao/max_defense_shen", d_shen+1);
			me->save();
			fabao_ob->save();
			message_vision(HIR "$N»º»º½«·¨Á¦×¢Èë$nÖĞ£¬Ö»¼û$n·Å³öÎå²ÊÏ¼¹â£¬»¶Ìø²»Ö¹£¡\n" NOR, me, fabao_ob);
			return 1;
		}

		else if( property == "defense_shou" )
		{
			if(d_shou >= 25 )
				return notify_fail("Õâ¼ş·¨±¦µÄ·¨±¦ÊÕÈ¡Á¦ÒÑĞŞÁ·µ½¶¥¡£\n");

			dx_req = (d_shou + 1)*100000;
			fali_req =  ( d_shou + 1)*200;
			dx_cost = ( d_shou + 1)*1000;
			fali_cost = (d_shou + 1)*3;
			
			if( my_dx < dx_req )
				return notify_fail("ÒÔÄãµÄµÀĞĞ£¬Ä¿Ç°»¹²»ÄÜĞŞÁ¶Õâ¸ö·¨±¦µÄ·¨±¦ÊÕÈ¡Á¦¡£\n");
			if( my_fali < fali_req )
				return notify_fail("ÒÔÄãµÄ·¨Á¦ĞŞÎª£¬Ä¿Ç°»¹²»ÄÜĞŞÁ¶Õâ¸ö·¨±¦µÄ·¨±¦ÊÕÈ¡Á¦¡£\n");
			//now, let's upgrade...
			me->add("daoxing", -dx_cost);
			me->add("max_mana", -fali_cost);
			fabao_ob->set("fabao/max_defense_shou", d_shou+1);
			me->save();
			fabao_ob->save();
			message_vision(HIR "$N»º»º½«·¨Á¦×¢Èë$nÖĞ£¬Ö»¼û$n·Å³öÎå²ÊÏ¼¹â£¬»¶Ìø²»Ö¹£¡\n" NOR, me, fabao_ob);
			return 1;
		}

		else 
		{
			return notify_fail("Õâ¼ş·¨±¦Ã»ÓĞÕâ¸öĞŞÁ¶ÌØĞÔ£¬ÇëÓÃ cost <·¨±¦Ãû> À´²é¿´¡£\n");
		}
	}      
}

int  do_change_name(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
  
   if( !arg || arg == "") 
      return notify_fail("ÇëÓÃ change_name <·¨±¦> <ĞÂÖĞÎÄÃû> À´¸ÄÃû¡£\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("ÇëÓÃ change_name <·¨±¦> <ĞÂÖĞÎÄÃû> À´¸ÄÃû¡£\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷°¡¡£\n");

   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("ÄÇ¸ö²»ÊÇ·¨±¦Ò®£¡\n");

   if( fabao_ob->query("equipped") )
      return notify_fail("Äã±ØĞë·ÅÏÂ·¨±¦²ÅÄÜ¸ÄÃû¡£\n");
   
   newname += "$NOR$";      
   arg = newname;
            
        arg = replace_string(arg, "$BLK$", "");
        arg = replace_string(arg, "$RED$", "");
        arg = replace_string(arg, "$GRN$", "");
        arg = replace_string(arg, "$YEL$", "");
        arg = replace_string(arg, "$BLU$", "");
        arg = replace_string(arg, "$MAG$", "");
        arg = replace_string(arg, "$CYN$", "");
        arg = replace_string(arg, "$WHT$", "");
        arg = replace_string(arg, "$HIR$", "");
        arg = replace_string(arg, "$HIG$", "");
        arg = replace_string(arg, "$HIY$", "");
        arg = replace_string(arg, "$HIB$", "");
        arg = replace_string(arg, "$HIM$", "");
        arg = replace_string(arg, "$HIC$", "");
        arg = replace_string(arg, "$HIW$", "");
        arg = replace_string(arg, "$NOR$", "");
        
   if( !check_legal_name(arg, 12) )   {
      return 1; 
   }
  
   arg = newname;
    
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
  
   fabao_ob->set("name", arg);
   fabao_ob->save();     
   
   write("¸Ä¶¯³É¹¦¡£\n");
   return 1;
}
      
int  do_change_id(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
   string *id_list, *t_list;
  
   if( !arg || arg == "") 
      return notify_fail("ÇëÓÃ change_id <·¨±¦> <ĞÂÓ¢ÎÄÃû> À´¸ÄÃû¡£\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("ÇëÓÃ change_id <·¨±¦> <ĞÂÓ¢ÎÄÃû> À´¸ÄÃû¡£\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷°¡¡£\n");

   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("ÄÇ¸ö²»ÊÇ·¨±¦Ò®£¡\n");

   if( fabao_ob->query("equipped") )
      return notify_fail("Äã±ØĞë·ÅÏÂ·¨±¦²ÅÄÜ¸ÄÃû¡£\n");

   if( !check_legal_id( newname ) )		return 1;
  
   newname = replace_string(newname, " ", "_"); 
   fabao_ob->set("id", newname);

   id_list = ({ newname });
   t_list = explode( newname, "_");
   if( sizeof(t_list) > 1 )   {
	  id_list += t_list;
   }
   fabao_ob->set_name( fabao_ob->query("name"), id_list ); 
   fabao_ob->save();
	
   write("¸Ä¶¯³É¹¦¡£\n");
   return 1;
}

      
int  do_change_desc(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
  
   if( !arg || arg == "") 
      return notify_fail("ÇëÓÃ change_desc <·¨±¦> <ĞÂÃèÊö> À´ÖØĞÂÃèÊö·¨±¦¡£\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("ÇëÓÃ change_desc <·¨±¦> <ĞÂÃèÊö> À´ÖØĞÂÃèÊö·¨±¦¡£\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷°¡¡£\n");

   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("ÄÇ¸ö²»ÊÇ·¨±¦Ò®£¡\n");

   if( fabao_ob->query("equipped") )
      return notify_fail("Äã±ØĞë·ÅÏÂ·¨±¦²ÅÄÜ¸ÄÃû¡£\n");

   if( !check_legal_name(newname, 80 ) )		return 1;
   
   fabao_ob->set("long", newname);
   fabao_ob->save();
   
   write("¸Ä¶¯³É¹¦¡£\n");
   return 1;
}
      
int  do_change_unit(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
  
   if( !arg || arg == "") 
      return notify_fail("ÇëÓÃ change_unit <·¨±¦> <µ¥Î»> À´Ö¸¶¨·¨±¦µ¥Î»¡£\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("ÇëÓÃ change_unit <·¨±¦> <µ¥Î»> À´Ö¸¶¨·¨±¦µ¥Î»¡£\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷°¡¡£\n");

   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("ÄÇ¸ö²»ÊÇ·¨±¦Ò®£¡\n");

   if( fabao_ob->query("equipped") )
      return notify_fail("Äã±ØĞë·ÅÏÂ·¨±¦²ÅÄÜ¸ÄÃû¡£\n");

   if( !check_legal_name(newname, 2 ) )		return 1;
   
   fabao_ob->set("desc", newname);
   fabao_ob->save();
   
   write("¸Ä¶¯³É¹¦¡£\n");
   return 1;
}

int  do_change_wield(string arg)//this is by tianlin 2001.5.1
{
   string name, newname;
   object fabao_ob, me=this_player();
  
   if( !arg || arg == "") 
      return notify_fail("ÇëÓÃ change_wield <·¨±¦> <ĞÂµÄ×°±¸ÃèÊö> À´¸ÄÃèÊö¡£\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("ÇëÓÃ change_wield <·¨±¦> <ĞÂµÄ×°±¸ÃèÊö> À´¸ÄÃèÊö¡£\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷°¡¡£\n");

   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("ÄÇ¸ö²»ÊÇ·¨±¦Ò®£¡\n");

   if( fabao_ob->query("equipped") )
      return notify_fail("Äã±ØĞë·ÅÏÂ·¨±¦²ÅÄÜ¸ÄÃû¡£\n");
   
   newname += "$NOR$";      
   arg = newname;
            
        arg = replace_string(arg, "$BLK$", "");
        arg = replace_string(arg, "$RED$", "");
        arg = replace_string(arg, "$GRN$", "");
        arg = replace_string(arg, "$YEL$", "");
        arg = replace_string(arg, "$BLU$", "");
        arg = replace_string(arg, "$MAG$", "");
        arg = replace_string(arg, "$CYN$", "");
        arg = replace_string(arg, "$WHT$", "");
        arg = replace_string(arg, "$HIR$", "");
        arg = replace_string(arg, "$HIG$", "");
        arg = replace_string(arg, "$HIY$", "");
        arg = replace_string(arg, "$HIB$", "");
        arg = replace_string(arg, "$HIM$", "");
        arg = replace_string(arg, "$HIC$", "");
        arg = replace_string(arg, "$HIW$", "");
        arg = replace_string(arg, "$NOR$", "");
        
   if( !check_legal_name(arg, 80) )   {
      return 1; 
   }
  
   arg = newname;
    
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
  
   fabao_ob->set("wield_msg", arg);
   fabao_ob->save();
   
   write("¸Ä¶¯³É¹¦¡£\n");
   return 1;
}
int  do_change_unwield(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
  
   if( !arg || arg == "") 
      return notify_fail("ÇëÓÃ change_unwield <·¨±¦> <ĞÂ·ÅÏÂÎäÆ÷ÃèÊö> À´¸ÄÃèÊö¡£\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("ÇëÓÃ change_unwield <·¨±¦> <ĞÂ·ÅÏÂÎäÆ÷ÃèÊö> À´¸ÄÃèÊö¡£\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷°¡¡£\n");

   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("ÄÇ¸ö²»ÊÇ·¨±¦Ò®£¡\n");

   if( fabao_ob->query("equipped") )
      return notify_fail("Äã±ØĞë·ÅÏÂ·¨±¦²ÅÄÜ¸ÄÃû¡£\n");
   
   newname += "$NOR$";      
   arg = newname;
            
        arg = replace_string(arg, "$BLK$", "");
        arg = replace_string(arg, "$RED$", "");
        arg = replace_string(arg, "$GRN$", "");
        arg = replace_string(arg, "$YEL$", "");
        arg = replace_string(arg, "$BLU$", "");
        arg = replace_string(arg, "$MAG$", "");
        arg = replace_string(arg, "$CYN$", "");
        arg = replace_string(arg, "$WHT$", "");
        arg = replace_string(arg, "$HIR$", "");
        arg = replace_string(arg, "$HIG$", "");
        arg = replace_string(arg, "$HIY$", "");
        arg = replace_string(arg, "$HIB$", "");
        arg = replace_string(arg, "$HIM$", "");
        arg = replace_string(arg, "$HIC$", "");
        arg = replace_string(arg, "$HIW$", "");
        arg = replace_string(arg, "$NOR$", "");
        
   if( !check_legal_name(arg, 80) )   {
      return 1; 
   }
  
   arg = newname;
    
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
  
   fabao_ob->set("unwield_msg", arg);
   fabao_ob->save();     
   
   write("¸Ä¶¯³É¹¦¡£\n");
   return 1;
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("koujian_nuwa") && dir == "east")
	{
	   message_vision("$NÕ¾ÁËÆğÀ´£¬ÅÄÁËÅÄÉíÉÏµÄÍÁ¡£\n",me);
	   me->delete_temp("koujian_nuwa");
	}
	remove_call_out("check_hp");
	return ::valid_leave(me,dir);
}

int do_koujian(string arg)
{
	object ob=this_player();
	if (!arg || (arg != "nuwa" && arg !="nuwa niangniang"))
	  return notify_fail("ÄãÒªßµ¼ûË­£¿\n");
	if (ob->query_temp("koujian_nuwa"))
	{ 
		message_vision("$N¹§¹§¾´¾´µÄ¿ÄÁË¼¸¸öÍ·.\n",ob);
		return 1;
	}
	else
	   ob->set_temp("koujian_nuwa",1);
	message_vision("$NÆËÍ¨Ò»Éù¹òµ½µØÉÏ£¬¹§¹§¾´¾´µØ¿ÄÁËÒ»¸öÍ·£¬ÀÊÉùµÀ£º¡±µÜ×Ó"+ob->query("name")
	+"°İ¼ûÅ®æ´ÄïÄï£¡¡±\n",ob);
	if (ob->query("family/master_id")=="nuwa niangniang")
	  {
	      message_vision(HIC"Ò»ÕóÇå·ç´µÀ´£¬°Ñ$NÇáÇáµØ¾í×ßÁË¡£\n"NOR,ob);
	      ob->move(__DIR__"nuwaroom");
	      return 1;
	  }
	call_out("check_hp",15,ob);
	return 1;
}

void check_hp(object ob)
{
	remove_call_out("check_hp");
	if (random(50-ob->query_kar())!=0)
	 {
	   if (ob->query("sen")<=10)
	     {
	     	ob->unconcious();
	     	return;
	     } else 
	     {
	     	ob->receive_damage("sen",ob->query("sen")/5);
	     	if (ob->query("sen")*2 < ob->query("max_sen"))
	     	  message_vision("$NÒÑ¾­¹òµÃÍ·»èÑÛ»¨µÄÁË£¬Ëæ»ú¶¼»áµøµ¹¡£\n",ob);
	     	else
	     	  message_vision("$N¾õµÃÓĞĞ©Í·ÔÎ¡£\n",ob);
	     }
	   call_out("check_hp",15,ob);
	   return;
	 }
	//ob->delete_temp("koujian_nuwa");
	message_vision(HIC"Ìì¿ÕÖĞ´«À´Ò»ÉùÌ¾Ï¢£º¡°ÄãÕâÓÖÊÇºÎ¿àÄØ?\n"NOR,ob);
	if (ob->query("family/family_name")=="ÔÂ¹¬") {
        message_vision(HIC"Ò»ÕóÇå·ç´µÀ´£¬°Ñ$NÇáÇáµØ¾í×ßÁË¡£\n"NOR,ob);
	ob->move(__DIR__"nuwaroom");
	}
} 

