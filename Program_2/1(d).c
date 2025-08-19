#include <stdio.h>

int merge(int arr[],int left,int mid,int right)
{
    int n1=mid-left+1;
    int n2=right-mid;
    int left_arr[n1],right_arr[n2];

    for(int i=0;i<n1;i++)
        left_arr[i]=arr[left+i];

    for(int i=0;i<n2;i++)
        right_arr[i]=arr[mid+1+i];

    int i=0,j=0,k=left;

    while(i<n1&&j<n2)
    {
        if(left_arr[i]<=right_arr[j])
        {
            arr[k]=left_arr[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=right_arr[j];
            j++;
            k++;
        }
    }

    while(i<n1)
        arr[k++]=left_arr[i++];

    while(j<n2)
        arr[k++]=right_arr[j++];

    return 0;
}

int merge_sort(int arr[],int left,int right)
{
    if(left<right)
    {
        int mid=left+(right-left)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
    return 0;
}

int main()
{
    int arr[5]={5,2,4,7,3};
    merge_sort(arr,0,4);
    for(int i=0;i<5;i++)
        printf("%d ",arr[i]);
}
