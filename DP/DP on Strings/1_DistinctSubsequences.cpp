#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

//  x>y
int DistinctSubsequences(string x, string y, int m, int n){
    //first always return condition of n, because as soon as it depleted we need 1
    if(n<0) return 1;
    if(m<0) return 0;

    if(x[m]==y[n])
        return DistinctSubsequences(x,y,m-1,n-1)+DistinctSubsequences(x,y,m-1,n);
    return DistinctSubsequences(x,y,m-1,n);
}

int DistinctSubsequencesDP(string x, string y){
    int m=x.size();
    int n=y.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1));

    //for every j=0 it would be 1, cuz we aint got any string to find, if we take none from x, we get 1
    dp[0][0]=1;
    for(int i=1; i<=m; i++) dp[i][0]=1;
    for(int i=1; i<=n; i++) dp[0][i]=0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(x[i-1]==y[j-1])
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[m][n];
}

int main()
{
    string x="rabbbit";
    string y="rabbit";
    cout<<DistinctSubsequences(x,y,x.size()-1,y.size()-1)<<endl;
    cout<<DistinctSubsequencesDP(x,y)<<endl;
    return 0;
}