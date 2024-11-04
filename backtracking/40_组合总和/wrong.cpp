//本方法出现了超时的问题
class Solution {
public:
    vector<vector<int>> result;
    vector<int> element;
    set<vector<int>> unique_result;
    void backtracking(vector<int>& candidates,int target,int startIndex){
        int sum=accumulate(element.begin(),element.end(),0);
        if(sum>target){
            return;
        }
        if(sum==target){
            //不能直接对element排序，考虑到回溯！
            vector<int> sortedElement=element;
            sort(sortedElement.begin(),sortedElement.end());
            //result.push_back(element);
            unique_result.insert(sortedElement);
            return;
        }
        for(int i=startIndex;i<candidates.size();i++){
            if(sum<target){
                element.push_back(candidates[i]);
                backtracking(candidates,target,i+1);
                element.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        backtracking(candidates,target,0);
        result=vector<vector<int>>(unique_result.begin(),unique_result.end());
        return result;
    }
};
