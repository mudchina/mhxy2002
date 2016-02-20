//1
void wzg (object ob, int level) 
{
  ob->set_skill("unarmed", level);
  ob->set_skill("wuxing-quan", level);
  ob->set_skill("dodge", level);
  ob->set_skill("baguazhen", level);
  ob->set_skill("parry", level);
  ob->set_skill("sword", level);
  ob->set_skill("sanqing-jian", level);
  ob->set_skill("staff", level);
  ob->set_skill("fumo-zhang", level);
  ob->set_skill("hammer", level);
  ob->set_skill("kaishan-chui", level);
  ob->set_skill("blade", level);
  ob->set_skill("yange-blade", level);
  ob->set_skill("force", level);   
  ob->set_skill("zhenyuan-force", level);
  ob->set_skill("literate", level);
  ob->set_skill("spells", level);
  ob->set_skill("taiyi", level);
  ob->map_skill("spells", "taiyi");
  ob->map_skill("force", "zhenyuan-force");
  ob->map_skill("unarmed", "wuxing-quan");
  ob->map_skill("sword", "sanqing-jian");
  ob->map_skill("dodge", "baguazhen");
  ob->map_skill("staff", "fumo-zhang");
  ob->map_skill("blade", "yange-blade");
  ob->map_skill("hammer", "kaishan-chui");
}
//2
void jjf (object ob, int level)
{
  ob->set_skill("literate", level);
  ob->set_skill("force", level);
  ob->set_skill("lengquan-force", level);
  ob->set_skill("parry", level);
  ob->set_skill("dodge", level);
  ob->set_skill("yanxing-steps", level);
  ob->set_skill("unarmed", level);
  ob->set_skill("changquan", level);
  ob->set_skill("mace", level);
  ob->set_skill("wusi-mace", level);
  ob->set_skill("spear", level);
  ob->set_skill("bawang-qiang", level);
  ob->map_skill("mace", "wusi-mace");
  ob->map_skill("force", "lengquan-force");
  ob->map_skill("unarmed", "changquan");
  ob->map_skill("spear", "bawang-qiang");
  ob->map_skill("parry", "bawang-qiang");
  ob->map_skill("dodge", "yanxing-steps");
}  
//3
void shushan (object ob, int level)
{
  ob->set_skill("unarmed", level);
  ob->set_skill("fumozhang",level);
  ob->set_skill("dodge", level);
  ob->set_skill("zuixian-steps", level);
  ob->set_skill("parry", level);
  ob->set_skill("sword", level);
  ob->set_skill("shushan-jianfa", level);
  ob->set_skill("force", level);   
  ob->set_skill("shushan-force", level);
  ob->set_skill("literate", level);
  ob->set_skill("spells", level);
  ob->set_skill("xianfeng-spells", level);
  ob->map_skill("spells", "xianfeng-spells");
  ob->map_skill("force", "shushan-force");
  ob->map_skill("sword", "shushan-jianfa");
  ob->map_skill("dodge", "zuixian-steps");
  ob->map_skill("unarmed", "fumozhang");
}
//4
void xueshan (object ob, int level)
{
   ob->set_skill("unarmed", level);
   ob->set_skill("cuixin-zhang", level);
   ob->set_skill("dodge", level);
   ob->set_skill("xiaoyaoyou", level);
   ob->set_skill("parry", level);
   ob->set_skill("sword", level);
   ob->set_skill("bainiao-jian", level);
   ob->set_skill("force", level);   
   ob->set_skill("ningxie-force", level);
   ob->set_skill("literate", level);
   ob->set_skill("spells", level);
   ob->set_skill("dengxian-dafa", level);
   ob->set_skill("throwing", level);
   ob->map_skill("spells", "dengxian-dafa");
   ob->map_skill("force", "ningxie-force");
   ob->map_skill("unarmed", "yingzhaogong");
   ob->map_skill("blade", "bingpo-blade");
   ob->map_skill("blade", "bingpo-blade");
   ob->map_skill("sword", "bainiao-jian");
   ob->map_skill("parry", "bainiao-jian");
}  
//5
void lingjie (object ob, int level)
{
   ob->set_skill("literate", level);
   ob->set_skill("spells", level);
   ob->set_skill("kongming-spells", level);
   ob->set_skill("unarmed", level);
   ob->set_skill("guangming-shouyin", level);
   ob->set_skill("dodge", level);
   ob->set_skill("fengtian-steps", level);
   ob->set_skill("parry", level);
   ob->set_skill("force", level);
   ob->set_skill("guangming-force", level);
   ob->set_skill("umbrella", level);
   ob->set_skill("lingfan-san",level);
   ob->map_skill("spells", "kongming-spells");
   ob->map_skill("unarmed", "guangming-shouyin");
   ob->map_skill("dodge", "fengtian-steps");
   ob->map_skill("force", "guangming-force");
   ob->map_skill("umbrella", "lingfan-san");
}    
//6
void psd (object ob, int level)
{
   ob->set_skill("literate", level);
   ob->set_skill("unarmed", level);
   ob->set_skill("dodge", level);
   ob->set_skill("force", level);
   ob->set_skill("parry", level);
   ob->set_skill("sword", level);
   ob->set_skill("spells", level);
   ob->set_skill("whip", level);
   ob->set_skill("pansi-dafa", level);
   ob->set_skill("lanhua-shou", level);
   ob->set_skill("jiuyin-xinjing", level);
   ob->set_skill("qingxia-jian", level);
   ob->set_skill("yueying-wubu", level);
   ob->set_skill("yinsuo-jinling", level);
   ob->map_skill("spells", "pansi-dafa");
   ob->map_skill("unarmed", "lanhua-shou");
   ob->map_skill("force", "jiuyin-xinjing");
   ob->map_skill("sword", "qingxia-jian");
   ob->map_skill("parry", "yinsuo-jinling");
   ob->map_skill("dodge", "yueying-wubu");
   ob->map_skill("whip", "yinsuo-jinling");
}  
//7
void hell (object ob, int level)
{
  ob->set_skill("jinghun-zhang", level);
  ob->set_skill("tonsillit", level);
  ob->set_skill("gouhunshu", level);
  ob->set_skill("unarmed", level);
  ob->set_skill("whip", level);
  ob->set_skill("sword", level);
  ob->set_skill("hellfire-whip",level);
  ob->set_skill("zhuihun-sword", level);
  ob->set_skill("dodge", level);
  ob->set_skill("ghost-steps", level);
  ob->set_skill("parry", level);
  ob->set_skill("spells", level);
  ob->set_skill("force", level);
  ob->map_skill("sword", "zhuihun-sword");
  ob->map_skill("parry", "zhuihun-sword");
  ob->map_skill("dodge", "ghost-steps");
  ob->map_skill("unarmed", "jinghun-zhang");
  ob->map_skill("force", "tonsillit");
  ob->map_skill("whip", "hellfire-whip");
  ob->map_skill("spells", "gouhunshu");
}  
//8
void wdd (object ob, int level)
{
  ob->set_skill("unarmed", level);
  ob->set_skill("dodge", level);
  ob->set_skill("parry", level);
  ob->set_skill("stealing", level);
  ob->set_skill("spells", level);
  ob->set_skill("sword", level);
  ob->set_skill("qixiu-jian", level);
  ob->set_skill("yinfeng-zhua", level);
  ob->set_skill("lingfu-steps", level);
  ob->set_skill("force", level);
  ob->set_skill("blade", level);
  ob->set_skill("kugu-blade", level);
  ob->set_skill("yaofa", level);
  ob->set_skill("huntian-qigong", level);
  ob->map_skill("force", "huntian-qigong");
  ob->map_skill("blade", "kugu-blade");
  ob->map_skill("unarmed", "yinfeng-zhua");
  ob->map_skill("spells", "yaofa");
  ob->map_skill("sword", "qixiu-jian");
  ob->map_skill("parry", "qixiu-jian");
  ob->map_skill("dodge", "lingfu-steps");
}  
//9
void putuo (object ob, int level)
{
  ob->set_skill("literate", level);
  ob->set_skill("spells", level);
  ob->set_skill("buddhism", level);
  ob->set_skill("unarmed", level);
  ob->set_skill("jienan-zhi", level);
  ob->set_skill("dodge", level);
  ob->set_skill("lotusmove", level);
  ob->set_skill("parry", level);
  ob->set_skill("force", level);
  ob->set_skill("lotusforce", level);
  ob->map_skill("spells", "buddhism");
  ob->map_skill("unarmed", "jienan-zhi");
  ob->map_skill("dodge", "lotusmove");
  ob->map_skill("force", "lotusforce");
}  
//10
void fc (object ob, int level)
{
  ob->set_skill("literate", level);
  ob->set_skill("unarmed", level);
  ob->set_skill("dodge", level);
  ob->set_skill("parry", level);
  ob->set_skill("stick", level);
  ob->set_skill("sword", level);
  ob->set_skill("liangyi-sword", level);
  ob->set_skill("spells", level);
  ob->set_skill("dao", level);
  ob->set_skill("puti-zhi", level);
  ob->set_skill("wuxiangforce", level);
  ob->set_skill("force", level);
  ob->set_skill("qianjun-bang", level);
  ob->set_skill("jindouyun", level);
  ob->map_skill("spells", "dao");
  ob->map_skill("unarmed", "puti-zhi");
  ob->map_skill("force", "wuxiangforce");
  ob->map_skill("stick", "qianjun-bang");
  ob->map_skill("parry", "qianjun-bang");
  ob->map_skill("dodge", "jindouyun");
  ob->map_skill("sword", "liangyi-sword");
}  
//11
void hyd (object ob, int level)
{
  ob->set_skill("unarmed", level);
  ob->set_skill("dodge", level);
  ob->set_skill("force", level);
  ob->set_skill("parry", level);
  ob->set_skill("spear", level);
  ob->set_skill("spells", level);
  ob->set_skill("huoyun-qiang", level);
  ob->set_skill("moshenbu", level);
  ob->set_skill("moyun-shou", level);
  ob->set_skill("huomoforce", level);
  ob->set_skill("pingtian-dafa", level);
  ob->map_skill("force", "huomoforce");
  ob->map_skill("spells", "pingtian-dafa");
  ob->map_skill("unarmed", "moyun-shou");
  ob->map_skill("dodge", "moshenbu");
  ob->map_skill("parry", "huoyun-qiang");
  ob->map_skill("spear", "huoyun-qiang");
}  
//12
void wusheng (object ob, int level)
{
  ob->set_skill("unarmed", level);
  ob->set_skill("dodge", level);
  ob->set_skill("parry", level);
  ob->set_skill("spells", level);
  ob->set_skill("feisheng", level);
  ob->set_skill("literate", level);
  ob->set_skill("sword", level);
  ob->set_skill("wuying", level);
  ob->set_skill("fumobashi", level);  
  ob->set_skill("mizongbu", level);
  ob->set_skill("dodge", level);  
  ob->set_skill("force", level); 
  ob->set_skill("xiantian", level);
  ob->map_skill("spells", "feisheng");
  ob->map_skill("unarmed", "fumobashi");
  ob->map_skill("force", "xiantian");
  ob->map_skill("sword", "wuying");
  ob->map_skill("parry", "wuying");
  ob->map_skill("dodge", "mizongbu");
}  
//13
void moon (object ob, int level)
{
  ob->set_skill("literate", level);
  ob->set_skill("unarmed", level);
  ob->set_skill("dodge", level);
  ob->set_skill("force", level);
  ob->set_skill("parry", level);
  ob->set_skill("sword", level);
  ob->set_skill("spells", level);
  ob->set_skill("moonshentong", level);
  ob->set_skill("baihua-zhang", level);
  ob->set_skill("moonforce", level);
  ob->set_skill("snowsword", level);
  ob->set_skill("moondance", level);
  ob->map_skill("spells", "moonshentong");
  ob->map_skill("unarmed", "baihua-zhang");
  ob->map_skill("force", "moonforce");
  ob->map_skill("sword", "snowsword");
  ob->map_skill("parry", "snowsword");
  ob->map_skill("dodge", "moondance");
}	

