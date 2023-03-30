#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;


int m,n,sz;
bool f(int i, int j, vector<vector<char>>& board, string s, int idx){
    if(i<0 || j<0 || i>=m || j>=n || board[i][j]!=s[idx]){
        return false;
    }
    if(idx==sz-1 && s[idx]==board[i][j]){
        return true;
    }
         
    char ch=board[i][j];
    board[i][j]='$';
        
    bool ans = f(i+1,j,board,s,idx+1) || f(i,j+1,board,s,idx+1) || f(i-1,j,board,s,idx+1) || f(i,j-1,board,s,idx+1);
        
    board[i][j]=ch;
    return ans;
}
    
    
    
bool exist(vector<vector<char>>& board, string word) {
    m=board.size();
    n=board[0].size();
    sz=word.size();
        
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(word[0]==board[i][j] && f(i,j,board,word,0))
                return true;
        }
    }    
    return false;
}

int main()
{   vector<vector<char>> board{{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'}};
    string word = "AAAAAAAAAAAAAAA";
    exist(board,word) ? cout<<"Yes" : cout<<"No";
    return 0;
}