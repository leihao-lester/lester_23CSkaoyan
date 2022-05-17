#include <iostream>
using namespace std;
typedef struct
{
    int data[100];
    int length;
} SqList;

bool DelRepeat(SqList &L)
{
    int index  = 0;
    if(L.length <= 1) return true;
    for(int i = 1;i<L.length;i++)
    {
        if(L.data[i] == L.data[i-1]) index++;
        else L.data[i-index] = L.data[i];
    }
    L.length -= index;
    return true;
}

int main()
{
    SqList L;
    L.length = 7;
    for (int i = 0; i < L.length; i++)
    {
        cin >> L.data[i];
    }
    DelRepeat(L);
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
}