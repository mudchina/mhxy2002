//By tianlin@mhxy for 2002.1.9

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "听说最近"HIG"绿林悍匪"NOR+WHT"横行，还请诸位多加小心！",
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

int give_gift()
{
        STORY_D->give_gift("/quest/feizei/hanfei", 1,
                           HIM "\n“嗖”的一声"HIG"绿林悍匪"HIM"到你面前。\n\n" NOR);
    CHANNEL_D->do_channel(this_object(), "rumor", 
	    "听说"HIG"绿林悍匪"+HIM+"作恶多端，请大家多加小心！\n");
        return 1;
}