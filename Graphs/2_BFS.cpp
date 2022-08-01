#include<bits/stdc++.h>
using namespace std;

void bfs(int v, vector<int> graph[], vector<bool> &visited){
    queue<int> q;
    q.push(v);
    visited[v]=true;

    while(!q.empty()){
        int src = q.front();
        q.pop();
        cout<<src<<" ";
        
        for(auto &u:graph[src]){
            if(!visited[u]){
                visited[u]=true;
                q.push(u);
            } 
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

    vector<bool> visited(n, false);
    for(int i=0; i<n; i++){
        if(!visited[i])
            bfs(i, graph, visited);
    }
    // bfs(0, graph, visited);
    return 0;
}