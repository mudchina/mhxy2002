//EDIT BY LUCAS
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG 
�����Ǻ��񸮵�ʯ�ҡ������������ţ����㨡�����
ȴ���������ӣ����������������������߰���������
��С�������ڵ��ϲ���ˣ�ӡ�
LONG);

  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"zhongtang",
  "west" : __DIR__"dayuan",
]));

        set("objects", ([
                __DIR__"npc/guai" : 3,
        ])); 

        setup();
} 
