#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> Sort(int *arr, int n, int k){
    vector<int> v;
    priority_queue<int, vector<int>, greater<int>> Heap;
    
    for(int i=0; i<n; i++){
        Heap.push(arr[i]);

        if(Heap.size()>k){
            v.push_back(Heap.top());
            Heap.pop();
        }
    }

    while(!Heap.empty()){
        v.push_back(Heap.top());
        Heap.pop();
    }
    return v;
}

int main(){
    int arr[] = {6,5,3,2,8,10,9};
    int n = sizeof(arr)/sizeof(int);
    vector<int> v = Sort(arr, n, 3);
    for(auto i:v) cout<<i<<" ";
    return 0;
}