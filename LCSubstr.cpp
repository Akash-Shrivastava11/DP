#include<bits/stdc++.h>
using namespace std;

int lcstr(string &x,string &y)
{
    int n =x.length(),res=0;
    int m=y.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
        if(i==0||j==0)
        dp[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
            {
            dp[i][j]=1+dp[i-1][j-1];
            res=max(res,dp[i][j]);
            }
            else
            dp[i][j]=0;
        }
    }
    return(res);
}

int main()
{
    string x,y;
    cout<<"Enter s1: ";
    cin>>x;
    cout<<"Enter s2:";
    cin>>y;
    cout<<lcstr(x,y);
}