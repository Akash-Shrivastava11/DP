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


bool isPartition(vector<int>s,int sm)
{
    
    int sum=0;
    for(int i=0;i<s.size();i++)
    sum+=s[i];
    if(sum%2!=0)
    return false;
    else if(sum%2==0)
    return(SubsetSum(s,sm));
}

int main()
{
    vector<int>v;
    int x,sum,size;
    cout<<"Enter the size: ";
    cin>>size;
    cout<<"Enter the set: ";
    for(int i=0;i<size;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    cout<<"\n"<<"Enter the required sum whose partition is to be checked: ";
    cin>>sum;
    cout<<isPartition(v,sum);
}