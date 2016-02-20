//namd.c
#include <ansi.h>

mapping surname=([
"’‘"    :  "zhao",         "«Æ"    :  "qian",         
"ÀÔ"    :  "sun",          "¿Ó"    :  "li",           
"÷‹"    :  "zhou",         "Œ‚"    :  "wu",           
"÷£"    :  "zhen",         "Õı"    :  "wang",         
"∑Î"    :  "feng",         "≥¬"    :  "chen",         
"Ò“"    :  "zhu",          "Œ¿"    :  "wei",          
"ΩØ"    :  "jiang",        "…Ú"    :  "shen",         
"∫´"    :  "han",          "—Ó"    :  "yang",         
"÷Ï"    :  "zhu",          "«ÿ"    :  "qing",         
"”»"    :  "you",          "–Ì"    :  "xu",           
"∫Œ"    :  "he",           "¬¿"    :  "lu",           
" ©"    :  "shi",          "’≈"    :  "zhang",        
"ø◊"    :  "kong",         "≤‹"    :  "cao",          
"—œ"    :  "yan",          "ª™"    :  "hua",          
"Ω"    :  "jin",          "Œ∫"    :  "wei",          
"Ã’"    :  "tao",          "Ω™"    :  "jiang",        
"∆›"    :  "qie",          "–ª"    :  "xie",          
"◊ﬁ"    :  "zhou",         "”˜"    :  "yu",           
"∞ÿ"    :  "bo",           "ÀÆ"    :  "shui",         
"Òº"    :  "dou",          "’¬"    :  "zhang",        
"‘∆"    :  "yun",          "À’"    :  "su",           
"≈À"    :  "pan",          "∏"    :  "ge",           
"ﬁ…"    :  "xi",           "∑∂"    :  "fan",          
"≈Ì"    :  "peng",         "¿…"    :  "lang",         
"¬≥"    :  "lu",           "Œ§"    :  "wei",          
"≤˝"    :  "chang",        "¬Ì"    :  "ma",           
"√Á"    :  "miao",         "∑Ô"    :  "feng",         
"ª®"    :  "hua",          "∑Ω"    :  "fang",         
"…µ"    :  "sha",          "»Œ"    :  "ren",          
"‘¨"    :  "yuan",         "¡¯"    :  "liu",          
"µÀ"    :  "deng",         "±´"    :  "bao",          
" ∑"    :  "shi",          "Ã∆"    :  "tang",         
"∑—"    :  "fei",          "¡Æ"    :  "lian",         
"·Ø"    :  "chen",         "—¶"    :  "xue",          
"¿◊"    :  "lei",          "∫ÿ"    :  "he",           
"ƒﬂ"    :  "ni",           "Ã¿"    :  "tang",         
"ÃŸ"    :  "teng",         "“Û"    :  "yin",          
"¬ﬁ"    :  "luo",          "ª™"    :  "hua",          
"∫¬"    :  "hao",          "⁄˘"    :  "wu",           
"∞≤"    :  "an",           "≥£"    :  "chang",        
"¿÷"    :  "le",           "¥Ù"    :  "dai",          
" ±"    :  "shi",          "∏∂"    :  "fu",           
"∆§"    :  "pi",           "±Â"    :  "bian",         
"∆Î"    :  "qi",           "øµ"    :  "kang",         
"ŒÈ"    :  "wu",           "”‡"    :  "yu",           
"‘™"    :  "yuan",         "≤∑"    :  "po",           
"πÀ"    :  "gu",           "”Ø"    :  "ying",         
"∆Ω"    :  "ping",         "ª∆"    :  "huang",        
"∫Õ"    :  "he",           "ƒ¬"    :  "mu",           
"–§"    :  "xiao",         "“¸"    :  "yin",          
"“¶"    :  "yao",          "…€"    :  "shao",         
"’ø"    :  "zhan",         "ÕÙ"    :  "wang",         
"∆Ó"    :  "qi",           "√´"    :  "mao",          
"”Ì"    :  "yu",           "µ“"    :  "di",           
"√◊"    :  "mi",           "±¥"    :  "bei",          
"√˜"    :  "ming",         "≤ÿ"    :  "zang",         
"º∆"    :  "ji",           "∑¸"    :  "fu",           
"≥…"    :  "cheng",        "¥˜"    :  "dai",          
"Ã∏"    :  "tan",          "ÀŒ"    :  "song",         
"√©"    :  "mao",          "≈”"    :  "pang",         
"–‹"    :  "xiong",        "ºÕ"    :  "ji",           
" Ê"    :  "su",           "«¸"    :  "qu",           
"œÓ"    :  "xiang",        "◊£"    :  "zhu",          
"∂≠"    :  "dong",         "¡∫"    :  "liang",        
"∑Æ"    :  "fan",          "∫˙"    :  "hu",           
"¡Ë"    :  "ling",         "ªÙ"    :  "ho",           
"”›"    :  "yu",           "ÕÚ"    :  "wan",          
"÷ß"    :  "zhi",          "ø¬"    :  "ke",           
"Í√"    :  "jiu",          "π‹"    :  "guan",         
"¬¨"    :  "lu",           "”¢"    :  "ying",         
"≥"    :  "qiu",          "∫Ú"    :  "hou",          
"‘¿"    :  "yue",          "Àß"    :  "suai",         
"Àæ¬Ì"  :  "sima",         "…œπŸ"  :  "shangguan",    
"≈∑—Ù"  :  "ouyang",       "œƒ∫Ú"  :  "xiahou",       
"÷Ó∏"  :  "zhuge",        "Œ≈»À"  :  "wenren",       
"∂´∑Ω"  :  "dongfang",     "∫’¡¨"  :  "helian",       
"ª ∏¶"  :  "huangpu",      "Œæ≥Ÿ"  :  "weichi",       
"π´—Ú"  :  "gongyang",     "Â£Ã®"  :  "zhantai",      
"π´÷Œ"  :  "gongye",       "◊⁄’˛"  :  "zongzheng",    
"Âß—Ù"  :  "puyang",       "¥æ”⁄"  :  "chunyu",       
"µ•”⁄"  :  "shanyu",       "Ã´ Â"  :  "taishu",       
"…ÍÕ¿"  :  "shentu",       "π´ÀÔ"  :  "gongshun",     
"÷ŸÀÔ"  :  "zhongshun",    "‘Ø–˘"  :  "xuanyuan",     
"¡Ó∫¸"  :  "linghu",       "÷”¿Î"  :  "zhongli",      
"”ÓŒƒ"  :  "yuwen",        "≥§ÀÔ"  :  "changshun",    
"ƒª»›"  :  "murong",       "ÀæÕΩ"  :  "situ",         
" ¶ø’"  :  "shikong",      "Úßø◊"  :  "zhuankong",    
"∂Àƒæ"  :  "duanmu",       "Œ◊¬Ì"  :  "wuma",         
"π´Œ˜"  :  "gongxi",       "∆·µÒ"  :  "qidiao",       
"¿÷’˝"  :  "lezheng",      "»¿Ê·"  :  "xiangsi",      
"π´¡º"  :  "gongliang",    "Õÿ÷∫"  :  "tuozhi",       
"º–π»"  :  "jiagu",        "‘◊∏∏"  :  "zaifu",        
"π»¡∫"  :  "guliang",      "≥˛Ω˙"  :  "chujing",      
"—÷∑®"  :  "yanfa",        "»Í€≥"  :  "ruye",         
"Õø«’"  :  "tuqin",        "∂Œ«ß"  :  "duanqian",     
"∞Ÿ¿Ô"  :  "baili",        "∂´π˘"  :  "dongguo",      
"ƒœπ˘"  :  "nanguo",       "∫Ù—”"  :  "huyan",        
"πÈ∫£"  :  "guihai",       "—Ú…‡"  :  "yangshe",      
"Œ¢…˙"  :  "weisheng",     "¡∫«"  :  "liangqiu",     
"◊Û«"  :  "zuoqiu",       "∂´√≈"  :  "dongmen",      
"Œ˜√≈"  :  "ximen",        "∞€…Õ"  :  "baishang",     
"ƒœπŸ"  :  "nangong",      "Á√"    :  "gou",          
"ø∫"    :  "kang",         "øˆ"    :  "kuang",        
"∫Û"    :  "hou",          "”–"    :  "you",          
"«Ÿ"    :  "qing",         "…Ã"    :  "shang",        
"ƒ≤"    :  "mo",           "Ÿ‹"    :  "she",          
"∂˙"    :  "er",           "ƒ´"    :  "mo",           
"π˛"    :  "ha",           "⁄€"    :  "qiao",         
"ƒÍ"    :  "nian",         "∞Æ"    :  "ai",           
"—Ù"    :  "yang",         "Ÿ°"    :  "dong",         
"µ⁄"    :  "di",           "ŒÂ"    :  "wu",           
"—‘"    :  "yan",          "∏£"    :  "fu",           
"ÿ·"    :  "kai",          "÷”"    :  "zong",         
"◊⁄"    :  "zong",         "¡÷"    :  "lin",          
" Ø"    :  "shi",
]);

