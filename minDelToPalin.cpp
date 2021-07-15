#include<bits/stdc++.h>
using namespace std;

int lcs(string &a , string &b)
{
    int n=a.size();
    int m=b.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++)
    {
        if(i==0||j==0)
        dp[i][j]=0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

void lps(string &x)
{
    string a=x;
    reverse(x.begin(),x.end());
    string b=x;
    cout<<"Minimum deletions to obtain Longest Palindromic Subsequence is: "<<x.size()-lcs(a,b);
}



int main()
{
    string x,y;
    cout<<"Enter s1: ";
    cin>>x;
    lps(x);
}
