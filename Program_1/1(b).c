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

void generateRandomArray(int arr[],int n){
    for(int i=0;i<n;i++) arr[i]=rand()%10000;
}

int compare(const void* a,const void* b){
    return (*(int*)a-*(int*)b);
}

int generateRandomKey(int arr[],int n){
    int index=1+rand()%(n-1);
    return arr[index];
}


int main(){
    int sizes[]={10,50,100,500,1000,2000,3000,5000,7000,10000};
    int num_sizes=9;
    srand(time(NULL));

    for(int i=0;i<num_sizes;i++){
        int n=sizes[i];
        int* arr=(int*)malloc(n*sizeof(int));
        generateRandomArray(arr,n);
        qsort(arr,n,sizeof(int),compare);

        int key=generateRandomKey(arr,n);

        clock_t start=clock();
        for(int k=0;k<10000;k++){
            binary_search(arr,n,key);
        }
        clock_t end=clock();

        double time=((double)(end-start))/CLOCKS_PER_SEC/10000;
        printf("For input size %d time taken = %f\n",n,time);

        free(arr);
    }
    return 0;
}
