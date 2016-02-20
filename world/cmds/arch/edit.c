// By tianlin 2001.5.1
// edit.c
#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;
mixed query(string arg)
{
    if (arg && arg=="channel_id")
      return  RED"ÔÚÏß±à¼­(Edit)";
    return 0;
}
int main(object me, string file)
{
    string filename;
    if( !file ) return notify_fail("Ö¸Áî¸ñÊ½£ºedit <µµÃû>\n");
    if( in_edit(me) ) return notify_fail("ÄãÒÑ¾­ÔÚÊ¹ÓÃ±à¼­Æ÷ÁË¡£\n");
    filename=resolve_path(me->query("cwd"), file);
    if (!(int)SECURITY_D->valid_write(filename,me,"write"))
            return notify_fail("ÄãÃ»ÓĞ×ã¹»µÄ¶ÁĞ´È¨Àû¡£\n");
    foreach (object user in users())
        if (filename == "/"+in_edit(user) )
            return notify_fail("¹²Ïí³åÍ»£º"+user->name(1)+"("+capitalize(user->query("id"))+")"+"ÕıÔÚ±à¼­¸ÃÎÄ¼ş("+filename+")¡£\n");
    printf("±à¼­ÎÄ¼ş£º%s\n",filename);
CHANNEL_D->do_channel(this_object(),"sys",sprintf("%s(%s)ÕıÔÚÏß±à¼­(%s)¡£"
,me->name(1),capitalize(me->query("id")),filename));
    log_file("edit/"+geteuid(me), sprintf("edit %s %s\n", resolve_path(me->query
("cwd"), file), ctime(time())) );
    seteuid(geteuid(me));
    ed(resolve_path(me->query("cwd"), file));
    me->set("cwf",filename);
    return 1;
}
int help(object me)
{
  write(@HELP
Ö¸Áî¸ñÊ½ : edit <µµÃû>, edit here
ÀûÓÃ´ËÒ»Ö¸Áî¿ÉÖ±½ÓÔÚÏßÉÏ±à¼­µµ°¸¡£
[36m/ Ç°Ïò²éÕÒÄãºóÃæËù¸ú×ÅµÄ×Ö·û£¬±ÈÈç/¾Æ´ü
? ºóÏò²éÕÒÄãºóÃæËù¸ú×ÅµÄ×Ö·û
= ÏÔÊ¾µ±Ç°ĞĞÊÇµÚ¼¸ĞĞ
a ÔÚµ±Ç°ĞĞºóĞÂÔö¼ÓÒ»ĞĞ
A ÀàËÆ'a'ÃüÁî£¬µ«ÊÇ½«·­×ª×Ô¶¯Ëõ½øÄ£Ê½
c ½«µ±Ç°ĞĞÄÚÈİ¸²¸ÇµôÊäÈëĞÂ±à¼­ÄÚÈİ
d É¾³ıÖ¸¶¨·¶Î§µÄĞĞ
e ÍË³öµ±Ç°µµ°¸, ¿ªÊ¼±à¼­ÁíÒ»µµ(µµ°¸¸Ä±ä¹ıÎ´´æÅÌÎŞĞ§)
E ÀàËÆ'e'ÃüÁî£¬µ«ÊÇÎÄ¼ş±»ĞŞ¸Ä¹ıÒ²ÓĞĞ§
f ÏÔÊ¾»ò¸Ä±äÎÄ¼şÃû
g ²éÕÒÆ¥ÅäĞĞ²¢¶ÔÆäÖ´ĞĞÏàÓ¦ÃüÁî
h °ïÖúÎÄ¼ş(¾ÍÊÇÏÔÊ¾ÄãÏÖÔÚ¿´µ½µÄÕâĞ©ĞÅÏ¢£¬¿ÉÄÜÊÇÓ¢ÎÄ)
i ÔÚµ±Ç°ĞĞÇ°Ãæ²åÈëÒ»ĞĞ
I ÅÅ°æÕû¸ö´úÂë (Qixx version 1.0)
j ºÏ²¢ĞĞ£¬ÏµÍ³Ä¬ÈÏÊÇ½«ºóĞøĞĞÁ¬½Óµ½µ±Ç°ĞĞ
k ±ê¼Çµ±Ç°ĞĞ- later referenced as 'a
l ÏÔÊ¾Ö¸¶¨ĞĞ(¿ÉÏÔÊ¾¿ØÖÆ×Ö·û)
m ÒÆ¶¯Ö¸¶¨ĞĞ(»ò¼¸ĞĞ)µ½Ö¸¶¨Î»ÖÃ
n ĞĞºÅÏÔÊ¾ÇĞ»»¿ª¹Ø
O Í¬ÃüÁî'i'
o Í¬ÃüÁî'a'
p Êä³öÖ¸¶¨·¶Î§ĞĞ
q ÍË³ö±à¼­Æ÷
Q ÍË³ö±à¼­Æ÷£¬¼´Ê¹ÎÄ¼şÒÑ¾­±»ĞŞ¸ÄÇÒÎ´´æÅÌ
r ÔÚÎÄ¼şÎ²»òÖ¸¶¨ĞĞºó¶Á½øÁíÒ»ÎÄ¼ş
s ²éÕÒ²¢Ìæ»»(Ö»¶Ôµ±Ç°ĞĞµÚÒ»¸ö²éÕÒµÄ×Ö·û´®½øĞĞÌæ»»)
set ²éÑ¯£¬¸Ä±äºÍ±£´æ±à¼­Æ÷µÄÉè¶¨Öµ
t ¸´ÖÆÖ¸¶¨ĞĞµ½Ö¸¶¨Î»ÖÃ
v ËÑË÷²¢¶Ô²»Æ¥ÅäĞĞÖ´ĞĞÖ¸¶¨ÃüÁî
x ±£´æÎÄ¼ş²¢ÍË³ö
w ½«±à¼­µÄÄÚÈİĞ´µ½µ±Ç°ÎÄ¼ş»òÖ¸¶¨µÄÎÄ¼şÀï
W ÀàËÆ'w'ÃüÁî£¬µ«ÊÇÊÇ½«±à¼­µÄÄÚÈİ¸½¼Óµ½Ö¸¶¨»òµ±Ç°ÎÄ¼şºó
z ÏÔÊ¾20ĞĞ£¬¿ÉÓÃ²ÎÊı . + -
Z ÏÔÊ¾40ĞĞ£¬¿ÉÓÃ²ÎÊı . + -[2;37;0m[4;53m[1;37m[5mÕâĞ©ÊÇ½Ì»áÄãÔõÃ´Ê¹ÓÃeditÖ¸Áî.[2;37;0m
[4;53m[41m[1;33mBy tianlin 2001.5.1[2;37;0m
HELP
    );
    return 1;
}
