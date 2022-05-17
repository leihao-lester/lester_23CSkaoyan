using namespace std;
#include<iostream>
#define MaxSize 100

typedef struct
{
    int data[MaxSize];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue &Q)
{
    Q.front = 0;
    Q.rear = 0;
}

bool QueueEmpty(SqQueue Q)
{
    return Q.rear == Q.front;
}

bool EnQueue(SqQueue &Q, int x)
{
    if(Q.rear == MaxSize) return false;
    Q.data[Q.rear++] = x;
    return true;
}

bool DeQueue(SqQueue &Q, int &x)
{
    if(Q.front == Q.rear) return false;
    x = Q.data[Q.front++];
    return true;
}

bool GetHead(SqQueue Q, int &x)
{
    if(Q.front == Q.rear) return false;
    x = Q.data[Q.front];
    return true;
}

int main()
{
    SqQueue Q;
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
    GetHead(Q, x);
    cout<<x;
}