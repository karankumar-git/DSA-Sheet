class Solution {
public:
    void recursionPermutation(vector<int> &ds,vector<int> &nums,vector<vector<int>> &ans,int freq[]){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = 0; i<nums.size(); i++){
            if(freq[i] == 0){
                ds.push_back(nums[i]);
                freq[i] = 1;
                recursionPermutation(ds,nums,ans,freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        int n = nums.size();
        int freq[n];
        for(int i = 0 ; i<n; i++){
            freq[i] = 0;
        }
        recursionPermutation(ds,nums,ans,freq);
        return ans;
    }
};
