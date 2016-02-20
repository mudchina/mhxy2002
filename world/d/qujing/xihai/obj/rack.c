//copy from /d/lintai/obj/rack.c

inherit ITEM;

void create()
{
        set_name("兵器架", ({ "rack" }) );
        set_weight(500000);
        set_max_encumbrance(80000);
        if( clonep() ) {
                object a,b,c,d,e;
                  seteuid(getuid());
                if(a=new("/d/obj/weapon/fork/gangcha"))
                  a->move(this_object());

                  seteuid(getuid());
                if(d=new("/d/obj/weapon/fork/gangcha"))
                  d->move(this_object());

                  seteuid(getuid());
                if(b=new("/d/obj/weapon/hammer/bahammer"))
                  b->move(this_object());

                  seteuid(getuid());
                if(e=new("/d/obj/weapon/hammer/bahammer"))
                  e->move(this_object());

                  seteuid(getuid());
                if(c=new("/d/obj/armor/tiejia"))
                  c->move(this_object());
                set_default_object(__FILE__);
        } else {
                set("unit", "个");
                set("long", "这是一个兵器架，里面插满了各色武器。\n");
                set("value", 0);
        }
}

int is_container() { return 1; }

