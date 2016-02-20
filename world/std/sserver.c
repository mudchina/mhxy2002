//Cracked by Roath
// sserver.c

inherit F_CLEAN_UP;

// This function selects a random target for offensive spells/functions.
object offensive_target(object me)
{
	int sz;
	object *enemy;
	object victim;

	// mon 4/28/99
	// clean_up my enemy before selecting a target.
	me->clean_up_enemy();

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) victim=enemy[random(sz)];
	else return 0;
	
	if(!victim) return 0;
	if( victim->query_temp("netdead") )   {
	    if( member_array( me, victim->query_netdead_enemy() ) == -1 )
		return 0; // can't start fight if the 
	                //victim is already netdead
	}

	return victim;
}
