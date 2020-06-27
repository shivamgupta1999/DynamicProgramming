class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n=A.size();
        int m=A[0].size();
        int dp[n][m];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                dp[i][j]=0;
        
        for(int i=0;i<m;i++)
            dp[0][i]=A[0][i];
        
        if(m==1){
            int sum=0;
            
            for(int i=0;i<n;i++)
                sum+=A[i][0];
            
            return sum;
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0)
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+A[i][j];
                else if(j==m-1)
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+A[i][j];
                else
                    dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]))+A[i][j];
            }
        }
        
        int sum=100*n;
        
        for(int i=0;i<m;i++)
            sum=min(sum,dp[n-1][i]);
        
        return sum;
            
    }
};