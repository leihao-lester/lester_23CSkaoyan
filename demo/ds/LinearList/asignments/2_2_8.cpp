#include <iostream>
using namespace std;
int a[100];
int m,n;

void ReverseMN(int a[],int m,int n)
{
    int b[100];
    for(int i=0;i<m;i++)
    {
        b[i] = a[i];
    }
    for(int i=m;i<m+n;i++)
    {
        a[i-m] = a[i];
    }
    for(int i = n;i<m+n;i++)
    {
        a[i] = b[i-n];
    }
}

int main()
{
    cin>>m>>n;
    for (int i = 0; i < m+n; i++)
    {
        cin >> a[i];
    }
    ReverseMN(a,m,n);
    for (int i = 0; i < m+n; i++)
    {
        cout << a[i] << " ";
    }
}