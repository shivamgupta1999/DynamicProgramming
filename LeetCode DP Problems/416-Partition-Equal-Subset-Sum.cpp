class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        if(sum&1)
            return false;
        
        sum/=2;
        
        int n=nums.size();
        
        int dp[sum+1];
        memset(dp,0,sizeof(dp));
        
        dp[0]=1;
        
        for(int j=0;j<n;j++)
            for(int i=sum;i>=nums[j];i--)
                if(i-nums[j]>=0)
                    dp[i]=dp[i-nums[j]]||dp[i];
        
        if(dp[sum])
        return true;
        
        return false;
    }
};