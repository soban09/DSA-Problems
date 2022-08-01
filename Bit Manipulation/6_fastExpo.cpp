#include<iostream>
using namespace std;

int fastExpo(int a, int n){
    int ans=1;

    while(n>0){
        if(n&1){
            ans*=a;
        }
        a*=a;
        n=n>>1;
    }
    return ans;
}

int main(){
    cout<<fastExpo(3,5)<<endl;
    cout<<fastExpo(4,4)<<endl;
    cout<<fastExpo(2,10)<<endl;
    return 0;
}