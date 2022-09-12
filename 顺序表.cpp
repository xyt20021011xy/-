#include<iostream>
#include<malloc.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
using namespace std;
typedef int ElemType;
typedef int Status;
typedef struct
{
	int length;
	int Maxsize;
	ElemType* date;
}SqList;
int main() {
	SqList L;
	InitList(L);
}
Status InitList(SqList& L) {
	L.date = (ElemType*)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
	if (!L.date) {
		return -1;
	}
	L.length = 0;
	L.Maxsize = LIST_INIT_SIZE;
	return 1;
}
Status Insert(SqList& L,int i,ElemType e)
{
	if (i<1 || i>L.length + 1) {
		return 0;
	}if (L.length >= L.Maxsize) {
		
		L.date = (ElemType*)realloc(L.date, (LIST_INIT_SIZE + LISTINCREMENT) * sizeof(ElemType));
		if (!L.date) {
			exit(0);
		}
	}
	L.Maxsize += LISTINCREMENT;
	ElemType* q = L.date + i - 1;
	ElemType* p= L.date + L.length - 1;
	while (p >= q) {
		*(p + 1) = *p;
		p--;
	}*q = e;
	++L.length;
	return 1;

}
Status comapre(ElemType a, ElemType b) {
	if (a == b) {
		return 1;
	}
	return 0;
}
int Location(SqList L, Status(*comapre(ElemType, ElemType)), ElemType e) {
	ElemType* p = L.date;
	int i = 1;
	while (i <= L.length && comapre(*p, e) == 0) {
		++p;
		++i;
	}if (i < L.length) {
		return i;
	}
	else {
		return 0;
	}



}Status Delete(SqList& L, int i, ElemType& e) {
	if (i<1 || i>L.length)return 0;
	ElemType* p = &L.date[i - 1], * q = L.date+ L.length - 1;
	e = *p;
	while (p < q) {
		*p = *(p + 1);
		p++;
	}
	L.length--;
	return 1;
}//Ïú»Ù
void destroy(SqList &L){

	L.length = 0;
	L.Maxsize = 0;
	free(L.date);
	L.date = NULL;
}
