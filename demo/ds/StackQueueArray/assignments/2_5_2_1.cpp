using namespace std;
#include <iostream>
#define MaxSize 100
typedef struct
{
    int data[MaxSize];
    int front, rear;
    int tag;
} LoopQueue;

void InitQueue(LoopQueue &Q)
{
    Q.front = 0;
    Q.rear = 0;
    Q.tag = 0;
}

bool QueueEmpty(LoopQueue Q)
{
    return Q.tag == 0;
}

bool EnQueue(LoopQueue &Q, int x)
{
    if ((Q.rear == Q.front) && Q.tag == 1) return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.tag = 1;
    return true;
}

bool DeQueue(LoopQueue &Q, int &x)
{
    if((Q.rear == Q.front) && Q.tag == 0) return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    Q.tag = 0;
    return true;
}

bool GetTop(LoopQueue &Q, int &x)
{
    if((Q.rear == Q.front) && Q.tag == 0) return false;
    x = Q.data[Q.front];
    return true;
}

int GetLength(LoopQueue Q)
{
    return (Q.rear + MaxSize - Q.front) % MaxSize;
}


int main()
{
    LoopQueue Q;
    InitQueue(Q);
    for(int i = 0; i < 5; i++)
    {
        int x;
        cin>>x;
        EnQueue(Q, x);
    }
    int x;
    DeQueue(Q, x);
    cout<< x<<endl;
    GetTop(Q, x);
    cout<<x<<endl;
    cout<<GetLength(Q)<<endl;
}