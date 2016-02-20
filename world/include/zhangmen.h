static mapping zhangmen_skills = ([
"魔教"      : ({ "tianmo","tianmo-blade" }),
"月宫"        : ({ "moonshentong","moonforce","snowsword"}),
"五庄观"      : ({ "taiyi","zhenyuan-force" }),
"南海普陀山"  : ({ "buddhism","lotusforce" }),
"东海龙宫"    : ({ "seashentong","dragonforce" }),
"将军府"      : ({ "lengquan-force" }),
"阎罗地府"    : ({ "gouhunshu","tonsillit","hellfire-whip" }),
"陷空山无底洞": ({ "kugu-blade","huntian-qigong" }),
"灵剑门"      : ({ "lingjian-force","sword" }),
"方寸山三星洞": ({ "dao","qianjun-bang","wuxiangforce" }),
"大雪山"      : ({ "dengxian-dafa","ningxie-force" }),
]);

static mapping skills_limit = ([
"moonshentong":150,
"moonforce"   :150,
"snowsword"   :160,
"taiyi"       :150,
"zhenyuan-force" :150,
"buddhism"    :150,
"lotusforce"  :150,
"seashentong" :150,
"tianmo"  :100,
"tianmo-blade"  :100,
"dragonforce" :150,
"lengquan-force":150,
"gouhunshu"   :150,
"tonsillit" :130,
"hellfire-whip":150,
"kugu-blade"  :181,
"huntian-qigong":130,
"lingjian-force"  :150,
"sword" :150,
"dao"          :150,
"qianjun-bang" :160,
"wuxiangforce"  :150,
"dengxian-dafa":150,
"ningxie-force":150,
]);

#define DEBUG 1

int can_zhangmen(object ob)
{
 string family_name,skillname;
 string* fname;
 int myskill,limitskill;
 int i,j;

 family_name=ob->query("family/family_name");
 if(!family_name) return 0;

 fname=keys(zhangmen_skills);
 if(!fname) return 0;

 for(i=0;i<sizeof(fname);i++)
  if(fname[i]==family_name) break;
 if(i>=sizeof(fname)) return 0;

 fname=zhangmen_skills[family_name];
 if(!fname) return 0;

 j=0;
 for(i=0;i<sizeof(fname);i++)
  {
   skillname=fname[i];
   limitskill=skills_limit[skillname];
   if(limitskill) {
      myskill=ob->query_skill(skillname,1);
      if(myskill>=limitskill) j++;
    }
  }
 if(j==sizeof(fname)) return 1;
 return 0;
}
