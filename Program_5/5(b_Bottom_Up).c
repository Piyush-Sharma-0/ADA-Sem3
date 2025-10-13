#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int a,int b){
    return (a>b)?a:b; 
}

int knapsack_dp(int n,int capacity,int value[],int weight[]){
    int** dp=(int**)malloc((n+1)*sizeof(int*));
    for(int i=0;i<=n;i++){
        dp[i]=(int*)malloc((capacity+1)*sizeof(int));
        for(int w=0;w<=capacity;w++){
            dp[i][w]=0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int w=1;w<=capacity;w++){
            if(weight[i-1]<=w)
                dp[i][w]=max(value[i-1]+dp[i-1][w-weight[i-1]], dp[i-1][w]);
            else
                dp[i][w]=dp[i-1][w];
        }
    }
    int result=dp[n][capacity];
    for(int i=0;i<=n;i++) free(dp[i]);
    free(dp);
    return result;
}

int main(){
    int n=1000, capacity=300;
    int value[n], weight[n];
    for(int i=0;i<n;i++){
        value[i]=rand()%100+1;
        weight[i]=rand()%10+1;
    }

    FILE* f=fopen("knapsack_times.txt","a");
    if(!f){ printf("Cannot open file\n"); return 1; }

    clock_t start=clock();
    for(int i=0;i<1000;i++){
        double result=knapsack_dp
    (n,capacity,value,weight);
    }
    clock_t end=clock();
    double time_taken=(double)(end-start)/CLOCKS_PER_SEC/1000;

    fprintf(f,"0/1 DP approach %f\n",time_taken);
    fclose(f);
    printf("0/1 DP approach %f\n",time_taken);
    return 0;
}