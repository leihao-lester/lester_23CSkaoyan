#include <iostream>
using namespace std;
typedef struct
{
    int data[100];
    int length;
} SqList;

bool DelST(SqList &L, int s, int t)
{
    if (s >= t || L.length == 0)return false;
    int index  = 0;
    for(int i = 0;i<L.length;i++)
    {
        if(L.data[i]<=t && L.data[i]>=s) index++;
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
    DelST(L,1,5);
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
}