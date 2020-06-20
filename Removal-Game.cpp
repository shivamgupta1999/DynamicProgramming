//Problem Link
//https://cses.fi/problemset/task/1097/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n,sum=0;
    cin>>n;

    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }

    long long dp[n][n];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j]=0;

    for(int i=n-1;i>=0;i--){
        for(int j=1;j<n;j++){
                if(i==j)
                    dp[i][j]=a[i];
                else
                    dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }

    cout<<(sum+dp[0][n-1])/2;

}