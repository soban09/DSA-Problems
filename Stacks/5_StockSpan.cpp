// stock span similar to NGL
// being equal will also work

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

vector<int> StockSpan(int *arr, int n){
    vector<int> v;
    stack<int> s;

    for(int i=0; i<n; i++){
        if(s.size()==0)
        // ans = i - NGL = i - (-1) = i+1
        // there is no greater than that, hence all will be small till this index
            v.push_back(i+1);
            
        else if(s.size()>0 && arr[s.top()]>arr[i])
            v.push_back(i-s.top());

        else if(s.size()>0 && arr[s.top()]<=arr[i]){
            while(s.size()>0 && arr[s.top()]<=arr[i])
                s.pop();
            if(s.size()==0)
                v.push_back(i+1);
            else
                v.push_back(i-s.top());
        }
        s.push(i);
    }
    return v;
}

int main(){
    int arr[] = {100,80,60,70,60,75,85};
    vector<int> v = StockSpan(arr, 7);
    for(auto a:v) cout<<a<<" ";
    return 0;
}