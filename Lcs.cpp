#include<iostream>
#include<algorithm>

using namespace std;
string s1,s2;
int dp[100][100];
int lcs (string s1,string s2,int m,int n)
{

    if(m==0 || n==0)
    return 0;

    if(dp[m][n]!=-1)
    {
        return dp[m][n];
    }

    if(s1[m-1]==s2[n-1])
    dp[m][n]= 1+lcs(s1,s2,m-1,n-1);

    else
    dp[m][n]= max(lcs(s1,s2,m,n-1), lcs(s1,s2,m-1,n));
    
    return dp[m][n];
}

int main()
{
    
    cout<<"String 1: ";
    cin>>s1;
    cout<<"String 2: ";
    cin>>s2;
    
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        dp[i][j]=-1;
    }
    cout<<lcs(s1,s2,s1.length(),s2.length());
}