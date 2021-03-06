#include<bits/stdc++.h>
using namespace std;


int solve(int arr[] , int i ,int j)
{
    int t[i+1][j+1];
    memset(t,-1,sizeof(t));
    if(i>=j)return 0;
    if(t[i][j]!=-1)
    return t[i][j];
    int mn = INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp=solve(arr,i,k)+solve(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
        if(temp<mn)
        mn=temp;
    }
    return t[i][j]=mn;
}

int main()
{
    int arr[10];
    cout<<"Enter the array: ";
    for(int i=0;i<5;i++)
    cin>>arr[i];
    cout<<solve(arr,1,4);
}