//by tianlin@mhxy for 2001.9.30
//´ÓÐÂ¸ÄÐ´,Çë²»Òª³­!

#include <ansi.h>

int main(object me, string arg)
{
	string loc;
        int mana_cost;
	object ridee, map;
	string ridemsg;

        seteuid(getuid());

        if( me->is_fighting() )
                return notify_fail("ÄãÕýÔÚÕ½¶·£¬·É²»¿ª¡£\n");
        if( me->is_busy() || me->query_temp("pending/exercising"))
                return notify_fail("ÄãÕýÃ¦×ÅÄØ£¬Ã»¹¤·òÌÚÔÆ¼ÝÎí¡£\n");
	if( !wizardp(me) && !environment(me)->query("outdoors") )
		return notify_fail("ÖÜÎ§Ã»ÓÐÒ»Æ¬ÔÆ£¬Ã»°ì·¨ÌÚÔÆ¼ÝÎí¡£\n");
	if( me->is_ghost() )
		return notify_fail("[34m×öÁË¹íÁË£¬¾ÍÀÏÊµµã°É£¡[2;37;0m\n");
        if( !arg )
                return notify_fail("ÄãÒª·Éµ½ÄÄÀïÈ¥£¿\n");
	if( me->query_temp("no_move") )
	    return notify_fail("Äã±»¶¨×¡ÁË£¬ÄÄÀï·ÉµÃÆðÀ´£¡\n");

	if( RANK_D->grade_dx( RANK_D->describe_dx( (int)me->query("daoxing") ) ) 
		< RANK_D->grade_dx(BLU "³õÁìÃîµÀ" NOR) )
	{
		message_vision(HIY
"$N·ÜÁ¦ÍûÉÏÒ»Ìø£¬ËÆºõÏë·ÉÆðÀ´¡£½á¹ûÀëµØ²»µ½Èý³ß¾ÍÒ»¸öµ¹ÔÔ´ÐË¤ÁËÏÂÀ´¡£\n"
NOR, me);
		return notify_fail("ÄãÏÖÔÚ»¹³õÁìÃîµÀ¶¼Ì¸²»ÉÏ£¬ÄÄÀï·ÉµÃÆðÀ´¡£\n");
	}

	if( RANK_D->grade_fali( RANK_D->describe_fali( (int)me->query("max_mana") ) ) 
		< RANK_D->grade_fali(HIB "ÌÚÔÆ¼ÝÎí" NOR) )
	{
		message_vision(HIY
"$N·ÜÁ¦ÍûÉÏÒ»Ìø£¬ËÆºõÏë·ÉÆðÀ´¡£½á¹ûÀëµØ²»µ½Èý³ß¾ÍÒ»¸öµ¹ÔÔ´ÐË¤ÁËÏÂÀ´¡£\n"
NOR, me);
		return notify_fail("¿´À´ÒÔÄãµÄ·¨Á¦ÐÞÎª»¹²»ÄÜÌÚÔÆ¼ÝÎí¡£\n");
	}

	if( (int)me->query("mana") < 200 )
	{
		message_vision(HIY
"$N·ÜÁ¦ÍûÉÏÒ»Ìø£¬ËÆºõÏë·ÉÆðÀ´¡£½á¹ûÀëµØ²»µ½Èý³ß¾ÍÒ»¸öµ¹ÔÔ´ÐË¤ÁËÏÂÀ´¡£\n"
NOR, me);
		return notify_fail("ÄãÄ¿Ç°·¨Á¦²»¹»³äÓ¯¡£\n");
	}


        if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 50 )
                return
notify_fail("ÄãÏÖÔÚÍ·ÄÔ²»Ì«ÇåÐÑ£¬µ±ÐÄµôÏÂÀ´Ë¤ËÀ¡£\n");

        if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 50 )
                return
