#include <iostream>
using namespace std;
typedef struct
{
    int data[100];
    int length;
} SqList;

SqList MergeSqList(SqList &x, SqList &y)
{
    SqList L;
    L.length = x.length + y.length;
    int i=0,j=0,k=0;
    while(i<x.length &&j<y.length)
    {
        if(x.data[i]<=y.data[j])
        {
            L.data[k] = x.data[i];
            i++;
        }
        else
        {
            L.data[k] = y.data[j];
            j++;
        }
        k++;
    }
    if(i<x.length)
    {
        for(int t = i; t < x.length; t++)
        {
            L.data[k] = x.data[t];
            k++;
        }
    }
    if(j < y.length)
    {
        for(int t = j; t < y.length; t++)
        {
            L.data[k] = y.data[t];
            k++;
        }
    }
    return L;
}

int main()
{
    SqList a,b;
    a.length = 7;
    b.length = 7;
    for (int i = 0; i < a.length; i++)
    {
        cin >> a.data[i];
    }
    for(int i = 0; i < b.length; i++)
    {
        cin >> b.data[i];
    }
    SqList L = MergeSqList(a,b);
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
}