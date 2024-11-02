class Solution {
public:
    unordered_map<int,string> map;
    vector<string> result;
    string str="";
    void backtracking(string digits,int startIndex){
        if(startIndex==digits.size()){
            if(str!=""){
                result.push_back(str);
            }
            return;
        }
        string representations=map[digits[startIndex]];
        for(int i=0;i<representations.size();i++){
            str.push_back(representations[i]);
            backtracking(digits,startIndex+1);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        map['2']="abc";
        map['3']="def";
        map['4']="ghi";
        map['5']="jkl";
        map['6']="mno";
        map['7']="pqrs";
        map['8']="tuv";
        map['9']="wxyz";
        backtracking(digits,0);
        return result;
    }
};
