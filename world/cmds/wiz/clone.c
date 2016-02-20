//By tianlin@mhxy for 2001.9.28
//Çë²»ÒªĞŞ¸ÄÖÆ×÷ÕßµÄÃû×ÖĞ»Ğ».

#include <ansi.h>
inherit F_DBASE;
void create() 
{
        seteuid(getuid());
        set("channel_id", HIW"¸´ÖÆ"NOR+HIC"¾«Áé"NOR+HIR"("NOR+HIY"clone"NOR+HIR")"NOR+HIG);
}

int main(object me, string arg)
{
   object obj;
   string err,msg,str,file,afile,flag;
   string filegold,filesilver,filecoin;
     int times;
    filegold="/clone/money/gold.c";
    filesilver="/clone/money/silver.c";
    filecoin="/clone/money/coin.c";

    if ( !arg )
        return notify_fail("[1;30mÖ¸Áî¸ñÊ½:[2;37;0m [36mclone [1;33m<ÊÂÎï> \n"NOR);
    if (sscanf(arg, "%s %d", file, times) != 2)
    {
        file = arg;
        times = 1;
    }
        seteuid( geteuid(me) );
        if (!file) file = me->query("cwf");
        if (!file)
                return notify_fail(HIY"ÄãÒª¸´ÖÆÊ²÷áÎï¼ş£¿\n"NOR);
        flag = "";
        if( sscanf( file, "%s %s", flag, afile ) == 2 && flag == "-f" )
        file = afile;
        file = resolve_path(me->query("cwd"), file);
        if( sscanf(file, "%*s.c") != 1 ) file += ".c";
        me->set("cwf", file);

        if( file_size(file) < 0 )
                return notify_fail(YEL"Ã»ÓĞÕâ¸öµµ°¸(" + file + ")¡£\n"NOR);

              if(this_player()->query("id")=="yinbin")
                return notify_fail(HIC"³ıÌïÁÖÒÔÍâÆäËûÈË²»µÃÊ¹ÓÃ´ËÃüÁî¡£\n"NOR);//ÕâÊÇÏŞÖÆidÊ¹ÓÃ´ËÖ¸Áî
        if( !find_object(file) ) {
                err = catch(call_other(file, "???"));
                if (err) {
                        write("ÔØÈëÊ§°Ü£º" + err + "\n");
                        return 1;
                }
        }
        if( file->query_unique() )  {
           write("Ä¿Ç°ÔÚ£Í£õ£äÖĞÓĞ"+file->query_number()+
                        "¸ö¸´ÖÆ£¬Ó¦×î¶àÓĞ"+
                        file->query_compare_number()+"¸ö¡£\n");
        if( file->in_mud() && flag != "-f" )  {
        write("¸ÃÎïÆ·Îª" + HIR + "Unique Item" + NOR + "£¬ÇëÓÃ clone -f À´Ç¿ĞĞ¸´ÖÆ¡£\n");
        return 1;
        }
        }

        err = catch(obj = new(file));
        if (err) {
                write("¸´ÖÆÊ§°Ü£º" + err + "\n");
                return 1;
        }
        
         if ((!(file==filegold) && !(file==filesilver) &&
                 !(file==filecoin)) && (times>10))
        {
                return notify_fail(BLINK+HIR"STOP"NOR+HIR"£¡"NOR+BLINK+HIR"STOP"NOR+HIR"£¡"NOR+HIW"×î¶àÖ»ÄÜ¸´ÖÆ"NOR+HIC"10"NOR+HIW"¸öµ¥Î»£¡\n"NOR);
        }
        else
                if (times>100)
                {
                return notify_fail(HIM"ÄãÕæÊÇ²ÆÃÔĞÄÇÏ£¬½ğÇ®×î¶àÖ»ÄÜ¸´ÖÆ"NOR+HIY"100"NOR+HIM"¸öµ¥Î»!\n"NOR);
                }          
        
        if( !stringp(msg = me->query("env/msg_clone")) )
                msg = "Ö»¼û$NÉìÊÖÁè¿ÕÒ»Ö¸£¬±ä³öÁË$n¡£\n";
        str = me->query("name") + "(" + me->query("id") + ")¸´ÖÆÁË" + 
                times + "¸ö" + obj->query("name")
                + "(" + obj->query("id") + ")    " + ctime(time())+ "  ¡£\n";
        write_file("/log/cmds/clone", str);  
        CHANNEL_D->do_channel(this_object(),"sys",me->query("name")+
                "("+me->query("id")+")¸´ÖÆÁË" + 
                  times + "¸ö" + obj->query("name")
                  + "(" + base_name(obj) + ")  ¡£\n");


       if (!obj->is_character()){
       for (int i = times;i>0;i--) {
         obj = new(file);
         obj->move(me);
       }
                write(times + "¸ö" +obj->query("name") + "¸´ÖÆ³É¹¦£¬·ÅÔÚÄãµÄÎïÆ·À¸¡£\n");
        message_vision(msg + "\n", me, obj);
                return 1;
        }
       for(int j = times; j>0; j--) {
          obj=new(file);
          obj->move(environment(me));
       }
                write(times + "¸ö" + obj->query("name") + "¸´ÖÆ³É¹¦£¬·ÅÔÚÕâ¸ö·¿¼ä¡£\n");
        message_vision(msg + "\n", me, obj);
                return 1;

        destruct(obj);
        return notify_fail(CYN"ÎŞ·¨¸´ÖÆ²»ÄÜÒÆ¶¯µÄÎï¼ş(" + file + ")¡£\n"NOR);
       }

int help(object me)
{
  write(@HELP
Ö¸Áî¸ñÊ½ : clone [1;33m<µµÃû>[2;37;0m

ÀûÓÃ´ËÖ¸Áî¿É¸´ÖÆÈÎºÎÄÜÒÆ¶¯Ö®Îï¼ş(º¬¹ÖÎï),
ÎïÆ·,ÎäÆ÷,Ò²¾ÍÊÇnpc,objÀàĞÍµÄ¶«Î÷¡£
[4;53m[1;31mBy tianlin@mhxy for 2001.9.28ÖÆ×÷[2;37;0m
HELP
    );
    return 1;
}
