
inherit ROOM;
string *names=({
	__DIR__"tt7",
	__DIR__"tt1",
	__DIR__"tt5",
	__DIR__"tt6",
} );
void create()
{
	set("short", "巨树林中");
	set("long", @LONG
在这些千年古木下，已经让人辩不清方向了，只听得脚下踩在落叶上沙沙的声音。
LONG
	);
	setup();
}
void reset()
{
	int i,j;
	string temp;
	::reset();
	for (i=0;i<=3;i++)
	{
		j=random(4);
		temp=names[j];
		names[j]=names[i];
		names[i]=names[j];
		names[i]=temp;
	}
	set("exits", ([
		"north" : names[0],
		"south" : names[1],
		"east" : names[2],
		"west" : names[3],
	]));
}
