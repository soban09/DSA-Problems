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
    int arr[] = {1,3,12,5,15,11};
    int n = sizeof(arr)/sizeof(int);
    int k1 = KthSmallest(arr, n, 3);
    int k2 = KthSmallest(arr, n, 6);

    int sum=0;
    for(int i=0; i<n; i++){
        if(arr[i]>k1 && arr[i]<k2) sum+=arr[i];
    }
    cout<<sum;
    return 0;
}