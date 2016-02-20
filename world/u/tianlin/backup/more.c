// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// cat.c
//[2000/11/16 根据神魔乱舞巫师管理需要lsg 修改]
inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
   string file;
   object ob;

   seteuid(geteuid(me));
   if (!arg) return notify_fail("指令格式 : more <档名>|<物件名> \n");
   file = resolve_path(me->query("cwd"), arg);
   if( file_size(file) < 0 ) {
     ob = present(arg, me);
     if( !ob ) ob = present(arg, environment(me));
     if( !ob ) return notify_fail("没有这个档案。\n");
      file = base_name(ob) + ".c";
    }
if (! (int)SECURITY_D->valid_read(file,me) ) return notify_fail("没有这个档案。\n");
  me->start_more_file(read_file(file));
 CHANNEL_D->do_channel( this_object(), "sys",
sprintf("〓监视〓-> 巫师：%s(%s) 正在浏览(more) %s文件 \n",me->name(1), geteuid(me),file ,  ));
   return 1;
}

int help(object me)
{
write(@HELP
指令格式 : more <档案>|<物件名>
 
分页显示档案内容。
 
more 模式下的指令:
q      : 离开 more.
b      : 显示前一页的内容.
[ENTER]: 显示下一页的内容.

HELP
    );
    return 1;
}
