//与组合相比只是多了一个比较总和是否等于n的过程，剪枝操作上有更新
class Solution {
public:
    vector<vector<int>> result;
    vector<int> element;
    void backtracking(int n,int k,int startIndex){
        int sum=accumulate(element.begin(),element.end(),0);
        if(element.size()==k){
            if(sum==n){
                result.push_back(element);
            }
            return;
        }
        for(int i=startIndex;i<=9;i++){
            if(sum+i<=n){
                element.push_back(i);
                backtracking(n,k,i+1);
                element.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n,k,1);
        return result;
    }
};
