class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        
        int dp[d+1][target+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=target;i++){
            if(i<=f)
                dp[1][i]=1;
            if(d==1&&target==i)
                return dp[1][i];
        }
        
        for(int i=2;i<=d;i++){
            for(int j=1;j<=target;j++){
                for(int k=1;k<=f;k++){
                    if(j-k>=0)
                    dp[i][j] += dp[i-1][j-k]%1000000007;
                    dp[i][j]%=1000000007;
                }
            }
        }
        
        return dp[d][target]%1000000007;
    }
};