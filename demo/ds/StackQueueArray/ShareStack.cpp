using namespace std;
#include<iostream>
#define MaxSize 100
typedef struct 
{
    int data[MaxSize];
    int top[2];
}ShareStack;

void InitStack(ShareStack &S)
{
    S.top[0] = -1;
    S.top[1] = MaxSize;
}

bool StackEmpty(ShareStack &S, int sno)
{
    if(sno != 0 && sno != 1) return false;
    if(sno == 0) return S.top[0] == -1;
    else return S.top[1] == MaxSize;
}

bool Push(ShareStack &S, int sno, int x)
{
    if(sno != 0 && sno != 1) return false;
    if(S.top[0] + 1 == S.top[1]) return false;
    if(sno == 0)
    {
        S.data[++S.top[0]] = x;
    }
    else
    {
        S.data[--S.top[1]] = x;
    }
    return true;
}

bool Pop(ShareStack &S, int sno, int &x)
{
    if(sno != 0 && sno != 1) return false;
    if((sno == 0 && S.top[0] == -1)|| (sno == 1 && S.top[1] == MaxSize)) return false;
    if(sno == 0)
    {
        x = S.data[S.top[0]--];
    }
    else
    {
        x = S.data[S.top[1]++];
    }
    return true;
}

bool GetTop(ShareStack &S, int sno, int &x)
{    
    if(sno != 0 && sno != 1) return false;
    if((sno == 0 && S.top[0] == -1)|| (sno == 1 && S.top[1] == MaxSize)) return false;
    if(sno == 0)
    {
        x = S.data[S.top[0]];
    }
    else
    {
        x = S.data[S.top[1]];
    }
    return true;
}

int main()
{
    ShareStack S;
    InitStack(S);
    for(int i = 0; i < 6; i++)
    {
        int x;
        int y;
        cin>>x>>y;
        Push(S,x,y);
    }
    int x;
    Pop(S, 1, x);
    cout<<x<<endl;
    GetTop(S,1,x);
    cout<<x;
}