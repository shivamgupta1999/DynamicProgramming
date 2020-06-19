//Problem Link
//https://cses.fi/problemset/task/1744/

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long

int dp[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a,b,ans=0;
    cin>>a>>b;

    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            dp[i][j]=1e9;
            if(i==j)
                dp[i][j]=0;
        }
    }

    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            for(int k=1;k<i;k++)
                dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
            for(int k=1;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
        }
    }

    cout<<dp[a][b]<<endl;
}