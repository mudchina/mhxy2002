// guanjia.c
// 9-2-97 pickle

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int rank_me();
string expell_me(object me);
void create()
{
  set_name("ÌïÊó¾«", ({"tian shu", "tian", "shu", "tianshu", "monster"}));
  set("gender", "Å®ĞÔ");
  set("age", 23);
  set("long",
"Ëı¾ÍÊÇÎŞµ×¶´µÄ´ó¹Ü¼Ò¡£Ïëµ±ÄêËıºÍÓñÊóÒ»ÆëĞŞÏÉ³ÉÁËÈËĞÎ£¬\n"
"µ«Òò×ÊÖÊÌ«²î£¬³ÉÕı¹ûÖÕ¾¿ÊÇÎŞÍû¡£ÕÕ¹Ë×Åµ±ÄêµÄ½»Çé£¬ÓñÊó\n"
"°²ÅÅËı×öÁËÕâ¶´µÄ¹Ü¼Ò¡£\n");
  set("title", "´ó¹Ü¼Ò");
  set("cor", 25);
  set("combat_exp", 400000);
  set("daoxing", 600000);

  set("attitude", "heroic");
  create_family("Ïİ¿ÕÉ½ÎŞµ×¶´", 2, "µÜ×Ó");
  set_skill("literate", 120);
  set_skill("unarmed", 120);
  set_skill("parry", 120);
  set_skill("spells", 120);  
  set_skill("sword", 120);  
  set_skill("qixiu-jian", 120);
  set_skill("yinfeng-zhua", 120);
  set_skill("lingfu-steps", 120);
  set_skill("dodge", 120);
  set_skill("force", 120);
  set_skill("yaofa", 120);
  set_skill("huntian-qigong", 120);
  set_skill("archery", 120);
  set_skill("xuanyuan-archery", 120);
  map_skill("force", "huntian-qigong");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("spells", "yaofa");
  map_skill("sword", "qixiu-jian");
  map_skill("parry", "xuanyuan-archery");
  map_skill("dodge", "lingfu-steps");
  map_skill("archery", "xuanyuan-archery");
  
  set("str", 30);
  set("per", 30);
  set("max_kee", 900);
  set("max_sen", 900);
  set("force", 3000);
  set("max_force", 1500);
  set("force_factor", 75);
  set("mana", 3000);
  set("max_mana", 1500);
  set("mana_factor", 76);
  set("inquiry", ([
                   "ÅÑÃÅ": (: expell_me :),
                   "leave": (: expell_me :),
		   "name": "±¾¹ÃÄï¾ÍÊÇÕâÎŞµ×¶´µÄ´ó×Ü¹Ü£¡",
		   "here": "ÄãÏ¹ÁËÑÛÀ²£¿ÕâÀï¾ÍÊÇ¶¦¶¦´óÃûµÄÏİ¿ÕÉ½ÎŞµ×¶´£¡",
		   "rumors": "²»ÖªµÀ£¡ÕÒ±ğÈËÎÊÈ¥¡£",
		   "ÈËÈâ°ü×Ó": "ÄãÏ¹ÁËÑÛÀ²£¿±¾¹ÃÄïÓÖ²»ÊÇ³ø×Ó£¡",
		   	"Ö°Î»": (: rank_me :),
                 ]) );  
  setup();
  carry_object("/d/obj/weapon/archery/qiankun-bow")->wield();
  carry_object("/d/obj/cloth/yuanxiang")->wear();
  carry_object("/d/obj/cloth/nichang")->wear();
  carry_object("/d/obj/weapon/archery/zhentian-arrow")->wield();
}
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "Ïİ¿ÕÉ½ÎŞµ×¶´ÕÆÃÅ")
		return notify_fail("ÄãÒÑ¾­ÊÇÕÆÃÅÈËÁË£¬»¹À´ÒªÊ²Ã´Ö°Î»£®\n");
        if( (string)me->query("family/family_name") == "Ïİ¿ÕÉ½ÎŞµ×¶´"){
                if( exp <= 100000 ){
                        me->set("title", RED"Ïİ¿ÕÉ½ÎŞµ×¶´"WHT"×êµØÊó¾«"NOR);
                  } else if(exp < 1000000 ){
                        me->set("title", RED"Ïİ¿ÕÉ½ÎŞµ×¶´"WHT"ÈËÈâ³ø×Ó"NOR);
                  } else if(exp < 2000000 ){
                        me->set("title", RED"Ïİ¿ÕÉ½ÎŞµ×¶´"WHT"·­ÌìÊóÍõ"NOR);
                  } else if(exp < 3000000 ){
                        me->set("title", RED"Ïİ¿ÕÉ½ÎŞµ×¶´"WHT"°Ë±ÛòğÉñ"NOR);
                } else {
                        me->set("title", RED"Ïİ¿ÕÉ½ÎŞµ×¶´"WHT"Ç§ÒíòğÊ¥"NOR);
                }

                tell_object(me, "ÌïÊó¾«¶ÔÄãËµ£ºÄã¿ÉÒÔ×ö"+me->query("title")+"¡£\n");
                tell_room(environment(me),
"ÌïÊó¾«¶Ô"+me->query("name")+"Ëµ£ºÄã¿ÉÒÔ×ö"+me->query("title")+"¡£\n", ({me, me}));
         CHANNEL_D->do_channel(me,"chat","ÏÖÊÚÓè±¾ÃÅµÜ×Ó"+me->query("name")+""+me->query("title")+"Ò»Ö°¡£¹§Çë¸÷Î»ÏÉ³¤¶à¼ÓÅõ³¡£¡");
     me->save();  
        }
        return 1;
}
int attempt_apprentice(object me)
{
  string myname=RANK_D->query_rude(me);
  string myid=me->query("id");
  command("look "+myid);
  command("consider");
  if (me->query("combat_exp")+me->query("daoxing")>400000)
  {
    command("say "+myname+"À´¸ÉÊ²Ã´£¿ÏëÀ´ÇÀÀÏÄïµÄÎ»×Ó£¿\n");
    return 1;
  }
  if (me->query("wudidong/sell_reward")<1000)
  {
    command("say "+myname+"ÒªÏëÀ´ÎŞµ×¶´£¬ÏÈÌá¼¸¿ÅÈËÍ·À´Ğ¢¾´ÎÒ£¡\n");
    return 1;
  }
  command("grin");
  command("say ÀÏÄï×î°®³ÔÈËÈâ°ü×ÓÁË¡£"+myname+"±ğÍüÁË¶à¸ø³ø·¿ÅªµãÔ­ÁÏ£¡");
  command("recruit "+myid);
  return 1;
}
int prevent_learn(object me, string skill)
{
  string myname=RANK_D->query_rude(me);

}
string expell_me(object me)
{
  me=this_player();

  if((string)me->query("family/family_name")=="Ïİ¿ÕÉ½ÎŞµ×¶´")
  {
    me->set_temp("wudidong/betray", 1);
    return ("Ê²Ã´£¿ÏëÒªÀë¿ª£¿ÄÇÄã¾Í±ğ¹ÖÀÏÄï³Í·££¡(jieshou)\n");
  }
  return ("ÄãÊÇÄÄÀïÀ´µÄ£¡¹ö£¡\n");
}
void init()
{
    add_action("do_accept", "jieshou");
}
int do_accept(string arg)
{
    object me=this_player();
    if (arg) return notify_fail("ÄãÒª¸ÉÊ²Ã´£¿\n");
    if (!me->query_temp("wudidong/betray")) return notify_fail("ÄãÒª½ÓÊÜÊ²Ã´£¿\n");
    message_vision("$NµÀ£º²»´í£¬ÎÒÒªÀë¿ªÎŞµ×¶´ÕâºÄ×ÓÎÑ£¡\n", me);
    me->add("betray/count", 1);
    me->add("betray/wudidong", 1);
    me->delete("family");
    me->delete("class");
    me->set("title", "ÆÕÍ¨°ÙĞÕ");
    me->set("combat_exp", me->query("combat_exp")*80/100);
    me->set("daoxing", me->query("daoxing")*80/100);
    if (me->query_skill("yaofa"))
    {
        me->delete_skill("yaofa");
	//me->set_skill("yaofa", me->query_skill("yaofa")/2);
	//if (me->query_skill("yaofa")>30) me->set_skill("yaofa", 30);
    }
    if (me->query_skill("huntian-qigong"))
    {
        me->delete_skill("huntian-qigong");
	//me->set_skill("huntian-qigong", me->query_skill("huntian-qigong")/2);
	//if (me->query_skill("huntian-qigong")>30) me->set_skill("huntian-qigong", 30);
    }
    me->save();
    return 1;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob))
  {
    ob->set("class", "yaomo");
  }
}
ÿ
