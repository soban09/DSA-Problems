// same as Prims Algo
// calculates the shortest distance between two nodes

// can work for both directed and undirected
// cannot handle negative edge graph
// But will definitely not work when there is a negative weight cycle.

// O(ElogV)

//  Prims : weight[v]=edgeWeight
//  Dijkstra : weight[v]=edgeWeight+weight[u]

// using parent is only for printing MST/route

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

void printShortestRoute(int a, int b, vector<int> parent, vector<int> weight){
    cout<<b<<" --> ";
    if(b==a)
        return;
    printShortestRoute(a, parent[b], parent, weight);
}

void Dijkstra(vector<pi> graph[], int n, int a, int b){
    int minWeight=0;
    
    vector<int> parent(n, -1);
    vector<int> weight(n, INT16_MAX);
    // vector<bool> visited(n, false);

    priority_queue<pi, vector<pi>, greater<pi>> heap;
    heap.push({0,0});

    weight[0]=0;
    
    while(!heap.empty()){
        // least weighted node
        int nodeWt = heap.top().first;
        int u = heap.top().second;
        heap.pop();
        // visited[u]=true;

        //every neighbours of u (least weighted node)
        for(auto &[edgeWt,v]:graph[u]){

            // if edgeWeight is less than the weight of the node then update
            if(edgeWt+nodeWt<weight[v]){
                weight[v]=edgeWt+nodeWt;
                heap.push({weight[v],v});
                parent[v]=u;
            }
        }
    }
    // printShortestRoute(a, b, parent, weight);
    cout<<"\npath weight : "<<weight[4];
}

int main(){
    int n,e;
    cin>>n>>e;

    vector<pi> graph[n];
    for(int i=0; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({w,v});
        graph[v].push_back({w,u});
    }

    Dijkstra(graph, n, 0, 4);
    
return 0;
}

// weighted graph
// 5 7
// 0 1 10
// 0 2 20
// 1 2 30
// 1 3 5
// 3 4 8
// 2 3 15
// 2 4 6
