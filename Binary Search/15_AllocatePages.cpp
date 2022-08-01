#include<iostream>
using namespace std;

bool isValid(int *arr, int n, int k, int mx){
    int sum=0, student=1;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(sum>mx){
            student++;
            sum=arr[i];
        }
        if(student>k) return false;
    }
    return true;
}

pair<int, int> FindSumAndMax(int *arr, int n){
    int mx=-1, sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        mx = max(mx, arr[i]);
    }
    return {mx, sum};
}

int AllocatePages(int *arr, int n, int k){
    pair<int, int> p = FindSumAndMax(arr, n);
    int start = p.first, end = p.second, mid, res=-1;

    while(start<=end){
        mid = (start+end)/2;
        if(isValid(arr, n, k, mid)){
            res=mid;
            end=mid-1;
        }
        // go right
        else start=mid+1;
    }
    return res;
}

int main(){
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr)/sizeof(int);
    cout<<AllocatePages(arr, n, 2);
    return 0;
}