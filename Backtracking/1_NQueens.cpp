#include<bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<int>> board){
    for(auto i:board){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
}

bool isSafe(vector<vector<int>> &board, int row, int col, int n){
    for(int i=0; i<row; i++)
        if(board[i][col]==1) return false;
    
    for(int i=row,j=col; i>=0 && j>=0; i--,j--)
        if(board[i][j]==1) return false;

    for(int i=row,j=col; i>=0 && j<n; i--,j++)
        if(board[i][j]==1) return false;

    return true;
}

bool NQueens(vector<vector<int>> &board, int n, int row){
    if(row>=n) return true;

    for(int j=0; j<n; j++){
        if(isSafe(board, row, j, n)){
            board[row][j]=1;

            if(NQueens(board, n, row+1)) return true;

            board[row][j]=0;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    if(NQueens(board, n, 0)) printBoard(board);
    else cout<<"Not possible";
    return 0;
}