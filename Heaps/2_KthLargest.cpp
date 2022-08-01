#include<iostream>
#include<queue>
using namespace std;

int KthLargest(int *arr, int n, int k){
    priority_queue<int, vector<int>, greater<int>> MinH; //Min Heap

    for(int i=0; i<n; i++){
        MinH.push(arr[i]);
        if(MinH.size()>k){
            MinH.pop();
        }
    }
    int ans = MinH.top();
    while(MinH.size()!=0){
        cout<<MinH.top()<<" ";
        MinH.pop();
    }
    cout<<endl;
    return ans;
}

int main(){
    int arr[] = {7,10,4,3,20,15};
    int k=3;
    int n = sizeof(arr)/sizeof(int);
    cout<<KthLargest(arr, n, k);
    return 0;
}