// variation of prv problem
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int MaxSumOfNonAdjDPSO(vector<int> arr, int n){
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

int HouseRobber(int *arr, int n){
    // temp1 = x 3 2 1
    // temp2 = 1 3 2 x
    vector<int> temp1,temp2;
    for(int i=0; i<n; i++){
        if(i!=0) temp1.push_back(arr[i]);
        if(i!=n-1) temp2.push_back(arr[i]);
    }
    return max(MaxSumOfNonAdjDPSO(temp1,n-1), MaxSumOfNonAdjDPSO(temp2,n-1));
}

int main()
{
    int arr[]={1,3,2,1};
    cout<<HouseRobber(arr,4);
    return 0;
}