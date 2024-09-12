#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
//本题出现的bug
/*
 * 1.取栈top后忘记pop出栈，导致死循环，而且是两个地方都忘记出栈
 * 2.在栈中存放的是index,比较大小时应该用index找到
 */
vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> stack1;
    vector<int> answer(temperatures.size(),0);
    for(int i=0;i<temperatures.size();i++){
        if(stack1.empty()||temperatures[stack1.top()]>=temperatures[i]){
            stack1.push(i);
        }else{
            while(!stack1.empty()&&temperatures[stack1.top()]<temperatures[i]){
                int top=stack1.top();
                stack1.pop();
                answer[top]=i-top;
            }
            stack1.push(i);
        }
    }
    return answer;
}
int main() {
    vector<int> nums1={30,40,50,60};
    vector<int> ans= dailyTemperatures(nums1);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
}
