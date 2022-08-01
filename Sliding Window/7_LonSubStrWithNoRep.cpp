#include<iostream>
#include<unordered_map>
using namespace std;

int LonSubStrkUnique(string s){
    int i=0,j=0,mx=-1;
    unordered_map<char, int> mp;

    while(j<s.size()){
        mp[s[j]]++;

        if(mp.size() == j-i+1){
            mx = max(mx, j-i+1);
        }
        else if(mp.size() < j-i+1){
            while(mp.size() < j-i+1){
                mp[s[i]]--;

                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;
            }
        }
        j++;
    }
    return mx;
}

int main(){
    string s="aabacbebebe";
    cout<<LonSubStrkUnique(s);
    return 0;
}