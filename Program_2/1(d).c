#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[],int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int L[n1],R[n2];

    for(int i=0;i<n1;i++) L[i]=arr[left+i];
    for(int i=0;i<n2;i++) R[i]=arr[mid+1+i];

    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

void merge_sort(int arr[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void generateRandomArray(int arr[],int n){
    for(int i=0;i<n;i++) arr[i]=rand()%10000;
}

int main(){
    int sizes[]={10,50,100,500,1000,3000,6000,7000,8000};
    int num_sizes=9;

    for(int i=0;i<num_sizes;i++){
        int n=sizes[i];
        int* arr=(int*)malloc(n*sizeof(int));
        int* temp=(int*)malloc(n*sizeof(int));
        generateRandomArray(arr,n);

        for(int j=0;j<n;j++) temp[j]=arr[j];

        clock_t start=clock();
        for(int k=0;k<1000;k++){
            for(int j=0;j<n;j++) arr[j]=temp[j];
            merge_sort(arr,0,n-1);
        }
        clock_t end=clock();

        double time=((double)(end-start))/CLOCKS_PER_SEC/1000;
        printf("For input size %d time taken = %f\n",n,time);

        free(arr);
        free(temp);
    }
    return 0;
}
