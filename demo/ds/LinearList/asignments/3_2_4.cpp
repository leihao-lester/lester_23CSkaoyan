#include<iostream>
using namespace std;
typedef struct LNode
{
    int data;
    LNode *next;
}LNode, *LinkList;

LinkList InitList()
{
    LinkList L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    return L;
}

// 在第i个位置插入元素e
bool ListInsert(LinkList &L, int i, int e)
{
    if(i<1)
        return false;
    LNode *p = L;
    int j=0;
    while(p!=NULL && j<i-1)
    {
        p = p->next;
        j++;
    }
    if(p == NULL)
        return false;
    LNode *tmp = (LNode *) malloc(sizeof(LNode));
    tmp->next = p->next;
    tmp->data = e;
    p->next  = tmp;
    return true;
}

void DelMin(LinkList &L)
{
    LNode *p = L->next;
    if(p == NULL) return;
    if( p->next == NULL)
    {
        free(p);
        L->next = NULL;
        return ;
    }
    int vmin = p->data;
    LNode *premin = L;
    LNode *pre = L;
    while (p)
    {
        if(p->data < vmin)
        {
            premin = pre;
            vmin = p->data;
        }
        pre = p;
        p = p->next;
    }
    LNode *tmp = premin->next;
    premin->next = tmp->next;
    free(tmp);
}


int main()
{
    LinkList L = InitList();
    for(int i=0;i<5;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        ListInsert(L,1,tmp);
    }
    DelMin(L);

    LNode *p = L->next;
    while (p!= NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}