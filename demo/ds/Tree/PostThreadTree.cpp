using namespace std;
#include <iostream>
#include <stack>

typedef struct ThreadNode
{
    int data;
    ThreadNode *lchild, *rchild;
    int ltag, rtag;
    ThreadNode *parent; // 为了实现找某个结点在后序遍历下的后继结点
}ThreadNode, *ThreadTree;

void CreateThreadTree(ThreadTree &T, ThreadNode *parent)
{
    int tmp;
    cin>>tmp;
    if(tmp == -1) T = NULL;
    else
    {
        T = (ThreadNode *) malloc(sizeof(ThreadNode));
        T->data = tmp;
        T->ltag = 0;
        T->rtag = 0;
        T->parent = parent;
        CreateThreadTree(T->lchild, T);
        CreateThreadTree(T->rchild, T);
    }
}

void PostThread(ThreadTree &p, ThreadTree &pre)
{
    if(p != NULL)
    {
        PostThread(p->lchild, pre);
        PostThread(p->rchild, pre);
        if(p->lchild == NULL)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        if(pre != NULL && pre->rchild == NULL)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
    }
}

void CreatePostThread(ThreadTree &T)
{
    ThreadTree pre = NULL;
    if(T != NULL)
    {
        PostThread(T, pre);
        if(pre->rchild == NULL)
        {
            pre->rtag = 1;
        }
    }
}

void visit(ThreadNode *p)
{
    cout<<p->data<<" ";
}

ThreadNode *FirstNode(ThreadNode *p)
{
    while(p->ltag == 0) p = p->lchild;
    while(p->rtag == 0) p = p->rchild;
    return p;
}

ThreadNode *NextNode(ThreadNode *p)
{
    if(p->rtag == 1) return p->rchild;
    ThreadNode *parent = p->parent;
    if(parent == NULL) return NULL;
    if(parent->lchild == p && parent->rtag == 0) return FirstNode(parent->rchild); // 注意考虑父节点是否有右子树
    else return parent;
}

ThreadNode *LastNode(ThreadNode *p)
{
    return p;
}

ThreadNode *PreNode(ThreadNode *p)
{
    if(p->rtag == 1) return p->lchild;
    else return p->rchild;
}

void PostOrder(ThreadTree T)
{
    for(ThreadNode *p = FirstNode(T); p != NULL; p = NextNode(p))
        visit(p);
}

void ReversePostOrder(ThreadTree T)
{
    for(ThreadNode *p = LastNode(T); p != NULL; p = PreNode(p))
        visit(p);
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
    // another test example:1 2 3 4 -1 -1 5 -1 -1 -1 6 -1 7 -1 -1
    // eg. 
    //        1
    //       /  \
    //     2      6
    //    /        \
    //   3          7
    //  / \
    // 4   5
    ThreadTree T;
    CreateThreadTree(T,NULL);
    CreatePostThread(T);
    PostOrder(T);
    cout<<endl;
    ReversePostOrder(T);
}
