//bdt-job.c
//海洋2.0
//星星(lywin)
//小玉鼠(yushu)修改成xyj任务

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

mapping *bdt = ({ 
         ([ "bdt":"十字街头","where":"/d/city/center"]),
         ([ "bdt":"青龙大街","where":"/d/city/qinglong-e1"]),   
         ([ "bdt":"青龙大街","where":"/d/city/qinglong-e2"]),   
         ([ "bdt":"青龙大街","where":"/d/city/qinglong-e3"]),   
         ([ "bdt":"长安城东门","where":"/d/city/dongmen"]),   
         ([ "bdt":"玄武大街","where":"/d/city/xuanwu-n1"]),   
         ([ "bdt":"朝阳门","where":"/d/huanggong/chaoyangmen"]),   
         ([ "bdt":"朱雀大街","where":"/d/city/zhuque-s1"]),   
         ([ "bdt":"朱雀大街","where":"/d/city/zhuque-s2"]),   
         ([ "bdt":"朱雀大街","where":"/d/city/zhuque-s3"]),   
         ([ "bdt":"朱雀大街","where":"/d/city/zhuque-s4"]),   
         ([ "bdt":"南城口","where":"/d/changan/nanchengkou"]),   
         ([ "bdt":"白虎大街","where":"/d/city/baihu-w1"]),   
         ([ "bdt":"白虎大街","where":"/d/city/baihu-w2"]),   
         ([ "bdt":"白虎大街","where":"/d/city/baihu-w3"]),    
         ([ "bdt":"长安城西门","where":"/d/city/ximen"]),    
         ([ "bdt":"背阴巷","where":"/d/city/beiyin1"]),    
         ([ "bdt":"背阴巷","where":"/d/city/beiyin2"]),    
         ([ "bdt":"背阴巷","where":"/d/city/beiyin3"]),    
         ([ "bdt":"背阴巷","where":"/d/city/beiyin4"]),    
         ([ "bdt":"背阴巷","where":"/d/city/beiyin5"]),    
         ([ "bdt":"长安民居","where":"/d/city/minju1"]),   
         ([ "bdt":"长安民居","where":"/d/city/minju2"]),   
         ([ "bdt":"长安民居","where":"/d/city/minju3"]),   
         ([ "bdt":"长安民居","where":"/d/city/minju4"]),   
         ([ "bdt":"长安望南街","where":"/d/eastway/wangnan1"]),   
         ([ "bdt":"长安望南街","where":"/d/eastway/wangnan2"]),   
         ([ "bdt":"长安望南街","where":"/d/eastway/wangnan3"]),   
         ([ "bdt":"长安望南街","where":"/d/eastway/wangnan4"]),   
         ([ "bdt":"长安望南街","where":"/d/eastway/wangnan5"]),   
         ([ "bdt":"回春药铺","where":"/d/city/yaopu"]),   
         ([ "bdt":"鞋帽店","where":"/d/city/xiemao"]),   
         ([ "bdt":"老孙皮货店","where":"/d/city/maohuo"]),   
         ([ "bdt":"吉祥杂货铺","where":"/d/city/zahuopu"]),   
         ([ "bdt":"长安武馆","where":"/d/city/wuguan"]),   
         ([ "bdt":"长安武馆","where":"/d/city/wuguanzhong"]),   
         ([ "bdt":"兵器铺","where":"/d/city/bingqipu"]), 
         ([ "bdt":"化生寺","where":"/d/city/huashengsi"]), 
         ([ "bdt":"大雄宝殿","where":"/d/city/baodian"]), 
         ([ "bdt":"方丈室","where":"/d/city/fangzhang"]), 
         ([ "bdt":"袁氏草堂","where":"/d/city/caotang"]), 
         ([ "bdt":"小雁塔内","where":"/d/eastway/xyt1"]), 
         ([ "bdt":"小雁塔内","where":"/d/eastway/xyt10"]), 
         ([ "bdt":"大雁塔内","where":"/d/eastway/dyt1"]), 
         ([ "bdt":"大雁塔内","where":"/d/eastway/dyt3"]), 
         ([ "bdt":"大雁塔内","where":"/d/eastway/dyt5"]), 
                });
                
mapping query_bdt()
{
        return bdt[random(sizeof(bdt))];
}

int update_condition(object me, int duration)
{
        mapping bdt,bdtwhere;
        object ob;
        bdt = this_object()->query_bdt();
        bdtwhere = bdt["where"];
            
   if( duration < 1 )
   {
      tell_object(me, HIC "你的保护大唐任务时限到了，快回去报告吧\n" NOR );   	
      me->delete("job/bdt");
      me->set("job/bdt-done",1);   
      return 0;
   }
   if( !living(me) ) {
      message("vision", me->name() + "大呼道：妖管横行，天亡我大唐呀！！\n", environment(me), me);
   }
   else {
      tell_object(me, HIC "忽然城里有人大呼，不少妖怪打到" + bdt["bdt"] + "来了！\n" NOR );
      ob = new("/obj/bdt/yaoguai");
      ob->move(bdtwhere);
   }

   me->apply_condition("bdt-job", duration - 1);

   if( duration < 1 )
   {
      tell_object(me, HIC "你的保护大唐任务时限到了，快回去报告吧\n" NOR );
      me->delete("job/bdt");
      me->set("job/bdt-done",1);   	
      return 0;
   }
   return CND_CONTINUE;
}

