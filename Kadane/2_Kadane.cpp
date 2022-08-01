// For circular array

#include<iostream>
using namespace std;

int MaxSumSubArray(int *arr, int n){
    int max_so_far=INT16_MIN, max_ending=0;

    for(int i=0; i<n; i++){
        max_ending+=arr[i];

        if(max_ending<0) max_ending=0;
        max_so_far = max(max_ending, max_so_far);
    }
    return max_so_far;
}

int MaxSumSubCircularArr(int *arr, int n){
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        arr[i]*=-1;
    }

    return sum+MaxSumSubArray(arr, n);
}

int main(){
    int arr[] = {8,2,3,-10,7,8};

    int normalSum = MaxSumSubArray(arr,6);

    normalSum<0 ? cout<<normalSum : cout<<max(normalSum, MaxSumSubCircularArr(arr,6));
    return 0;
}