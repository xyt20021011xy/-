#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
void ShellInsert(int *pInt, int i);

int Partition(int *pInt, int low, int high);

void Merge(int *pInt, int low, int mid, int high);

void Distribute(int *pInt, queue<int> pQueue[10], int i);

void Collect(int *pInt, queue<int> pQueue[10]);


int n;
//sort
void ssort(int b[]){
    sort(b,b+n);
}
//希尔排序
void sort1(int b[]){
    int k;
    int dlta[3]={5,3,1};
    int t=3;
    for(k=0;k<t;++k)
        ShellInsert(b,dlta[k]);

}
void ShellInsert(int *pInt, int dk) {
    int t;
    for(int i=dk;i<n;i++){
        if(pInt[i]<pInt[i-dk]){
            t=pInt[i];
            int j;
            for(j=i-dk;j>=0&&(pInt[j]>t);j=j-dk){
                pInt[j+dk]= pInt[j];
            }pInt[j+dk]=t;
        }
    }
}
//插入排序
void sort2(int b[]){
    int t,j;
    for(int i=1;i<n;i++){
        if(b[i]<b[i-1]){
            t=b[i];
            for(j=i-1;j>=0&&b[j]>t;j--){
                b[j+1]=b[j];
            }b[j+1]=t;
        }
    }
}
//快速排序
void sort3(int b[],int low,int high){
    int  pivotloc;
    if(low<high)
    {
        pivotloc = Partition(b, low, high ) ;
        sort3(b, low, pivotloc-1) ;
        sort3(b, pivotloc+1, high );
    }
}
int Partition(int *pInt, int low, int high) {
    int t=pInt[low];
    while(low<high){
        while(pInt[high]>=t&&high>low)high--;
        pInt[low]=pInt[high];
        while(pInt[low]<=t&&low<high)low++;
        pInt[high]=pInt[low];

    }pInt[low]=t;
    return low;

}
//冒泡排序
void sort4(int b[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(b[j+1]<b[j]){
                int t=b[j];
                b[j]=b[j+1];
                b[j+1]=t;
            }
        }
    }
}
//归并排序
void sort5(int b[],int low,int high){
    if( low == high ) return;
    else{
        int mid=(low+high)/2;
        sort5(b, low , mid); //左侧递归
        sort5(b, mid+1, high);//右侧递归
        Merge(b, low, mid, high); //归并
    }
}
void Merge(int *R, int low, int mid, int high) {
    int left=low,right=mid+1,result=low;
    int T[n];
    while(left<=mid &&right<=high ){
        if(R[left]<R[right]){
            T[result++]=R[left++];
        }
        else{
            T[result++]=R[right++];
        }
    }
    while(left<=mid){
        T[result++]=R[left++];
    }
    while(right<=high ) {
        T[result++]=R[right++];
    }
    for(int i=low;i<=high;i++) R[i]=T[i];
}
//基数排序
void sort6(int b[]){
    queue<int>bucketArray[10];
    int max=-99999;
    for(int i=0;i<n;i++){
        if(max<b[i]){
            max=b[i];
        }
    }int count=0;
    while(max>0){
        max=max/10;
        count++;
    }
    for(int i=1;i<=count;i++){
        Distribute(b, bucketArray, i);
        Collect(b, bucketArray);

    }
}
void Collect(int *pInt, queue<int> pQueue[10]) {
    int j=0;
    for(int i=0;i<10;i++){
        while(!pQueue[i].empty()){
            pInt[j++]=pQueue[i].front();
            pQueue[i].pop();
        }
    }
}

void Distribute(int *pInt, queue<int> pQueue[10], int i) {
    for(int j=0;j<n;j++){
        int x=i,c=pInt[j];
        while(--x){
            c=c/10;
        } int radix=c%10;
        pQueue[radix].push(pInt[j]);
    }
}

int main(){
    cin>>n;
    int b[n];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    //ssort(b);
    //sort1(b);
    //sort2(b);
    //sort3(b,0,n-1);
    //sort4(b);
    //sort5(b,0,n-1);
    sort6(b);




    int fl=1;
    for(int i=0;i<n;i++){
        if(fl){
            fl=0;
            printf("%d",b[i]);
        } else printf(" %d",b[i]);
    }
}