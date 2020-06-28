class Solution {
public:
    int numSquares(int n) {
        vector<int> s,dp(n+1,INT_MAX);
        
        for(int i=1;i*i<=n;i++){
            s.push_back(i*i);
        }
        
        dp[0]=0;
        
        for(int i=1;i<=n;i++)
            for(int j=0;j<s.size();j++)
                if(i-s[j]>=0)
                    dp[i]=min(dp[i],dp[i-s[j]]+1);
        
        return dp[n];
    }
};