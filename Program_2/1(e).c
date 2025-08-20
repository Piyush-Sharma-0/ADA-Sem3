#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<high;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }

    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;

    return i+1;
}

int quick_sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quick_sort(arr,low,pi-1);
        quick_sort(arr,pi+1,high);
    }
    return 0;
}


void generateRandomArray(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i]=rand()%10000;
    }
}

int main(){
    int n;
    printf("Enter total elements int the array");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    generateRandomArray(arr,n);
    clock_t start=clock();

    for(int i=0;i<1000;i++){
        quick_sort(arr,0, n-1);
    }
    clock_t end=clock();
    printf("Array is-\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    double time= ((double)(end=start))/CLOCKS_PER_SEC/1000;
    printf("Time taken=%f",time);
    
}