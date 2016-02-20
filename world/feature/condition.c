// condition.c

#include <condition.h>

mapping conditions;
mapping type_conditions;

nomask int update_condition()
{
	mixed *cnd, err;
	int i, flag, update_flag;
	object cnd_d;

	if( !mapp(conditions) || !(i=sizeof(conditions)) ) return 0;
	cnd = keys(conditions);
	update_flag = 0;
	while(i--) {

		cnd_d = find_object(CONDITION_D(cnd[i]));
		if( !cnd_d ) {
			err = catch(call_other(CONDITION_D(cnd[i]), "???"));
			cnd_d = find_object(CONDITION_D(cnd[i]));

			if( err || !cnd_d ) {
				log_file("condition.err",
					sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
						CONDITION_D(cnd[i]), this_object(), err)
				);
				if (mapp(conditions))
					map_delete(conditions, cnd[i]);
				continue;
			}
		}
		
		flag = call_other(cnd_d, "update_condition", this_object(), conditions[cnd[i]]);
		if( !( flag & CND_CONTINUE ) )
			if (mapp(conditions)) map_delete(conditions, cnd[i]);
		update_flag |= flag;
	}
	if( !sizeof(conditions) ) conditions = 0;

	return update_flag;
}

nomask void apply_condition(string cnd, mixed info)
{
	if( !mapp(conditions) )
		conditions = ([ cnd : info ]);
	else
		conditions[cnd] = info;
}

nomask mixed query_condition(string cnd)
{
	if( !mapp(conditions) || undefinedp(conditions[cnd]) ) return 0;
	return conditions[cnd];
}

nomask mapping query_entire_conditions()
{
	return conditions;
}

nomask mapping query_conditions_by_type(string required_type)
{
	object cnd_d;
	int i;
	string cnd_type;
	mixed *cnd, err;

	if (!mapp(conditions) || !(i = sizeof(conditions))) return 0;
	type_conditions = 0;
	cnd = keys(conditions);
	while(i--) {

		cnd_d = find_object(CONDITION_D(cnd[i]));
		if (!cnd_d) {
			err = catch(call_other(CONDITION_D(cnd[i]), "???"));
			cnd_d = find_object(CONDITION_D(cnd[i]));

			if (err || !cnd_d) {
				log_file("condition.err",
					sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
						CONDITION_D(cnd[i]), this_object(), err)
				);
				if (mapp(conditions))
					map_delete(conditions, cnd[i]);
				continue;
			}
		}

		cnd_type = call_other(cnd_d, "query_type", this_object());
		if (cnd_type == required_type) {
			if (!mapp(type_conditions)) type_conditions = ([ cnd[i] : conditions[cnd[i]] ]);
			else type_conditions[cnd[i]] = conditions[cnd[i]];
		}
	}
	return type_conditions;
}

nomask void clear_condition(string cnd)
{
	if (!cnd)
		conditions = 0;
	else if (mapp(conditions)) map_delete(conditions, cnd);
}
 
nomask void clear_conditions_by_type(string required_type)
{
	object cnd_d;
	int i;
	string cnd_type;
	mixed *cnd, err;

	if (!mapp(conditions) || !(i = sizeof(conditions))) return;
	cnd = keys(conditions);
	while(i--) {

		cnd_d = find_object(CONDITION_D(cnd[i]));
		if (!cnd_d) {
			err = catch(call_other(CONDITION_D(cnd[i]), "???"));
			cnd_d = find_object(CONDITION_D(cnd[i]));

			if (err || !cnd_d) {
				log_file("condition.err",
					sprintf("Failed to load condition daemon %s, removed from %O\nError: %s\n",
						CONDITION_D(cnd[i]), this_object(), err)
				);
				if (mapp(conditions))
					map_delete(conditions, cnd[i]);
				continue;
			}
		}

		cnd_type = call_other(cnd_d, "query_type", this_object());
		if (cnd_type == required_type) map_delete(conditions, cnd[i]);
	}
}
