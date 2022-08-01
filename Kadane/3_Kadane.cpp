#include<iostream>
#include<algorithm>
using namespace std;

int maxProduct(int *arr, int n) {
    int max_so_far=arr[0];
    int max_ending=arr[0];
    int min_ending=arr[0];
        
    for(int i=1; i<n; i++){
        int temp = max({arr[i], arr[i]*max_ending, arr[i]*min_ending});
        min_ending = min({arr[i], arr[i]*max_ending, arr[i]*min_ending});
        max_ending = temp;
        
        max_so_far = max(max_ending, max_so_far);
    }
    return max_so_far;
}

int main(){
    int arr[] = {2,3,-2,4};
    cout<<maxProduct(arr,4);
    return 0;
}