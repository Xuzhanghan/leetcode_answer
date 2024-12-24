class Solution {
public:
    bool canJump(vector<int>& nums) {
    auto pos=find(nums.begin(),nums.end(),0);
    if(pos==nums.end()){
        return true;
    }
    //没0一定能成功，但有零不一定会失败
    while(pos!=nums.end()&&pos!=nums.end()-1){
        int index_of_zero= distance(nums.begin(),pos);
        int start=0;
        while(start<index_of_zero){
            if(start+nums[start]>index_of_zero){
                *pos=-1;
                pos=find(nums.begin(),nums.end(),0);
                break;
            }
            start++;
        }
        if(start==index_of_zero){
            return false;
        }
    }
    return true;
}
};
