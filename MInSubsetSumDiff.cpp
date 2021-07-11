#include<bits/stdc++.h>
#include<vector>
using namespace std;

void SubsetSum(vector<int>v,int sum)
{
    
    int n = v.size(),mn=INT_MAX;
    
    int dp[n+1][sum+1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
        
    for(int i=1;i<=n;i++)
    {
        
        for(int j=1;j<=sum;j++)
        {
            if(v[i-1]<=j)
            dp[i][j]=dp[i-1][j-v[i-1]]||dp[i-1][j];
            if(v[i-1]>j)
            dp[i][j]=dp[i-1][j];
        }
    }
    vector<int>res;
    for(int j=0;j<=sum/2;j++)
    {
        if(dp[n][j]==1)
    res.push_back(j);
    }

    for(int i=0;i<res.size();i++)
    {
         mn=min(mn,sum-(2*res[i]));
    }
    cout<<mn;
}


int main()
{
    vector<int>v;
    int x,s=0,size;
    cout<<"Enter the size of set: ";
    cin>>size;
    cout<<"Enter the set: ";
    for(int i=0;i<size;i++)
    {
    cin>>x;
    v.push_back(x);
    }
    for(int i=0;i<size;i++)
    s+=v[i];

    SubsetSum(v,s);
}