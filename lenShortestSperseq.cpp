#include<bits/stdc++.h>
#include<string>
#include<algorithm>
using namespace std;

int srtSbsq(string x , string y)
{
    string ans;
    int n=x.length();
    int m=y.length();
    int dp[n+1][m+1];            //Good variation of Lcs.
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
            dp[i][j]=0;

            else if(x[i-1]==y[j-1])
            dp[i][j]=1+dp[i-1][j-1];

            else
            {
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
            }
        }
    }
    return(m+n-dp[n][m]);
}



int main()
{
    string str1,str2;
    cout<<"Enter the first string: ";
    cin>>str1;
    cout<<"Enter the second string: ";
    cin>>str2;
    cout<<srtSbsq(str1,str2);
}