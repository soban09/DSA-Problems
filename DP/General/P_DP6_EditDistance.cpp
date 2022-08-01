#include <bits/stdc++.h>
using namespace std;


int EditDistance(string s, string t){
	if(s.size()==0 || t.size()==0){
		return max(s.size(), t.size());
	}

	if(s[0]==t[0]){
		return EditDistance(s.substr(1), t.substr(1));
	}

	//insertion
	int i = 1+EditDistance(s.substr(1), t);
	//deletion
	int d = 1+EditDistance(s, t.substr(1));
	//replace
	int r = 1+EditDistance(s.substr(1), t.substr(1));

	int count = min(i, min(d,r));
	return count;
}

int EditDistance_Better(string s, string t, int **ans){
	int m = s.size();
	int n = t.size();

	if(m==0 || n==0){
		ans[m][n] = max(m, n);
		return ans[m][n];
	}

	if(ans[m][n] != -1){
		return ans[m][n];
	}

	if(s[0]==t[0]){
        ans[m-1][n-1] = EditDistance_Better(s.substr(1), t.substr(1), ans);
        return ans[m][n];
    }

	else{
		//insertion
		ans[m-1][n] = 1+EditDistance_Better(s.substr(1), t, ans);
		//deletion
		ans[m][n-1] = 1+EditDistance_Better(s, t.substr(1), ans);
		//replace
		ans[m-1][n-1] = 1+EditDistance_Better(s.substr(1), t.substr(1), ans);
	}

	ans[m][n] = min(ans[m-1][n], min(ans[m-1][n-1], ans[m][n-1]));
	return ans[m][n];

}

int EditDistance_Better(string s, string t){
	int m = s.size();
	int n = t.size();

	int **ans = new int*[m+1];
	for(int i=0; i<=m; i++){
		ans[i] = new int[n+1];
		for(int j=0; j<=n; j++){
			ans[i][j]=-1;
		}
	}

	return EditDistance_Better(s, t, ans);
}

int EditDistance_DP(string s, string t){
    int m=s.size();
    int n=t.size();
    int **ans = new int*[m+1];
    for(int i=0; i<=m; i++){
        ans[i] = new int[n+1];
    }

    //edges to b filled with 0
    for(int i=0; i<=m; i++){
        ans[i][0] = i;
    }
    for(int j=0; j<=n; j++){
        ans[0][j] = j;
    }

    //now the empty part
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){

            if(s[m-i]==t[n-j]){
                ans[i][j] = ans[i-1][j-1];
            }
            else{
                ans[i][j] = 1+min(ans[i-1][j-1], min(ans[i][j-1], ans[i-1][j]));
            }
        }
    }
    return ans[m][n];
}


int main()
{
	string s,t;
	cin>>s>>t;

	cout<<EditDistance(s,t)<<endl;
	cout<<EditDistance_Better(s,t)<<endl;
	cout<<EditDistance_DP(s,t)<<endl;


	return 0;
}