// yuzu.c
// cgm 28/12/1999
// idea 7/4/2000

#include <ansi.h>

inherit NPC;

string *msg_d = ({
                      "他妈的","你妈的","傻B","我操","操你","和你妈睡",
                      "操！","操!","fuck","FUCK","Fuck","婊子",
                      "你奶奶的","和你妈做爱","她妈的","你爷爷的",
                      "放你妈的屁","tmd","TMD","tmmd","TMMD","操你妈","日死你","干你娘",
                      "操你姐","狗屁wiz","狗wiz","破wiz","日死你",
                      "干你妈","干你的","ｆｕｃｋ","ＦＵＣＫ","F u c k"
                      ,"f u c k","日你妈","狗逼","狗B","王八","小B"
                      ,"tnnd","他奶奶的"
                      });


void create()
{
        set_name("文明神使", ({"shenshi","shenshi"}));
        set("title", HIY"「西行战记精神文明标兵」"NOR);
        set("gender", "男性" );
        set("age", 30);
        set("per", 5);
        set("long", HIR"一个神秘的文明神使，你碰上他准是你干了什么坏事。\n"NOR);
        set("combat_exp", 10000000);
        set("attitude", "peaceful");
        set("dex", 50);
        set("str", 50);
   
        set_skill("literate", 800);
        set("max_sen", 1000);
        set("max_kee", 500);
        set("max_force", 1000);
        
        set("no_clean_up",1);
        setup();

        carry_object("/obj/loginload/skirt.c")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();

        if( !clonep() ) CHANNEL_D->register_relay_channel("rumor");
        if( !clonep() ) CHANNEL_D->register_relay_channel("chat");
        if( !clonep() ) CHANNEL_D->register_relay_channel("muisc");
        if( !clonep() ) CHANNEL_D->register_relay_channel("xxzj");
        if( !clonep() ) CHANNEL_D->register_relay_channel("xyy");
        if( !clonep() ) CHANNEL_D->register_relay_channel("say");
        
}

void relay_channel(object criminal, string channel, string msg)
{

        int i;
        string criname,result;
        int howlong;
        if( !userp(criminal) ) return;

        for(i=0; i<sizeof(msg_d); i++)
        {
            if( strsrch(msg, msg_d[i]) >= 0)
                   {
                    message_vision(CYN"文明神使乎然出现，扔出索套，一下就套住$N的脖子。\n$N伸长舌头、翻着白眼地被拖走了。\n"NOR, criminal);
                    
                    criname = criminal->query("name") + "("+criminal->query("id")+")";
                    howlong=20;
                    
                    result = sprintf("%s在%s频道说脏话(%s)被设囚禁 %d 分\n",
                    criname,channel,msg,howlong);
                    
                    criminal->set("qiushi/howlong",howlong);
                    criminal->set("qiushi/temp",result);
                    criminal->move("/d/wiz/qiushi");
                    
                    
                    message("channel:rumor",HIM"【谣言】某人：据说"+criname+"在公众频道使用粗言烂语，被文明神使抓走了。\n"NOR, users());
                    return;
                    }
        }
}
