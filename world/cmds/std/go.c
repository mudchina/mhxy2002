// go.c
#include <ansi.h>
inherit F_CLEAN_UP;
#include "/cmds/std/valid_move.h";

mapping default_dirs = ([
	"north":		"北",
	"south":		"南",
	"east":			"东",
	"west":			"西",
	"northup":		"北边",
	"southup":		"南边",
	"eastup":		"东边",
	"westup":		"西边",
	"northdown":	"北边",
	"southdown":	"南边",
	"eastdown":		"东边",
	"westdown":		"西边",
	"northeast":	"东北",
	"northwest":	"西北",
	"southeast":	"东南",
	"southwest":	"西南",
	"up":			"上",
	"down":			"下",
	"out":			"外",
	"enter":		"里",
	"left": 		"左",
	"right":		"右",
]);
static  mapping empty_mapping = ([ ]);

void create() { seteuid(getuid()); }

// follow will have silent=2, so as to reduce the CPU load.
int main(object me, string arg, int silent)
{
    	mixed dest;
	string ridemsg, mout, min, dir,msg, thing_msg;
	object env, obj, ridee,thing;
	mapping exit;
	int valid;
       mapping my, my_temp;
       mapping my_env, my_armor;

	if( !arg ) return notify_fail("你要往哪个方向走？\n");

        if(!valid_move(me)) return 0;

	env = environment(me);
	if(!env) return notify_fail("你哪里也去不了。\n");

	if( !mapp(exit = env->query("exits")) || !exit[arg] ||  undefinedp(exit[arg]) ) {
		if( query_verb()=="go")
			return notify_fail("这个方向没有出路。\n");
		else
			return 0;
	}
	dest = exit[arg];

        my = me->query_entire_dbase();
        my_temp = me->query_entire_temp_dbase();
        if (! my_temp) my_temp = empty_mapping;

        my_armor = my_temp["armor"];
        if (! my_armor) my_armor = empty_mapping;

        my_env = my["env"];
        if (! my_env) my_env = empty_mapping;

	if (dest && objectp(dest))
	    obj = dest;
	else if( !(obj = load_object(dest)) )
	        return notify_fail("你要去的区域还没有连通。\n");
	else if( !(obj = find_object(dest)) )
		return notify_fail("无法移动。\n");

	valid=(int)env->valid_leave(me, arg);
	if( !valid ) return 0;
	if(valid>1) return 1;

	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;

        // snowcat 12/20/97
        if (ridee = me->ride())
          ridemsg = ridee->query("ride/msg")+"着"+ridee->name();
        else  
          ridemsg = "";

        if(ridee && !valid_move(ridee)) 
           return notify_fail("你的座骑走动不了。\n");
           
if(me->is_ghost()&&domain_file(base_name(environment(me)))!="death")
 {              
 	        write(BLU"突然间阴风阵阵，你耳边响起一阵空洞而又阴森的声音:‘回来哟，回来哟!’\n"NOR);
		write(HIW"一阵白雾将你裹了起来，你又回到了鬼门关\n"NOR);
                me->move("/d/death/gate");
                return 1;
 }
	if( me->is_fighting() ) {
		mout = ridemsg + "往" + dir + "落荒而逃了。\n";
		min = ridemsg + "跌跌撞撞地跑了过来，模样有些狼狈。\n";
	} else {
		if (me->query("position"))
		     ridemsg += "踏着一朵祥云";
	        else
		     ridemsg += "裹着一团妖气";
		//Jiz. 02/11

                if (objectp(thing = my_armor["cloth"]))
                        ridemsg = "身着" + thing->query("name");
                else
		if (userp(me))
                        ridemsg = "全身清洁溜溜";
		else
			ridemsg = "";

                if (objectp(thing = my_temp["weapon"]))
                        ridemsg += "手执"+ thing->query("name");

		if( ridee && ridee->query("bird") ) {
			mout = ridemsg+ "往" + dir + "飞去。\n";
			min = ridemsg+ "飞了过来。\n";
		} else {
 		 	mout = ridemsg+ "往" + dir + "离开。\n";
			min = ridemsg+ "走了过来。\n";
		}
	}

	if( !wizardp(me) || !me->query("env/invisibility") )
	{
	    	if (environment(me) && environment(me)->query("no_look"))
		    	message( "vision", "一个模糊的影子" +  mout, environment(me), ({me}) );
		else
			message( "vision", me->name() + mout, environment(me), ({me}) );
	}
	if( (! ridee || ridee->move(obj)) && me->move(obj, silent) ) {
		me->remove_all_enemy();
		if( !wizardp(me) || !me->query("env/invisibility") ) {
	    			if (environment(me) && environment(me)->query("no_look"))
		    			message( "vision", "一个模糊的影子" +  min, environment(me), ({me}) );
				else
					message( "vision", me->name() + min, environment(me), ({me}) );
		}
		me->set_temp("pending", 0);
		// added by snowcat, to fix the bug of recursive move of mutual follow + move to same room 
		if (env != obj)
			all_inventory(env)->follow_me(me, arg);
		if (ridee)
			tell_object (me,"你"+min);
		if (userp(me) && me->query_condition("no_pk_time") &&
		me->query_temp("rumor_time")+10<time() &&
		  MISC_D->find_place(environment(me))!=
		me->query_temp("last_place"))
		{ 
		  me->set_temp("last_place",MISC_D->find_place(environment(me)));
		  msg="听说杀人通缉犯"+HIW+me->query("name")+HIM+"最近在"+HIC+me->query_temp("last_place")+HIM+"附近出没。\n";
		CHANNEL_D->do_channel(this_object(),"rumor",msg);
		me->set_temp("rumor_time",time());
		}
		return 1;
	}

	return 0;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;

	if( !environment(me) || !living(me) ) return;
	exits = environment(me)->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	if (environment(me) && environment(me)->query("no_flee")) return;
	tell_object(me, "看来该找机会逃跑了．．．\n");
        if( me->query_temp("no_move") ) {
          tell_object (me, "可你被定住了，逃不掉！\n");
          return;
        }

	if( random(me->query_skill("dodge")/10 + me->query("kar")) < 10 ) {
	   tell_object(me, "你逃跑失败。\n");
	   return;
	}

	main(me, directions[random(sizeof(directions))], 0);
}

int help(object me)
{
	write(@HELP
指令格式 : go <方向>
 
让你往指定的方向移动。
 
HELP
    );
    return 1;
}
