//skills.c
//modified by yushu 2001/5/6
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob;
	mapping skl, lrn, map;
	string *sname, *mapped;
	int i;

	seteuid(getuid());

	if(!arg)
		ob = me;
	else{
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("你要察看谁的技能？\n");
	}
	if( ob!=me && ob->query("env/invisibility")&&!wizardp(me) )
		return notify_fail("你要察看谁的技能？\n");

	if( ob!=me && !wizardp(me) 
	&& !ob->is_apprentice_of(me) 
	&& !me->is_apprentice_of(ob) 
	&& getuid(ob)!=me->query("bonze/dadangid")
	&& getuid(ob)!=me->query("couple/id"))
		return notify_fail("只有巫师或有师徒关系的人能察看他人的技能。\n");

	skl = ob->query_skills();
	if(!sizeof(skl)) {
		write( (ob==me ? "你" : ob->name()) + "目前并没有学会任何技能。\n");
		return 1;
	}
	sname  = sort_array( keys(skl), (: strcmp :) );
       printf( CYN"                       〓〓"NOR HIR" %s "HIW"所学武技表"NOR  CYN" 〓〓\n",ob->name());
       printf("┏━━━━━━━━━━━━━━━━━━━━━━┯━━━━┯━━┯━━━┓\n");
       printf("┃       名               称                  │ 描  述 │等级│ 经 验┃\n");
       printf("┠──────────────────────┴────┴──┴───┨\n");
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});
	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	for(i=0; i<sizeof(skl); i++) {
	printf(CYN"┃"NOR"%s%s%-40s"      NOR "             %-10s %4d/   %5d"CYN"┃\n"NOR, 
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? "  ": HIG"→"HIY),
			to_chinese(sname[i]) + " (" + sname[i] + ")"NOR,
			SKILL_D(sname[i])->level_description(skl[sname[i]]),
			skl[sname[i]], (int)lrn[sname[i]],
		);
	}
	printf(CYN"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"NOR);
	write((ob==me ? "你" : ob->name()) +"目前共掌握"HIR+chinese_number(sizeof(skl))+NOR"项技能。\n\n");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : skills|jineng [<某人>]

这个指令可以让你查询所学过的技能。

你也可以指定一个和你有师徒关系的对象，用 skills 可以查知对方的技能状况。

巫师可以查询任何人或 NPC 的技能状况。

HELP
    );
    return 1;
}
