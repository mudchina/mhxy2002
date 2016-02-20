// By tianlin 2001.5.1
#include <ansi.h>
inherit NPC;
string ask_age()
{
        object me = this_player();
        object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
        int no;
        ob = filter_array(ob,
                (: $2->query("age")*12+$2->query("month")
                        < $1->query("age")*12+$1->query("month") :), me);
        no = sizeof(ob) + 1;
        return me->name()+RANK_D->query_respect(me)+"的年龄在梦幻西游目前中排名第"
                +chinese_number(no)+"。";
}
string ask_beauty()
{
        object me = this_player();
        object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
        int no;
        ob = filter_array(ob,
                (: $2->query("per")     < $1->query("per") :), me);
        no = sizeof(ob) + 1;
        return me->name()+RANK_D->query_respect(me)+"的容貌在梦幻西游目前中排名第"
                +chinese_number(no)+"。";
}
int ask_force()
{
        object me = this_player();
        object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
        int no;
        ob = filter_array(ob,
                (: $2->query("max_force")      < $1->query("max_force") :), me);
        no = sizeof(ob) + 1;
        command("say "+me->name()+RANK_D->query_respect(me)+"的内力在梦幻西游目前中排名第"
                +chinese_number(no)+"。");
        return 1;
}
int ask_spells()
{
        object me = this_player();
        object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
        int no;
        ob = filter_array(ob,
                (: $2->query("max_mana")      < $1->query("max_mana") :), me);
        no = sizeof(ob) + 1;
        command("say "+me->name()+RANK_D->query_respect(me)+"的法力在梦幻西游目前排名第"
                +chinese_number(no)+"。");
        return 1;
}
int ask_pk()
{
        object me = this_player();
        object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
        int no;
        ob = filter_array(ob,
                (: $2->query("PKS")      < $1->query("PKS") :), me);
        no = sizeof(ob) + 1;
        command("say "+me->name()+RANK_D->query_respect(me)+"的杀害玩家数在梦幻西游目前排名第"
                +chinese_number(no)+"。");
        return 1;
}
int ask_mk()
{
        object me = this_player();
        object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
        int no;
        ob = filter_array(ob,
                (: $2->query("MKS")      < $1->query("MKS") :), me);
        no = sizeof(ob) + 1;
        command("say "+me->name()+RANK_D->query_respect(me)+"的杀害ＮＰＣ数在梦幻西游目前排名第"
                +chinese_number(no)+"。");
        return 1;
}
int ask_exp()
{
        object me = this_player();
        object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
        int no;
        ob = filter_array(ob,
                (: $2->query("combat_exp")      < $1->query("combat_exp") :), me);
        no = sizeof(ob) + 1;
        command("say "+me->name()+RANK_D->query_respect(me)+"的武学在梦幻西游目前在线玩家中排名第"
                +chinese_number(no)+"。");
        message_vision(CYN "$N指着$n赞叹道：“"+me->name()+"是梦幻西游中第"
                +chinese_number(no)+"高手！”\n" NOR, this_object(), me);
        return 1;
}
int ask_daoxing()
{
        object me = this_player();
        object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
        int no;
        ob = filter_array(ob,
                (: $2->query("daoxing")      < $1->query("daoxing") :), me);
        no = sizeof(ob) + 1;
        command("say "+me->name()+RANK_D->query_respect(me)+"的道行在梦幻西游目前在线玩家中排名第"
                +chinese_number(no)+"。");
        message_vision(CYN "$N指着$n赞叹道：“"+me->name()+"是梦幻西游中第"
                +chinese_number(no)+"高手！”\n" NOR, this_object(), me);
        return 1;
}

void create()
{
        set_name("水中月",({"lovechao"}));
        set("gender","男性");
        set("age",40);
        set("per", 30);
        set("int", 30);
        set("kar", 30);
        set("str", 20);
        set("cor", 25);
        set("cps", 99);
        set("long", @LONG
一个字：杠~~

 打听年龄用 ask lovechao about age
 打听容貌用 ask lovechao about beauty
打听道行用 ask lovechao about exp
 打听ＰＫ用 ask lovechao about pk
 打听法力用 ask lovechao about spells
打听内力用 ask lovechao about force
 打听杀人用 ask lovechao about mk
 打听道行用 ask lovechao about daoxing
LONG);
        set("daoxing",3000000);
        set("combat_exp", 11112345);
        set("max_force", 5000);
        set("force", 5000);
        set("max_mana", 7000);
        set("mana", 7000);
        set("max_sen", 5000);
        set("sen", 5000);
        set("max_kee", 5000);
        set("kee", 5000);
        set_skill("spells", 412);
        set_skill("dodge", 21);
        set_skill("parry", 44);
        set_skill("force", 4);
        set_skill("literate", 973);
        set("title", "梦幻西游总管");
        set("attitude", "friendly");
        set("inquiry",([
                "spells": (: ask_spells :),
                "force": (: ask_force :),
                "pk": (: ask_pk :),
                "mk": (: ask_mk :),
                "age": (: ask_age :),
                "beauty": (: ask_beauty :),
                "exp": (: ask_exp :),
                "daoxing" : (: ask_daoxing :),
        ]) );
        setup();
    //    carry_object("/d/obj/cloth/jia_sha")->wear();
        
}
