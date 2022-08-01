#include<iostream>
using namespace std;

int FOccurence(int *arr, int n, int e){
    int mid, idx=-1, start=0, end=n-1;

    while(start<=end){
        mid = (start+end)/2;

        if(arr[mid]==e){
            idx=mid;
            end=mid-1;
        }

        else if(arr[mid]>e) end=mid-1;
        else start=mid+1;
    }
    return idx;
}

int LOccurence(int *arr, int n, int e){
    int mid, idx=-1, start=0, end=n-1;

    while(start<=end){
        mid = (start+end)/2;

        if(arr[mid]==e){
            idx=mid;
            start=mid+1;
        }

        else if(arr[mid]>e) end=mid-1;
        else start=mid+1;
    }
    return idx;
}
int main(){
    int arr[] = {2,3,4,10,10,10,12,13,14};
    int n = sizeof(arr)/sizeof(int);
    cout<<(LOccurence(arr,n,10)-FOccurence(arr,n,10)+1);
    return 0;
}