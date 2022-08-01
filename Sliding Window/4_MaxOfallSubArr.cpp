#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

vector<int> MaxOfallSubArr(int *arr, int n, int k){
    vector<int> v;
    list<int> l;

    if(k>n){
        v.push_back(*max_element(arr, arr+n));
        return v;
    }

    int i=0,j=0;
    
    while(j<n){

        while(!l.empty() && l.back()<arr[j]){
            l.pop_front();
        }
        l.push_back(arr[j]);

        if(j-i+1 < k)
            j++;

        if(j-i+1 == k){
            v.push_back(l.front());

            if(l.front() == arr[i])
                l.pop_front();

            i++;j++;
        }
    }
    return v;
}

int main(){
    int arr[] = {1,3,-1,-3,5,3,6,7};
    vector ans = MaxOfallSubArr(arr, 8, 3);
    for(auto a:ans) cout<<a<<" ";
    return 0;
}