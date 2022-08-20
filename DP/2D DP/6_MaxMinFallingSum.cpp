#include<iostream>
#include <algorithm>
using namespace std;

// variable starting to variable ending

using vi = vector<int>;
using vvi = vector<vi>;
int m,n;

int MaxMinFallingSum(vvi grid, int i, int j, vvi &dp){
    if(j<0 || j>=n)
        return -1e8;
    if(i==0)
        return grid[i][j];
    if(dp[i][j]!=-1)
        return dp[i][j];

    int up = grid[i][j] + MaxMinFallingSum(grid, i-1, j, dp);
    int rdia = grid[i][j] + MaxMinFallingSum(grid, i-1, j+1, dp);
    int ldia = grid[i][j] + MaxMinFallingSum(grid, i-1, j-1, dp);
    
    return dp[i][j]=max({up, rdia, ldia});
}

int MaxMinFallingSumDP(vvi grid){
    vvi dp(m, vi(n,-1));

    for(int j=0; j<n; j++){
        dp[0][j]=grid[0][j];
    }

    for(int i=1; i<m; i++){
        for(int j=0; j<n; j++){
            int up = grid[i][j] + dp[i-1][j];

            int ldia=-1e8, rdia=-1e8;
            if(j>0) ldia = grid[i][j] + dp[i-1][j-1];
            if(j<n-1) rdia = grid[i][j] + dp[i-1][j+1];

            dp[i][j] = max({up,ldia,rdia});
        }
    }
    
    int mx=-1e8;
    for(int j=0; j<n; j++){
        mx= max(mx, dp[m-1][j]);
    }
    return mx;
}

int MaxMinFallingSumDPSO(vvi grid){
    vi prv(n,-1);

    for(int j=0; j<n; j++){
        prv[j]=grid[0][j];
    }

    for(int i=1; i<m; i++){
        vi tmp(n,-1);
        for(int j=0; j<n; j++){
            int up = grid[i][j] + prv[j];

            int ldia=-1e8, rdia=-1e8;
            if(j>0) ldia = grid[i][j] + prv[j-1];
            if(j<n-1) rdia = grid[i][j] + prv[j+1];

            tmp[j] = max({up,ldia,rdia});
        }
        prv=tmp;
    }
    
    int mx=-1e8;
    for(int j=0; j<n; j++){
        mx= max(mx, prv[j]);
    }
    return mx;
}

int main()
{   vvi grid{{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};
    m=4,n=4;
    vvi dp(m, vi(n, -1));
    int mx=-1e8;
    for(int j=0; j<n; j++){
        mx = max(mx, MaxMinFallingSum(grid, m-1, j, dp));
    }
    cout<<mx<<endl;
    cout<<MaxMinFallingSumDP(grid)<<endl;
    cout<<MaxMinFallingSumDPSO(grid)<<endl;
    return 0;
}