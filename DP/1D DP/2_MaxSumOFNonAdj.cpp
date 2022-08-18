#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int MaxSumOfNonAdj(int *arr, int idx, vector<int> &dp){
    //index 1 was picked
    if(idx<0)
        return 0;

    //index was 2 picked and 1 aint and hence 0 was called
    if(idx==0)
        return dp[0]=arr[idx];

    if(dp[idx]!=-1)
        return dp[idx];
    
    int notPicked = MaxSumOfNonAdj(arr,idx-1, dp);
    int picked = arr[idx] + MaxSumOfNonAdj(arr, idx-2, dp);
    return dp[idx]=max(notPicked, picked);
}

int MaxSumOfNonAdjDP(int *arr, int n){
    vector<int> dp(n, -1);
    //if 2 is picked 0 will always be picked
    dp[0]=arr[0];
    //if 1 is picked and hence you call -ve indices
    int neg=0;

    for(int i=1; i<n; i++){
        int picked = arr[i];

        //to avoid index out of bounds
        if(i>1)
            picked+=dp[i-2];
        
        int notPicked = dp[i-1];
        dp[i]=max(picked, notPicked);
    }
    return dp[n-1];
}

int MaxSumOfNonAdjDPSO(int *arr, int n){
    // vector<int> dp(n, -1);
    // //if 2 is picked 0 will always be picked
    // dp[0]=arr[0];
    // //if 1 is picked and hence you call -ve indices
    // int neg=0;

    int prv=arr[0], prv2=0;

    for(int i=1; i<n; i++){
        int picked = arr[i];

        //to avoid index out of bounds
        if(i>1)
            picked+=prv2;
        
        int notPicked = prv;
        int curr=max(picked, notPicked);

        prv2=prv;
        prv=curr;
    }
    return prv;
}

int main()
{
    int arr[]={1,2,4,9};
    vector<int> dp(4,-1);
    cout<<MaxSumOfNonAdj(arr,3,dp)<<endl;
    cout<<MaxSumOfNonAdjDP(arr,4)<<endl;
    cout<<MaxSumOfNonAdjDPSO(arr,4);
    return 0;
}