//By tianlin@mhxy for 2002.1.9

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "²»ºÃÀ²¡«¡«¡«²»ºÃÀ²¡«¡«¡«",
        "Ë¾Âí¹â£ºÔõÃ´ÁË£¿³öÊ²Ã´ÊÂÁË£¿",
        "Ð¡º¢¼×£ºËÀ²»ÁËµôµ½¸×ÀïÁË¡£",
        "Ë¾Âí¹â¿ÈËÔÒ»Éù£¬µÀ£ºÎÒ»¹ÒÔÎªÊ²Ã´´ó²»ÁËµÄÊÂ£¬Ëû²»ÊÇËÀ²»ÁËÂï£¡»ÅÉõÃ´¡£",
        "ÖÚÐ¡º¢ÂÒ³ÉÒ»ÍÅ¡£",
        "[1;35m±ù[2;37;0m[33m¡«¡«[1;35mÌÇ[2;37;0m[33m¡«¡«[1;35mºù[2;37;0m[33m¡«¡«[1;35mÂ«[2;37;0m[33m¡«¡«",
        "Ë¾Âí¹âÝëÈ»¶øÆð£ºËûÄÌÄÌµÄ£¬ÎÒ¼ÇµÃËÀ²»ÁË»¹Ç·ÎÒÒ»´®ÌÇºùÂ«£¡",
        "Ð¡º¢ÒÒ£ºÊÇÓÐÕâÃ´»ØÊÂ£¬²»¹ýÄãÒª²»ÂíÉÏÕÒµ½¼Ò³¤°ÑËÀ²»ÁËÀÌÉÏÀ´£¬¾Í±ðÖ¸ÍûÁË£¡",
        "ºß£¡Ë¾Âí¹âÀäÀäÐ¦µÀ£ºÇøÇøÐ¡ÊÂ£¬ºÎ×ã¹Ò³Ý£¿",
        "......",
        "Ë¾Âí¹â¾ÙÆðÒ»¿éÊ¯Í·£¬ºÝºÝµÄÔÒÁËÏÂÈ¥£¬¡°ßÑµ±¡±£¬¸×ÆÆË®³ö¡£",
        "ËÀ²»ÁË¹¶ÑÓ²Ð´­¡£",
        "Ë¾Âí¹â·­ÆðËÀ²»ÁË£¬µÀ£ºËÀ²»ÁË°¡ËÀ²»ÁË£¬ÄãÇ·ÎÒµÄÄÇ´®±ùÌÇºùÂ«»¹¼Ç²»¼ÇµÃ£¿",
        "ËÀ²»ÁË£ºÄãËµÉ¶£¿",
        "Æ¹ÅÒ£¡",
        "ËÀ²»ÁË±»Ë¾Âí¹âÈÓµ½ÁË¸×Àï¡£",
        "ËÀ²»ÁË´Ó¸×ÀïÈÓ³öÁËÒ»´®±ùÌÇºùÂ«¡£",
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
        STORY_D->give_gift("/clone/gift/bingtang", 1,
                           HIM "\n¡°Å¾¡±µÄÒ»ÉùÒ»¿Ã±ùÌÇºùÂ«µôµ½ÄãÃæÇ°¡£\n\n" NOR);
        return 0;
}
