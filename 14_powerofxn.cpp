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

double optimal(double x,int n){
	double ans = 1.00;
	bool isNegative = false;
	if(n<0){
		isNegative = true;
		n = -1*n;
	}
	while(n>0){
		if(n%2==0){
			x *= x;
			n /= 2;
		}
		else{
			ans *= x;
			n = n-1;
		}
	}
	if(isNegative)	return double(1.00)/double(ans);
	return ans;
}

int main(){
	double x ;
	cin>>x;
	int n;
	cin>>n;
	cout<<brute(x,n)<<endl;
	cout<<optimal(x,n)<<endl;
}