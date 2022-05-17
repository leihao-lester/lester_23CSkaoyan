#include<stdio.h>
#include<stdlib.h>
using namespace std;
#include<iostream>
#define ElemType int

typedef struct LNode
{
    ElemType data;
    LNode* next;
}LNode,*LinkList;


LinkList InitList()
{
    LinkList L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    return L;
}

// 头插法建立单链表
LinkList List_HeadInsert(LinkList &L)
{
    LNode *p;
    int x;
    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    cin>>x;
    while(x != 9999)
    {
        p = (LNode*) malloc(sizeof(LNode));
        p->data = x;
        p->next = L->next;
        L->next = p;
        cin>>x;
    }
    return L;
}

// 尾插法建立单链表
LinkList List_TailInsert(LinkList &L)
{
    int x;
    L = (LinkList) malloc(sizeof(LNode));
    LNode *p, *r=L;
    cin>>x;
    while(x != 9999)
    {
        p = (LNode*) malloc(sizeof(LNode));
        p->data = x;
        r->next = p;
        r = p;
        cin>>x;
    }
    r->next = NULL;
    return L;
}

// 按序号查找结点
LNode* GetElem(LinkList L,int i)
{
    LNode *p = L->next;
    if(i < 1) return NULL;
    int j = 1;
    while (p)
    {
        if(j == i) return p;
        j++;
        p = p->next;
    }
    return NULL;
}

// 按值查找表结点
LNode* LocateElem(LinkList L,int e)
{
    LNode *p = L->next;
    while(p)
    {
        if(p->data == e) return p;
        p = p->next;
    }
    return NULL;
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

// 删除第i个位置的元素
bool ListDelete(LinkList &L, int i, int &e)
{
    if(i<1) return false;
    int j = 0;
    LNode * p = L;
    while(p!=NULL && j < i-1)
    {
        p = p->next;
        j++;
    }
    if(p == NULL) return false;
    LNode* tmp = p->next;
    e = tmp->data;
    p->next = p->next->next;
    free(tmp);
    return true;
}

int main()
{
    LinkList L = InitList();
    // L = List_HeadInsert(L);
    L = List_TailInsert(L);
    // for(int i=0;i<5;i++)
    // {
    //     int tmp;
    //     scanf("%d",&tmp);
    //     ListInsert(L,1,tmp);
    // }
    // ListInsert(L,3,99);
    // int e;
    // ListDelete(L,5,e);

    LNode *p = L->next;
    while (p!= NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}
