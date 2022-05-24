//BRUTE FORCE
// sort then count

int brute(vector<int> nums){
    if(nums.size()==0){
        return 0;
    }
    sort(nums.begin(),nums.end());
    int prev = nums[0];
    int ans = 1;
    int count = 1;
    for(int i = 1 ; i<nums.size(); i++){
        if(nums[i] == prev+1){
            count++;
        }
        else if(nums[i] != prev){
            count = 1;
        }
        prev = nums[i];
        ans = max(ans,count);
    }
    return ans;
}


//OPTIMAL SOLUTION
//using hashmap
int optimalsolution(vector<int> nums){
    //incase of [] and [x], ans is size of array.
    if(nums.size()<2){
        return nums.size();
    }
    unordered_map<int,int> mp;
    for(int x: nums){
        mp[x]++;
    }
    int longeststreak = INT_MIN;
    for(int x: nums){
        //leave the element when x-1 is present.
        if(mp.find(x-1)!=mp.end()) continue;
        else{
            int count = 0;
            int ele = x;
            //count the next consecutive numbers till its succesor present.
            while(mp.find(ele++) != mp.end()){
                count++;
            }
            longeststreak = max(longeststreak,count);
        }
    }
    return longeststreak;
}