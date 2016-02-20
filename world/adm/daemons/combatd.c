// combatd.c
//by tianlin@mhxy 2001.5.1 for pansi and shushan NK
//by tianlin@mhxy 2001.8.10 √Ë ˆ¥”–¬±‡º≠¡À“ªœ¬

#pragma optimize

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include "/cmds/std/valid_kill.h"

inherit F_DBASE;

int victim_lose(object killer,object victim,string killerid);
void victim_penalty(object victim);
int nk_gain(object killer, object victim);
string chinese_daoxing(int gain);

int check_family(string fam);

//this mapping indicates whether this family class is
//xian or yao.
mapping family=(["∑Ω¥Á…Ω»˝–«∂¥":1,
                 "ƒœ∫£∆’Õ”…Ω":1,
                 "ÃÏ≈ÓÀß∏Æ":1,//By tianlin@mhxy for 2001.7.2
                 "Ω´æ¸∏Æ":1,
                 "ŒÂ◊Øπ€":1,
                 "Œ‰µ±≈…":1,//By tianlin@mhxy for 2001.9.27
		   "Œ‰ •√≈":1,//“—–ﬁ∏ƒπ˝
                 " Ò…Ω≈…":1,//“—∏¸–¬
                 "…Ÿ¡÷≈…":1,//By tianlin@mhxy for 2001.12.13.‘⁄1‘¬÷–—ÆÕÍ≥…÷∆◊˜
                 "…ÒΩ£…Ω◊Ø":1,//By tianlin@mhxy for 2001.12.13.
                 "—÷¬ﬁµÿ∏Æ":0,
                 "ÃÏø’ΩÁ":0,
                 "‘¬π¨":0,
                 "¡ÈΩÁ":0,
                 "∂´∫£¡˙π¨":0,
		   "¡˙π¨":0,
                 "“∆ª®π¨":0,//‘⁄2001.11‘¬«∞ÕÍ≥…÷∆◊˜
                 "≈ÃÀø∂¥":-1,
                 "¥Û—©…Ω":-1,
                 "ƒßΩÃ":-1,
                 "ª‘∆∂¥":-1,//moyun-shou‘ˆ«ø,≤¢–ﬁ∏ƒº”∆‰pfm 2∏ˆ
                 "–˘‘Øπ≈ƒπ":-1,//–ﬁ∏ƒÕÍ±œ
                 "¥‰‘∆…Ω∞≈Ω∂∂¥":-1,//‘›≤ªø™∑≈
                 "œ›ø’…ΩŒﬁµ◊∂¥":-1,
                 "¬“ Ø…Ω±Ã≤®Ã∂":-1, 
]);

string *guard_msg = ({
	CYN "$N"NOR+CYN"◊¢ ”◊≈$n"NOR+CYN"µƒ––∂Ø£¨∆ÛÕº—∞’“ª˙ª·≥ˆ ÷°£\n" NOR,
	CYN "$N"NOR+CYN"’˝∂¢◊≈$n"NOR+CYN"µƒ“ªæŸ“ª∂Ø£¨ÀÊ ±◊º±∏∑¢∂Øπ• ∆°£\n" NOR,
	CYN "$N"NOR+CYN"ª∫ª∫µÿ“∆∂ØΩ≈≤Ω£¨œÎ“™’“≥ˆ$n"NOR+CYN"µƒ∆∆’¿°£\n" NOR,
	CYN "$N"NOR+CYN"ƒø≤ª◊™æ¶µÿ∂¢◊≈$n"NOR+CYN"µƒ∂Ø◊˜£¨—∞’“Ω¯π•µƒ◊Óº— ±ª˙°£\n" NOR,
	CYN "$N"NOR+CYN"¬˝¬˝µÿ“∆∂Ø◊≈Ω≈≤Ω£¨À≈ª˙≥ˆ ÷°£\n" NOR,
});

string *catch_hunt_msg = ({
	HIW "$N"NOR+HIW"∫Õ$n"NOR+HIW"≥»Àœ‡º˚∑›Õ‚—€∫Ï£¨¡¢øÃ¥Ú¡À∆¿¥£°\n" NOR,
	HIW "$N"NOR+HIW"∂‘◊≈$n"NOR+HIW"¥Û∫»£∫°∏ø…∂Ò£¨”÷ «ƒ„£°°π\n" NOR,
	HIW "$N"NOR+HIW"∫Õ$n"NOR+HIW"“ª≈ˆ√Ê£¨∂˛ª∞≤ªÀµæÕ¥Ú¡À∆¿¥£°\n" NOR,
	HIW "$N"NOR+HIW"“ª—€∆≥º˚$n"NOR+HIW"£¨°∏∫ﬂ°πµƒ“ª…˘≥Â¡Àπ˝¿¥£°\n" NOR,
	HIW "$N"NOR+HIW"“ªº˚µΩ$n"NOR+HIW"£¨„∂¡À“ª„∂£¨¥ÛΩ–£∫°∏Œ“‘◊¡Àƒ„£°°π\n" NOR,
	HIW "$N"NOR+HIW"∫»µ¿£∫°∏$n"NOR+HIW"£¨Œ“√«µƒ’ ªπ√ªÀ„ÕÍ£¨ø¥’–£°°π\n" NOR,
	HIW "$N"NOR+HIW"∫»µ¿£∫°∏$n"NOR+HIW"£¨ø¥’–£°°π\n" NOR,});

string *winner_msg = ({
	CYN "\n$N"NOR+CYN"π˛π˛¥Û–¶£¨Àµµ¿£∫≥–»√¡À£°\n\n" NOR,
	CYN "\n$N"NOR+CYN"À´ ÷“ªπ∞£¨–¶◊≈Àµµ¿£∫≥–»√£°\n\n" NOR,
	CYN "\n$N"NOR+CYN" §¡À’‚’–£¨œÚ∫Û‘æø™»˝≥ﬂ£¨–¶µ¿£∫≥–»√£°\n\n" NOR,
	CYN "\n$n"NOR+CYN"¡≥…´Œ¢±‰£¨Àµµ¿£∫≈Â∑˛£¨≈Â∑˛£°\n\n" NOR,
	CYN "\n$n"NOR+CYN"œÚ∫ÛÕÀ¡Àº∏≤Ω£¨Àµµ¿£∫’‚≥°±» ‘À„Œ“ ‰¡À£¨≈Â∑˛£¨≈Â∑˛£°\n\n" NOR,
	CYN "\n$n"NOR+CYN"œÚ∫Û“ª◊›£¨π™…Ì◊ˆ“æÀµµ¿£∫∏Ûœ¬Œ‰“’≤ª∑≤£¨π˚»ª∏ﬂ√˜£°\n\n" NOR,
});

void create()
{
	seteuid(getuid());
	set("name", "’Ω∂∑æ´¡È");
	set("id", "combatd");
	
//	if(!MISC_D->check_date()) {shutdown(-1);return;}
}

