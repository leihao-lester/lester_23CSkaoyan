#include <iostream>
using namespace std;
int A[100];
int n, x;

void MyFun(int A[], int x, int n)
{
    int l = 0, r = n - 1,mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (A[mid] == x) break;
        else if (A[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    if(A[mid] == x && mid != n-1)
    {
        int tmp = A[mid];
        A[mid] = A[mid+1];
        A[mid+1] = A[mid];
    }
    if(l>r)
    {
        int i;
        for (i = n-1; i > r; i--)
        {
            A[i+1] = A[i];
        }
        A[i+1] = x; // 易错
    }
}

int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    MyFun(A, x, n);
    for (int i = 0; i < n + 1; i++)
    {
        cout << A[i] << " ";
    }
}