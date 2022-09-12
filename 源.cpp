#include<iostream>
#include<malloc.h>

using namespace std;
typedef int ElemType ;
typedef int Status;
//��������
typedef struct LNode{
	ElemType val;
	LNode *next;
	
}LNode,*LinkList;
//��ʼ��
Status Initlist(LinkList& L);
//����ָ��������ʼ��
Status createList(LinkList& L, int len);
//����
Status insertLinkList(LinkList &L, int pos, ElemType e);
//�޸�
Status modifyLinkList(LinkList& l, int pos, ElemType e);
//ɾ��
Status deleteLinkList(LinkList &L, int pos, ElemType &e);
//ת��
void reverseLinkList(LinkList &L);
//ֵ����
int seachLinkList(LinkList L, ElemType e);
//λ�����
int seach1LinkList(LinkList L, int pos);
//ȡ��
int getLen(LinkList  L);
//
int isEmpty(LinkList& L);
//��ӡ
void printLinkList(LinkList L);
//��������
void DestoryLinkList(LinkList &L);
//�п�
void ListIsEmpty(LinkList& L);


//����
int main(){
    LinkList L;
    Initlist(L);
    ElemType e;
    int len, pos;
    printf("����Ԫ�ظ�����");
    scanf("%d", &len);
    printf("\n�����룺");

    createList(L, len);

    printf("��ǰ��������Ԫ�أ�");

    printLinkList(L);
    printf("\n");
    printf("%d", getLen(L));
    printf("\n����λ�úͲ���ֵ(�м��ÿո����)��");
    scanf("%d%d", &pos, &e);

    insertLinkList(L, pos, e);

    printf("\n����Ԫ�غ���������Ԫ�أ�");

    printLinkList(L);


    printf("�������޸�Ԫ��λ�ü���С");
    int a, b;
    scanf("%d %d", &a, &b);
    modifyLinkList(L, a, b);
    printLinkList(L);

    printf("\n������ɾ��Ԫ��λ�ã�");
    scanf("%d", &pos);

    deleteLinkList(L, pos, e);

    printf("\nԪ��%d��ɾ��", e);
    printf("\nɾ������������Ԫ�أ�");

    printLinkList(L);

    printf("\n���������Ԫ�أ�");
    scanf("%d", &e);
    printf("%d", seachLinkList(L, e));

    printf("������Ҫ����λ��");
    int c;
    scanf("%d", &c);
    printf("%d", seach1LinkList(L, c));
    

    //��������
   DestoryLinkList(L);

    //�п�
    //ListIsEmpty(L);
    return 0;
}



//��ʼ������
Status Initlist(LinkList& L) {
    L = (LNode*)malloc(sizeof(LNode));
    if (!L)exit(0);
       
    
    L->next = NULL;
    return 1;
    
}
//����ָ��������ʼ��
Status createList(LinkList &L, int len) {
    ElemType e;
   
    LNode *r,*n;
   
    r = L;
    for (int i = 0; i < len; i++) {
        scanf("%d", &e);
        n = (LNode*)malloc(sizeof(LNode*));//����ռ�
        if (!n)exit(0);
        n->val = e;
        n->next = NULL;
        r->next = n;
        r = r->next;
    }
    return 1;
}
//ȡ��
int getLen(LinkList  L) {
    int count = 0;
    while (L ->next!= NULL) {
        L = L->next;
        count++;
    }return count;



}
//ֵ����
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
//λ�����
int seach1LinkList(LinkList L, int pos) {
    if (pos<1 || pos>getLen(L))return -1;
    while (pos--) {
        L = L->next;
       
    } return L->val;
}
//�޸�
Status modifyLinkList(LinkList& L, int pos, ElemType e) {
    if(pos<1||pos>getLen(L) + 1) return -1;
    LNode* r;
    r = L;
    while (--pos) {
        r = r->next;
    }r->next->val = e;


    return 1;


}
//����
Status insertLinkList(LinkList &L, int pos, ElemType e) {
    if (pos < 1 || pos > getLen(L) + 1) return -1; //����λ�ô���
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
//ɾ��
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
//��ӡ
void printLinkList(LinkList L) {
    LNode* node;
    node = L->next;
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
}
//��������
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
//�п�
void ListIsEmpty(LinkList &L)
{
    if (L == NULL) {
        printf("��");
    }
    else {
        printf("�ǿ�");
    }
}