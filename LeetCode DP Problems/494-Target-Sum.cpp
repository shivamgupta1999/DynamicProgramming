class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        
        long sum=accumulate(nums.begin(),nums.end(),0);
        long rsum=(sum+S)/2;
        long n = nums.size();
        
        vector<vector<long>> dp(n+1,vector<long>(sum+1,0));
        
        if(S>sum||(sum+S)%2==1)
            return 0;
        
        dp[0][0] = 1;
        
        for(long i = 1;i<=n;i++){
            for(long j = 0;j<=rsum;j++){
                if(nums[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][rsum];
    }
};