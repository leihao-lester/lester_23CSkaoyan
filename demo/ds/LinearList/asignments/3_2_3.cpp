#include<iostream>
using namespace std;
#include<stack>
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

// 法一：链表逆置，头插法
void ReversePrint(LinkList L)
{
    LinkList newL = (LinkList)malloc(sizeof(LNode));
    newL->next = NULL;
    LNode* p = L->next;
    while(p)
    {
        LNode* tmp = (LNode*)malloc(sizeof(LNode));
        tmp->data = p->data;
        tmp->next = newL->next;
        newL->next = tmp;
        p = p->next;
    }
    p = newL->next;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}

// 法二：像这种你指的操作往往可以利用栈
void ReversePrint_2(LinkList L)
{
    stack<LNode*> s;
    LNode *p = L->next;
    while(p)
    {
        s.push(p);
        p = p->next;
    }
    while(!s.empty())
    {
        cout<<s.top()->data<<" ";
        s.pop();
    }
}

// 法三：利用递归
// 第一个函数处理头节点
void ReversePrint_3(LinkList L)
{
    if(L->next != NULL) ReversePrint_3_2(L->next);
}
// 第二个函数处理递归操作
void ReversePrint_3_2(LinkList L)
{
    if(L->next != NULL)
    {
        ReversePrint_3_2(L->next);
    }
    if(L != NULL) cout<<L->data<<" ";
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
    ReversePrint_2(L);
}