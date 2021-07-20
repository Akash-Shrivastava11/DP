#include<bits/stdc++.h>
using namespace std;
static int dp[100][100];
bool isPal(string x, int i,int j)
{
    // cout<<i<<j;
    while(i<j){
    if(x[i]==x[j])
    {
        i++;
        j--;
    }
    else
    return false;
    }
    return true;
}

int palpart(string name,int i,int j)
{
    if(i>=j) return 0;
    if(isPal(name,i,j)) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int mn=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp=palpart(name,i,k)+palpart(name,k+1,j)+1;
        mn=min(mn,temp);
    }
    return dp[i][j]=mn;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    string name;
    cout<<"Enter the string";
    cin>>name;
    cout<<palpart(name,0,name.size()-1);
}