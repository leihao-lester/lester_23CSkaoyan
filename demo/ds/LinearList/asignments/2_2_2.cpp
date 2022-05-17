#include<iostream>
using namespace std;
typedef struct {
    int data[100];
    int length;
}SqList;

void ReverseSqList(SqList &L)
{
    if(L.length < 1) return ;
    for(int i = 0; i < L.length / 2; i++)
    {
        int tmp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 -i] = tmp;
    }
}

int main()
{
    SqList L;
    L.length = 5;
    for(int i = 0; i< L.length; i++)
    {
        cin>>L.data[i];
    }
    ReverseSqList(L);
    for(int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
}