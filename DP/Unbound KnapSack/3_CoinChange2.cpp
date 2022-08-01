// Find Min No of coins to make the given sum
// A lil different than most of the ques
//req double intialization

#include<bits/stdc++.h>
using namespace std;

int CoinChange(int *coin, int n, int sum){
    int dp[n+1][sum+1];

    //the reason we intializing with INT_MAX-1 cuz we are adding 1 if we are choosing that coin

    //for row 1
    for(int i=0; i<=sum; i++) dp[0][i]=INT_MAX-1;
    //for coloumn 1
    for(int i=1; i<=n; i++) dp[i][0]=0;

    //for row 2
    for(int j=1; j<=sum; j++){
        if(j%coin[0]==0) 
            dp[1][j]=j/coin[0];
        else
            dp[1][j] = INT_MAX-1;
    }

    for(int i=2; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(coin[i-1]<=j){
                dp[i][j] = min(1+dp[i][j-coin[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum]>=INT_MAX-1 ? -1 : dp[n][sum];
}

int main(){
    int coin[] = {1,2,5};
    cout<<CoinChange(coin,3,11);
    return 0;
}