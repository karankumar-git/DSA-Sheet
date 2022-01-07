class Solution {
public:
  
    //it is an approach 2 because in approach 1 we use lots of arrays to find the answer which leads in increase in space complexity.
    //but here, we use only index to find our result ans.
  
    void recursionPermutation(int idx,vector<int> &nums,vector<vector<int>> &ans){
        //if index is eqls to nums size while swapping the numbers it means we get our permutation, we should store it.
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = idx; i<nums.size(); i++){
            swap(nums[idx],nums[i]);
            recursionPermutation(idx+1,nums,ans); // perform permutation on other indexes of array(idx+1).
            swap(nums[idx],nums[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; //to store answer.
        recursionPermutation(0,nums,ans);
        return ans;
    }
};
