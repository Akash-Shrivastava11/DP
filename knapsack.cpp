#include<iostream>
#include<algorithm>
using namespace std;

void knapsack(int wt[],int val[],int capacity,int n)
{
    int dp[n+1][capacity+1];
    for(int i=0;i<(n+1);i++)
    {
        for(int j=0;j<(capacity+1);j++)
        {
            if(i==0 || j==0)
            dp[i][j]=0;
        }
    }
    for(int i=0;i<(n+1);i++)
    {
        for(int j=0;j<(capacity+1);j++)
        {
            if(wt[i-1]<=j)
            dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    cout<< dp[n][capacity];
}


int main()
{
    int wt[10],val[10],capacity,x;
    cout<<"Enter total values count";
    cin>>x;
    cout<<"\n";
    cout<<"Enter the weight and coresponding value";
    for(int i=0;i<x;i++)
    {
        cout<<"for"<<i+1;
        cin>>wt[i]>>val[i];
        cout<<"\n";
    }
    cout<<"Enter the capacity of the knapsack";
    cin>>capacity;
    int n=sizeof(wt)/sizeof(int);
    cout<<n;
    knapsack(wt,val,capacity,n);
}