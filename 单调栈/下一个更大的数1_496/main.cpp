#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
    vector<int> ans;//初始化存放下一个更大数的容器
    nums2.push_back(INT16_MAX);
    stack<int> stack1;//构建并维护一个单调减的栈，每个元素出栈时得到其下一个更大的数，存入哈希表
    unordered_map<int,int> nextGreaterMap;
    for(int i=0;i<nums2.size()-1;i++){
        if(stack1.empty()||stack1.top()>=nums2[i]){
            stack1.push(nums2[i]);
        }else{
            while(!stack1.empty()&&stack1.top()<nums2[i]){
                int top=stack1.top();
                stack1.pop();
                nextGreaterMap.insert({top,nums2[i]});
            }
            stack1.push(nums2[i]);
        }
    }
    while(!stack1.empty()&&stack1.top()<nums2[nums2.size()-1]){
        int top=stack1.top();
        stack1.pop();
        nextGreaterMap.insert({top,-1});
    }
    for(int i=0;i<nums1.size();i++){
        int greater_num=nextGreaterMap[nums1[i]];
        ans.push_back(greater_num);
    }
    return ans;
}
int main() {
    vector<int> nums1={2,4};
    vector<int> nums2={1,2,3,4};
    vector<int> ans= nextGreaterElement(nums1,nums2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
}