mapping jp_surname=([
"…Ω±æ"  :  "shanben",      "πÍÃÔ"  :  "guitian",      
"◊À»˝"  :  "zisan",        "¥Ûµ∫"  :  "dadao",        
"À…œ¬"  :  "songxia",      "∫·ÃÔ"  :  "hengtian",     
"∂´÷•"  :  "dongzhi",      "∫Ú±æ"  :  "houben",       
"¥®“∞"  :  "chuangye",     "…Ωø⁄"  :  "shankou",      
"¡Âƒæ"  :  "lingmu",       "∏⁄≤÷"  :  "gangcang",     
"–°µ∫"  :  "xiaodao",      "æÆ…œ"  :  "jinshang",     
"∞≤ƒŒ"  :  "annai",        "«≥ÃÔ"  :  "qiantian",     
"◊ÙÃŸ"  :  "zuoteng",      "π„ƒ©"  :  "guangmu",      
"¥Û÷Ò"  :  "dazhu",        "¥Û¥Â"  :  "dachun",       
"≤Æ◊Ù"  :  "bozuo",        "∏ª∏‘"  :  "fugang",       
"∂´œÁ"  :  "dongxiang",
]);

mapping middle_name=([
"÷“" : "zhong",		"–¢" : "xiao",
"¿Ò" : "li",		"“Â" : "yi",
"÷«" : "zhi",		"”¬" : "yong",
"» " : "ren",		"øÔ" : "kuang",
"œ‹" : "xian",		"¡Ó" : "ling",
"∏£" : "fu",		"¬ª" : "lu",
"¥Û" : "da",		"–°" : "xiao",
"œ˛" : "xiao",		"∏ﬂ" : "gao",
"ø…" : "ke",		"∞¢" : "a",
"Ω" : "jin",		" ¿" : "shi",
"øÀ" : "ke",		" Â" : "shu",
"÷Æ" : "zhi",		"π´" : "gong",
"∑Ú" : "fu",		" ±" : "shi",
"»Ù" : "ruo",		"«Ï" : "qing",
"Œƒ" : "wen",		"Œ‰" : "wu",
"∂‡" : "duo",		"≤≈" : "cai",
"≥§" : "zhang",		"◊”" : "zi",
"”¿" : "yong",		"”—" : "you",
"◊‘" : "zi",		"»À" : "ren",
"Œ™" : "weo",		"Ã˙" : "tie",
]);

