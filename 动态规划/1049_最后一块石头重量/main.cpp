#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
//表面看是每次取两个石头，实际上仍然可以分组看，只要可以分成两个等和的数组就说明可以没有石头剩下，否则就取最接近1/2sum的值
int lastStoneWeightII(vector<int>& stones) {
    int len=stones.size();
    int sum= accumulate(stones.begin(),stones.end(),0);
    int target=sum/2;
    //如果和为奇数，即使找到了1/2sum也要用(sum-1/2sum)-1/2sum
    vector<vector<int>> dp(len+1,vector<int>(sum+1,0));//是否可以通过这样避免有大于1/2sum的数时不发生溢出

    for(int i=0;i<len;i++){
        dp[i][0]=true;
    }
    dp[0][stones[0]]=true;
    for(int i=1;i<len;i++){
        for(int j=1;j<=target;j++){
            if(j>=stones[i]){
                dp[i][j]=dp[i-1][j]|dp[i-1][j-stones[i]];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    if(dp[len-1][target]){
        return sum-target-target;
    }else{
        for(int i=target;i>=0;i--){
            if(dp[len-1][i]){
                //找到为true的
                return (sum-i)-i;
            }
        }
    }
    return -1;
}
int main() {
    vector<int> stones={2,7,4,1,8,1};
    cout<<lastStoneWeightII(stones);
}
