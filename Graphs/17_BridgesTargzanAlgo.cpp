// Tarzan's Algo for finding the bridges in a graph
// Only for Un-directed graph
// Works on the principle that an edge between two nodes A and B could be a bridge such that if and only if I could reach B through some other path, means if A connects B through only a single path, its a edge.
// How will you find it? Store the time of insertion and lowest time of insertion of a perticular among all its neighbours except its parent. If a edge between node A and B will be a bridge iff lowest insertion time of B is greater than time of insertion of A.

#include<bits/stdc++.h>
using namespace std;

int timer=0;
vector<vector<int>> bridges;
    
void dfs(int node, int parent, vector<int> graph[], vector<int> &tin, vector<int> &low, vector<int> &vis){
    vis[node]=1;
    low[node]=tin[node]=timer;
    timer++;
        
    for(auto adjacent:graph[node]){
        if(adjacent==parent)
            continue;
        if(vis[adjacent]==0){
            // complete the dfs of adjacent
            dfs(adjacent,node,graph,tin,low,vis);
                
            // now gimme your lowest insertion time (evil laugh..)
            low[node] = min(low[node],low[adjacent]);
                
            // check if this node can be an edge
            if(low[adjacent] > tin[node])
                bridges.push_back({adjacent,node});
        }
        else{
            low[node] = min(low[node],low[adjacent]);
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;

    vector<int> graph[n];
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    
    return 0;
}