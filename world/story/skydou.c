//By tianlin@mhxy for 2002.1.9

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "巫师会议室内"
        "红雨：没有其它事了，大家可以按照分工去工作了。"
        "凤冀：且慢!",
        "众巫师诧然.",
        "凤冀：田林，你喜欢头发油腻的肥胖女人吗？",
        "田林：当然不喜欢。",
        "凤冀：那鼻子扁平，长着小眼睛的女人怎么样？",
        "田林：这根本不可能。",
        "凤冀：或许你喜欢有口臭的女人吧？",
        "田林：开玩笑，有没有搞错，这可能吗？",
        "凤冀猛的抓住田林的衣领，厉声喝道：既然如此，你为什么还要勾引我的马子!",      
        (: give_gift :)
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
        STORY_D->give_gift("/clone/gift/obj/qnd", 1,
         HIM "\n“啪”的一声一颗潜能丹掉在你面前！\n" NOR);
        return HIM "听说一笑的宝物掉落凡间。\n" NOR;
}

