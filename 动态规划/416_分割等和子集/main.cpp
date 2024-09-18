#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
//本题出现的bug
/*
 * 1.在不考虑最大数大于1/2sum时会出现数组越界，因为定义时j的范围只到1/2sum
 * */
//转化为求和为1/2sum的数组，是否可以恰好装满这个背包

bool canPartition(vector<int>& nums) {
    int sum= accumulate(nums.begin(),nums.end(),0);//第三个参数是累加的初始值
    //dp数组可以使用vector代替，可以节省空间更加灵活
    int len=nums.size();
    int max=*max_element(nums.begin(),nums.end());//这个用法再了解一下
    int target=sum/2;
    //可以直接返回的情况 1.只有一个数 2.和为奇数 3.最大元素大于和的1/2
    if(sum%2!=0){
        return false;//和为奇数，直接返回false
    }
    if(max>target){
        return false;
    }
    //dp的含义
    vector<vector<int>> dp(len,vector<int>(target+1,0));//二维vector的初始化

    //初始化 1.所有j为0的都是true 2.dp[0][nums[0]]为true
    dp[0][0]=1;
    dp[0][nums[0]]=1;

    for(int i=1;i<len;i++){
        //从第二个数开始遍历
        for(int j=0;j<=target;j++){
            if(nums[i]>j){
                dp[i][j]=dp[i-1][j];
            }else if(nums[i]==j){
                dp[i][j]=1;
            }else{
                dp[i][j]=dp[i-1][j]|dp[i-1][j-nums[i]];
            }
        }
    }
    int result=dp[len-1][target];
    if(result==1){
        return true;
    }else{
        return false;
    }

}
int main() {
    vector<int> nums={100};
    cout<<canPartition(nums);
}