string damage_msg(int damage, string type)
{
	string str;

//	return "‘Ï≥… " + damage + " µ„" + type + "°£\n";

	if( damage == 0 ) return "Ω·π˚√ª”–‘Ï≥…»Œ∫Œ…À∫¶°£\n";

	switch( type ) {
	case "≤¡…À":
	case "◊•…À":
	case "∏Ó…À":
		if( damage < 10 ) return "Ω·π˚÷ª ««·«·µÿªÆ∆∆$pµƒ∆§»‚°£\n";
		else if( damage < 20 ) return "Ω·π˚‘⁄$p$lªÆ≥ˆ“ªµ¿œ∏≥§µƒ—™∫€°£\n";
		else if( damage < 40 ) return "Ω·π˚"MAG"°∏‡Õ°π"NOR"µÿ“ª…˘ªÆ≥ˆ“ªµ¿…Àø⁄£°\n";
		else if( damage < 80 ) return "Ω·π˚"MAG"°∏‡Õ°π"NOR"µÿ“ª…˘ªÆ≥ˆ“ªµ¿"HIR"—™¡‹¡‹"NOR"µƒ…Àø⁄£°\n";
		else if( damage < 160 ) return "Ω·π˚"MAG"°∏‡Õ°π"NOR"µÿ“ª…˘ªÆ≥ˆ“ªµ¿”÷≥§”÷…Óµƒ…Àø⁄£¨Ω¶µ√$N¬˙¡≥"HIR"œ —™£°\n"NOR;
		else return "Ω·π˚÷ªÃ˝º˚$n“ª…˘≤“∫ø£¨$pµƒ$l±ªªÆ≥ˆ“ªµ¿…Óº∞º˚π«µƒø…≈¬…Àø⁄£°\n";
		break;
	case "ø≥…À":
	case "≈¸…À":
		if( damage < 10 ) return "Ω·π˚÷ª «‘⁄$nµƒ∆§»‚…œ≈ˆ¡À≈ˆ£¨∏˙Œ√◊”∂£≤Ó≤ª∂‡°£\n";
		else if( damage < 20 ) return "Ω·π˚‘⁄$n$lø≥≥ˆ“ªµ¿œ∏≥§µƒ—™∫€°£\n";
		else if( damage < 40 ) return "Ω·π˚"CYN"°∏‡€°π"NOR"“ª…˘≈¸≥ˆ“ªµ¿"HIR"—™¡‹¡‹"NOR"µƒ…Àø⁄£°\n";
		else if( damage < 80 ) return "Ω·π˚÷ªÃ˝"CYN"°∏‡€°π"NOR"µÿ“ª…˘£¨$nµƒ$l±ª≈¸µ√—™»Á»™”ø£¨Õ¥µ√$p“ß—¿«–≥›£°\n";
		else if( damage < 160 ) return "Ω·π˚"CYN"°∏‡€°π"NOR"µÿ“ª…˘ø≥≥ˆ“ªµ¿”÷≥§”÷…Óµƒ…Àø⁄£¨Ω¶µ√$N¬˙¡≥"HIR"œ —™£°\n"NOR;
		else return WHT"Ω·π˚÷ªÃ˝º˚$n“ª…˘≤“∫ø£¨$pµƒ$l±ª≈¸ø™“ªµ¿…Óº∞º˚π«µƒø…≈¬…Àø⁄£°\n"NOR;
		break;
	case "«π…À":
	case "¥Ã…À":
		if( damage < 10 ) return "Ω·π˚÷ª ««·«·µÿ¥Ã∆∆$pµƒ∆§»‚°£\n";
		else if( damage < 20 ) return "Ω·π˚‘⁄$p$l¥Ã≥ˆ“ª∏ˆ¥¥ø⁄°£\n";
		else if( damage < 40 ) return "Ω·π˚°∏‡€°πµÿ“ª…˘¥Ã»Î¡À$n$l¥Á–Ì£°\n";
		else if( damage < 80 ) return "Ω·π˚°∏‡€°πµÿ“ª…˘¥ÃΩ¯$nµƒ$l£¨ π$p≤ª”…◊‘÷˜µÿÕÀ¡À≤Ω£°\n";
		else if( damage < 160 ) return "Ω·π˚°∏‡€‡Õ°πµÿ“ª…˘£¨$w“—‘⁄$p$l¥Ã≥ˆ“ª∏ˆ—™»‚ƒ£∫˝µƒ—™øﬂ¡˛£°\n";
		else return "Ω·π˚÷ªÃ˝º˚$n“ª…˘≤“∫ø£¨$w“—‘⁄$pµƒ$l∂‘¥©∂¯≥ˆ£¨œ —™Ω¶µ√¬˙µÿ£°\n";
		break;
	case "÷˛…À":
		if( damage < 10 ) return "Ω·π˚÷ª ««·«·µÿ“ª¥•£¨‘⁄$nµƒ∆§∑Ù…œ¡Ùœ¬“ªµ„∞◊∫€°£\n";
		else if( damage < 20 ) return "Ω·π˚‘⁄$pµƒ$l¡Ùœ¬º∏µ¿—™∫€°£\n";
		else if( damage < 40 ) return "Ω·π˚“ªœ¬◊”÷˛÷–£¨$nµƒ$l∂Ÿ ±≥ˆœ÷º∏∏ˆ—™ø◊£°\n";
		else if( damage < 80 ) return "Ω·π˚“ªœ¬◊”÷˛÷–£¨$n¡¢øÃ—™¡˜»Á◊¢£°\n";
		else if( damage < 120 ) return "Ω·π˚"MAG"°∏ﬂÍ°π"NOR"µÿ“ª…˘£¨$n∂Ÿ ±œ —™∑…Ω¶£°\n";
		else if( damage < 160 ) return "Ω·π˚’‚“ªœ¬"MAG"°∏ﬂÍ°π"NOR"µÿ“ª…˘£¨$n±ª÷˛µ√ªÎ…Ì «—™£°\n";
		else return "Ω·π˚"MAG"°∏ﬂÍ°π"NOR"÷ÿ÷ÿµÿ‘“÷–£¨$n±ª÷˛µ√«ß¥Ø∞◊ø◊£¨—™»‚Àƒ¥¶∫·∑…£°\n";
		break;
	case "’∆…À":
	case "»≠…À":
	case "ˆ…À":
		if( damage < 10 ) return "Ω·π˚÷ª ««·«·µÿ≈ˆµΩ£¨±»≈ƒ≤‘”¨…‘Œ¢÷ÿ¡Àµ„°£\n";
		else if( damage < 20 ) return "Ω·π˚‘⁄$pµƒ$l‘Ï≥…“ª¥¶ˆ«‡°£\n";
		else if( damage < 40 ) return "Ω·π˚“ªª˜√¸÷–£¨$nµƒ$lµ« ±÷◊¡À“ªøÈ¿œ∏ﬂ£°\n";
		else if( damage < 80 ) return "Ω·π˚“ªª˜√¸÷–£¨$n√∆∫ﬂ¡À“ª…˘œ‘»ª≥‘¡À≤ª–°µƒø˜£°\n";
		else if( damage < 120 ) return "Ω·π˚"WHT"°∏≈È°π"NOR"µÿ“ª…˘£¨$nÕÀ¡À¡Ω≤Ω£°\n";
		else if( damage < 160 ) return "Ω·π˚’‚“ªœ¬"WHT"°∏≈È°π"NOR"µÿ“ª…˘¥Úµ√$n¡¨ÕÀ¡À∫√º∏≤Ω£¨≤Ó“ªµ„À§µπ£°\n";
		else if( damage < 240 ) return "Ω·π˚÷ÿ÷ÿµÿª˜÷–£¨$n"WHT"°∏≈È°π"NOR"µÿ“ª…˘Õ¬≥ˆ“ªø⁄"HIR"œ —™£°\n"NOR;
		else return "Ω·π˚÷ªÃ˝º˚"WHT"°∏≈È°π"NOR"µÿ“ª…˘æﬁœÏ£¨$nœÒ“ª¿¶µæ≤›∞„∑…¡À≥ˆ»•£°\n";
		break;
	case "◊≤…À":
	case "‘“…À":
		if( damage < 10 ) return "Ω·π˚÷ª ««·«·µÿ≈ˆµΩ£¨µ»”⁄∏¯$n…¶¡À“ªœ¬—˜°£\n";
		else if( damage < 20 ) return "Ω·π˚‘⁄$pµƒ$l‘“≥ˆ“ª∏ˆ–°Î˚∞¸°£\n";
		else if( damage < 40 ) return "Ω·π˚‘“∏ˆ’˝◊≈£¨$nµƒ$lµ« ±÷◊¡À“ªøÈ¿œ∏ﬂ£°\n";
		else if( damage < 80 ) return "Ω·π˚‘“∏ˆ’˝◊≈£¨$n√∆∫ﬂ“ª…˘œ‘»ª≥‘¡À≤ª–°µƒø˜£°\n";
		else if( damage < 120 ) return "Ω·π˚"WHT"°∏≈È°π"NOR"µÿ“ª…˘£¨$nÃ€µ√¡¨—¸∂ºÕ‰¡À£°\n";
		else if( damage < 160 ) return "Ω·π˚’‚“ªœ¬"RED"°∏∫‰°π"NOR"µÿ“ª…˘‘“µ√$n—€√∞Ω–«£¨≤Ó“ªµ„À§µπ£°\n";
		else if( damage < 240 ) return "Ω·π˚÷ÿ÷ÿµÿ‘“÷–£¨$n—€«∞“ª∫⁄£¨°∏Õ€°πµÿ“ª…˘Õ¬≥ˆ“ªø⁄œ —™£°\n";
		else return "Ω·π˚÷ªÃ˝º˚"RED"°∏∫‰°π"NOR"µÿ“ª…˘æﬁœÏ£¨$n±ª‘“µ√—™»‚ƒ£∫˝£¨≤“≤ª»Ã∂√£°\n";
		break;
	case "’…À":
	case "ƒ⁄…À":
		if( damage < 20 ) return "Ω·π˚‘⁄$n…Ì…œ“ª¥•º¥ ≈£¨µ»”⁄∏¯$n…¶¡À“ªœ¬—˜°£\n";
		else if( damage < 40 ) return "Ω·π˚$nªŒ¡À“ªªŒ£¨≥‘¡Àµ„–°ø˜°£\n";
		else if( damage < 80 ) return "Ω·π˚$n∆¯œ¢“ª÷œ£¨œ‘»ª”–µ„∫ÙŒ¸≤ª≥©£°\n";
		else if( damage < 120 ) return "Ω·π˚$nÃÂƒ⁄“ª’ÛæÁÕ¥£¨ø¥∆¿¥ƒ⁄…À≤ª«·£°\n";
		else if( damage < 160 ) return "Ω·π˚"HIY"°∏ŒÀ°π"NOR"µÿ“ª…˘$n÷ªæıµ√—€«∞“ª∫⁄£¨À´∂˙∫‰√˘≤ª÷π£°\n";
		else return RED+BBLU"Ω·π˚÷ªÃ˝º˚"HIY"°∏ŒÀ°π"NOR+RED+BBLU"µÿ“ª…˘æﬁœÏ£¨$n"HIW"°∏Õ€°π"NOR+RED+BBLU"µÿ“ª…˘Õ¬≥ˆ“ªø⁄"HIR"œ —™"NOR+RED+BBLU"£¨ŒÂ‘‡¡˘∏≠∂º¥Ì¡ÀŒª£°\n"NOR;
		break;
		case "±ﬁ…À":
		case "≥È…À":
		if( damage < 10 ) return "Ω·π˚÷ª «‘⁄$nµƒ∆§»‚…œ≈ˆ¡À≈ˆ£¨∏˙Œ√◊”∂£≤Ó≤ª∂‡°£\n";
		else if( damage < 20 ) return "Ω·π˚‘⁄$n$l≥È≥ˆ“ªµ¿«·Œ¢µƒ◊œ∫€°£\n";
		else if( damage < 40 ) return "Ω·π˚"HIC"°∏≈æ°π"NOR"µÿ“ª…˘‘⁄$n$l≥È≥ˆ“ªµ¿≥§≥§µƒ"HIR"—™∫€£°\n"NOR;
		else if( damage < 80 ) return "Ω·π˚÷ªÃ˝"HIC"°∏≈æ°π"NOR"µÿ“ª…˘£¨$nµƒ$l±ª≥Èµ√∆§ø™»‚’¿£¨Õ¥µ√$p“ß—¿«–≥›£°\n";
		else if( damage < 160 ) return "Ω·π˚"HIC"°∏≈æ°π"NOR"µÿ“ª…˘±¨œÏ£°’‚“ªœ¬∫√¿˜∫¶£¨÷ª≥Èµ√$n∆§ø™»‚’¿£¨"HIR"—™ª®∑…Ω¶£°\n"NOR;
		else return "Ω·π˚÷ªÃ˝º˚$n“ª…˘≤“∫ø£¨$w÷ÿ÷ÿµÿ≥È…œ¡À$pµƒ$l£¨$n∂Ÿ ±—™»‚∫·∑…£¨ Æ√¸∂œ¡Àæ≈Ãı£°\n";
		break;
	default:
		if( !type ) type = "…À∫¶";
		if( damage < 10 ) str =  "Ω·π˚÷ª «√„«ø‘Ï≥…“ª¥¶«·Œ¢";
		else if( damage < 20 ) str = "Ω·π˚‘Ï≥…«·Œ¢µƒ";
		else if( damage < 30 ) str = "Ω·π˚‘Ï≥…“ª¥¶";
		else if( damage < 50 ) str = "Ω·π˚‘Ï≥…“ª¥¶—œ÷ÿ";
		else if( damage < 80 ) str = "Ω·π˚‘Ï≥…∆ƒŒ™—œ÷ÿµƒ";
		else if( damage < 120 ) str = "Ω·π˚‘Ï≥…œ‡µ±—œ÷ÿµƒ";
		else if( damage < 170 ) str = "Ω·π˚‘Ï≥… Æ∑÷—œ÷ÿµƒ";
		else if( damage < 230 ) str = "Ω·π˚‘Ï≥…º´∆‰—œ÷ÿµƒ";
		else str =  "Ω·π˚‘Ï≥…∑«≥£ø…≈¬µƒ—œ÷ÿ";
		return str + type + "£°\n";
	}
}

string eff_status_msg(int ratio)
{
	if( ratio==100 ) return HIG "ø¥∆¿¥∆¯—™≥‰”Ø£¨≤¢√ª”– ‹…À°£" NOR;
	if( ratio > 95 ) return HIG "À∆∫ı ‹¡Àµ„«·…À£¨≤ªπ˝π‚¥”Õ‚±Ìø¥≤ª¥Û≥ˆ¿¥°£" NOR;
	if( ratio > 90 ) return HIY "ø¥∆¿¥ø…ƒ‹ ‹¡Àµ„«·…À°£" NOR;
	if( ratio > 80 ) return HIY " ‹¡Àº∏¥¶…À£¨≤ªπ˝À∆∫ı≤¢≤ª∞≠ ¬°£" NOR;
	if( ratio > 60 ) return HIY " ‹…À≤ª«·£¨ø¥∆¿¥◊¥øˆ≤¢≤ªÃ´∫√°£" NOR;
	if( ratio > 40 ) return HIR "∆¯œ¢¥÷÷ÿ£¨∂Ø◊˜ø™ º…¢¬“£¨ø¥¿¥À˘ ‹µƒ…À◊≈ µ≤ª«·°£" NOR;
	if( ratio > 30 ) return HIR "“—æ≠…À∫€¿€¿€£¨’˝‘⁄√„¡¶÷ß≥≈◊≈≤ªµπœ¬»•°£" NOR;
	if( ratio > 20 ) return HIR " ‹¡Àœ‡µ±÷ÿµƒ…À£¨÷ª≈¬ª·”–…˙√¸Œ£œ’°£" NOR;
	if( ratio > 10 ) return RED "…À÷ÿ÷Æœ¬“—æ≠ƒ—“‘÷ß≥≈£¨—€ø¥æÕ“™µπ‘⁄µÿ…œ°£" NOR;
	if( ratio > 5  ) return RED " ‹…Àπ˝÷ÿ£¨“—æ≠—Ÿ—Ÿ“ªœ¢£¨√¸‘⁄µ©œ¶¡À°£" NOR;
	return RED " ‹…Àπ˝÷ÿ£¨“—æ≠”–»Á∑Á÷–≤–÷Ú£¨ÀÊ ±∂ºø…ƒ‹∂œ∆¯°£" NOR;
}

