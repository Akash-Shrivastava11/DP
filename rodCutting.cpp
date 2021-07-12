#include<bits/stdc++.h>
using namespace std;
int maxLen=8;
int MaxVal(vector<int>&length,vector<int>&price)
{
    
    int n = length.size();
    int dp[n+1][9];
    for(int i=0;i<=n;i++)
    dp[i][0]=0;
    for(int j=1;j<maxLen+1;j++)
    dp[0][j]=0;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<maxLen+1;j++)
        {
            if(length[i-1]<=j)
            dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            else
            dp[i][j]=dp[i-1][j]; 
        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=maxLen;j++)
    //     cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }

    return(dp[n][maxLen]);
}


int main()
{
    vector<vector<int>>dp;
    vector<int>length={1,2,3,4,5,6,7,8};
    vector<int>price={1,5,8,9,10,17,17,20};
    cout<<MaxVal(length,price);
}