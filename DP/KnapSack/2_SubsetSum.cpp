//A derivative of knapSack problem

#include<iostream>
using namespace std;

bool SubsetSum(int *arr, int n, int sum){
    if(sum==0){
        return true;
    }

    if(n<0){
        return false;
    }

    if(arr[n-1]<=sum){
        return SubsetSum(arr,n-1,sum-arr[n-1]) or SubsetSum(arr,n-1,sum);
    }
    else{
        return SubsetSum(arr,n-1,sum);
    }
}

bool SubsetSumDP(int *arr, int n, int sum){
    bool dp[n+1][sum];
    dp[0][0]=true;

    //for coloumn 1
    for(int i=1; i<=n; i++) dp[i][0]=true;
    //for row 1
    for(int i=1; i<=sum; i++) dp[0][i]=false;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum; j++){
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
    int arr[] = {2,3,7,8,10};
    if(SubsetSum(arr,5,11))cout<<"Yes";
    else cout<<"No";
    cout<<endl;
    if(SubsetSumDP(arr,5,11))cout<<"Yes";
    else cout<<"No";
return 0;
}