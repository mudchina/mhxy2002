//by ephq
#include "/daemon/skill/dianxue/valid_kill.h";
mapping type(object me)
{
	object weapon;
	string skill_type;
	mapping sc;

	weapon=me->query_temp("weapon");

        if (objectp(weapon = me->query_temp("weapon")))
        skill_type=weapon->query("skill_type") ;
        else skill_type="unarmed";

        switch(skill_type){
                        case "sword":
                        	sc=(["dif": 100,
                        	     "action":"剑尖猛的向",
                        	     "type":"刺"
                        	   ]); 	
                                break;                  
                        case "fork":
                        	sc=(["dif":50,
                        	     "action":"叉头急速的往" ,
                        	     "type":"叉",                       		
                        	   ]); 	                        
                                break;
                        case "mace":
                        	sc=(["dif":65,
                        	     "action":"锏头化做无数锏影往", 	 
                        	     "type":"挥"                       		
                        	   ]); 	                        
                                break;
                        case "needle":
                        	sc=(["dif":120,
                        	     "action":"针头带着“咝，咝”的破空声，疾往", 	 
                        	     "type":"刺"                       		
                        	   ]); 	                        
                                break;
                        case "blade":
                        	sc=(["dif":67,
                        	     "action":"刀尖中宫直进，往",
                        	     "type":"戳" 	                        		
                        	   ]); 	                        
                                break;                                                                                                
                        case "spear":
                        	sc=(["dif":75,
                        	     "action":"枪头一抖，往", 	 
                        	     "type":"挑"                       		
                        	   ]); 	                        
                                break;
                        case "throwing":
                        	sc=(["dif":80,
                        	     "action":"化做点点流星，疾射而出,直向" ,
                        	     "type":"飞"	                        		
                        	   ]); 	                        
                                break;
                        case "whip":
                        	sc=(["dif":105,
                        	     "action":"鞭尖如灵蛇般的向", 	                        		
                        	     "type":"撩"
                        	   ]); 	                        

                                break;                                                                                                
                        case "unarmed":
                        	sc=(["dif":110,
                        	     "action":"食指微动，直往" ,	 
                        	     "type":"戳"                       		
                        	   ]); 	                        
                                break;                                                                                                                                
                        default: sc=(["type":"none"]);
                                break;
                        }
        
	return sc;
}
