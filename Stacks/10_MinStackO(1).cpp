#include<iostream>
#include<stack>
using namespace std;

stack<int> s;
int minE=-1;

void pushE(int a){
    s.push(a);

    if(s.size()==0){
        s.push(a);
        minE = a;
    }
    else{
        if(a>=s.top()){
            s.push(a);
        }
        else{
            s.push(2*a-minE);
            minE = a;
        }
    }
}

int popE(){
    if(s.size()==0) return -1;
    
    // checking the Flag conditions:
    if(s.top()>=minE){
        s.pop();
    }
    else{
        minE = 2*minE-s.top();
        s.pop();
    }
}

int topE(){
    if(s.size()==0) return -1;
    
    // checking the Flag conditions:
    if(s.top()>=minE){
        return s.top();
    }
    else{
        minE = 2*minE-s.top();
        return minE;
    }
}

int MinE(){
    return minE;
}

int main(){
    
    return 0;
}