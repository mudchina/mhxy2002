#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIR"新年老人"NOR, ({ "xiannian laoren", "old man", "man"}) );
	set("attitude", "friendly");
	set("class", "xian");
	set("age", 10000);

	setup();
}

void init()
{       
	object ob;
        if(!clonep()) return;

	::init();

        set("chat_chance", 10);
        set("inquiry", ([
                "name" : "我是新年老人哦。\n",
                "here" : "这地方我可是头回来哦。\n", 
                "礼物" : "不给，不给。\n",
                "gift" : "我还想要礼物呢。\n",
         ]) );

         call_out("greeting", 1);
}

void greeting()
{
    switch (random(5))
    {
        case 0:
        message("system",HIR+"空气中到处流淌着浓浓的节日气氛,要过年了....\n"+NOR,users());
        break;
        case 1:
        message("system",HIM+"轰地一个大地红在空中绽开美丽的光环....\n"+NOR,users());
        break;
        case 2:
        message("system",HIG+"梦幻西游全体巫师祝您在新的一年里万事如意!\n"+NOR,users());
        break;
        case 3:
        message("system",HIY+"又是家家团圆的好日子了，人人脸上都洋溢着幸福的笑容...\n"+NOR,users());
        break;
        case 4:
        message("system",HIR+"空气中到处流淌着浓浓的节日气氛,要过年了....\n"+NOR,users());
        break;
    }
    call_out("greeting",180);
}

