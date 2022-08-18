#include<iostream>
#include<vector>
using namespace std;

int frogjump(int *arr, int idx, vector<int> &dp){
    if(idx<=0)
        return dp[idx]=0;

    if(dp[idx]!=-1)
        return dp[idx];
    
    int left,right;
    left = frogjump(arr,idx-1,dp) + abs(arr[idx]-arr[idx-1]);
    if(idx>1)
        right = frogjump(arr,idx-2,dp) + abs(arr[idx]-arr[idx-2]);

    return dp[idx]=min(left,right);
}

int frogJumpDP(int *arr, int n){
    // int dp[n]={-1};
    // dp[0]=0;
    // for(int i=1; i<n; i++){
    //     int left,right;
    //     left = dp[i-1] + abs(arr[i]-arr[i-1]);
    //     if(i>1)
    //         right = dp[i-2] + abs(arr[i]-arr[i-2]);
    //     dp[i]=min(left,right);
    // }
    // return dp[n];

    //space optimisation
    int prev=0,prev2=0;
    for(int i=1; i<n; i++){
        int left,right=INT16_MAX;
        left = prev + abs(arr[i]-arr[i-1]);
        if(i>1)
            right = prev2 + abs(arr[i]-arr[i-2]);
        int curr=min(left,right);

        prev2=prev;
        prev=curr;
    }
    return prev;
}

int frogKJump(int *arr, int idx, int k, vector<int> &dp){
    if(idx<=0)
        return 0;
    if(dp[idx]!=-1)
        return dp[idx];
    
    int mn=INT16_MAX;
    for(int j=1; j<=k; j++){
        if(idx<j) break;
        mn = min(mn, frogKJump(arr,idx-j,k,dp) + abs(arr[idx]-arr[idx-j]));
    }
    return dp[idx]=mn;
}

int frogKJumpDP(int *arr, int n, int k){
    int dp[n]={-1};

    for(int i=1; i<n; i++){
        int mn=INT16_MAX;
        for(int j=1; j<=k; j++){
            if(i<j) break;

            mn = min(mn, dp[i-j]+abs(arr[i]-arr[i-j]));
        }
    }
    return dp[n-1];
}

int main()
{
    int arr[]={10,20,30,10};
    vector<int> dp(4,-1);
    cout<<frogjump(arr,3,dp)<<endl;
    cout<<frogJumpDP(arr,4)<<endl;
    return 0;
}