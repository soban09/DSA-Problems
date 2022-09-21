#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int EditDistance(string x, string y, int i, int j, vvi &dp){
    if(i<0) return j+1;
    if(j<0) return i+1;

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(x[i]==y[j])
        return dp[i][j]=EditDistance(x,y,i-1,j-1, dp);
    
    // order of calls: insertion, deletion, replace
    return dp[i][j] = 1+min({EditDistance(x,y,i,j-1,dp), EditDistance(x,y,i-1,j,dp), EditDistance(x,y,i-1,j-1,dp)});
}

int EditDistanceDP(string x, string y){
    int m=x.size();
    int n=y.size();

    vvi dp(m+1, vi(n+1, -1));

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0)
                dp[i][j]=j;

            else if(j==0)
                dp[i][j]=i;

            else if(x[i-1]==y[j-1])
                dp[i][j] = dp[i-1][j-1];

            else
                dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
        }
    }

    return dp[m-1][n-1];
}

int EditDistanceDPSO(string x, string y){
    int m=x.size();
    int n=y.size();

    vi prv(n+1, -1);

    for(int i=0; i<=m; i++){
        vi tmp(n+1, -1);

        for(int j=0; j<=n; j++){
            if(i==0)
                prv[j]=j;

            else if(j==0)
                tmp[j]=i;

            else if(x[i-1]==y[j-1])
                tmp[j] = prv[j-1];

            else
                tmp[j] = 1 + min({tmp[j-1], prv[j], prv[j-1]});
        }
        prv=tmp;
    }

    return prv[n-1];
}

int main()
{
    vvi dp(5, vi(3, -1));
    cout<<EditDistance("horse", "ros", 4, 2, dp)<<endl;
    cout<<EditDistanceDP("horse", "ros")<<endl;
    cout<<EditDistanceDPSO("horse", "ros")<<endl;
    return 0;
}