mapping male_name=([
"∞‘" : "ba",		"∞◊" : "bai",
"∞‡" : "ban",		"±Û" : "bin",
"±ˆ" : "bin",		"≤˝" : "chang",
"≥¨" : "chao",		"≥œ" : "cheng",
"¥®" : "chuan",		"∂¶" : "ding",
"∂®" : "ding",		"∑®" : "fa",
"∑…" : "fei",		"∑Á" : "feng",
"∑Ê" : "feng",		"∏÷" : "gan",
"Ó∏" : "gan",		"π·" : "gui",
"π‚" : "guang",		"∫£" : "hai",
"ª¢" : "hu",		"ª™" : "hua",
"∫∆" : "hao",		"∫Í" : "hong",
"º√" : "ji",		"º·" : "jian",
"Ω°" : "jian",		"Ω£" : "jian",
"Ω≠" : "jiang",		"Ω¯" : "jin",
"Ω‹" : "jie",		"ø°" : "jun",
"øµ" : "kan",		"¡º" : "liang",
"˜Î" : "qi",		"√Ò" : "min",
"√˜" : "ming",		"√˘" : "ming",
"ƒ˛" : "ning",		"≈‡" : "pei",
"∆Ù" : "qi",		"«ø" : "qiang",
"»Ÿ" : "rong",		"…Ω" : "shan",
"Ã©" : "tai",		"ÃŒ" : "tao",
"Õ¶" : "ting",		"Œ∞" : "wei",
"Œı" : "xi",		"œÈ" : "xiang",
"–€" : "xiong",		"–Ò" : "xu",
"∂∑" : "dou",		"“„" : "yi",
"Ë§" : "yu",		"”" : "yu",
"”Ó" : "yu",		"‘¿" : "yue",
"÷€" : "zhou",		
]);
			
