#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> FirstNegative(vector<int> arr, int k){
    int i=0,j=0;
    queue<int> q;
    vector<int> v;

    while(j<arr.size()){
        if(arr[j]<0) q.push(arr[j]);

        if(j-i+1 < k) j++;

        else if(j-i+1 == k){

            if(q.empty()) v.push_back(0);
            else{
                v.push_back(q.front());
                if(arr[i]==q.front()) q.pop();
            }
            i++;j++;
        }
    }
    
    return v;
}

int main(){
    vector<int> arr{12,-1,-7,8,-15,30,16,28};
    vector ans = FirstNegative(arr, 3);
    for(auto a:ans) cout<<a<<" ";
    return 0;
}