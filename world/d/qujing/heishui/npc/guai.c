inherit NPC;

string *names = ({
  "ÁúÏº¹Ö",
  "½ðÀð¹Ö",
  "ó¦Ð·¹Ö",
  "Äàöú¹Ö",
  "»Æ÷­¹Ö",
  "öùÓã¹Ö",
  "Ë®Éß¹Ö",
  "ÎÚ¹ê¹Ö",
  "²ÝÓã¹Ö",
});

void create()
{
  int i = random(9)+1;
  string str;
  set_name(names[random(sizeof(names))], ({"yao guai", "yao", "guai"}));
  set("gender", "ÄÐÐÔ");
  set("age", 30*i); 
  set("long", "ºÚË®ºÓÑýÍõÊÖÏÂµÄÑý¹Ö¡£\n" );
  set("attitude", "aggressive");
  set("combat_exp", 40000*i);
  set("per", 10);
  set_skill("parry", 15*i);
  set_skill("unarmed", 15*i);
  set_skill("dodge", 15*i);
  set_skill("blade", 15*i);
  set_skill("fork", 15*i);
  set_skill("mace", 15*i);
  set_skill("spear", 15*i);
  set_skill("sword", 15*i);
  set_skill("whip", 15*i);
  set_skill("axe", 15*i);
  set_skill("hammer", 15*i);
  set_skill("rake", 15*i);
  set_skill("stick", 15*i);
  set_skill("staff", 15*i);
  set_skill("dagger", 15*i);
  set("max_sen",100*i);
  set("max_gee",100*i);
  set("max_gin",100*i);
  set("force",100*i);
  set("max_force",100*i);
  set("max_mana",100*i);
  set("force_factor",15*i);
  setup();
  carry_object("/d/obj/armor/tiejia")->wear();
  carry_object("/d/qujing/heishui/obj/boot")->wear();
  str = "/d/qujing/heishui/obj/weapon0";
  str[strlen(str)-1] = '0'+random(5);
  carry_object(str)->wield();
}