mapping female_name=([
"∞Æ" : "ai",		"¥∫" : "chun",
"µ§" : "dan",		"∑º" : "fang",
"∑“" : "fen",		"∑Ô" : "feng",
"π√" : "gu",		"∫Ï" : "hong",
"∫Á" : "hong",		"Ωø" : "jiao",
"æÍ" : "juan",		"æ’" : "ju",
"¿º" : "lan",		"·∞" : "lan",
"¿ˆ" : "li",		"¿Ú" : "li",
"¡´" : "lian",		"¡·" : "ling",
"¡’" : "lin",		"ƒ»" : "na",
"«Ÿ" : "qin",		"«€" : "qin",
"Ÿª" : "qian",		"∆º" : "ping",
"Ê√" : "ding",		"œº" : "xia",
"œ„" : "xiang",		"—ﬁ" : "yan",
"—‡" : "yan",		"”¢" : "ying",
"Á¯" : "ying",		"”Ò" : "yu",
"’‰" : "zhen",		"÷È" : "zhu",
]);
	
mapping jp_name=([
"Ã´¿…"   : "tailang",		"¥Œ¿…"   : "cilang",
"»˝¿…"   : "sanlang",		"Àƒ¿…"   : "silang",
"ŒÂ¿…"   : "wulang",		" Æ“ª¿…" : "shiyilang",
" ÆÀƒ¿…" : "shisilang",		"∂˛ Æ¡˘" : "ershiliu",
"ø° ˜"   : "junshu",		"ƒ˛¥Œ"   : "ningci",
"”¢ª˙"   : "yingji",		"“±◊÷"   : "zhizi",
"ø°–€"   : "junxiong",		"ƒ¡∑Ú"   : "mufu",
"π‚∑Ú"   : "guangfu",		"æ¥“ª"   : "jingyi",
"”¢ ¿"   : "yingshi",		" ˛ Ø"   : "shushi",
"”Âº™"   : "yuji",		"“ª“∂"   : "yiye",
"◊”πÊ"   : "zigui",		"µæ‘Ï"   : "daozhao",
"“¡≥Â"   : "yichong",		"À…‘∞"   : "songyuan",
"…ÓÀÆ"   : "shenshui",		"¥Ûπ€"   : "daguan",
"∑·π˙"   : "fengguo",		"–¢∫Õ"   : "xiaohe",
"√Ø"     : "mao",		"¥®"     : "chuan",
"Œ¿"     : "wei",		"µ∫ Ÿ"   : "daoshou",
"π‚‘∆"   : "guangyun",		"∞≤÷Œ"   : "anzhi",
"…Ω¿÷"   : "shanle",		"√Œ∂˛"   : "menger",
]);

mapping color_list = ([
"≥‡":	"chi",		"∫Ï":	"hong",
"ª∆":	"huang",	"¬Ã":	"lu",
"«‡":	"qing",		"¿∂":	"lan",
"◊œ":	"zi",		"Œ⁄":	"wu",
"∫⁄":	"hei",		"“¯":	"yin",
"∞◊":	"bai",		"Ω":	"jin",
"ª“":	"hui",		"ƒæ":	"mu",
"ÀÆ":	"shui",		"ª":	"huo",
"Õ¡":	"tu",		"Œ∏":	"wei",
"πÌ":	"gui",		"‘¬":	"yue",
"÷Ï":	"zhu",		"»’":	"ri",
"∂∑":	"dou",		"ı˛":	"zui",
"ø¸":	"kui",		"≤Œ":	"shen"
]);

mapping animal_list =([
"Õ√":	"tu",		"∫¸":	"hu",
"¡˙":	"long",		"Ú‘":	"jiao",
"ª¢":	"hu",		"±™":	"bao",
"¬Ì":	"ma",		"¬π":	"lu",
"—Ú":	"yang",		"…ﬂ":	"she",
"‚Ø":	"zhang",	"º¶":	"ji",
"π∑":	"gou",		"¿«":	"lang",
"‘≥":	"yuan",		"∫Ô":	"hou",
" Û":	"shu",		"≈£":	"niu",
"÷Ì":	"zhu",		"Ú":	"fu",
"≤Ú":	"chai",		"Ã°":	"lai",
"·Ù":	"fei",		"Ú˛":	"mang",
"–‹":	"xiong",	"œÛ":	"xiang",
"ıı":	"diao",		"¿Í":	"li",
"‚µ":	"huan",		"Óº":	"pi",
"—‡":	"yan",		"Úæ":	"yin",
"ÔÙ":	"zhi",		"·Û":	"pao",
"‚•":	"ni",		"È·":	"ao",
"¡Á":	"ling",		"˜‰":	"ji",
"–…":	"xing",
]);

