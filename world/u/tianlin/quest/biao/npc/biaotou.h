void destroying(object me)
{
        destruct(me);
        return;
}
int checking(object me, object ob)
{
        if((int)time() > this_object()->query("temp_time"))
        {
                  call_out("destroying",1,me);
                  return 1;
        }
        else
        {
                 call_out("checking",120, me, ob);
                return 1;
        }
}
