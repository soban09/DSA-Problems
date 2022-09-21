// Adjacency List used in prims
// Forms a MST like Kruskals

//  Prims : weight[v]=edgeWeight
//  Dijkstra : weight[v]=edgeWeight+weight[u]

// Only works on undirected graph
// can handle negative edge graph

// we compare edge weight with node's weight (A node weight is a hypothetical value representing the cost to reach this node, by default it is infinte)
// to get the least weighted node, we can use STL heap vs STL set, set is a good choice since we can update a value if we want to
// what if you use STL heaps ? Well heap will save both updated and outdated info inside it and hence increasing the complexity!

// using parent is only for printing MST/route

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

void Prims(vector<pi> graph[], int n){
    int minWeight=0;
    
    vector<int> parent(n, -1);
    vector<int> weight(n, INT16_MAX);
    vector<bool> visited(n, false);

    priority_queue<pi, vector<pi>, greater<pi>> heap;
    heap.push({0,0});

    weight[0]=0;
    
    while(!heap.empty()){
        // least weighted node
        int u = heap.top().second;
        heap.pop();
        visited[u]=true;

        //every neighbours of u (least weighted node)
        for(auto &[edgeWt,v]:graph[u]){

            // if edgeWeight is less than the weight of the node then update
            if(!visited[v] && edgeWt<weight[v]){
                weight[v]=edgeWt;
                heap.push({edgeWt,v});
                parent[v]=u;
            }
        }
    }
    // for(auto a:parent)
    //     cout<<a<<" ";
    // cout<<endl;
    for(auto w:weight){
        minWeight+=w;
    }
    cout<<endl<<minWeight;
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

    Prims(graph, n);
    
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
