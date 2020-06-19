//Problem Link
//https://cses.fi/problemset/task/1639

#include <bits/stdc++.h>
using namespace std;

int dp[5001][5001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a,b;
    cin>>a>>b;

    int n=a.length(),m=b.length();
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=0;
        }
    }

    for(int i=0;i<=n;i++)
    dp[i][0]=i;
    for(int i=0;i<=m;i++)
    dp[0][i]=i;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1])
            dp[i][j]=dp[i-1][j-1];
            else{
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
    }

    cout<<dp[n][m]<<endl;

}