// 特兰克斯 by Calvin

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string suanming(object me);
void create()
{
        set_name(HIW"特兰克斯"NOR, ({"telan kesi", "tlks", "telan", "kesi"}));
        set("title", HIG"龙珠传人"NOR);
        set("gender", "男性" );
        set("age", 10);
        set("per", 30);
        set("str", 30);
set("long","赛亚人贝吉塔及地球人布玛的儿子。\n");

        set("class", "yaomo");
        set("combat_exp", 100000000);
        set("daoxing", 100000000);

//        set("rank_info/respect", "宝宝");
        set("attitude", "peaceful");
        set_skill("unarmed", 1000);
        set_skill("cuixin-zhang", 1000);
        set_skill("dodge", 1000);
        set_skill("xiaoyaoyou", 1000);
        set_skill("parry", 1000);
        set_skill("sword", 1000);
        set_skill("bainiao-jian", 1000);
        set_skill("blade", 1000);
        set_skill("bingpo-blade", 1000);
        set_skill("throwing", 1000);
        set_skill("force", 1000);   
        set_skill("ningxie-force", 1000);
        set_skill("literate", 1000);
        set_skill("spells", 1000);
        set_skill("dengxian-dafa", 300);

        map_skill("spells", "dengxian-dafa");
        map_skill("force", "ningxie-force");
        map_skill("unarmed", "cuixin-zhang");
        map_skill("sword", "bainiao-jian");
        map_skill("blade", "bingpo-blade");
        map_skill("dodge", "xiaoyaoyou");
        set("max_kee", 10000);
        set("max_sen", 10000);
        set("force", 6000);
        set("max_force", 6000);
        set("mana", 6000);
        set("max_mana", 6000);  
        set("force_factor", 1000);
        set("mana_factor", 1000);

        set_temp("apply/damage", 50);
        set_temp("spply/armor", 50);
        set_temp("apply/dodge", 50);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "juanbi":),
                (: cast_spell, "tuntian" :),
                (: perform_action, "sword", "chaofeng":),
            (: perform_action, "sword", "feijian":),
       }) );

            setup();
        carry_object("/d/longzhu/weapon/duanjian")->wield();
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
                if (inv[i]->query("id")=="4" || inv[i]->query("id")=="fen longzhu")
                {
                   inv[i]->move(me);

                   message_vision("$N掉下一枚纯蓝色的珠子，$n赶忙一把抓到怀里。\n",this_object(),me);
            message("channel:rumor",HIG+"【"HIW"龙珠传说"HIG"】"HIC"孙悟空"HIW"："+me->query("name")+"在长安城西附近得到了"HIB"蓝龙珠"HIW"。\n"+NOR,users());
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
           "name" : "我是布玛的儿子,怎么? 想欺负我吗?。\n",
            "here" : "这个问题最好找我妈妈告诉你。\n", 
            "龙珠" : "传说中的龙珠一共有七颗,我这只有一颗蓝色的龙珠,如果你需要的话,就去找颗其他的龙珠和我交换。\n", 
         ]) );

        set("chat_msg", ({
            "特兰克斯说道：怎么就是没人陪我玩啊?\n",       
                "特兰克斯上上下下打量了你几眼。\n",
                "看了看你,样子极为恼怒。\n",
                "看了看你问道:请问你知道龙珠吗?\n",
                (: random_move :)
        }) );
}


int accept_object(object me, object ob)
{
object zhu;
zhu=new("/d/longzhu/obj/4.c");
if((string)ob->query("id")=="fen longzhu" )
{
message_vision(HIR"你我有缘,我就把我们这里的宝贝给$N作为见面礼吧!\n"+HIC"说着特兰克思拿出一颗蓝龙珠给了$N!\n\n",me);
zhu->move(me);
return 1;
}
else
{
command("say 不敢当不敢当．．．您太客气了。");
 return 1;
}
}