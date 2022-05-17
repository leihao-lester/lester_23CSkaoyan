#include<iostream>
using namespace std;
typedef struct LNode
{
    int data;
    LNode *next;
}LNode, *LinkList;

LinkList List_HeadInsert(LinkList &L)
{
    LNode *p;
    int x;
    L = NULL;
    cin>>x;
    while (x != 9999)
    {
        p = (LNode*) malloc(sizeof(LNode));
        p->data = x;
        p->next = L;
        L = p;
        cin>>x;
    }
    return L;
}

LinkList List_TailInsert(LinkList &L)
{
    LNode *p,*r;
    int x,i=1;
    L = NULL;
    r = L;
    cin>>x;
    while(x != 9999)
    {
        p = (LNode*) malloc(sizeof(LNode));
        p->data = x;
        if(i != 1) r->next = p;
        if(i == 1) L = p; // 易错
        r = p;
        cin>>x;
        i = 2;
    }
    r->next = NULL;
    return L;
}

bool ListInsert(LinkList &L, int i, int e)
{
    if(i<1) return false;
    if(i == 1)
    {
        LNode* p = (LNode*) malloc(sizeof(LNode));
        p->data = e;
        p->next = L;
        L = p;
        return true;
    }
    int j = 1;
    LNode *p = L;
    while(p != NULL && j<i-1)
    {
        p = p->next;
        j++;
    }
    if(p == NULL) return false;
    LNode* tmp = (LNode*) malloc(sizeof(LNode));
    tmp->data = e;
    tmp->next = p->next;
    p->next = tmp;
    return true;
}

bool ListDelete(LinkList &L, int i, int &e)
{
    if(i < 1) return false;
    if(i == 1)
    {
        LNode *p = L;
        e = L->data;
        L = L->next;
        free(p);
        return true;
    }
    LNode *p = L;
    int j = 1;
    while(p != NULL && j < i-1)
    {
        p = p->next;
        j++;
    }
    if(p == NULL) return false;
    LNode *tmp = p->next;
    e = tmp->data;
    p->next = tmp->next;
    free(tmp);
    return true;
}

int main()
{
    LinkList L;
    // L = List_HeadInsert(L);
    L = List_TailInsert(L);
    // ListInsert(L, 1, 100);
    int e;
    ListDelete(L,3,e);
    cout<<"e:"<<e<<endl;
    LNode *p = L;
    while (p!= NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}