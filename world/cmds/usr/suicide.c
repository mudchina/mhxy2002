// suicide.c
// By tianlin 2001.5.8
// ╪схКвти╠охр╙йДхКиМ╥щ╠Йй╤

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( me->is_busy() )
		return notify_fail("дЦиор╩╦Ж╤╞вВ╩╧ц╩мЙЁи║ё\n");

	if( !arg ) {
		write("дЦжьпбм╤л╔║ё\n");
		return 1;
	}

	if( arg!="-f" ) 
		return notify_fail("вти╠спа╫жжё╛дЗйгр╙сют╤кю╣Т╩╧йгжьпбм╤л╔ё©\n");

	if(wizardp(me))
	    return notify_fail("гК╡╩р╙вти╠╣Тнвй╕уй╨её╛п╩п╩ё║\n");

	write(
		"хГ╧ШдЗя║тЯсют╤кю╣Т╣двти╠╥╫й╫ё╛уБ╦ЖхкнО╣двйао╬мсют╤и╬ЁЩакё╛гКнЯ╠ь\n"
		"©╪бггЕЁЧё╛х╥╤╗╣д╩╟гКйДхКдЗ╣д"BLINK HIW"иМ╥щ╠Йй╤ё╨\n"NOR);
	CHANNEL_D->do_channel(this_object(),"rumor",me->name()+"уЩтзя╟урр╩жжлс╠э╥Ёду╣д╥╫╥╗║ё");
	input_to("check_superpasswd", 1, me, 1);
	return 1;
}
// by tianlin 2001.5.8
private void check_superpasswd(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("superpasswd");
	if( crypt(passwd, old_pass)!=old_pass ) {
              write("\nиМ╥щ╠Йй╤╢МнСё║\n");
              return;
       }
       write("гКйДхКдЗ╣дцэбКё╨");
       input_to("check_password", 1, me, 1);
}
private void check_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("password");
	if( crypt(passwd, old_pass)!=old_pass ) {
		write("цэбК╢МнСё║\n");
		return;
	}

	if (forever) {
		tell_object( me,
			HIR "\n\nдЦ╬Ж╤╗р╙вти╠акё╛хГ╧ШхЩй╝цКжсдз╡╩╨С╩зё╛╬муФ╣дсю╠Пак║ё\n\n\n" NOR);
		me->set_temp("suicide_countdown", 30);
		me->start_busy( (: call_other, this_object(), "slow_suicide" :) );
	}
}

private int slow_suicide(object me)
{
	object link_ob;
	int stage;
	string myid, couple;

	stage = me->query_temp("suicide_countdown");
	me->add_temp("suicide_countdown", -1);
	if( stage > 1 ) {
		if( stage%5 == 0 )
		  tell_object(me, 
			HIR "дЦ╩╧сп " + stage + " цК╣дй╠╪Д©ирт╨С╩з║ё"+
			"(сцquitцЭаНю╢╨С╩з)\n" NOR);
		return 1;
	}

	link_ob = me->query_temp("link_ob");
	if( !link_ob ) return 0;

	log_file("static/SUICIDE",
		sprintf("%s(%s) commits a suicide on %s from %s\n", geteuid(me), me->name(), ctime(time()), (string)query_ip_name(me) ) );

	seteuid(getuid());
	rm( link_ob->query_save_file() + __SAVE_EXTENSION__ );
	rm( me->query_save_file() + __SAVE_EXTENSION__ );
	myid=me->query("id");

	// remove player home.
	rm( "/data/playerhomes/h_"+myid+ __SAVE_EXTENSION__ );

	// remove mailbox.
	rm( "/data/mail/"+myid[0..0]+"/"+myid+ __SAVE_EXTENSION__ );

	// remove couple's home as well. (the home is registered by the 
	// couple.)
	couple=me->query("coupld/id");
	if(couple)
	  rm("/data/mail/"+couple[0..0]+"/"+couple+__SAVE_EXTENSION__);


	write("╨ц╟иё╛сю╠Пак:(\n");
	tell_room(environment(me), me->name() +
		"вти╠акё╛рт╨СдЦтыр╡©╢╡╩╣╫уБ╦Жхкак║ё\n", ({me}));
	CHANNEL_D->do_channel(this_object(),"rumor",me->name()+"н╙аклс╠эЁ╬йю╪Д╣д╥Ёдуё╛лАг╟втнр╫Б╥еак║ё");
	destruct(me);
	return 0;
}
int halt_suicide(object me)
{
	tell_object(me, "дЦ╥ефЗаквти╠╣ддНм╥║ё\n");
	CHANNEL_D->do_channel(this_object(),"rumor",me->name(1) + "╬Ж╤╗╪лпЬсб╦р╣ь╩Нобх╔║ё");
	return 1;
}

int help (object me)
{
        write(@HELP
ж╦аН╦Яй╫: suicide [-f]
 
хГ╧ШрРн╙дЁжжт╜рРдЦ╡╩оК╩Нак, дЦ©иртя║тЯвти╠.
вти╠╥жа╫жж:
[1;31mв╒: рРн╙сп╣дмФ╪р╟явт╪╨╣дхк╦Ь╠Пхк╧р╩З,╤Ь╠Пхкх╢╦Ьвти╠ак,
р╩юЮ╣х╣х,гК╡╩р╙гАрв╟яиМ╥щ╠Йй╤╦Фкъ╠Пхк,хГ╥╒иЗртмБ,
нвй╕р╩би╡╩╦╤хн╨нтПхн.[2;37;0m
 
suicide    : жьпбм╤л╔
suicide -f : сют╤╣дЁЩх╔мФ╪рвйао, о╣мЁ╩Ар╙гСдЦ
             йДхКцэбКрт╪╟иМ╥щ╠Йй╤ртх╥хоиМ╥щ.
 
гКиВжья║тЯ :)
 
HELP
);
        return 1;
}
