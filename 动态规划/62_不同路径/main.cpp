#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
//本题出现的bug 暂无
//思路：使用二维dp存储m*n的可能路径数量，通过扩大（增加下标为0的行与列避免对第一行第一列的特殊讨论）

int uniquePaths(int m, int n) {
    int dp[101][101];
    dp[0][0]=0;
    dp[0][1]=0;
    dp[1][0]=0;
    dp[1][1]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i==1&&j==1){
                continue;
            }
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m][n];
}
int main() {
    cout<<uniquePaths(3,3);
}