mapping animal_names = ([
"∫¸¿Í":"huli",		"∫⁄–‹":"heixiong",
"π∑–‹":"gouxiong",	"∞◊–‹":"baixiong",
"–´◊”":"xiezi",		"Û∏Ú‹":"chanchu",
"Ú⁄Úº":"wugong",	"Õ¡±Ó":"tubie",
"∑…ª»":"feihuang",	"ª»≥Ê":"huangchong",
"¥Û«‡≥Ê":"daqingchong",	"≥Ù≥Ê":"chouchong",
"Ã¯‘È":"tiaozao",	" ≠◊”":"shizi",
"¿œª¢":"laohu",		" ®◊”":"shizi",
"ª∆ ®":"huangshi",	"∫⁄ ®":"heishi",
"∞◊ ®":"baishi",	"“∞Õ√":"yetu",
"ª®±™":"huabao",	"…Ω±™":"shanbao",
"≤›±™":"caobao",	"…Ω—Ú":"shanyang",
"¬Ì∫Ô":"mahou",		"‚®∫Ô":"mihou",
"‘≥∫Ô":"yuanhou",	"ª“¿«":"huilang",
"“∞÷Ì":"yezhu",		"÷©÷Î":"zhizhu",
"¬Ì¬π":"malu",		"∞◊¬π":"bailu",
"ª“¬π":"huilu",		"∫⁄¬π":"heilu",
"…Ωº¶":"shanji",	"“∞º¶":"yeji",
"ÔÙº¶":"zhiji",		"¥Ã‚¨":"ciwei",
"ª®∫¸¿Í":"huahuli",	"∞◊∫¸¿Í":"baihuli",
"ª“∫¸¿Í":"huihuli",	"–…–…":"xingxing",
"·Ù·Ù":"feifei",	"∞◊¬Ì":"baima",
"∫Ï¬Ì":"hongma",	"∫⁄¬Ì":"heima",
"∞◊√®":"baimao",	"ª®√®":"huamao",
"∫⁄√®":"heimao",	"“∞√®":"yemao",
"“∞¬Ì":"yema",		"“∞¬ø":"yelu",
"∞◊Õ√":"baitu",		"ª“Õ√":"huitu",
"ÀÆ≈£":"shuiniu",	"ÍÛ≈£":"maoniu",
"“∞≈£":"yeniu",		"∞◊ Û":"baishu",
"ª“ Û":"huishu",	"∫⁄¬Ï“œ":"heimayi",
"¬Ï“œ":"mayi",		"∞◊“œ":"baiyi",
"…Ω¿œ Û":"shanlaoshu",	"ª®…ﬂ":"huashe",
"«‡…ﬂ":"qingshe",	"∞◊…ﬂ":"baishe",
"ª“∞ﬂ…ﬂ":"huibanshe",	"æﬁÚ˛":"jumang",
"ÀÆ…ﬂ":"shuishe",	"∫£¿Í":"haili",
"∫”¿Í":"heli",
]);

mapping middle_list =([
"Ω≈"	:	"jiao",		"Õ∑"	:	"tou",
"Œ≤"	:	"wei",		"◊Ï"	:	"zui",
"∂˙"	:	"er",		"—€"	:	"yan",
"±«"	:	"bi",		"—¿"	:	"ya",
"…‡"	:	"she",		"…Ì"	:	"shen",
"◊¶"	:	"zhua",
]);
string *title_list = ({ 
	"‘¬π¨∆˙ÕΩ",	"Ω´æ¸∏Æ≈—Ω´", 
	"¥Û—©…Ωƒı—˝",	"Œﬁµ◊∂¥ƒı—˝",
	"∑Ω¥Á…Ω∆˙ÕΩ",	"ŒÂ◊Øπ€ƒıÕΩ", 
	"µÿ∏Æ‘©πÌ",	"¡˙π¨∆˙ÕΩ",
	"ÃÏπ¨≈—Ω´",	"∑Ω¥Á—˝µ¿",
	"Œﬁµ◊∂¥–°—˝",	"ŒÂ◊Øπ€∂ÒÕΩ",
	"∆’Õ”∂Ò…Æ",
});	

