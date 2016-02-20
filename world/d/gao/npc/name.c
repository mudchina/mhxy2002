inherit NPC;
#include <ansi.h>
int query_gold_of_user(object me);
        string *banned_name = ({
        "你","我", "他", "她", "它", "妈妈","爸爸",
        "雪雪","老六","剑先生","老婆","爷爷","奶奶","老公",
        "姐姐","哥哥","阿紫","玩具熊","判官","六月","淘气",
        "巫师","无厘头","怜香惜玉","乌龟","王八","你妈","狗日",
        });
void create()
{
       set_name("书生", ({ "shu sheng","shu","sheng" }) );
       set("gender", "男性" );
       set("age", 59);
       set("title", WHT"高老庄门客"NOR);
       set("str", 21);
       set("max_kee", 1000);
       set("kee", 1000);
       set("give_tuzi",5);
       set("long",
              "一个在高老庄暂住的书生,以为别人「改名」字为生。\n");
       set("combat_exp", 10000);
       set("attitude", "friendly");
       set("inquiry", ([
              "改名" : "要改名就找我,你可以 change <中文名>\n",
               ]) );
       setup();
       carry_object("/obj/cloth")->wear();
}
void init()
{
       add_action("do_gai","change");
}
int do_gai(string name)
{
        object me;
        int i;
        me = this_player();

    if( !name || sscanf(name, "%s", name)!=1 )
        return notify_fail("指令格式：gai <中文名>\n");
    

        message_vision(CYN"$N点头哈腰地对$n说道:我要改名为 "BOLD+name+NOR+CYN+" ...\n\n"NOR,me,this_object());

    i = strlen(name);
    
    if( (strlen(name) < 2) || (strlen(name) > 16 ) )
        {
        command("say 对不起，你的中文名字必须是 1 到 8 个中文字。\n");
        return 1;
    }
    while(i--)
        {
        if( name[i]<=' ' )
                {
            command("say 对不起，你的中文名字不能用控制字元。\n");
            return 1;
        }
        if( i%2==0 && !is_chinese(name[i..<0]) )
                {
            command("say 对不起，请用「中文」取名字。\n");
            return 1;
        }
    }
    if( member_array(name, banned_name)!=-1 )
        {
        command("say 对不起，这种名字会造成其他人的困扰。\n");
        return 1;
    }
         if(me->query("class")=="bonze"||me->query("class")=="alchemist")
          {
             command("shake");
             command("say 小生不能为你改名!");
            return 1;
           }
    if ( !query_gold_of_user( me ) ) return 1;

        command("nod");
        command("say 好了,你的名子已经改完了!");
        me->add("marks/gainame", 1);
        me->set("name", name);
                return 1;
}
int query_gold_of_user(object me)
{
        object gold;
        int gold_number;
        int value;
        value = 300*(me->query("marks/gainame")+1);
        gold_number=0;
        gold=present("gold_money",me);
        if (gold) {
                gold_number=gold->query_amount();
                if ( gold_number>=value ){
                     gold->set_amount(gold_number-value);
                return 1;
        }else{
            command("shake");
            message_vision(CYN"$N说道: 改名需要"+chinese_number(value)+"两 "HIY"黄金 "NOR+CYN"的润笔费...\n"NOR,this_object());
            return 0;
             }
        }
            command("shake");
            message_vision(CYN"$N说道: 改名需要"+chinese_number(value)+"两 "HIY"黄金 "NOR+CYN"的润笔费...\n"NOR,this_object());
            return 0;
}

