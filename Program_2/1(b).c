#include <stdio.h>
void selection_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[m]){
                m=j;
            }
        }
        int t=a[m];
        a[m]=a[i];
        a[i]=t;
    }
}
int main(){
    int a[]={5,2,9,1,5,6};
    int n=6;
    selection_sort(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
