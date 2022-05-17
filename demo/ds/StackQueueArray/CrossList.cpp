using namespace std;
#include <iostream>
typedef struct OLNode
{
    int i,j; //矩阵三元组i代表行 j代表列 data代表当前位置的数据
    int data;
    OLNode *down, *right; //指针域 右指针 下指针
} OLNode, *OLink;

typedef struct
{
    OLink *rhead, *chead; //行和列链表头指针
    int mu, nu, tu; //矩阵的行数,列数和非零元的个数
}CrossList;

void CreateMatrix_OL(CrossList &M)
{
    int m,n,t;
    cin>>m>>n>>t;
    M.mu = m;
    M.nu = n;
    M.tu = t;
    if(!(M.chead = (OLink*)malloc(sizeof(OLNode)*(m+1))) || !(M.rhead = (OLink*)malloc(sizeof(OLNode)*(n+1)))) cout<<"error"<<endl;
    for(int i = 0; i < m; i++)
    {
        M.rhead[i] = NULL;
    }
    for(int j = 0; j < n; j++)
    {
        M.chead[j] = NULL;
    }
    for(int k = 0; k < t; k++)
    {
        int i,j,data;
        cin>>i>>j>>data;
        OLNode *p = (OLNode*)malloc(sizeof(OLNode));
        p->i = i;
        p->j = j;
        p->data = data;
        // 链接到行
        if(M.rhead[i] == NULL || M.rhead[i]->j > j)
        {
            p->right = M.rhead[i];
            M.rhead[i] = p;
        }
        else
        {
            OLNode *q;
            for(q = M.rhead[i]; (q->right) && q->right->j < j; q = q->right);
            p->right = q->right;
            q->right = p;
        }
        // 链接到列
        if(M.chead[j] == NULL || M.chead[j]->i > i)
        {
            p->down = M.chead[j];
            M.chead[j] = p;
        }
        else
        {
            OLNode *q;
            for(q = M.chead[j]; (q->down) && q->down->j < j; q = q->down);
            p->down = q->down;
            q->down = p;
        }
    }
}

void display(CrossList M)
{
    for(int i = 0; i < M.mu; i++)
    {
        OLNode *q = M.rhead[i];
        int j = 0;
        while(j < M.nu)
        {
            if(q && q->j == j)
            {
                cout<<q->data<<" ";
                q = q->right;
            }
            else cout<<0<<" ";
            j++;
        }
        cout<<endl;
    }
}

int main()
{
    CrossList M;
    CreateMatrix_OL(M);
    display(M);
}