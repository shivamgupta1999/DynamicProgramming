//Problem Link
//https://cses.fi/problemset/task/1145/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    
    vector<int> dp;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    for(int i=0;i<n;i++){
        auto it = lower_bound(dp.begin(),dp.end(),a[i]);
        if(it==dp.end())
            dp.push_back(a[i]);
        else
            *it=a[i];
    }
    cout<<dp.size()<<endl;
}