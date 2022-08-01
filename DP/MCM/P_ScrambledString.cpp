//A derivative of MCM
//two more optimisations:-
//1- to also check in map before making those two rcursive calls
//2- to also check if two strings have same characters

#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<string, bool> mp;

bool ScrambleString(string a, string b){
    if(a==b) return true;

    if(a.length()<=1) return false;

    int n=a.length();
    bool flag = false;

    for(int i=1; i<n; i++){

        //if it is swapped
        bool cond1 = ScrambleString(a.substr(0,i), b.substr(n-i,i)) && ScrambleString(a.substr(i,n-i), b.substr(0,n-i));
        //if it is not swapped
        bool cond2 = ScrambleString(a.substr(0,i), b.substr(0,i)) && ScrambleString(a.substr(i,n-i), b.substr(i,n-i));

        if(cond1 || cond2){
            flag = true;
            break;
        }
    }
    return true;
}

bool ScrambleStringMem(string a, string b){
    if(a==b) return true;

    if(a.length()<=1) return false;

    string key = a;
    key.push_back(' ');
    key.append(b);

    if(mp.find(key)!=mp.end()){
        return mp[key];
    }

    int n=a.length();
    bool flag = false;

    for(int i=1; i<n; i++){

        //if it is swapped
        bool cond1 = ScrambleStringMem(a.substr(0,i), b.substr(n-i,i)) && ScrambleString(a.substr(i,n-i), b.substr(0,n-i));
        //if it is not swapped
        bool cond2 = ScrambleStringMem(a.substr(0,i), b.substr(0,i)) && ScrambleString(a.substr(i,n-i), b.substr(i,n-i));

        if(cond1 || cond2){
            flag = true;
            break;
        }
    }
    mp.insert({key, flag});
    return flag;
}

int main(){
    string a,b;
    cin>>a>>b;

    if(a.size()!=b.size()){
        cout<<"No";
    }
    else{
        if(ScrambleStringMem(a,b)) cout<<"Yes";
        else cout<<"No";
    }
return 0;
}