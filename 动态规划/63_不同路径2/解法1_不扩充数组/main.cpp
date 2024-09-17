class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    int dp[101][101];
    if(obstacleGrid[0][0]==1){
        dp[0][0]=0;
    }else{
        dp[0][0]=1;
    }
    for(int i=2;i<=m;i++){
       if(obstacleGrid[i-1][0]==1){
           dp[i-1][0]=0;
       }else{
           dp[i-1][0]=dp[i-2][0];
       }
    }
    for(int i=2;i<=n;i++){
        if(obstacleGrid[0][i-1]==1){
            dp[0][i-1]=0;
        }else{
            dp[0][i-1]=dp[0][i-2];
        }
    }

    for(int i=2;i<=m;i++){
        for(int j=2;j<=n;j++){
            if(obstacleGrid[i-1][j-1]==1){
                dp[i-1][j-1]=0;
            }else{
                dp[i-1][j-1]=dp[i-1][j-2]+dp[i-2][j-1];
            }
        }
    }
    return dp[m-1][n-1];}
};