string status_msg(int ratio)
{
	if( ratio==100 ) return HIG "ø¥∆¿¥≥‰¬˙ªÓ¡¶£¨“ªµ„“≤≤ª¿€°£" NOR;
	if( ratio > 95 ) return HIG "À∆∫ı”––©∆£±π£¨µ´ «»‘»ª Æ∑÷”–ªÓ¡¶°£" NOR;
	if( ratio > 90 ) return HIY "ø¥∆¿¥ø…ƒ‹”––©¿€¡À°£" NOR;
	if( ratio > 80 ) return HIY "∂Ø◊˜À∆∫ıø™ º”–µ„≤ªÃ´¡Èπ‚£¨µ´ «»‘»ª”–Ãı≤ªŒ…°£" NOR;
	if( ratio > 60 ) return HIY "∆¯¥≠–Í–Í£¨ø¥∆¿¥◊¥øˆ≤¢≤ªÃ´∫√°£" NOR;
	if( ratio > 40 ) return HIR "À∆∫ı Æ∑÷∆£±π£¨ø¥¿¥–Ë“™∫√∫√–›œ¢¡À°£" NOR;
	if( ratio > 30 ) return HIR "“—æ≠“ª∏±Õ∑÷ÿΩ≈«·µƒƒ£—˘£¨’˝‘⁄√„¡¶÷ß≥≈◊≈≤ªµπœ¬»•°£" NOR;
	if( ratio > 20 ) return HIR "ø¥∆¿¥“—æ≠¡¶≤ª¥”–ƒ¡À°£" NOR;
	if( ratio > 10 ) return RED "“°Õ∑ªŒƒ‘°¢Õ·Õ·–±–±µÿ’æ∂º’æ≤ªŒ»£¨—€ø¥æÕ“™µπ‘⁄µÿ…œ°£" NOR;
	return RED "“—æ≠œ›»Î∞ÎªË√‘◊¥Ã¨£¨ÀÊ ±∂ºø…ƒ‹À§µπ‘Œ»•°£" NOR;
}

//report_shen messages
string sen_status_msg(int ratio)
{
	if( ratio==100 ) return HIG "ø¥∆¿¥Õ∑ƒ‘«Â–—£¨“ªµ„“≤≤ª√‘∫˝°£" NOR;
	if( ratio > 90 ) return HIG "≈ƒ¡À≈ƒ◊‘º∫µƒƒ‘¥¸£¨À∆∫ı”–µ„≤ªÃ´µ√æ¢°£" NOR;
	if( ratio > 80 ) return HIY "ø¥∆¿¥”––©√‘∫˝¡À°£" NOR;
	if( ratio > 60 ) return HIY "µƒ»∑”–µ„√‘∫˝¡À£¨µ´ªπ±Êµ√≥ˆ∂´Œ˜ƒœ±±°£" NOR;
	if( ratio > 40 ) return HIR "¡Ω—€∑¢÷±£¨ø⁄Ω«¡˜œ—£¨…Ò÷«ø™ ºªÏ¬“°£" NOR;
	if( ratio > 20 ) return HIR "√‘√‘∫˝∫˝£¨“°“°ªŒªŒ£¨“—æ≠±Ê≤ª≥ˆ∂´Œ˜ƒœ±±¡À°£" NOR;
	if( ratio > 10 ) return RED "…Ò÷«“—æ≠¥¶‘⁄º´∂»ªÏ¬“÷–°£" NOR;
	return RED "–ƒ÷«“—æ≠ÕÍ»´√‘ ß£¨ÀÊ ±∂º”–ø…ƒ‹±≥π˝∆¯»•°£" NOR;
}

varargs void report_status(object ob, int effective)
{
	if( effective ) 
		message_vision( "( $N" + eff_status_msg(
			       (int)ob->query("eff_kee") * 100 /(1+(int)ob->query("max_kee")) ) 
			       + " )\n", ob);
	else
		message_vision( "( $N" + status_msg(
			       (int)ob->query("kee") * 100/(1+(int)ob->query("max_kee")) ) 
			       + " )\n", ob);
}

varargs void report_sen_status(object ob, int effective)
{
	
	message_vision( "( $N" + sen_status_msg(
		(int)ob->query("sen") * 100 /(1+(int)ob->query("max_sen")) ) 
		+ " )\n", ob);
}

// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
	int status, level, power;

	if( !living(ob) ) return 0;

	level = ob->query_skill(skill);

	switch(usage) {
		case SKILL_USAGE_ATTACK:
			level = ob->eff_skill_level(level, SKILL_USAGE_ATTACK);
			level += ob->query_temp("apply/attack");
			break;
		case SKILL_USAGE_DEFENSE:
			level = ob->eff_skill_level(level, SKILL_USAGE_DEFENSE);
			level += ob->query_temp("apply/defense");
			break;
	}

	if( !level ) return (int)ob->query("combat_exp") / 2;

	power = (level*level*level) / 3;
	if( (status = ob->query("max_sen")) > 0 )  {
		if ( power > 100000 )
		   power = power / status * (int)ob->query("sen");
        else
		   power = power * (int)ob->query("sen") / status;
	}

	power +=  ob->query("combat_exp");

	return power;
}
/*
// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//
varargs int do1_attack(object me, object victim,object who)     //π¶≥«µƒ÷¥––
{
int myda,vda;
int one,two,three;
int ap,dp;
one=me->query("soilder");
two=victim->query("soilder");
three=victim->query("defendance");
message_vision("$NΩ´ ÷÷–≥§µ∂“ªª”°£±¯Ω´“œæ€£¨”ø÷¡≥«±ﬂ£¨“ª±ﬂº‹∆‘∆Ã›≈ ‘Ω≥««Ω£¨“ª±ﬂæÚÕ¡∂¯Ω¯°£\n",me);
message_vision("$N÷ªº˚≥««Ω…œÕÚº˝∆Î∑…£¨¿ﬁ Ø≤¢∑¢£¨ ÿµ√ «¿◊¥Ú≤ª∂Ø£¨ÀÆ∆√≤ªΩ¯°£\n",me);
ap=one*me->query("train_level");
dp=two*(victim->query("train_level")+three);
if((ap<=0)&&(dp>0))
{
message("vision",HIY+"°æŒ‰¡÷∑…œ≠°ø:"+NOR+HIC+me->query("name")+"∂‘"+
victim->query("short")+"µƒΩ¯π•Œﬁπ¶∂¯∑µ°£"+who->query("name")+" ÿŒ¿ §¿˚.\n"NOR,users());
tell_object(who,"ƒ„±£Œ¿¡À≥« –£¨µ√µΩ¡À“ªƒÍµƒµ¿––Ω±¿¯°£\n");
who->add("combat_exp",1000);
me->set("soilder",0);
me->set("train_level",0);
me->remove_enemy(victim);
me->delete("attacking");	
victim->delete("receive_attack");
victim->save();
return 1;
}
if((ap>0)&&(dp<=0) )
{
message("vision",HIY+"°æŒ‰¡÷∑…œ≠°ø:"+NOR+HIC+me->query("name")+"π•’º¡À"+
victim->query("short")+" ,"+who->query("name")+" ÿŒ¿ ß¿˚.\n"NOR,users());
victim->set("owner",me->query("id"));
victim->set("soilder",0);
victim->set("train_level",0);
me->remove_enemy(victim);
me->delete("attacking");	
victim->delete("receive_attack");
victim->save();
return 1;
}
if(ap < dp )
{
message_vision("$Nµƒ ÿ ∆µ±’Ê¿Œøø£¨‘⁄“ª’Ûº§¡“µƒ»‚≤´÷Æ∫Û£¨$nµƒπ• ∆ª∫¡Àœ¬¿¥°£\n",who,me);
myda=(dp-ap)/1000;
if(myda<=0) myda=-1*myda+1;
tell_object(me,"µ–»À∆¥√¸µ÷øπ£¨ƒ„’€À¡À:"+chinese_number(myda)+"√˚»À¬Ì°£\n");
me->add("soilder",-myda);
tell_object(who,"µ–»À∆¥√¸Ω¯π•£¨ƒ„’€À¡À:"+chinese_number(myda/2)+"√˚»À¬Ì°£\n");
victim->add("soilder",-myda/5);
}else
if(ap < 5*dp)
{
message_vision("$Nµƒ ÿ ∆µ±’ÊÕÁ«ø£¨‘⁄“ª’Ûº§¡“µƒ»‚≤´÷Æ∫Û£¨$nªπ «ƒ√≤ªœ¬¿¥°£\n",who,me);
myda=(ap-dp)*dp/(ap*1000);
vda=(ap-dp)*ap/(dp*1000);
if(vda<=0) vda=-1*vda+1;
if(myda<=0) myda=-1*myda+1;
tell_object(me,"µ–»À∆¥√¸µ÷øπ£¨ƒ„’€À¡À:"+chinese_number(myda)+"√˚»À¬Ì°£\n");
me->add("soilder",-myda);
tell_object(who,"µ–»À∆¥√¸Ω¯π•£¨ƒ„’€À¡À:"+chinese_number(vda)+"√˚»À¬Ì°£\n");
victim->add("soilder",-vda);
victim->add("defendance",-1);
if(victim->query("defendance")<0) victim->set("defendance",0);
}else 
{
message_vision("$Nµƒ ÿ ∆À‰»ªÕÁ«ø£¨‘⁄“ª’Ûº§¡“µƒ»‚≤´÷Æ∫Û£¨$nªπ «Ω•Ω•’º¡À”≈ ∆°£\n",who,me);
myda=(ap-dp)*dp/(ap*2000);
vda=(ap-dp)*ap/(dp*500);
if(vda<=0) vda=-1*vda+1;
if(myda<=0) myda=-1*myda+1;

tell_object(me,"µ–»Àµ÷øπΩ•»ı£¨ƒ„’€À¡À:"+chinese_number(myda)+"√˚»À¬Ì°£\n");
me->add("soilder",-myda);
tell_object(who,"µ–»À∆¥√¸Ω¯π•£¨ƒ„’€À¡À:"+chinese_number(vda)+"√˚»À¬Ì°£\n");
victim->add("soilder",-vda);
victim->add("defendance",-2);
if(victim->query("defendance")<0) victim->set("defendance",0);
}
}
*/
// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
// cloud”⁄2000,9£¨‘ˆº”≈≠∆¯÷µ£¨”√“‘∏ƒ±‰’Ω∂∑÷–≥ˆ’–µƒ…À∫¶∂»£¨“‘º∞≥ˆ’–∆µ¬ 
varargs int do_attack(object me, object victim, object weapon, int attack_type)
{
   mapping my, your, action, victim_action;
   string limb, *limbs, result;
   string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
   mixed foo;
   int ap, dp, pp;
   int damage, damage_bonus, defense_factor;
   int wounded = 0;
   //int cost;
   int mod_val;
   
   my = me->query_entire_dbase();
   your = victim->query_entire_dbase();

   //
   // (1) Find out what action the offenser will take.
   //
   action = me->query("actions");
   if( !mapp(action) ) {
     me->reset_action();
     action = me->query("actions");
     if( !mapp(action) ) {
        CHANNEL_D->do_channel( this_object(), "sys",
          sprintf("%s(%s): bad action = %O",
             me->name(1), me->query("id"), me->query("actions", 1)));
        return 0;
     }
   }
   result = "\n" + action["action"] + "£°\n";

   //
   // (2) Prepare AP, DP for checking if hit.
   //
   if( objectp(weapon) )   {
            if( weapon->query("use_apply_skill") )
                attack_skill = weapon->query("apply/skill_type");
            else
                attack_skill = weapon->query("skill_type");
        }
   else             attack_skill = "unarmed";

   limbs = victim->query("limbs");
   limb = limbs[random(sizeof(limbs))];

   ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
   //‘⁄’‚¿Ô£¨ø¥ø¥≥ˆ’–’ﬂ”–√ª”–∫‹¥Ûµƒ∑ﬂ≈≠÷µ£¨”–ø…ƒ‹ª·≥ˆ’––◊∫›£¨µ´∑¿”˘ª·ºıµÕ…Ÿ–Ì
   if( me->query("anger")>30 )//”–≈≠ ±
   if( me->query("anger")>90 || random(5)>3 )
   {
       me->set_temp("anger_attack",random(100));//Àµ√˜≥ˆ’–—œ¿˜£¨∑¿”˘ΩµµÕ¡À
	   ap = (ap*me->query("anger")*me->query("anger_attack"))/10000 + ap;
	   me->set("anger",0);//≥ˆπ˝∫›’–¡À£¨≈≠∆¯œ˚ ß
   }
   
   if( ap < 1) ap = 1;
   
   dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
    dodge_skill = victim->query_skill_mapped("dodge");
   mod_val = 0;
   if( dodge_skill )  {
       victim_action = SKILL_D(dodge_skill)->query_action();
      if( victim_action && victim_action["dodge_power"] )
         mod_val = victim_action["dodge_power"];
   }
   //Àµ√˜≥ˆ’–—œ¿˜£¨∑¿”˘ΩµµÕ¡À
   if( victim->query_temp("anger_attack") )
   {
	   dp = (dp*(100+random(victim->query("cps"))-victim->query_temp("anger_attack")))/100;
	   victim->delete_temp("anger_attack");
   }

   if( dp < 1 ) dp = 1;
   if( victim->is_busy() ) dp /= 3;

        if( userp(me))
        {
                        if( my["force_factor"] && (my["force"] >
                        my["force_factor"]) )
                                        my["force"] -= my["force_factor"];
                        else
                                        my["force_factor"] = 0;
        }

   if( action["dodge"] )  mod_val += action["dodge"];
   if( dp > 1000000 )
       mod_val = dp / 100 * (100 + mod_val);
    else 
      mod_val = (100 + mod_val) * dp / 100;
   if( mod_val < 1 ) mod_val = 1;
   if( mod_val > ((ap + dp)/100*80)) mod_val = (ap + dp)/100*80;

   //
   // (3) Fight!
   //     Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
   //     AP and DP are greater than zero, so we always have chance to hit
   //     or be hit.
   //  
   if( random(ap + dp) < mod_val ) {      // Does the victim dodge this hit?

     if( !dodge_skill ) {
        dodge_skill = "dodge"; 
           result += SKILL_D(dodge_skill)->query_dodge_msg(limb);
     }
     else   {
           if( victim_action && victim_action["dodge_action"] )
          result += victim_action["dodge_action"];
     else
          result += SKILL_D(dodge_skill)->query_dodge_msg(limb);
     }

     if( dp < ap && (!userp(victim) || !userp(me)) 
     &&     random(sizeof(victim->query_enemy())) < 4
     &&   random(your["sen"]*100/your["max_sen"] + your["int"]*your["cps"]) > 150 ) {
        your["combat_exp"] += 1;
        victim->improve_skill("dodge", 1);
     }

     // This is for NPC only. NPC have chance to get exp when fail to hit.
     if( (ap < dp) && !userp(me) ) {
        if( random(my["int"]) > 15 ) my["combat_exp"] += 1;
        me->improve_skill(attack_skill, random(my["int"]));
     }
     damage = RESULT_DODGE;

   } else {

     //
     //   (4) Check if the victim can parry this attack.
     //
     if( victim->query_temp("weapon") ) {
        pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
        if( !weapon ) pp *= 2;
        parry_skill = victim->query_skill_mapped("parry");
     } else {
      pp = skill_power(victim, "unarmed", SKILL_USAGE_DEFENSE);
        parry_skill = victim->query_skill_mapped("unarmed");
        if( weapon ) pp /= 2;
     }

     if( victim->is_busy() ) pp /= 3;
     if( pp < 1 ) pp = 1;
     mod_val = 0;
        if( action["parry"] )       mod_val = action["parry"];
     if( pp > 1000000 )
        mod_val = pp / 100 * (100 + mod_val);
     else
        mod_val = (100 + mod_val) * pp / 100;
     if(mod_val < 1)  mod_val = 1;
     if( mod_val > ((ap + dp)/100*80)) mod_val = (ap + dp)/100*80;

     if( random(ap + pp)< mod_val ) {

        //parry_skill = victim->query_skill_mapped("parry");
        if( !parry_skill ) parry_skill = "parry";
        // change to SKILL_D(parry_skill) after added parry msg to those
        // martial arts that can parry.
        // because of number of local variable limit, here use
        // dodge_skill
        dodge_skill = SKILL_D(parry_skill)->query_parry_msg(weapon);
        if( dodge_skill )     result += dodge_skill;
        else
            result += SKILL_D("parry")->query_parry_msg(weapon);

        if( pp < ap && (!userp(victim) || !userp(me)) 
        &&     random(sizeof(victim->query_enemy())) < 4
        &&   random(your["sen"]*100/your["max_sen"] + your["int"]*your["cps"]) > 150 ) {
          your["combat_exp"] += 1;
          victim->improve_skill("parry", 1);
        }
        damage = RESULT_PARRY;

     } else {

        //
        //   (5) We hit the victim and the victim failed to parry
        //

        damage = me->query_skill(attack_skill) / 4;
        damage += me->query_temp("apply/damage");
        damage = (damage + random(damage)) / 2;
        if( action["damage"] )
          damage += action["damage"] * damage / 100;

        damage_bonus = me->query_str();

        // Let force skill take effect.
        if( my["force_factor"] && (my["force"] > my["force_factor"]) ) {
          if( force_skill = me->query_skill_mapped("force") ) {
             foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["force_factor"]);
             if( stringp(foo) ) result += foo;
             else if( intp(foo) ) damage_bonus += foo;
          }
        }

        if( action["force"] )
          damage_bonus += action["force"] * damage_bonus / 100;

        if( martial_skill = me->query_skill_mapped(attack_skill) ) {
          foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
          if( stringp(foo) ) result += foo;
          else if(intp(foo) ) damage_bonus += foo;
        }

        // Let weapon or monster have their special damage.
        if( weapon ) {
          foo = weapon->hit_ob(me, victim, damage_bonus);
          if( stringp(foo) ) result += foo;
          else if(intp(foo) ) damage_bonus += foo;
        } else {
          foo = me->hit_ob(me, victim, damage_bonus);
          if( stringp(foo) ) result += foo;
          else if(intp(foo) ) damage_bonus += foo * 3 / 4;
        }

        if( damage_bonus > 0 )
          damage += (damage_bonus + random(damage_bonus))/2;
        if( damage < 0 ) damage = 0;


        // Let combat exp take effect
        defense_factor = your["combat_exp"];
        while( random(defense_factor) > my["combat_exp"] ) {
          damage -= damage / 3;
          defense_factor /= 2;
        }

        //
        //   (6) Inflict the damage.
        //

        damage = victim->receive_damage("kee", damage, me );


        if( (me->is_killing(victim) || weapon)
        && random(damage) > (int)victim->query_temp("apply/armor") ) {
          // We are sure that damage is greater than victim's armor here.
          victim->receive_wound("kee",
             damage - (int)victim->query_temp("apply/armor"), me);
          wounded = 1;
        }
          
        result += damage_msg(damage, action["damage_type"]);

		//”…”⁄ ‹µΩ…À∫¶£¨victim≤˙…˙∑ﬂ≈≠£¨∑ﬂ≈≠÷µÀÊ◊≈…À∫¶¥Û–°∂¯±‰
        if( damage > victim->query("max_kee")/5)
			victim->add("anger",10+random(10));
		else
              victim->add("anger",1+random(10));
		tell_object(victim,"ƒ„µƒ≈≠∆¯‘ˆº”¡À£°\n");
		if( victim->query("anger")>100 ) victim->set("anger",100);

        //
        //   (7) Give experience
        //

        if( !userp(me) || !userp(victim) ) {
          if( (ap < dp)
          &&   (random(my["sen"]*100/my["max_sen"] + my["int"]*my["cps"]) > 150) ) {
             my["combat_exp"] += 1;
             if( my["potential"] - my["learned_points"] < 100 )
               my["potential"] += 1;
             me->improve_skill(attack_skill, 1);
          }
          if( random(your["max_kee"] + your["kee"]) < damage ) {
             your["combat_exp"] += 1;
             if( your["potential"] - your["learned_points"] < 100 )
               your["potential"] += 1;
          }
        }
     }
   } 

   result = replace_string( result, "$l", limb );
   if( objectp(weapon) )
     result = replace_string( result, "$w", weapon->name() );
   else if( stringp(action["weapon"]) )
     result = replace_string( result, "$w", action["weapon"] );
   if( objectp(victim->query_temp("weapon")) )
     result = replace_string( result, "$W", 
       victim->query_temp("weapon")->name() );

   if ((damage != RESULT_DODGE) && (damage != RESULT_PARRY) )
     message_vision(result, me, victim );
   else
     if ( (string)me->query("env/brief_message") != "YES" 
       && (string)victim->query("env/brief_message") != "YES" ) 
        message_vision(result, me, victim );

   if( wizardp(me) && (string)me->query("env/combat")=="verbose" ) {
     if( damage > 0 )
        tell_object(me, sprintf( GRN "AP£∫%d£¨DP£∫%d£¨PP£∫%d£¨Mod£∫%d£¨…À∫¶¡¶£∫%d\n" NOR,
          ap, dp, pp, mod_val, damage));
     else
        tell_object(me, sprintf( GRN "AP£∫%d£¨DP£∫%d£¨PP£∫%d£¨Mod£∫%d\n" NOR,
          ap, dp, pp, mod_val));
   }
   if( wizardp(victim) && (string)victim->query("env/combat")=="verbose" ) {
     if( damage > 0 )
        tell_object(victim, sprintf( GRN "AP£∫%d£¨DP£∫%d£¨PP£∫%d£¨Mod£∫%d£¨…À∫¶¡¶£∫%d\n" NOR,
          ap, dp, pp, mod_val, damage));
     else
        tell_object(victim, sprintf( GRN "AP£∫%d£¨DP£∫%d£¨PP£∫%d£¨Mod£∫%d\n" NOR,
          ap, dp, pp, mod_val));
   }

   if( damage > 0 ) {
     report_status(victim, wounded);
     if( victim->is_busy() ) victim->interrupt_me(me);
     if( (!me->is_killing(your["id"])) && (!victim->is_killing(my["id"])) ) {
       // fight until one side's kee is < 50%
       if( victim->query("kee") < victim->query("max_kee") * 50 / 100)  {
         //≤ª¥Ú¡À£¨≈≠œ˚ ß
		 me->set("anger",0);
		 victim->delete_temp("anger_attack");
		 victim->set("anger",0);
		 me->delete_temp("anger_attack");

		 me->remove_enemy(victim);
         victim->remove_enemy(me);
         message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
          }
     }
   }

   if( functionp(action["post_action"]) )
     evaluate( action["post_action"], me, victim, weapon, damage);

   if( damage > 0 && attack_type != TYPE_QUICK &&
    me->query_temp("perf_quick") && me->is_fighting(victim) )   {
        if( me->query_temp("weapon") &&
        me->query_temp("perf_quick/"+me->query_temp("weapon")->query("skill_type")) )  {
           if( me->query_temp("perf_quick/msg") )
               message_vision(CYN + me->query_temp("perf_quick/msg") +NOR, me, victim);
           else
               message_vision(CYN + "$N"NOR+CYN"µ√ ∆≤ª»ƒ»À£¨∂‘$n"NOR+CYN"’πø™¡¨–¯π•ª˜°£"+NOR, me, victim);
           do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
           return 1;
        }
    }

   // See if the victim can make a riposte.
   if( attack_type==TYPE_REGULAR
   &&   damage < 1
   &&   victim->query_temp("guarding") ) {
     victim->set_temp("guarding", 0);
     if( random(my["cps"]) < 5 ) {
        message_vision("$N“ªª˜≤ª÷–£¨¬∂≥ˆ¡À∆∆’¿£°\n", me);
        do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
     } else {
        message_vision("$Nº˚$nπ•ª˜ ßŒÛ£¨≥√ª˙∑¢∂Øπ•ª˜£°\n", victim, me);
        do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
     }
   }
}
varargs int shibai(object me, object victim,object who)
{
message("vision",HIY+"°æŒ‰¡÷∑…œ≠°ø"+NOR+HIC+me->query("name")+"∂‘"+
victim->query("short")+"µƒΩ¯π•Œﬁπ¶∂¯∑µ°£"+who->query("name")+" ÿŒ¿ §¿˚.\n"NOR,users());
//tell_object(who,"ƒ„±£Œ¿¡À≥« –£¨µ√µΩ¡À“ªƒÍµƒµ¿––Ω±¿¯°£\n");
//who->add("combat_exp",1000);
me->set("soilder",0);
me->set("train_level",0);
me->remove_enemy(victim);
me->delete("attacking");	
victim->delete("receive_attack");
victim->save();
return 1;
}

