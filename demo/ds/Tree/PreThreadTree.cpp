using namespace std;
#include <iostream>
#include <stack>

typedef struct ThreadNode
{
    int data;
    ThreadNode *lchild, *rchild;
    int ltag, rtag;
    ThreadNode *parent; // 为了寻找某个结点在先序遍历下的前驱结点
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

void PreThread(ThreadTree &p, ThreadTree &pre) // todo
{
    if(p != NULL)
    {
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
        // 在访问某个结点时可能已经将该节点的左孩子指针线索化
        if(p->ltag == 0)
        {
            PreThread(p->lchild, pre);
        }
        // 在访问某个结点的左子树时有可能已经将该节点的右孩子指针线索化
        // 如： A
        //     /
        //    B
        if(p->rtag == 0)
        {
            PreThread(p->rchild, pre);
        }
    }
}

void CreatePreThread(ThreadTree &T)
{
    ThreadNode *pre = NULL;
    if(T != NULL)
    {
        PreThread(T, pre);
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
    return p;
}

ThreadNode *NextNode(ThreadNode *p)
{
    if(p->ltag == 0) return p->lchild;
    else return p->rchild;
}

void PreOrder(ThreadTree T)
{
    for(ThreadNode *p = FirstNode(T); p != NULL; p = NextNode(p))
        visit(p);
}

ThreadNode *LastNode(ThreadNode *p)
{
    if(p->rtag == 0) return LastNode(p->rchild);
    else if(p->rtag == 1 && p->ltag == 1) return p;
    else return LastNode(p->lchild); 
}

ThreadNode *PreNode(ThreadNode *p)
{
    if(p->ltag == 1) return p->lchild;
    else
    {
        ThreadNode *parent = p->parent;
        if(parent == NULL) return NULL;
        if(parent->lchild == p) return parent;
        else return LastNode(parent->lchild);
    }
}

void ReversePreOrder(ThreadTree T)
{
    for(ThreadNode *p = LastNode(T); p != NULL; p = PreNode(p)) // 注意循环结束条件为 p != T
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
    ThreadTree T;
    CreateThreadTree(T, NULL);
    CreatePreThread(T);
    PreOrder(T);
    cout<<endl;
    ReversePreOrder(T);
}