#include<iostream>
using namespace std;
typedef struct LNode
{
    int data;
    LNode* next;
}LNode, *LinkList;

LinkList InitList()
{
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    return L;
}

bool InsertLIst(LinkList &L, int i, int e)
{
    if(i <= 0) return false;
    LNode* p = L;
    int j = 0;
    while(p && j < i-1)
    {
        p = p->next;
        j++;
    }
    if(p == NULL) return false;
    LNode* tmp = (LNode*) malloc(sizeof(LNode));
    tmp->data = e;
    tmp->next = p->next;
    p ->next = tmp;
    return true;
}

// 删除值为x的元素,法一：删除当前结点下一个结点data值为x
void DelX_1(LinkList &L, int x)
{
    LNode* p = L;
    while(p->next)
    {
        if(p->next->data == x)
        {
            LNode* tmp = p->next;
            p->next = tmp->next;
            free(tmp);
        }
        else
        {
            p = p->next;
        }
    }
    
}

// 法二：保存当前结点的前驱结点，然后删除当前结点data值为x
void DelX_2(LinkList &L, int x)
{
    LNode* p = L->next;
    LNode* pre = L;
    while(p)
    {
        if(p->data == x)
        {
            LNode* tmp = p;
            p = p->next;
            pre->next = p;
            free(tmp);
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}


// 法三：采用尾插法建立单链表，建立的过程就是删除x的过程
//       即，建立的时候只筛选出不为x的结点
void DelX_3(LinkList &L, int x)
{
    LNode *p = L->next, *r = L;
    while(p)
    {
        if(p->data != x)
        {
            r->next = p;
            r = r->next;
            p = p->next;
        }
        else
        {
            LNode *q = p;
            p = p->next;
            free(q);
        }
    }
    r->next = NULL;
}


int main()
{
    LinkList L = InitList();
    for(int i = 0; i < 5; i++)
    {
        int tmp;
        cin>>tmp;
        InsertLIst(L, 1, tmp);
    }
    DelX_3(L, 3);
    LNode* p = L->next;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}