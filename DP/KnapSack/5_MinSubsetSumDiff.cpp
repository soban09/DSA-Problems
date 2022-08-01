//A derivative problem of subset sum and equal sum partition

#include<bits/stdc++.h>
using namespace std;

bool **SubsetSum(int *arr, int n, int sum){

    // bool dp[n+1][sum+1];
    //to return the array making it dynamically allotted
    
    bool **dp = new bool*[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = new bool[sum+1];
    }


    dp[0][0] = true;
    for(int i=1; i<=n; i++) dp[i][0] = true;
    for(int i=1; i<=sum; i++) dp[0][i] = false;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp;
}

int MinSubSetSumDiff(int *arr, int n){

    int sum=0, ans=INT_MAX;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }

    bool **dp = SubsetSum(arr,n,sum);
    for(int i=0; i<=sum/2; i++){
        if(!dp[n][i]){
            continue;
        }
        ans = min(ans, sum-2*i);
    }
    return ans;
}

int main(){
    int arr[] = {1,2,7};
    cout<<MinSubSetSumDiff(arr,3);

return 0;
}