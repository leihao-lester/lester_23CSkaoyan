#include<stdio.h>
#include<stdlib.h>
#define InitSize 100
#define ElemType int 

// 定义动态分配存储的顺序表
typedef struct SqList{
    ElemType *data;
    int length;
    int MaxSize;
}SqList;

// 初始化顺序表
SqList InitList_Sq()
{
    SqList L;
    L.length = 0;
    L.MaxSize = InitSize;
    L.data = (ElemType*)malloc(InitSize * sizeof(ElemType));
    return L;
}

// 增加容量
void IncreaseSize(SqList &L, int len)
{
    ElemType* p = L.data;
    L.data = (ElemType*) malloc((len + InitSize) * sizeof(ElemType));
    for(int i = 0; i<L.length;i++)
    {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}

// 在顺序表的第i个位置插入新元素
bool ListInsert_Sq(SqList &L, int i, ElemType e)
{
    if(i < 1 || i > L.length + 1 || L.length + 1 > L.MaxSize)
        return false;
    if(i == L.length + 1) 
    {
        L.data[i-1] = e;
    }
    else
    {
        for(int j = L.length; j >= i; j--)
        {
            L.data[j] = L.data[j-1];
        }
        L.data[i-1] = e;
    }
    L.length++;
    return true;
}


// 删除第i个位置的元素
bool ListDelete_Sq(SqList &L, int i, ElemType &e)
{
    if(i < 1 || i > L.length)
        return false;
    e = L.data[i-1];
    for(int j=i-1;j<L.length-1;j++)
    {
        L.data[j] = L.data[j+1];
    }
    L.length--;
    return true;
}


// 按位查找
ElemType GetElem_Sq(SqList &L, int i)
{
    if(i < 1 || i >= L.length)
        return -1;
    return L.data[i-1];
}

// 按值查找
int LocateElem_Sq(SqList &L, ElemType e)
{
    for(int i = 0;i<L.length;i++)
    {
        if(L.data[i] == e)
            return i+1;
    }
    return 0;
}


// 测试
int main()
{
    SqList L = InitList_Sq();
    for(int i=0;i<5;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        ListInsert_Sq(L,L.length + 1,tmp);
    }
    int e;
    ListDelete_Sq(L,5,e);
    int d = LocateElem_Sq(L,3);
    printf("%d\n",d);

    for(int i =0 ;i<L.length;i++)
    {
        printf("%d ",L.data[i]);
    }
}


