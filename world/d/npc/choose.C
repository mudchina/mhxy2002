// modi by xintai 2/15/01

#include <ansi.h>

inherit F_DBASE;

string *families = ({
  "大雪山",
  "方寸山三星洞",
  "月宫",
  "南海普陀山",
  "阎罗地府",
  "盘丝洞",
  "将军府",
  "东海龙宫",
  "陷空山无底洞",
  "五庄观",
  "火云洞",
  "蜀山派",
  "武圣门",
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
        string str,m_name;
        list = users();
        i = sizeof(list);

        if (i < 10){
        remove_call_out("choose_npc");
	call_out("choose_npc",120);
        return;
        }

        j = random(sizeof(families));
        k = random(sizeof(families));
        while( i-- ) {
                if (!wizardp(list[i]) && list[i]->query("family/family_name") == families[j]
                && (list[i]->query("combat_exp") + list[i]->query("daoxing"))> 10000 )

                {
                newob = new(__DIR__"npc");
                newob->set("target",families[k]);
                if(newob->invocation(list[i], k ))
                ppl++;
                else
                destruct(newob);
                }
        }
        
        reset_eval_cost();
        
        switch(families[k])
        {
                case "方寸山三星洞":
                        m_name="菩提老祖(Master puti)";
                        break;
                case "月宫":
                        m_name="西王母(Xi wangmu)";
                        break;
                case "阎罗地府":
            		m_name="地藏王菩萨(Dizang pusa)";
                        break;
                case "陷空山无底洞":
                        m_name="玉鼠精(Yu shu)";
                        break;
                case "将军府":
                        m_name="秦琼(Qin qiong)";
                        break;
                case "火云洞":
                        m_name="牛魔王(Niumo wang)";
                        break;
                case "大雪山":
                        m_name="大鹏明王(Dapeng mingwang)";
                        break;
                case "五庄观":
                        m_name="镇元大仙(Zhenyuan daxian)";
                        break;
                case "南海普陀山":
                        m_name="观音菩萨(Guanyin pusa)";
                        break;
                case "东海龙宫":
                        m_name="敖广(Ao guang)";
                        break;
                case "盘丝洞":
                        m_name="青霞仙子(Qingxia xianzi)";
                        break;
                case "蜀山派":
                        m_name="李逍遥(Li xiaoyao)";
                        break;
                case "武圣门":
                        m_name="孔武大帝(Master_dadi)";
                        break;

        }
        if (ppl)
        {
        if (j != k)
        message("system",HIG"【"+families[k]+"】"+m_name+"：有"+chinese_number(ppl)+"名"+families[j]+"弟子正在攻打本派，本派弟子速回灭之。\n"NOR,users());
        else
        message("system",HIG"【"+families[k]+"】"+m_name+"：本派"+chinese_number(ppl)+"名不孝弟子，在本派闹事，众弟子速回护法。\n"NOR,users());
        remove_call_out("choose_npc");
	call_out("choose_npc",300);
        }
        else
        {
        message("system",HIG"太白金星「唉」的一声叹了口气。\n"NOR,users());
        message("system",HIG"太白金星(Tai bai)：不知道什么时候才能实现真正的和平啊？\n"NOR,users());
        remove_call_out("choose_npc");
	call_out("choose_npc",60);
        }
}
