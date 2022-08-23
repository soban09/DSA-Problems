//same problem as count Subset sum difference

//NOTE : will have the same problem is array contains 0 

#include<iostream>
using namespace std;

int SubSetSum(int *arr, int n, int sum){
    int dp[n+1][sum+1];

    dp[0][0] = 1;

    //will cause problem
    // for(int i=1; i<=n; i++) dp[i][0] = 1;
    for(int i=1; i<=sum; i++) dp[0][i] = 0;

    for(int i=1; i<=n; i++){

        //run from zero
        for(int j=0; j<=sum; j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int TargetSum(int *arr, int n, int diff){
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    
    if((diff+sum)%2!=0) return 0;

    return SubSetSum(arr, n, (diff+sum)/2);
}

int main(){
    int arr[] = {1,1,2,3};
    cout<<TargetSum(arr,4,1);
return 0;
}