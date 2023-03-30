//a derivative of MCM

#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

bool isPalindrome(string String, int i, int j)
{
    while(i < j)
    {
      if(String[i] != String[j])
        return false; 
      i++;
      j--;
    }
    return true;
}

int MinCut(string s, int i, int j){
    if(i>=j) return 0;

    if(isPalindrome(s,i,j)) return 0;

    int mn = INT_MAX;

    for(int k=i; k<j; k++){
        int tempAns = MinCut(s,i,k) + MinCut(s,k+1,j) + 1;
        
        mn = min(mn, tempAns);
    }
    return mn;
}

int solveMem(string s, int i, int j){
    if(i>=j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(isPalindrome(s,i,j)) return 0;

    int mn = INT_MAX;

    for(int k=i; k<j; k++){
        int tempAns = solveMem(s,i,k) + solveMem(s,k+1,j) + 1;
        
        mn = min(mn, tempAns);
    }
    dp[i][j] = mn;
    return dp[i][j];
}



int main(){
    string s="nitin";
    memset(dp, -1, sizeof(dp));
    cout<<MinCut(s,0,s.size()-1);
return 0;
}