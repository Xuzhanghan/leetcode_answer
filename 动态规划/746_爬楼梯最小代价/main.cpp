#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
//本题出现的bug

int minCostClimbingStairs(vector<int>& cost) {
    int dp[2];
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=cost.size();i++){
        int cost_value1=dp[0]+cost[i-2];
        int cost_value2=dp[1]+cost[i-1];
        if(cost_value1<=cost_value2){
            dp[0]=dp[1];
            dp[1]=cost_value1;
        }else{
            dp[0]=dp[1];
            dp[1]=cost_value2;
        }
       // cout<<"dp"<<dp[1]<<endl;
    }
    return dp[1];
}
int main() {
    vector<int> cost={10,15,20};
    cout<<minCostClimbingStairs(cost);
}
