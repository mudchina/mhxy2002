//By tianlin@mhxy for 2002.1.9

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "[1;33mÌıËµ×î½ü[2;37;0m[1;32mµÁ·Ë[2;37;0m[1;33mºáĞĞ£¬»¹ÇëÖîÎ»¶à¼ÓĞ¡ĞÄ£¡[2;37;0m",
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
        STORY_D->give_gift("/quest/feizei/feizei", 1,
                           HIM "\n¡°à²¡±µÄÒ»Éù"HIR"·ÉÔô"NOR"µ½ÄãÃæÇ°¡£\n\n" NOR);
        return 1;
}