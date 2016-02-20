//负责存放妖。

#include <ansi.h>
#include "place.h"
string* guainame=({
        "野猫怪","yemao guai",
        "野鸡怪","yeji guai",
        "野狗怪","yegou guai",
        "野兔怪","yetu guai",
        "野象怪","yexiang guai",
        "野熊怪","yexiong guai",
        "野猪怪","yezhu guai",
        "蝎子怪","xiezi guai",
        "野猴怪","yehou guai",
"椅妖","yizi yao",
"鬼婆","gui po",
"风妖","feng yao",
"雪精","xue jing",
"蛤蟆怪","hama guai",
"壁虎怪","bihu guai",
"水蛇精","shuishe jing",
"僵尸","jiang shi",
"树妖","shu yao",
"狐狸精","huli jing",
"槐树精","huaishu jing",
"吸血鬼","xixie gui",
"杨树精","yangshu jing",
"吊死鬼","diaosi gui",
"黑无常","heiwu chang",
"白无常","baiwu chang",
"蝴蝶精","hudie jing",
"刑天","xing tian",
"夔","kui",
"蚩尤","chi you",
"水魔兽","shui moshou",
"土魔兽","tu moshou",
"火魔兽","huo moshou",
"蛟怪","jiao guai",
"蛇妖","she yao",
"石矶娘娘","shiji niangniang",
"黑山老妖","heishan laoyao",
"蜈蚣精","wugong jing",
"白骨精","baigu jing",
"蜘蛛精","zhizhu jing",
"蜂妖","feng yao",
"灯笼怪","denglong guai",
"坛子精","tanzi guai",
"扫把精","saoba jing",
});
        
string* xianname=({
        "仙人","xian ren",
        "仙官","xian guan",
        "仙女","xian nu",
        "仙卿","xian qing",
        "仙将","xian jiang",
        "仙妃","xian fei",
        "大仙","da xian",       
	"白云大师","baiyun dashi",
	"燕赤侠","yanchi xia",
	"仙子","xian zi",
	"灭妖专家","secmieyao zhuanjia",
	"菩萨","pu sa",
	"共工","gong gong",
	"祝融","zhu rong",
	"姜子牙","jiang ziya",
	"哪吒","ne zha",
	"木吒","mu zha",
	"金吒","jin zha",
	"托塔天王","tuota tianwang",
	"金刚","jin gang",
	"尊者","zun zhe",
	"赤脚大仙","chijiao daxian",
	"黄飞虎","huangfei hu",
	"广成子","guancheng zi",
	"太乙真人","taiyi zhenren",
	"陆压道人","luya daoren",
	"傀儡生","kuilei sheng",
	"钟馗","zhong kui",
	"罗汉","luo han",
	"剑仙","jian xian",
	"灶王爷","zaowang ye",
	"土地神","tudi shen",
	"财神","cai shen",
	"龙女","long nv",
	"善财童子","shancai tongzi",
	"进宝天尊","jinbao tianzun",
	"天兵","tian bing",
	"天将","tian jiang",
	"巨灵神","juling zhen",
});


int add_new_yao( object me);
void create()
{
    seteuid(getuid());
}

string query_yao(object me)
{
     me=this_player();
     
     if(!me->query("m_mieyao")) {
       if(me->query("mud_age")-me->query("secmieyao_mudage")<480) {
         return("不是让你去杀了"+me->query("secmieyao/place")+"的"+me->query("secmieyao/name")+"么？\n");
	} else {
		me->set("m_mieyao",1);
         	me->add("faith",-1);
         	return ("你真是没用，我再给你一次机会！");
	        }
      } else {
          if(me->query("mud_age")-me->query("secmieyao_mudage")<80) 
		return ("干的不错，先下去休息休息吧。\n");
     else {
	me->delete("m_mieyao");
	add_new_yao(me);
        if(me->query("secmieyao/type")=="xian")
        {
         	return ("现有"+me->query("secmieyao/name")+"("+me->query("secmieyao/id")+")在"+me->query("secmieyao/place")+"为非作歹，\n你马上去灭了他，以尽除妖灭魔的义务！\n");
        } else {
      	  	return ("听说"+me->query("secmieyao/name")+"("+me->query("secmieyao/id")+")最近在"+me->query("secmieyao/place")+"一带修行，\n你马上去吃了他，扬我魔族气势！\n");
    	       } 
 	     	  }
 	}
}


