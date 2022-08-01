#include<bits/stdc++.h>
using namespace std;

void printSol(vector<vector<int>> sol){
    for(auto i:sol){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
}

bool isSafe(vector<vector<int>> maze, int x, int y, int n){
    return x>=0 && y>=0 && x<n && y<n && maze[x][y]==1;
}

bool RatInAMaze(vector<vector<int>> maze, int x, int y, int n, vector<vector<int>> &sol){
    if(x==n-1 && y==n-1 && maze[x][y]==1) return true;

    if(isSafe(maze, x, y, n)){
        if(sol[x][y]==1) return false;

        sol[x][y]=1;

        if(RatInAMaze(maze, x+1, y, n, sol)) return true;

        if(RatInAMaze(maze, x, y+1, n, sol)) return true;

        sol[x][y]=0;
    }
    return false;
}

int main(){
    vector<vector<int>> maze{{1,0,0,0}, {1,1,0,1}, {0,1,0,0}, {1,1,1,1}};   
    vector<vector<int>> sol(4, vector<int>(4, 0));

    if(RatInAMaze(maze, 0, 0, 4, sol)) printSol(sol);
    else cout<<"Not found"; 
    return 0;
}