varargs int chenggong(object me, object victim,object who)
{
message("vision",HIY+"°æŒ‰¡÷∑…œ≠°ø"+NOR+HIC+me->query("name")+"π•’º¡À"+
victim->query("short")+" ,"+who->query("name")+" ÿŒ¿ ß¿˚.\n"NOR,users());
victim->set("owner",me->query("id"));
victim->set("owner_name",me->query("name"));
victim->set("soilder",0);
victim->set("train_level",0);
me->remove_enemy(victim);
me->delete("attacking");	
victim->delete("receive_attack");
victim->save();
return 1;
}

varargs int do1_attack(object me, object victim,object who)     //π¶≥«µƒ÷¥––
{
int myda,vda;
int one,two,three;
int ap,dp;
one=me->query("soilder");
two=victim->query("soilder");
three=victim->query("defendance");
message_vision("$NΩ´ ÷÷–≥§µ∂“ªª”°£±¯Ω´“œæ€£¨”ø÷¡≥«±ﬂ£¨“ª±ﬂº‹∆‘∆Ã›≈ ‘Ω≥««Ω£¨“ª±ﬂæÚÕ¡∂¯Ω¯°£\n",me);
message_vision("$N÷ªº˚≥««Ω…œÕÚº˝∆Î∑…£¨¿ﬁ Ø≤¢∑¢£¨ ÿµ√ «¿◊¥Ú≤ª∂Ø£¨ÀÆ∆√≤ªΩ¯°£\n",me);
ap=one*me->query("train_level");
dp=two*(victim->query("train_level")+three);
if((ap<=0)&&(dp>0))
{
  shibai(me,victim,who);
  return 1;
}
if((ap>0)&&(dp<=0))
{
   chenggong(me,victim,who);
   return 1;
}
if(ap < dp )
{
message_vision("$Nµƒ ÿ ∆µ±’Ê¿Œøø£¨‘⁄“ª’Ûº§¡“µƒ»‚≤´÷Æ∫Û£¨$nµƒπ• ∆ª∫¡Àœ¬¿¥°£\n",who,me);
myda=(dp-ap)/1000;
if(myda<=0) myda=-1*myda+1;
tell_object(me,"µ–»À∆¥√¸µ÷øπ£¨ƒ„’€À¡À:"+chinese_number(myda)+"√˚»À¬Ì°£\n");
me->add("soilder",-myda);
if(me->query("soilder") < 0) { me->set("soilder",0); shibai(me,victim,who); return 1;}
tell_object(who,"µ–»À∆¥√¸Ω¯π•£¨ƒ„’€À¡À:"+chinese_number(myda/2)+"√˚»À¬Ì°£\n");
victim->add("soilder",-myda/5);
if(victim->query("soilder") < 0) { victim->set("soilder",0); chenggong(me,victim,who); return 1;}
}else
if(ap < 5*dp)
{
message_vision("$Nµƒ ÿ ∆µ±’ÊÕÁ«ø£¨‘⁄“ª’Ûº§¡“µƒ»‚≤´÷Æ∫Û£¨$nªπ «ƒ√≤ªœ¬¿¥°£\n",who,me);
myda=(ap-dp)*dp/(ap*1000);
vda=(ap-dp)*ap/(dp*1000);
if(vda<=0) vda=-1*vda+1;
if(myda<=0) myda=-1*myda+1;
tell_object(me,"µ–»À∆¥√¸µ÷øπ£¨ƒ„’€À¡À:"+chinese_number(myda)+"√˚»À¬Ì°£\n");
me->add("soilder",-myda);
if(me->query("soilder") < 0) { me->set("soilder",0); shibai(me,victim,who); return 1;}
tell_object(who,"µ–»À∆¥√¸Ω¯π•£¨ƒ„’€À¡À:"+chinese_number(vda)+"√˚»À¬Ì°£\n");
victim->add("soilder",-vda);
if(victim->query("soilder") < 0) { victim->set("soilder",0); chenggong(me,victim,who); return 1;}
victim->add("defendance",-1);
if(victim->query("defendance")<0) victim->set("defendance",0);
}else 
{
message_vision("$Nµƒ ÿ ∆À‰»ªÕÁ«ø£¨‘⁄“ª’Ûº§¡“µƒ»‚≤´÷Æ∫Û£¨$nªπ «Ω•Ω•’º¡À”≈ ∆°£\n",who,me);
myda=(ap-dp)*dp/(ap*2000);
vda=(ap-dp)*ap/(dp*500);
if(vda<=0) vda=-1*vda+1;
if(myda<=0) myda=-1*myda+1;
tell_object(me,"µ–»Àµ÷øπΩ•»ı£¨ƒ„’€À¡À:"+chinese_number(myda)+"√˚»À¬Ì°£\n");
me->add("soilder",-myda);
if(me->query("soilder") < 0) { me->set("soilder",0); shibai(me,victim,who); return 1;}
tell_object(who,"µ–»À∆¥√¸Ω¯π•£¨ƒ„’€À¡À:"+chinese_number(vda)+"√˚»À¬Ì°£\n");
victim->add("soilder",-vda);
if(victim->query("soilder") < 0) { victim->set("soilder",0); chenggong(me,victim,who); return 1;}
victim->add("defendance",-2);
if(victim->query("defendance")<0) victim->set("defendance",0);
}
}

//	fight()
//
//	This is called in the attack() defined in F_ATTACK, which handles fighting
//	in the heart_beat() of all livings. Be sure to optimize it carefully.
//
void fight(object me, object victim)
{
	object ob;

	if( !living(me) ) return;
	if( me->query_temp("netdead") )  return;
  	if( victim->query_temp("netdead") )   {
   	    if( member_array( me, victim->query_netdead_enemy() ) == -1 )
		return;     // can't start fight if the victim is already netdead
 	}

	if( !me->visible(victim)
	&& (random(100 + (int)me->query_skill("perception")) < 100) )
		return;
   /*    if(me->query("attacking")){                 //π•≥«ø™ º°£
      ob=find_player(victim->query("owner"));
      do1_attack(me,victim,ob);
            } */
	// If victim is busy or unconcious, always take the chance to make an attack.
	// added: if victim is in "no_move", similar to "is_busy".
	if( victim->is_busy() || (victim->query_temp("no_move")) || !living(victim) ) {
		me->set_temp("guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);
		do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

	// Else, see if we are brave enough to make an aggressive action.
	} else if( random( (int)victim->query("cps") * 3 ) < ((int)me->query("cor") + (int)me->query("bellicosity") / 50) ) {
		me->set_temp("guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);
		do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);

	// Else, we just start guarding.
	} else if( !me->query_temp("guarding") ) {
		me->set_temp("guarding", 1);
		message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
		return;
	} else return;
}

//	auto_fight()
//
//	This function is to start an automatically fight. Currently this is
//	used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
	// Don't let NPC autofight NPC.
	if( !userp(me) && !userp(obj) ) return;

	// Because most of the cases that we cannot start a fight cannot be checked
	// before we really call the kill_ob(), so we just make sure we have no 
	// aggressive callout wating here.
	if( me->query_temp("looking_for_trouble") ) return;
	me->set_temp("looking_for_trouble", 1);

	// This call_out gives victim a chance to slip trough the fierce guys.
	call_out( "start_" + type, 0, me, obj);
}

void start_berserk(object me, object obj)
{
	int bellicosity;

	if( !me ) return;// Are we still exist( not becoming a corpse )?
	me->set_temp("looking_for_trouble", 0);
	if( !obj ) return;

	if( wizardp(obj) ) return;	

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	bellicosity = (int)me->query("bellicosity");
	message_vision("$N”√“ª÷÷“Ï—˘µƒ—€…Ò…® ”◊≈‘⁄≥°µƒ√ø“ª∏ˆ»À°£\n", me);

	if(	(int)me->query("force") > (random(bellicosity) + bellicosity)/2 ) return;

	if( bellicosity > (int)me->query("score") 
	&&	!wizardp(obj) ) {

	    // auto kill, mark my_killer_list. -- mon 9/23/98
	    if(userp(me) && userp(obj)) {
        	set_my_killer_list(me, obj);
	    }

	    message_vision("$N∂‘◊≈$n∫»µ¿£∫" + RANK_D->query_self_rude(me)
		+ "ø¥ƒ„ µ‘⁄∫‹≤ªÀ≥—€£¨»•À¿∞…°£\n", me, obj);
	    me->kill_ob(obj);
	} else {
		message_vision("$N∂‘◊≈$n∫»µ¿£∫Œπ£°" + RANK_D->query_rude(obj)
			+ "£¨" + RANK_D->query_self_rude(me) + "’˝œÎ’“»À¥Úº‹£¨≈„Œ“ÕÊ¡Ω ÷∞…£°\n",
			me, obj);
		me->fight_ob(obj);
	}
}

