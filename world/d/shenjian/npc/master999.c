// LLY@FYSY
#include <ansi.h>

inherit NPC;
int send_letter();

//int wieldsword();
void create()

{
        
        set_name("谢晓峰", ({ "master xie", "xie xiaofeng", "master","xie"  }) );

        set("long",
"谢晓峰五岁学剑,十六岁剑成,十九岁败华少坤,一手清风细雨温柔剑法当世无双
更兼风度潇洒绝伦,得七星塘慕容秋荻芳心,惹来一生情债．．\n");
        
        set("nickname", HIG"剑神"NOR);
        set("attitude", "heroism");
        create_family("神剑山庄",1,"庄主");
        set("str", 50);
        set("cor", 40);
        set("cps", 40);
	 set("agi",40);
	 set("int",40);
        set("combat_exp", 8000000);
        set("daoxing", 4000000);
	 
        set("max_force", 5600);
        set("force", 5600);
        set("max_mana", 6000);
        set("mana", 6000);
        set("force_factor", 100);
        set("inquiry", ([
		"apprentice" : (: send_letter :),
	        "拜师" : (: send_letter :), ]));
        set("chat_chance_combat", 15);

        set("chat_msg_combat", ({
 "谢晓峰叹道：神剑山庄现在还好吗？\n",

"谢晓峰仰望天空，又叹了一口气。\n",
	     }) );

                set("chat_chance", 15);

                 set("chat_msg_combat", ({
           //     (: wieldsword  :),
        }) );
        set_temp("apply/damage",500);
	 set_skill("sword",280);
	 set_skill("force",300);
        set_skill("parry",300);
        set_skill("dodge",300);
        set_skill("unarmed",300);
	 set_skill("cloudforce",290);
        set_skill("literate",170);
	 set_skill("qingfeng-jian",300);
        set_skill("shadowsteps",300);
	map_skill("dodge","shadowsteps");
	map_skill("force","cloudforce");
	map_skill("sword","qingfeng-jian");
        setup();

        carry_object(__DIR__"obj/letter");
        carry_object(__DIR__"obj/3childe-sword");
        carry_object(__DIR__"obj/sjcloth")->wear();

      //  carry_object(__DIR__"obj/ajiskin")->wear();
}
void attempt_apprentice(object me)
{
        if(me->query_temp("for_shenjian"))
	{
	command("haha");
        command("remove skinmask");
        command("say 好吧，既然你已是我神剑山庄之人，我就收你为徒吧！\n");
        command("recruit " + me->query("id") );
		return;
	}
	else
	{
	command("shake");
        command("say 你别开玩笑的，我哪有资格收你为徒。\n");
	}
	}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shenjian");
}
 
void init()
{add_action("do_look","look");

        }

void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if ( exp <= 512000 ) {
                student->set("title","神剑山庄剑王");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","神剑山庄剑帝");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","神剑山庄剑圣");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","神剑山庄剑魂");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","神剑山庄剑罡");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","神剑山庄剑煞");
                return ;
        } else
                student->set("title","神剑山庄剑仙");
                return ;

}

int accept_fight(object me)
{
        if(me->query("family/family_name") == query("family/family_name") &&
           me->query("family/master_id") == query("id"))
        {
        command("say 好，你赢了我就可以去神剑山庄继续学习更高深的剑术了！\n");
        return 1;
        }
        else
        {
        command("fear");
        command("say 在下自知不是对手，还是不用比了。");
        return 0;
        }
}
void win_enemy(object loser)
{
command("say 你在剑术上的造诣还不够，慢慢来吧！\n");
}
void lose_enemy(object winner)
{
command("say 你的剑术已经在我之上，可以去神剑山庄继续学习更高深的剑术了！。\n");
winner->set_temp("won_master_xie",1);
}


int do_look(string arg)
{
if (arg == "aji" )
{
write("他是这里一个负责打杂的中年汉子,平时大家都管他叫“没用的阿吉”。\n");
write("他看起来约三十多岁。\n");
write("武功看起来好象略有小成，出手似乎极轻。\n");
return 1;
}
return 0;
}
int send_letter()
{
        object letter,me;

	me = this_player();
	say("谢晓峰说道：这位" + RANK_D->query_respect(me) +
		"，如果你想拜我为师，就得随我之姓入我神剑山庄。\n你愿意的话就将此信交与神剑山庄后院小楼之人。\n");
	if( letter = present("letter", this_object())) {
	
	       letter->move(me);
		message_vision(HIY "$N将一封信交给了$n，又开始干活了。\n" NOR, this_object(), me );
	}
        return 1;
}
/*int wieldsword()
{
command("wield sword");
perform_action("sword.yixiao");
command("unwield sword");
return 1;
} */
