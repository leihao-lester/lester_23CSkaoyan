#include<iostream>
using namespace std;
typedef struct {
    int data[100];
    int length;
}SqList;

void DelX(SqList &L, int x)
{
    int index = 0;
    for(int i = 0; i < L.length; i++)
    {
        if(L.data[i] == x)
        {
            index++;
        }
        else
        {
            L.data[i-index] = L.data[i];
        }
    }
    L.length -= index;
}

int main()
{
    SqList L;
    L.length = 7;
    for(int i = 0; i< L.length; i++)
    {
        cin>>L.data[i];
    }
    DelX(L,3);
    for(int i = 0; i < L.length; i++)
    {
        cout<<L.data[i]<< " ";
    }

}