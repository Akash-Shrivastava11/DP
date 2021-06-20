#include<iostream>
#include<algorithm>

using namespace std;
long long dp[100];

long long fib(long long n)
{
    if(n==0||n==1)
    return n;
    if(n==2)
    return 1;

    if(dp[n]!=-1)
    return dp[n];

    dp[n]=fib(n-1)+fib(n-2);
    return dp[n];
}

int main()
{
    for(long long i=0;i<100;i++)
    dp[i]=-1;
    long long n;
    cout<<"Value: ";
    cin>>n;
    cout<<fib(n);
}