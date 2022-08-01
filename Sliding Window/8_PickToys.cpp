#include<iostream>
#include<unordered_map>
using namespace std;

int LonSubStrkUnique(string s, int k){
    if(s.size() <= 1) return 1;

    int i=0,j=0,mx=-1;
    unordered_map<char, int> mp;

    while(j<s.size()){
        mp[s[j]]++;

        if(mp.size() <= k){
            mx = max(mx, j-i+1);
        }
        else if(mp.size() > k){
            while(mp.size() > k){
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
    string s="aaaaaaabebebe";
    // cout<<max(LonSubStrkUnique(s,1), LonSubStrkUnique(s,2));
    cout<<LonSubStrkUnique(s,2);
    return 0;
}