#include<iostream>
using namespace std;

int FindMin(int *arr, int n, int e){
    int start=0, end=n-1, mid;

    while(start<=end){
        mid=(start+end)/2;

        if(arr[mid]==e) return 0;
        else if(arr[mid]>e) end=mid-1;
        else start=mid+1;
    }

    return min(abs(arr[start]-e), abs(arr[end]-e));
}

int main(){
    int arr[]= {1,3,8,10,15};
    int n = sizeof(arr)/sizeof(int);
    cout<<FindMin(arr,n,12);
    return 0;
}