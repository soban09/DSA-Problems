// Bipartite graph = can be coloured with 2 colors and have (if) cycle of even length

#include<bits/stdc++.h>
using namespace std;

enum Color {red, blue, white};

bool CheckBipartite(int v, vector<int> graph[], vector<int> &colors){
    queue<int> q;
    q.push(v);
    colors[v]=red;

    while(!q.empty()){
        int src = q.front();
        q.pop();
        int revColor = colors[src]==red ? blue : red;
        
        for(auto &u:graph[src]){
            if(colors[u]==white){
                colors[u]=revColor;
                q.push(u);
            }
            else if(colors[u]==colors[src])
                return false; 
        }    
    }
    return true;
}

int main(){
    int n,e;
    cin>>n>>e;

    vector<int> graph[n];
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        // Un Directed graph
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> colors(n, white);
    bool ans = CheckBipartite(0, graph, colors);
    ans ? cout<<"Yes" : cout<<"No";
    return 0;
}