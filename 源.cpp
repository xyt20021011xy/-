#include<iostream>
#include<malloc.h>

using namespace std;
typedef int ElemType ;
typedef int Status;
//构造链表
typedef struct LNode{
	ElemType val;
	LNode *next;
	
}LNode,*LinkList;
//初始化
Status Initlist(LinkList& L);
//创造指定数量初始化
Status createList(LinkList& L, int len);
//插入
Status insertLinkList(LinkList &L, int pos, ElemType e);
//修改
Status modifyLinkList(LinkList& l, int pos, ElemType e);
//删除
Status deleteLinkList(LinkList &L, int pos, ElemType &e);
//转置
void reverseLinkList(LinkList &L);
//值搜索
int seachLinkList(LinkList L, ElemType e);
//位序查找
int seach1LinkList(LinkList L, int pos);
//取表长
int getLen(LinkList  L);
//
int isEmpty(LinkList& L);
//打印
void printLinkList(LinkList L);
//销毁链表
void DestoryLinkList(LinkList &L);
//判空
void ListIsEmpty(LinkList& L);


//测试
int main(){
    LinkList L;
    Initlist(L);
    ElemType e;
    int len, pos;
    printf("创建元素个数：");
    scanf("%d", &len);
    printf("\n请输入：");

    createList(L, len);

    printf("当前链表所有元素：");

    printLinkList(L);
    printf("\n");
    printf("%d", getLen(L));
    printf("\n插入位置和插入值(中间用空格隔开)：");
    scanf("%d%d", &pos, &e);

    insertLinkList(L, pos, e);

    printf("\n插入元素后链表所有元素：");

    printLinkList(L);


    printf("请输入修改元素位置及大小");
    int a, b;
    scanf("%d %d", &a, &b);
    modifyLinkList(L, a, b);
    printLinkList(L);

    printf("\n请输入删除元素位置：");
    scanf("%d", &pos);

    deleteLinkList(L, pos, e);

    printf("\n元素%d已删除", e);
    printf("\n删除后链表所有元素：");

    printLinkList(L);

    printf("\n请输入查找元素：");
    scanf("%d", &e);
    printf("%d", seachLinkList(L, e));

    printf("请输入要查找位序");
    int c;
    scanf("%d", &c);
    printf("%d", seach1LinkList(L, c));
    

    //销毁链表
   DestoryLinkList(L);

    //判空
    //ListIsEmpty(L);
    return 0;
}



//初始化操作
Status Initlist(LinkList& L) {
    L = (LNode*)malloc(sizeof(LNode));
    if (!L)exit(0);
       
    
    L->next = NULL;
    return 1;
    
}
//创造指定数量初始化
Status createList(LinkList &L, int len) {
    ElemType e;
   
    LNode *r,*n;
   
    r = L;
    for (int i = 0; i < len; i++) {
        scanf("%d", &e);
        n = (LNode*)malloc(sizeof(LNode*));//申请空间
        if (!n)exit(0);
        n->val = e;
        n->next = NULL;
        r->next = n;
        r = r->next;
    }
    return 1;
}
//取表长
int getLen(LinkList  L) {
    int count = 0;
    while (L ->next!= NULL) {
        L = L->next;
        count++;
    }return count;



}
//值搜索
int seachLinkList(LinkList L, ElemType e) {
    int count = 0;\
        while (L != NULL) {
            L = L->next;
            count++;
            if (L->val == e) {
                return count;
            }
        }

    return count;

}
//位序查找
int seach1LinkList(LinkList L, int pos) {
    if (pos<1 || pos>getLen(L))return -1;
    while (pos--) {
        L = L->next;
       
    } return L->val;
}
//修改
Status modifyLinkList(LinkList& L, int pos, ElemType e) {
    if(pos<1||pos>getLen(L) + 1) return -1;
    LNode* r;
    r = L;
    while (--pos) {
        r = r->next;
    }r->next->val = e;


    return 1;


}
//插入
Status insertLinkList(LinkList &L, int pos, ElemType e) {
    if (pos < 1 || pos > getLen(L) + 1) return -1; //插入位置错误
    LNode *n;
    LNode *r = L;   
    n = (LNode*)malloc(sizeof(LNode));
    if (!n) {
        exit(-1);
    }
    n->val = e;
    n->next = NULL;
    while (--pos) {
        r = r->next;
    }n->next = r->next;
    r->next = n;
    return 1;

}
//删除
Status deleteLinkList(LinkList &L, int pos, ElemType &e) {
    LNode *p = L,*q;
    if (pos > getLen(L) + 1) return -1;
    int j = 0;
    while (j < pos - 1) {
        j++;
        p = p->next;
    }
    

    q = p->next;
    e = p->next->val;
     p->next=p->next->next;
     free(q);
     
     
     
  /* LNode* q = p->next;
    p->next = q->next;
    e = q->val;
    //*********************
    free(q);*/
    return 1;

}
//打印
void printLinkList(LinkList L) {
    LNode* node;
    node = L->next;
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
}
//销毁链表
void DestoryLinkList(LinkList &L)
{
    LNode* p;
    while (L != NULL)
    {
        p = L;
        L = L->next;
        free(p);
    };
}
//判空
void ListIsEmpty(LinkList &L)
{
    if (L == NULL) {
        printf("空");
    }
    else {
        printf("非空");
    }
}