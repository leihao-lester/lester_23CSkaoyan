#include <stdio.h>
#define MaxSize 100 // 定义线性表的最大长度
#define ElemType int

// 定义顺序表(静态分配一维数组)
typedef struct SqList
{
    ElemType data[MaxSize];
    int length;
} SqList;

// 初始化顺序表
SqList InitList_Sq()
{
    SqList L;
    L.length = 0;
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
    return L;
}

// 在顺序表的第i个位置插入新元素
bool ListInsert_Sq(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (i == L.length + 1) 
    {
        L.data[i-1] = e;
        L.length++;
        return true;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

// 删除第i个位置的元素
bool ListDelete_Sq(SqList &L, int i, ElemType &e)
{
    if(i<1 || i>L.length)
        return false;
    e = L.data[i-1]; 
    for(int j = i-1;j<L.length-1;j++)
    {
        L.data[j] = L.data[j+1];
    }
    L.length--;
    return true;
}

// 按位查找
ElemType GetElem_Sq(SqList &L, int i)
{
    if(i<1 || i>L.length)
        return false;
    return L.data[i-1];
}

// 按值查找
int LocateElem_Sq(SqList &L, ElemType e)
{
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i] == e) return i+1;
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
        ListInsert_Sq(L,1,tmp);
    }
    int e;
    ListDelete_Sq(L,2,e);
    printf("%d\n",GetElem_Sq(L,4));
    printf("%d\n",LocateElem_Sq(L,6));
    for(int i=0;i<L.length;i++){
        printf("%d ",L.data[i]);
    }
}
