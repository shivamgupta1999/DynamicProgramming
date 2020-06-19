#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<vector<bool> >dp(n+1,vector<bool>(n*1000+1,false));

    dp[0][0]=true;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=n*1000;j++){
            dp[i][j]=dp[i-1][j];
            if(j-a[i-1]>=0&&dp[i-1][j-a[i-1]])
                dp[i][j]=true;
        }
    }

    vector<int> values;

    for(int i=1;i<=n*1000;i++){
        if(dp[n][i])
        values.push_back(i);
    }

    cout<<values.size()<<endl;
    for(auto i : values)
    cout<<i<<" ";

}