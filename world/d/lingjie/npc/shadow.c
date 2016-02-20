inherit NPC;
string ask_for_leave();
#include <ansi.h>
#include "/d/obj/lquest.h"
#include "/d/lingtai/npc/zhenfa.h"


string ask_mieyao(object me);
string ask_cancel();

void create()
{
        set_name("影子", ({"shadow"}));
        set("gender", "男性" );
        set("age", 1000);
        set("title",MAG"灵界管事"NOR);
        set("long", "只是一个影子。\n");
        set("combat_exp", 5000000);
        set("daoxing", 8000000);
        set("class", "lingjie");

        set("attitude", "peaceful");
        set("per", 40);
        set("max_kee", 3000);
        set("max_gin", 3000);
        set("max_sen", 3000);
        set_skill("umbrella",100);
        set_skill("lingfan-san",100);
        set_skill("parry",200);
        map_skill("umbrella", "lingfan-san");
        map_skill("parry","lingfan-san");
        set("inquiry", ([
                "除魔": (: ask_mieyao :),
                "脱离" : (: ask_for_leave :),
                "leave" : (: ask_for_leave :),
                "cancel": (: ask_cancel :),
                ]) );
        setup();
        carry_object("/d/lingjie/obj/san")->wield();
        carry_object("/d/lingjie/obj/yuyi")->wear();
}

void init()
{
        add_action("do_agree", "agree");
}

string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("没用的东西！");
}
else
{
     return ("你有任务吗？！");
}
}
string ask_for_leave()
{
        object me=this_player();

        if (me->query("family/family_name") == "灵界" ) {
                command("dao2");
                me->set_temp("betray", 1);
                return ("灵界可不是说来就来,说走就走的，你真的愿意(agree)？");
        }

        return ("你说什么呢...\n");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N答道：愿意。\n\n", this_player());
                command("say 既是这样，没人强留你了！");
                this_player()->add("betray/count", 1);
                this_player()->add("betray/moon", 1);
                this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
                this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
                this_player()->delete_skill("kongming-spells");
                this_player()->delete_skill("lingfan-san");
                this_player()->delete_skill("libieyu");
                
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "普通百姓");
                if(this_player()->query("betray/lingjie")) this_player()->add("betray/lingjie",1);
                else this_player()->set("betray/lingjie",1);
                if(this_player()->query("betray/count")) this_player()->add("betray/count",1);
                else this_player()->set("betray/count",1);
                this_player()->save();
                command("chat "+this_player()->query("name")+"离开灵界，从此与灵界再无瓜葛,请各位仙长做个见证！\n");
                command("say 记住,世界上没有对错,只有输赢,强者生存!\n");
                message_vision("影子伸出一只大手抓住$N,甩了出去!\n", this_player());
                this_player()->move("/d/changan/fendui");
                tell_room( environment(this_player()),"啪啪,"+this_player()->query("name")+"重重的摔了下来。\n");

                return 1;
        }
        return 0;
}

string ask_mieyao(object me)
{
    me=this_player();
    if((string)me->query("family/family_name")=="灵界") {
//  if(me->query("faith")<100)
//      return ("你还是先多加修炼为妙。");
    tell_room(environment(me),"影子抬手晃了晃，身体变成一面镜子。\n");
    return "/d/obj/mieyao"->query_yao(me);
    }
    return ("我不知道。");
}

void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("idle");

        ob=present("hufa");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/lingjie/npc/hufa");
                ob->move(environment());
        }
        message_vision("\n忽然从门外冲进来个灵界护法，对$N大喊一声“干什么？你这个臭流氓！\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
