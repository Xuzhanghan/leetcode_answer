#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
//本题出现的bug 1.明确i j代表的是下标还是行号和列号 2.第一行和第一列还是需要注意，算特殊的情况,是看到用例才知道自己考虑的不全面{{1,0}}
/*本题出现的bug
 * 1.使用i j遍历时，没有注意其含义究竟是数组下标还是行号和列号，影响了“小于等于”，“i-1"这种边界值确定
 * 2.第一行和第一列的比较特殊，上一次采取扩充的方法，避免了额外的讨论，这一次没有采取扩充，直接赋值1或0，没有考虑它们前面有障碍的情况
 * */

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    int dp[102][102];
    //改成扩充
    dp[1][1]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(obstacleGrid[i-1][j-1]==1){
                dp[i][j]=0;
            }else{
                if(!(i==1&&j==1)){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
    }
    return dp[m][n];
}
int main() {
    vector<vector<int>> obstacleGrid8 = {
            {1,0}
    };
    cout<<uniquePathsWithObstacles(obstacleGrid8);
}
