//Cracked by Roath
// promote.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string id,file,club_name;
	object mark,ob,old_mark;
	mapping ob_info;
	int level;
	seteuid(getuid());
        if(!arg) return notify_fail("指令格式 : setclub <某人> with (帮会信物档案路径)\n");
        else
        {
        	if( sscanf(arg, "%s with %s", id, file)!=2 ) return notify_fail("指令格式 : setclub <某人> with (帮会信物档案路径)\n");
                ob = present(id, environment(me));
                if (!ob) ob = find_player(id);
                if (!ob) ob = find_living(id);
	        if (!ob) return notify_fail("没有这个人喔.\n");
		
		if(!mark=new(file)) return notify_fail("没有这个信物或是档案不正确.\n");
		if(!stringp(club_name=mark->query("club"))) return notify_fail("这个信物的<club>资料不正确.\n");
		 if( (mark->query_weight()+ob->query_encumbrance())>ob->query_max_encumbrance() )
 		 return notify_fail(ob->name(1)+"拿不动"+mark->query("name")+"。\n");
		ob->delete("club");

		CLUB_D->add_club(mark->query("club_id"));
		
		if(mark->query("club_max_level") > 1) level=mark->query("club_max_level");
			else level=5;
		
		ob_info=([
				"level": level,
				"title": "帮会创始人",
				"info1": "无",
				"info2": ctime(time()),
				"info3": me->name_id(1),
		]);
		
		CLUB_D->set_member(mark->query("club_id"),getuid(ob),ob_info);
		CLUB_D->set_club_leader(mark->query("club_id"),getuid(ob));
		while(old_mark=present("club_mark", ob)) destruct(old_mark);
		mark->move(ob);
		message_vision("$N将$n提升为"+club_name+"的创始人。\n",me,ob);
		ob->save();
	}
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : setclub <某人> with (帮会信物档案路径)

将一名玩家提升为帮派老大。
HELP
    );
    return 1;
}
