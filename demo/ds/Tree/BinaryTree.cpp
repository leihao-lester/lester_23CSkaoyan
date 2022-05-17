using namespace std;
#include <iostream>
#include <stack>
#include <queue>

typedef struct BiTNode
{
    int data;
    BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void CreateBinaryTree(BiTree &T)
{
    int tmp;
    cin>>tmp;
    if(tmp == -1) T = NULL;
    else 
    {
        T = (BiTree) malloc(sizeof(BiTNode));
        T->data = tmp;
        CreateBinaryTree(T->lchild);
        CreateBinaryTree(T->rchild);
    }
}

void visit(BiTree T)
{
    cout<<T->data<<" ";
}

// 递归实现先序遍历
void PreOrder(BiTree T)
{
    if(T != NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

// 递归实现中序遍历
void InOrder(BiTree T)
{
    if(T != NULL)
    {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

// 递归实现后序遍历
void PostOrder(BiTree T)
{
    if(T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

// 非递归实现先序遍历
void PreOrder2(BiTree T)
{
    stack<BiTree> S;
    BiTree p = T;
    while(p || !S.empty())
    {
        if(p)
        {
            visit(p);
            S.push(p);
            p = p->lchild;
        }
        else
        {
            p = S.top();
            p = p->rchild;
            S.pop();
        }
    }
}

// 非递归实现中序遍历
void InOrder2(BiTree T)
{
    stack<BiTree> S;
    BiTree p = T;
    while(p || !S.empty())
    {
        if(p)
        {
            S.push(p);
            p = p->lchild;
        }
        else
        {
            p = S.top();
            visit(p);
            p = p->rchild;
            S.pop();
        }
    }
}

// 非递归实现后序遍历
void PostOrder2(BiTree T)
{
    stack<BiTree> S;
    BiTree p = T;
    BiTree lastVisit = NULL;
    while(p || !S.empty())
    {
        if(p)
        {
            S.push(p);
            p = p->lchild;        
        }
        else
        {
            p = S.top();
            if(p->rchild && p->rchild != lastVisit)
            {
                p = p->rchild;
            }
            else
            {
                visit(p);
                S.pop();
                lastVisit = p;
                p = NULL;
            }

        }
    }
}

// 层次遍历
void LevelOrder(BiTree T)
{
    queue<BiTree> Q;
    BiTree p;
    Q.push(T);
    while(!Q.empty())
    {
        p = Q.front();
        visit(p);
        Q.pop();
        if(p->lchild) Q.push(p->lchild);
        if(p->rchild) Q.push(p->rchild);
    }
}

int main()
{
    // test example:1 2 4 -1 -1 5 8 -1 -1 -1 3 6 -1 9 -1 -1 7 -1 -1
    // eg.
    //        1
    //     /     \
    //    2       3
    //  /   \   /   \
    // 4     5  6    7
    //      /    \
    //     8      9
    BiTree T;
    CreateBinaryTree(T);
    cout<<"PreOrder:\t";
    PreOrder(T);
    cout<<endl;
    cout<<"InOrder:\t";
    InOrder(T);
    cout<<endl;
    cout<<"PostOrder:\t";
    PostOrder(T);
    cout<<endl;
    cout<<"PreOrder2:\t";
    PreOrder2(T);
    cout<<endl;
    cout<<"InOrder2:\t";
    InOrder2(T);
    cout<<endl;
    cout<<"PostOrder2:\t";
    PostOrder2(T);
    cout<<endl;
    cout<<"LevelOrder:\t";
    LevelOrder(T);
    cout<<endl;
}