#include<bits/stdc++.h>
using namespace std;

void printSudoku(vector<vector<int>> sudoku){
    for(auto i:sudoku){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
}

bool findUnassigned(vector<vector<int>> sudoku, int &row, int &col){
    for(row=0; row<9; row++){
        for(col=0; col<9; col++)
            if(sudoku[row][col]==0) return true;
    }
    return false;
}

bool isSafeinGrid(vector<vector<int>> sudoku, int row, int col, int num){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
            if(sudoku[i+row][j+col]==num) return false;
    }
    return true;
}

bool isSafeinX(vector<vector<int>> sudoku, int row, int num){
    for(int i=0; i<9; i++)
        if(sudoku[row][i]==num) return false;
    return true;
}

bool isSafeinY(vector<vector<int>> sudoku, int col, int num){
    for(int i=0; i<9; i++)
        if(sudoku[i][col]==num) return false;
    return true;
}

bool isSafe(vector<vector<int>> sudoku, int row, int col, int num){
    return isSafeinX(sudoku, row, num) && isSafeinY(sudoku, col, num) && isSafeinGrid(sudoku, row-row%3, col-col%3, num) && sudoku[row][col]==0;
}

bool solveSudoku(vector<vector<int>> &sudoku){
    int row, col;

    if(!findUnassigned(sudoku, row, col)) return true;

    for(int num=1; num<=9; num++){
        if(isSafe(sudoku, row, col, num)){

            sudoku[row][col]=num;

            if(solveSudoku(sudoku)) return true;

            sudoku[row][col]=0;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> sudoku{
                    { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                    { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                    { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                    { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                    { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                    { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                    { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                    { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                    { 0, 0, 5, 2, 0, 6, 3, 0, 0 }};

    if(solveSudoku(sudoku)) printSudoku(sudoku);
    else cout<<"Cannot solve"; 
    return 0;
}