void start_hatred(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We found our hatred! Charge!
	message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
	me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We found our vendetta opponent! Charge!
	me->kill_ob(obj);
//	obj->fight_ob(me);
}

void start_aggressive(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We got a nice victim! Kill him/her/it!!!
	me->kill_ob(obj);
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event, string msg)
{
	switch(event) {
		case "dead":
			message_vision("\n$NÀ¿¡À°£\n\n", ob);
			break;
		case "unconcious":
			message_vision("\n$NΩ≈œ¬“ª∏ˆ≤ªŒ»£¨µ¯‘⁄µÿ…œ“ª∂Ø“≤≤ª∂Ø¡À°£\n\n", ob);
			break;
		case "revive":
			message_vision("\n$N¬˝¬˝’ˆø™—€æ¶£¨«Â–—¡Àπ˝¿¥°£\n\n", ob);
			break;
                case "death_rumor":
			CHANNEL_D->do_channel(this_object(),"rumor",msg);
			break;
	}
}

void winner_reward(object killer, object victim)
{
	killer->defeated_enemy(victim);
}

void killer_reward(object killer, object victim)
{
	int bls,exp, pot, score,level;
	string vmark,killmsg,rkmsg;
	int gain,gain1,lose;
	string str,killerid;
	object weapon;
	// Call the mudlib killer apply.
	killer->killed_enemy(victim);

	if( userp(victim) ) { // victim is user.
	    
	    string *my_killer_list;
	    int init_killer;
	    int no_pk;

	   killer->add("PKS", 1);
	   killer->add("PKD", 1);
	   
	   killerid=killer->query("id");
           //‘ˆº”À¿Õˆº«¬º°¢≥»À√˚°¢»’∆⁄  by LitChi
          victim->set("kill/killer_name",killer->query("name"));
//By tianlin@mhxy for 2002.1.23–ﬁ∏ƒlitchi◊ˆµƒ ±º‰º”»Îpker id.
          victim->set("kill/killer_id",killer->query("id"));
          victim->set("kill/killer_date",BJTIME_D->chinese_time(1, time()) ); 

	   // mon 8/4/98
	   // to see whether the killer has init the kill on me.
	   // if yes, then this is PK. (init_killer!=-1)
	   // if no, (means the victim init the kill and got killed),
	   // then treat this as normal death. (init_killer==-1)
	   my_killer_list=victim->query_temp("my_killer_list");
	   victim->delete_temp("my_killer_list");

	   if(!my_killer_list) init_killer=-1;
	   else init_killer=member_array(killerid, my_killer_list);
		
	   no_pk=killer->query_condition("no_pk_time");
	   if(no_pk>10) init_killer=1; // killed by a player who
	   // has PK record, then this is PK.
           // regardless who init it.

///////////////////////////////////////////////////////////////////////
killmsg=killer->query_temp("kill_msg");
    if(killmsg)
    {
	switch (killmsg)
	{
		case "slash":
	 	{	rkmsg="’∂";	}
		break;
		case "slice":
	 	{	rkmsg="ø≥";	}
		break;
		case "chop":
	 	{	rkmsg="≈¸";	}
		break;
		case "hack":
	 	{	rkmsg="≈¸";	}
		break;
		case "thruse":
	 	{	rkmsg="¥Ã";	}
		break;
		case "pierce":
	 	{	rkmsg="¥Ã";	}
		break;
		case "wave":
	 	{	rkmsg="±ﬁ";	}
		break;
		case "whip":
	 	{	rkmsg="≥È";	}
		break;
		case "impale":
	 	{	rkmsg="¥¡";	}
		break;
		case "rake":
	 	{	rkmsg="÷˛";	}
		break;
		case "bash":
	 	{	rkmsg="‘“";	}
		break;
		case "crush":
	 	{	rkmsg="‘“";	}
		break;
		case "slam":
	 	{	rkmsg="¥Ï";	}
		break;
		case "throw":
	 	{	rkmsg="…‰";	}
		break;
		case "shoot":
	 	{	rkmsg="…‰";	}
		break;
//now start cast :
//		case "cast_qiankun":	//∑«π•ª˜–‘ transfer , chuqiao, qiankun, yinshen
//		{	rkmsg="";	}
//		break;
		case "cast_zhenhuo":
		{	rkmsg="Ã´““’Êª";		}
		break;
		case "cast_baxian":
		{	rkmsg="∞Àœ…¥Û’Û";		}
		break;
		case "cast_bighammer":
		{	rkmsg="¥Û¡¶ΩµƒßË∆";		}
		break;
		case "cast_jingang":
		{	rkmsg="’ŸªΩΩ∏’";		}
		break;
		case "cast_jinguzhou":
		{	rkmsg="ΩÙπø÷‰";		}
		break;
		case "cast_thunder":
		{	rkmsg="ŒÂ¿◊÷‰";		}
		break;
		case "cast_invocation":
		{	rkmsg="’ŸªΩÃÏΩ´";		}
		break;
		case "cast_fenshen":
		{	rkmsg="∑÷…Ì ı";		}
		break;
		case "cast_dingshen":
		{	rkmsg="∂®…Ì∑®";		}
		break;
		case "cast_light":
		{	rkmsg="≤‘¡Èº˝";		}
		break;
		case "cast_jieti"://escape, tudun, suliao, huanying
		{	rkmsg="ÃÏƒßΩ‚ÃÂ¥Û∑®";		}
		break;
		case "cast_sanmei":
		{	rkmsg="»˝Œ∂’Êª";		}

		break;
		case "cast_zhuang":
		{	rkmsg="∆ΩÃÏ¥Û∑®";		}
		break;
		case "cast_arrow":
		{	rkmsg="¬‰»’…Òº˝";		}
		break;
		case "cast_shiyue":// mihun huimeng
		{	rkmsg=" ¥‘¬÷‰";		}
		break;
		case "cast_qingwang":
		{	rkmsg="«ÈÕ¯";		}
		break;
		case "cast_hufa":
		{	rkmsg="’ŸªΩª§∑®";		}
		break;
		case "cast_freez":
		{	rkmsg="—©ŒË∑Á¡È";		}
		break;
		case "cast_jiushen":
		{       rkmsg="æ∆…Ò";       }
		break;
		case "cast_jianshen":
		{       rkmsg="Ω£…Ò";       }
		break;
		case "cast_tuntian":
		{       rkmsg="ƒß ﬁÕÃÃÏ";       }
		break;
		case "cast_gouhun"://miwu
		{	rkmsg="π¥ªÍ ı";		}
		break;
		case "cast_animate":
		{	rkmsg="∏¥ªÓπÌªÍ";		}
		break;
		case "cast_fu":
		{	rkmsg="ÃÏ ¶∑˚∑®";		}
		break;
		case "cast_wuzhishan":
		{	rkmsg="ŒÂ÷∏…Ω";		}
		break;
		case "cast_sanmei":
		{	rkmsg="»˝√¡’Êª";		}
		break;
		case "cast_yading":
		{	rkmsg="ÃÏ÷Ì—π∂•";		}
		break;
/*		case "cast_":
		{	rkmsg="";		}
		break;
*/
// now start perform msg
		case "perform_sanban":
		{	rkmsg="Œﬁµ–»˝∞Â∏´";		}
		break;
		case "perform_haotan":
		{	rkmsg="≥’«È∞ÀÃæ";		}
		break;
		case "perform_hongyan":
		{	rkmsg="∫Ï—’∞◊∑¢";		}
		break;	
		case "perform_zplw":
		{	rkmsg="÷Ì∞“¬“ŒË";		}
		break;	
		case "perform_daoda":
		{	rkmsg="µπ¥Ú“ª∞“";		}
		break;	
		case "perform_daoluan":
		{	rkmsg="µπ¬“∆ﬂ–«";		}
		break;	
        	case "perform_huadie":
		{	rkmsg="ªØ    µ˚";		}
		break;
		case "perform_mantian":
		{	rkmsg="«‡œº¬˛ÃÏ";		}
		break;
		case "perform_wang":
		{	rkmsg="ÃÏ¬ﬁµÿÕ¯";		}
		break;
		case "perform_kai":
		{	rkmsg="ø™ÃÏ±Ÿµÿ";		}
		break;
		case "perform_meihua":
		{	rkmsg="√∑ª®¡˘≥ˆ";		}
		break;
		case "perform_lei":
		{	rkmsg="¿◊ÈÍ≈≠ª";		}
		break;
		case "perform_zhua":
		{	rkmsg="Œﬁ≥£◊¶";		}
		break;
		case "perform_ldlh":
		{	rkmsg="¡˘µ¿¬÷ªÿ";		}
		break;
		case "perform_lunhui":
		{	rkmsg="¡∂”¸";		}
		break;
		case "perform_pudu":
		{	rkmsg="¥»π‚∆’∂…";		}
		break;
		case "perform_xlfh":
		{	rkmsg="Ωµ¡˙∑¸ª¢";		}
		break;
		case "perform_storm":
		{	rkmsg="±©∑Á÷Ë”Í";		}
		break;
		case "perform_diyu":
		{	rkmsg="Œ“»Îµÿ”¸";		}
		break;
		case "perform_pili":
		{	rkmsg="≈˘ˆ®»˝¥Ú";		}
		break;
		case "perform_qiankun":
		{	rkmsg="«¨¿§“ª∞Ù";		}
		break;
		case "perform_pozhan":
		{	rkmsg="∆∆’¿∞Ÿ≥ˆ";		}
		break;
		case "perform_zhangxinlei":
		{	rkmsg="’∆–ƒ¿◊";		}
		break;
		case "perform_flower":
		{	rkmsg="ÃÏ≈Æ…¢ª®";	}
		break;
		case "perform_diezhang":
		{	rkmsg="µ˛’∆";		}
		break;
		case "perform_huifeng":
		{	rkmsg="ªÿ∑Á";		}
		break;
		case "perform_wuxue":
		{	rkmsg="ŒË—©";		}
		break;
		case "perform_sheshen":
		{	rkmsg="…·…Ìºº";		}
		break;
		case "perform_three":
		{	rkmsg="…Ò°§»À°§πÌ";	}
		break;
		case "perform_chaofeng":
		{	rkmsg="∞ŸƒÒ≥Ø∑Ô";	}
		break;
		case "perform_feijian":
		{	rkmsg="∑…ƒÒÕ∂¡÷";	}
		break;
		case "perform_yaowu":
		{	rkmsg="—˝ŒÌ≥ÂÃÏ";	}
		break;
		case "perform_fumo":
		{	rkmsg="”˘Ω£∑¸ƒß";	}
		break;
		case "perform_jinsheng":
		{	rkmsg="”˘Ω£ΩÒ…˙";	}
		break;
		case "perform_wanjian":
		{	rkmsg="ÕÚΩ£æˆ";	}
		break;
		case "perform_duanshui":
		{	rkmsg="∂œÀÆŒﬁ∫€";	}
		break;
		case "perform_feilong":
		{	rkmsg="∑…¡˙ÃΩ‘∆ ÷";	}
		break;
		case "perform_buhui":
		{	rkmsg="≤ªª⁄";	}
		break;
		case "perform_fengchan":
		{	rkmsg="ŒÂ‘¿∑‚Ï¯";	}
		break;
		case "perform_ji":
		{	rkmsg="º¿«π";	}
		break;
	        case "perform_huohun":
		{	rkmsg="ªªÍ";	}
		break;
	       case "perform_lihuo":
		{	rkmsg="¿Îª»˝÷ÿ";	}
		break;
	       case "perform_shenli":
		{	rkmsg="…Ò¡¶";	}
		break;
	       case "perform_leidong":
		{	rkmsg="¿◊∂Øæ≈ÃÏ";	}
		break;
	       case "perform_break":
		{	rkmsg="ªÏ‘™“ª∆∆";	}
		break;
	       case "perform_fengbo":
		{	rkmsg="Œﬁæ°∑Á≤®";	}
		break;
	       case "perform_juejian":
		{	rkmsg="»˝«Âæ¯Ω£";	}
		break;
	       case "perform_jianzhang":
		{	rkmsg="Ω£’∆";	}
		break;
	       case "perform_jianmang":
		{	rkmsg="¡Èª√Ω£√¢";	}
		break;
	    case "perform_jianqi":
		{	rkmsg="¡Èª√Ω£∆¯";	}
		break;
	    case "perform_luanwu":
		{	rkmsg="»∫ƒß¬“ŒË";	}
		break;
	    case "perform_tiandi":
		{	rkmsg="ÃÏµÿÕ¨ Ÿ";	}
		break;
	    case "perform_zouxiao":
		{	rkmsg="±ÃÛÔ¥´«È";	}
		break;
	    case "perform_damoyange":
		{	rkmsg="¥ÛƒÆ—„∏Ë";	}
		break;
/*		case "perform_":
		{	rkmsg="";		}
		break;
*/
		
//now start exert .........// ∑«π•ª˜–‘ recover refresh transfer regenerate heal lifeheal
		case "exert_sheqi":
		{	rkmsg="…„∆¯";		}
		break;
		case "exert_roar":
		{	rkmsg="¡˙“˜";		}
		break;
		
		case "special_msg"://Ãÿ ‚µƒπ•ª˜
		{	rkmsg=killer->query_temp("special_msg");	
			killer->delete_temp("special_msg");
		}
		break;
	}
      }//if(killmsg)
	



           if(userp(killer) && init_killer!=-1) { // killer is user.
//           if(userp(killer))  // killer is user.
	     killer->apply_condition("no_pk_time",240+no_pk);
	       //limit on how many one can pk in a row.
             lose=victim_lose(killer,victim,killerid);
	     gain=lose*8/10;
	     if(gain<0) gain=0;
	     victim->delete_temp("last_fainted_from");
	     /*
	     if(killerid==victim->query("kill/last_killer")) {
	       //discourage repeated killing same player.
	       gain1=victim->query("kill/last_lose")/2;
               if(gain>gain1) {
	         gain=gain1;
               }
             }
	     */
	     if(lose>100)
	       killer->delete("kill/last_killer");
	     //any one can kill this killer to
	     //get maximum dx benefit.
	     //including the one who last killed 
	     //this killer.
	     //here check lose>100, so one can't
	     //pk a newbie to erase the last_killer flag.
	     killer->add("kill/pkgain",gain);
	     killer->add("daoxing",gain);

	     victim->set("kill/last_killer",killerid);
	     //the victim is protected for repeated
	     //killing by the same killer.
	     victim->set("kill/last_lose",gain);
	     //actually last_lose is what the killer gains,
	     //not really the victim lose.
	     //victim loss is in /death/combat_exp_loss
//	     victim->add("kill/pklose",lose);
//	     victim->add("daoxing",-lose);
             
	     victim_penalty(victim);

             str=chinese_daoxing(gain);
             if(strlen(str)>1) {
               str=killer->name(1)+"µ√µΩ"+str+"µ¿––£°";
             } 

//      add by dragon for PK rumor
//by tianlin –ﬁ∏ƒ¡À“ªœ¬—’…´

			weapon=killer->query_temp("kill_weapon");
			if(weapon && rkmsg)
			{			
	     		str=victim->name(1)+"‘⁄[37m"+
	         	MISC_D->find_place(environment(killer))+"[1;35m±ª"+killer->name(1)+"”√"HIY+weapon->name()+HIM+rkmsg+"À¿¡À°£"+str;
	     		CHANNEL_D->do_channel(this_object(), "rumor",str);
			} else {
			if(rkmsg && !weapon)
			{
			str=victim->name(1)+"‘⁄[37m"+
	         	MISC_D->find_place(environment(killer))+"[1;35m±ª"+killer->name(1)+"”√“ª’–"+HIW"°∞"+rkmsg+"°±"+HIM"ÀÕ»•º˚¡À—÷Õı°£"+str;
	     		CHANNEL_D->do_channel(this_object(), "rumor",str);
			}else if(weapon && !rkmsg){
			str=victim->name(1)+"‘⁄[37m"+
	         	MISC_D->find_place(environment(killer))+"[1;35m±ª"+killer->name(1)+"”√"HIY+weapon->name()+HIM"ÀÕ»•¡Àº˚¡À—÷Õı°£"+str;
	     		CHANNEL_D->do_channel(this_object(), "rumor",str);
					   }else {
			str=victim->name(1)+"‘⁄[37m"+
	         	MISC_D->find_place(environment(killer))+"[1;35m±ª"+killer->name(1)+"…±À¿¡À°£"+str;
	     		CHANNEL_D->do_channel(this_object(), "rumor",str);
						  }
			
				
			
	     	}
	     	bls=10;
		killer->delete_temp("kill_weapon");
		killer->delete_temp("kill_msg");
           } else {    // killer is not user or killer didn't init the kill.
	       int i;
	       string last_faint;
	       object fainter;
	       // mon 8/1/98
	       // check who fainted the victim.
	       // if it was a player faint the victim,
	       // give the player credit for pk :)
	       last_faint=victim->query_temp("last_fainted_from");
	       if(last_faint) {
		   fainter=find_player(last_faint);
		   if(fainter && userp(fainter)) {
	             if(!my_killer_list) init_killer=-1;
	             else init_killer=
			 member_array(last_faint, my_killer_list);

		     if(init_killer!=-1) {
                       fainter->apply_condition("no_pk_time",240+
	                 fainter->query_condition("no_pk_time"));
		       log_file("death","["+ctime(time())+"] "+
			       victim->query("id")+" was fainted by "+
			       fainter->query("id")+" and killed by "+
			       killer->query("id")+".\n");
		     }
		   }
	       }

               victim_penalty(victim);

	       bls = 10;
//	       CHANNEL_D->do_channel(this_object(), "rumor",
//		  sprintf("%s±ª%s…±À¿¡À°£", victim->name(1), killer->name(1)));
/////////////////for NK rumor
//by tianlin 2001.8.15		
			weapon=killer->query_temp("kill_weapon");
			if(weapon && rkmsg)
			{			
	     		str=victim->name(1)+"‘⁄[37m"+
	         	MISC_D->find_place(environment(killer))+"[1;35m±ª"+killer->name(1)+"”√"HIY+weapon->name()+HIM+rkmsg+"À¿¡À°£";
	     		CHANNEL_D->do_channel(this_object(), "rumor",str);
			} else {
			if(rkmsg && !weapon)
			{
			str=victim->name(1)+"‘⁄[37m"+
	         	MISC_D->find_place(environment(killer))+"[1;35m±ª"+killer->name(1)+"”√“ª’–"+HIW"°∞"+rkmsg+"°±"+HIM"ÀÕ»•¡À—÷¬ﬁµÿ∏Æ°£";
	     		CHANNEL_D->do_channel(this_object(), "rumor",str);
			}else if(weapon && !rkmsg){
			str=victim->name(1)+"‘⁄[37m"+
	         	MISC_D->find_place(environment(killer))+"[1;35m±ª"+killer->name(1)+"”√"HIY+weapon->name()+HIM"ÀÕ»•¡À—÷¬ﬁµÿ∏Æ°£";
	     		CHANNEL_D->do_channel(this_object(), "rumor",str);
					   }else {
			str=victim->name(1)+"‘⁄[37m"+
	         	MISC_D->find_place(environment(killer))+"[1;35m±ª"+killer->name(1)+"…±À¿¡À°£";
	     		CHANNEL_D->do_channel(this_object(), "rumor",str);
						  }
if ( userp(killer) && !killer->query_temp("kill_killer")) {
                                CHANNEL_D->do_channel(this_object(), "rumor",
                                sprintf("%s±ªπŸ∏ÆÕ®º©¡À°£", killer->name(0)));
                        
        } 
			if(victim->query("PKD")>9)
			{			
	     		str=HIR+"…±»À∑∏"+HIM+victim->name(1)+"‘⁄"+HIW+
	         	MISC_D->find_place(environment(killer))+HIM+"±ª"+killer->name(1)+HIM+"æÕµÿ’˝∑®"+HIM+"£¨"+killer->name(1)+"µ√µΩ¡À”¶”–µƒΩ±¿¯°£";
	     		CHANNEL_D->do_channel(this_object(), "rumor",str);
                           killer->add("daoxing",5000);
                           victim->set("PKD",0);
	}
			if(killer->query("PKD")>9)
			{			
	     		str=victim->name(1)+"‘⁄"+HIW+
	         	MISC_D->find_place(environment(killer))+HIM+"±ª"HIR"…±»À∑∏"HIM+killer->name(1)+HIM+"…±À¿¡À"+HIM+"£¨"+killer->name(1)+"±ª”Òª ¥Ûµ€ºı…Ÿµ¿–– ÆŒÂƒÍ◊˜Œ™¥¶∑£°£";
	     		CHANNEL_D->do_channel(this_object(), "rumor",str);
                           killer->add("daoxing",-15000);
                           victim->set("PKD",0);
	}	
	     	}
           }
	} else {  //NPC is the victim.
	  if(userp(killer)) {
                int reward;

		reward=nk_gain(killer, victim);

		// nk_reward is defined as needed for each NPC
		// this allows individual NPC to customize NK reward.
		// mon 12/24/99
		if((int)victim->nk_reward(killer, reward)>0) {
		    // this NPC has its own reward.
		} else if(reward>0) {
		  string msg;
                  killer->add("kill/nkgain",reward);
		  killer->add("daoxing",reward);
                  str=chinese_daoxing(reward);
                  tell_object(killer,"\nƒ„µ√µΩ¡À"+str+"µ¿––°£\n");
		  msg=sprintf("%s(%d)…±À¿¡À%s(%d)£¨µ√µΩ%dµ„µ¿––°£", 
		    killer->query("id"),(killer->query("daoxing")+
			killer->query("combat_exp"))/2, 
		    victim->query("id"),(victim->query("daoxing")+
			victim->query("combat_exp"))/2,reward);
		  log_file("npc_kill","["+ctime(time())+"] "+msg+"\n");
		  CHANNEL_D->do_channel(this_object(), "sys",msg);
		}
	  }
	  killer->add("MKS", 1);
	  bls = 1;
	}

        if(!userp(killer) &&
	   ((killer->query("daoxing")+killer->query("combat_exp"))/10>
	    (victim->query("daoxing")+victim->query("combat_exp"))) ) bls=0;
        //mon 2/15/98
	//can't use newbie to kill NPC to increase NPC's bls.

	// NPC got 10 times of bellicosity than user.
	killer->add("bellicosity", bls * (userp(killer)? 1: 10));

	if( stringp(vmark = victim->query("vendetta_mark")) )
		killer->add("vendetta/" + vmark, 1);

        if(userp(killer)) killer->save();
	if(userp(victim)) victim->save();
}
//±ª…±∫¶µƒÕÊº“≤Œ ˝…Ë∂®
void victim_penalty(object victim)
{
        int i;

	// by snowcat 2/21/1998 for death/*
	int combat_exp_loss = (int)victim->query("combat_exp") / 40;
	int dx_loss = (int)victim->query("daoxing") / 40;

        victim->clear_condition();
        // Give the death penalty to the dying user.
        victim->set("bellicosity", 0);

	i=victim->query_condition("no_pk_time");
	if(i>240) victim->apply_condition("no_pk_time",i-80);

        victim->set("death/mud_age",victim->query("mud_age"));
        victim->set("death/combat_exp_loss",combat_exp_loss);
        victim->set("death/dx_loss",dx_loss);
	log_file("death",victim->query("id")+
	  " lost "+combat_exp_loss+" exp points and "
	  + dx_loss+ " dx points.\n");

	victim->add("combat_exp", -combat_exp_loss);
	victim->add("daoxing", -dx_loss);
       victim->add("death/die",1);
	victim->delete("vendetta");
	if( victim->query("thief") )
		victim->set("thief", (int)victim->query("thief") / 2);
	if( (int)victim->query("potential") > (int)victim->query("learned_points"))
		victim->add("potential",
  ((int)victim->query("learned_points") - (int)victim->query("potential"))/2 );//À¿ÕˆµÙµƒqnœ÷‘⁄…Ë∂®Œ™2∑÷÷Æ1
        if(random(100)>(int)victim->query("kar")) {
          victim->set("death/skill_loss",1);
  	  victim->skill_death_penalty();
	}
	 else
//	  victim->set("death/skill_loss",0);

        victim->save();
}

