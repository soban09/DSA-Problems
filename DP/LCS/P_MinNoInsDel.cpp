//a derivative of LCS

#include<iostream>
using namespace std;

int ShortestCommonSupSeq(string x, string y, int n, int m){
    int dp[n+1][m+1];

    dp[0][0]=0;
    for(int i=1; i<=n; i++) dp[i][0]=0;
    for(int i=1; i<=m; i++) dp[0][i]=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i-1]==y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main(){
    string x = "heap";
    string y = "pea";
    int LCS = ShortestCommonSupSeq(x,y,x.size(), y.size());
    cout<<"Ins = "<<y.size()-LCS<<endl;
    cout<<"Del = "<<x.size()-LCS;
return 0;
}