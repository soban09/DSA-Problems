// Creates MST

// un directed + weighted Graph

// sort the edges according to the weight and then count the edge if it doesnt forms cycle
// same like pathCompression
// Not represented by Adjacency List because we sort edges not vertices

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public : 
        vector<int> parent, rank;
        int groups;

        DisjointSet(int n){
            groups=n;
            rank.resize(n, 0);
            parent.resize(n);
            for(int i=0; i<n; i++)
                parent[i]=i;
        }

        int findParent(int node){
            if(node==parent[node])
                return node;
            return parent[node] = findParent(parent[node]);
        }

        void makeParent(int u, int v){
            int parent1 = findParent(u);
            int parent2 = findParent(v);
            if(parent1==parent2) return;

            if(rank[parent1] < rank[parent2]){
                parent[parent1]=parent2;
            } else if(rank[parent1] > rank[parent2]){
                parent[parent2] = parent1;
            } else{
                parent[parent1]=parent2;
                rank[parent2]++;
            }
        }

        bool isUnited(){
            return groups==1;
        }
};

struct Edge{
    int w;
    int u;
    int v;
};

int Kruskals(vector<Edge> graph, int n){
    DisjointSet dsu(n);
    
    int MinWeight=0;

    int i=0;
    for(auto &[w,u,v]:graph){
        int parent1 = dsu.findParent(u);
        int parent2 = dsu.findParent(v);
        
        // if cycle cant be made 
        if(parent1!=parent2){
            // make parent according to rank
            dsu.makeParent(u,v); 
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