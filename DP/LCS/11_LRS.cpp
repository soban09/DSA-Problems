//a derivative of LCS

#include<iostream>
using namespace std;

int LRS(string x, int n){
    int dp[n+1][n+1];

    // dp[0][0]=0;
    // for(int i=1; i<=n; i++) dp[i][0]=0;
    // for(int i=1; i<=n; i++) dp[0][i]=0;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(i!=j and x[i-1]==x[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}

int main(){
    string x = "axxzxy";
    cout<<LRS(x,x.size());
return 0;
}