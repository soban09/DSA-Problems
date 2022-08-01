// will not work in case of negative numbers

#include<iostream>
using namespace std;

int LargestSubArrWithGivenSum(int *arr, int n, int k){
    int i=0,j=0,mx=-1,sum=0;

    while(j<n){
        sum+=arr[j];
        
        // if(sum < k)
        //     j++;

        if(sum == k)
            mx = max(mx, j-i+1);

        else if(sum > k){
            while(sum > k){
                sum-=arr[i];
                i++;
            }
        }
        j++;
    }
    return mx;
}

int main(){
    int arr[] = {4,1,1,1,2,3,5};
    cout<<LargestSubArrWithGivenSum(arr,7,5);
    return 0;
}