int nk_gain(object killer, object victim)
{
	    string fam, fam1;
	    int cla, eff_dx, eff1, eff2, dx, reward, nkgain;

	    // some NPC has no rewards.
	    // mon 3/9/99
	    if(victim->query("no_nk_reward")) return 0;

            //can't kill NPCs which were fainted by
	    //other players to get daoxing.
            if(victim->query_temp("last_fainted_from")
               && victim->query_temp("last_fainted_from")!=
               killer->query("id")) return 0;

            fam=killer->query("family/family_name");

	    if(fam && !undefinedp(family[fam])) {//player must have a
	                                         //family.
              cla=family[fam];
              eff_dx=victim->query("eff_dx");
	      nkgain=victim->query("nkgain");

              //can't kill NPCs of the same menpai as the player
	      //to get daoxing.
	      fam1=victim->query("family/family_name");
	      if(fam1 && fam==fam1)
	        return 0;

              if(eff_dx!=0 && cla*eff_dx>0)
	        return 0;
		//for NPC being set eff_dx, only 
		//if cla*eff_dx<=0 (not all in xian or all in yao)
		//can gain daoxing.

              //For NPC which has not been set eff_dx,
	      //the default is everyone can kill them to get
	      //dx reward, however, the default value is low.
	      if(!eff_dx) { 
	        //default value for eff_dx and nkgain.
		//the default nkgain is low.
		//If want to increase the value for certain NPC,
		//then need to set its eff_dx and nkgain.

                int dxn=0;

		eff_dx=(victim->query("daoxing")+
			victim->query("combat_exp"))/2;
                if(eff_dx>20000)
		  dxn=eff_dx/3;
		else if(eff_dx>5000)
		  dxn=eff_dx/2;
                else 
		  dxn=eff_dx;
		  //make it easier for newbie.
                eff_dx=dxn;
              }

	      if(!nkgain) {
	        int effdx=eff_dx;

		if(effdx<0) effdx=-effdx;

		if(effdx>667000) 
		  nkgain=600;
                else if(effdx>333000)
		  nkgain=500;
                else if(effdx>100000)
		  nkgain=400;
                else if(effdx>33000)
		  nkgain=300;
                else if(effdx>17000)
		  nkgain=200;
                else if(effdx>5000)
		  nkgain=150;
                else if(effdx>2000)
		  nkgain=100;
                else if(effdx>500)
		  nkgain=50;
                else nkgain=25;

		nkgain=nkgain+20;
	      }

                if(eff_dx<0) eff_dx=-eff_dx;
                eff1=eff_dx/8;
		eff2=eff_dx/4;
		dx=(killer->query("daoxing")+
			killer->query("combat_exp"))/2;
		if(dx>eff_dx) reward=0;
		else if(dx>eff2) reward=nkgain;
		else if(dx>eff1) reward=10*(dx-eff1)/(eff2-eff1)*
		  nkgain/10;
                else reward=0;

		if(cla==0 || (cla!=0 && !fam1)) reward=reward*2/3;
		//cla==0: people not xian and not yao. e.g. longgong, moon.
		//cla!=0: people either xian or yao. if they kill
		//        no family NPC, dx reward reduse.

		return reward;
             
            }
	    return 0;
}

