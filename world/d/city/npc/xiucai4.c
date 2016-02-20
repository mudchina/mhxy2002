inherit NPC;
#include <ansi.h>
string * degree_desc = ({
       BLU "文盲" NOR,
       BLU "童生" NOR,
       BLU "秀才" NOR,
       CYN "举人" NOR,
       CYN "解元" NOR,
       CYN "贡士" NOR,
       CYN "会元" NOR,
       GRN "进士" NOR,
       GRN "探花" NOR,
       GRN "榜眼" NOR,
       GRN "状元" NOR,
       HIY "翰林院士" NOR,
       HIY "翰林硕士" NOR,
       HIY "翰林博士" NOR,
       HIY "翰林院编修" NOR,
       HIR "庶吉士" NOR,
       HIR "学士" NOR,
       HIR "内阁大学士" NOR,
       HIR "内阁首辅" NOR,
       MAG "文学大宗师" NOR,
       HIW "圣人" NOR,
});
int ask_degree();
string apply_gongming(object me);

void create()
{
        set_name("贺知章", ({"he zhizhang", "he", "zhizhang"}));
        set("gender", "男性");
        set("age", 55);
        set("title", "国子监大学士");
        set("str", 25);
        set("int", 30);
        set("long", "贺知章是国子监大学士，统管全国文人考试及升级。\n");
        set("combat_exp", 30000);
  set("daoxing", 50000);

        set("attitude", "friendly");
        set("class", "scholar");
        set_skill("unarmed", 50);
        set_skill("dodge",50);
        set_skill("literate", 100);
        set_skill("parry", 50);

        set("force", 500); 
        set("max_force", 500);
        set("inquiry", ([
                "name" : "薄名何足挂齿...老夫贺知章蒙皇上恩赏国子监大学士，实是愧不敢当。\n",
                "here" : "这里便是国子监。\n",
                "读书识字": "对了，你是来对地方了！\n",
                "学习" : "只要总管府认定，我们就收！\n",
                "功名" : (: apply_gongming :),
            "学位" : (:ask_degree:),
        ]) );
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}
int recognize_apprentice(object ob, object who)
{
/*
        object tongpai;
        if( !tongpai = present("tong pai", ob))
return notify_fail("贺知章笑道：没有总管府的认可，我是不敢乱收学生的！\n");
        if((string)tongpai->query("player") != (string)ob->id())
return notify_fail("贺知章瞪了你一眼，学文之人怎可作弊！！？\n");
*/  
      return 1;
}

string apply_gongming(object me)
{
        me=this_player();
        if( me->query("class") != 0 ) //means already has a class
        {
                return "功名富贵都是过眼云烟，又何必挂在心上？\n";
        }
        else
        {
                message_vision("贺知章说道：功名富贵都是过眼云烟，又何必挂在心上？\n", me);
                message_vision("贺知章对$N叹了口气道：既然你如此热衷...\n", me);
                me->set("class", "scholar");
                if( me->query_skill("literate", 1) < 20 )
                        return "以阁下的才识，还只能从童生做起。\n";
                else if( me->query_skill("literate", 1) < 100 )
                        return "以阁下的才识，做个秀才还是可以的。\n";
                else    return "以阁下的才识，做个大学士没问题。\n";
        }
}
int ask_degree()
{
        int lv;
        object ob = this_player();
        lv = (ob->query_skill("literate") / 5);
        if (lv >= sizeof(degree_desc)) lv = sizeof(degree_desc)-1; 
        if (lv < 3) 
        {
               command("say "+ob->query("name")+"，你那点墨水也好意思问? 随便给你个学位就算了! \n");
               ob->set("xuewei",degree_desc[lv]);
               return 1;
        }
        if (lv < 10) 
{
               command("say "+ob->query("name")+"，呃，不错，有前途，很高兴授予学位给你，继续好好努力! \n");
               ob->set("xuewei",degree_desc[lv]);
               return 1;
}
        else
{
               command("say 果然是长江后浪逐前浪啊，"+ob->query("name")+"，我非常荣幸能有机会为你授学位! \n");
               ob->set("xuewei",degree_desc[lv]);
               return 1;
}}
