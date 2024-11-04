class Solution {
public:
    vector<vector<int>> result;
    vector<int> element;
    void backtracking(vector<int>& candidates,int target,int startIndex,vector<int>& used){
        int sum=accumulate(element.begin(),element.end(),0);
        if(sum>target){
            return;
        }
        if(sum==target){
            //不能直接对element排序，考虑到回溯！
            result.push_back(element);
            return;
        }
        for(int i=startIndex;i<candidates.size();i++){
            if(i>0&&candidates[i]==candidates[i-1]&&used[i-1]==0){
                continue;
            }
            if(sum<target){
                used[i]=1;
                element.push_back(candidates[i]);
                backtracking(candidates,target,i+1,used);
                used[i]=0;
                element.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> used(candidates.size(),0);
        backtracking(candidates,target,0,used);
        return result;
    }
};
