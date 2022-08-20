#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

// fixed starting to variable ending

using vi = vector<int>;
using vvi = vector<vi>;

int TriangleMinPathSum(vvi tri, int n, int i, int j, vvi &dp){
    if(i==n-1)
        return tri[i][j];

    if(dp[i][j]!=-1)
        return dp[i][j];

    int down = tri[i][j] + TriangleMinPathSum(tri, n, i+1, j, dp);
    int dia = tri[i][j] + TriangleMinPathSum(tri, n, i+1, j+1, dp); 

    return dp[i][j]=min(dia,down);
}

int TriangleMinPathSumDP(vvi tri, int n){
    vvi dp(n, vi(n,-1));
    for(int j=0; j<n; j++){
        dp[n-1][j]=tri[n-1][j];
    }

    for(int i=n-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            int down = tri[i][j] + dp[i+1][j];
            int dia = tri[i][j] + dp[i+1][j+1];

            dp[i][j]=min(down,dia);
        }
    }
    return dp[0][0];
}

int TriangleMinPathSumDPSO(vvi tri, int n){
    vi prv(n,-1);
    for(int j=0; j<n; j++){
        prv[j]=tri[n-1][j];
    }

    for(int i=n-2; i>=0; i--){
        vi temp(i+1,-1);
        for(int j=n-2; j>=0; j--){
            int down = tri[i][j] + prv[j];
            int dia = tri[i][j] + prv[j+1];

            temp[j]=min(down,dia);
        }
        prv.pop_back(); //to make it same size of tmp
        prv=temp;
    }
    return prv[0];
}

int main()
{   vvi tri = {{1},{2,3},{3,6,7},{8,9,6,10}};
    vvi dp(4, vi(4, -1));
    cout<<TriangleMinPathSum(tri,4,0,0,dp)<<endl;
    cout<<TriangleMinPathSumDP(tri,4)<<endl;
    cout<<TriangleMinPathSumDPSO(tri,4);
    return 0;
}