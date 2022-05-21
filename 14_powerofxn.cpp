#include <bits/stdc++.h>
using namespace std;

double brute(double x,int n){
	//it can't handle the case, if n < 0 (negative)
	double ans = 1.00;
	for (int i = 0; i < n; ++i)
	{
		ans *= x;
	}
	return ans;
}

int main(){
	double x ;
	cin>>x;
	int n;
	cin>>n;
	cout<<brute(x,n)<<endl;
}