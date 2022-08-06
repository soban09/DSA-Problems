// Hard
// Bipartite graph = can be coloured with 2 colors and have cycle of even length (if it has cycle)
// hence if odd length cycle exits = not possible to be bipartite

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
        cout<<src<<" ";
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

bool OddWeightSum(vector<pair<int, int>> graph[], int n){
    vector<int> Graph[2*n];

    int pseudoNode = n+1, pNodeCount=0;
    for(int u=0; u<n; u++){
        for(auto &[v,w] : graph[u]){
            
            // odd weight
            if(w%2!=0){
                Graph[u].push_back(v);
                Graph[v].push_back(u);
            }
            else{
                Graph[pseudoNode].push_back(u);
                Graph[u].push_back(pseudoNode);
                Graph[pseudoNode].push_back(v);
                Graph[v].push_back(pseudoNode);

                pseudoNode++;
                pNodeCount++;
            }
        }
    }
    vector<int> colors(n, white);
    return CheckBipartite(0, Graph, colors);
}

int main(){
    int n,e;
    cin>>n>>e;

    vector<pair<int,int>> graph[n];
    for(int i=0; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;
        // Un Directed graph
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    bool ans = OddWeightSum(graph, n);
    cout<<endl;
    ans ? cout<<"Yes" : cout<<"No";
    return 0;
}