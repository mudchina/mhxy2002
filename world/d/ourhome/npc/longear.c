// longear.c
// 1996/12/06 by cglaem

inherit NPC;

string send_mail();
string receive_mail();

void create()
{
	set_name("кЁ╥Г╤З", ({"shunfeng er", "er", "longear",
"youchai","chai" }) );
	set("title", "сй╡Н");
	set("gender", "дппт" );
	set("age", 30);
	set("long",
		"г╟сЯ╩й╢С╣шгвпе║ёрРн╙м╣лЩсЯ╩й╢С╣ш╦ЗФо╤П╣ВгИ╤Ь╠╩╥ён╙сй╡Н║ё\n");
	set("combat_exp", 8000);
  set("daoxing", 100000);

	set("attitude", "friendly");
	set("inquiry", ([
                        "name":"а╛нрдЦ╤╪╡╩хой╤ё©╢СцШ╤╕╤╕╣дкЁ╥Г╤З╬мйгнр║ё", 
		"here" : "╧Мж╙╣юуБйгй╡ц╢╣ь╥╫ё║нрж╩╦╨тПйупе╥╒пе║ё",
                        "Фо╤П" : "╟╕...©ио╖ж╩нефДиЫн╢╪ШфДхк║ё",
                        "сЯ╩й╢С╣ш" : "дЦ╠ПлАкШё║р╩лАнр╬мспфЬ...ж╩пМжщ╧ы╥е╩Пё╛╡╩пМ╟ыпу╣Ц╣ф║ё",
		"╥╒пе" : (: send_mail :),
		"йупе" : (: receive_mail :),
		"пе╪Ч" : (: receive_mail :),
		"пе" : (: receive_mail :),
		"mail" : "дЗ╫╡╣дйгмБ╧З╩╟╟иё©нрлЩ╡╩╤╝р╝~~~~~~~~",
	]) );
	set_skill("literate", 70);
	set_skill("dodge", 50);
	set_skill("unarmed", 40);
	set("per", 15);
            set("max_kee", 500);
            set("max_gin", 100);
            set("max_sen", 300);
            set("force", 150);
            set("max_force", 300);
            set("force_factor", 0);
	setup();
	add_money("coin", 70);
	carry_object("/d/ourhome/obj/linen")->wear();
}

string send_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "дЦ╣дпеоД╩╧тз╟иё©сцпеоД╬м©ирт╪дпеак║ё\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "╣хр╩об╣╫╢Сй╞м╥ю╢урнр╟и║ё\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "е╤... р╙╪дпейгбПё©уБйгдЦ╣дпеоДё╛╪дпе╣д╥╫╥╗пеоДиоспк╣цВ║ё\n";
}

string receive_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "дЦ╣дпеоД╩╧тз╟иё©дЦкЫсп╣дпе╤╪тзюОцФ║ё\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "╣хр╩об╣╫╢Сй╞м╥ю╢урнр╟и║ё\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "╨цё╛╢Щнрурур....спакё╛дЦ╣дпеоДтзуБё╛бЩбЩ©╢╟иё╛╡╩╢Р╫адЦак║ё\n";
}
Ъ