#include<iostream>
#include<queue>
using namespace std;
// min heap
typedef priority_queue<int, vector<int>, greater<int>> pq;

int MinCost(int *arr, int n){
    pq Heap;
    for(int i=0; i<n; i++){
        Heap.push(arr[i]);
    }

    int cost=0;
    while(Heap.size()>1){
        int x=Heap.top(); Heap.pop();
        int y=Heap.top(); Heap.pop();
        cost+=(x+y);
        Heap.push(x+y); 
    }
    return cost;
}

int main(){
    int arr[]={1,2,3,4,5};
    cout<<MinCost(arr,5);
    return 0;
}