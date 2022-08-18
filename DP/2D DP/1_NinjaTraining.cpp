// ninja can learn new tricks but cannot do the same trick on following day
//find max no of points he can get
//I/P : 0 1 3, 2 3 4, 1 9 3 ===> a 2d arr 

#include<bits/stdc++.h>
using namespace std;

int NinjaTraining(vector<vector<int>> points, vector<vector<int>> &dp, int day, int last){
    //he can either of 3
    if(day==0){
        int maxi=-1;
        for(int task=0; task<3; task++){
            if(task!=last)
                maxi=max(maxi, points[0][task]);
        }
        return maxi;
    }

    if(dp[day][last]!=-1)
        return dp[day][last];

    int maxi=-1;
    for(int task=0; task<3; task++){
        if(task!=last){
            int point = points[day][task] + NinjaTraining(points, dp, day-1, task);
            maxi=max(maxi, point);
        }
    }
    return dp[day][last]=maxi;
    // return maxi;
}

int NinjaTrainingDP(vector<vector<int>> points, int n){
    vector<vector<int>> dp(n, vector<int>(4,-1));

    dp[0][0]=max(points[0][1], points[0][2]);
    dp[0][1]=max(points[0][0], points[0][2]);
    dp[0][2]=max(points[0][0], points[0][1]);
    dp[0][3]=max({points[0][0], points[0][1], points[0][2]});

    for(int day=1; day<n; day++){
        for(int last=0; last<4; last++){
            dp[day][last]=0;
            for(int curr=0; curr<3; curr++){
                if(last!=curr){
                    int point = points[day][curr] + dp[day-1][curr];
                    dp[day][last]=max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n-1][3];
}

int NinjaTrainingDPSO(vector<vector<int>> points, int n){
    vector<int> dp(4, -1);

    dp[0]=max(points[0][1], points[0][2]);
    dp[1]=max(points[0][0], points[0][2]);
    dp[2]=max(points[0][0], points[0][1]);
    dp[3]=max({points[0][0], points[0][1], points[0][2]});

    for(int day=1; day<n; day++){
        vector<int> temp(4,0);
        for(int last=0; last<4; last++){
            temp[last]=0;
            for(int curr=0; curr<3; curr++){
                if(last!=curr){
                    int point = points[day][curr] + dp[curr];
                    temp[last]=max(temp[last], point);
                }
            }
        }
        dp=temp;
    }
    return dp[3];
}

int main()
{
    vector<vector<int>> points{{18,11,19}, {4,13,7}, {1,8,13}};
    vector<vector<int>> dp(3, vector<int>(4,-1));

    //3 shows no task in {0,1,2} and hence a dp of 4 col
    cout<<NinjaTraining(points,dp,2,3)<<endl;
    cout<<NinjaTrainingDP(points,3)<<endl;
    cout<<NinjaTrainingDPSO(points,3);
    return 0;
}