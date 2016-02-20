inherit F_VENDOR_SALE;


void create()
{
//   reload("zhangshengshou");
        set_name("张圣手", ({"zhang shengshou", "zhang", "boss"}));
        set("title", "妙手回春");
        set("gender", "男性");
        set("age", 37);
        set("long",
"张圣手长年从事中药材的贩卖，医术也是了得。\n");
        set("kee", 300); 
        set("max_kee", 300);
        set("sen", 200);
        set("max_sen", 200);
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set("vendor_goods", ([
               "jiuzi"         : "/clone/herb/jiuzi",
                "baishu"        : "/clone/herb/baishu",
                "beimu"         : "/clone/herb/beimu",
                "bingpian"      : "/clone/herb/bingpian",
                "bohe"          : "/clone/herb/bohe",
                "caizi"         : "/clone/herb/caizi",
                "chaihu"        : "/clone/herb/chaihu",
                "chansu"        : "/clone/herb/chansu",
                "chenpi"        : "/clone/herb/chenpi",
                "chuanwu"       : "/clone/herb/chuanwu",
                "dahuang"       : "/clone/herb/dahuang",
                "danggui"       : "/clone/herb/dangui",
                "dingxiang"     : "/clone/herb/dingxiang",
                "duanxu"        : "/clone/herb/duanxu",
                "duhuo"         : "/clone/herb/duhuo",
                   "erhua"       : "/clone/herb/ercha",
                "fangfeng"      : "/clone/herb/fangfeng",
                "fuzi"          : "/clone/herb/fuzi",
                "gancao"        : "/clone/herb/gancao",
                "goujuzi"       : "/clone/herb/goujuzi",
                "gsliu"         : "/clone/herb/gsliu",
                "guiwei"        : "/clone/herb/guiwei",                
                "hafem"         : "/clone/herb/hafen",
              "honghua"       : "/clone/herb/honghua",
                "huajiao"       : "/clone/herb/huajiao",        
                "huangbo"       : "/clone/herb/huangbo",
                "huanglian"     : "/clone/herb/huanglian",
                "hugu"          : "/clone/herb/hugu",   
                "hupo"          : "/clone/herb/hupo",
                "jinying"       : "/clone/herb/jinying",
                "juhua"         : "/clone/herb/juhua",
                "lanhua"        : "/clone/herb/lanhua",
                "lianqiao"      : "/clone/herb/lianqiao",
                "lianzi"        : "/clone/herb/lianzi",
                "lurong"        : "/clone/herb/lurong",
                "moyao"         : "/clone/herb/moyao",
                "niuhuang"      : "/clone/herb/niuhuang",
                "niuxi"         : "/clone/herb/niuxi",
                "qianjinzi"     : "/clone/herb/qianjinzi",
                "ruxiang"       : "/clone/herb/ruxiang",
                "shancha"       : "/clone/herb/shancha",
                "shengdi"       : "/clone/herb/shengdi",
                "shenglg"       : "/clone/herb/shenglg",
                "shexiang"      : "/clone/herb/shexiang",
                "sumu"          : "/clone/herb/sumu",
                "chuanshanjia"   : "/clone/herb/shanjia",
               "qingdai"       : "/clone/herb/qingdai",
                 "taoxian"       : "/clone/herb/taoxian",
                "tiandong"      : "/clone/herb/tiandong",
                "tianqi"        : "/clone/herb/tianqi",
                "tugou"         : "/clone/herb/tugou",
                "water"         : "/clone/herb/water",
                "wulingzhi"     : "/clone/herb/wulingzhi",   
                "xiefen"        : "/clone/herb/xiefen",
                "xingren"       : "/clone/herb/xingren",
                "xiongdan"      : "/clone/herb/xiongdan",
                "xuejie"        : "/clone/herb/xuejie",
                "yanghuo"       : "/clone/herb/yanghuo",
                "yjhua"         : "/clone/herb/yjhua",
                "yuanzhi"       : "/clone/herb/yuanzhi",
                "zhusha"        : "/clone/herb/zhusha",
                "zihua"         : "/clone/herb/zihua",
                "zzfen"         : "/clone/herb/zzfen",
              ]) );

        set_skill("literate", 70);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
      setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        add_money("gold", 1);
}



void init()
{
        object ob;

        ::init();
        add_action("do_vendor_list", "list");

}


