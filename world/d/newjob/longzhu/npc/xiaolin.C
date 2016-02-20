// 小林 by Calvin 

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name(HIW"小林"NOR, ({"xiao lin","xiao","lin"}));
        set("title", HIG"心叶童子"NOR);
        set("gender", "男性" );
        set("age", 16);
        set("per", 33);
        set("str", 30);
set("long","一位清风阳光型的小伙子。\n");

        set("attitude", "aggressive");
       set("class", "sanjie");
       set("shen_type", 1);
       set("max_kee", 100000);
       set("max_gin", 100000);
       set("max_sen", 100000);
       set("force", 6000);
       set("max_force", 6000);
       set("force_factor", 1000);
       set("max_mana", 6000);
       set("mana", 6000);
       set("mana_factor", 1000);
       set("combat_exp", 100000000);
       set("daoxing", 100000000);

        set_skill("dodge", 1000);
        set_skill("parry", 1000);
        set_skill("spells", 1000);  
        set_skill("tianmogong", 1000);
        set_skill("literate", 1000);
        set_skill("blade", 1000);  
        set_skill("zileidao", 1000);
        set_skill("zhaoyangbu", 1000);
        set_skill("force", 1000);   
        set_skill("huntianforce", 1000);

        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("blade", "zileidao");
        map_skill("parry", "zileidao");
        map_skill("dodge", "zhaoyangbu");
        set("chat_msg_combat", ({
        (: perform_action, "blade", "tulong" :),
        }) );

        setup();
            carry_object("/d/longzhu/armor/xinjia")->wear();
            carry_object("/d/longzhu/weapon/xindao")->wield();
}

void die()
{
 int i;
 object me,*inv;
 if(objectp(me=query_temp("last_damage_from") ))
        {
            inv = all_inventory(this_object());
            for(i=0; i<sizeof(inv); i++)
            {
              if (inv[i]->query("id")=="6" || inv[i]->query("id")=="liang longzhu")
                {
                   inv[i]->move(me);

                   message_vision("$N对你$n说道:你真厉害,你应该得到这颗龙珠。\n",this_object(),me);
            message("channel:rumor",HIG+"【"HIW"龙珠传说"HIG"】"HIC"孙悟空"HIW"：据说"+me->query("name")+"在密林附近得到了"HIC"亮龙珠"HIW"。\n"+NOR,users());
         }
        }
  }
 ::die();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 10);
        set("inquiry", ([
           "name" : "我是心叶童子 小林 。\n",
            "here" : "这是心叶树下。\n", 
            "龙珠" : "传说中的龙珠分布在七个不同的地方。\n", 
         ]) );

        set("chat_msg", ({
            "小林说道：龙珠分别藏于世界各地,收集齐了可不容易啊!\n",       
                "小林死钉钉的看着你的一举一动。\n",
                "小林说道:我这烂地方可能你是搜不到什么宝贝的。\n",
                "看了看你问道:请问你知道龙珠吗?\n",
        }) );
}