int add_new_yao( object me)
{
    string my_id,my_cls,type;
    string sname;
 
    string* yaoname;
    int my_exp,index,i;
    mapping skill_status;
    mapping secmieyao;
    object where,yao;
        
    my_exp=me->query("combat_exp");
    my_cls=me->query("class");
//By tianlin@mhxy for 2001.9.30
//     if(my_cls=="xian"||my_cls=="taoist"||my_cls=="dragon"||my_cls=="bonze"||my_cls=="fighter"){
     if(my_cls=="xian"||my_cls=="taoist"||my_cls=="dragon"||my_cls=="shaolin"||my_cls=="wudang"||my_cls=="bonze"||my_cls=="fighter"){
        type="xian";
        yaoname=guainame;
    }
    else {
        type="mo";
        yaoname=xianname;
    }
    
    index=random(sizeof(yaoname)/2)*2;
    
    secmieyao=(["type" : type]);
    secmieyao+=(["id" : yaoname[index+1] ]);
   
    if(my_exp<10000)
    { 
    sname="小小 "+yaoname[index];
    i = 0;
    } 
    else if(my_exp<100000)
    {
    sname="十年 "+yaoname[index];
    i = 1;
    }    
    else if(my_exp<1000000)
    {        
    sname="百年 "+yaoname[index];
    i = 2;
     }
    else if(my_exp<10000000)
     {
     i = 3;
    sname="千年 "+yaoname[index];
     }    
else 
{
sname="得道 "+yaoname[index];
 i = 4;
}
   
    secmieyao+=(["name" : sname]);
    
    if (skill_status = me->query_skills() ) {
      yaoname  = keys(skill_status);
      my_exp = 0;
      for(index=0; index<sizeof(skill_status); index++) {
        if(skill_status[yaoname[index]]>my_exp &&(string)SKILL_D(yaoname[index])->type()=="martial")
           my_exp=skill_status[yaoname[index]];
      }
    }
    
    index=random(sizeof(place))+1;
    yaoname=place[index];
    secmieyao+=(["place" :yaoname[sizeof(yaoname)-1] ]);
    index=random(sizeof(yaoname)-2);
    sname=yaoname[sizeof(yaoname)-2]+yaoname[index];
    secmieyao+=(["location" : sname]);
    me->set("secmieyao_mudage",me->query("mud_age"));
    me->set("secmieyao",secmieyao);
    
    if(!(where=find_object(secmieyao["location"])))
             where=load_object(secmieyao["location"]);

    switch(i)
        {
        case 0:
        yao=new("/d/obj/npc/yao0");
        break;
        case 1:
        yao=new("/d/obj/npc/yao0");
        break;
        case 2:
        yao=new("/d/obj/npc/yao");
        break;
        case 3:
        yao=new("/d/obj/npc/yao1");
        break;
        case 4:
        yao=new("/d/obj/npc/yao1");
        break;
        }
   // yao=new("/d/obj/npc/yao");
    yao->move(where);
//  if (me->query("id")=="xlwang")  me->move(where);
//    yao->set("owner_name",me->name());
    yaoname=explode(secmieyao["id"]," ");
    yaoname=({secmieyao["id"]})+yaoname;
    if( me->query_temp("apply/name") )
        me->delete_temp("apply/name");
    yao->set_name(me->name()+"的 "+secmieyao["name"],yaoname);
    yao->set("pre_killer",me);
    yao->init_skill(me->query("combat_exp"),my_exp,
         me->query("max_kee"),me->query("max_force"),
         me->query("max_sen"),me->query("max_mana"),secmieyao["type"]);
}

int query_killyao(object me,string loc,string yaoid)
{
    string* loclist;
    string* loclist2;
    mapping secmieyao=me->query("secmieyao");
    
    if(!mapp(secmieyao))return 0;
    loclist=explode(secmieyao["location"],"/");
    loclist2=explode(loc,"/");
    return (loclist[sizeof(loclist)-2]==loclist2[sizeof(loclist2)-2]&&secmieyao["id"]==yaoid);     
    return 0;   
}
