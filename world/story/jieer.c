//By tianlin@mhxy for 2002.1.9

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "田林在网上聊天泡MM……",
        "突然一个惊艳的名字跳入了他的眼帘",
        "田林老着脸皮凑了上去。",
        "叽咶一阵乱烦之后，田林心动了",
        "于是开始打听MM的样子：",
        "田林：亲爱的，你长的什么样啊？",
        "MM：恩……长头发，挺瘦的，168。",
        "田林：能不能在说仔细点，太抽象了。",
        "MM：很仔细了啊。",
        "田林：可是……如果……。",
        "MM：如果什么？",
        "田林：……如果……我拿一个168的拖把，也是很象你说的啊。",
        "MM断线了！",
        "三分钟之后……田林在网吧门口被人围住了……",
        "@%^$&%^*^&(",
        "田林留下了一件遗物……",
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
    STORY_D->give_gift("/d/obj/misc/crystalball", 1,
     HIM "\n“啪”的一声一个水晶球掉在你面前！\n" NOR);
 return HIM "听说田林的宝物水晶球遗失了。\n" NOR;
}

