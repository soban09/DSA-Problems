#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int solve(int *arr, int i, int j){
    if(i>=j) return 0;

    int mn = INT_MAX;

    for(int k=i; k<j; k++){
        int tempAns = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];

        if(tempAns < mn){
            mn = tempAns;
        }
    }
    return mn;
}

int solveMem(int *arr, int i, int j){
    if(i>=j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int mn = INT_MAX;

    for(int k=i; k<j; k++){
        int tempAns = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        
        mn = min(mn, tempAns);
    }
    dp[i][j] = mn;
    return dp[i][j];
}

int main(){
    int arr[] = {1,2,3,4};
    memset(dp,-1,sizeof(dp));
    cout<<solve(arr,1,3)<<endl;
    cout<<solveMem(arr,1,3);
return 0;
}