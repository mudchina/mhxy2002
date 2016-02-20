// yingke.c       created 17-06-2001 piao
#include <ansi.h>


inherit NPC;

void create()
{
        set_name("小伙计", ({"huoji"}));
        set("gender", "男性" );
        set("age", 13);
        set("title", HIR"万梅山庄迎客"NOR);
        set("long", "一个门童，每天负责在庄门前迎接远道而来的客人．\n");
        set("combat_exp", 200);
        set("attitude", "friendly");
        set_skill("dodge", 10);
        set("per", 30);
        set("max_kee", 150);
        set("max_gin", 150);
        set("max_sen", 150);
        setup();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting()
        && !this_player()->query("env/invisibility") ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "小伙计说道：这位" + RANK_D->query_respect(ob) +
"，欢迎到我们万梅山庄来，您是来拜见我们庄主西门吹雪的吧！\n");
}

