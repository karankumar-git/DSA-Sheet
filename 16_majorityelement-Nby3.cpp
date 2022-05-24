#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> v){
	vector < int > ans;
  	for (int i = 0; i < n; i++) {
    	int cnt = 1;
	    for (int j = i + 1; j < n; j++) {
    	  	if (arr[j] == arr[i])
        		cnt++;
    	}

		if (cnt > (n / 3)) 
  			ans.push_back(arr[i]);
	}
	return ans;
}

int better(vector<int> v,int n){
  unordered_map < int, int > mp;
  vector < int > ans;

  for (int i = 0; i < n; i++) {
    mp[arr[i]]++;
  }

  for (auto x: mp) {
    if (x.second > (n / 3))
      ans.push_back(x.first);
  }

  return ans;
}

int extendedMooreVotingAlgo(vector<int> v,int n){
	
}