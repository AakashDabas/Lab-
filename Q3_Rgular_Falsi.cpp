#include<iostream>
#include<cmath>

using namespace std;

float f(float a){
	return a - cos(a);
}

int main(){
	float a = 0;
	float b = 1;
	float x = 0, y =0;
	while(1){
		x = (a*f(b) - b*f(a))/(f(b) - f(a));
		if(f(a)*f(x) < 0)	b = x;
		else	a = x;
		if(y == x)	break;
		y = x;
	}
	cout<<x;
}
