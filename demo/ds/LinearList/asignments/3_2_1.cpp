#include<iostream>
using namespace std;

typedef struct LNode
{
    int data;
    LNode* next;
}LNode, *LinkList;

bool ListInsert(LinkList &L, int i, int e)
{
    if(i<1)
        return false;
    if(i == 1)
    {
        LNode*p = (LNode* )malloc(sizeof(LNode));
        p->data = e;
        p->next = L;
        L = p;
        return true;
    }
    LNode *p = L;
    int j=1;
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

// 删除值为x的元素
// 注：这里面的删除元素和单链表按照位次删除元素的原理不同
//     按照位次删除元素首先要找到i-1个元素，然后才能删除第i个元素
//     而对于没有头节点且需要递归的，按照值删除元素则需要判断当前结点是否为x，删除当前结点，
//     所以要通过修改指向当前结点的引用指针来达到删除结点的目的
void DelX(LinkList &L, int x)
{
    if(L == NULL) return ;
    if(L->data == x)
    {
        LNode* p = L;
        L = L->next; // 如果值为x，则需要重新赋值
        free(p);
        DelX(L, x);
    }
    else
        DelX(L->next, x); // 如果值不为x，则不需要赋值
}



int main()
{
    LinkList L = NULL;
    for(int i=0;i<5;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        ListInsert(L,1,tmp);
    }
    DelX(L, 5);
    LNode *p = L;
    while (p!= NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}