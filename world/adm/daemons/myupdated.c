// myupdated.c by LitChi 2001/7/26

#include <ansi.h>
#define UPDATE_HOUR 1
inherit F_DBASE;

void updateit(string file);
int update_file(string file);

void create()
{
        seteuid( ROOT_UID );
        set("channel_id","定时更新精灵");
        remove_call_out("updateit");
          call_out( "updateit", 1, "/adm/daemons/choosed.c");
           call_out( "updateit", 5, "/daemon/skill/*.c");//open by tianlin 本来我给cut了,为了减轻系统负重,但是有时候也出现skills没有被全部载入.所以先给开通
}

void updateit(string file)
{
        int i;
        object obj, *inv;
        string err;
        string dir, result;
        object ob;
        mixed *files;
        object me = this_object();

        seteuid( ROOT_UID );

    message("channel:sys", HIG"【UPDATE】"BLK + "UPDATE精灵开始编译["+ file +"]。。。\n"NOR, users());
    dir = resolve_path(me->query("cwd"), file);

    if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' )   dir += "/";
    files = get_dir(dir, -1);

    dir = dir[0..strsrch(dir,"/",-1)];

    if( !sizeof(files) ){
        if (file_size(dir) == -2) return;
        else
            return;
    }

    result = "";
    
    for(i=0; i<sizeof(files); i++){
        files[i][0] = resolve_path(dir,files[i][0]);
          if(files[i][1] != -2) {
            if( file_size(files[i][0])==-1 )
               return;
            update_file(files[i][0]);
          }
    }
    message("channel:sys", HIG"【UPDATE】"BLK + "编译结束，共编译"+ i +"个文件，下次编译将在" + UPDATE_HOUR + "个小时后开始。\n"NOR, users());
//    remove_call_out("updateit");
    call_out( "updateit", UPDATE_HOUR * 3600, file);
}

int update_file(string file)
{
        int i;
        object obj, *inv;
        string err;
        
        if (obj = find_object(file)) destruct(obj);

        if (obj) return notify_fail("无法清除旧程式码。\n");

//        message("channel:sys", HIG"【UPDATE】"BLK + "重新编译"+ file + "："NOR, users());
        err = catch( call_other(file, "???") );
        if (err)
                message("channel:sys", "发生错误："+ err +"\n"NOR, users());
        else 
//              message("channel:sys", "成功！\n"NOR, users());

        return 1;
}
