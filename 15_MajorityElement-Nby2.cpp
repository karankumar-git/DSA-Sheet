#include <bits/stdc++.h>
using namespace std;

int brute(vector<int> arr){
	//gives TLE in LEETCODE
	for(int i = 0; i<arr.size();i++){
		int count = 0;
		for(int j = 0; j<arr.size();j++){
			if(arr[i]==arr[j]){
				count++;
			}
		}
		if(count>arr.size()/2)	return arr[i];
	}
	return -1;
}

int better(vector<int> arr){
	//accepted in leetcode
	unordered_map<int,int> mp;
	for(int x:arr){
		if(mp.find(x) == mp.end()){
			mp[x] = 1;
		}
		else{
			mp[x]++;
			if(mp[x]>arr.size()/2){
				return x;
			}
		}
	}
	return arr[0];
}

int optimal(vector<int> arr){
	int count = 0;
	int element ;
	for(int x: arr){
		if(count == 0){
			element = x;
		}
		if(x == element){
			count ++;
		}
		else{
			count --;
		}
	}
	return element;
}

int main(){
	int n;
	cin>>n;

	vector<int> arr(n);
	for(int i =0; i<n; i++){
		cin>>arr[i];
	}

	cout<<brute(arr)<<endl;
	cout<<better(arr)<<endl;
	cout<<optimal(arr)<<endl;
}