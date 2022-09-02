// Find Min No of coins to make the given sum
// A lil different than most of the ques
//req double intialization

#include<bits/stdc++.h>
using namespace std;

int CoinChange(int *coin, int n, int sum){
    if(n==0){
        if(sum%coin[0]==0)
            return sum/coin[0];
        else
            return 1e9;
    }

    int notTake = CoinChange(coin, n-1, sum);
    int take = INT16_MAX;
    if(coin[n]<=sum)
        take = 1 + CoinChange(coin, n, sum-coin[n]);
    return min(take, notTake);
}

int CoinChangeDP(int *coin, int n, int sum){
    int dp[n+1][sum+1];

    for(int i=0; i<=sum; i++){
        if(i%coin[0]==0)
            dp[0][i]=i/coin[0];
        else
            dp[0][i]=1e9;
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(coin[i-1]<=j){
                dp[i][j] = min(1+dp[i][j-coin[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }

            // or

            // int notTake = dp[i-1][j];
            // int take=INT_MAX;
            // if(coin[i-1]<=j)
            //     take = 1+dp[i][j-coin[i-1]];
            // dp[i][j]=min(take, notTake);
        }
    }
    return dp[n][sum]>=INT_MAX-1 ? -1 : dp[n][sum];
}

int main(){
    int coin[] = {1,2,5};
    cout<<CoinChange(coin,3,11)<<endl;
    cout<<CoinChangeDP(coin,3,11);
    return 0;
}