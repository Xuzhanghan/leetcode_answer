#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
vector<int> nextGreaterElements(vector<int>& nums) {
    int len=nums.size();
    vector<int> ans(len,-1);
    //因为可能存在重复的元素所以不能用哈希表
    for(int i=0;i<len-1;i++){
        nums.push_back(nums[i]);
    }//将数组的循环拼接起来
    stack<int> stack1;
    for(int i=0;i<nums.size();i++){
        if(stack1.empty()||nums[stack1.top()]>=nums[i]){
            stack1.push(i);
        }else{
            while(!stack1.empty()&&nums[stack1.top()]<nums[i]){
                int topIndex=stack1.top();
                stack1.pop();
                if(topIndex<ans.size()){
                    ans[topIndex]=nums[i];
                }
            }
            stack1.push(i);
        }
    }
    return ans;
}
int main() {
    vector<int> nums1={1,2,3,1};
    vector<int> ans= nextGreaterElements(nums1);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
}
