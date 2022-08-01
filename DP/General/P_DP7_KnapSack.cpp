#include <bits/stdc++.h>
using namespace std;

int KnapSack(int n, int *w, int *v, int MaxW){
	//base case
	if(n==0 || MaxW==0){
		return 0;
	}

	if(w[0] > MaxW){
		return KnapSack(n-1, w+1, v+1, MaxW);
	}

	//recursive case
	int x = KnapSack(n-1, w+1, v+1, MaxW-w[0]) + v[0];
	int y = KnapSack(n-1, w+1, v+1, MaxW);

	return max(x,y);

}

int main(){
	
	int n, MaxW;
	cin>>n>>MaxW;


	int *weights = new int[n];
	int *value = new int[n];
	for(int i=0; i<n; i++){
		cin>>weights[i]>>value[i];
	}

	cout<<KnapSack(n, weights, value, MaxW)<<endl;

	return 0;
}