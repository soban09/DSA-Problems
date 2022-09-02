#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

// how to store -1 dp state, just do a coordinate shift
int LIS(int *arr, int i, int prv, int n, vvi &dp){
    if(i>=n)
        return 0;

    if(dp[i][prv+1]!=-1)
        return dp[i][prv+1];

    if(prv==-1 || arr[i]>arr[prv]){
        return dp[i][prv+1] = max(1 + LIS(arr,i+1,i,n,dp), LIS(arr,i+1,prv,n,dp));
    }
    return dp[i][prv+1]=LIS(arr,i+1,prv,n,dp);
}

// int LISDP(int *arr){

// }

int main(){
    int arr[] = {1,2,3,4,1,2};
    int n=6;
    vvi dp(n,vi(n,-1));
    cout<<LIS(arr,0,-1,n,dp);
    return 0;
}