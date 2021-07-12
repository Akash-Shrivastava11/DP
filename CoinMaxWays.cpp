#include<bits/stdc++.h>
using namespace std;

int MaxWays(vector<int>&coins,int &sum)
{
    int n = coins.size();
    int dp[n+1][sum+1];
    for(int i=0 ; i<=n ; i++)
    dp[i][0]=1;
    for(int j =1;j<=sum;j++)
    dp[0][j]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j>=coins[i-1])
            dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return(dp[n][sum]);
}

int main()
{
    vector<int>coins={1,2,3};
    int sum = 5;
    cout<<MaxWays(coins,sum);
}