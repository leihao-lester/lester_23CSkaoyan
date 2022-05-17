using namespace std;
#include<iostream>

typedef struct LinkNode
{
    int data;
    LinkNode *next;
} *LiStack,LinkNode;

void InitStack(LiStack &S)
{
    S = (LiStack) malloc(sizeof(LinkNode));
    S->next = NULL;
}

bool StackEmpty(LiStack &S)
{
    return S->next == NULL;
}

bool Push(LiStack &S, int x)
{
    LiStack p = (LiStack) malloc(sizeof(LinkNode));
    p->data = x;
    LiStack q = S->next;
    S->next = p;
    p->next = q;
    return true;
}

bool Pop(LiStack &S, int &x)
{
    if(S->next == NULL) return false;
    LiStack p = S->next;
    S->next = p->next;
    x = p->data;
    free(p);
    return true;
}

bool GetTop(LiStack &S,int &x)
{
    if(S->next == NULL) return false;
    x = S->next->data;
    return true;
}

int main()
{
    LiStack S;
    InitStack(S);
    for(int i = 0; i < 5; i++)
    {
        int x;
        cin>>x;
        Push(S, x);
    }
    int x;
    Pop(S, x);
    cout<<x<<endl;
    GetTop(S, x);
    cout<<x;
}