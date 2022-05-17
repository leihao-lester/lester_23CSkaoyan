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

void sort(LinkList &L)
{
    LNode *p = L->next,*pre;
    LNode *r = p->next;
    p->next = NULL;
    p = r;
    while(p != NULL)
    {
        r = p->next;
        pre = L;
        while(pre->next != NULL && pre->next->data < p->data)
        {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
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
    sort(L);
    LNode *p = L->next;
    while (p!= NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}