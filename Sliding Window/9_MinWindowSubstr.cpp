#include<iostream>
#include<unordered_map>
using namespace std;

int MinWindowSubStr(string s, string t){
    int i=0,j=0,mn=INT16_MAX;
    unordered_map<char, int> mp;

    for(auto c:t)
        mp[c]++;

    int count=mp.size();

    while(j<s.size()){
        
        // if it is alpha in T string
        if(mp.find(s[j])!=mp.end()){
            mp[s[j]]--;
            if(mp[s[j]]==0)
                count--;
        }

        if(count==0){

            // possible candidate for our answer
            mn = min(mn, j-i+1);

            while(count==0){

                // if it is alpha in T string
                if(mp.find(s[i])!=mp.end()){

                    // adding count
                    mp[s[i]]++;

                    // plenty of supply (can be removed)
                    if(mp[s[i]]<0){
                        i++;
                        mn = min(mn, j-i+1);
                    }
                    // not enough supply
                    else{
                        i++;
                        count++;
                    }
                }

                // if it is not a alpha in T string (can be removed)
                else{
                    i++;
                    mn = min(mn, j-i+1);
                }
            }
        }

        j++;
    }
    return mn;
}

int main(){
    string s = "totmtaptat";
    string t = "tta";
    cout<<MinWindowSubStr(s,t);
    return 0;
}