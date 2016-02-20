//book by yushu 2001.2
inherit ITEM;
int do_read(string arg);
void create()
{
        set_name("〖蜀山仙术〗", ({"shushan spells","book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
	  set("long",
	"上面写了密密麻麻的字,看来象是关于蜀山仙风云体术的术。\n");
        set("material", "paper");
        set("value", 1000);
        set("skill", ([
                        "name": "xianfeng-spells",
                        "exp_required": 1000,
                        "sen_cost": 30,
                        "difficulty": 30,
                        "max_skill": 50,
]) );
          }
}
void init()
{
    add_action("do_read", "read");
}
int do_read(string arg)
{
    object me=this_player();
    if(me->query("family/family_name")!="蜀山派")
        return notify_fail("不是蜀山的不能读这本书！\n");
}
