using namespace std;
#include <iostream>
typedef struct LinkNode
{
    int data;
    LinkNode *next;
}LinkNode;

typedef struct LinkQueue
{
    LinkNode *front, *rear;
}LinkQueue;

void InitQueue(LinkQueue &Q)
{
    Q.front = (LinkNode*) malloc(sizeof(LinkNode));
    Q.rear = Q.front;
    Q.front->next = NULL;
}

bool QueueEmpty(LinkQueue Q)
{
    return Q.front == Q.rear;
}

bool EnQueue(LinkQueue &Q, int x)
{
    LinkNode *p = (LinkNode*) malloc(sizeof(LinkNode));
    p->data = x;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return true;
}

bool DeQueue(LinkQueue &Q, int &x)
{
    if(Q.front == Q.rear) return false;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if(p == Q.rear) Q.rear = Q.front; // 若原队列中只有一个结点，删除后变空
    free(p);
    return true;
}

bool GetTop(LinkQueue &Q, int &x)
{
    if(Q.front == Q.rear) return false;
    x = Q.front->next->data;
    return true;
}


int main()
{
    LinkQueue Q;
    InitQueue(Q);
    for(int i = 0; i < 5; i++)
    {
        int x;
        cin>> x;
        EnQueue(Q, x);
    }
    int x;
    DeQueue(Q, x);
    cout<<x<<endl;
    GetTop(Q, x);
    cout<<x<<endl;
}

