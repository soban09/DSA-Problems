// Kosaraju's Algo for stronly connected component
// only for Directed Graph
// Strongly connected component means if you pick a directed edge btw 2 nodes A and B in a component, there also must be a direct/indirect edge from B to A.
// Idea is that when we do DFS we jump from one SCC to another, if we revert or take a transpose of every edge, we would do DFS on SCC1 and then would not be able to reach another SCC because we flipped the edge
// Step1 : Do DFS and store the nodes as they complete their DFS
// Step2 : Take transpose of the Graph
// Step3 : Do simple DFS
// SCC1 -> SCC2 -> SCC3 -> SCC4


#include<bits/stdc++.h>
using namespace std;

void dfs2(int v, vector<int> graph[], vector<bool> &visited, stack<int> &s){
    visited[v]=true;
    for(auto &u:graph[v]){
        if(!visited[u]){
            dfs(u, graph, visited);
        }
    }
    s.push(v);
}

void dfs(int v, vector<int> graph[], vector<bool> &visited){
    visited[v]=true;
    for(auto &u:graph[v]){
        if(!visited[u]){
            dfs(u, graph, visited);
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
        // directed graph
        graph[u].push_back(v);
    }

    vector<bool> vis(n, false);
    stack<int> s;
    for(int i=0; i<n; i++){
        if(!vis[i])
            dfs2(i, graph, vis, s);
    }

    vector<int> graphT[n];
    for(int v=0; v<n; v++){
        vis[v]=false;
        for(auto u:graph[v]){
            graphT[u].push_back(v);
        }
    }

    int scc=0;
    while(!s.empty()){
        auto node = s.top(); s.pop();
        if(!vis[node]){
            dfs(node, graphT, vis);
            scc++;
        }
    }
    cout<<scc;
    return 0;
}