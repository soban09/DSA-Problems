#include<iostream>
#include<unordered_map>
using namespace std;

int CountAnagram(string s, string p){
    unordered_map<char, int> mp;
    int ans = 0;
    
    //storing the occ. of string p in the map
    for (auto &x : p){
        mp[x]++;
    }

    int count = mp.size();
    int k = p.size();
    int i=0, j=0;

    while (j < s.size()){
        //calculation part
        mp[s[j]]--;
        if (mp[s[j]] == 0)
            count--;

        //window length not achived yet
        if (j-i+1 < k)
            j++;

        //window length achived, find ans and slide the window
        else if (j-i+1 == k){
            //finding the ans
            if (count == 0)
                ans++;

            mp[s[i]]++;

            if (mp[s[i]] == 1)
                count++;

            //slide the window
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    string s = "forxxorfxofr";
    string ptrn = "for";
    cout<<CountAnagram(s,ptrn);
    return 0;
}