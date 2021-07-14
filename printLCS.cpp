#include<bits/stdc++.h>
#include<string>
#include<algorithm>
using namespace std;

void printLcs(string x , string y)
{
    string ans;
    int n=x.length();
    int m=y.length();
    int dp[n+1][m+1];
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


    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

    int i=n;
    int j=m;
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
        ans.push_back(x[i-1]);
        i--;
        j--;
        }
        else
        {
            if(dp[i][j-1]>dp[i-1][j])
            j--;
            else
            i--;
        }

    }
    reverse(ans.begin(),ans.end());
    cout<<ans;

}

int main()
{
    string str1,str2;
    cout<<"Enter the first string: ";
    cin>>str1;
    cout<<"Enter the second string: ";
    cin>>str2;
    printLcs(str1,str2);
}