//By tianlin@mhxy for 2002.1.9

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "[1;32m½­ºþ·çÆ½ÀË¾²£¬²¨À½²»¾ª¡£[2;37;0m",
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}
