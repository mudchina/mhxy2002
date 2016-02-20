// claim.c

inherit F_CLEAN_UP;

int filter(object ob);

int main(object me, string arg)
{
	object *ob;
        int i;
        int n;

#if 0
        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;
#endif

	write(sprintf("一共清除了 %d 个变量.\n",
		      reclaim_objects()));
	return 1;
}

int help()
{
	write(@TEXT
指令格式: reclaim

查阅所有的对象，清除那些不应继续保存在内存中的变量。
TEXT );
	return 1;
}
