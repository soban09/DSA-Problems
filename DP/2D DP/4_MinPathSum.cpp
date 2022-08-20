#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

// fixed starting to fixed ending

int MinPathSum(vector<vector<int>> grid, int m, int n, vector<vector<int>> &dp){
    if(m==0 && n==0)
        return grid[0][0];
    if(m<0 || n<0)
        return INT16_MAX;
    if(dp[m][n]!=-1)
        return dp[m][n];
    
    int up = grid[m][n]+MinPathSum(grid,m-1,n,dp);
    int left = grid[m][n]+MinPathSum(grid,m,n-1,dp);
    return dp[m][n]=min(up,left);
}

int MinPathSumDP(vector<vector<int>> grid){
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n,-1));
    
    dp[0][0]=grid[0][0];
    for(int i=1; i<m; i++)
        dp[i][0]=grid[i][0]+dp[i-1][0];
    for(int i=1; i<n; i++)
        dp[0][i]=grid[0][i]+dp[0][i-1];
   
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            dp[i][j]=grid[i][j]+min(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}

int MinPathSumDPSO(vector<vector<int>> grid){
    int m=grid.size();
    int n=grid[0].size();
    vector<int> prv(n,-1);
    
    // dp[0]=grid[0][0];
    // for(int i=1; i<m; i++)
    //     dp[i][0]=grid[i][0]+dp[i-1][0];
    // for(int i=1; i<n; i++)
    //     dp[0][i]=grid[0][i]+dp[0][i-1];

    //do this or inside following loop
   
    for(int i=0; i<m; i++){
        vector<int> temp(n,-1);

        for(int j=0; j<n; j++){
            if(i==0 && j==0)
                temp[j]=grid[0][0];
            else{
                int up=grid[i][j];
                if(i>1) up+=prv[j];
                else up=INT16_MAX;

                int left=grid[i][j];
                if(j>1) left+=temp[j-1];
                else left=INT16_MAX;

                temp[j]=min(up,left);
            }
        }
        prv=temp;
    }
    return prv[n-1];
}

int main()
{   vector<vector<int>> grid{{5, 9, 6},{11, 5, 2}};
    vector<vector<int>> dp(2, vector<int>(3,-1));
    cout<<MinPathSum(grid,1,2,dp)<<endl;
    cout<<MinPathSumDP(grid)<<endl;
    cout<<MinPathSumDPSO(grid);
    return 0;
}