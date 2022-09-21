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

//deals with negative numbers too
// use this only
int MaxSumSubArray2(int *arr, int n){
    int max_so_far=arr[0];
    int curr_max=arr[0];

    for(int i=0; i<n; i++){
        curr_max = max(arr[i], curr_max+arr[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

// opposite of prv function
int MinSumSubArray(int *arr, int n){
    int min_so_far=arr[0];
    int curr_min=arr[0];

    for(int i=0; i<n; i++){
        curr_min = min(arr[i], curr_min+arr[i]);
        min_so_far = max(min_so_far, curr_min);
    }
    return min_so_far;
}

int main(){
    int arr[] = {1,2,3,-10,7,8};
    cout<<MaxSumSubArray(arr,6);
    return 0;
}