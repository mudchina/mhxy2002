// BY LANDIS@MYTH
// 2002.02.06

#include <ansi.h>
#include <mudlib.h>

inherit F_DBASE;
inherit F_SAVE;

/**********************************************
mapping topten = ([
        "type1"  :     ([
                "id1"   :     ([
                        "name"  :    name,
                        "value" :    value,
                        ]),
                "id2"   :     ([
                        "name"  :    name,
                        "value" :    value,
                        ]),
                ]),
        ]);
***********************************************/

mapping topten;
mapping direct;

static mapping types = ([
        "dx"    :       HIW"道行高手（DX）",
        "exp"   :       HIM"武学高手（EXP）",
        "age"   :       HIC"江湖寿星（AGE）",
        "die"   :       HIB"悲情人物（DIE）",
        "per"   :       HIM"江湖美女（PER）",
        "hsm"   :       HIG"江湖帅哥（HSM）",
        "nker"  :       HIY"N K 高手（NKER）",
        "pker"  :       HIB"P K 狂魔（PKER）",
        "rich"  :       HIR"江湖富豪（RICH）",
        "mana"  :       NOR CYN"法力高手（MANA）",
        "force" :       NOR WHT"内力高手（FORCE）",
        "quest" :       HIW"解迷高手（QUESTS）",
        ]);

int get_all_data(object, string);
int topten_add(object, string);

void create()
{
        int size;
        string *map;

        seteuid(ROOT_UID);
        set("channel_id", "排行精灵");
        CHANNEL_D->do_channel( this_object(), "sys", "排行系统已经启动。");

        restore();

        if (! mapp(topten))
                topten = ([ ]);

        if (! mapp(direct))
                direct = ([ ]);

        map  = keys(types);
        size = sizeof(map);

        while (size--)
        {
                if (! mapp(topten[map[size]]))
                        topten[map[size]] = ([ ]);
        }
}

string query_save_file()
{
        return DATA_DIR "toptend";
}

void save()
{
        int i, j;
        string id;
        string *ids;
        string *tmp;
        string *key;

        mapping map;
        mapping *maps;

        tmp = keys(types);

        for (i=0; i<sizeof(tmp); i++)
        {
                map = topten[tmp[i]];

                if (mapp(map) && sizeof(keys(map)) > 1)
                {
                        maps = ({ });
                        ids = keys(map);

                        for (j=0; j<sizeof(ids); j++)
                        {
                                map[ids[j]]["id"] = ids[j];
                                maps += ({ map[ids[j]] });
                        }

                        map = ([ ]);
                        key = ({ });
                        maps = sort_array(maps, "sort_value");


                        for (j=0; j<sizeof(maps); j++)
                        {
                                id   = maps[j]["id"];
                                map_delete(maps[j], "id");

                                key += ({ id });
                                map[id] = maps[j];
                        }

                        direct[tmp[i]] = key;
//                      topten[tmp[i]] = map;
                }
        }

        ::save();
}

int topten_checkplayer(object player)
{
        int i;
        int flag;
        string *tmp;

        flag = 0;
        tmp  = keys(types);
        i    = sizeof(tmp);

        while (i--)
        {
                if (topten_add(player, tmp[i]))
                        flag ++;
        }

        save();

        if (flag == sizeof(tmp))
                return 1;

        return 0;
}

string query_type()
{
        int i;
        string str;
        string tmp;
        string msg;
        string *key;

        str  = HIW + INTERMUD_MUD_NAME + " 现有以下类型的排行榜：\n";
        str += HIB + "━━━━━━━━━━━━━━━━━━━━━━\n";
        msg  = "　：　" + HIW + INTERMUD_MUD_NAME + " ";

        key = keys(types);

        for (i=0; i<sizeof(key); i++)
        {
                tmp  = HIR + sprintf("%-4s", chinese_number(i+1)) + msg;
                tmp += types[key[i]];
                tmp += "\n";

                str += tmp;
        }

        str += HIB + "━━━━━━━━━━━━━━━━━━━━━━\n" + NOR;

        return str;
}

