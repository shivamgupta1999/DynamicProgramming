//Problem Link
//https://cses.fi/problemset/task/1635

#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
#define ll long long
 
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
        dp[i]=0;
        dp[0]=1;
        for(int i=1;i<x+1;i++){
        	for(int j=0;j<n;j++){
        		if(i-a[j]>=0){
        			dp[i]=(dp[i]+dp[i-a[j]])%mod;
				}
			}
		}
		cout<<dp[x]<<endl;
}