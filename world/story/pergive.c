//By tianlin@mhxy for 2002.1.9

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "东方不财：莲亭，你觉的我美吗？",
        "杨莲亭笑道：美，美，我这儿搞到了一种仙丹，可以使人变的更美。",
        "东方不财大喜道：好，快给我一颗。",
        "杨莲亭掏出一葫芦：喏，这儿。",
        "东方不财：" HIY "哎呀！" NOR,
        "杨莲亭：不好，怎么掉下了黑木崖了，马上派人去找找。",
        "东方不财：算了算了，我已经够美了......。",
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
        STORY_D->give_gift("/clone/gift/perwan", 1,
                           HIM "\n“啪”的一声一枚仙丹掉到你面前。\n\n" NOR);
        return 0;
}
