class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n=matrix.size();
        int m=n > 0 ? matrix[0].size() : 0;
        int dp[n+1][m+1],ans=0;
        
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                dp[i][j]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                    ans=max(ans,dp[i][j]);
                }
            }
        }
            
        return ans*ans;
    }
};