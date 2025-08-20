#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(int arr[],int n,int key){
    int start=0,end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]<key) start=mid+1;
        else end=mid-1;
    }
    return -1;
}

void generateSortedArray(int arr[],int n){
    for(int i=0;i<n;i++) arr[i]=i; // strictly sorted unique values
}

int main(){
    int sizes[]={10,50,100,500,1000,3000,6000,7000,8000};
    int num_sizes=9;

    for(int i=0;i<num_sizes;i++){
        int n=sizes[i];
        int* arr=(int*)malloc(n*sizeof(int));
        generateSortedArray(arr,n);

        int key=arr[n/2]; // middle element

        clock_t start=clock();
        for(int k=0;k<1000;k++){
            binary_search(arr,n,key);
        }
        clock_t end=clock();

        double time=((double)(end-start))/CLOCKS_PER_SEC/1000;
        printf("For input size %d time taken = %f\n",n,time);

        free(arr);
    }
    return 0;
}
