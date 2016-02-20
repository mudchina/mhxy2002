// greenhat.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(GRN"绿帽子"NOR, ({ "hat", "maozi" }) );
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "顶");
                set("long","这是一顶人见人怕的帽子，可是有时你又只好带着它。\n");
                set("material", "hat");
                set("wear_msg","$N很不情愿地带上一顶$n。\n");
                set("remove_msg","$N很快乐地摘下一顶$n。\n");
                set("armor_prop/armor", 1);
        }
        setup();
}

void init()
{
        add_action ("do_give", "give");
}

int do_give(string arg)
{
        object me, ob, who;
        string wiz, obs, whos;

        me = this_player();
        if (sscanf(arg, "%s to %s", obs, whos) != 2) return 0;
        if (obs != "hat" && obs != "maozi") return 0;
  
        ob = present ("hat", me);
        if (!ob) write ("好可怜啊，你没有送别人"GRN"绿帽子"NOR"的能力！\n");
        who = find_player(whos);
        if (!who) write ("没有这个人。\n");
        if (ob && who) {
                ob->move (who);
                message_vision ("$N送给$n一顶"GRN"绿帽子"NOR"戴。\n", me, who);
        }
        return 1;
}