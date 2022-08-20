#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

// fixed starting to fixed ending

int uniquePaths(int m, int n, vector<vector<int>> &dp){
    if(m==0 && n==0)
        return 1;
    if(m<0 || n<0)
        return 0;
    if(dp[m][n]!=-1)
        return dp[m][n];
    return dp[m][n]=uniquePaths(m-1,n,dp)+uniquePaths(m,n-1,dp);
}

int uniquePathsDP(int m, int n){
    vector<vector<int>> dp(m, vector<int>(n,-1));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0)
                dp[0][0]=1;
            else{
                int up=0, left=0;
                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
    }
    return dp[m-1][n-1];
}

int uniquePathsDPSO(int m, int n){
    vector<int> prv(n,0);
    for(int i=0; i<m; i++){
        vector<int> temp(n,0);
        for(int j=0; j<n; j++){
            if(i==0 && j==0)
                temp[0]=1;
            else{
                int up=0, left=0;
                if(i>0) up=prv[j];
                if(j>0) left=temp[j-1];
                temp[j]=up+left;
            }
        }
        prv=temp;
    }
    return prv[n-1];
}

int uniquePathsPermutation(){
    
}

int main()
{   
    int m=4,n=3;
    vector<vector<int>> dp(m, vector<int>(n,-1));
    cout<<uniquePaths(m-1,n-1,dp)<<endl;
    cout<<uniquePathsDP(m,n)<<endl;
    cout<<uniquePathsDPSO(m,n)<<endl;
    return 0;
}