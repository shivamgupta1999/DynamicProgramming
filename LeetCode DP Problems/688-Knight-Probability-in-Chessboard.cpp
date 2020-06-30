class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        
        double dp[N][N][K+1];
        
        memset(dp,0.0,sizeof(dp));
        
        int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
        int dy[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
        
        for(int k=0;k<=K;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(k==0){
                        dp[i][j][k]=1.0;
                        continue;
                    }
                    for(int l=0;l<8;l++){
                        int x=dx[l]+i;
                        int y=dy[l]+j;
                        if(x>=0&&y>=0&&x<N&&y<N){
                            dp[i][j][k]+=dp[x][y][k-1];
                        }
                    }
                    dp[i][j][k]/=8;
                }
            }
        }
        return dp[r][c][K];
    }
};