varargs mapping random_name(string type)
{
	mapping name;
	int a,b,c;
	string *surnames, *middle_names, *last_names;
	string temp_name, *temp_id;
	
	name=allocate_mapping(3);
	
	switch(type)
	{
		case "male" :
		surnames=keys(surname);
		middle_names=keys(middle_name);
		last_names=keys(male_name);
		a=random(sizeof(surnames));
		b=random(sizeof(middle_names));
		c=random(sizeof(last_names));
		if(random(100)>20)
		{
			temp_name=surnames[a]
				 + middle_names[b]
				 + last_names[c];
			temp_id=({surname[surnames[a]]+" "
				   +middle_name[middle_names[b]]
				   +male_name[last_names[c]],
				   surname[surnames[a]]});
		}
		else {
			temp_name=surnames[a]
				 + last_names[c];
			temp_id=({surname[surnames[a]]+" "
				   +male_name[last_names[c]],
				   surname[surnames[a]]});
		}
		name=([
			"name" : temp_name,
			"id"   : temp_id,
			"title": YEL"≤∂øÏ"NOR,
		]);
		break;
		case "female" :
		surnames=keys(surname);
		middle_names=keys(middle_name);
		last_names=keys(female_name);
		a=random(sizeof(surnames));
		b=random(sizeof(middle_names));
		c=random(sizeof(last_names));
		if(random(100)>20)
		{
			temp_name=surnames[a]
				 + middle_names[b]
				 + last_names[c];
			temp_id=({surname[surnames[a]]+" "
				   +middle_name[middle_names[b]]
				   +female_name[last_names[c]],
				   surname[surnames[a]]});
		}
		else {
			temp_name=surnames[a]
				 + last_names[c];
			temp_id=({surname[surnames[a]]+" "
				   +female_name[last_names[c]],
				   surname[surnames[a]]});
		}
		name=([
			"name" : temp_name,
			"id"   : temp_id,
			"title": HIM"∏Ë≈Æ"NOR,
		]);
		break;
		case "japan" :
		surnames=keys(jp_surname);
		last_names=keys(jp_name);
		a=random(sizeof(surnames));
		b=random(sizeof(last_names));
		name=([
			"name" : surnames[a]
				 + last_names[b],
			"id"   : ({jp_surname[surnames[a]]+" "
				   +jp_name[last_names[b]],
				   jp_surname[surnames[a]]}),
			"title": WHT"»’±æŒ‰ ø"NOR,
		]);
		break;
                case "yaoguai":
		if(random(2))
		{
			surnames=keys(animal_list);
			middle_names=keys(middle_list);
			a=random(sizeof(surnames));
			b=random(sizeof(middle_names));
			c=random(sizeof(surnames));
			name=([
				"name" 	: surnames[a]+
					  middle_names[b]+
					  surnames[c],
				"id"	: ({animal_list[surnames[a]]+
					    middle_list[middle_names[b]]+" "+
					    animal_list[surnames[c]],
					    animal_list[surnames[c]]}),
                                "title"	:title_list[random(sizeof(title_list))],
			]);
		}
		else
		{
			if(random(2))
			{
				surnames=keys(color_list);
				middle_names=keys(animal_list);
				a=random(sizeof(surnames));
				b=random(sizeof(middle_names));
				c=random(2);
				temp_name=surnames[a]+
					  middle_names[b];
				temp_name+=c?"æ´":"π÷";
				if(c)
					temp_id=({color_list[surnames[a]]+
						  animal_list[middle_names[b]]+" "+
					  	"jing", "jing"});
				else
					temp_id=({color_list[surnames[a]]+
						  animal_list[middle_names[b]]+" "+
					  	"guai",	"guai"});
			}
			else
			{
				surnames=keys(animal_names);
				a=random(sizeof(surnames));
				b=random(2);
				temp_name=surnames[a];
				temp_name+=b?"æ´":"π÷";
				if(b)
					temp_id=({animal_names[surnames[a]]+" "+
						  "jing", "jing"});
				else
					temp_id=({animal_names[surnames[a]]+" "+
						  "guai", "guai"});
			}
			name=([
				"name" : temp_name,
				"id"   : temp_id,
				"title": "NONE",
			]);
		}
		break;
		default:
		name=([
			"name" : "≤‚ ‘",
			"id"   : ({"test"}),
		]);
		break;
	}
	return name;
}
