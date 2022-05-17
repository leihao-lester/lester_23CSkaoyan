using namespace std;
#include<iostream>
#include<stack>

typedef struct Queue
{
    stack<int> s1;
    stack<int> s2;
}Queue;

bool Enqueue(Queue &Q, int x)
{
    // 判断是否已满
    Q.s1.push(x);
    return true;
}

bool Dequeue(Queue &Q, int &x)
{
    // 判断是否为空
    while(!Q.s1.empty())
    {
        Q.s2.push(Q.s1.top());
        Q.s1.pop();
    }
    x = Q.s2.top();
    Q.s2.pop();
    while(!Q.s2.empty())
    {
        Q.s1.push(Q.s2.top());
        Q.s2.pop();
    }
    return true;
}

bool QueueEmpty(Queue &Q)
{
    return Q.s1.empty();
}