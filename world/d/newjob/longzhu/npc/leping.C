// 乐平 by Calvin

inherit NPC;
#include <ansi.h>

void create()
{
        set_name(HIW"乐平"NOR, ({"le ping","ping","le"}));
        set("title", HIG"多林寺巡使"NOR);
        set("long", "一位多林寺的小学徒。\n");

        set("gender", "男性");
        set("attitude", "peaceful");

        set("age", 19+random(1));
        set("combat_exp", 5000000+random(5000000));
        set("daoxing", 5000000+random(5000000));

        set("shen_type", 1);
        set("per", 25);
        set("max_kee",100000);
        set("max_gin", 100000);
        set("force", 1000);
        set("spells", 1000);
        set("force_factor", 10);
        set_skill("force", 100+random(100));
        set_skill("unarmed",500+random(500));
        set_skill("dodge",500+random(500));
        set_skill("parry", 500+random(500));

        setup();
        carry_object("/d/longzhu/armor/xingtian")->wear();
        carry_object("/d/longzhu/obj/5");
        setup();
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
                if (inv[i]->query("id")=="5" || inv[i]->query("id")=="huang longzhu")
                {
                   inv[i]->move(me);
                   message_vision("$N掉下一枚纯黄色的珠子，$n赶忙一把抓到怀里。\n",this_object(),me);
            message("channel:rumor",HIG+"【"HIW"龙珠传说"HIG"】"HIC"孙悟空"HIW"：据说"+me->query("name")+"在长安城附近得到了"HIY"黄龙珠"HIW"。\n"+NOR,users());
         }
        }
  }
 ::die();
}

int accept_fight(object me)
{
        command("say 好吧，砌搓技艺，点到为止,如果你赢了我就告诉你龙珠的事！\n");
        command("say 我只知道龙珠的事,其他我一概不知！\n");
        command("say 我告诉你这个秘密,你可不要说是我说的啊！\n");
        command("say 长安城的那个化生寺里的游方僧人那到是有颗,不知是真是假！\n");
        command("say 其他的我真的什么也不知道了！\n");
        return 1;
}
int accept_ask(object me)
{
        command("say 我只知道龙珠的事,其他我一概不知！\n");
        command("say 我告诉你一个秘密,你可不要说是我说的啊！\n");
        command("say 长安城的那个化生寺里的游方僧人那到是有颗,不知是真是假！\n");
        command("say 其他的我真的什么也不知道了！\n");
        return 1;
}
