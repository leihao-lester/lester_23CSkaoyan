using namespace std;
#include <iostream>
#include <stack>
#include <queue>

void reverse(queue<int> &Q)
{
    stack<int> S;
    while(!Q.empty())
    {
        S.push(Q.front());
        Q.pop();
    }
    while(!S.empty())
    {
        Q.push(S.top());
        S.pop();
    }
}
int main()
{
    queue<int> Q;
    for(int i = 0; i < 5; i++)
    {
        int x;
        cin>>x;
        Q.push(x);
    }
    reverse(Q);
    while(!Q.empty())
    {
        cout<<Q.front()<<endl;
        Q.pop();
    }
}