// jiuhua.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(WHT "����ͨ����" NOR, ({"tongmai dan", "dan"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ҩ�裬����ȥ��������������"
                            "����һ�㣬ʵ��Ч����������ʥҩ��\n");
                set("unit", "��");
                set("value", 4000);
                set("weight", 85);
set("base_unit","��");/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "chuanwu"  : 1,
                                    "honghua"  : 1,
                                    "dangui"   : 1,
                                    "chenpi"   : 1,
                                    "moyao"    : 1,
                                    "shengdi"  : 1,
                                    "yjhua"    : 1,
                                    "heshouwu" : 1,
                                    "renshen"  : 1,
                                    "lurong"   : 1, ]),
                        "neili" : 150,
                        "jing"  : 40,
                        "time"  : 5,
                        "min_level" : 120,
                        "medical" : 150,
                ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();

        if(! arg || arg!="tongmai dan")
                {
                write("��ʹ��ʲôҩ��\n");
                return 1;
                }
        if (time() - me->query_temp("last_eat/tongmai") < 60)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        my = me->query_entire_dbase();
        if (my["eff_kee"] == my["max_kee"])
        {
                write("�����ڲ�û�����ˣ����ط���" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/tongmai", time());

        message_vision(WHT "$N" WHT "��" + name() +
                       WHT "����һ�������˶ǣ�������ɫ�������ö��ˡ�\n" NOR, me);

        me->receive_curing("kee", 100);
        me->receive_heal("kee", 100);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}