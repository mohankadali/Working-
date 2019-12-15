

node* swap(node **first,node **second)
{
    node *p,*p1,*r,*r1,*temp;
    p=p1=r=r1=temp=start;
    while(p!=*first)
    {
        p1=p;
        p=p->link;
    }
    while(r!=*second)
    {
        r1=r;
        r=r->link;
    }
    temp=r->link;
    r->link=p->link;
    p->link=temp;
    p1->link=r;
    r1->link=p;
    return start;
}
