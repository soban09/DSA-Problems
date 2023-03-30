#include<iostream>
using namespace std;

int BS(int *arr, int start, int end, int e){
    int mid;
    while(start<=end){
        mid = (start+end)/2;
        if(arr[mid]==e) return mid;
        else if(arr[mid]>e) end=mid-1;
        else start=mid+1;
    }
    return -1;
}

int FindMin(int *arr, int n){
    // already sorted
    if(arr[0]<arr[n-1]) return 0;

    int mid, start=0, end=n-1;

    while(start<=end){
        mid = (start+end)/2;
        cout<<mid<<" ";
        int nxt = (mid+1)%n;
        int prv = (mid+n-1)%n;

        if(arr[mid]<=arr[prv] && arr[mid]<=arr[nxt]){
            return mid;
        }
        else if(arr[start]<=arr[mid]){
            start=mid+1;
        }
        else end=mid-1;
    }
    return -1;
}

int main(){
    int arr[] = {4,5,6,7,0,1,2};
    int n = sizeof(arr)/sizeof(int);
    int index = FindMin(arr, n);
    cout<<index<<endl;
    cout<<(-1)*BS(arr, 0, index-1, 0)*BS(arr, index, n-1, 0);
    return 0;
}