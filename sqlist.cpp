#include<bits/stdc++.h>

using namespace std;

#define Maxsize 100
#define elemtype int

typedef struct //静态定义
{
    elemtype data[Maxsize];
    int length;
};

typedef struct //动态定义
{
    elemtype *data;//动态分配数组的指针
    int maxsize,length;//数组的最大容量与当前个数
}sqlist;

bool listinsert(sqlist &L,int i,elemtype e)//将元素e插入到顺序表
{
    if(i<1 || i> L.length+1) //检查i的合理性
        return false;
    if(L.length>=L.maxsize) //检查链表是否已满
        return false;

    for(int j=L.length;L.length>=i;j--)// 将第i个元素及其后续元素都后移一个单位
        L.data[j]=L.data[j-1];
    L.data[i-1]=e;//插入e
    L.length++;//长度增加1
    return true;//返回true
}

bool Listdelete(sqlist &L,int i,elemtype &e)//实现删除第i个位置的元素
{
    if(i<1 || i>L.length)//检查i的合理性
        return false;
    e=L.data[i-1];//用e返回被删除的值
    for(int j=i;i<L.length;j++)//第i个位置及后续元素都前移一个单位
        L.data[j-1]=L.data[j];

    L.length--;//长度减少1
    return true;//返回true
}

int locateelem(sqlist L,elemtype e)//按值查找返回位置
{
    int i;
    for(i=0;i<L.length;i++)
        if(L.data[i]==e)
            return i+1;
    return 0;
}


//单链表

typedef struct LNode
{
    elemtype data;
    struct LNode*next;

}LNode,*LinkList;


LinkList CreateListhead(LinkList &L)//头插法建立单链表
{
    LNode *s;int x;
    L=(LinkList)malloc(sizeof(LinkList));
    L->next=NULL;
    while(cin>>x,x)
    {
        s=(LinkList)malloc(sizeof(LinkList));
        s->data=x;
        s->next=L->next;
        L->next=s;
    }
    return L;
}

LinkList CreateListtail(LinkList &L)//尾插法建立单链表
{
    LNode *s,*r=L;int x;
    L=(LinkList)malloc(sizeof(LinkList));
    while(cin>>x,x)
    {
        s=(LinkList)malloc(sizeof(LinkList));
        s->data=x;
        r->next=s;
        r=s;
    }

    r->next=NULL;
    return L;
}

LNode *GetElem(LinkList L,int i)//按序号索值,取出单链表(带头结点)中第i个位置的节点指针
{
    int j=1;
    LNode *p=L->next;
    if(i==0)return L;
    if(i<1)return NULL:
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }

    return p;
}

LNode *Locate(LinkList L,elemtype e)//按值查找节点
{
    LNode *p=L->next;
    while(p&&p->data!=e)
    {
        p=p->next;
    }

    return p;
}




