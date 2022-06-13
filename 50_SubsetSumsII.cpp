// Brute Force Approach
// 2^n calls -> Set -> Vector<Vector>

void solve(int i,int n,vector<int> arr,vector<int> temp,set<vector<int>>& st){
    if(i == n){
        st.insert(temp);    // insertion in set takes logN time.
        return;
    }
    else{
        solve(i+1,n,arr,temp,st);
        temp.push_back(arr[i]);
        solve(i+1,n,arr,temp,st);
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    set<vector<int>> st;
    sort(nums.begin(),nums.end());

    // 2^n calls add in set -> (2^n)*(log(2^n))
    solve(0,nums.size(),nums,{},st);
    
    // Set -> vector<vector> -> (2^n)
    vector<vector<int>> ans;
    for(auto it = st.begin(); it!=st.end(); it++){
        ans.push_back(*it);
    }
    return ans;
}


// Optimized Approach - Optimizing Recursion

void findSubsets(int idx, vector<int> arr, vector<int> ds, vector<vector<int>>& ans){
    ans.push_back(ds);
    for(int i = idx; i<arr.size(); i++){
        if(i != idx && arr[i] == arr[i-1])  continue;
        ds.push_back(arr[i]);
        findSubsets(i+1,arr,ds,ans);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(),nums.end());
    findSubsets(0,nums,ds,ans);
    return ans;
}