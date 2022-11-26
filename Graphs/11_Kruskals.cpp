// Creates MST

// un directed + weighted Graph

// sort the edges according to the weight and then count the edge if it doesnt forms cycle
// same like pathCompression
// Not represented by Adjacency List because we sort edges not vertices

#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int w;
    int u;
    int v;
};

int findParent(vector<pair<int, int>> &subset, int i){
    auto &[rank, parent] = subset[i];
    if(parent==i) return i;
    
    return parent = findParent(subset, parent);
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

int Kruskals(vector<Edge> graph, int n){
    vector<pair<int, int>> subset(n);
    int MinWeight=0;

    for(int i=0; i<n; i++){
        auto &[rank, parent] = subset[i];
        rank=0;
        parent=i;
    }

    int i=0;
    for(auto &[w,u,v]:graph){
        int x = findParent(subset, u);
        int y = findParent(subset, v);
        
        if(x!=y){
            // make parent according to rank
            makeParent(subset,u,v); 
            MinWeight+=w;
            cout<<u<<"--"<<v<<" : "<<w<<endl;
            i++;
        }
        // we need only n-1 edges
        if(i==n-1) break;        
    }
    return MinWeight;
}

int main(){
    int n,e;
    cin>>n>>e;

    vector<Edge> graph;
    for(int i=0; i<e; i++){
        Edge e;
        cin>>e.u>>e.v>>e.w;
        graph.push_back(e);
    }

    sort(graph.begin(), graph.end(), [](Edge &e1, Edge &e2){
        return e1.w < e2.w;
    });

    cout<<Kruskals(graph, n);
    return 0;
}

// weighted graph :

// sample input 1  
// 4 5 0 1 10 1 3 15 2 3 4 2 0 6 0 3 5
// sample input 2 
// 5 7
// 0 1 10
// 0 2 20
// 1 2 30
// 1 3 5
// 3 4 8
// 2 3 15
// 2 4 6