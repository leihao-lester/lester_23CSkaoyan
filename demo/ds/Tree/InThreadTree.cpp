using namespace std;
#include <iostream>
#include <stack>

typedef struct ThreadNode
{
    int data;
    ThreadNode *lchild, *rchild;
    int ltag, rtag;
}ThreadNode, *ThreadTree;

void CreateThreadTree(ThreadTree &T)
{
    int tmp;
    cin>>tmp;
    if(tmp == -1) T = NULL;
    else 
    {
        T = (ThreadNode *) malloc(sizeof(ThreadNode));
        T->data = tmp;
        T->ltag = 0; // 注意初始化
        T->rtag = 0;
        CreateThreadTree(T->lchild);
        CreateThreadTree(T->rchild);
    }
}

void InThread(ThreadTree &p, ThreadTree &pre)
{
    if(p != NULL)
    {
        InThread(p->lchild, pre);
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
        InThread(p->rchild, pre);
    }
}

void CreateInThread(ThreadTree &T)
{
    ThreadTree pre = NULL;
    if(T != NULL)
    {
        InThread(T, pre);
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


// 求中序线索二叉树中中序序列下的第一个结点
ThreadNode *FirstNode(ThreadNode *p)
{
    while(p->ltag == 0) p = p->lchild;
    return p;
}

// 求中序线索二叉树中结点p在中序序列下的后继
ThreadNode *NextNode(ThreadNode *p)
{
    if(p->rtag == 0) return FirstNode(p->rchild);
    else return p->rchild;
}

// 求中序线索二叉树中中序序列下的最后一个结点
ThreadNode *LastNode(ThreadNode *p)
{
    while(p->rtag == 0) p = p->rchild;
    return p;
}

// 求中序线索二叉树中结点p在中序序列下的前驱
ThreadNode *PreNode(ThreadNode *p)
{
    if(p->ltag == 0) return LastNode(p->lchild);
    else return p->lchild;
}

// 不含头节点的中序线索树的中序遍历
void InOrder(ThreadTree T)
{
    for(ThreadNode *p = FirstNode(T); p != NULL; p = NextNode(p))
        visit(p);
}

// 不含头节点的中序线索树的逆中序遍历
void ReverseInOrder(ThreadTree T)
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
    ThreadTree T;
    CreateThreadTree(T);
    CreateInThread(T);
    InOrder(T);
    cout<<endl;
    ReverseInOrder(T);

}