void mojie (object ob, int level)
{
  ob->set_skill("literate", level);
  ob->set_skill("unarmed", level);
  ob->set_skill("dodge", level);
  ob->set_skill("force", level);
  ob->set_skill("parry", level);
  ob->set_skill("sword", level);
  ob->set_skill("spells", level);
  ob->set_skill("evilfight", level);
  ob->set_skill("spiritforce", level);
  ob->set_skill("liejiuquan", level);
  ob->set_skill("evilsword", level);
  ob->set_skill("evilmove", level);
  ob->set_skill("yaohu-whip", level);
  ob->set_skill("segokee", level);
  ob->set_skill("evileye", level);
}	
//14
void lg (object ob, int level)
{
  ob->set_skill("huntian-hammer", level);
  ob->set_skill("hammer", level);
  ob->set_skill("literate", level);
  ob->set_skill("unarmed", level);
  ob->set_skill("dodge", level);
  ob->set_skill("force", level);
  ob->set_skill("parry", level);
  ob->set_skill("fork", level);
  ob->set_skill("spells", level);
  ob->set_skill("seashentong", level);
  ob->set_skill("dragonfight", level);
  ob->set_skill("dragonforce", level);
  ob->set_skill("fengbo-cha", level);
  ob->set_skill("dragonstep", level);
  ob->map_skill("hammer", "huntian-hammer");
  ob->map_skill("spells", "seashentong");
  ob->map_skill("unarmed", "dragonfight");
  ob->map_skill("force", "dragonforce");
  ob->map_skill("fork", "fengbo-cha");
  ob->map_skill("parry", "fengbo-cha");
  ob->map_skill("dodge", "dragonstep");
}	
//15
void mojiao (object ob, int level)
{
   ob->set_skill("literate", level);
   ob->set_skill("spells", level);
   ob->set_skill("tianmo", level);
   ob->set_skill("unarmed", level);
   ob->set_skill("tigerfight", level);
   ob->set_skill("dodge", level);
   ob->set_skill("dimo-steps", level);
   ob->set_skill("blade", level);
   ob->set_skill("parry", level);
   ob->set_skill("force", level);
   ob->set_skill("evil-force", level);
   ob->set_skill("sword", level);
   ob->set_skill("nature",level);
   ob->set_skill("tianmo-blade", level);
   ob->set_skill("tianxian-sword", level);
   ob->map_skill("spells", "tianmo");
   ob->map_skill("unarmed", "tigerfight");
   ob->map_skill("dodge", "dimo-steps");
   ob->map_skill("force", "evil-force");
   ob->map_skill("parry", "tianmo-blade");
   ob->map_skill("blade", "tianmo-blade");
   ob->map_skill("sword", "tianxian-sword");
}	