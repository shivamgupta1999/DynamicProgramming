//Problem Link
//https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
        int n,x;
        cin>>n>>x;
        int a[n];
        for(int i=0;i<n;i++){
        	cin>>a[i];
		}
        int dp[x+1];
        for(int i=0;i<x+1;i++)
        dp[i]=1000000000;
        dp[0]=0;
        for(int i=1;i<x+1;i++){
        	for(int j=0;j<n;j++){
        		if(i-a[j]>=0){
        			dp[i]=min(dp[i],dp[i-a[j]]+1);
				}
			}
		}
		cout<<(dp[x]==1e9?-1:dp[x])<<endl;
	return 0;
}
