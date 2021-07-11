#include<bits/stdc++.h>
#include<vector>
using namespace std;

bool SubsetSum(vector<int>v,int sum)
{
    int n = v.size();
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

    return(dp[n][sum]);
}


int main()
{
    vector<int>v;
    int x,s,size;
    cout<<"Enter the size of set: ";
    cin>>size;
    cout<<"Enter the set: ";
    for(int i=0;i<size;i++)
    {
    cin>>x;
    v.push_back(x);
    }
    cout<<"Enter the sum: ";
    cin>>s;
    cout<<SubsetSum(v,s);
}

