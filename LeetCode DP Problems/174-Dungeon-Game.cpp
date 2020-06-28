class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dun) {
        
        int n=dun.size();
        int m=dun[0].size();
        
        int dp[n][m];
        
        dp[n-1][m-1]=dun[n-1][m-1]>0?1:1-dun[n-1][m-1];
        
        for(int i=n-2;i>=0;i--)
            dp[i][m-1]=max(1,dp[i+1][m-1]-dun[i][m-1]);
        
        for(int i=m-2;i>=0;i--)
            dp[n-1][i]=max(1,dp[n-1][i+1]-dun[n-1][i]);
        
        for(int i=n-2;i>=0;i--)
            for(int j=m-2;j>=0;j--)
                dp[i][j]=max(1,min(dp[i+1][j]-dun[i][j],dp[i][j+1]-dun[i][j]));
        
        return dp[0][0];
    }
};