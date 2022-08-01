//Unbounded KnapSack

#include<iostream>
using namespace std;

int KnapSack(int *v, int *wt, int W, int n){
    if(n==0 || W==0) return 0;

    if(wt[n-1]<=W){
        return max(v[n-1]+KnapSack(v,wt,W-wt[n-1],n) ,KnapSack(v,wt,W,n-1));
    }
    return KnapSack(v,wt,W,n-1);
}

int UKnapSack(int *v, int *wt, int W, int n){
    int dp[n+1][W+1];

    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int i=0; i<=W; i++) dp[0][i] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(wt[i-1]<=j){
                dp[i][j] = max(v[i-1]+dp[i][j-wt[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main(){
    int wt[] = {1,1,3,4};
    int v[] = {1,3,5,9};

    cout<<KnapSack(v,wt,12,4)<<endl;
    cout<<UKnapSack(v,wt,12,4);
return 0;
}