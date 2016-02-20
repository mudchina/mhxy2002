//Longgong_hot.c
int update_condition(object me, int duration)
{
        int limit, shaqi;

        limit = (int)me->query("cor")*50 + (int)me->query("max_force");
	shaqi = (int)me->query("bellicosity");

        me->apply_condition("longgong_hot", duration - 1);

        if( shaqi > limit
        &&      living(me) ) {
                me->unconcious();
        } else if( !living(me) ) {
message("vision", me->name() + "×ìÀïÅç³ö¹ÉÅ¨ÑÌ£¬È´ÒÀÈ»»èÃÔ²»ĞÑ¡£\n",environment(me), me);
		return 0;
        } else if( shaqi > limit/2 ) {
                tell_object(me, "[31mÄã¾õµÃ¸¹ÄÚÈç»ğÁÇÒ»°ã£¬ËæÊÇÒªÕ¨¿ªÒ»Ñù¡£\n[2;37;0m");
                message("vision", me->name() + "Ò»ÕÅ×ì£¬ËÆºõÍÂ³ö¼¸¿Å»ğĞÇ£¬±Ù±ÙÂÒ±Å¡£\n",environment(me), me);
                me->receive_damage("sen", 30);
		me->add("bellicosity", 30);
        } else if( shaqi > limit/4 ) {
                tell_object(me, "[1;31mÄã¾õµÃÈçÍ¬»ğÂ¯Ò»°ãÉÕµÄÄÑÊÜ¡£\n[2;37;0m");
                message("vision", me->name() + "×ìÀïÃ°³öµ­µ­¼¸ĞíºÚÑÌ¡£\n",environment(me), me);
                me->receive_damage("sen", 20);
		me->add("bellicosity", 20);
        } else {
		tell_object(me, "[1;31mÄã¾õµÃ¸¹ÄÚÏóÓĞÒ»ÍÅ»ğÔÚÉÕÒ»Ñù¡£\n[2;37;0m");
                message("vision", me->name() + "Í·ÉÏÃ°³öË¿Ë¿°×ÑÌ¡£\n",environment(me), me);
                me->receive_damage("sen", 10);
                me->add("bellicosity", 10);
	}

	me->add("potential", 10);

        if( !duration ) return 0;
        return 1;
}

