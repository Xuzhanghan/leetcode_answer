class Solution {
public:
    vector<vector<int>> result;
vector<int> element;
void backtracking(vector<int>& candidates, int target,int startIndex){
    int sum=accumulate(element.begin(),element.end(),0);
    if(startIndex==candidates.size()){
        return;
    }
    if(sum==target){
        result.push_back(element);
        return;
    }
    
    for(int i=startIndex;i<candidates.size();i++){
        if(sum<target){
            element.push_back(candidates[i]);
            backtracking(candidates,target,i);
            element.pop_back();
        }
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates,target,0);
        return result;
    }
};
