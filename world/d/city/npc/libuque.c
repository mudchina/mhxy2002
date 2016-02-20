inherit NPC;
 
void do_drink();
 
void create()
{
        seteuid(getuid());
        set_name("¿Ó≤ª»±", ({"libu que", "que"}));
        set("long", "”–¡À¿Ó≤ª»±, ≤√¥∂º≤ª≥Ó°£\n");
        set("gender","ƒ––‘");
	set("title", "±¯∆˜∑∑◊”");
	set("class", "scholar");
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
        set("combat_exp",600000);
        set("attitude","heroism");
        set("chat_chance",20);
        set("chat_msg", ({
        "¿Ó≤ª»±µÕ…˘Àµµ¿£∫Œ“µƒ“–ÃÏΩ£Õ˛¡¶Œﬁ±»°£\n",
        "¿Ó≤ª»±µÕ“˜µ¿£∫Œ“À‰»ª«Æ≤ª∂‡,µ´ «∏¸–¬“ª¥ŒŒ“æÕ”–“ª∞Ÿ¡Ωª∆Ω“≤≤ª¥Ì°£\n",
        "¿Ó≤ª»±∏ﬂ–Àµƒ≥™∆∏Ë¿¥£∫“ª ∂˛ »˝ Àƒ ŒÂ …œ…Ω¥Ú¿œª¢°£\n",
        "¿Ó≤ª»±≥§“˜µ¿£∫«Ó—Ω,√ª«Æ—Ω,À≠ƒ‹∏¯Œ“µ„«Æ!\n",
	(: random_move :)
        }));

        set("chat_chance", 90);

        set_skill("dodge", 90);
        set_skill("force", 90);
        set_skill("parry", 90);
        set_skill("unarmed", 90);
        set_skill("sword", 90);
        set_skill("literate", 120);
	set("max_force", 2000);
	set("force", 2000);
	set("force_factor", 1000);
        set("max_kee", 2000);
        set("max_gin", 4000);
        set("max_sen", 2000);

        setup();
        carry_object("/d/obj/armor/jinsijia")->wear();
        carry_object("/d/obj/weapon/sword/yitian")->wield();
	carry_object("d/obj/cloth/monkcloth")->wear();
	carry_object("d/obj/cloth/shoupipifeng")->wear();
	carry_object("d/lingtai/obj/shoe")->wear();
	carry_object("d/qujing/tianzhu/obj/tiekui")->wear();
        add_money("gold", 100);
}
 
void do_drink()
{
    object *list, ob;
    int i, can_drink;
    if ((int)this_object()->query("water") >= 380) return;
    list = all_inventory(this_object());
    i = sizeof(list);
    can_drink = 0;
    while (i--) {
        if ((string)list[i]->query("liquid/type") == "alcohol") {
            ob = list[i];
            can_drink = 1;
        }
    }
    if (can_drink) {
        command("drink "+(string)ob->query("id"));
        if ((int)ob->query("liquid/remaining") == 0)
            command("drop "+(string)ob->query("id"));
    }
    else {
        command("sigh");
        command("say «Ó—Ω...«Ó—Ω! ");
    }
    return;
}

int accept_object(object who, object ob)
{	object m;
	m=new("/d/obj/book/jianpu.c");
    if ((string)ob->query("liquid/type")=="alcohol")
    {
        if ((int)ob->query("liquid/remaining") == 0)
        {
            command("shake");
            command("say ø’µƒŒ“≤ª“™£Æ£Æ£Æ");
            return notify_fail("∫√œÛ¿Ó≤ª»±≤ª « ’∆∆¿√µƒ£¨≤ª“™ø’∆ø◊”°£\n");
        }
        else
                if ( (string)ob->name()=="≈£∆§æ∆¥¸" )
                {
                        command ("frown");
                        command ("say ’‚æ∆ªπ «ƒ˙¡Ù◊≈◊‘º∫∫»∞…°£");
                        return
notify_fail("∫√œÛ¿Ó≤ª»±ø¥≤ª∆ƒ„∏¯À˚µƒæ∆°£\n");
                }
                else
                {
                        command("smile");
                        command("say ∂‡–ª!");
			if ((int)who->query_temp("mark/¿Ó≤ª»±") < 1){
			who->set_temp("mark/¿Ó≤ª»±", 1 ); 
			}
                        if(present("jian pu", this_object())) {
			return 0;
			}
                        who->add_temp("mark/¿Ó≤ª»±", 1 );
                        call_out("destroy", 1, ob);
                if ((int)who->query_temp("mark/¿Ó≤ª»±") >= 5+random(5))
                        {
command ( "whisper " + who->query("id") + 
" Œ“ø¥ƒ˙“≤ «Œª¡∑π¶œ∞Œ‰µƒ»À£¨“≤À„‘€√«”–‘µ£¨’‚±æΩ£∆◊æÕÀÕ∏¯ƒ„ƒ√»•—–∂¡∞…°£\n");
				m->move(who);
                                who->set_temp("mark/¿Ó≤ª»±", 0 );
				return 1;
                        }
                        return 1;
                }
        }
    }

void destroy(object ob)
{
        destruct(ob);
        return;
}

ˇ