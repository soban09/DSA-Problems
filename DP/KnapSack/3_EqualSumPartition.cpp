//A KnapSack derivative problem
//same as subset sum problem

#include<iostream>
using namespace std;

bool EqualSumPartition(int *arr, int n){
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }

    if(sum%2!=0) return false;
    sum=sum/2;

    //after this it is just subset sum problem

    int dp[n+1][sum];
    dp[0][0]=true;

    for(int i=1; i<=n; i++) dp[i][0]=true;
    for(int i=1; i<=sum; i++) dp[0][i]=false;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1]<=sum){
                dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
} 

int main(){
    int arr[] = {1,5,5,11};
    if(EqualSumPartition(arr,4)) cout<<"Yes";
    else cout<<"No";
return 0;
}