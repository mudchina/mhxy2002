// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/33tian/33tian
inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

���������ľ�ͷ��̧ͷ��ȥ�������ǰ�ãã��һƬ�����ƴ���ָ��
��������Ľ��¾����칬�ˣ���Լ�ܿ�����������������˿���ϸ裬
�������������������״������û����ҹ֮�֣�ֻ�п����в�ʱ����
�������㣬���˸е�ƽ��������
LONG);
 //  set("outdoors", "sky");
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"west1",
]));

  setup();
}