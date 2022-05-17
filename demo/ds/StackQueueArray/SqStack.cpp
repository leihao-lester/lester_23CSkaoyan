using namespace std;
#include<iostream>
#define MaxSize 100

typedef struct{
    int data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack &S)
{
    S.top = -1;
}

bool StackEmpty(SqStack S)
{
    return S.top == -1;
}

bool Push(SqStack &S, int x)
{
    if(S.top + 1 == MaxSize) return false;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, int &x)
{
    if(S.top == -1) return false;
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack &S, int &x)
{
    if(S.top == -1) return false;
    x = S.data[S.top];
    return true;
}

int main()
{
    SqStack S;
    InitStack(S);
    for(int i = 0; i < 5; i++)
    {
        int x;
        cin>>x;
        Push(S,x);
    }
    int y;
    Pop(S,y);
    cout<<y<<endl;
    GetTop(S,y);
    cout<<y<<endl;
}