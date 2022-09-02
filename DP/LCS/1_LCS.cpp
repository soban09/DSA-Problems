#include<bits/stdc++.h>
using namespace std;

int dp1[10][10];

int LCS(string x, string y, int n, int m){
    if(n==0 || m==0) return 0;

    if(x[n-1]==y[m-1])
        return 1+LCS(x,y,n-1,m-1);
    
    return max(LCS(x,y,n-1,m), LCS(x,y,n,m-1));
}

int LCSMem(string x, string y, int n, int m){
    if(n==0 || m==0){
        dp1[0][0] = 0;
        return 0;
    }
    if(dp1[n][m]!=-1){
        return dp1[n][m];
    }

    if(x[n-1]==y[m-1]){
        dp1[n][m] = 1+LCSMem(x,y,n-1,m-1);
        return dp1[n][m];
    }
    
    dp1[n][m] = max(LCSMem(x,y,n-1,m), LCSMem(x,y,n,m-1));
    return dp1[n][m];
}

int LCSDP(string x, string y, int n, int m){
    int dp[n+1][m+1];
    dp[0][0] = 0;

    for(int i=0; i<=n; i++) dp[i][0]=0;
    for(int i=0; i<=m; i++) dp[0][i]=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i-1]==y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    memset(dp1,-1,sizeof(dp1));
    string x = "abcdgh";
    string y = "abedfhr";
    cout<<LCS(x, y, x.size(), y.size())<<endl;
    cout<<LCSMem(x, y, x.size(), y.size())<<endl;
    cout<<LCSDP(x, y, x.size(), y.size());
return 0;
}