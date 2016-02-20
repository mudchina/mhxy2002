// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// by mon

int valid_perform(object me, object target)
{    int pk_k, pk_v;   

//  if( userp(target) && userp(me) ) return notify_fail("目前是安全日，禁止PK\n");
     
     if(userp(target) && me->query_condition("no_pk_time")>240 
       && userp(me))
       return notify_fail("你最近杀人太多，此时忽然觉得罪孽深重，下不去手。\n");

     return 1;
}

