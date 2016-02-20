//By tianlin@Mhxy for 2001.12.30

#include <ansi.h>

inherit F_DBASE;

string *families = ({
  "方寸山三星洞",
  "武当派",
  "轩辕古墓",
  "神剑山庄",
  "月宫",
  "南海普陀山",
  "阎罗地府",
  "将军府",
  "东海龙宫",
  "陷空山无底洞",
  "大雪山",
  "五庄观",
  "蜀山派",
  "武圣门",
  "天蓬帅府",
  "盘丝洞",
  "火云洞",
  "灵界",
  "魔教",
  "天空界",
});
string *masters = ({
 "菩提老祖",
 "张三丰",
 "妲姬",
 "谢晓峰",
 "西王母",
 "观音菩萨",
 "地藏王菩萨",
 "白发老人",
 "敖广", 
 "玉鼠夫人",
 "大鹏明王", 
 "镇元大仙",
 "静虚老祖", 
 "孔武大帝", 
 "猪八戒", 
 "紫霞仙子", 
 "黄飞虎", 
 "八叶的老师", 
 "无恨", 
  "因陀罗",
});
void create()
{
        seteuid(getuid());
        set("name","");
        remove_call_out("choose_npc");
        call_out("choose_npc",10);      

}

void choose_npc()
{
        int i, j ,k,ppl;
        object *list, newob;
        string str;
        list = users();
        i = sizeof(list);

        if (i < 10){
        remove_call_out("choose_npc");
        call_out("choose_npc",60);
        return;
        }

        j = random(sizeof(families));
        k = random(sizeof(families));
        while( i-- ) {
                if (!wizardp(list[i]) && list[i]->query("family/family_name") == families[j]
                && (list[i]->query("combat_exp") + list[i]->query("daoxing"))> 10000 )
                {
                newob = new("/u/tianlin/xinmo/npc");
                newob->set("target",families[k]);
                if(newob->invocation(list[i], k )) ppl++;
                else
                destruct(newob);
                }
        }
        reset_eval_cost();
        if (ppl)
        {
        if (j != k)
        message("system",NOR+HIM"【"NOR+HIW"梦幻西游"NOR+HIM"】"NOR+CYN+masters[k]+"：近有"NOR+HIC+chinese_number(ppl)+NOR+CYN"名"
        NOR+RED+families[j]+NOR+CYN"弟子跑到"NOR+HIY+families[k]+NOR+CYN"地头来挑衅滋事，本门弟子请速回灭之！\n"NOR,users());
        else
        message("system",NOR+HIM"【"NOR+HIW"梦幻西游"NOR+HIM"】"NOR+CYN+masters[k]+"：听说有"NOR+HIC+chinese_number(ppl)+NOR+CYN"名"
        NOR+HIY+families[j]+NOR+CYN"不孝弟子在本门闹事。请本门弟子速回清理门户!\n"NOR,users());
        remove_call_out("choose_npc");
        call_out("choose_npc",240);
        }
        else
        {
        message("system",NOR+HIM"【"NOR+HIW"梦幻西游"NOR+HIM"】"NOR+CYN"各大门派最近似乎很平静，但这恐怕是个不祥的预兆。。。\n"NOR,users());
        remove_call_out("choose_npc");
        call_out("choose_npc",60);
        }
}

