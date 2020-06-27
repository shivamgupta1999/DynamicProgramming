class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int dp[amount+1];
        
        for(int i=0;i<=amount;i++)
            dp[i]=amount+1;
        
        dp[0]=0;
        
        for(int i=1;i<=amount;i++)
            for(int j=0;j<n;j++)
                if(i-coins[j]>=0)
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
        
        return (dp[amount]<=amount ? dp[amount] : -1);
    }
};