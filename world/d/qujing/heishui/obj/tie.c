inherit ITEM;

void create()
{
        set_name("信帖", ({"letter", "xin tie"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long",
"这是张以天蚕洁丝所织的信帖，上面以云霞彩丝绣着几行字：\n"
"\n"

"     愚甥近日偶得东土僧人唐僧，闻其乃十世修行之体，\n" 
"     食其肉者可长生不老，愚不敢独享，恭请舅父大人\n" 
"     光临寒舍，同席举杯，共享长生。\n" 
"\n"
"                                          愚甥顿首\n");
                set("material", "paper");
        }
  set("is_monitored",1);
  setup();
}

