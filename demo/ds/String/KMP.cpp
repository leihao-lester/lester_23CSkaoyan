using namespace std;
#include <iostream>
#define MaxSize 100
typedef struct
{
    char ch[MaxSize];
    int length;
}String;

void get_next(String T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while(i < T.length)
    {
        if(j == 0 || T.ch[j] == T.ch[i]) next[++i] = ++j;
        else j = next[j];
    }
}

void get_nextval(String T, int nextval[])
{
    int i = 1, j = 0;
    nextval[1] = 0;
    while(i < T.length)
    {
        if(j == 0 || T.ch[i] == T.ch[j])
        {
            ++i, ++j;
            if(T.ch[i] != T.ch[j]) nextval[i] = j; // 这个地方的判断条件决定着更不更新next值
            else nextval[i] = nextval[j];
        } 
        else j = nextval[j];
    }
}

int Index(String S, String T)
{
    int i = 1, j = 1;
    while(i <= S.length && j <= T.length)
    {
        if(S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if(j > T.length) return i - T.length;
    else return 0;
}

int Index_KMP(String S, String T)
{
    int i = 1, j = 1;
    int next[T.length + 1];
    get_next(T, next);
    while(i <= S.length && j <= T.length)
    {
        if(j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else j = next[j];
    }
    if(j > T.length) return i - T.length;
    else return 0;
}

int Index_KMP_Pro(String S, String T)
{
    int i = 1, j = 1;
    int nextval[T.length + 1];
    get_nextval(T, nextval);
    while(i <= S.length && j <= T.length)
    {
        if(j == 0 || S.ch[i] == T.ch[j])
        {
            ++i;
            ++j;
        }
        else j = nextval[j];
    }
    if(j > T.length) return i - T.length;
    else return 0;
}

int main()
{
    String S, T;
    cin>>S.length>>T.length;
    for(int i = 1; i <= S.length; i++) cin>>S.ch[i];
    for(int i = 1; i <= T.length; i++) cin>>T.ch[i];
    cout<<Index(S, T)<<endl;
    cout<<Index_KMP(S, T)<<endl;
    cout<<Index_KMP_Pro(S, T)<<endl;
}