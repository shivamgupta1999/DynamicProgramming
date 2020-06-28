class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        int length=stones.size();
        int sum=0;
        
        for(auto i:stones)
            sum+=i;
        
        int dp[length][sum/2+1];
        
        for(int i=0;i<length;i++)
            for(int j=0;j<=sum/2;j++)
                dp[i][j]=0;
        
        for(int i=0;i<length;i++){
            for(int j=0;j<=sum/2;j++){
                if(j==0)
                    dp[i][j]=1;
                else if(j<stones[i]&&i>0)
                    dp[i][j]=dp[i-1][j];
                else if(j==stones[i])
                    dp[i][j]=1;
                else if(i>0)
                    dp[i][j]=dp[i-1][j]|dp[i-1][j-stones[i]];
            }
        }
        
        for(int i=sum/2;i>=0;i--){
            if(dp[length-1][i]){
                return abs(sum-2*i);
            }
        }
        return 0;
    }
};