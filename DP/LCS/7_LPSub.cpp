#include<bits/stdc++.h>
using namespace std;

int LPSub(string x, string y, int n, int m){
    int dp[n+1][m+1];

    dp[0][0] = 0;
    for(int i=1; i<=n; i++) dp[i][0]=0;
    for(int i=1; i<=m; i++) dp[0][i]=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i-1]==y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = 0;
        }
    }
    int mx = 0;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            mx = max(mx,dp[i][j]);
        }
    }
    return mx;
}

int main(){
    string x = "agbcba";
    string y = x;
    reverse(y.begin(), y.end());

    cout<<LPSub(x,y,x.size(), y.size());
return 0;
}