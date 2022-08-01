#include<bits/stdc++.h>
using namespace std;

int dp[10][10];

int KnapSack(int *val, int *wt, int W, int n){
    if(n==0 || W==0){
        return 0;
    }

    if(wt[n-1]<=W){
        return max(val[n-1]+KnapSack(val, wt, W-wt[n-1], n-1), KnapSack(val, wt, W, n-1));
    }
    return KnapSack(val, wt, W, n-1);
}

int KnapSackMemoize(int *val,int *wt, int W, int n){
    if(n==0 || W==0){
        dp[n][W]==0;
        return 0;
    }

    if(dp[n][W]!=-1){
        return dp[n][W];
    }

    if(wt[n-1]<=W){
        dp[n][W] = max(val[n-1]+KnapSack(val, wt, W-wt[n-1], n-1), KnapSack(val, wt, W, n-1));
        return dp[n][W];
    }

    dp[n][W] = KnapSack(val,wt,W,n-1);
    return dp[n][W];
}

int KnapSackDP(int *val, int *wt, int W, int n){
    int dp2[n+1][W+1];
    // memset(dp2, -1, sizeof(dp2));

    for(int i=0; i<=n; i++){
        dp2[i][0]=0;
    }
    for(int i=0; i<=W; i++){
        dp2[0][i]=0;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){

            if(wt[i-1]<=j){
                dp2[i][j] = max(val[i-1] + dp2[i-1][j-wt[i-1]], dp2[i-1][j]);
            }

            else{
                dp2[i][j] = dp2[i-1][j];
            }
        }
    }
    return dp2[n][W];
}

int main(){
    int n,W;
    cin>>n>>W;
    memset(dp, -1, sizeof(dp));

    int *val = new int[n];
    int *wt = new int[n];

    for(int i=0; i<n; i++){
        cin>>val[i]>>wt[i];
    }

    cout<<KnapSack(val,wt,W,n)<<endl;
    cout<<KnapSackMemoize(val,wt,W,n)<<endl;
    cout<<KnapSackDP(val,wt,W,n)<<endl;
return 0;
}