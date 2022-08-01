#include<iostream>
#include<queue>
using namespace std;

int KthSmallest(int *arr, int n, int k){
    priority_queue<int> MaxH; //Max Heap

    for(int i=0; i<n; i++){
        MaxH.push(arr[i]);
        if(MaxH.size()>k){
            MaxH.pop();
        }
    }
    return MaxH.top();
}

int main(){
    int arr[] = {7,10,4,3,20,15};
    int k=3;
    int n = sizeof(arr)/sizeof(int);
    cout<<KthSmallest(arr, n, k);
    return 0;
}