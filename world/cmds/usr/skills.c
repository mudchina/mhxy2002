//by tianlin 2001.5.1
// skills.c

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
//        if ( ob->query("SPSKILLS",1)  ) return ob->skills();		 
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("ฤใาชฒ์ฟดหญตฤผผฤÜฃฟ\n");
                 if( !ob->is_character() || ob->is_corpse() )
                         return notify_fail("มฌ"HIC + ob->query("name") + NOR"ตฤืดฬฌถผาชฒ้ฟดฃฟฤใีๆำฤฤฌกฃ\n");
	}
	if( ob!=me && ob->query("env/invisibility")&&!wizardp(me) )
		return notify_fail("ฤใาชฒ์ฟดหญตฤผผฤÜฃฟ\n");

	if( ob!=me && !wizardp(me) 
	&& !ob->is_apprentice_of(me) 
	&& !me->is_apprentice_of(ob) 
	&& getuid(ob)!=me->query("bonze/dadangid")
	&& getuid(ob)!=me->query("couple/id"))
		return notify_fail("ึปำะฯตอณนÜภํิฑป๒ำะท๒ฦÞนุฯตตฤศหฤÜฒ์ฟดห๛ศหตฤผผฤÜกฃ\n");

	skl = ob->query_skills();
// printf("[33mกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิ\n[2;37;0m");
	if(!sizeof(skl)) {
		write( (ob==me ? "ฤใ" : ob->name()) + "ฤฟวฐฒขรปำะังปแศฮบฮผผฤÜกฃ\n");
		return 1;
	}
	write( (ob==me ? "ฤใ" : ob->name()) +"ฤฟวฐนฒังนý"HIR""+
chinese_number(sizeof(skl))+""NOR"ึึผผฤÜฃบ\n\n"); 
	sname  = sort_array( keys(skl), (: strcmp :) );
	
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	
	for(i=0; i<sizeof(skl); i++) {
		printf("%s%s%-40s" NOR" - %-10s %4d/%5d\n", 
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? "  ": "[37mกฬ[36m"),//By tianlin@mhxy 2001.10.9
			to_chinese(sname[i]) + " (" + sname[i] + ")",
			SKILL_D(sname[i])->level_description(skl[sname[i]]),
			skl[sname[i]], (int)lrn[sname[i]],
		);
	}
	write("\n");
 // printf("[33m กิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิกิ รฮปรฮ๗ำฮ กิกิกิกิกิกิ\n[2;37;0m");
	return 1;
}

int help(object me)
{
	write(@HELP
ึธม๎ธ๑สฝ : skills|jineng [<ฤณศห>]

ีโธ๖ึธม๎ฟษาิศรฤใฒ้ัฏห๙ังนýตฤผผฤÜกฃ

ฤใาฒฟษาิึธถจาปธ๖บอฤใำะสฆอฝนุฯตตฤถิฯ๓ฃฌำร skills ฟษาิฒ้ึชถิทฝตฤผผฤÜืดฟ๖กฃ

ฮืสฆฟษาิฒ้ัฏศฮบฮศหป๒ NPC ตฤผผฤÜืดฟ๖กฃ

HELP
    );
    return 1;
}
