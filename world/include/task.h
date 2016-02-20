//By waiwai@mszj 2000/12/02
//设置为exp>500万的玩家不能接task任务

void init()
{
        object ob = this_player();
        if( interactive(environment()) &&
            environment()->query("combat_exp") > 5000000 &&random(5) == 2 )
        {
         tell_object(ob,this_object()->name()+"转眼就不见了!\n");
        remove_call_out("des");
        call_out("des",1); 
       }
}
void des()
{
        destruct(this_object());
}
