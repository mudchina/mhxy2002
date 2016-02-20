//BY tianlin@mhxy for 2001.12.30

inherit NPC;
#include <ansi.h>
int ask_cake();

void create()
{
         set_name(HIY"精灵"NOR, ({"jing ling","jingling","jing","ling"}));
    set ("long", @LONG
牡丹宴厅的主人，管理着牡丹宴厅的一切事务！
当你过生日时,你可以来向他要礼物.
(ask jing ling about 生日礼物)
LONG);
       set("gender", "女性");
       set("title",HIW"生辰"NOR);
       set("age", 20);
       set("per", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
//     carry_object("/u/yudian/weapon/mmjian")->wield();
//     carry_object("/u/yudian/hak")->wear();
       set("inquiry", ([
            "精灵物语" : "“那是我最喜欢的书哦，绝对不给人！”\n", 
            "生日礼物" : (: ask_cake :),      
]));
        setup();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
}
}
int ask_cake()
{ 
        object ob;
        if (this_player()->query("birthday"))    {
            command("say 恭喜恭喜，祝你生日快乐！\n");
          ob=new("u/tianlin/npc/obj/cake");  //礼物的路径，自定义。
          ob->move(this_player()); 
        message_vision("\n$N给了$n一个特制的生日蛋糕。\n",  this_object(),this_player());
        this_player()->delete("birthday"); 
         return 1;            }
      return 0;
}
void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
say(name()+"今天是你的生日吗,如果是的话,我这里有你的一份礼物！”\n"NOR);

}