string topten_query(string type)
{
        int i;
        string str;
        string id, name;
        string *ids;
        mapping map;

        if (member_array(type, keys(types)) == -1)
                return WHT"没有此类型的排行榜。\n"NOR;

        str  = HIW + INTERMUD_MUD_NAME + " 十大 ";
        str += types[type] + "\n";
        str += HIB + "──────────────\n" + NOR;

        ids = direct[type];
        map = topten[type];

        if (! mapp(map) || sizeof(keys(map)) < 10)
                return WHT"此类型排行榜数据尚未收集完全。\n"NOR;

        for (i=0; i<sizeof(ids); i++)
        {
                str += WHT + "第 ";
                str += HIY + chinese_number(i+1) + NOR;
                str += WHT + " 名  ";

                id   = ids[i];
                name = map[id]["name"];

                str += name + "(" + capitalize(id) + ")";
                str += "\n" + NOR;
        }

        str+= HIB + "──────────────\n" + NOR;

        return str;
}

int topten_del(string id, string type)
{
        string *tmp;
        mapping dir;

        tmp = keys(topten);
        if (member_array(type, tmp) == -1)
                return notify_fail(WHT + "没有" + type + "这种排行榜！\n" + NOR);

        dir = topten[type];
        map_delete(dir, id);

        save();
        return 1;
}

int topten_add(object player,string type)
{
        int val;
        int size;
        string *tmp;
        string id, name;
        mapping value;
        mapping map;

        tmp = keys(types);

        if (! userp(player) || wizardp(player))
                return 0;

        if (member_array(type, tmp) == -1)
                return notify_fail(WHT + "没有" + type + "这种排行榜！\n" + NOR);

        if (! mapp(topten[type]))
                topten[type] = ([]);

        name = player->name();
        id   = player->query("id");

        if (get_all_data(player,type) > 0)
                val = get_all_data(player,type);
        else
                return notify_fail(WHT"查询类型错误，请核对。\n"NOR);

        map = ([ ]);
        map["name"]  = name;
        map["value"] = val;

        value = topten[type];
        value[id] = map;

        tmp  = keys(value);
        size = sizeof(tmp);

        if (size > 10)
        {
                while (size--)
                {
                        map = value[tmp[size]];

                        if (map["value"] <= val)
                        {
                                map_delete(value, tmp[size]);
                                break;
                        }
                }
        }                                

        topten[type] = value;
        return 1;
}

int get_all_data(object player, string type)
{
        int total;
        mapping my;

        my = player->query_entire_dbase();

        switch(type)
        {
                case "rich":
                        total = my["balance"] + my["money"];
                        break;
                case "quests":
                        total = my["quest/number"] + my["TASK"];
                        break;
                case "pker":
                        total = my["PKS"];
                        break;
                case "nker":
                        total = my["MKS"];
                        break;
                case "exp":
                        total = my["combat_exp"];
                        break;
                case "dx":
                        total = my["daoxing"];
                        break;
                case "force":
                        total = my["max_force"];
                        break;
                case "age":
                        total = my["mud_age"];
                        break;
                case "hsm":
                        if (my["gender"] != "男性")
                                total = -1;
                        else
                                total = my["per"];
                        break;
                case "per":
                        if (my["gender"] != "女性")
                                total = -1;
                        else
                                total = my["per"];
                        break;
                case "mana":
                        total = my["max_mana"];
                        break;
                default:
                        total = -1;//用-1标志类型出错！
        }

        return total;
}

int sort_value(mapping map1, mapping map2)
{
        int num1, num2;

        num1 = map1["value"];
        num2 = map2["value"];

        if (num1 > num2) return -1;
        if (num1 < num2) return  1;

        return 0;
}