int victim_lose(object killer,object victim,string killerid) 
{            int lose,exp_k,exp_v;
             int lose1;

             if((wizardp(victim)&&!wizardp(killer))
	        ||(!wizardp(victim)&&wizardp(killer)))
		return 0;

             if(victim->query_temp("last_fainted_from")
               && victim->query_temp("last_fainted_from")!=
               killerid) {
               lose=0;
             } else {
               exp_k=killer->query("daoxing");
               exp_v=victim->query("daoxing");
               if (exp_k>exp_v) {
                 lose=10*exp_v/(exp_k+1)*(4000+exp_v)/500;
		  // a exp_v/exp_k pre-factor.
		 if(exp_k>exp_v*4) lose=0;
		 // if less then 1/4 dx, then no damage.
               } else {
                 lose=(4000+exp_v)/50;  // about 2% lose for victim.
               }
               if(lose<0) lose=0;
               if(lose>exp_v) lose=exp_v;
             }
	     
	     // this is the maximum lose.
	     lose1=(int)victim->query("daoxing") / 40;
	     if(lose>lose1) lose=lose1;
	     
	     return lose;
}

string chinese_daoxing(int gain)
{            int year,day,hour;
             string str;

             year=gain/1000;
             day=(gain-year*1000)/4;
             hour=(gain-year*1000-day*4)*3;
             str="";
             if(year) str=str+chinese_number(year)+"ƒÍ";
             if(day) str=str+chinese_number(day)+"ÃÏ";
             if(hour) str=str+chinese_number(hour)+" ±≥Ω";

             return str;
}

int check_family(string fam)
{
    if(fam && !undefinedp(family[fam]))
      return family[fam];
    else
      return 0;
}


//the following functions are for performs...weiqi
//copy and modified from spelld.c

int attacking_perform_success(object attacker, object target, int skill_level, int success_adj)
{
        int ap, dp, success;
 
        ap = ( skill_level * skill_level * skill_level / 10 ); //this is from skill.
        //at high exp, the skill level can not follow, so need adjustment here.
        ap = ap*(1+attacker->query("combat_exp")/500000);
        ap = ap+attacker->query("combat_exp");
        dp = target->query("combat_exp");

        success = 0;

        if ( success_adj < 20 ) success_adj = 20;
        else if( success_adj > 500 ) success_adj = 500;

        ap = ap*success_adj/100;

        if( random(100)>dp*100/(ap+dp) ) success = 1;

        return success;
}

int attacking_perform_damage(object attacker, object target, int damage_adj)
{
        int a_neili, d_neili, damage;

        if( damage_adj < 50 ) damage_adj = 50;
        else if( damage_adj > 200 ) damage_adj = 200;

        //will use current neili...but do not allow it exceeds 2 time of the max.
        a_neili = attacker->query("force");
        if( a_neili > 2*attacker->query("max_force") ) a_neili = 2*attacker->query("max_force");
        d_neili = target->query("force");
        if( d_neili > 2*target->query("max_force") ) d_neili = 2*target->query("max_force");


        //neili and qi. weaker than cast here...
        damage = (a_neili - d_neili)/30 + 
                random(attacker->query("eff_kee") / 30)-random(target->query("eff_kee") / 30);

        //mana_factor, here the attacker has some advantage.
        //the damage_adj higher, the better for attacker.
        damage += (3*damage_adj/200) //weaker than cast here...
                *( attacker->query("force_factor") - random(target->query("force_factor")) );

        //for backfire, we need let it be serious...
        if( damage < 0 ) damage = damage - target->query("force_factor"); 
        //here increase the damage, since previously it's included in random()

        damage = damage*damage_adj/100; //last damage scaled again.

        //finally, we need let the force level useful...
        //the setting is, at enabled level 200, the damage will double.
        if( damage > 0 )
        {
                damage += (damage*(int)attacker->query_skill("force"))/200;
        }
        else if ( damage < 0 )
        {
                damage += (damage*(int)target->query_skill("force"))/200;
        }
	
	
        return damage;
}

/*
weiqi 981206
attacking-cast...called from spells function.
modified for perform...
a typical call would be:

        COMBAT_D->attacking_perform(
                me, 
                        //attacker 
                target, 
                        //target
		skill_level, 
			//level of skill used
                success_adj, 
                        //success adjustment
                damage_adj, 
                        //damage adjustment
                "both", 
                        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
                HIC "$Nº∏∏ˆ÷∏Õ∑—∏ÀŸƒÌ∂Ø£¨Õª»ª’≈◊Ï“ª≈Á£°∫Ï≥»ª∆»˝µ¿ª—Ê∫Ù£°µÿ“ª…˘œÚ$næÌ»•£°\n" NOR,
                        //initial message
                HIC "Ω·π˚$n±ª…’µ√ΩπÕ∑¿√∂Ó£°\n" NOR, 
                        //success message
                HIC "µ´ «$n«·«·“ªÃ¯æÕ∂„¡Àø™¿¥°£\n" NOR, 
                        //fail message
                HIC "µ´ «ª—Ê±ª$n“‘∑®¡¶“ª±∆£¨∑¥œÚ$NªÿæÌ∂¯»•£°\n" NOR, 
                        //backfire initial message
                HIC "Ω·π˚Ã´““’Êª∑¥ …£¨$n±ª…’µ√ΩπÕ∑¿√∂Ó£°\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );
*/
void attacking_perform(
        object attacker, 
        object target, 
	int skill_level,//the level of skill used to attack.
        int success_adj, 
        int damage_adj, //default value is 100 for this 2 parameters.
        string damage_type, //must be "shen"/"sen", "qi"/"kee" or "both"(default)
        string msg_init, 
        string msg_success, 
        string msg_fail, 
        string msg_backfire_init,
        string msg_backfire_success)
{
        int damage;

        //first, show the initial message...
        message_vision( msg_init, attacker, target );

        //calculate if the casting can happen...
        if( attacking_perform_success(attacker, target, skill_level, success_adj) == 0 )
        {
                message_vision( msg_fail, attacker, target );
                //let the target kill attacker.
                target->kill_ob(attacker);
                return;
        }

        damage = attacking_perform_damage(attacker, target, damage_adj);

        if( damage > 0 ) //attacker hit target
                SPELL_D->apply_damage(attacker, target, damage, damage_type, msg_success);

        else if( damage < 0 ) //backfire
        {
                message_vision(msg_backfire_init, attacker, target);
                SPELL_D->apply_damage(target, attacker, -damage, damage_type, msg_backfire_success);
        }

        else //damge=0
		message_vision(HIB "Ω·π˚’˝∫√±ª$N“‘ƒ⁄¡¶±∆◊°£¨À≠“≤√ª”–≥‘ø˜°£\n" NOR, target);

        //let the target kill attacker.
        target->kill_ob(attacker);

        return;
}


