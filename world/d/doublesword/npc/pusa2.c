

inherit NPC;
inherit F_MASTER;

string hesword(object me);

void create()
{
   set_name("惠光菩萨", ({ "huiguang pusa", "guanyin", "pusa" }));
   set("title", "");
   set("long", @LONG
理圆四德，智满金身。眉如小月，眼似双星。兰心欣紫竹，
LONG);
   set("gender", "男性");
   set("age", 35);
   set("attitude", "peaceful");
   set("rank_info/self", "贫僧");
   set("rank_info/respect", "惠光菩萨");
   set("class", "bonze");
           set("str",24);
   set("per",100);//means no rong-mao description.
   set("max_kee", 5000);
   set("max_gin", 5000);
   set("max_sen", 5000);
   set("force", 4000);
   set("max_force", 2000);
   set("force_factor", 200);
   set("max_mana", 3000);
   set("mana", 6000);
   set("mana_factor", 200);
   set("combat_exp", 2000000);
   set_skill("literate", 190);
   set_skill("spells", 200);
   set_skill("buddhism", 200);
   set_skill("unarmed", 160);
   set_skill("jienan-zhi", 160);
   set_skill("dodge", 180);
   set_skill("lotusmove", 160);
   set_skill("parry", 160);
   set_skill("force", 180);
   set_skill("lotusforce", 180);
   set_skill("staff", 180);
   set_skill("lunhui-zhang", 180);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");
   set("chat_chance_combat", 90);
   set("chat_msg_combat", ({
     (: cast_spell, "bighammer" :),
     (: cast_spell, "jinguzhou" :)
   }) );
   set("inquiry",([
      "紫青双剑": (: hesword :),
      "doublesword": (: hesword :),

   ]) );
   create_family("南海普陀山", 1, "菩萨");

   setup();
   carry_object("/d/nanhai/obj/jiasha")->wear();
   carry_object("/d/nanhai/obj/jingu1");
   carry_object("/d/nanhai/obj/nine-ring")->wield();
}
string hesword(object me)
{
    me=this_player();
    if((string)me->query("family/family_name")!="五庄观")
        return ("你不是五庄观弟子，不要知道这个秘密的");
    if(me->query("faith")<1000)
        return ("我看你对五庄观观主还不够忠诚！\n");
     if(me->query("sword_hesword") == 1 ) 
                       {
             message_vision("\n惠光菩萨疑惑地看着你......\n", me);
        return ("我已经告诉你了呀...\n");
                       }
    command("consider");
     if( ! me->query("sword_xiaofeng") == 1 ) 
     return ("你的晓风残月剑法如此不纯熟，怎么用的来这柄剑？\n");
     if( ! me->query("sword_sanqing") == 1 ) 
     return ("你的三清剑法如此不纯熟，怎么用的来这柄剑？\n");
     message_vision("\n\n惠光菩萨点头对$N道：这个秘密我是知道的!", me);
     message_vision("\n惠光菩萨点头对你道：既然是你五庄观观主得意门生，我就告诉你吧.....", me);
          me->set("sword_hesword", 1);
     return ("\n惠光菩萨说道:合剑要心诚,.........\n");
}
