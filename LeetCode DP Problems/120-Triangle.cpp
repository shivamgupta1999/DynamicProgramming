class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n=triangle.size();
        vector<int>dp[n];
        
        dp[0].push_back(triangle[0][0]);
        
        for(int i=1;i<n;i++)
            dp[i].push_back(dp[i-1][0]+triangle[i][0]);
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=i;j++){
                if(j==i)
                    dp[i].push_back(dp[i-1][j-1]+triangle[i][j]);
                else
                    dp[i].push_back(min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j]);
            }
        }
        
        int ans=INT_MAX;
        
        for(int i:dp[n-1])
            ans=min(ans,i);
        
        return ans;
    }
};