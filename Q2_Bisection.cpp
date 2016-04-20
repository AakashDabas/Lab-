#include<iostream>
#include<cmath>

using namespace std;

double function(double x){
	return x - cos(x);
}

int main(){
	double mid, f_mid, left, right, pre_f_mid;
	left = 0;
	right = 1;
	mid = (left+right)/2;
	pre_f_mid = function(mid);
	while(1){
		double value_at_left = function(left);
		double value_at_right = function(right);
		double value_at_mid = function(mid);
		if(value_at_mid*value_at_left < 0)	right = mid;
		else	left = mid;
		pre_f_mid = f_mid;
		mid = (left+right)/2;
		f_mid = function(mid);
		if(abs(pre_f_mid) <= 0.00001)	break;
	}
	cout<<mid;
}
