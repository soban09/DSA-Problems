// dp[i][j] = how many sqaures ones matrices which end up at right most bottom i,j
// Approach : find min of up left and upleft, and add 1 only if all are >0, means they form either sqaures of 1 size, 2 size etc
// but either of them is ==0 means they do dont form a sqaure, then your ans is only 1

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;


int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n,0));
        int ans=0;

        for(int i=0; i<m; i++){
            if(matrix[i][0]==1) dp[i][0]=1;
            ans+=dp[i][0];
        }
        for(int j=1; j<n; j++){
            if(matrix[0][j]==1) dp[0][j]=1;
            ans+=dp[0][j];
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j]==1){
                    if(dp[i-1][j-1]>0 && dp[i-1][j]>0 && dp[i][j-1]>0)
                        dp[i][j] = 1+min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
                    else
                        dp[i][j]++;
                }
                ans+=dp[i][j];
            }
        }

        return ans;
    }


int main(){
    return 0;
}

// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]