notify_fail("ÄãÏë·ÉÆðÀ´£¬¿ÉÊÇÌåÁ¦ËÆºõÓÐµã²»Ö§¡£\n");

        mana_cost=-(100-(int)me->query_skill("spells"))/4-40;
        if(mana_cost > 0) mana_cost=0;

          if( (string)me->query("family/family_name") == "ÏÝ¿ÕÉ½ÎÞµ×¶´") {
                  message_vision(HIB"Ö»¼ûÆ½µØÀïºöÈ»¹ÎÆðÒ»ÕóÒõ·ç£¬½«$N½ô½ô¹ü×¡£¬\n"+
  "Çê¿Ì¼ä$NËæ·ç¶øÈ¥£¬ÏûÊ§µÃÎÞÓ°ÎÞ×Ù¡£ \n\n"NOR, me);
}
           if( (string)me->query("family/family_name") == "½«¾ü¸®") {
      message_vision(HIY"$NÓÃÊÖÇáÇáÒ»Ö¸£¬Ö»¼ûÌìÉÏ½µÏÂÒ»¶äÎå²ÊÏéÔÆ£¬\n"+
"$N×ÝÉíÔ¾ÉÏ£¬³ËÏéÔÆÆ®Ò¡¶øÈ¥......\n\n"NOR, me);
}
        if( (string)me->query("family/family_name") == "ÑÖÂÞµØ¸®") {
                message_vision(CYN"$NÍùºÚ°µ´¦Ò»Ö¸£¬Ö»¼ûËùÖ¸Ö®´¦·Â·ð³öÏÖÒ»ÉÈÃÅ£¬\n"+
"$N´ó²½×ßÈë£¬ÃÅÒ²ËæÖ®ÏûÊ§¡£ \n\n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "·½´çÉ½ÈýÐÇ¶´") {
                message_vision(HIG"$NÄí¸ö¿Ú¾÷£¬¿ÚÖÐÄî¶¯ÕæÑÔ£¬´ó½ÐÒ»Éù£º¡°½î¶·ÔÆ£¡¡±£¬\n"+
"Ö»¼ûÌìÉÏ½µÏÂÒ»¶äÆßÉ«ÔÆ²Ê£¬$N×ÝÉíÔ¾ÉÏ£¬·É³Û¶øÈ¥......\n\n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "ÔÂ¹¬") {
                message_vision(HIM"$NåüÃÄÒ»Ð¦£¬ÐÀÈ»ÆðÎè£¬Ëæ×ÅÒ»Õó»¨Ïã£¬ÒÑÏûÊ§ÔÚÔÂ¹âÖÐ¡£\n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "ÎäÊ¥ÃÅ") {
                message_vision(HIY"$NË«±Û½»²æ£¬Ä¬Äî¼¸¾äÖäÓï£¬Ò»µÀ¹âÖù´ÓÌì¶ø½µ£¬$NÒÑÏûÊ§ÔÚ¹âÖùÖÐ¡£\n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "Îå×¯¹Û") {
                message_vision(HIB"$N´óÐäÒ»°Ú£¬Ö»¼û·çÆðÔÆÓ¿£¬ÈËÒÑ½è·çÔÆÖ®ÊÆÔÚ¿ÕÖÐ´ó²½ÂõÈ¥¡£\n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "´óÑ©É½") {
                message_vision(HIW"$NËæÊÖÒ»»Ó£¬Ö»¼ûÒ»ÍÅÑ©Îí¹ü×¡ÕæÉí£¬Ðý×ª¶øÈ¥¡£ \n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "ÄÏº£ÆÕÍÓÉ½") {
                message_vision(HIY"$N¿ÚÖÐÄî×Å·ðºÅ£¬½ÅÏÂÉýÆðÏéÔÆ£¬»º»ºÀëµØ·ÉÈ¥¡£  \n"NOR, me);
              }
        if( (string)me->query("title/title_name") =="ÆÕÍ¨°ÙÐÕ") {
                message_vision(BLU"$NÑöÌì´ó½Ð:¡°Áù¶¡Áù¼×,ÖîÌìÉñÛ¡ËÍÎÒÒ»³Ì¡±.Ò»ÕóÒõ·ç´µ¹ý,$NÏûÊ§µÄÎÞÓ°ÎÞ×Ù....\n"NOR, me);
        }
        if( (string)me->query("family/family_name") =="Áé½ç") {
                message_vision(MAG"$NËæÊÖÌÍ³ö¸ù°×Óð,ÇáÇá»ÓÊÖ¼ä,°×ÔÆÒÑ×ßÔ¶,´ø×ßÁËÒ»Æ¬»ØÒä£¬ÁôÏÂÁËÎÞ±ßµÄ¼ÅÄ¯..\n"NOR, me);
        }
        if( (string)me->query("family/family_name") =="Ä§½Ì") {
                message_vision(RED"¡°ÌìÄ§ÎÞÐÎ£¬µØÄ§ÎÞÓ°£¬ÈËÄ§ÎÞ×Ù¡±£¬¼¸¾äÖäÓïÄîÍê£¬$N»¯ÎªÒ»µÀ"NOR+HIR"»ð¹â"NOR+RED"³å³öÈË¼ä..\n"NOR, me);
        }
        if( (string)me->query("family/family_name") =="Ìì¿Õ½ç") {
                message_vision(HIB"$NÐÅÊÖÖÀ³ö×Ô¼ºµÄÊØ»¤ÊÞ£¬Ô¾ÉÏÊØ»¤ÊÞµÄºó±³£¬´ÜÏö¶øÈ¥£¡\n"NOR, me);
        }
        if( (string)me->query("family/family_name") == "¶«º£Áú¹¬") {
                message_vision(HIC"$NÒ¡ÉíÒ»±ä£¬ÏÖ³öÔ­ÐÎ£¬ÕýÊÇÒ»ÌõÉñÁú£¬Ëæ¼´´©ÔÆ¶øÈ¥¡£ \n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "»ðÔÆ¶´") {
              message_vision(RED"$N¿ÚÄí¸ö¿Ú¾÷£¬¿ÚÖÐÄî¶¯ÕæÑÔ,Í»È»¡°ºä¡±µØÃ°ÆðÒ»ÍÅºìÎí,$NËæ¼´ÒþÈëºìÎíÖÐ¡£\n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "ÂÒÊ¯É½±Ì²¨Ì¶") {
              message_vision(CYN"$NÒ¡ÉíÒ»±ä£¬ÏÖ³öÔ­ÐÎ£¬ÕýÊÇÒ»ÌõÉñÁú£¬Ëæ¼´´©ÔÆ¶øÈ¥¡£ \n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "ÌìÅîË§¸®") {
              message_vision(WHT"$N¿ÚÖÐ´óº°Ò»Éù: ÖíÎÞÄÜ. . .½Ó×ÅÄãÌ¤ÆðÒ»ÍÅ"HIR"Æß"HIM"²Ê"HIC"Ïé"HIY"ÔÆ"NOR WHT"·ÉÏòÌì¼Ê¡£ \n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "Îäµ±ÅÉ") {
              message_vision(HBRED+HIW"$N¿ÚÖÐÄîÁË¼¸¾ä¿Ú¾÷,À´ÁËÒ»ÕÐ"NOR+HBBLU HIY"¡°Ì«¼«Ê®ÈýÊ½¡±"NOR+HBRED+HIW",»º»ºµÄÀëÈ¥..... \n"NOR, me);//By tianlin@mhxy for 2001.9.30ÖÆ×÷
              }
        if( (string)me->query("family/family_name") == "Éñ½£É½×¯") {
              message_vision(WHT"$N¿ÚÖÐÄîÁË¼¸¾ä¿Ú¾÷,Ö»¼ûÌìÉÏ·ÉÀ´ÎÞÊýµÄ½£Óê°ÑÄã¸ø¾íÁË½øÈ¥.\n"NOR, me);//By tianlin@mhxy for 2001.12.14ÖÆ×÷
              }
        if( (string)me->query("family/family_name") == "ÉÙÁÖËÂ") {
              message_vision(WHT"$N¿ÚÖÐ´óº°Ò»Éù: ÖíÎÞÄÜ. . .½Ó×ÅÄãÌ¤ÆðÒ»ÍÅ"HIR"Æß"HIM"²Ê"HIC"Ïé"HIY"ÔÆ"NOR WHT"·ÉÏòÌì¼Ê¡£ \n"NOR, me);
              }
         if( (string)me->query("family/family_name") == "ÊñÉ½ÅÉ") {
             message_vision(HIC"$N¿ÚÄí¸ö¿Ú¾÷£¬ÈÓ³öÒ»°Ñ±¦½££¬$N·É³Û¶øÉÏ£¬Ò»ÕÐ¡¸Óù½£·ÉÐÐ¡¹ÏòÔ¶·½·ÉÈ¥¡£¡£¡£¡£\n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "ÅÌË¿¶´") {
             message_vision(MAG"$Nð©ÍóÇá¶¶£¬µ«¼ûÒ»µÀ²ÊºçÂäÁËÏÂÀ´,$NÏËÑüÇá°ÚÆ®È»¶øÉÏ,Ï¼¹âÒ»ÉÁ,²ÊºçÏûÊ§µÄÎÞÓ°ÎÞ×Ù¡£\n"NOR, me);
              }
        if((string)me->guery("family/family_name") == "½­ºþÀË×Ó"){
             message_vision(HBYEL+HIB" $NÉíÐÍÒ»±ä£¬¿ÚÖÐ´óº°Ò»Éù ·ÉÏÉ £¬$N¸úËæ×Å×Ô¼ºµÄÕâ¹ÉÆøµÀ£¬ÔÚÃ£Ã£ÈËº£ÏûÊ§µÄ²»ÁôºÛ¼£¡£\n"NOR, me); 
              }

        me->add("mana", mana_cost);

        if(arg=="stone") loc="/d/dntg/hgs/entrance";
        else if(arg=="kaifeng") loc="/d/kaifeng/tieta";
        else if(arg=="moon") loc="/d/moon/ontop2";
        else if(arg=="lingtai") loc="/d/lingtai/gate";
        else if(arg=="putuo") loc="/d/nanhai/gate";
        else if(arg=="changan") loc="/d/city/center";
        else if(arg=="sky") loc="/d/dntg/sky/nantian";
	 else if(arg=="wuzhuang") loc="/d/qujing/wuzhuang/gate";
	 else if(arg=="meishan") loc="/d/meishan/erlangwai";
        else if(arg=="wudang") loc="/d/wudang/xuanyuegate";
        else if(arg=="lingjie") loc="/d/lingjie/rukou";
//        else if(arg=="shenjian") loc="/d/shenjian/wuc";
        else if(arg=="shaolin") loc="/d/southern/shaolin/simen";//by tianlin@mhxy for 2001.9.27ÐÞ¸Ä
        else if(arg=="wudangshan") loc="/d/wudang1/guangchang";//by tianlin@mhxy for 2001.9.25¼ÓÈëwudangÅÉ
        else if(arg=="33tian") loc="/d/33tian/33tian";//by tianlin 2001.7.1
      else if(arg=="shushan") loc="/d/shushan/shanmen";
              else if(arg=="penglai") {
		if(!(map=present("eastsea map", me)) && !wizardp(me)) {
			write("ÄãÔÚÌìÉÏ×ªÁË°ëÌìÒ²²»Öª¸ÃÍùÄÇ±ß·É¡£¡£¡£\n");
			message_vision("\n$NÊ§ÍûµØ´ÓÔÆÉÏÌøÁËÏÂÀ´£¡\n", me);
			return 1;
			}
		if( !wizardp(me)&&(string)map->query("unit")!="ÕÅ" ){
			write("ÄãÔÚÌìÉÏ×ªÁË°ëÌìÒ²²»Öª¸ÃÍùÄÇ±ß·É¡£¡£¡£\n");
                        message_vision("\n$NÊ§ÍûµØ´ÓÔÆÉÏÌøÁËÏÂÀ´£¡\n", me);
                        return 1;
                        }
//		write("Äã¼Ý×ÅÏéÔÆÏò¶«±ßº£ÖÐ·ÉÈ¥¡£¡£¡£\n\n");
		loc="/d/penglai/penglai";
	}
//by tianlin 2001.7.17¼ÓÒÔÐÞ¸ÄxueshanµÄfly xueshan²»ÓÃmap
	else if(arg=="xueshan") {
		if(!(map=present("xueshan map", me)) &&(string)me->query("family/family_name")!="´óÑ©É½"&& !wizardp(me)){
			write("ÄãÔÚÌìÉÏ×ªÁË°ëÌìÒ²²»Öª¸ÃÍùÄÇ±ß·É¡£¡£¡£\n");
			message_vision("\n$NÊ§ÍûµØ´ÓÔÆÉÏÌøÁËÏÂÀ´£¡\n", me);
			return 1;
			}
		if( !wizardp(me)&&(string)me->query("family/family_name")!="´óÑ©É½"&&(string)map->query("unit")!="ÕÅ" ){
                        write("ÄãÔÚÌìÉÏ×ªÁË°ëÌìÒ²²»Öª¸ÃÍùÄÇ±ß·É¡£¡£¡£\n");
                        message_vision("\n$NÊ§ÍûµØ´ÓÔÆÉÏÌøÁËÏÂÀ´£¡\n", me);
                        return 1;
                        }
		loc="/d/xueshan/binggu";
	}
//By tianlin@mhxy for 2002.1.10,ÖÆ×÷Ö»ÓÐshenjianµÄµÜ×Ó¿ÉÒÔfly shenjian
	else if(arg=="shenjian") {
		if((string)me->query("family/family_name")!="Éñ½£É½×¯"&& !wizardp(me)){
			write(HIC"ÄãÔÚÌì¿ÕÖÐÏëÁËÓÖÏë£¬¿ÉÊÇÍüÁËÈ¥Éñ½£É½×¯µÄÂ·ÁË!\n"NOR);
			message_vision(HIY"\n$N´ÓÔÆÉÏÌøÁËÏÂÁË,·Ç³£Ê§Íû£¡\n"NOR, me);
			return 1;
			}
		if( !wizardp(me)&&(string)me->query("family/family_name")!="Éñ½£É½×¯"){
                        write("ÄãÔÚÌìÉÏ×ªÁË°ëÌìÒ²²»Öª¸ÃÍùÄÇ±ß·É¡£¡£¡£\n");
                        message_vision("\n$NÊ§ÍûµØ´ÓÔÆÉÏÌøÁËÏÂÀ´£¡\n", me);
                        return 1;
                        }
		loc="/d/shenjian/wuc";
	}
	else if(arg=="wusheng"){
		loc = "/d/wusheng/room1.c";
		loc[strlen(loc)-3] = '1'+random(4);
	}
	else if(arg=="baoxiang"){
		loc = "/d/qujing/baoxiang/bei1.c";
		loc[strlen(loc)-3] = '1'+random(4);
	}else if(arg=="pingding"){
		loc = "/d/qujing/pingding/ping1.c";
		loc[strlen(loc)-3] = '1'+random(4);
	}else if(arg=="yalong"){
		loc = "/d/qujing/pingding/yalong1.c";
		loc[strlen(loc)-3] = '1'+random(3);
	}else if(arg=="wuji"){
		loc = "/d/qujing/wuji/square.c";
		//loc[strlen(loc)-3] = '1'+random(9);
	}else if(arg=="chechi"){
		loc = "/d/qujing/chechi/jieshi1.c";
		loc[strlen(loc)-3] = '1'+random(9);
	}else if(arg=="tongtian"){
		loc = "/d/qujing/tongtian/hedong1.c";
		loc[strlen(loc)-3] = '1'+random(6);
	}else if(arg=="jindou"){
		loc = "/d/qujing/jindou/jindou1.c";
		loc[strlen(loc)-3] = '1'+random(4);
	}else if(arg=="nuerguo"){
		loc = "/d/qujing/nuerguo/towna1.c";
		/*
		if (me->query("obstacle/nuerguo")!="done" && !wizardp(me)){
			write("\nÒ»Õó·ç°ÑÄã¶«µ¹Î÷ÍáµØ´µÁË»ØÀ´£¡\n");
			write("¿´Ñù×Ó·É²»¹ýÈ¥¡£\n");
			return 1;
			}
		*/
		loc[strlen(loc)-4] = 'a'+random(3);
		loc[strlen(loc)-3] = '1'+random(3);
	}else if(arg=="dudi"){
		loc = "/d/qujing/dudi/dudi1.c";
		loc[strlen(loc)-3] = '1'+random(4);
	}else if(arg=="huangfeng"){
                loc = "/d/qujing/huangfeng/huangfeng1.c";
		loc[strlen(loc)-3] = '1'+random(7);
        }else if(arg=="baigudong"){
                loc = "/d/qujing/baigudong/sroad1.c";
                loc[strlen(loc)-3] = '1'+random(6);
       }else if(arg=="shuangcha"){
		loc = "/d/qujing/shuangcha/shanlu1.c";
		loc[strlen(loc)-3] = '1'+random(5); 
       }else if(arg=="liusha"){
         	loc = "/d/qujing/liusha/river.c";
       }else if(arg=="heifeng"){
		loc = "/d/qujing/heifeng/road1.c";
		loc[strlen(loc)-3] = '1'+random(4);
       }else if(arg=="yingjian"){
		loc = "/d/qujing/yingjian/xiaolu1.c";
		loc[strlen(loc)-3] = '1'+random(4); 
        }else if(arg=="firemount"){
         	loc = "/d/qujing/firemount/cuiyun1.c";
		loc[strlen(loc)-3] = '1'+random(5);
	}else if(arg=="jilei"){
		loc = "/d/qujing/jilei/jilei1.c";
		loc[strlen(loc)-3] = '1'+random(3);
	}else if(arg=="jisaiguo"){
		loc = "/d/qujing/jisaiguo/east1.c";
		loc[strlen(loc)-3] = '1'+random(4);
	}else if(arg=="jingjiling"){
		loc = "/d/qujing/jingjiling/jingji1.c";
	}else if(arg=="xiaoxitian"){
		loc = "/d/qujing/xiaoxitian/simen.c";
        }else if(arg=="zhuzi"){
         	loc = "/d/qujing/zhuzi/zhuzi1.c";
		loc[strlen(loc)-3] = '1'+random(5);
        }else if(arg=="qilin"){
         	loc = "/d/qujing/qilin/yutai.c";
        }else if(arg=="pansi"){
         	loc = "/d/qujing/pansi/ling1.c";
		loc[strlen(loc)-3] = '1'+random(6);
        }else if(arg=="biqiu"){
         	loc = "/d/qujing/biqiu/jie1.c";
		loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="qinghua"){
         	loc = "/d/qujing/biqiu/zhuang.c";
	}else if(arg=="wudidong"){
		loc = "/d/qujing/wudidong/firemount-wudidong3.c";
		loc[strlen(loc)-3] = '1'+random(3);
        }else if(arg=="qinfa"){
         	loc = "/d/qujing/qinfa/jiedao1.c";
		loc[strlen(loc)-3] = '1'+random(8);
        }else if(arg=="yinwu"){
         	loc = "/d/qujing/yinwu/huangye1.c";
        }else if(arg=="fengxian"){
         	loc = "/d/qujing/fengxian/jiedao1.c";
		loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="yuhua"){
         	loc = "/d/qujing/yuhua/xiaojie1.c";
		loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="baotou"){
         	loc = "/d/qujing/baotou/shanlu1.c";
		loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="zhujie"){
         	loc = "/d/qujing/zhujie/shanlu11.c";
		loc[strlen(loc)-3] = '1'+random(8);
        }else if(arg=="jinping"){
         	loc = "/d/qujing/jinping/xiaojie1.c";
		loc[strlen(loc)-3] = '1'+random(7);
        }else if(arg=="qinglong"){
         	loc = "/d/qujing/qinglong/shanjian.c";
        }else if(arg=="tianzhu"){
         	loc = "/d/qujing/tianzhu/jiedao11.c";
		loc[strlen(loc)-3] = '1'+random(8);
        }else if(arg=="maoying"){
         	loc = "/d/qujing/maoying/shanpo1.c";
		loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="lingshan"){
         	loc = "/d/qujing/lingshan/dalu1.c";
		loc[strlen(loc)-3] = '1'+random(3);
        }else{
                write("\n\nµ½ÁË£¡Äã°´ÏÂÔÆÍ·ÌøÁËÏÂÀ´¡£\n");
                write("ß×£¿£®£®£®ÔõÃ´»¹ÔÚÔ­À´µÄµØ·½£¿\n");
                return 1;
        }

	if (! loc)
		return 1;
		
	// mon /10/18/98
	if(MISC_D->random_capture(me,0,1)) return 1;

	if (ridee = me->ride()) {
	  ridemsg = ridee->query("ride/msg")+"×Å"+ridee->name();
	  ridee->move(loc);
	}  
	else  
	  ridemsg = "";
	                                            	
	me->move(loc);
       write("\n\nµ½ÁË£¡Äã°´ÏÂÔÆÍ·ÌøÁËÏÂÀ´¡£\n");

          if( (string)me->query("family/family_name") == "ÏÝ¿ÕÉ½ÎÞµ×¶´") {
message_vision(HIB"\nºöÈ»¼ä¹ÎÆðÒ»ÕóÒõ·ç£¬·ç¾¡´¦£¬$N×ßÁË³öÀ´¡£ \n"
  NOR, me);
}
           if( (string)me->query("family/family_name") == "½«¾ü¸®") {
   message_vision(HIY"\nÖ»¼û¿ÕÖÐÆ®ÂäÒ»¶äÎå²ÊÏéÔÆ£¬$N²¦¿ªÔÆ¶Ë×ßÁË³öÀ´¡£ \n"
  NOR, me);
}
        if( (string)me->query("family/family_name")=="ÑÖÂÞµØ¸®") {
                message_vision(CYN"\nÒõÓ°ÖÐ´µÆðÒ»ÕóÀä·ç£¬°éËæ×ÅÀäÉ­É­µÄÐ¦Éù£¬$N"+ridemsg+"Èç÷Î÷È°ã´ÓºÚ°µÖÐ³öÏÖ¡£ \n"
NOR, me);

        }
            if( (string)me->query("family/family_name")=="·½´çÉ½ÈýÐÇ¶´") {
                message_vision(HIG"\nÖ»Ìý¼ûÌìÉÏ´«À´Ò»Éù£º¡°°³À´Ò²£¡¡±£¬ÈËËæÉùµ½£¬$N"+ridemsg+"´Ó½î¶·ÔÆÖÐÈ½È½ÂäÏÂ¡£\n"
NOR, me);
            }
            if( (string)me->query("family/family_name")=="ÔÂ¹¬") {
                message_vision(HIM"\nÖ»¼ûÒ»µÀÔÂ¹âÈ÷ÔÚÄãÃæÇ°£¬ÈáÈáµÄ£¬ÀäÀäµÄ£¬$N"+ridemsg+"´ÓÖÐÆ®È»¶øÖÁ¡£ \n"
NOR, me);
        }
            if( (string)me->query("family/family_name")=="Îå×¯¹Û") {
                message_vision(HIB"\nÒ»ÕóÇå·ç´µÀ´£¬$N"+ridemsg+"´Ó¿ÕÖÐ½µÂä¡£ \n"
NOR, me);
        }
            if( (string)me->query("family/family_name")=="´óÑ©É½") {
                message_vision(HIW"\nö®Ê±¼ä£¬´óÑ©·×·É£¬$N"+ridemsg+"ÒàÈç¾§Ó¨ÌÞÍ¸µÄÑ©»¨Ëæ·çÆ®ÏÂ¡£ \n"
 NOR, me);
        }
            if( (string)me->query("family/family_name")=="ÄÏº£ÆÕÍÓÉ½") {

                message_vision(HIY"\nÒ»ÉùºéÁÁµÄ¡°ÄÏÎÞ°¢ÃÖÍÓ·ð¡±£¬$N"+ridemsg+"´Ó·ð¹âÖÐ£¬ÏéÔÆÀï×ß³ö¡£ \n"
NOR, me);
        }
        if( (string)me->query("title/title_name") =="ÆÕÍ¨°ÙÐÕ") {
                message_vision(BLU"Òõ·ç¹ý´¦,$NÏÖÁË³öÀ´.......\n"NOR, me);
        }
        if( (string)me->query("family/family_name") =="Áé½ç") {
                message_vision(MAG"Î¢·çÕóÕó,$N"+ridemsg+"ÊÖ³ÖÒ»°Ñ»ìÔªÅùö¨ÕäÖéÉ¡Âõ²½×ßÁË³öÀ´£¬´ø×ÅÒ»Ë¿ã°âêÓë¹Â¼Å..........\n"NOR, me);
        }
        if( (string)me->query("family/family_name") =="Ä§½Ì") {
                message_vision(RED"Ò»µÀ"+HIR"»ð¹â"NOR+RED"$N"+ridemsg+"Æ¾¿Õ³öÏÖ£¬Ï¸¿´¾¹È»»¯³ÉÒ»¸öÈËÐÎ...\n"NOR, me);
        }
        if( (string)me->query("family/family_name") =="Ìì¿Õ½ç") {
                message_vision(HIB"Ò»ÕóºôÐ¥Éù¹ýºó£¬$N"+ridemsg+"´ÓÌì¿Õ½çµÄÊØ»¤ÉñÊÞ±³ÉÏ×ÝÉíÌøÏÂ..... \n"NOR, me);
        }
            if( (string)me->query("family/family_name")=="¶«º£Áú¹¬") {
                message_vision(HIC"\n°ë¿ÕÖÐ·Â·ð³å³öÒ»ÌõË®Öù£¬$N"+ridemsg+"´ÓË®ÖùÉÏÎÈÎÈÌøÂäµØÏÂ¡£  \n"
NOR, me);
        }
            if( (string)me->query("family/family_name")=="»ðÔÆ¶´") {
                message_vision(RED"\nÒ»ÍÅºìÉ«µÄÑÌÎíÓ¿ÁË¹ýÀ´,$N"+ridemsg+"Í»È»´ÓÀïÃæ±ÄÁË³öÀ´. \n"
NOR, me);
        }
        if( (string)me->query("family/family_name") == "ÂÒÊ¯É½±Ì²¨Ì¶") {
              message_vision(CYN"\n°ë¿ÕÖÐ·Â·ð³å³öÒ»ÌõË®Öù£¬$N"+ridemsg+"´ÓË®ÖùÉÏÎÈÎÈÌøÂäµØÏÂ¡£  \n"
NOR, me);
              }
        if( (string)me->query("family/family_name") == "ÌìÅîË§¸®") {
              message_vision(WHT"\nÔÆ²Ê³öÏÖÔÚÌì¼Ê£¬$N"+ridemsg+"Ò»¸ö×ÝÉíÌøÁËÏÂÀ´¡£  \n"
NOR, me);
              }
        if( (string)me->query("family/family_name") == "Îäµ±ÅÉ") {
              message_vision(HBRED HIW"\nÍ»È»ÌìÆø´ó±ä£¬$N"+ridemsg+"ÂýÂý×ßÁË¹ýÀ´¡£  \n"
NOR, me);
              }
        if( (string)me->query("family/family_name") == "Éñ½£É½×¯") {
              message_vision(WHT"\nÍ»È»Ìì¿ÕÖÐ³öÏÖÎÞÊý½£Óê£¬$N"+ridemsg+"´Ó½£ÓêÖÐ×ßÁË¹ýÀ´¡£  \n"
NOR, me);
              }
        if( (string)me->query("family/family_name") == "ÉÙÁÖËÂ") {
              message_vision(WHT"\nÔÆ²Ê³öÏÖÔÚÌì¼Ê£¬$N"+ridemsg+"Ò»¸ö×ÝÉíÌøÁËÏÂÀ´¡£  \n"
NOR, me);
              }
            if( (string)me->query("family/family_name")=="ÊñÉ½ÅÉ") {
                message_vision(HIC"\nÒ»µÀÀ¶¹âÉÁ¹ý,$N"+ridemsg+"´Ó½£ÉÏÌøÁËÏÂÀ´¡£ \n"
NOR, me);
        }        
            if( (string)me->query("family/family_name") == "ÅÌË¿¶´") {
                message_vision(MAG"\nµ«¼ûÒ»µÀ²Êºç´ÓÌì¿Õ»®¹ý£¬$N"+ridemsg+"Ëæ²ÊºçÆ®È»¶øÖÁ¡£ \n"
NOR, me);
        }
            if( (string)me->query("family/family_name") == "ÎäÊ¥ÃÅ") {
                message_vision(HIY"\nÖ»Ìý¿ÕÖÐÒ»ÉùÇåÐ¥£¬$N"+ridemsg+"ËæÒ»¶äÏéÔÆÆ®È»¶øÖÁ¡£ \n"
NOR, me);
        }
            if( (string)me->query("family/family_name") == "½­ºþÀË×Ó"){
                message_vision(HBYEL+HIB"\nÌì¿ÕÖÐÅÌÐý×Å¾ÅÌõ½ðÁú£¬$N"+ridemsg+"´ÓÔÆÎíÖÐÒ»³å¶ø³ö¡£\n"NOR, me);
        }
                 return 1;
}

int help(object me)
{
        write(@HELP
Ö¸Áî¸ñÊ½ : fly|fei [Ä¿µÄµØ]

µ±ÄãµÄµÀÐÐºÍ·¨Á¦¸ßÇ¿Ê±£¬Äã¿ÉÒÔÌÚÔÆ¼ÝÎí¡£

Ä¿Ç°Äã¿ÉÒÔ·Éµ½µÄµØ·½£º
[33mchangan[2;37;0m         ->[37m³¤°²³Ç                 [33mkaifeng[2;37;0m        ->[37m¿ª·â³Ç
[33mstone[2;37;0m           ->[37m»¨¹ûÉ½ÏÉÊ¯             [33msky[2;37;0m            ->[37mÄÏÌìÃÅ
[33mmoon[2;37;0m      	->[37mÀ¥ÂØÉ½ÔÂ¹¬             [33mpenglai[2;37;0m        ->[37mÅîÀ³ÏÉµº
[33mlingtai[2;37;0m         ->[37mÁéÌ¨·½´çÉ½    	 [33mputuo[2;37;0m     	->[37mÄÏº£ÆÕÍÓÉ½
[33mxueshan[2;37;0m	        ->[37m´óÑ©É½º®±ù¹È           [33mmeishan[2;37;0m        ->[37mÃ·É½¹à½­¿Ú
[33mwuzhuang[2;37;0m        ->[37mÍòÊÙÉ½Îå×¯¹Û           [33mshushan[2;37;0m        ->[1;32mÍò½£Ö®×ðÊñÉ½[2;37;0m
[33mwusheng[2;37;0m	        ->[37mÎäÊ¥ÃÅ                 [33m33tian[2;37;0m           ->[37m¶µÂÊ¹¬
[33mlingjie[2;37;0m	        ->[37mÁé½ç                 


[33mbaoxiang[2;37;0m	->[37m±¦Ïó¹ú		 [33mpingding[2;37;0m  	->[37mÆ½¶¥É½
[33myalong[2;37;0m    	->[37mÑ¹ÁúÉ½ 		 [33mwuji[2;37;0m           ->[37mÎÚ¼¦¹ú
[33mchechi[2;37;0m		->[37m³µ³Ù¹ú 		 [33mtongtian[2;37;0m	->[37mÍ¨ÌìºÓ
[33mjindou[2;37;0m  	->[37m½ð¶µÉ½ 		 [33mnuerguo[2;37;0m	->[37mÅ®¶ù¹ú
[33mdudi[2;37;0m   		->[37m¶¾µÐÉ½ 		 [33mfiremount[2;37;0m	->[37m»ðÑæÉ½
[33mjilei[2;37;0m    	->[37m»ýÀ×É½ 		 [33mjisaiguo[2;37;0m	->[37m¼ÀÈü¹ú
[33mjingjiling[2;37;0m	->[37m¾£¼¬Áë		 [33mxiaoxitian[2;37;0m	->[37mÐ¡Î÷Ìì
[33mzhuzi[2;37;0m		->[37mÖì×Ï¹ú		 [33mqilin[2;37;0m		->[37m÷è÷ëÉ½
[33mpansi[2;37;0m		->[37mÅÌË¿Áë		 [33mbiqiu[2;37;0m		->[37m±ÈÇð¹ú 
[33mqinghua[2;37;0m		->[37mÇå»ª×¯		 [33mwudidong[2;37;0m       ->[37mÎÞµ×¶´
[33mqinfa[2;37;0m           ->[37mÇÕ·¨¹ú		 [33mfengxian[2;37;0m	->[37m·ïÏÉ¿¤ 
[33myinwu[2;37;0m    	->[37mÒþÎíÉ½		 [33myuhua[2;37;0m   	->[37mÓñ»ªÏØ 
[33mbaotou[2;37;0m  	->[37m±ªÍ·É½		 [33mzhujie[2;37;0m  	->[37mÖñ½ÚÉ½
[33mjinping[2;37;0m 	->[37m½ðÆ½¸®		 [33mqinglong[2;37;0m	->[37mÇàÁúÉ½ 
[33mtianzhu[2;37;0m 	->[37mÌìóÃ¹ú		 [33mmaoying[2;37;0m 	->[37mÃ«Ó±É½ 
[33mlingshan[2;37;0m	->[37mÁéÉ½                   [33mbaigudong[2;37;0m      ->[1;31m°×¹Ç¶´[2;37;0m   
[33mhuangfeng[2;37;0m       ->[1;31m»Æ·ç¶´[2;37;0m                 [33mshuangcha[2;37;0m      ->[1;31mË«²æÁë[2;37;0m
[33myingjian[2;37;0m        ->[1;31mÓ¥³î½§[2;37;0m                 [33mheifeng[2;37;0m        ->[1;31mºÚ·çÉ½[2;37;0m
[33mliusha[2;37;0m          ->[1;31mÁ÷É³ºÓ[2;37;0m                 




HELP
        );
        return 1;
}

