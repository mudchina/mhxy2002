inherit F_FOOD;
inherit ITEM;

string *names = ({
        "ÏÊËñ",
        "Ä¢¹½",
        "É½Ò©",
        "»Æ¾«",
        "Ê¯»¨²Ë",
        "»Æ»¨²Ë",
        "±â¶¹½Ç",
        "ôø¶¹½Ç",
        "Íõ¹Ï",
        "°×¹û",
        "ÂûÇà",
        "ÇÑ×Ó",
        "¶¬¹Ï",
        "ÓóÍ·",
        "ÂÜ²·",
        "ÁÖéÕ",
        "éÏé­",
        "Á«Èâ",
        "ÀóÖ¦",
        "ÁúÑÛ",
        "É½Àõ",
        "·çÁâ",
        "ÊÁ×Ó",
        "ºúÌÒ",
        "ÒøĞÓ",
        "½ğéÙ",
        "Ïã³È",
});

string *ids = ({
        "xian sun",
        "mo gu",
        "shan yao",
        "huang jing",
        "shihua cai",
        "huanghua cai",
        "bian doujiao",
        "jiang doujiao",
        "wang gua",
        "bai guo",
        "man qing",
        "qie zi",
        "dong gua",        
        "yu tou",
        "luo bo",
        "lin qin",
        "gan lan",
        "lian rou",
        "li zhi",
        "long yan",
        "shan li",
        "feng ling",
        "shi zi",
        "hu tao",
        "yin xing",
        "jin ju",
        "xiang cheng",        
});

void create()
{
  set_name("¹Ï¹ûÊß²Ë",({"guaguo shucai"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "¸ö");
 set("value", 100);
    set("food_remaining", 5);
    set("food_supply", 35);
    setup();
       }
}
void init()
{
  int i = random(sizeof(names));
  if( query("name") == "¹Ï¹ûÊß²Ë")
  set_name(names[i],({ids[i],"ggsc"}));
 ::init();
}
