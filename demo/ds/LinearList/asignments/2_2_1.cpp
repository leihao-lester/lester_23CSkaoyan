#include<iostream>
using namespace std;
typedef struct {
    int data[100];
    int length;
}SqList;
int e;

bool DelMin(SqList L, int &e)
{
    if(L.length == 0)
    {
        cout<<"error"<<endl;
        return false;
    }
    int Min = L.data[0];
    int MinIndex = 0;
    for(int i = 0; i < L.length; i++)
    {
        if(L.data[i] < Min)
        {
            Min = L.data[i];
            MinIndex = i;
        }
    }
    L.data[MinIndex] = L.data[L.length -1];
    e = Min;
    L.length--;
    return true;
}

int main()
{
    SqList L;
    L.length = 5;
    for(int i = 0; i< L.length; i++)
    {
        cin>>L.data[i];
    }
    int e;
    DelMin(L,e);
    cout<<"e="<<e<<endl;
}