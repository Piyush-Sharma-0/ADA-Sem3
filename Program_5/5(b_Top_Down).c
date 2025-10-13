#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int a,int b){ return (a>b)?a:b; }

int knapsack_dp(int n,int capacity,int value[],int weight[],int** memo){
    if(n==0 || capacity==0) return 0;
    if(memo[n][capacity]!=-1) return memo[n][capacity];

    int pick=0;
    if(weight[n-1]<=capacity) pick=value[n-1]+knapsack_dp(n-1,capacity-weight[n-1],value,weight,memo);
    int notpick=knapsack_dp(n-1,capacity,value,weight,memo);
    memo[n][capacity]=max(pick,notpick);
    return memo[n][capacity];
}

int main(){
    int n=1000, capacity=300;
    int value[n], weight[n];
    for(int i=0;i<n;i++){
        value[i]=rand()%100+1;
        weight[i]=rand()%10+1;
    }

    int** memo=(int**)malloc((n+1)*sizeof(int*));
    for(int i=0;i<=n;i++){
        memo[i]=(int*)malloc((capacity+1)*sizeof(int));
        for(int j=0;j<=capacity;j++) memo[i][j]=-1;
    }

    FILE* f=fopen("knapsack_times.txt","a");
    if(!f){ printf("Cannot open file\n"); return 1; }

    clock_t start=clock();
    for(int i=0;i<1000;i++){
        double result=knapsack_dp(n,capacity,value,weight,memo);
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC/1000;

    fprintf(f,"0/1 DP TopDown %f\n",time_taken);
    fclose(f);

    for(int i=0;i<=n;i++) free(memo[i]);
    free(memo);

    // printf("0/1 TD Knapsack Value=%d\n",result);
    return 0;
}
