#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
    if(s.size()==1) return false;
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(') st.push(')');
        else if(s[i]=='{') st.push('}');
        else if(s[i]=='[') st.push(']');
        else if(!st.empty() && s[i]==st.top()) st.pop();
        else return false;
    }
    return st.empty();
}

int main(){
    string s = "(){}[]";
    cout<<isValid(s);    
    return 0;
}