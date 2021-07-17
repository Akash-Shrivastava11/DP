#include<bits/stdc++.h>
using namespace std;

bool LcsTd(string &x,string &y)
{
    int m=x.length();
    int n=y.length();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    dp[i][0]=0;
    for(int i=0;i<=n;i++)
    dp[0][i]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return(x.size()==dp[m][n]);
}

int main()
{
    string str1,str2,size;
    cout<<"Enter the first string: ";
    cin>>str1;
    cout<<"Enter the second string: ";
    cin>>str2;
    cout<<LcsTd(str1,str2);
}