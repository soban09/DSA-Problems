// Disjoint set or Union find algo for detecting cycle in a graph
// a graph can be represented by diff method over here cuz we need edges
// path compression just dont let graph become a linear DS like LL, instead it spreads it
// Idea is to find root and make root as parent of node 
// Attach smaller rank tree under root of high rank tree

// NOTE : Always read the Disjoint Set problem and then come to this

#include<bits/stdc++.h>
using namespace std;

int findParent(vector<pair<int, int>> &subset, int i){
    auto &[rank, parent] = subset[i];
    if(parent==i) return i;
    
    parent = findParent(subset, parent);
    return parent;
}

void makeParent(vector<pair<int, int>> &subset, int u, int v){
    auto &[rank1, parent1] = subset[u];
    auto &[rank2, parent2] = subset[v];

    // make v parent of u
    if(rank1<rank2){
        parent1 = v;
    }
    // make u parent of v
    else if(rank1>rank2){
        parent2 = u;
    }
    else{
        parent1 = v;
        rank2++;
    }
}

bool UnionFind(vector<pair<int,int>> graph, int n){
    vector<pair<int, int>> subset(n);

    for(int i=0; i<n; i++){
        auto &[rank, parent] = subset[i];
        rank=0;
        parent=i;
    }

    for(auto &[u,v]:graph){
        int x = findParent(subset, u);
        int y = findParent(subset, v);
        
        if(x==y) return true;
        
        // make parent according to rank
        makeParent(subset,u,v); 
    }
    return false;
}

int main(){
    int n,e;
    cin>>n>>e;

    vector<pair<int,int>> graph;
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        graph.push_back({u,v});
    }

    UnionFind(graph, n) ? cout<<"Yes" : cout<<"No";
    return 0;
}