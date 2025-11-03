#include<stdio.h>
void sort(int arr1[],int arr2[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr1[j]>arr1[j+1]){
                int t=arr1[j];
                arr1[j]=arr1[j+1];
                arr1[j+1]=t;
                int k=arr2[j];
                arr2[j]=arr2[j+1];
                arr2[j+1]=k;
            }
        }
    }
}

int activity_selection(int activities[][2],int num_activities){
    int j=0;
    int count=1;
    printf("{%d,%d}",activities[0][0],activities[0][1]);
    for(int i=1;i<num_activities;i++){
        if (activities[i][0] >= activities[j][1]){
            count+=1;
            j=i;
            printf("{%d,%d}",activities[i][0],activities[i][1]);
        }
    }
}

int main(){
    int start[]={1,3,0,5,3,5,6,8,8,2,12};
    int finish[]={4,5,6,7,9,9,10,11,12,14,16};
    int num_activities=sizeof(start)/sizeof(start[0]);
    sort(finish,start,num_activities);
    int activities[num_activities][2];
    for(int i=0;i<num_activities;i++){
        activities[i][0]=start[i];
        activities[i][1]=finish[i];
    }
    activity_selection(activities,num_activities);
}