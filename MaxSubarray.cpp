int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int maxi = nums[0];
    for(auto x : nums){
      sum += x;
      if(sum>maxi){
          maxi = sum;
      }
      if(sum<0){
          sum=0;
      }
    }
    return maxi;
}
