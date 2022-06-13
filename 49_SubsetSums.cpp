#include<iostream>
using namespace std;

void solve(vector<int> arr, int n ,int i, int sum,vector<int>& ans){
    if(i == n){
        ans.push_back(sum);
        return;
    }
    else{
        //pick
        solve(arr,n,i+1,sum+arr[i],ans);
        //notpick
        solve(arr,n,i+1,sum,ans);
    }
}
vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    vector<int> ans;
    solve(arr,N,0,0,ans);
    sort(ans.begin(),ans.end());
    return ans;
}