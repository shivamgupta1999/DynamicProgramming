//Problem Link
//https://cses.fi/problemset/task/1093/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,sum=0;
    cin>>n;

    sum=n*(n+1)/2;

    if(sum&1)
        cout<<0<<endl;
    else{
        sum/=2;

        int dp[n][sum+1];

        for(int i=0;i<n;i++){
            for(int j=0;j<=sum;j++){
                dp[i][j]=0;
            }
        }

        dp[0][0] = 1;

        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                if(j-i>=0)
                    (dp[i][j]+=dp[i-1][j-i])%=1000000007;
            }
        }

        cout<<dp[n-1][sum];

    }

}